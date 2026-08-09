# Directory Update Log

## 2026-08-08
* **Update**: Implementation landed — refreshed OKF against shipped Zephir (`opengl/gl/*.zep`), PIE `composer.json` (`opengl` 0.5.0), `scripts/prepare-ext.sh`, installers, and `examples/proof_menu.php`. Namespace is `Opengl\GL\*` (not `OpenGl`); GPU DTOs are `GlBuffer` / `GlTexture` / `GlShader` / `GlProgram` (not bare `Buffer`/`Texture`/…). API concept files retargeted to `api/glbuffer.md` etc. Demo verified on macOS Apple M1 Pro (GL 2.1 Metal). Status remains `draft` pending Angel human verification of OKF prose.
* **Initialization**: Created OKF v0.2 knowledge bundle for `php-io-extensions/open-gl` from the package brief and sibling format at `metal/.okf` / `glfw` / `sdl3` conventions. Source tree was empty at generation time — API and build paths are planned.
* **Creation**: Orientation (overview, stack segmentation), architecture (stack, zephir+fd, linking), API (GL/Buffer/Texture/Shader/Program), build/packaging, conventions, traps, and playbooks.
* **Note**: Bundle marked `draft` pending Angel human verification after Zephir sources, `scripts/prepare-ext.sh`, and a glfw-backed demo land.

## 2026-08-08
* **Update**: Version bump to **0.7.0** for Packagist/PIE; jetpack installer; ecosystem docs moved to `0.7.x`.
