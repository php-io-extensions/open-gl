<?php

declare(strict_types=1);

/*
 * The support list: every command of OpenGL 4.1 core and OpenGL ES 3.0, the two dialects this
 * extension builds on (macOS's and the Pi's floor), of EGL 1.5 and of CGL, marked bound when a stub
 * declares the PHP function of the same name.
 *
 *   php84 scripts/support.php           writes SUPPORT.md and the README badge
 *   php84 scripts/support.php --check   exits 1 when either differs (the date is not compared)
 *
 * gl.xml and egl.xml are read at pinned Khronos registry commits, cached under scripts/.support-cache/.
 * OpenGL is the core profile: each version's requires added in order, its core-profile removes taken
 * away. ES counts versions 2.0 and 3.0; EGL 1.0 to 1.5; extensions are not counted. A command both
 * dialects have sits under its GL version only. CGL is every CGL function the macOS SDK's
 * OpenGL.framework headers declare (clang's AST dump, macOS only); Apple marks all of OpenGL
 * deprecated, so CGL's deprecation is not a filter here.
 */

const SUPPORT_LABEL = 'OpenGL API';
const SUPPORT_GL = ['version' => '4.1', 'es' => '3.0', 'egl' => '1.5'];
const SUPPORT_GL_XML = 'https://raw.githubusercontent.com/KhronosGroup/OpenGL-Registry/6af574a14089ccfee87efe230ebcdd8742859813/xml/gl.xml';
const SUPPORT_EGL_XML = 'https://raw.githubusercontent.com/KhronosGroup/EGL-Registry/e964211ff5f7c2bcada786954a16d5b813379395/api/egl.xml';
const SUPPORT_FRAMEWORK = '/OpenGL.framework/Headers/';

/**
 * The commands of one API's versions up to $max, under the version that adds each, after the
 * removes of $profile. Commands already in $seen are skipped and recorded there.
 * @param array<string, true> $seen
 * @return array<string, list<string>>
 */
function support_registry(string $xml, string $api, string $max, ?string $profile, array &$seen): array
{
    $registry = simplexml_load_string($xml);
    if ($registry === false) {
        throw new RuntimeException("Cannot read the {$api} registry.");
    }
    $owner = [];
    foreach ($registry->xpath('/registry/feature') as $feature) {
        if ((string) $feature['api'] !== $api || version_compare((string) $feature['number'], $max, '>')) {
            continue;
        }
        foreach ($feature->require as $require) {
            if (isset($require['profile']) && (string) $require['profile'] !== $profile) {
                continue;
            }
            foreach ($require->command as $command) {
                $owner[(string) $command['name']] ??= (string) $feature['name'];
            }
        }
        foreach ($feature->remove as $remove) {
            if (! isset($remove['profile']) || (string) $remove['profile'] === $profile) {
                foreach ($remove->command as $command) {
                    unset($owner[(string) $command['name']]);
                }
            }
        }
    }
    $counted = [];
    foreach ($owner as $name => $feature) {
        if (! isset($seen[$name])) {
            $seen[$name] = true;
            $counted[$feature][] = $name;
        }
    }
    uksort($counted, 'support_version_order');
    foreach ($counted as &$names) {
        sort($names, SORT_STRING);
    }
    unset($names);

    return $counted;
}

/** GL_VERSION_1_10 after GL_VERSION_1_5: the feature names in version order. */
function support_version_order(string $a, string $b): int
{
    $number = static fn (string $n): string => preg_replace('/^.*VERSION_(\d+)_(\d+)$/', '$1.$2', $n);

    return version_compare($number($a), $number($b));
}

/** @return list<string> sorted CGL function names declared in OpenGL.framework headers, from a text AST dump */
function support_cgl(string $ast): array
{
    $names = [];
    $file = '';
    foreach (explode("\n", $ast) as $line) {
        if (preg_match('#<(/[^:<>]+):\d+:\d+#', $line, $m) === 1) {
            $file = $m[1];
        }
        if (preg_match("/^[|`]-FunctionDecl .*? (CGL\\w+) '/", $line, $m) === 1 && str_contains($file, SUPPORT_FRAMEWORK)) {
            $names[] = $m[1];
        }
    }
    $names = array_values(array_unique($names));
    sort($names, SORT_STRING);

    return $names;
}

