---
type: Trap
title: Runtime resolution, and what the link line does and does not do
description: Every GL entry point is dlsym'd at call time; the link line is a declared dependency, not a fallback, and the GL runtime is a requirement rather than a warning path.
tags: [trap, loader, dlsym, linking, portability]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# Runtime resolution, and what the link line does and does not do

Two separate facts, easy to blur into one false one. The first version of
this page did exactly that, so it is spelled out here.

## Fact 1 — no entry point is called by name

**No GL, EGL or CGL symbol is referenced anywhere in this extension's code.**
Every call goes through `phpgl_entry()`, which `dlsym`s the name once,
caches it in a function-static slot, and re-resolves it when
`Bridge::load()` bumps the generation.

That is what lets one `.so` serve both boxes:

- The Pi's Mesa has GL 3.1 and no CGL at all.
- The Mac's OpenGL.framework has GL 4.1 and no EGL at all.

A link-time reference to `glProgramUniform1f` would be satisfied on the Mac
and would make the module fail to load on the Pi. A link-time reference to
`CGLCreateContext` would make the Linux build fail outright. Instead,
`OpenGL\CGL\CGL` exists on Linux and simply warns; `OpenGL\GL\GL41\GL41`
exists on the Pi and simply warns. There is not a single `#ifdef` in any
generated binding body.

**Verified, not assumed.** `nm -u` on the built module lists no undefined
`gl*`, `egl*` or `CGL*` symbol on either box, and `check-parity.php` rejects
any body that names one — both the per-binding composite check and a
whole-file scan of every non-glue `src/*.c`, so a call in a file with no
annotations in it (`src/phpgl-support.c` is that shape) cannot hide either.
`scripts/tests/fixtures/linktime` and `.../support-linktime` are the
fixtures that prove the guard fires.

## Fact 2 — the module still declares a link dependency, and that is fine

`ext/config.m4` carries `-framework OpenGL` on Darwin and `-lEGL -lGL -ldl`
elsewhere. **Keeping it is a deliberate decision.** It declares, in the one
place a packager reads, which platform runtime this extension is for.

What it actually produces, measured on the built artefacts:

| | result |
|---|---|
| Darwin | the `.so` carries a load command for `/System/Library/Frameworks/OpenGL.framework/Versions/A/OpenGL`. A framework is linked whether or not a symbol is used, so this *is* a load-time dependency of the module. |
| Linux | `ldd` shows only `libc` and the loader. The toolchain's default `--as-needed` drops `-lEGL` and `-lGL` because no symbol is referenced, and `-ldl` is empty on glibc ≥ 2.34. No load-time dependency results. |

So the honest summary is: **the link line is a declaration, not a mechanism.**
Linking a library does not help `dlopen` find it later — the dynamic loader
searches by soname at `dlopen` time, from the runtime search path, and is
unaffected by what this module was linked against. An earlier version of this
page claimed the opposite; it was wrong.

## The GL runtime is a requirement, not a warning path

Either way the platform's GL runtime must be present for this extension to be
of any use:

- **macOS:** OpenGL.framework is a load-time dependency. A Mac without it
  cannot load the module at all. (Every Mac has it.)
- **Linux:** the module loads fine without `libGL.so.1` / `libEGL.so.1`, and
  then `Bridge::load()` returns `false` with
  `no OpenGL library could be opened`, and every binding warns. Nothing
  works. `build-linux.sh` therefore checks for both libraries before building
  and refuses rather than shipping something that would resolve nothing.

State it as a requirement when packaging this extension. It is not a
degraded mode, it is not a fallback, and there is no sensible behaviour
without it.

## The one place platform knowledge is allowed

`src/phpgl-bridge.c` — and only there — knows that Darwin means
`/System/Library/Frameworks/OpenGL.framework/OpenGL` and Linux means
`libGL.so.1` + `libEGL.so.1`, and that the current context is found via
`CGLGetCurrentContext` / `eglGetCurrentContext` / `glXGetCurrentContext`.
That file is the platform seam. Nothing else may become one.
