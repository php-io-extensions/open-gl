# php-open-gl

[![PHP](https://img.shields.io/badge/php-%E2%89%A5%208.2-777bb4?logo=php&logoColor=white)](https://www.php.net)
[![Built with Zephir](https://img.shields.io/badge/built%20with-Zephir-ff6a00)](https://zephir-lang.com/)
[![Platform](https://img.shields.io/badge/platform-linux%20%7C%20macOS-lightgrey)](#requirements)
[![License: MIT](https://img.shields.io/badge/license-MIT-green)](#license)

> PHP extension for the OpenGL **rendering API** — built with [Zephir](https://zephir-lang.com/), installable via [PHP PIE](https://github.com/php/pie).

`opengl` exposes `gl*` entry points to PHP 8.2+ under `Opengl\GL\…`. It is the
draw half of ScrapyardIO's Windowed Visual Output stack. Window/context creation
stays in peer packages (`php-io-extensions/glfw`, `php-io-extensions/sdl3`).

OpenGL `#define` tokens live in a companion microscrap wrapper, not in this
extension.

---

## Requirements

| Component            | Minimum version | Notes                                                                  |
| -------------------- | --------------- | ---------------------------------------------------------------------- |
| PHP                  | 8.2             | ZTS and NTS builds both supported.                                     |
| OpenGL               | system          | macOS `OpenGL.framework` or Linux Mesa (`libgl1-mesa-dev`).             |
| OS                   | Linux / macOS   | x86_64 + aarch64. Windows is not currently supported.                  |
| Compiler             | C11 toolchain   | `gcc`, `clang`, or Apple Clang.                                        |
| `php-dev` / `phpize` | matches PHP     | Required for any build path that is not PIE.                           |

---

## Installation

### Via PHP PIE (recommended)

```bash
pie install php-io-extensions/open-gl
```

### Platform installers

**macOS** (Homebrew / system frameworks):

```bash
bash install-macos.sh
# or with Laravel Herd on PATH:
bash install-macos-herd.sh
```

**Debian Trixie / Raspberry Pi OS**:

```bash
bash install-debian-trixie.sh
```

**JetPack 6 / Ubuntu 22.04** (Jetson):

```bash
bash install-jetpack6.sh
```

### Manual build with Zephir (maintainers)

```bash
bash scripts/prepare-ext.sh
cd ext && phpize && ./configure --enable-opengl && make
php -n -d extension="$(pwd)/modules/opengl.so" --ri opengl
```

`scripts/prepare-ext.sh` regenerates C sources, patches portable `ext/config.m4`
(Darwin `-framework OpenGL` / Linux `-lGL`), applies Zephir 0.19 REGISTER fixups
when needed, and strips phpize junk so absolute host paths never ship.

---

## Quick start

```php
<?php
use Opengl\GL\GL;

// Requires a current OpenGL context from glfw/sdl3 first.
GL::glClearColor(0.1, 0.2, 0.3, 1.0);
GL::glClear(0x00004000); // GL_COLOR_BUFFER_BIT — prefer microscrap enums
```

### Named objects (`fd`)

Buffers, textures, shaders, and programs are Zephir objects. The opaque GLuint
name is stored on public `fd` (0 = none), matching the posi/ftdi handle style:

```php
$buffer = GL::glGenBuffer();
GL::glBindBuffer(0x8892, $buffer); // GL_ARRAY_BUFFER
// $buffer->fd is the GLuint name
```

### Examples

```bash
# Visual window + on-screen Quit menu (needs glfw + opengl)
OPENGL_PROOF_SECONDS=5 php examples/proof_menu.php
```

---

## API surface

| Class | Namespace | Role |
| ----- | --------- | ---- |
| `GL` | `Opengl\GL` | Static `gl*` passthrough (clear, viewport, fixed-function draw, buffer/texture/shader/program helpers) |
| `GlBuffer` | `Opengl\GL` | Buffer object DTO (`fd`, `target`, `size`, `usage`) |
| `GlTexture` | `Opengl\GL` | Texture object DTO (`fd`, `target`, `width`, `height`, `format`) |
| `GlShader` | `Opengl\GL` | Shader object DTO (`fd`, `type`, `compiled`) |
| `GlProgram` | `Opengl\GL` | Program object DTO (`fd`, `linked`) |

### Binding conventions

- Opaque GLuint names → object `fd` (`int`) or plain `int` where noted
- Static methods mirror C names (`glClear`, `glGenBuffer`, …)
- Hard failures from context-less calls surface as OpenGL errors via `glGetError`
- No FFI

### What this package is not

- Not a windowing library (use `glfw` / `sdl3`)
- Not an extension loader (GLEW/glad — future slice)
- Not Metal / Vulkan / CUDA

---

## Version

**0.7.0** — ecosystem docs line `0.7.x`. IDE stubs under `ide/0.7.0/`.

## License

MIT — see [LICENSE](LICENSE).
