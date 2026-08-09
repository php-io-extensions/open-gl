---
type: Architecture
title: Layered stack
description: Zephir → OpenGL C API → platform GL library
resource: /config.json
tags: [opengl, architecture, zephir]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: config
    resource: /config.json
    title: Zephir config
  - id: gl-zep
    resource: /opengl/gl/gl.zep
    title: gl.zep
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
  - id: composer
    resource: /composer.json
    title: PIE package manifest
---

# Layers

```text
PHP (Opengl\GL\{GL,GlBuffer,GlTexture,GlShader,GlProgram})
        │  Zephir static methods + thin DTO classes with public fd
        ▼
OpenGL C API (opengl-compat.h / platform headers)
        │
        ▼
Platform GL library
   Darwin: OpenGL.framework
   Linux:  libGL (and related)
```

Unlike [metal](../metal/), there is **no** Objective-C bridge layer. Zephir calls C OpenGL directly (posi/sdl3/glfw style).[^gl-zep]

# Source map

| Layer | Path | Role |
|-------|------|------|
| Zephir | `opengl/gl/{gl,glbuffer,gltexture,glshader,glprogram}.zep` | Public PHP API |
| C headers | `src/*.h` → synced to `ext/src/` | Compat / helpers |
| Zephir config | `config.json` | Extension metadata |
| Packaging | `scripts/prepare-ext.sh` | Generate + patch into `ext/` |
| PIE | `composer.json` | `build-path: ext`, Linux+Darwin |

# Design intent

- Keep Zephir thin: static methods map 1:1 to `gl*` where practical (`GL::glClear`, …).
- Data objects hold schema + opaque `GLuint` in `fd` — see [Zephir static + fd](/architecture/zephir-static-and-fd.md).
- Context must already be current (created by glfw/sdl3) before calling into this extension.
- Constants stay out of the extension — see [Constants in microscrap](/conventions/constants-microscrap.md).

[^config]: Zephir config
[^gl-zep]: gl.zep
[^prepare]: prepare-ext.sh
[^composer]: PIE package manifest
