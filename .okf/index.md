---
okf_version: "0.2"
---

# ext-opengl

1:1 PHP bindings of the OpenGL calls both dialects share, with CGL on macOS and EGL on Linux. Version 0.10.0.

# API

* [Bindings](api/bindings.md) — Functions and constants by group: state, programs, buffers, textures, draws, CGL, EGL.

# Architecture

* [Contexts](architecture/contexts.md) — CGL and surfaceless EGL, the current-context guard, which handles are released.
* [Data](architecture/data.md) — Lists, strings, addresses, offsets, and the pixel-store size.

# Runbooks

* [Build, install, test](runbooks/build.md) — Mac and Pi installers, the measured Pi driver, Pest.
* [Adding a binding](runbooks/adding-a-binding.md) — Stub, gen_stub, one `.c`, `config.m4`, the surface test.
