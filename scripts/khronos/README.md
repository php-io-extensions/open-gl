# Vendored Khronos headers — the audit truth

ext-gtk audits its bindings against vendored GObject-Introspection XML.
OpenGL has no such thing, so these two headers are this repo's equivalent:
`scripts/gen-gl-src.php` translates them into `src/`, and
`scripts/audit-header.php` re-measures every `@audit block` marker against
them. Nothing else decides what this extension exposes.

They are vendored rather than read from the build box for the reason gtk
vendors its girs: the surface must not change because someone upgraded a
`-dev` package. Re-vendoring is a deliberate act, and the audit fails loudly
when the counts move (`scripts/tests/audit-guard.php` proves that).

## glcorearb.h

| | |
|---|---|
| Source | `/usr/include/GL/glcorearb.h` on the Pi 5 build box |
| Package | `libgl-dev:arm64 1.7.0-1+b2` (Debian 13 trixie) |
| Upstream | Khronos OpenGL Registry, generated from the API XML |
| Copyright | 2013-2020 The Khronos Group Inc., SPDX `MIT` |
| md5 | `129d6c3fb6d5a3ce56c6a2ad7148fb63` |
| Harvested | 2026-09-13 |

Bound: `GL_VERSION_1_0` .. `GL_VERSION_4_1`, 479 prototypes —
48, 14, 4, 9, 9, 19, 93, 6, 84, 12, 19, 28, 46, 88.

Deferred to a later wave: `GL_VERSION_4_2` .. `GL_VERSION_4_6`, 178
prototypes — 12, 43, 9, 110, 4. The audit reports them as deferred rather
than as a shortfall.

Out of scope entirely: every `GL_ARB_*`, `GL_NV_*`, … extension block in this
file. The header is vendored whole anyway, so re-vendoring is a single copy
and the scope decision lives in the generator, not in a trimmed file.

## egl.h

| | |
|---|---|
| Source | `/usr/include/EGL/egl.h` on the Pi 5 build box |
| Package | `libegl-dev:arm64 1.7.0-1+b2` (Debian 13 trixie) |
| Upstream | Khronos EGL Registry, git `8c62b915dd`, 2021-11-05 |
| Copyright | 2013-2020 The Khronos Group Inc., SPDX `Apache-2.0` |
| md5 | `aa732b7becd0d3baaef09c5e57575ecf` |
| Harvested | 2026-09-13 |

Bound: `EGL_VERSION_1_0` .. `EGL_VERSION_1_5`, 44 prototypes —
24, 4, 5, 0, 1, 10. (`EGL_VERSION_1_3` declares constants only.)

`eglplatform.h` and `eglext.h` are deliberately **not** vendored: the binding
never includes a window-system header, and no extension entry point is bound.
`src/egl-types.h` carries the ABI of the EGL types the bound prototypes use,
generated from this file.

## CGL — not vendored

`OpenGL\CGL\CGL` is audited against the live
`OpenGL.framework/Headers/{OpenGL.h,CGLCurrent.h,CGLTypes.h,CGLContext.h}`
in the macOS SDK, the same way ext-metal audits against the live Metal SDK
headers. Apple's headers are not redistributed here.

Consequences, both by design:

- `scripts/gen-gl-src.php` and `scripts/audit-header.php` re-measure CGL only
  on Darwin. On Linux they print a SKIP note and leave the committed
  `src/cgl.{h,c}` alone — generation is a Mac-side job anyway.
- The generated `src/cgl.{h,c}` and `src/cgl-types.h` are committed, so the
  Linux build compiles the CGL class like any other. Every CGL entry point is
  resolved at runtime, so on Linux they simply never resolve and warn.

Note that `CGLContext.h` and `CGLTypes.h` declare no functions at all (0 and
0); the 49 CGL prototypes are 47 in `OpenGL.h` plus 2 in `CGLCurrent.h`. The
design named the first three headers; `OpenGL.h` was added because that is
where the functions actually live.
