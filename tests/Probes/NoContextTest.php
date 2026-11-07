<?php

declare(strict_types=1);

// Site opengl-no-context (outcome 1): macOS GL dereferences the current context, so a gl* call with
// none crashes. Linux's libglvnd answers such a call with nothing, so the site is macOS only.

beforeEach(fn () => requireProbeBuild());

it('refuses a gl* call with no current context, which macOS GL dereferences (SIGSEGV) without the refusal', function (string $call): void {
    $kept = glProbe("{$call};", null, context: false);
    $off = glProbe("{$call};", 'opengl-no-context', context: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED Error')
        ->and($kept['stdout'])->toContain('no current OpenGL context')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
})->with([
    'glGetError' => ['glGetError()'],
    'glClear' => ['glClear(GL_COLOR_BUFFER_BIT)'],
    'glGenBuffers' => ['glGenBuffers(1, $names)'],
])->skip(! MAC, 'libglvnd answers a call with no context on Linux');
