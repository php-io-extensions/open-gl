---
type: Convention
title: No FFI
description: Extension-only binding; no PHP FFI fallback path
tags: [opengl, convention, ffi]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: readme
    resource: /README.md
    title: README
  - id: composer
    resource: /composer.json
    title: PIE package manifest
---

# Rule

Ship OpenGL to PHP **only** through this Zephir/C extension. Do not add:

- `FFI::cdef` wrappers as an alternate API
- Dual-path “if extension missing, use FFI” helpers inside this package
- Documented FFI recipes as the supported binding

# Why

Siblings (posi/sdl3/glfw/metal) are PIE php-ext packages with a single compiled surface. FFI would fork maintenance, weaken typing, and confuse packaging.[^readme][^composer]

# Guidance

If someone needs OpenGL without compiling the extension, that is a different product — not a mode of `php-io-extensions/open-gl`.

[^readme]: README
[^composer]: PIE package manifest
