---
type: Architecture
title: Contexts
description: CGL on macOS and surfaceless EGL on Linux, and the guard every gl* binding runs.
tags: [opengl, cgl, egl, context]
status: draft
generated: { by: grok/4.7, at: 2026-10-04T23:50:00-04:00 }
sources:
  - id: plan
    resource: /docs/superpowers/plans/2026-10-04-slice-3-ext-opengl.md
    title: Slice 3 plan
  - id: measured
    resource: src/egl.c
    title: Surfaceless EGL path
---

# Overview

An OpenGL context cannot exist without a platform context API, so CGL and EGL are part of this extension. The Mac path is an offscreen CGL 4.1 core context. The Linux path is surfaceless EGL: `eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA, EGL_DEFAULT_DISPLAY, null)`, then a GLES 3.1 context made current with no surface.[^measured]

# Handles

| Class | Released by |
|---|---|
| `CGLPixelFormatObj` | `CGLDestroyPixelFormat` |
| `CGLContextObj` | `CGLReleaseContext` |
| `EGLContext` | `eglDestroyContext` |
| `EGLSurface` | `eglDestroySurface` |
| `GLsync` | `glDeleteSync` |
| `EGLDisplay`, `EGLConfig` | never; EGL owns them |

Dropping the last PHP reference removes the identity-table entry and does not destroy the native object. `fromPointer(0)` throws `ValueError`. Any other address is trusted.

`CGLReleaseContext` and `eglDestroyContext` clear the context when it is the current one, then release it. A later `gl*` call throws instead of using a dangling current context.[^plan]

# The guard

```c
OPENGL_REQUIRE_CONTEXT()
```

opens every `gl*` function. It calls `CGLGetCurrentContext()` or `eglGetCurrentContext()`. When that is null it throws `Error` "`name(): no current OpenGL context`" and returns. CGL and EGL functions themselves do not require a current context.

[^plan]: Slice 3 plan
[^measured]: src/egl.c
