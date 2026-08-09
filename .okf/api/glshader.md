---
type: CoreType
title: Opengl\\GL\\GlShader
description: Shader object DTO with public fd, type, compiled
resource: /opengl/gl/glshader.zep
tags: [opengl, api, shader, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: glshader-zep
    resource: /opengl/gl/glshader.zep
    title: glshader.zep
  - id: gl-zep
    resource: /opengl/gl/gl.zep
    title: gl.zep
---

# Schema

| Field | Type | Notes |
|-------|------|--------|
| `fd` | `int` (public) | Opaque `GLuint` shader name; `0` = none / deleted |
| `type` | `int` (public) | Shader type (`GL_VERTEX_SHADER` / `GL_FRAGMENT_SHADER`, …) |
| `compiled` | `int` (public) | Non-zero after a successful `glCompileShader` |

Class name is **`GlShader`**, not `Shader`.[^glshader-zep]

# Lifecycle

1. `GL::glCreateShader($type)` → `fd` + `type`.
2. `GL::glShaderSource($shader, $source)` → `GL::glCompileShader($shader)` (sets `compiled`; returns `bool`).
3. Attach to [GlProgram](/api/glprogram.md); `GL::glGetShaderInfoLog` on failure.
4. `GL::glDeleteShader($shader)` zeros `fd` and `compiled`.

[^glshader-zep]: glshader.zep
[^gl-zep]: gl.zep
