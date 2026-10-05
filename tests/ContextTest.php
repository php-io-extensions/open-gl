<?php

declare(strict_types=1);

it('refuses a GL call with no current context', function (): void {
    // A fresh process: this run makes a context current in whichever test file goes first.
    $output = shell_exec(escapeshellarg(PHP_BINARY) . ' -r ' . escapeshellarg('try { glGetString(GL_VERSION); } catch (Error $e) { echo $e->getMessage(); }') . ' 2>&1');

    expect($output)->toBe('glGetString(): no current OpenGL context');
});

it('makes an offscreen context of the platform\'s dialect current', function (): void {
    glContext();

    expect(glGetString(GL_VERSION))->toStartWith(MAC ? '4.1' : 'OpenGL ES 3.')
        ->and(glGetString(GL_RENDERER))->not->toBe('')
        ->and(glGetError())->toBe(GL_NO_ERROR);
});

it('fills as many integers as the query answers', function (): void {
    glContext();
    glGetIntegerv(GL_MAX_SAMPLES, $samples);
    glGetIntegerv(GL_VIEWPORT, $viewport);
    glGetIntegerv(GL_MAX_VIEWPORT_DIMS, $dims);

    expect($samples)->toHaveCount(1)
        ->and($samples[0])->toBeGreaterThanOrEqual(4)
        ->and($viewport)->toHaveCount(4)
        ->and($dims)->toHaveCount(2);
});

it('refuses an attribute list without its terminator', function (): void {
    if (MAC) {
        CGLChoosePixelFormat([kCGLPFAAccelerated], $pixelFormat, $count);
    } else {
        eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA, EGL_DEFAULT_DISPLAY, [EGL_WIDTH, 1]);
    }
})->throws(ValueError::class, 'must end with');

it('names CGL errors and EGL\'s client APIs', function (): void {
    if (MAC) {
        expect(CGLErrorString(kCGLNoError))->toBe('no error');
    } else {
        $display = eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA, EGL_DEFAULT_DISPLAY, null);
        eglInitialize($display, $major, $minor);
        expect([$major, $minor])->toBe([1, 5])
            ->and(eglQueryString($display, EGL_CLIENT_APIS))->toContain('OpenGL_ES');
    }
});
