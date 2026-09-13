# Agent guidelines — php-io-extensions/opengl

## Knowledge Bundle (OKF)

This package ships an Open Knowledge Format bundle at [`.okf/`](.okf/). Before changing code or advising on this package: read [`.okf/index.md`](.okf/index.md) first, open only the concepts the task needs, prefer `status: stable` over `draft`. When you learn something durable, update the affected concept(s) and append `.okf/log.md`; new or changed concepts stay `status: draft` until a human verifies them.

## Binding rules (the spec: [`.okf/binding-rules.md`](.okf/binding-rules.md))

1. **One PHP static method = one native call.** There are no sanctioned composites in this extension — OpenGL has no objects to construct and register, so there is nothing to except.
2. **One static class per header version block**, method name = the function name verbatim: `glClear` → `OpenGL\GL\GL10\GL10::glClear`, `glGenBuffers` → `GL15::glGenBuffers`, `eglMakeCurrent` → `OpenGL\EGL\EGL::eglMakeCurrent`, `CGLCreateContext` → `OpenGL\CGL\CGL::CGLCreateContext`. A function belongs to the block it *first appeared in*, not to the version you are running.
3. **`src/gl-*.{h,c}`, `src/egl.{h,c}`, `src/cgl.{h,c}`, `src/*-types.h` and `src/phpgl-registry.*` are GENERATED** from the vendored Khronos headers by `php scripts/gen-gl-src.php`. Never hand-edit them; `scripts/tests/gen-src-guard.php` will catch you. The only hand-written C is `src/phpgl-support.{h,c}` and `src/phpgl-bridge.{h,c}`.
4. **Never hand-write `.zep` files or optimizers** — they are generated from the `/*@zep …*/` and `/*@reserved …*/` lines in `src/*.h` by `php scripts/gen-zep.php`.
5. **Nothing is silently omitted.** Every header prototype is bound (`@zep`) or kept as a commented `@reserved` signature; `bound + reserved` must equal the header's count per class (`@audit block` markers, re-measured against the header by `audit-header.php`). `@audit partial <class> <reason>` sanctions a shortfall, never an excess. Only two things may be reserved — a callback parameter, and a type owned by a framework this binding does not include — and the emitted line says which; **any other unmapped type stops the generator by name**, so a new scalar spelling cannot quietly shrink the surface. `scripts/tests/reserved-guard.php` proves both halves.
6. **The pointer rule (D2) — this is the one that keeps the layer opinion-free.** Scalars → `int`/`double`/`bool`; `const GLchar *` in → `string`; `const GLchar *const *` in → `array` of strings; `const GLubyte *`/`const char *` returns → `var`; **every other pointer, in or out, crosses as raw pointer bits in an `int`, 0 = NULL**. No `count` parameter is ever invented or dropped, and no per-function judgement is made anywhere. PHP builds and reads the bytes with `Bridge::alloc/write/read` and `pack()`/`unpack()`. A type the table does not cover stops the generator by name.
7. **Every entry point is resolved at RUNTIME**, through `phpgl_entry()` and the `PFNGL…PROC` typedefs — never at link time. That is what lets one `.so` serve a GL 3.1 Pi and a GL 4.1 Mac. A binding that calls `glFoo`/`eglFoo`/`CGLFoo` by name is rejected by the parity guard. See [`.okf/traps/runtime-resolution-not-linking.md`](.okf/traps/runtime-resolution-not-linking.md).
8. **A call the current context cannot make raises `E_WARNING("<name> is not available in the current context")` and returns 0/void.** No exceptions, no error side channel. Symbol resolution is *not* availability — Mesa resolves GL 4.6 names on a 3.1 context — so the gate compares the context's version against the block the function came from. See [`.okf/traps/version-ceilings.md`](.okf/traps/version-ceilings.md).
9. **All glue lives in `OpenGL\Bridge\Bridge`** (`src/phpgl-bridge.{h,c}`); no other bridge class may exist, and no other file may contain platform knowledge. See [`.okf/bridge.md`](.okf/bridge.md).
10. **No constants in the ext** — enum values become PHP enums in **jovian/ogx**. Examples carry inline ints with `header:line` citations until then.
11. **No window, ever.** This extension creates contexts (EGL/CGL) and draws. `GtkGLArea` and `NSOpenGLView` are other repos' waves. See [`.okf/traps/no-window-in-ext.md`](.okf/traps/no-window-in-ext.md).
12. Zephir reserved words in method/parameter names get a trailing underscore; all-caps names are emitted mixed-case. No **method** name hits either rule — every GL/EGL/CGL function name passes through verbatim — but three **parameter** names do: `glShaderSource`'s `string` becomes `string_`, and `glBindVertexArray`/`glIsVertexArray`'s `array` becomes `array_`. Positional calls are unaffected; named arguments must use the escaped spelling.

## Pipeline

```bash
export HERD_PHP_84_INI_SCAN_DIR="$(zsh -ic 'echo $HERD_PHP_84_INI_SCAN_DIR')"   # Mac, non-interactive shells

php scripts/gen-gl-src.php        # GEN_SRC_OK
php scripts/gen-zep.php           # GEN_OK
php scripts/check-parity.php      # PARITY_OK, then chains audit-header.php → AUDIT_OK
php scripts/tests/run-all.php     # TESTS_OK   ← negative controls; run before calling a wave done
bash install-macos.sh             # php --ri opengl must report config.json's version
php scripts/verify-reflection.php # REFLECTION_OK
php examples/proof_headless.php   # PROOF_HEADLESS_OK
bash scripts/pi-verify.sh         # PI_VERIFY_OK — push, build, reflect and prove on the Pi
```

`scripts/tests/run-all.php` is not optional: every guard in this repo is proved able to *fail* against a fixture that breaks exactly what it catches. A guard nobody has watched fail is a guard nobody should trust.

**Source guards pass on sources that do not compile.** A wave is not done until `install-macos.sh` *and* `scripts/pi-verify.sh` are green. Fix on the Mac, re-push, rebuild — never edit on the Pi.
