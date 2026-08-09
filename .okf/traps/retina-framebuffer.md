---
type: Trap
title: Retina framebuffer vs window size
description: With glfw on HiDPI, drawable pixels differ from window points
tags: [opengl, trap, retina, glfw, viewport]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php
---

# Symptom

Scene draws in a corner, looks blurry, or hit-testing for on-screen Quit is wrong on Mac Retina (and other HiDPI) while window size looks “correct.”

# Cause

glfw window size is often in **screen coordinates (points)**. The OpenGL framebuffer / backbuffer size is in **pixels**, commonly 2× on Retina. `glViewport` and scissor must use framebuffer dimensions; UI hit-testing in the demo uses **logical window** coords with `glOrtho(0, winW, 0, winH)`.[^demo]

# Guidance

1. After creating the window/context, query glfw framebuffer size (not only window size).
2. Set `GL::glViewport(0, 0, $fbW, $fbH)` on resize (as `proof_menu.php` does).
3. Keep on-screen Quit hit boxes in the same coordinate space used for ortho drawing.
4. Do not hard-code 800×600 pixels from window size alone.

[^demo]: proof_menu.php
