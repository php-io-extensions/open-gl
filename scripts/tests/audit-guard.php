#!/usr/bin/env php
<?php
/*
 * Negative controls for audit-header.php — the "nothing silently omitted"
 * guard.
 *
 *   audit-drift    an @audit block marker that claims more prototypes than
 *                  the header it names actually has (this is what catches a
 *                  re-vendored header that changed the surface)
 *   audit-short    a block whose prototypes are not all bound or reserved,
 *                  with nothing sanctioning the shortfall
 *   audit-partial  the same shortfall with @audit partial — must PASS and
 *                  print PARTIAL, because a sanctioned gap is not drift
 *
 * Also asserts the real package audits clean and reports the deferred
 * 4.2 .. 4.6 blocks rather than treating them as a shortfall.
 *
 * Prints AUDIT_GUARD_OK.
 */

declare(strict_types=1);

require __DIR__ . '/lib/harness.php';

$scripts = dirname(__DIR__);
$root = dirname($scripts);
$audit = $scripts . '/audit-header.php';
$expect = new Expect('audit-guard');

// ---- a marker that no longer matches its header
$dir = stageFixture(__DIR__ . '/fixtures/audit-drift');
[$code, $text] = runScript($audit, [$dir]);
$expect->that($code !== 0, 'the audit accepted a block marker that the header contradicts');
$expect->that(
    str_contains($text, 'the header has 2'),
    "the audit failed without naming the real header count:\n{$text}"
);

// ---- an unsanctioned shortfall
$dir = stageFixture(__DIR__ . '/fixtures/audit-short');
[$code, $text] = runScript($audit, [$dir]);
$expect->that($code !== 0, 'the audit accepted an unsanctioned shortfall');
$expect->that(
    str_contains($text, 'is short of the header'),
    "the audit failed without the shortfall diagnostic:\n{$text}"
);

// ---- the same shortfall, sanctioned
$dir = stageFixture(__DIR__ . '/fixtures/audit-partial');
[$code, $text] = runScript($audit, [$dir]);
$expect->that($code === 0, "the audit rejected an @audit partial class:\n{$text}");
$expect->that(str_contains($text, 'PARTIAL'), "an @audit partial class did not print PARTIAL:\n{$text}");
$expect->that(str_contains($text, 'AUDIT_OK'), 'the sanctioned fixture did not print AUDIT_OK');

// ---- the real package
[$code, $text] = runScript($audit, [$root]);
$expect->that($code === 0 && str_contains($text, 'AUDIT_OK'), "the real package does not audit clean:\n{$text}");
$expect->that(str_contains($text, 'failures=0'), 'the real audit reported failures');
$expect->that(
    str_contains($text, 'GL_VERSION_4_2') && str_contains($text, 'deferred'),
    'the audit did not report the deferred 4.2 .. 4.6 blocks'
);
$expect->that(
    !str_contains($text, 'SHORT') && !str_contains($text, 'EXCESS'),
    "the real audit reported a short or excess class:\n{$text}"
);

$expect->finish('AUDIT_GUARD_OK');
