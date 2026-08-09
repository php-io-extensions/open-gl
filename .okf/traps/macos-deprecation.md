---
type: Trap
title: macOS OpenGL deprecation
description: OpenGL.framework still links on Darwin but Apple marks the API deprecated
tags: [opengl, trap, darwin, deprecation]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: config-m4
    resource: /ext/config.m4
    title: ext/config.m4
  - id: link
    resource: /architecture/linking-opengl.md
    title: Linking OpenGL
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php
---

# Symptom

Compiler warnings about OpenGL deprecation on macOS; future SDK may harden further. Confusion with the **metal** package (native modern path on Darwin).

# Cause

Apple deprecated OpenGL in favor of Metal. The framework remains linkable for this package’s Linux+macOS GL binding goal, but it is not Apple’s forward path.[^config-m4][^link]

# Guidance

- Still link `-framework OpenGL` for Darwin builds of **this** extension (`GL_SILENCE_DEPRECATION` is set in `config.m4`).
- Prefer `php-io-extensions/metal` when the product goal is a native macOS renderer with AppKit menus.
- Demo verified on Apple M1 Pro via the system OpenGL 2.1 (Metal) path — deprecated, still works.[^demo]
- Keep CI on current Xcode; revisit if Apple removes headers/libs.

[^config-m4]: ext/config.m4
[^link]: Linking OpenGL
[^demo]: proof_menu.php
