# Log

## 2026-10-04

Created the bundle for 0.10.0. The extension binds the shared OpenGL 4.1 core / OpenGL ES 3 calls, CGL on macOS, and EGL on Linux. The suite is 21 tests: 271 assertions on Homebrew PHP 8.4 NTS and ZTS, 298 assertions on the Pi (the EGL stub declares more constants than the CGL stub). Gate: stencil-then-cover triangle, 4× MSAA, blit resolve, read back, on CGL and on surfaceless EGL. The hypotenuse is neither solid colour on either. GLES rejects `GL_RGB` into a `GL_RGBA8` texture; the sizing test drains that error.
