---
type: Runbook
title: Generate and guard on the Mac — build and prove on both boxes
description: >-
  The pipeline that turns vendored Khronos headers into a loadable
  extension, the guards that keep it faithful, and the Mac/Pi split.
tags: [toolchain, zephir, build, khronos, pi, macos]
status: stable
generated:
  by: claude-fable-5.1
  at: 2026-09-13T00:00:00Z
---

# Toolchain

Two generation steps, not one. The vendored headers in `scripts/khronos/`
are the truth about what exists; `src/*.h`'s annotations are the truth about
what PHP sees; everything downstream is generated and prunes itself.

```
scripts/khronos/*.h ──gen-gl-src.php──▶ src/*.{h,c}
                                          │ (@zep annotations)
                                          ▼
                                  gen-zep.php ──▶ opengl/**/*.zep
                                               └─▶ optimizers/*Optimizer.php
                                                      │
                                             zephir generate ──▶ ext/
```

Never hand-edit `src/gl-*`, `src/egl.*`, `src/cgl.*`, `src/*-types.h`,
`src/phpgl-registry.*`, `opengl/`, `optimizers/` or `ext/`. The only
hand-written C is `src/phpgl-support.{h,c}` and `src/phpgl-bridge.{h,c}`.

## Mac / Pi split

Development, generation and every source-level guard run on the Mac. Both
boxes compile and run the extension — that is the point of this repo, and
both are proved by the same `examples/proof_headless.php`.

- **Mac:** Apple M1 Pro, Herd PHP 8.4 NTS. `install-macos.sh`. OpenGL.framework
  caps at **4.1** (`4.1 Metal - 89.4`, GLSL 4.10).
- **Pi 5:** Debian 13 trixie aarch64, PHP 8.4.20 ZTS at
  `/usr/local/php84-zts`, `phpize` at `/usr/local/bin/phpize`, Mesa 26.2.
  `build-linux.sh`. V3D 7.1.7.0 caps at **GL 3.1 core, GLSL 1.40**.

Reach the Pi with Angel's `fnk` zsh alias (sshpass-wrapped ssh; credentials
live in `~/.zshrc` and are never inlined). Expand it as
`zsh -ic 'fnk "…"'` and stream files as a tar over its stdin —
`scripts/pi-verify.sh` does all of that. **Fix on the Mac, re-push, rebuild.
Never edit on the Pi.**

Before anything on the Mac:

```bash
export HERD_PHP_84_INI_SCAN_DIR="$(zsh -ic 'echo $HERD_PHP_84_INI_SCAN_DIR')"
```

## Pipeline

```bash
# Mac — generate and guard
php scripts/gen-gl-src.php          # headers -> src/           (GEN_SRC_OK)
php scripts/gen-zep.php             # annotations -> zep + optimizers (GEN_OK)
php scripts/check-parity.php        # PARITY_OK, then chains audit-header (AUDIT_OK)
php scripts/tests/run-all.php       # negative controls          (TESTS_OK)

# Mac — build, install, prove
bash install-macos.sh               # prepare-ext -> phpize -> make -> codesign -> ini
php scripts/verify-reflection.php   # REFLECTION_OK
php examples/proof_headless.php     # PROOF_HEADLESS_OK (CGL, 4.1)

# Pi — push, build, prove (one command, from the Mac)
bash scripts/pi-verify.sh           # PI_VERIFY_OK
```

`scripts/pi-verify.sh` runs `prepare-ext.sh` locally first (so the tree that
crosses is regenerated, stripped and stamped), tars it over `fnk`, runs
`build-linux.sh` on the Pi, then `verify-reflection.php` and
`proof_headless.php` there.

## Guards

- **`gen-gl-src.php --check`** — regenerate into memory and diff against the
  tree. Any difference, including a hand-edit to a generated file, prints
  `GEN_SRC_DRIFT` and names the file.
- **`check-parity.php`** — zep bare calls ↔ optimizers ↔ C prototypes (names
  and arity), `config.json` extra-sources coverage, and the composite guard.
  The composite guard is shaped for a runtime-resolved binding: every body
  outside the glue file must make **exactly one** `phpgl_entry()` resolution
  and **exactly one** `fn()` call through it, and must contain **no** direct
  `glFoo`/`eglFoo`/`CGLFoo` call by name — a name called directly would be a
  link-time call and would break the one-`.so`-for-both-boxes contract. Then
  it chains the header audit.
- **`audit-header.php`** — "nothing silently omitted", against the vendored
  headers instead of a gir. Per class, `bound + reserved` must equal the sum
  of its `@audit block` markers, and **every marker is re-measured against
  the header it names** — that is what catches a re-vendored header that
  quietly changed the surface. `@audit partial <class> <reason>` sanctions a
  shortfall, never an excess. Blocks 4.2 .. 4.6 are reported as *deferred*,
  not as a shortfall. CGL's markers are re-measured only on Darwin (the
  headers are Apple's and are not vendored); on Linux the verdict says so.
