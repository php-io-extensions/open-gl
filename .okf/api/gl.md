---
type: CoreType
title: Opengl\\GL\\GL
description: Static gl* entry points (clear, viewport, fixed-function, buffer/texture/shader/program helpers)
resource: /opengl/gl/gl.zep
tags: [opengl, api, gl]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: gl-zep
    resource: /opengl/gl/gl.zep
    title: gl.zep
  - id: readme
    resource: /README.md
    title: README
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php
---

# Role

Static facade for OpenGL C entry points. Callers must have a **current** GL context (from glfw/sdl3).[^gl-zep] Named objects are returned or accepted as `GlBuffer` / `GlTexture` / `GlShader` / `GlProgram` DTOs.

# Schema

## State / query

| Method | Returns | Notes |
|--------|---------|--------|
| `glClearColor(float, float, float, float)` | `void` | |
| `glClear(int mask)` | `void` | Mask ints from microscrap / local consts |
| `glViewport(int, int, int, int)` | `void` | Use framebuffer pixels on Retina |
| `glScissor(int, int, int, int)` | `void` | |
| `glEnable(int)` / `glDisable(int)` | `void` | |
| `glFlush()` / `glFinish()` | `void` | |
| `glGetError()` | `int` | |
| `glGetString(int name)` | `string` | |
| `glGetIntegerv(int pname)` | `int` | Single-value query |

## Fixed-function draw / matrix

| Method | Returns |
|--------|---------|
| `glColor4f(float, float, float, float)` | `void` |
| `glBegin(int mode)` / `glEnd()` | `void` |
| `glVertex2f` / `glVertex3f` | `void` |
| `glLoadIdentity()` | `void` |
| `glMatrixMode(int)` | `void` |
| `glOrtho(float…)` | `void` |
| `glDrawArrays(int mode, int first, int count)` | `void` |

## Buffer / texture / shader / program helpers

| Method | Returns | Notes |
|--------|---------|--------|
| `glGenBuffer()` | `GlBuffer` | Sets `fd` |
| `glBindBuffer(int, GlBuffer)` | `void` | Updates `target` |
| `glBufferData(int, string, int)` | `void` | Raw bind-target upload |
| `glBufferDataObject(GlBuffer, string, int)` | `void` | Bind + upload; sets `size`/`usage` |
| `glDeleteBuffer(GlBuffer)` | `void` | Zeros `fd` |
| `glGenTexture()` | `GlTexture` | |
| `glBindTexture(int, GlTexture)` | `void` | |
| `glTexParameteri(int, int, int)` | `void` | |
| `glDeleteTexture(GlTexture)` | `void` | |
| `glCreateShader(int)` | `GlShader` | Sets `type` |
| `glShaderSource(GlShader, string)` | `void` | |
| `glCompileShader(GlShader)` | `bool` | Sets `compiled` |
| `glGetShaderInfoLog(GlShader)` | `string` | |
| `glDeleteShader(GlShader)` | `void` | |
| `glCreateProgram()` | `GlProgram` | |
| `glAttachShader(GlProgram, GlShader)` | `void` | |
| `glLinkProgram(GlProgram)` | `bool` | Sets `linked` |
| `glGetProgramInfoLog(GlProgram)` | `string` | |
| `glUseProgram(GlProgram)` / `glUseProgramNone()` | `void` | |
| `glDeleteProgram(GlProgram)` | `void` | |

All methods are `public static` on `Opengl\GL\GL`.[^gl-zep]

# Examples

```php
use Opengl\GL\GL;

// after glfw makes context current:
GL::glClearColor(0.1, 0.2, 0.3, 1.0);
GL::glClear(0x00004000); // GL_COLOR_BUFFER_BIT — prefer microscrap enums

$buffer = GL::glGenBuffer();
GL::glBindBuffer(0x8892, $buffer); // GL_ARRAY_BUFFER
```

Demo: [proof_menu.php](/playbooks/demo-loop.md) uses clear / ortho / begin-end quads.[^demo]

# Implementation notes

- No class constants — pass enum/`int` values from microscrap.
- Do not add window or context APIs here — see [No windowing](/traps/no-windowing.md).
- No FFI — see [No FFI](/conventions/no-ffi.md).

[^gl-zep]: gl.zep
[^readme]: README
[^demo]: proof_menu.php
