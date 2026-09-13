#!/usr/bin/env php
<?php
/*
 * The "nothing silently omitted" path, proved rather than asserted.
 *
 * Two kinds of prototype cannot be bound, and both must appear as a visible
 * @reserved line rather than stopping the generator or vanishing:
 *
 *   callback   a function-pointer parameter. There is none in 1.0 .. 4.1, so
 *              this test builds a SCRATCH copy of the generator with the
 *              version ceiling temporarily raised to 4.3, which is where
 *              glDebugMessageCallback(GLDEBUGPROC, const void *) lives, and
 *              checks the emitted line. The real tree is never touched and
 *              4.2+ is NOT bound by this repo.
 *   foreign    a type owned by a framework this binding does not include.
 *              Two exist in the real tree (CGLGetDeviceFromGLRenderer,
 *              CGLTexImageIOSurface2D) and are checked there, on Darwin.
 *
 * Also checks the other half of the rule: a type the table does not cover
 * and that is neither a callback nor foreign is still a HARD FAILURE, so a
 * new scalar spelling cannot quietly shrink the surface.
 *
 * Prints RESERVED_GUARD_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$scripts = dirname(__DIR__);
$root = dirname($scripts);
$expect = new Expect('reserved-guard');

/** Build a scratch package with the generator's version ceiling overridden. */
function scratchGenerator(string $root, string $scripts, string $maxMinor, string $extra = ''): string
{
    $staged = stageFixture($root . '/scripts/khronos');
    $pkg = dirname($staged) . '/phpgl-reserved-' . bin2hex(random_bytes(4));
    mkdir($pkg . '/scripts', 0755, true);
    rename($staged, $pkg . '/scripts/khronos');
    register_shutdown_function(static function () use ($pkg): void {
        removeTree($pkg);
    });

    $src = (string) file_get_contents($scripts . '/gen-gl-src.php');
    $src = str_replace(
        "const GL_MAX_MINOR = 1;",
        "const GL_MAX_MINOR = {$maxMinor};",
        $src
    );
    if ($extra !== '') {
        $src = str_replace('// ---------------------------------------------------------------- GL parsing', $extra, $src);
    }
    file_put_contents($pkg . '/scripts/gen-gl-src.php', $src);

    return $pkg;
}

// ---- 1. a callback parameter is reserved, not fatal ------------------------
// GL_MAX_MAJOR stays 4; raising the minor to 3 reaches glDebugMessageCallback.
$pkg = scratchGenerator($root, $scripts, '3');
[$code, $text] = runScript($pkg . '/scripts/gen-gl-src.php');

$expect->that(
    $code === 0 && str_contains($text, 'GEN_SRC_OK'),
    "the generator died on a header containing GLDEBUGPROC instead of reserving it:\n{$text}"
);
$expect->that(
    (bool) preg_match('/reserved=([1-9]\d*)/', $text),
    "the generator reported no reservations at all:\n{$text}"
);

$gl43 = $pkg . '/src/gl-43.h';
$expect->that(is_file($gl43), 'the scratch generator produced no src/gl-43.h');
if (is_file($gl43)) {
    $h = (string) file_get_contents($gl43);

    $line = null;
    foreach (explode("\n", $h) as $l) {
        if (str_contains($l, '@reserved') && str_contains($l, 'glDebugMessageCallback')) {
            $line = trim($l);
            break;
        }
    }
    $expect->that($line !== null, 'glDebugMessageCallback has no @reserved line in the scratch src/gl-43.h');
    if ($line !== null) {
        echo "reserved-guard: emitted line is\n  {$line}\n";
        $expect->that(str_contains($line, 'GL\\GL43'), 'the @reserved line names the wrong class');
        $expect->that(str_contains($line, 'GLDEBUGPROC'), 'the @reserved line does not name GLDEBUGPROC');
        $expect->that(str_contains($line, 'callback'), 'the @reserved line does not give the callback reason');
        $expect->that(
            (bool) preg_match('#^/\*@reserved\s+[A-Za-z0-9_\\\\]+\s+.*\*/$#', $line),
            'the @reserved line does not match the grammar gen-zep.php parses'
        );
    }

    $expect->that(
        !preg_match('/@zep\s+\S+\s+glDebugMessageCallback\s*\(/', $h),
        'glDebugMessageCallback was bound as well as reserved'
    );

    // bound + reserved must still equal the block's header count.
    preg_match('/@audit block \S+ GL_VERSION_4_3 (\d+)/', $h, $bm);
    $header = isset($bm[1]) ? (int) $bm[1] : -1;
    $bound = preg_match_all('/@zep\s+GL\\\\GL43\s+/', $h);
    $reserved = preg_match_all('/@reserved\s+GL\\\\GL43\s+/', $h);
    $expect->that(
        $header > 0 && $bound + $reserved === $header,
        "gl-43.h accounts for {$bound}+{$reserved} of {$header} prototypes — the audit sum must be exact"
    );
    echo "reserved-guard: scratch GL_VERSION_4_3 header={$header} bound={$bound} reserved={$reserved}\n";
}

// ---- 2. an unclassified type is still a hard failure -----------------------
// Teach the scratch generator that GLfloat is unknown: it is neither a
// callback nor foreign, so the generator must stop and name it rather than
// reserve it away.
$sabotage = <<<'PHP'
// TEST SABOTAGE: make a known scalar unmappable.
function phpglTestSabotage(): void
{
}
// ---------------------------------------------------------------- GL parsing
PHP;
$pkg2 = scratchGenerator($root, $scripts, '1', $sabotage);
$src = (string) file_get_contents($pkg2 . '/scripts/gen-gl-src.php');
$src = str_replace("static \$doubles = ['GLfloat', ", "static \$doubles = [", $src);
file_put_contents($pkg2 . '/scripts/gen-gl-src.php', $src);

[$code, $text] = runScript($pkg2 . '/scripts/gen-gl-src.php');
$expect->that($code !== 0, 'the generator reserved an unclassified type instead of failing');
$expect->that(
    str_contains($text, 'unsupported parameter type') && str_contains($text, 'GLfloat'),
    "the generator failed without naming the unclassified type:\n{$text}"
);

// ---- 3. the real tree's foreign-type reservations ---------------------------
if (is_file($root . '/src/cgl.h')) {
    $cgl = (string) file_get_contents($root . '/src/cgl.h');
    foreach ([
        'CGLGetDeviceFromGLRenderer' => 'OpenCL',
        'CGLTexImageIOSurface2D' => 'IOSurface.framework',
    ] as $fn => $owner) {
        $found = false;
        foreach (explode("\n", $cgl) as $l) {
            if (str_contains($l, '@reserved') && str_contains($l, $fn)) {
                $found = str_contains($l, $owner);
                break;
            }
        }
        $expect->that($found, "src/cgl.h has no @reserved line for {$fn} naming {$owner}");
    }
    // CGLGetShareGroup is an ordinary CGL opaque handle, declared in the CGL
    // headers themselves, so the pointer rule covers it and it must be bound.
    $expect->that(
        str_contains($cgl, '@zep CGL\\CGL CGLGetShareGroup(int ctx) -> int'),
        'CGLGetShareGroup is not bound; CGLShareGroupObj is a CGL type, not a foreign one'
    );
}

$expect->finish('RESERVED_GUARD_OK');
