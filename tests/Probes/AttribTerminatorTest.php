<?php

declare(strict_types=1);

// Site opengl-attrib-terminator (outcome 1): CGLChoosePixelFormat reads attributes up to the 0 that
// ends the list. Without it, CGL reads past the array. EGL stops at the first attribute it does not
// take (no crash on Mesa), so EGL lists go to EGL as given.

beforeEach(fn () => requireProbeBuild());

it('refuses a CGL attribute list without its 0, which CGL reads past (SIGSEGV) without the refusal', function (): void {
    $code = 'CGLChoosePixelFormat(array_fill(0, 1 << 20, kCGLPFAAccelerated), $pix, $n);';

    $kept = glProbe($code, null, context: false);
    $off = glProbe($code, 'opengl-attrib-terminator', context: false, gmalloc: true);

    expect($kept['signal'])->toBeNull()
        ->and($kept['stdout'])->toContain('REFUSED ValueError')
        ->and($kept['stdout'])->toContain('must end with 0')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
})->skip(! MAC, 'CGL is the macOS build');