/** The free functions the stubs declare. @return array<string, true> */
function support_bound(string $stubDir): array
{
    $bound = [];
    foreach (glob(rtrim($stubDir, '/') . '/*.stub.php') ?: [] as $file) {
        foreach (support_functions(file_get_contents($file)) as $function) {
            $bound[$function] = true;
        }
    }

    return $bound;
}

/**
 * The top-level functions of one stub, without class methods.
 * @return list<string>
 */
function support_functions(string $source): array
{
    $tokens = token_get_all($source);
    $out = [];
    $depth = 0;
    foreach ($tokens as $i => $token) {
        if ($token === '{' || (is_array($token) && in_array($token[0], [T_CURLY_OPEN, T_DOLLAR_OPEN_CURLY_BRACES], true))) {
            $depth++;
        } elseif ($token === '}') {
            $depth--;
        } elseif (is_array($token) && $token[0] === T_FUNCTION && $depth === 0) {
            for ($j = $i + 1; is_array($tokens[$j]) && $tokens[$j][0] === T_WHITESPACE; $j++) {
            }
            if (is_array($tokens[$j]) && $tokens[$j][0] === T_STRING) {
                $out[] = $tokens[$j][1];
            }
        }
    }

    return array_values(array_unique($out));
}

/**
 * @param array<string, list<string>> $counted
 * @param array<string, true> $bound
 */
function support_render(array $counted, array $bound, string $library, string $date): string
{
    $sections = [];
    $hits = 0;
    $total = 0;
    $countedKeys = [];
    foreach ($counted as $owner => $keys) {
        $lines = [];
        $ownerHits = 0;
        foreach ($keys as $key) {
            $countedKeys[$key] = true;
            $isBound = isset($bound[$key]);
            $ownerHits += $isBound ? 1 : 0;
            $lines[] = '- [' . ($isBound ? 'x' : ' ') . "] `{$key}`";
        }
        $hits += $ownerHits;
        $total += count($keys);
        $sections[] = "## {$owner} ({$ownerHits} / " . count($keys) . ")\n\n" . implode("\n", $lines) . "\n";
    }
    $outside = array_map(static fn (string $f): string => "- `{$f}`", array_keys(array_diff_key($bound, $countedKeys)));
    sort($outside, SORT_STRING);

    return '# ' . SUPPORT_LABEL . " support\n\n"
        . support_summary($library, $hits, $total, $date) . "\n\n"
        . "Generated by `php84 scripts/support.php` from the Khronos gl.xml and egl.xml registries, the macOS SDK's CGL headers and `stubs/`. One line per command: `[x]` bound, `[ ]` not bound. GL is the 4.1 core profile; a command ES 2.0 / 3.0 shares with it is listed under its GL version.\n\n"
        . implode("\n", $sections)
        . "\n## Bound outside the measured library\n\n"
        . "Functions the stubs declare that are none of the measured commands (extensions, the extension's own); none of them is counted.\n\n"
        . (count($outside) === 0 ? "None.\n" : implode("\n", $outside) . "\n");
}

function support_summary(string $library, int $hits, int $total, string $date): string
{
    return sprintf('%s — %d / %d members bound (%.1f%%) — %s', $library, $hits, $total, $total === 0 ? 0 : 100 * $hits / $total, $date);
}

function support_badge(string $label, int $bound, int $total): string
{
    $percent = sprintf('%.1f', $total === 0 ? 0 : 100 * $bound / $total);
    $message = str_replace('%20', '_', rawurlencode("{$percent}% ({$bound}/{$total})"));

    return "[![{$label}](https://img.shields.io/badge/" . str_replace(' ', '_', $label) . "-{$message}-blue?style=flat-square)](SUPPORT.md)";
}

/** Two support lists alike but for the date of their summary line. */
function support_same(string $a, string $b): bool
{
    $undated = static fn (string $s): string => preg_replace('/ — \d{4}-\d{2}-\d{2}$/m', '', $s);

    return $undated($a) === $undated($b);
}

/** The README with the badge line set: replaced where it is, else after the CI badge. */
function support_readme(string $readme, string $badge): string
{
    $lines = explode("\n", $readme);
    foreach ($lines as $i => $line) {
        if (str_starts_with($line, '[![' . SUPPORT_LABEL . ']')) {
            $lines[$i] = $badge;

            return implode("\n", $lines);
        }
    }
    foreach ($lines as $i => $line) {
        if (str_starts_with($line, '[![CI]')) {
            array_splice($lines, $i + 1, 0, [$badge]);

            return implode("\n", $lines);
        }
    }
    throw new RuntimeException('The README has no CI badge line to put the API badge after.');
}

