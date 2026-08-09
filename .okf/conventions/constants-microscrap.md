---
type: Convention
title: Constants in microscrap
description: No class constants in the extension; GL enums live in microscrap
tags: [opengl, convention, enums, microscrap]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: readme
    resource: /README.md
    title: README
  - id: gl-zep
    resource: /opengl/gl/gl.zep
    title: gl.zep
  - id: demo
    resource: /examples/proof_menu.php
    title: proof_menu.php
---

# Rule

Do **not** define PHP class constants (or Zephir class constants) for `GL_*` values inside this extension.[^readme][^gl-zep]

House backed enums / constant catalogs in **microscrap** (or another shared PHP package). Call sites pass `int` / enum-backed values into `Opengl\GL\*` methods.

# Why

- Project convention: prefer PHP Enums (FULLY UPPERCASE cases) over class constants.
- Keeps the extension binary smaller and avoids duplicating huge constant tables in C.
- Lets enum packages evolve without rebuilding the extension for every constant add.

# Guidance

```php
// preferred (illustrative)
GL::glClear(GlClearMask::COLOR_BUFFER_BIT->value);

// avoid in this extension
// class GL { public const COLOR_BUFFER_BIT = 0x4000; }
```

The demo currently inlines a few local `const` ints for smoke convenience; production code should prefer microscrap enums.[^demo]

When documenting APIs, say “pass microscrap enum / int” rather than inventing extension constants.

[^readme]: README
[^gl-zep]: gl.zep
[^demo]: proof_menu.php
