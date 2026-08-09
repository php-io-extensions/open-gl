---
type: Architecture
title: Linking OpenGL
description: Darwin -framework OpenGL vs Linux -lGL; Windows excluded
resource: /ext/config.m4
tags: [opengl, architecture, link, packaging]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: config-m4
    resource: /ext/config.m4
    title: Portable ext/config.m4
  - id: patch
    resource: /scripts/patch-config-m4.py
    title: patch-config-m4.py
  - id: composer
    resource: /composer.json
    title: PIE package manifest
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
---

# Platform link line

| OS | Link | Notes |
|----|------|--------|
| macOS (Darwin) | `-framework OpenGL` via `OPENGL_SHARED_LIBADD` | System framework; still available though deprecated by Apple — see [macOS deprecation](/traps/macos-deprecation.md) |
| Linux | `-lGL` via `PHP_EVAL_LIBLINE` → `OPENGL_SHARED_LIBADD` | Typically Mesa / system OpenGL |
| Windows | **Excluded** | `os-families-exclude: ["windows"]`[^composer] |

`ext/config.m4` is PIE-ready: portable Darwin framework / Linux `-lGL` branch written by `scripts/patch-config-m4.py` during prepare.[^config-m4][^patch]

# Packaging notes

- Link flags go on the **shared module** (`OPENGL_SHARED_LIBADD`), not only compiler flags.
- `scripts/prepare-ext.sh` regenerates sources and re-applies the portable `config.m4` patch.[^prepare]
- Consumers install via PIE from committed `ext/`; maintainers regenerate with Zephir first.

# Runtime prerequisite

Linking succeeds without a current context, but **calls** require a current OpenGL context from glfw/sdl3. Linking OpenGL does not create a window.

[^config-m4]: Portable ext/config.m4
[^patch]: patch-config-m4.py
[^composer]: PIE package manifest
[^prepare]: prepare-ext.sh
