#!/usr/bin/env php
<?php
/**
 * patch-config-m4.php — teach the generated ext/config.m4 that this
 * extension builds on two platforms.
 *
 * Zephir's config.json has one `extra-libs` string and emits one
 * PHP_EVAL_LIBLINE from it, which cannot say "-framework OpenGL here and
 * -lEGL -lGL -ldl there". posi solves the same problem one level up, with a
 * separate installer per platform; this extension is one .so built from one
 * source tree on both boxes, so the split has to live in config.m4 itself.
 *
 * The patch is a single `case $host_os` block appended to the extension's
 * SHARED_LIBADD, inserted immediately before the AC_DEFINE line. It is
 * idempotent (a marker comment is checked first) and verified: if the block
 * is not present after writing, the script fails rather than leaving a
 * config.m4 that links nothing.
 *
 * What this line is: a DECLARATION of which platform runtime the extension
 * is for. What it is not: a mechanism. No libGL, libEGL or OpenGL.framework
 * symbol is referenced at link time — every entry point goes through
 * dlopen/dlsym in phpgl-bridge.c — and linking a library does not help
 * dlopen find it later, since the dynamic loader searches by soname from the
 * runtime search path.
 *
 * Measured on the built artefacts: on Darwin -framework OpenGL still
 * produces a real load command (frameworks link whether or not a symbol is
 * used), so the framework is a load-time dependency there; on Linux
 * --as-needed drops -lEGL/-lGL because nothing references them, and -ldl is
 * empty on glibc >= 2.34. The runtime is required either way — see
 * .okf/traps/runtime-resolution-not-linking.md.
 *
 * Usage: php scripts/patch-config-m4.php <path-to-ext/config.m4>
 */

declare(strict_types=1);

const MARKER = 'PHPGL platform link flags';

$path = $argv[1] ?? '';
if ($path === '' || !is_file($path)) {
    fwrite(STDERR, "patch-config-m4: usage: patch-config-m4.php <ext/config.m4>\n");
    exit(1);
}

$src = (string) file_get_contents($path);

if (str_contains($src, MARKER)) {
    echo "patch-config-m4: already patched\n";
    exit(0);
}

if (!preg_match('/^\s*AC_DEFINE\(HAVE_OPENGL,/m', $src, $m, PREG_OFFSET_CAPTURE)) {
    fwrite(STDERR, "patch-config-m4: AC_DEFINE(HAVE_OPENGL, ...) not found in {$path}\n");
    exit(1);
}
$at = $m[0][1];

$block = <<<'M4'

	dnl ---- PHPGL platform link flags ----
	dnl Every GL/EGL/CGL entry point is resolved at runtime by
	dnl src/phpgl-bridge.c, so nothing here is referenced at link time.
	dnl This declares which platform runtime the extension needs; on Darwin
	dnl it also becomes a real load command, on Linux --as-needed drops it.
	case $host_os in
		darwin*)
			OPENGL_SHARED_LIBADD="$OPENGL_SHARED_LIBADD -framework OpenGL"
			;;
		*)
			OPENGL_SHARED_LIBADD="$OPENGL_SHARED_LIBADD -lEGL -lGL -ldl"
			;;
	esac

M4;

$out = substr($src, 0, $at) . $block . substr($src, $at);

if (file_put_contents($path, $out) === false) {
    fwrite(STDERR, "patch-config-m4: cannot write {$path}\n");
    exit(1);
}

$check = (string) file_get_contents($path);
if (!str_contains($check, MARKER)
    || !str_contains($check, '-framework OpenGL')
    || !str_contains($check, '-lEGL -lGL -ldl')) {
    fwrite(STDERR, "patch-config-m4: the platform block is not present after writing\n");
    exit(1);
}

echo "patch-config-m4: PATCH_OK\n";
