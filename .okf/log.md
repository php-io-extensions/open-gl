# Log

## 2026-10-04

Created the bundle for 0.10.0. The extension binds the shared OpenGL 4.1 core / OpenGL ES 3 calls, CGL on macOS, and EGL on Linux. The suite is 21 tests: 271 assertions on Homebrew PHP 8.4 NTS and ZTS, 298 assertions on the Pi (the EGL stub declares more constants than the CGL stub). Gate: stencil-then-cover triangle, 4× MSAA, blit resolve, read back, on CGL and on surfaceless EGL. The hypotenuse is neither solid colour on either. GLES rejects `GL_RGB` into a `GL_RGBA8` texture; the sizing test drains that error.

## 2026-10-05

Added `eglGetCurrentDisplay()`, `eglGetCurrentSurface()`, `EGL_DRAW` and `EGL_READ`: a caller that switches contexts puts back the display and surfaces with the context. Suite 22 tests on the Mac and the Pi (307 assertions there).

Added the four pixel-store skip constants. Strings for uploads and reads are sized with the skips: a skip left by another caller made `glReadPixels` write past a string sized without them. Suite 23 tests on Homebrew PHP 8.4 NTS and ZTS and the Pi.

## 2026-10-06

Added `GL_DRAW_FRAMEBUFFER_BINDING` and `GL_READ_FRAMEBUFFER_BINDING`: a caller reads which framebuffer a toolkit bound before its render callback. Suite 24 tests on the Mac and the Pi.
