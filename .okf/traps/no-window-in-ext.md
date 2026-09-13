---
type: Trap
title: No window in the extension
description: ext-opengl creates contexts and draws. It never opens a window, and windowed paths belong to other repos' waves.
tags: [trap, scope, layering]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# No window in the extension

This extension has no window, no event loop, no input, no display-server
connection, and no dependency on one. `examples/proof_headless.php` renders a
shaded triangle into a texture on both boxes with nothing on screen, over ssh
on the Pi, with no seat and no `DISPLAY`.

That is not an accident of the current wave. It is the scope line:

- **`OpenGL\EGL\EGL` and `OpenGL\CGL\CGL` create contexts, not windows.** The
  bound surface includes `eglCreateWindowSurface` and `CGLSetFullScreen`
  because they are in the headers and nothing is silently omitted — but this
  repo never *calls* them, and providing a window for them to attach to is
  not this repo's job.
- **Windowed GL belongs to the repo that owns the window.** `GtkGLArea` is an
  ext-gtk wave; `NSOpenGLView` is an ext-appkit wave. When they land, they
  will hand a native handle across as pointer bits — the same seam ext-metal
  uses for `CAMetalLayer` → ext-appkit — and this extension will not learn
  about it.
- **Choosing EGL or CGL is the caller's decision, not the extension's.**
  Both classes exist on both platforms (every entry point is runtime-resolved),
  and the only `PHP_OS_FAMILY` branch in this repo's PHP is one function in
  the proof. A convenience that picked a context API for you would be an
  opinion, and opinions live in Surface.

## Why this matters for testing

Because there is no window, the proof is a *byte check*, not a screenshot:
draw, `glReadPixels` into a Bridge buffer, assert the centre pixel is the
shader colour and the corner is the clear colour. That runs identically over
ssh, in CI, and on a headless box — which is how the Pi half of this repo is
verified at all.

If a future change makes the proof need a seat, the change is wrong.
