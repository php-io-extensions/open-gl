#!/usr/bin/env php
<?php
/**
 * audit-header.php — nothing silently omitted.
 *
 * ext-gtk audits against vendored GObject-Introspection XML; there is no
 * such thing for OpenGL, so the audit truth here is the prototype count per
 * version block in the vendored Khronos headers (and, for CGL, in the live
 * OpenGL.framework headers on Darwin).
 *
 * Per bound class the rule is the house rule:
 *
 *     bound + reserved  ==  the header's prototype count for that class
 *
 * where the class's header count is the sum of its `@audit block` markers,
 * and every one of those markers is itself re-measured against the header it
 * names. A marker that no longer matches the header is a hard failure — that
 * is what stops a re-vendored header from silently changing the surface.
 *
 * Markers, all one line, all in src/*.h:
 *
 *   /*@audit block GL\GL10 GL_VERSION_1_0 48 * /
 *       class GL\GL10 covers GL_VERSION_1_0, which has 48 prototypes.
 *   /*@audit partial GL\GL42 <reason> * /
 *       sanctions bound+reserved falling SHORT of the header count (never an
 *       excess) while a class is deliberately incomplete. Same semantics as
 *       ext-metal's marker: a partial class whose bound count already equals
 *       its header count prints OK, not PARTIAL.
 *
 * Blocks GL_VERSION_4_2 .. GL_VERSION_4_6 are a deferred wave: they have no
 * class, no markers, and are reported as DEFERRED, not as a shortfall.
 *
 * Usage: php scripts/audit-header.php [root]
 */

declare(strict_types=1);

const GL_MAX_MAJOR = 4;
const GL_MAX_MINOR = 1;
const CGL_HEADER_FILES = [
    'OpenGL.h', 'CGLCurrent.h', 'CGLTypes.h', 'CGLContext.h',
    'CGLDevice.h', 'CGLIOSurface.h',
];

$failures = [];

function problem(string $msg): void
{
    global $failures;
    $failures[] = $msg;
}

/** @return array<string,int> block name -> prototype count */
function measureGl(string $path): array
{
    $out = [];
    $cur = null;
    foreach (file($path, FILE_IGNORE_NEW_LINES) ?: [] as $line) {
        if (preg_match('/^#ifndef (GL_VERSION_\d+_\d+)$/', $line, $m)) {
            $cur = $m[1];
            $out[$cur] = 0;
            continue;
        }
        if (preg_match('~^#endif /\* GL_VERSION_\d+_\d+ \*/~', $line)) {
            $cur = null;
            continue;
        }
        if ($cur !== null && str_starts_with($line, 'GLAPI ')) {
            $out[$cur]++;
        }
    }

    return $out;
}

/** @return array<string,int> */
function measureEgl(string $path): array
{
    $out = [];
    $cur = null;
    foreach (file($path, FILE_IGNORE_NEW_LINES) ?: [] as $line) {
        if (preg_match('/^#ifndef (EGL_VERSION_\d+_\d+)$/', $line, $m)) {
            $cur = $m[1];
            $out[$cur] = 0;
            continue;
        }
        if (preg_match('~^#endif /\* EGL_VERSION_\d+_\d+ \*/~', $line)) {
            $cur = null;
            continue;
        }
        if ($cur !== null && str_starts_with($line, 'EGLAPI ')) {
            $out[$cur]++;
        }
    }

    return $out;
}

