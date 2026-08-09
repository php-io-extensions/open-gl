---
type: Orientation
title: Stack segmentation
description: Boundaries vs glfw, glew, sdl3, and metal
tags: [opengl, orientation, boundaries]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: readme
    resource: /README.md
    title: README
  - id: composer
    resource: /composer.json
    title: PIE package manifest
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php
  - id: metal-overview
    resource: ../metal/.okf/orientation/overview.md
    title: metal package overview
---

# Who owns what

| Concern | Package | Notes |
|---------|---------|--------|
| Window, input, swap, **GL context** | `php-io-extensions/glfw` (primary demo peer) | Cross-platform window kit |
| Alternate window/GPU path | `php-io-extensions/sdl3` | May create GL or other backends; still not this ext |
| OpenGL **draw API** (`gl*`) | **`php-io-extensions/open-gl`** | Binding only[^readme][^composer] |
| Native macOS window + Metal | `php-io-extensions/metal` | Darwin-only; AppKit + Metal — not OpenGL[^metal-overview] |
| GL extension loading (GLEW-style) | TBD / separate | Do not conflate with this package's public API |
| Enum / constant values | microscrap (PHP enums) | Not compiled into this extension |

# Composition for demos

```text
PHP app
  ├─ glfw   → create window + OpenGL context + poll events
  └─ opengl → glClear / draw / shaders / buffers (this package)
```

Canonical demo: `examples/proof_menu.php` — glfw window + `Opengl\GL\GL` draw + on-screen Quit.[^demo]

Quit UX: OpenGL cannot install a native menu bar. The demo draws an on-screen Quit affordance (and/or uses glfw key/window-close). Contrast with metal, which uses AppKit menus.

# Hard rules

1. Do **not** add GLFW/SDL window APIs to this extension.
2. Do **not** pull Metal/AppKit into this extension.
3. Do **not** `composer require` glfw/sdl3/metal as runtime deps of the extension package — peer composition at the app/example layer only.
4. Keep Windows out of PIE `os-families` (exclude), matching glfw/sdl3 style.

[^readme]: README
[^composer]: PIE package manifest
[^demo]: proof_menu.php
[^metal-overview]: metal package overview
