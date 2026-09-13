---
type: Component
title: OpenGL\Bridge\Bridge — the only glue
description: >-
  The runtime loader and its version gate, and the byte buffers the pointer
  rule makes necessary. Nothing else, and nothing that decides how OpenGL
  is used.
resource: src/phpgl-bridge.c
tags: [bridge, glue, loader, buffers, opengl]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# OpenGL\Bridge\Bridge

Everything in `src/phpgl-bridge.{h,c}` exists because PHP cannot open a
shared library, cannot hold a byte buffer a GPU driver can write into, and
cannot know whether the current context has a given entry point. Nothing
here decides anything about how OpenGL is used.

## Surface

| call | does |
|---|---|
| `load(): bool` | `dlopen` the platform's GL (and, on Linux, EGL) library and re-sample the current context's version. Idempotent for the libraries; **deliberately not** for the sample. |
| `isAvailable(string name): bool` | **gated.** True when `name` resolves *and* there is a current context *and* it is new enough for the block `name` came from. This is the one to ask before calling a binding: it answers the same question `phpgl_entry()` answers. |
| `procAddress(string name): int` | **ungated.** The address `dlsym`/`eglGetProcAddress` returns, as pointer bits, 0 when unresolved. It deliberately does not consult the version gate or the current context, because it reports what the *driver* has, not what this *context* can do — on Mesa those differ by three minor versions. Diagnostics only; no binding goes through it, and a non-zero answer here is not permission to call anything. |
| `contextVersion(): array` | `{major, minor, loaded}` — what the gate currently believes |
| `alloc(int size): int` | a zeroed block, returned as pointer bits |
| `free(int ptr): void` | releases one, and refuses a pointer this extension did not allocate |
| `write(int ptr, int offset, string bytes): bool` | bounds-checked copy in |
| `read(int ptr, int offset, int length): var` | bounds-checked copy out; `null` on refusal |

## The loader

**Every entry point in this extension is resolved at runtime and none is
linked.** That is what makes one `.so` serve a GL 3.1 Pi and a GL 4.1 Mac
(see [traps/runtime-resolution-not-linking.md](/traps/runtime-resolution-not-linking.md)).

- **Linux:** `dlopen("libGL.so.1")` and `dlopen("libEGL.so.1")`, then
  `eglGetProcAddress` first and `dlsym` second. Core `egl*` names come back
  NULL from `eglGetProcAddress` by spec, which is why the `dlsym` fallback is
  not optional.
- **Darwin:** `dlopen("/System/Library/Frameworks/OpenGL.framework/OpenGL")`
  and `dlsym`. GL and CGL live in the same image, so one handle serves both.
- Either platform falls back to `dlsym(RTLD_DEFAULT, …)` for a host process
  that links GL itself.

Each generated binding owns a function-static `phpgl_slot`, so a resolved
pointer costs one predictable branch per call and a missing one is only
looked up once.

## The version gate

`eglGetProcAddress` and `dlsym` answer "does the driver have this symbol",
which on Mesa is very nearly "yes, all of GL 4.6" regardless of what the
context can actually do. That is not the question a caller is asking, so the
gate answers the real one.

`scripts/gen-gl-src.php` emits `src/phpgl-registry.c`: every bound entry
point and the version block it first appeared in. A binding passes its own
block's version into `phpgl_entry(name, &slot, major, minor)`. EGL and CGL
pass `0, 0`, meaning ungated — they are how you *get* a context, so they
cannot depend on having one.

A gated call is refused on **either** of two grounds, and both are re-checked
on every call:

1. **there is no current context.** Not "there was none when we last
   sampled" — the probe (`CGLGetCurrentContext` / `eglGetCurrentContext` /
   `glXGetCurrentContext`, a cached function pointer) runs each time, because
   a context can be dropped as easily as it was made, and a GL call without
   one is undefined at best and fatal at worst.
