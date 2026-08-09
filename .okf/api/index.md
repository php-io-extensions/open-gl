# Public PHP API

All public classes live under `Opengl\GL` (Zephir capitalizes folder `opengl` → `Opengl`). Entry points are **static** methods on `GL`. Named GPU objects are Zephir DTOs with schema fields and opaque `GLuint` in public `fd` — class names are **`Gl*` prefixed**, not bare `Buffer` / `Texture` / `Shader` / `Program`.

**Status:** implemented in source; OKF concepts remain `draft` until Angel marks them `stable`.

* [Opengl\\GL\\GL](gl.md) - Static `gl*` entry points (clear, viewport, fixed-function, buffer/texture/shader/program helpers)
* [Opengl\\GL\\GlBuffer](glbuffer.md) - Buffer object DTO (`fd`, `target`, `size`, `usage`)
* [Opengl\\GL\\GlTexture](gltexture.md) - Texture object DTO (`fd`, `target`, `width`, `height`, `format`)
* [Opengl\\GL\\GlShader](glshader.md) - Shader object DTO (`fd`, `type`, `compiled`)
* [Opengl\\GL\\GlProgram](glprogram.md) - Program object DTO (`fd`, `linked`)
