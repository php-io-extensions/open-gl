---
type: Playbook
title: Zephir + PIE install
description: Generate, prepare-ext, configure, install on Linux and macOS
resource: /composer.json
tags: [opengl, build, pie, zephir]
status: draft
generated: { by: okf-documentation-generator/cursor-grok-4.5-high, at: 2026-08-09T00:01:00Z }
sources:
  - id: composer
    resource: /composer.json
    title: PIE package manifest
  - id: prepare
    resource: /scripts/prepare-ext.sh
    title: prepare-ext.sh
  - id: install
    resource: /install-macos.sh
    title: install-macos.sh
  - id: herd
    resource: /install-macos-herd.sh
    title: install-macos-herd.sh
  - id: debian
    resource: /install-debian-trixie.sh
    title: install-debian-trixie.sh
  - id: readme
    resource: /README.md
    title: README
  - id: config-m4
    resource: /ext/config.m4
    title: Portable ext/config.m4
---

# Requirements

| Component | Notes |
|-----------|--------|
| OS | Linux or macOS (Windows excluded) |
| PHP | ≥ 8.2 with matching `phpize` / headers |
| OpenGL | Darwin framework or Linux `libGL` / Mesa headers |
| Zephir | For regenerating `ext/` (`ZEPHIR_BIN` optional) |
| Peer (demos) | `glfw` extension for window/context |

# PIE (consumers)

```bash
pie install php-io-extensions/open-gl
```

Uses `type: php-ext`, `extension-name: opengl`, `build-path: "ext"`, `--enable-opengl`.[^composer]

# Platform installers

```bash
bash install-macos.sh
bash install-macos-herd.sh      # Laravel Herd
bash install-debian-trixie.sh   # Debian Trixie / Raspberry Pi OS
```

[^install][^herd][^debian]

# Manual maintainer build

```bash
bash scripts/prepare-ext.sh
cd ext && phpize && ./configure --enable-opengl && make
php -n -d extension="$(pwd)/modules/opengl.so" --ri opengl
```

`prepare-ext.sh`: `zephir generate` → copy `src/*.h` → `ext/src/` → `patch-config-m4.py` → `fixup-zephir-register.py` → strip phpize junk.[^prepare]

# Verify

```bash
php -n -d extension=./ext/modules/opengl.so --ri opengl
OPENGL_PROOF_SECONDS=5 php -d extension=./ext/modules/opengl.so examples/proof_menu.php
```

Demo also needs the `glfw` extension loaded — see [demo loop](/playbooks/demo-loop.md).

[^composer]: PIE package manifest
[^prepare]: prepare-ext.sh
[^install]: install-macos.sh
[^herd]: install-macos-herd.sh
[^debian]: install-debian-trixie.sh
[^readme]: README
[^config-m4]: Portable ext/config.m4
