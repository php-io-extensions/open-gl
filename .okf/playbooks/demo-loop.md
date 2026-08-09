---
type: Playbook
title: Minimal demo loop
description: examples/proof_menu.php — glfw window, Opengl draw, on-screen Quit
resource: /examples/proof_menu.php
tags: [opengl, playbook, demo, glfw]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php
  - id: readme
    resource: /README.md
    title: README
---

# Goal

Prove the extension can draw a scene into a **glfw**-created OpenGL context and offer an on-screen Quit option (OpenGL has no native menus).[^demo]

# Prerequisites

- Built `opengl.so` and peer `glfw` extension loaded
- Working GL drivers on Linux or macOS

# Canonical demo

```bash
php -d extension=./ext/modules/opengl.so examples/proof_menu.php
```

Smoke (auto-quit after N seconds):

```bash
OPENGL_PROOF_SECONDS=5 php -d extension=./ext/modules/opengl.so examples/proof_menu.php
```

Load glfw’s `.so` as well if it is not already installed for the SAPI.

# What the demo does[^demo]

1. glfw: create 960×540 window, hint GL 2.1 any profile, make context current
2. Print `GL::glGetString` vendor / renderer / version
3. Sync viewport to **framebuffer** size (Retina-safe) on resize
4. Loop: clear with animated HSV color; ortho quads for accent + on-screen Quit hit target; swap + poll
5. Quit via: click Quit, Enter/ESC, window close, or `OPENGL_PROOF_SECONDS`
6. Destroy window + `glfwTerminate`

# Acceptance criteria

- Window appears; scene animates; Quit hit-target works.
- Smoke env exits cleanly with `Quit selected — window closed cleanly.`
- No Metal/AppKit symbols; no window APIs inside the opengl extension.
- On Retina, viewport uses framebuffer pixel size — see [Retina trap](/traps/retina-framebuffer.md).

# Verified

macOS Apple M1 Pro (OpenGL 2.1 Metal) — demo path above.

[^demo]: proof_menu.php
[^readme]: README
