---
type: Orientation
title: Package overview
description: What opengl is, version targets, and what it deliberately is not
resource: /composer.json
tags: [opengl, orientation, php-ext]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: composer
    resource: /composer.json
    title: PIE package manifest
  - id: config
    resource: /config.json
    title: Zephir config
  - id: readme
    resource: /README.md
    title: README
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php
---

# Summary

`php-io-extensions/open-gl` is a **Linux + macOS** PHP extension (`type: php-ext`) that exposes the OpenGL **rendering API** (`gl*`) to PHP via Zephir. Windowing and GL context creation are **out of scope** — demos pair this extension with peer `glfw` (or optionally `sdl3`).[^composer][^readme]

| Fact | Value |
|------|--------|
| Package | `php-io-extensions/open-gl` |
| Extension name | `opengl` |
| Version | `0.5.0` |
| PHP | `>= 8.2` |
| OS | Linux + Darwin; Windows excluded (`os-families-exclude: ["windows"]`) |
| Namespace | `Opengl\GL\*` (Zephir capitalizes folder `opengl` → `Opengl`) |
| Author | Project Saturn Studios, LLC |
| License | MIT |
| Binding | Zephir only — **no FFI** |

# End capability (v0.5)

1. Call OpenGL entry points as static methods on `Opengl\GL\GL` (mirroring C `gl*`).
2. Hold GPU objects as Zephir DTOs (`GlBuffer`, `GlTexture`, `GlShader`, `GlProgram`) with schema fields and opaque `GLuint` in public `fd` (int).
3. Draw a scene into a context created by `glfw` (or `sdl3`), including an on-screen Quit control (OpenGL has no native menus).
4. Link platform GL: Darwin `-framework OpenGL`, Linux `-lGL` (PIE-ready `ext/config.m4`).

Demo: `examples/proof_menu.php` (optional `OPENGL_PROOF_SECONDS` auto-quit). Verified on macOS Apple M1 Pro (GL 2.1 Metal).[^demo]

# What it is not

- Not a windowing / input / context library — that is [glfw](../glfw/) or [sdl3](../sdl3/).
- Not Apple Metal — that is [metal](../metal/).
- Not a GLEW replacement as a product boundary (loader policy TBD; do not assume GLEW is bundled).
- Not available on Windows.
- Not an FFI wrapper and not a place for PHP class constants (constants → microscrap enums).

# Public namespace

Zephir classes live under `Opengl\GL\` (`opengl/gl/*.zep`). IDE stubs: `ide/0.5.0/Opengl/GL/`.

See [Stack segmentation](/orientation/stack-segmentation.md) and [Layered stack](/architecture/stack.md).

[^composer]: PIE package manifest
[^readme]: README
[^demo]: proof_menu.php
[^config]: Zephir config
