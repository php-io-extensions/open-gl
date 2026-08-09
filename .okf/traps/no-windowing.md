---
type: Trap
title: No windowing here
description: Context, window, and input belong to glfw or sdl3 — not opengl
tags: [opengl, trap, boundaries]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: readme
    resource: /README.md
    title: README
  - id: seg
    resource: /orientation/stack-segmentation.md
    title: Stack segmentation
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php
---

# Symptom

Someone expects `Opengl\GL\*` to create a window, make a context current, poll input, or swap buffers — or PRs start adding GLFW/SDL headers to this package.

# Cause

This extension is **rendering API bindings only** (`gl*`). Windowing is intentionally a peer concern.[^readme][^seg]

# Guidance

- Create window + context with `glfw` (demo default) or `sdl3`.
- Call into `opengl` only after the context is current.
- Implement Quit as on-screen UI and/or glfw key/close — see [proof_menu.php](/playbooks/demo-loop.md).[^demo]
- Reject PRs that couple this tree to window-kit link flags except as documented peer demo deps.

[^readme]: README
[^seg]: Stack segmentation
[^demo]: proof_menu.php
