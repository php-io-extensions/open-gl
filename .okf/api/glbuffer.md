---
type: CoreType
title: Opengl\\GL\\GlBuffer
description: Buffer object DTO with public fd, target, size, usage
resource: /opengl/gl/glbuffer.zep
tags: [opengl, api, buffer, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: glbuffer-zep
    resource: /opengl/gl/glbuffer.zep
    title: glbuffer.zep
  - id: gl-zep
    resource: /opengl/gl/gl.zep
    title: gl.zep
---

# Schema

| Field | Type | Notes |
|-------|------|--------|
| `fd` | `int` (public) | Opaque `GLuint` buffer name; `0` = none / deleted |
| `target` | `int` (public) | Last bind target (e.g. `GL_ARRAY_BUFFER`); `0` = unset |
| `size` | `int` (public) | Byte size of last successful `glBufferDataObject` upload |
| `usage` | `int` (public) | Usage hint from last `glBufferDataObject` |

Class name is **`GlBuffer`**, not `Buffer`.[^glbuffer-zep]

# Lifecycle

1. `GL::glGenBuffer()` → non-zero `fd`.
2. `GL::glBindBuffer($target, $buffer)` (stores `target`) + upload via `glBufferData` / `glBufferDataObject`.
3. `GL::glDeleteBuffer($buffer)` zeros `fd` and `size` — see [fd ownership](/conventions/fd-ownership.md).

# Examples

```php
use Opengl\GL\GL;

$vbo = GL::glGenBuffer();
GL::glBindBuffer(0x8892, $vbo); // GL_ARRAY_BUFFER
GL::glBufferDataObject($vbo, $bytes, /* usage */);
// $vbo->fd is the GLuint name
```

[^glbuffer-zep]: glbuffer.zep
[^gl-zep]: gl.zep
