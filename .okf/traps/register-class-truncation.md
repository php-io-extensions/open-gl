---
type: Trap
title: REGISTER_CLASS truncation
description: Zephir 0.19 may truncate Opengl\\GL\\* in ZEPHIR_REGISTER_CLASS
tags: [opengl, trap, zephir, register]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: fixup
    resource: /scripts/fixup-zephir-register.py
    title: fixup-zephir-register.py
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
---

# Symptom

Extension builds but classes are missing/wrong (`Class "Opengl\GL\GlBuffer" not found`), or `ZEPHIR_REGISTER_CLASS` lines show shortened namespaces (e.g. `Opengl\G\…` analogous to metal’s `Metal\MT\*` truncation of `Metal\MTL\*`).[^fixup]

# Cause

Zephir 0.19 has truncated nested namespace segments when emitting register macros. Metal required a fixup after `zephir generate`. `Opengl\GL\*` is the same risk class (`Opengl\G\GlBuffer`, etc.).

# Guidance

1. After `zephir generate`, run `scripts/fixup-zephir-register.py` mapping truncated forms → `Opengl\GL\{GL,GlBuffer,GlTexture,GlShader,GlProgram}`.
2. Wire is already in `scripts/prepare-ext.sh` — do not skip it.[^prepare]
3. Smoke with `php --ri opengl` and `class_exists('Opengl\\GL\\GlBuffer')` before tagging.
4. Do not “fix” by renaming the public namespace away from `Opengl\GL` without an explicit product decision — prefer the fixup script.

[^fixup]: fixup-zephir-register.py
[^prepare]: prepare-ext.sh
