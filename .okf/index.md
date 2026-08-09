---
okf_version: "0.2"
---

# php-io-extensions/open-gl

Cross-platform (Linux + macOS) PHP extension: Zephir static OpenGL (`gl*`) bindings plus thin data objects (`GlBuffer`, `GlTexture`, `GlShader`, `GlProgram`) that store opaque `GLuint`s in public `fd`. Windowing/context creation belongs to peer extensions (`glfw` / `sdl3`), not this package.

**Prefer** concepts with `status: stable` when present; content is currently `draft` pending Angel’s human verification of the OKF docs (implementation facts are grounded in shipped sources). Demo verified on macOS Apple M1 Pro (GL 2.1 Metal) via `examples/proof_menu.php`.

# Orientation

* [Package overview](orientation/overview.md) - What opengl is, version targets, and what it deliberately is not
* [Stack segmentation](orientation/stack-segmentation.md) - Boundaries vs glfw, glew, sdl3, and metal

# Architecture

* [Layered stack](architecture/stack.md) - Zephir → OpenGL C API → platform GL library
* [Zephir static + fd objects](architecture/zephir-static-and-fd.md) - Static `gl*` mirrors + schema objects with public `fd`
* [Linking OpenGL](architecture/linking-opengl.md) - Darwin `-framework OpenGL` vs Linux `-lGL`

# Public PHP API

* [Opengl\\GL\\GL](api/gl.md) - Static `gl*` entry points (clear, viewport, fixed-function, buffer/texture/shader/program helpers)
* [Opengl\\GL\\GlBuffer](api/glbuffer.md) - Buffer object DTO (`fd`, `target`, `size`, `usage`)
* [Opengl\\GL\\GlTexture](api/gltexture.md) - Texture object DTO (`fd`, `target`, `width`, `height`, `format`)
* [Opengl\\GL\\GlShader](api/glshader.md) - Shader object DTO (`fd`, `type`, `compiled`)
* [Opengl\\GL\\GlProgram](api/glprogram.md) - Program object DTO (`fd`, `linked`)

# Build & packaging

* [Zephir + PIE install](build/zephir-and-pie.md) - prepare-ext, install-macos*.sh, install-debian-trixie.sh, PIE
* [Committed ext/ notes](build/packaging-ext.md) - Portable config.m4, REGISTER fixup, strip phpize junk

# Conventions

* [Sibling patterns](conventions/sibling-patterns.md) - Patterns from posi / sdl3 / glfw / metal (not dependencies)
* [fd ownership](conventions/fd-ownership.md) - Who creates/deletes GLuints behind `fd`
* [No FFI](conventions/no-ffi.md) - Extension-only binding; no PHP FFI fallback
* [Constants in microscrap](conventions/constants-microscrap.md) - No class constants; enums live elsewhere

# Traps

* [No windowing here](traps/no-windowing.md) - Context/window/input are glfw or sdl3
* [macOS OpenGL deprecation](traps/macos-deprecation.md) - Framework still links; Apple marks GL deprecated
* [Retina framebuffer vs window size](traps/retina-framebuffer.md) - Drawable pixels ≠ window points with glfw
* [REGISTER_CLASS truncation](traps/register-class-truncation.md) - Zephir 0.19 may truncate `Opengl\\GL\\*`

# Playbooks

* [Minimal demo loop](playbooks/demo-loop.md) - examples/proof_menu.php + OPENGL_PROOF_SECONDS
* [Regenerate committed ext/](playbooks/regenerate-ext.md) - Maintainer steps before tagging

# Indexes

* [Orientation](orientation/) — start here
* [Architecture](architecture/)
* [API](api/)
* [Build](build/)
* [Conventions](conventions/)
* [Traps](traps/)
* [Playbooks](playbooks/)
