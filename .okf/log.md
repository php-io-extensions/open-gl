# Change log

## 2026-09-13 — review pass: fifteen fixes

External review of 0.8.0 came back "with fixes": the binding core, the
counts and the buffer guards held (18 misuse probes), and fifteen things
needed doing. All of them, in one pass, re-verified on both boxes.

### The two that could have bitten hard

**`Bridge::alloc` could kill the process.** `pemalloc` routes a failed
allocation through `zend_out_of_memory()`, which prints and calls `exit(1)`,
so `Bridge::alloc(PHP_INT_MAX)` took the interpreter down. Worse, the
`> SIZE_MAX` guard that looked like it prevented that was **dead code on
64-bit**, where `zend_long` and `size_t` are the same width — it could never
be true. Now plain `malloc` + a `NULL` check + `E_WARNING` + `0`. Probed:
`PHP_INT_MAX`, `1<<62`, `1<<50`, `0`, `-1` all warn and return 0 with the
process alive, and a real 64-byte allocation still round-trips.

**The loader never re-resolved anything.** A slot that once resolved to
"missing" latched `state = 2` for the life of the process, and the
current-context probe table sat behind a `static int probed` that froze on
first use — so `Bridge::load()` re-opened libraries and then served stale
answers about them. Both are now keyed on a generation counter that
`load()` (and the new teardown) bumps. `scripts/tests/loader-guard.php`
asserts the wiring and exercises the observable half; the slot half is
honestly labelled as structurally checked, because making it observable
needs a symbol that is absent and then present in one process.

### The doc that was telling a lie

`.okf/traps/runtime-resolution-not-linking.md` claimed the `-lEGL -lGL -ldl`
/ `-framework OpenGL` line existed "so the loader has a soname to dlopen".
That is not how `dlopen` works — the dynamic loader searches by soname from
the runtime search path and does not care what this module was linked
against. The link line is **kept** (ruling upheld) but now described as what
it is: a declaration of which platform runtime the extension is for.
Measured on the built artefacts rather than asserted:

- Darwin: `otool -L` shows a real load command for OpenGL.framework — a
  framework links whether or not a symbol is used, so it *is* a load-time
  dependency there.
- Linux: `ldd` shows only libc and the loader. `--as-needed` drops
  `-lEGL`/`-lGL` because nothing references them; `-ldl` is empty on
  glibc ≥ 2.34.
- `nm -u` lists **no** undefined `gl*`/`egl*`/`CGL*` symbol on either box.

The GL runtime is a **requirement**, not a warning path: state it that way
when packaging. The same correction was applied to README, binding-rules,
toolchain, `patch-config-m4.php` and `build-linux.sh`.

Note for the record: the review's rationale for keeping the line was that
"egl.c/cgl.c call those APIs directly". They do not — every EGL and CGL
entry point goes through `phpgl_entry()` like every GL one, which the parity
guard and `nm -u` both confirm. The ruling stands; the reason in the doc is
the measured one.

### Nothing silently omitted, for real this time

**`@reserved` emission did not exist.** The generator's docstring described
it; `renderBinding()` called `fail()` instead. Implemented, with a
deliberate split: a **callback** parameter or a **foreign** type (one owned
by a framework this binding does not include) becomes a visible `@reserved`
line the audit counts; **anything else** unmapped still stops the generator
by name, so a new scalar spelling cannot quietly shrink the surface.
`scripts/tests/reserved-guard.php` proves both halves — the first against a
scratch copy with the ceiling raised to 4.3, which emits

```
/*@reserved GL\GL43 void glDebugMessageCallback(GLDEBUGPROC callback, const void * userParam) — GLDEBUGPROC is a callback; PHP cannot be a C function pointer */
```

and keeps the audit sum exact (43 = 42 + 1). The real tree stays at 4.1.

**Three CGL functions were invisible.** `CGLDevice.h` and `CGLIOSurface.h`
were audited by nobody, so `CGLGetShareGroup`, `CGLGetDeviceFromGLRenderer`
and `CGLTexImageIOSurface2D` were neither bound nor reserved nor counted.
Both headers are now audited — which needed statement-based parsing, because
`CGLTexImageIOSurface2D` is wrapped across two lines — and:

- `CGLGetShareGroup` **binds**. `CGLShareGroupObj` is declared in
  `CGLDevice.h` itself and is an ordinary CGL opaque handle, so the pointer
  rule covers it exactly as it covers `CGLContextObj`. Reserving it would
  have been the per-function judgement D2 exists to prevent. *(This is a
  deliberate deviation: the review listed it among the foreign types.)*
- `CGLGetDeviceFromGLRenderer` and `CGLTexImageIOSurface2D` **reserve**,
  naming `cl_device_id` → OpenCL and `IOSurfaceRef` → IOSurface.framework.

CGL: header 52, bound 50, reserved 2. Totals move 580 → **581 methods, 2
reserved**.

