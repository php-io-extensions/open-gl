#!/usr/bin/env php
<?php
/*
 * Idempotence controls for the two generators.
 *
 * src/ is generated from the vendored headers and the .zep tree is generated
 * from src/'s annotations, so "re-run it and nothing changes" is the whole
 * contract. Two ways it can break: a generator that is not deterministic,
 * and a tree someone hand-edited.
 *
 *   1. gen-gl-src.php --check must print GEN_SRC_CLEAN against the committed
 *      tree.
 *   2. A hand-edit to a generated file must make --check fail and name the
 *      file (run in a staged copy; the committed tree is never touched).
 *   3. gen-zep.php re-run must write nothing (written=0) and prune nothing.
 *
 * Prints GEN_SRC_GUARD_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$scripts = dirname(__DIR__);
$root = dirname($scripts);
$expect = new Expect('gen-src-guard');

// ---- 1. the committed src/ is exactly what the headers produce
[$code, $text] = runScript($scripts . '/gen-gl-src.php', ['--check']);
$expect->that(
    $code === 0 && str_contains($text, 'GEN_SRC_CLEAN'),
    "src/ is not what the vendored headers produce:\n{$text}"
);

// ---- 2. a hand-edit must be caught
$staged = stageFixture($root . '/scripts/khronos');
// Stage a minimal package: the generator needs scripts/khronos + src.
$pkg = dirname($staged) . '/phpgl-gen-' . bin2hex(random_bytes(4));
mkdir($pkg . '/scripts', 0755, true);
rename($staged, $pkg . '/scripts/khronos');
register_shutdown_function(static function () use ($pkg): void {
    removeTree($pkg);
});
copy($scripts . '/gen-gl-src.php', $pkg . '/scripts/gen-gl-src.php');

[$code, $text] = runScript($pkg . '/scripts/gen-gl-src.php');
$expect->that($code === 0 && str_contains($text, 'GEN_SRC_OK'), "the generator failed on a staged copy:\n{$text}");

$victim = $pkg . '/src/gl-10.c';
$expect->that(is_file($victim), 'the staged generator produced no src/gl-10.c');
if (is_file($victim)) {
    file_put_contents($victim, "/* hand-edited */\n" . file_get_contents($victim));
    [$code, $text] = runScript($pkg . '/scripts/gen-gl-src.php', ['--check']);
    $expect->that($code !== 0, 'the generator accepted a hand-edited generated file');
    $expect->that(
        str_contains($text, 'src/gl-10.c') && str_contains($text, 'GEN_SRC_DRIFT'),
        "the drift report did not name the edited file:\n{$text}"
    );
}

// ---- 3. gen-zep is idempotent against the committed tree
[$code, $text] = runScript($scripts . '/gen-zep.php');
$expect->that($code === 0 && str_contains($text, 'GEN_OK'), "gen-zep failed on the real package:\n{$text}");
$expect->that(
    (bool) preg_match('/written=0 pruned=0/', $text),
    "re-running gen-zep changed the tree (it must not):\n{$text}"
);

$expect->finish('GEN_SRC_GUARD_OK');