- **`scripts/tests/run-all.php`** — the negative controls. Each guard is run
  against a fixture that breaks exactly what that guard exists to catch:
  an annotation that drifted from its prototype, a body with two calls, a
  body with a link-time call, a `src/*.c` missing from extra-sources, an
  `@audit block` marker the header contradicts, an unsanctioned shortfall,
  and a hand-edited generated file. Plus positive controls, so a guard that
  fails on everything cannot pass either.
- **`verify-reflection.php`** — the only guard that inspects the **installed**
  `.so`: per class, the reflected method count equals the annotation count.
  Runs on whichever box just installed.

## Gotchas

- **Source guards pass on sources that do not compile.** A wave is not done
  until `install-macos.sh` *and* `pi-verify.sh` are green. gtk learned this;
  do not relearn it.
- **`zephir generate` runs under `php -n`** plus `zephir_parser`, so a
  previously installed `opengl.so` cannot segfault the compiler. Herd's
  `PHP_BINARY` contains spaces — anything shelling out to it must
  `escapeshellarg`.
- **Zephir's single `extra-libs` string cannot be per-platform.**
  `scripts/patch-config-m4.php` appends a `case $host_os` block to the
  generated `ext/config.m4` (`-framework OpenGL` on Darwin, `-lEGL -lGL -ldl`
  elsewhere) and verifies the patch landed. That line is a **declaration of
  which platform runtime this extension is for**, not a mechanism: no GL,
  EGL or CGL symbol is referenced at link time, and linking a library does
  not help `dlopen` find it later. On Darwin it still produces a real load
  command for OpenGL.framework; on Linux `--as-needed` drops it entirely.
  Either way the runtime is a hard requirement — see
  [traps/runtime-resolution-not-linking.md](/traps/runtime-resolution-not-linking.md).
- **A PHP docblock containing `*/` inside a path or a glob terminates the
  comment.** Writing `GL_ARB_*/GL_NV_*` in `gen-gl-src.php`'s header cost a
  parse error. gtk's toolchain note warns about the `@zep` half of the same
  trap; this is the other half.
- **`gen-zep.php` treats any line containing `@zep` as an annotation.** File
  headers must not mention the token.
- **Copying Mac → Pi with plain `tar` ships AppleDouble `._*` files**, which
  change the gen-stamp and crash Zephir's parser. Always
  `COPYFILE_DISABLE=1 tar czf … --exclude '._*'` (pi-verify.sh does).
- **`ldconfig` is in `/sbin`**, which is not on a plain user's PATH over ssh.
  `build-linux.sh` resolves it explicitly and falls back to looking in
  `/usr/lib/*/`.
- **A copied Mach-O is SIGKILLed on Apple Silicon** unless it is `xattr -cr`'d
  and ad-hoc re-signed after `cp`. `install-macos.sh` does both.
- **`install-macos.sh` finds Herd's extension directory by heuristic, and the
  heuristic is worth knowing.** It resolves `php-config` next to `PHP_BINARY`
  first and falls back to the one on `PATH` — on this box that is Homebrew's,
  whose `--extension-dir` points at Homebrew's `pecl` tree, which is *not*
  where Herd's PHP loads from. So it then overrides that: if PHP's own
  "Scan for additional .ini files in" directory exists **and already contains
  `*.so`**, that directory becomes the extension directory. That is what puts
  `opengl.so` next to `30-opengl.ini` in
  `~/Library/Application Support/Herd/config/php/84/`, matching every other
  extension on the box. The consequence to remember: on a Herd install with an
  empty scan dir the heuristic does not fire, and the `.so` lands in
  Homebrew's tree where Herd's PHP will not find it — `php --ri opengl` then
  fails the version assertion rather than silently "succeeding".
- **`build-linux.sh` writes the ini to one interpreter's conf.d, not every
  one it can find.** The inherited gtk script wrote `30-opengl.ini` into
  `/etc/php/*/cli`, `/fpm` and `/apache2` as well as PHP's own scan dir. That
  is wrong as soon as a box has two PHPs: the `.so` is built against exactly
  one of them, and dropping an `extension=` line into a distro NTS php's
  conf.d next to the ZTS build it was compiled for makes that php fail to
  start. It now writes only to `$PHP_BIN`'s own CLI scan dir, plus an `fpm`
  conf.d under the same prefix (`…/cli/conf.d` → `…/fpm/conf.d`), which is the
  same installation. The extension is enabled for the interpreter it was built
  for and nothing else.
- **Both boxes had a stale `opengl` 0.7.0 installed.** Both installers write
  `30-opengl.ini`, so 0.8.0 supersedes it, and **both** now assert that
  `php --ri opengl` reports the version in `config.json` and fail if the
  installed `.so` is stale. `.gen-stamp` hashes `config.json` too, so a
  version bump alone marks a committed `ext/` stale instead of building a
  binary that disagrees with the manifest.
