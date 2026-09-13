---
type: Trap
title: Version ceilings — 4.1 Mac, 3.1 Pi, 4.2+ deferred
description: Symbol resolution is not availability; Mesa resolves GL 4.6 names on a 3.1 context. The gate answers the real question.
tags: [trap, versions, availability, mesa]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# Version ceilings

Three different ceilings are in play and they are easy to confuse.

| ceiling | value | set by |
|---|---|---|
| what this extension **binds** | GL 4.1 | design decision D1 |
| what the **Mac** can run | GL 4.1 (`4.1 Metal - 89.4`, GLSL 4.10) | OpenGL.framework, the platform's own ceiling |
| what the **Pi** can run | GL 3.1 core, GLSL 1.40 | V3D 7.1.7.0, a hardware ceiling |

## Symbol resolution is not availability

The trap: on Mesa, `eglGetProcAddress("glProgramUniform1f")` returns a
perfectly good pointer on a **GL 3.1** context, because Mesa's dispatch table
knows all of GL 4.6 regardless of what the context negotiated. `dlsym` is no
better. So "can I resolve this name" is not the question a caller is asking,
and answering it would make `Bridge::isAvailable` a liar on exactly the box
where it matters most.

**The gate answers the real question.** `scripts/gen-gl-src.php` emits
`src/phpgl-registry.c` — every bound entry point and the version block it
first appeared in — and each binding passes its own block's version into
`phpgl_entry()`. A 4.1 call on a 3.1 context is refused *before* the pointer
is used:

```
E_WARNING: glProgramUniform1f is not available in the current context
```

and the binding returns `0`/void. `examples/proof_headless.php` §6 proves
both halves of that from one script: `true` and a live call on the Mac,
`false` plus the warning and a `0` on the Pi.

## Sampling the version is platform-sensitive

The gate needs the context's version, and getting it is where this bit back.
Calling `glGetIntegerv(GL_MAJOR_VERSION, …)` with **no context current** does
not return an error on macOS; it dereferences a null dispatch table and kills
the process. So the Bridge asks the context API first
(`CGLGetCurrentContext` / `eglGetCurrentContext` / `glXGetCurrentContext`)
and treats "cannot tell" as "no context", which turns a crash into an
ordinary not-available warning. See [bridge.md](/bridge.md).

Practical consequence: **with no context current, every GL call warns.** That
is correct, and it is also the first thing to check when a script is
warning about calls that obviously exist.

## 4.2 .. 4.6 are deferred, not missing

178 prototypes across `GL_VERSION_4_2` .. `GL_VERSION_4_6` (12, 43, 9, 110,
4) are a later wave. They have no class, no `@audit block` marker, and no
`@reserved` lines. `audit-header.php` reports them under `deferred` and
passes; it fails only if a block **inside** the bound range goes unclaimed.

When that wave lands: add the classes to `GL_MAX_MINOR`/`GL_MAX_MAJOR` in
`gen-gl-src.php`, regenerate, and the deferred list shrinks on its own.
Note that 4.3 introduces `GLDEBUGPROC` — the first callback parameter in the
whole surface, and therefore the first `@reserved` lines this repo will have.