2. **the context is older than the entry point's block.** This half is
   sampled and cached, since a context's version cannot change under it.

A refused call raises

```
E_WARNING: <name> is not available in the current context
```

and returns `0`/void. No exception, no side channel — ext-gtk's rule.

**Sampling the context version needs care, and this is the one place the
Bridge holds platform knowledge.** Calling `glGetIntegerv` with no context
current does not fail politely on macOS; it dereferences a null dispatch
table and kills the process (reproduced on Darwin 24.4.0 with a two-line C
program). So the Bridge asks `CGLGetCurrentContext` / `eglGetCurrentContext`
/ `glXGetCurrentContext` first, and treats "cannot tell" as "no context" —
which downgrades every GL call to the ordinary not-available warning instead
of a crash. Only then does it read `GL_MAJOR_VERSION` / `GL_MINOR_VERSION`,
falling back to parsing `glGetString(GL_VERSION)`.

**When to call `load()`:** once before creating a context (EGL and CGL need
the libraries open), and the gate then re-samples on its own the first time a
GL call happens after a context becomes current. Calling `load()` again after
making a *different* context current is the way to force a re-sample — a
cached non-zero version is kept until you do.

## The buffers

The pointer rule (D2) sends every pointer across as bits, so PHP needs
somewhere to put bytes. `alloc` returns zeroed memory from plain `malloc`,
and that choice is load-bearing twice over:

- **Not `emalloc`**, because the size registry is a process global and a
  request-scoped block would dangle in it after request shutdown.
- **Not `pemalloc` either**, because `pemalloc` routes a failed allocation
  through `zend_out_of_memory()`, which prints and calls `exit(1)`. A caller
  asking for a buffer that cannot exist would have taken the process down —
  and the "size does not fit in `size_t`" check that looked like it guarded
  that is dead code on a 64-bit box, where `zend_long` and `size_t` are the
  same width. `malloc` returns `NULL` instead, which `alloc` turns into an
  `E_WARNING` and a `0`.

Callers free explicitly with `Bridge::free`; `MSHUTDOWN` sweeps the rest.

`write` and `read` are bounds-checked against the allocation they name:
a pointer this extension did not allocate, a negative offset, or a range that
runs past the end all raise `E_WARNING` and return `false`/`null`. That is
the guards-in-glue precedent from ext-metal — the glue is where memory safety
is enforceable, so it is enforced there and nowhere else.

What is **not** checked, on purpose: the pointer bits a *binding* receives.
`GL15::glBufferData($target, $size, $ptr, $usage)` will hand GL whatever int
you pass. See [traps/pointer-bits-only.md](/traps/pointer-bits-only.md).

## ZTS note — read this before using threads

`support-zts` is **true and must stay true**: the Pi build box's PHP is ZTS,
so the extension has to build and load there. That is a statement about the
build, not a promise of thread safety.

Everything the Bridge remembers is a plain process global with **no lock**:

- the `dlopen` handles and the `phpgl_loaded` flag,
- the generation counter and each binding's function-static slot,
- the sampled context version and the current-context probe table,
- **the buffer registry** — the `HashTable` mapping pointer bits to sizes.

Two threads calling `Bridge::alloc` at once can corrupt that HashTable, and
two threads calling `Bridge::load` at once race on the handles. Nothing
detects it.

**The contract is one PHP thread, one GL context, and that is also what
OpenGL itself wants** — a context is current *per thread*, so a second thread
would see no context and have every call refused anyway. This is ext-gtk's
stance verbatim, and the CLI process model both target. If you need GL from
several threads, run several processes.

`MSHUTDOWN` frees whatever buffers are left and closes the handles
(`phpgl_bridge_shutdown`, wired into the generated extension by
`scripts/patch-mshutdown.php` because Zephir compiles its own MSHUTDOWN out
of a release build), so a forgotten `Bridge::free` is not carried to the
grave.
