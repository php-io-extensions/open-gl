---
type: Convention
title: fd ownership
description: Who creates and deletes GLuints stored in public fd
tags: [opengl, convention, memory, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: gl-zep
    resource: /opengl/gl/gl.zep
    title: gl.zep
  - id: glbuffer-zep
    resource: /opengl/gl/glbuffer.zep
    title: glbuffer.zep
---

# Rules

| Object | Create | Destroy |
|--------|--------|---------|
| `GlBuffer` / `GlTexture` / `GlShader` / `GlProgram` | `GL::glGen*` / `glCreate*` → store in `->fd` | Matching `GL::glDelete*` zeros `fd` |
| Raw `int` (if ever passed) | Caller-owned | Caller must delete |

# Semantics

- `fd` is a **public int** wrapping `GLuint`, not a POSIX file descriptor.[^glbuffer-zep]
- `0` means “no object”; do not delete `0`.
- Destroying the PHP object **without** deleting the GL name leaks GPU memory until context destruction.
- Context loss (window destroy) invalidates all names — do not reuse stale `fd` values after context teardown.

# Checklist

1. Make context current (glfw/sdl3) before gen/bind/draw/delete.
2. Delete GL objects before destroying the context when practical.
3. Zero `fd` after successful delete to prevent double-free (`glDelete*` helpers already do this).[^gl-zep]

[^gl-zep]: gl.zep
[^glbuffer-zep]: glbuffer.zep