/** @return array<string,int>|null null when OpenGL.framework is absent */
function measureCgl(): ?array
{
    $dir = null;
    $sdk = trim((string) @shell_exec('xcrun --show-sdk-path 2>/dev/null'));
    foreach (array_filter([
        $sdk !== '' ? $sdk . '/System/Library/Frameworks/OpenGL.framework/Headers' : null,
        '/System/Library/Frameworks/OpenGL.framework/Headers',
    ]) as $candidate) {
        if (is_file($candidate . '/OpenGL.h')) {
            $dir = $candidate;
            break;
        }
    }
    if ($dir === null) {
        return null;
    }

    $out = [];
    foreach (CGL_HEADER_FILES as $file) {
        $out[$file] = 0;
        $src = (string) file_get_contents($dir . '/' . $file);

        // Comments and preprocessor lines out of the way, then count
        // declaration statements rather than lines: CGLTexImageIOSurface2D
        // is wrapped across two. Deliberately a second, independent
        // measurement of the same thing gen-gl-src.php parses.
        $src = preg_replace('~/\*.*?\*/~s', ' ', $src);
        $src = preg_replace('~//[^\n]*~', ' ', $src);
        $src = preg_replace('/^[ \t]*#(?:[^\n\\\\]|\\\\.)*$/m', ' ', $src);

        foreach (explode(';', $src) as $statement) {
            $statement = preg_replace('/\bOPENGL_\w+\s*\([^)]*\)/', '', $statement);
            $statement = preg_replace('/\bOPENGL_\w+\b/', '', $statement);
            $statement = preg_replace('/\bextern\s*"C"/', '', $statement);
            $statement = preg_replace('/\bextern\b/', '', $statement);
            $statement = trim(preg_replace('/\s+/', ' ', str_replace(['{', '}'], ' ', $statement)));

            if ($statement === '' || str_contains($statement, 'typedef')) {
                continue;
            }
            if (preg_match('/^\S.*?\bCGL\w+\s*\(.*\)$/', $statement)) {
                $out[$file]++;
            }
        }
    }

    return $out;
}

function versionOf(string $block): array
{
    preg_match('/_(\d+)_(\d+)$/', $block, $m);

    return [(int) $m[1], (int) $m[2]];
}

// ------------------------------------------------------------------- parse

$root = isset($argv[1]) ? rtrim($argv[1], '/') : dirname(__DIR__);

$bound = [];
$reserved = [];
$markers = [];   // classPath => [block => count]
$partials = [];  // classPath => reason

foreach (glob("{$root}/src/*.h") ?: [] as $path) {
    $rel = 'src/' . basename($path);
    foreach (file($path, FILE_IGNORE_NEW_LINES) ?: [] as $no => $line) {
        if (preg_match('#/\*\s*@audit\s+block\s+([A-Za-z0-9_\\\\]+)\s+(\S+)\s+(\d+)\s*\*/#', $line, $m)) {
            if (isset($markers[$m[1]][$m[2]])) {
                problem("{$rel}:" . ($no + 1) . " duplicate @audit block {$m[1]} {$m[2]}");
            }
            $markers[$m[1]][$m[2]] = (int) $m[3];
            continue;
        }
        if (preg_match('#/\*\s*@audit\s+partial\s+([A-Za-z0-9_\\\\]+)\s+(.*?)\s*\*/#', $line, $m)) {
            $partials[$m[1]] = $m[2];
            continue;
        }
        if (preg_match('#/\*\s*@reserved\s+([A-Za-z0-9_\\\\]+)\s+#', $line, $m)) {
            $reserved[$m[1]] = ($reserved[$m[1]] ?? 0) + 1;
            continue;
        }
        if (preg_match('#/\*\s*@zep(?:-construct)?\s+([A-Za-z0-9_\\\\]+)\s+#', $line, $m)) {
            $bound[$m[1]] = ($bound[$m[1]] ?? 0) + 1;
        }
    }
}

$glMeasured = measureGl("{$root}/scripts/khronos/glcorearb.h");
$eglMeasured = measureEgl("{$root}/scripts/khronos/egl.h");
$cglMeasured = measureCgl();

// ------------------------------------------ re-measure every @audit marker