/** @return array{int, int} bound and total, read back from a support list's summary line */
function support_totals(string $md): array
{
    preg_match('/ (\d+) \/ (\d+) members bound/', $md, $m);

    return [(int) $m[1], (int) $m[2]];
}

/** A pinned upstream file, downloaded once into the cache. */
function support_fetch(string $url, string $cache): string
{
    if (! is_file($cache)) {
        $body = @file_get_contents($url);
        if ($body === false) {
            throw new RuntimeException("Cannot download {$url}.");
        }
        @mkdir(dirname($cache), 0777, true);
        file_put_contents($cache, $body);
    }

    return file_get_contents($cache);
}

/** The text AST dump of the SDK's CGL headers, or null when clang cannot read them. */
function support_cgl_ast(): ?string
{
    $sdk = trim((string) shell_exec('xcrun --show-sdk-path 2>/dev/null'));
    $source = tempnam(sys_get_temp_dir(), 'support') . '.c';
    file_put_contents($source, "#include <OpenGL/OpenGL.h>\n#include <OpenGL/CGLDevice.h>\n#include <OpenGL/CGLIOSurface.h>\n");
    try {
        exec('/usr/bin/clang -x c -fsyntax-only -isysroot ' . escapeshellarg($sdk) . ' -Xclang -ast-dump ' . escapeshellarg($source) . ' 2>/dev/null', $lines, $status);
    } finally {
        @unlink($source);
        @unlink(substr($source, 0, -2));
    }

    return $sdk === '' || $status !== 0 ? null : implode("\n", $lines);
}

function support_main(array $argv): int
{
    $root = dirname(__DIR__);
    $cache = "{$root}/scripts/.support-cache/opengl";
    try {
        $gl = support_fetch(SUPPORT_GL_XML, "{$cache}/gl.xml");
        $egl = support_fetch(SUPPORT_EGL_XML, "{$cache}/egl.xml");
    } catch (RuntimeException $e) {
        fwrite(STDERR, $e->getMessage() . "\n");

        return 2;
    }
    $ast = support_cgl_ast();
    if ($ast === null) {
        fwrite(STDERR, "clang could not read the SDK's CGL headers (macOS with the Command Line Tools).\n");

        return 2;
    }
    $sdkVersion = trim((string) shell_exec('xcrun --show-sdk-version'));
    $seen = [];
    $counted = support_registry($gl, 'gl', SUPPORT_GL['version'], 'core', $seen)
        + support_registry($gl, 'gles2', SUPPORT_GL['es'], null, $seen)
        + support_registry($egl, 'egl', SUPPORT_GL['egl'], null, $seen)
        + ['CGL' => support_cgl($ast)];
    $library = 'OpenGL ' . SUPPORT_GL['version'] . ' core, OpenGL ES ' . SUPPORT_GL['es'] . ', EGL ' . SUPPORT_GL['egl'] . ", CGL (macOS SDK {$sdkVersion})";
    $md = support_render($counted, support_bound("{$root}/stubs"), $library, date('Y-m-d'));
    [$hits, $total] = support_totals($md);
    $readme = support_readme(file_get_contents("{$root}/README.md"), support_badge(SUPPORT_LABEL, $hits, $total));

    if (in_array('--check', $argv, true)) {
        $current = is_file("{$root}/SUPPORT.md") ? file_get_contents("{$root}/SUPPORT.md") : '';
        $same = support_same($current, $md) && $readme === file_get_contents("{$root}/README.md");
        fwrite(STDOUT, $same ? "SUPPORT.md and the badge are current.\n" : "SUPPORT.md or the badge differs: run php84 scripts/support.php.\n");

        return $same ? 0 : 1;
    }
    file_put_contents("{$root}/SUPPORT.md", $md);
    file_put_contents("{$root}/README.md", $readme);
    fwrite(STDOUT, "{$hits} / {$total}\n");

    return 0;
}

if (PHP_SAPI === 'cli' && isset($argv[0]) && realpath($argv[0]) === __FILE__) {
    exit(support_main($argv));
}
