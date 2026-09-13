#!/usr/bin/env php
<?php
/*
 * The loader's cache-invalidation contract.
 *
 * Bridge::load() must invalidate everything cached off the library
 * situation, not just re-open libraries:
 *
 *   - every entry-point slot (a slot that resolved to "missing" once must be
 *     retried after a load(), not latched for the life of the process)
 *   - the current-context probe table
 *   - the sampled context version
 *
 * Honest note on coverage. The slot half is checked STRUCTURALLY, because
 * making it observable from PHP needs a symbol that is absent and then
 * present in one process — i.e. breaking the box's GL libraries mid-run,
 * which no test here is allowed to do. The generation counter, its
 * comparison in phpgl_entry(), its bump in load(), and the probe table's
 * dependence on it are asserted in the source instead. The version-sample
 * half IS observable and is exercised live below.
 *
 * Prints LOADER_GUARD_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$root = dirname(__DIR__, 2);
$expect = new Expect('loader-guard');

// ---- structural: the generation mechanism is actually wired ---------------
$h = (string) file_get_contents($root . '/src/phpgl-bridge.h');
$c = (string) file_get_contents($root . '/src/phpgl-bridge.c');

$expect->that(
    (bool) preg_match('/typedef struct \{[^}]*unsigned int generation;[^}]*\} phpgl_slot;/s', $h),
    'phpgl_slot has no generation field'
);
$expect->that(
    str_contains($h, '#define PHPGL_SLOT_INIT {NULL, 0, 0}'),
    'PHPGL_SLOT_INIT does not initialise the generation to 0 (a fresh slot must look stale)'
);
$expect->that(
    (bool) preg_match('/slot->state == 0 \|\| slot->generation != phpgl_generation/', $c),
    'phpgl_entry does not re-resolve a slot from an older generation'
);
$expect->that(
    (bool) preg_match('/slot->generation = phpgl_generation;/', $c),
    'phpgl_entry does not stamp the slot with the current generation'
);
$expect->that(
    (bool) preg_match('/phpgl_bridge_load\(void\).*?phpgl_generation\+\+;/s', $c),
    'Bridge::load() does not bump the generation'
);
$expect->that(
    (bool) preg_match('/phpgl_ctx_probes_generation != phpgl_generation/', $c),
    'the current-context probe table is not keyed on the generation'
);
$expect->that(
    !preg_match('/static int probed = 0;/', $c),
    'the frozen-forever `static int probed` flag is still present'
);
$expect->that(
    (bool) preg_match('/phpgl_bridge_shutdown\(void\).*?phpgl_generation\+\+;/s', $c),
    'the module teardown does not invalidate cached slots'
);

// ---- structural: no allocation path can take the process down ------------
$expect->that(
    !preg_match('/\bpemalloc\s*\(\s*\(size_t\)/', $c),
    'a caller-sized allocation still goes through pemalloc, whose failure path exits'
);
$expect->that(
    (bool) preg_match('/block = malloc\(\(size_t\) want\);\s*if \(!block\) \{/', $c),
    'Bridge::alloc does not check malloc for NULL'
);

// ---- structural: a gated call needs a context on EVERY call --------------
$expect->that(
    (bool) preg_match('/if \(major > 0\) \{.*?if \(!phpgl_have_current_context\(\)\) \{/s', $c),
    'phpgl_entry does not re-check for a current context on a gated call'
);

// ---- live: the version sample is re-taken on every load() ----------------
if (extension_loaded('opengl')) {
    $php = escapeshellarg(PHP_BINARY);
    $script = <<<'PHP'
use OpenGL\Bridge\Bridge;
Bridge::load();
$a = Bridge::contextVersion();
Bridge::load();
$b = Bridge::contextVersion();
echo json_encode(['first' => $a, 'second' => $b]), "\n";
PHP;
    $out = [];
    exec($php . ' -r ' . escapeshellarg($script) . ' 2>&1', $out, $code);
    $text = implode("\n", $out);
    $json = json_decode(trim((string) end($out)), true);

    $expect->that($code === 0, "the load()/load() sequence did not exit cleanly:\n{$text}");
    $expect->that(is_array($json), "the load()/load() sequence produced no readable result:\n{$text}");
    if (is_array($json)) {
        $expect->that(
            $json['first'] === $json['second'],
            'two load()s with nothing in between disagreed about the context version'
        );
        $expect->that(
            ($json['second']['loaded'] ?? null) === true,
            'the second load() did not report the libraries open'
        );
    }

    // With no context current, every GL name is refused and the process lives.
    $script = <<<'PHP'
use OpenGL\Bridge\Bridge;
use OpenGL\GL\GL10\GL10;
Bridge::load();
$n = 0;
set_error_handler(function () use (&$n) { $n++; return true; });
for ($i = 0; $i < 5; $i++) { GL10::glClear(0x4000); }
$v = GL10::glGetString(0x1F02);
restore_error_handler();
echo json_encode(['warnings' => $n, 'string' => $v, 'available' => Bridge::isAvailable('glClear')]), "\n";
PHP;
    $out = [];
    exec($php . ' -r ' . escapeshellarg($script) . ' 2>&1', $out, $code);
    $json = json_decode(trim((string) end($out)), true);
    $expect->that($code === 0, 'GL calls with no current context did not leave the process alive');
    $expect->that(
        is_array($json) && $json['warnings'] >= 5,
        'a GL call with no current context did not warn every time'
    );
    $expect->that(
        is_array($json) && $json['available'] === false,
        'isAvailable reported a GL name usable with no context current'
    );

    // The OOM path the review found: a size that cannot be allocated must
    // warn and return 0, not exit(1).
    $script = <<<'PHP'
use OpenGL\Bridge\Bridge;
$r = [];
set_error_handler(function () { return true; });
foreach ([PHP_INT_MAX, 1 << 62, 1 << 50] as $n) { $r[] = Bridge::alloc($n); }
restore_error_handler();
echo json_encode(['results' => $r, 'alive' => true]), "\n";
PHP;
    $out = [];
    exec($php . ' -r ' . escapeshellarg($script) . ' 2>&1', $out, $code);
    $json = json_decode(trim((string) end($out)), true);
    $expect->that($code === 0, 'an impossible Bridge::alloc took the process down');
    $expect->that(
        is_array($json) && $json['results'] === [0, 0, 0],
        'an impossible Bridge::alloc did not return 0'
    );
} else {
    echo "loader-guard: the opengl extension is not loaded; live checks skipped\n";
}

$expect->finish('LOADER_GUARD_OK');
