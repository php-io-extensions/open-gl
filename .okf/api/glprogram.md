---
type: CoreType
title: Opengl\\GL\\GlProgram
description: Program object DTO with public fd and linked
resource: /opengl/gl/glprogram.zep
tags: [opengl, api, program, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: glprogram-zep
    resource: /opengl/gl/glprogram.zep
    title: glprogram.zep
  - id: gl-zep
    resource: /opengl/gl/gl.zep
    title: gl.zep
---

# Schema

| Field | Type | Notes |
|-------|------|--------|
| `fd` | `int` (public) | Opaque `GLuint` program name; `0` = none / deleted |
| `linked` | `int` (public) | Non-zero after a successful `glLinkProgram` |

Class name is **`GlProgram`**, not `Program`.[^glprogram-zep]

# Lifecycle

1. `GL::glCreateProgram()` → non-zero `fd`.
2. `GL::glAttachShader($prog, $shader)` → `GL::glLinkProgram($prog)` (sets `linked`; returns `bool`).
3. `GL::glUseProgram($prog)` / `GL::glUseProgramNone()`; `GL::glGetProgramInfoLog` on failure.
4. `GL::glDeleteProgram($prog)` zeros `fd` and `linked`.

# Examples

```php
use Opengl\GL\GL;

$prog = GL::glCreateProgram();
GL::glAttachShader($prog, $vs);
GL::glAttachShader($prog, $fs);
if (!GL::glLinkProgram($prog)) {
    echo GL::glGetProgramInfoLog($prog);
}
GL::glUseProgram($prog);
```

[^glprogram-zep]: glprogram.zep
[^gl-zep]: gl.zep