foreach ($markers as $classPath => $blocks) {
    foreach ($blocks as $block => $claimed) {
        $actual = null;
        if (str_starts_with($block, 'GL_VERSION_')) {
            $actual = $glMeasured[$block] ?? null;
        } elseif (str_starts_with($block, 'EGL_VERSION_')) {
            $actual = $eglMeasured[$block] ?? null;
        } elseif ($cglMeasured !== null) {
            $actual = $cglMeasured[$block] ?? null;
        } else {
            continue; // CGL headers absent: re-measurement skipped, see below
        }
        if ($actual === null) {
            problem("{$classPath}: @audit block names '{$block}', which the header does not have");
            continue;
        }
        if ($actual !== $claimed) {
            problem("{$classPath}: @audit block {$block} claims {$claimed}, the header has {$actual}"
                . ' — re-run scripts/gen-gl-src.php');
        }
    }
}

// ------------------------------------------------- every block has a class

$claimedBlocks = [];
foreach ($markers as $blocks) {
    foreach (array_keys($blocks) as $b) {
        $claimedBlocks[$b] = true;
    }
}
$deferred = [];
foreach ($glMeasured as $block => $n) {
    if (isset($claimedBlocks[$block])) {
        continue;
    }
    [$maj, $min] = versionOf($block);
    if ($maj > GL_MAX_MAJOR || ($maj === GL_MAX_MAJOR && $min > GL_MAX_MINOR)) {
        $deferred[$block] = $n;
        continue;
    }
    problem("{$block} has {$n} prototype(s) and no class claims it");
}
foreach ($eglMeasured as $block => $n) {
    if (!isset($claimedBlocks[$block])) {
        problem("{$block} has {$n} prototype(s) and no class claims it");
    }
}

// -------------------------------------------------------------- the verdict

$classes = array_unique(array_merge(
    array_keys($markers),
    array_keys($bound),
    array_keys($reserved)
));
sort($classes);

$audited = 0;
$skipped = 0;

printf("%-18s %8s %7s %9s  %s\n", 'class', 'header', 'bound', 'reserved', 'verdict');
foreach ($classes as $classPath) {
    $b = $bound[$classPath] ?? 0;
    $r = $reserved[$classPath] ?? 0;

    if (!isset($markers[$classPath])) {
        // Bridge is glue: it has no header counterpart to audit against.
        printf("%-18s %8s %7d %9d  %s\n", $classPath, '—', $b, $r, 'SKIP (glue)');
        $skipped++;
        continue;
    }

    $header = array_sum($markers[$classPath]);
    $isCgl = str_starts_with($classPath, 'CGL\\');
    $remeasured = !$isCgl || $cglMeasured !== null;

    $verdict = 'OK';
    if ($b + $r > $header) {
        $verdict = 'EXCESS';
        problem("{$classPath}: bound+reserved=" . ($b + $r) . " exceeds the header's {$header}");
    } elseif ($b + $r < $header) {
        if (isset($partials[$classPath])) {
            $verdict = 'PARTIAL';
        } else {
            $verdict = 'SHORT';
            problem("{$classPath}: bound+reserved=" . ($b + $r) . " is short of the header's {$header}"
                . ' — bind it, reserve it, or mark the class @audit partial');
        }
    }
    if (!$remeasured) {
        $verdict .= ' (counts not re-measured: no OpenGL.framework on this box)';
    }

    printf("%-18s %8d %7d %9d  %s\n", $classPath, $header, $b, $r, $verdict);
    $audited++;
}

if ($deferred !== []) {
    echo "\ndeferred (a later wave; see .okf/traps/version-ceilings.md):\n";
    $sum = 0;
    foreach ($deferred as $block => $n) {
        printf("  %-22s %4d\n", $block, $n);
        $sum += $n;
    }
    printf("  %-22s %4d\n", 'total deferred', $sum);
}

printf(
    "\naudited=%d skipped=%d failures=%d\n",
    $audited,
    $skipped,
    count($failures)
);

if ($failures !== []) {
    foreach ($failures as $f) {
        fwrite(STDERR, "audit: {$f}\n");
    }
    fwrite(STDERR, 'AUDIT_FAILED (' . count($failures) . ")\n");
    exit(1);
}

echo "AUDIT_OK\n";
