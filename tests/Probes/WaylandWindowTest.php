<?php

declare(strict_types=1);

// Site opengl-wl-null-window (outcome 1): wayland-egl dereferences the wl_egl_window it is given.

beforeEach(fn () => requireProbeBuild());

it('refuses wl_egl_window 0, which wayland-egl dereferences (SIGSEGV) without the refusal', function (string $call): void {
    $kept = glProbe("{$call};", null, context: false);
    $off = glProbe("{$call};", 'opengl-wl-null-window', context: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED ValueError')
        ->and($kept['stdout'])->toContain('must not be address 0')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
})->with([
    'resize' => ['wl_egl_window_resize(0, 16, 16, 0, 0)'],
    'destroy' => ['wl_egl_window_destroy(0)'],
])->skip(MAC, 'wayland-egl is the Linux build');