### The rest

- **A gated call now re-checks for a current context every time.** The
  version sample short-circuits once taken, so a dropped context left the
  gate answering from memory. README's overclaim corrected to match.
- **`build-linux.sh` no longer sprays `30-opengl.ini` across every
  `/etc/php/*/conf.d` it can find.** It writes to `$PHP_BIN`'s own scan dir
  plus an `fpm` sibling under the same prefix. The old behaviour would put
  an `extension=` line for a ZTS build into a distro NTS php's conf.d and
  stop that php from starting. Decision recorded in `toolchain.md`.
- **Module teardown.** Zephir wraps its `MSHUTDOWN` in
  `#ifndef ZEPHIR_RELEASE` and the generated header defines
  `ZEPHIR_RELEASE`, so a built extension had none at all — and this one
  holds process-global buffers and `dlopen` handles. `phpgl_bridge_shutdown()`
  frees remaining buffers, destroys the registry and closes the handles;
  `scripts/patch-mshutdown.php` wires it into the generated `ext/opengl.c`
  with three verified edits, the same shape as the config.m4 patcher, so a
  Zephir template change fails the build instead of dropping the teardown.
  Neither ext-gtk nor ext-metal wires one, so this is a new house pattern
  rather than a copied one.
- **`.gen-stamp` now hashes `config.json`**, so a version bump alone marks a
  committed `ext/` stale, and **`build-linux.sh` asserts `php --ri` against
  `config.json`** exactly as `install-macos.sh` does. Both boxes now refuse
  to call a stale `.so` a success.
- **Composite-guard hole closed.** The guard only inspected annotated
  bodies, so a direct GL call in a file with no annotations —
  `src/phpgl-support.c` is that shape — was invisible. Every non-glue
  `src/*.c` is now scanned end to end, with
  `scripts/tests/fixtures/support-linktime` as the negative control.
- **`glGetError` drain loop capped at 64 iterations.** A lost context can
  report an error forever; the loop trusted the driver to stop.
- **Docs:** `support-zts` stays true (the Pi's PHP is ZTS) and
  `bridge.md` now says plainly that the buffer registry is **unlocked** and
  GL must be driven from one thread; the `procAddress()`-ungated vs
  `isAvailable()`-gated asymmetry is in the surface table with the reason;
  `install-macos.sh`'s Herd scan-dir heuristic is written down in
  `toolchain.md`, including how it fails; and three parameter names *are*
  escaped (`string_` in `glShaderSource`, `array_` in
  `glBindVertexArray`/`glIsVertexArray`) — binding-rules and AGENTS said no
  name was.

### Guards after the pass

`TESTS_OK` covers 7 checks now (was 5): the two new ones are
`reserved-guard.php` and `loader-guard.php`. Counts land at
`audited=16 skipped=1 failures=0`, `zep_calls=581`, CGL `52 / 50 / 2 OK`.

## 2026-09-13 — 0.8.0, greenfield

First wave. OpenGL core **1.0 .. 4.1** bound 1:1 (479 prototypes, 14
classes), plus **EGL 1.0 .. 1.5** (44) and **CGL** (49) for context creation,
plus 8 Bridge glue calls: **580 static methods across 17 classes, 0
reserved**. Green on both boxes from one source tree and one `.so` shape.

### What was built

- `scripts/gen-gl-src.php` — the generator. Parses the vendored
  `glcorearb.h` / `egl.h` and the live CGL headers, applies the D2 type table
  mechanically, and writes `src/gl-10.{h,c}` .. `src/gl-41.{h,c}`,
  `src/egl.{h,c}`, `src/cgl.{h,c}`, the three `*-types.h` headers, and
  `src/phpgl-registry.{h,c}`. A type the table does not cover stops it by
  name; it never skips anything.
- `src/phpgl-bridge.{h,c}` — the runtime loader, the version gate, and the
  bounds-checked byte buffers. The only hand-written C besides
  `src/phpgl-support.{h,c}`.
- `scripts/gen-zep.php`, `check-parity.php`, `audit-header.php`,
  `prepare-ext.sh`, `patch-config-m4.php`, `verify-reflection.php`,
  `pi-verify.sh`, `scripts/tests/*`.
- `install-macos.sh` (Darwin) and `build-linux.sh` (Debian/Ubuntu), the posi
  dual-installer shape.
- `examples/proof_headless.php` — the exit criterion, run on both boxes.

### Measured results

| | Mac (M1 Pro, Herd PHP 8.4) | Pi 5 (Debian 13 aarch64, PHP 8.4.20 ZTS) |
|---|---|---|
| context | CGL, profile `0x4100` | EGL 1.5 surfaceless |
| `GL_VERSION` | `4.1 Metal - 89.4` | `3.1 Mesa 26.2.0-1~bpo13+0~rpt3` |
| `GL_RENDERER` | `Apple M1 Pro` | `V3D 7.1.7.0` |
| GLSL | `4.10` | `1.40` |
| centre / corner pixel | `255,128,64,255` / `0,0,0,255` | `255,128,64,255` / `0,0,0,255` |
| `isAvailable('glProgramUniform1f')` | `true` | `false` + warning + `0` |
| reflection | `classes=17 failures=0` | `classes=17 failures=0` |

Both print `PROOF_HEADLESS_OK`. Same `.so` shape, same script, opposite
ceilings — which is the whole thesis of D1's runtime resolution.

### Deviations from the brief, and why

1. **479 prototypes, not 460.** The brief gave both a total ("460") and the
   per-block counts ("48,14,4,9,9,19,93,6,84,12,19,28,46,88"). Those counts
   are exactly what the vendored header has, and they sum to **479**. The
   per-block list is the authority (the brief itself makes the header the
   audit truth), so the total was arithmetic, not a scope statement.
   Deferred blocks 4.2 .. 4.6 are **178**, not the brief's 197, by the same
   arithmetic (12+43+9+110+4); total in the header is 657.
2. **CGL is audited against `OpenGL.h`, not just the three named headers.**
   The brief named `{CGLTypes,CGLContext,CGLCurrent}.h`. `CGLContext.h` and
   `CGLTypes.h` declare **zero** functions; the 49 CGL prototypes are 47 in
   `OpenGL.h` plus 2 in `CGLCurrent.h`. All four are audited; `OpenGL.h` was
   added because that is where the functions are.
3. **Apple's CGL headers are not vendored.** The brief says to vendor
   `glcorearb.h` and `egl.h` (done, with provenance). CGL is audited against
   the live SDK — ext-metal's precedent — and re-measurement is skipped with
   a stated verdict on Linux. The generated `src/cgl.*` is committed, so the
   Linux build is unaffected.
4. **`Bridge::alloc` does not use `emalloc`.** The size registry is a process
   global; an `emalloc`'d block would dangle in it after request shutdown.
   Explicit lifetime (`Bridge::free`) keeps the registry sound. Documented in
   [traps/pointer-bits-only.md](/traps/pointer-bits-only.md).
   **Superseded by the review pass below:** this first shipped as `pemalloc`,
   whose own failure path is `exit(1)`. It is now plain `malloc`.
5. **One Bridge call beyond the brief's seven:** `contextVersion()` (what the
   version gate believes — not the same information as `glGetString`, and the
   first thing to look at when a call warns unexpectedly). The brief's other
   seven are exactly as specified. `free` is spelled `free`, not `free_`;
   it is not a Zephir reserved word.
