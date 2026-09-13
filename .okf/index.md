---
okf_version: "0.2"
---

# opengl — knowledge bundle

Faithful 1:1 binding of OpenGL core 1.0 .. 4.1 into PHP, plus the two
OS-native context APIs (EGL on Linux, CGL on macOS). One `.so` serves a GL
3.1 Pi and a GL 4.1 Mac, because every entry point is resolved at runtime.

Read this index first, then open only the concepts the task needs.

- [binding-rules.md](/binding-rules.md) — design decisions D1 (surface and
  grouping), D2 (the pointer line), D3 (context APIs) restated as law, with
  the full translation table and the per-class counts.
- [bridge.md](/bridge.md) — the only glue: the runtime loader, the version
  gate, and the byte buffers.
- [toolchain.md](/toolchain.md) — headers → src → zep → .so, its guards,
  and the Mac-generates / Pi-builds split.
- [traps/index.md](/traps/index.md) — runtime-resolution-not-linking,
  version-ceilings, pointer-bits-only, no-window-in-ext.
- [log.md](/log.md) — change log; 0.8.0's entry says what was built, what
  was deviated from, and what is deliberately left for a later wave.

## Scope

GL only, and only the parts that need native code. No window, no display
server, no event loop, no constants, no convenience: `examples/proof_headless.php`
renders a triangle to a texture on both boxes with no window anywhere.

**Bound (0.8.0):** 479 GL core prototypes across `OpenGL\GL\GL10\GL10` ..
`OpenGL\GL\GL41\GL41` (one class per version block), 44 EGL 1.0 .. 1.5
prototypes as `OpenGL\EGL\EGL`, 50 of CGL's 52 as `OpenGL\CGL\CGL`, and 8
`OpenGL\Bridge\Bridge` glue calls. **581 static methods, 17 classes, 2
reserved.**

The pointer rule leaves nothing in the GL or EGL surface unbindable. The two
reservations are CGL prototypes whose types belong to frameworks this binding
does not include — `CGLGetDeviceFromGLRenderer` (`cl_device_id`, OpenCL) and
`CGLTexImageIOSurface2D` (`IOSurfaceRef`, IOSurface.framework) — and they are
visible `@reserved` lines counted by the audit, not omissions.

**Deferred:** `GL_VERSION_4_2` .. `GL_VERSION_4_6`, 178 prototypes. A later
wave, recorded by the audit as deferred rather than missing; see
[traps/version-ceilings.md](/traps/version-ceilings.md).

**Out of scope, permanently:** extension blocks (`GL_ARB_*`, `GL_NV_*`, …);
windowed context paths (GtkGLArea, NSOpenGLView) which belong to ext-gtk and
ext-appkit; constants and PHP enums, which live in **jovian/ogx**.

Layering, verbatim house law: **ext-opengl = OpenGL + unavoidable glue;
jovian/ogx = PHP projection and constants; venusian = composition; surface =
abstraction.**
