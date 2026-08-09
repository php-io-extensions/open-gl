---
type: Convention
title: Committed ext/ notes
description: What to ship for Packagist/PIE
resource: /scripts/prepare-ext.sh
tags: [opengl, packaging, ext]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: composer
    resource: /composer.json
    title: PIE package manifest
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
  - id: patch
    resource: /scripts/patch-config-m4.py
    title: patch-config-m4.py
  - id: fixup
    resource: /scripts/fixup-zephir-register.py
    title: fixup-zephir-register.py
  - id: config-m4
    resource: /ext/config.m4
    title: ext/config.m4
---

# PIE expectation

`composer.json` sets `"build-path": "ext"`.[^composer] Consumers build from the **committed generated tree**.

# Maintainer pipeline (`scripts/prepare-ext.sh`)[^prepare]

1. `zephir generate`
2. Sync `src/*.h` → `ext/src/`
3. `patch-config-m4.py` (portable Darwin `-framework OpenGL` / Linux `-lGL`)
4. `fixup-zephir-register.py` for `Opengl\GL\*` truncation — see [REGISTER trap](/traps/register-class-truncation.md)
5. Strip phpize artifacts (Makefiles, configure, modules, objects, …)

# Critical packaging facts

| Fact | Why |
|------|-----|
| `OPENGL_SHARED_LIBADD` | Framework/`-lGL` must reach the `.so`[^config-m4] |
| Portable `config.m4` | Host-agnostic PIE builds[^patch] |
| REGISTER fixup | Zephir 0.19 truncates nested namespaces (`Opengl\G\*` → `Opengl\GL\*`)[^fixup] |
| No Windows | Match sibling exclude list |

# What not to commit

phpize junk, objects, host-absolute paths. Commit regenerable `ext/` sources + stubs that PIE needs.

[^composer]: PIE package manifest
[^prepare]: prepare-ext.sh
[^patch]: patch-config-m4.py
[^fixup]: fixup-zephir-register.py
[^config-m4]: ext/config.m4
