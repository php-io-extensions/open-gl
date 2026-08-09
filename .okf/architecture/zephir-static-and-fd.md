---
type: Architecture
title: Zephir static + fd objects
description: Static gl* mirrors plus Gl* schema classes with public fd (GLuint)
tags: [opengl, architecture, zephir, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: gl-zep
    resource: /opengl/gl/gl.zep
    title: gl.zep
  - id: glbuffer-zep
    resource: /opengl/gl/glbuffer.zep
    title: glbuffer.zep
  - id: sibling
    resource: /conventions/sibling-patterns.md
    title: Sibling patterns
---

# Two surfaces

| Kind | Example | Pattern |
|------|---------|---------|
| Static API class | `Opengl\GL\GL` | Static methods mirroring C `glClear`, `glDrawArrays`, … |
| Data objects | `GlBuffer`, `GlTexture`, `GlShader`, `GlProgram` | Zephir DTOs with typed schema fields + public `int $fd` |

# `fd` meaning

- `fd` is a **public int** holding the opaque OpenGL name (`GLuint`).
- Name chosen for consistency with other php-io-extensions “opaque handle as int” habits.[^gl-zep][^glbuffer-zep]
- `0` is the OpenGL “no object” / deleted sentinel.

# Ownership sketch

```text
$buf = GL::glGenBuffer();        // GLuint in $buf->fd
GL::glBindBuffer($target, $buf); // methods accept GlBuffer and read ->fd
// later
GL::glDeleteBuffer($buf);        // deletes GL name and zeros fd
```

See [fd ownership](/conventions/fd-ownership.md) and API concepts under `/api/`.

# What stays out of Zephir classes

- No PHP class-level constants for `GL_*` enums.
- No FFI stubs or dual-path loaders inside the extension.

[^gl-zep]: gl.zep
[^glbuffer-zep]: glbuffer.zep
[^sibling]: Sibling patterns