6. **The proof picks its `#version` directive from
   `GL_SHADING_LANGUAGE_VERSION`.** The brief asked for a GLSL 1.40 pair. A
   core profile above 3.2 does not accept `#version 140`, so the directive
   follows the GLSL version GL itself reports — `140` on the Pi, `150 core`
   on the Mac. That is a capability branch on data GL handed us, not a
   platform branch; `PHP_OS_FAMILY ===` still appears exactly once, and
   `structure-check.php` asserts that.
7. **One guard inside a generated body.** The brief says no per-function
   judgement, and there is none — but an array-of-strings parameter is the one
   place the *extension* allocates the array GL walks, so the generator emits
   a `count`-vs-length check derived from the header's parameter order. A
   header that breaks that shape stops the generator rather than earning a
   special case. See D2 in [binding-rules.md](/binding-rules.md).

### Things learned the hard way this session

- **`glGetIntegerv` with no current context kills the process on macOS.** Not
  a GL error, not a null return — a null dispatch table. Reproduced with a
  two-line C program before it was designed around. The Bridge now asks the
  context API first and treats "cannot tell" as "no context".
- **Mesa resolves GL 4.6 names on a 3.1 context**, so `dlsym` success is not
  availability. That is why `src/phpgl-registry.c` exists at all.
- **`*/` inside a PHP docblock ends the docblock**, even in the middle of a
  glob like `GL_ARB_*/GL_NV_*`. gtk's toolchain notes warn about the `@zep`
  half of this trap; this is the other half.
- **`ldconfig` is not on a plain user's PATH over ssh** — the first Pi run
  failed the runtime check with both libraries present.

### Open, deliberately

- Blocks **4.2 .. 4.6** (178 prototypes) are the next wave. 4.3 brings
  `GLDEBUGPROC`, which will be this repo's first `@reserved` lines.
- Windowed contexts (`GtkGLArea`, `NSOpenGLView`) belong to ext-gtk and
  ext-appkit waves, not here
  ([traps/no-window-in-ext.md](/traps/no-window-in-ext.md)).
- Constants: none are in the extension, by law. `examples/proof_headless.php`
  carries inline ints with `header:line` citations until **jovian/ogx** ships
  the enums.
