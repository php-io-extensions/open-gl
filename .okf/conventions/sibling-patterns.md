---
type: Convention
title: Sibling patterns
description: Patterns from posi / sdl3 / glfw / metal (not dependencies)
tags: [opengl, convention, packaging]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: composer
    resource: /composer.json
    title: composer.json
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
  - id: metal-sibling
    resource: ../metal/.okf/conventions/sibling-patterns.md
    title: metal sibling patterns
---

# Borrowed patterns (style only)

| Pattern | From | How open-gl uses it |
|---------|------|---------------------|
| Thin Zephir static classes | posi / sdl3 / glfw | `Opengl\GL\GL::*` mirrors C |
| Opaque int handles | sdl3 / glfw / metal | GPU names as `fd` on `Gl*` DTOs |
| PIE `type: php-ext`, `build-path: ext` | sdl3 / glfw / posi | Same layout in `composer.json`[^composer] |
| `prepare-ext.sh` + REGISTER fixup | metal / siblings | Zephir generate → portable `ext/`[^prepare] |
| Version `0.5.0`, PHP ≥ 8.2 | siblings | Aligned release |
| Windows excluded | glfw / sdl3 | `os-families-exclude: ["windows"]` |
| IDE stubs path | sdl3 | `ide/0.5.0/Opengl/GL/` |

# Not borrowed

- No AppKit/Metal/ObjC bridge (that is metal only).[^metal-sibling]
- No window/context APIs (glfw/sdl3).
- No composer `require` on peer extensions — demos compose them.

Keep boundaries explicit in docs and CI so opengl never grows accidental windowing or Metal coupling.

[^composer]: composer.json
[^prepare]: prepare-ext.sh
[^metal-sibling]: metal sibling patterns
