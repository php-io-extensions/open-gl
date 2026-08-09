---
type: CoreType
title: Opengl\\GL\\GlTexture
description: Texture object DTO with public fd, target, width, height, format
resource: /opengl/gl/gltexture.zep
tags: [opengl, api, texture, fd]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: gltexture-zep
    resource: /opengl/gl/gltexture.zep
    title: gltexture.zep
  - id: gl-zep
    resource: /opengl/gl/gl.zep
    title: gl.zep
---

# Schema

| Field | Type | Notes |
|-------|------|--------|
| `fd` | `int` (public) | Opaque `GLuint` texture name; `0` = none / deleted |
| `target` | `int` (public) | Last bind target (e.g. `GL_TEXTURE_2D`); `0` = unset |
| `width` | `int` (public) | Width in texels (`0` until set by caller after upload) |
| `height` | `int` (public) | Height in texels |
| `format` | `int` (public) | Internal / base format hint stored by caller (e.g. `GL_RGBA`) |

Class name is **`GlTexture`**, not `Texture`.[^gltexture-zep]

# Lifecycle

1. `GL::glGenTexture()` → non-zero `fd`.
2. `GL::glBindTexture($target, $texture)` + `glTexParameteri` / upload (caller may set `width`/`height`/`format`).
3. `GL::glDeleteTexture($texture)` zeros `fd`.

# Notes

- Retina demos: texture/framebuffer sizes follow **pixel** dimensions, not window points — see [Retina framebuffer](/traps/retina-framebuffer.md).

[^gltexture-zep]: gltexture.zep
[^gl-zep]: gl.zep
