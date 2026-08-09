# Agent guidance — php-io-extensions/open-gl

1. **Read [`.okf/index.md`](.okf/index.md) first** before changing architecture, API, or packaging.
2. Open only the concept files you need; prefer `status: stable` when present (most are currently `draft`).
3. This package is **Linux + macOS** OpenGL **draw bindings only** — no windowing, no FFI, no class constants (enums → microscrap).
4. Public PHP API: `Opengl\GL\{GL,GlBuffer,GlTexture,GlShader,GlProgram}` — note `Gl*` prefixes and `Opengl` (not `OpenGl`).
5. Opaque GPU names live in public `fd` (`GLuint` as int; `0` = none).
6. Build: `scripts/prepare-ext.sh` (zephir generate → copy `src/*.h` → `patch-config-m4.py` → `fixup-zephir-register.py` → strip phpize junk). Installers: `install-macos.sh`, `install-macos-herd.sh`, `install-debian-trixie.sh`, `install-jetpack6.sh`. Version target: **0.7.0**.
7. Demo: `examples/proof_menu.php` (needs glfw); smoke with `OPENGL_PROOF_SECONDS`.
8. When you learn a durable package fact, **update the matching `.okf` concept**, bump `generated.at`, and append `.okf/log.md`.
9. Do not invent APIs not present in `.zep` / `ext/`.
