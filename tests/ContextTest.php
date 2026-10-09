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

it('answers the display and surfaces current with an EGL context', function (): void {
    if (MAC) {
        expect(function_exists('eglGetCurrentDisplay'))->toBeFalse();

        return;
    }
    $display = eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA, EGL_DEFAULT_DISPLAY, null);
    eglInitialize($display, $major, $minor);
    eglBindAPI(EGL_OPENGL_ES_API);
    eglChooseConfig($display, [EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT, EGL_SURFACE_TYPE, EGL_PBUFFER_BIT, EGL_NONE], $configs, 1, $count);
    $context = eglCreateContext($display, $configs[0], null, [EGL_CONTEXT_MAJOR_VERSION, 3, EGL_NONE]);
    $surface = eglCreatePbufferSurface($display, $configs[0], [EGL_WIDTH, 4, EGL_HEIGHT, 4, EGL_NONE]);
    $previous = [eglGetCurrentDisplay(), eglGetCurrentSurface(EGL_DRAW), eglGetCurrentSurface(EGL_READ), eglGetCurrentContext()];
    eglMakeCurrent($display, $surface, $surface, $context);

    expect(eglGetCurrentDisplay()?->pointer())->toBe($display->pointer())
        ->and(eglGetCurrentSurface(EGL_DRAW)?->pointer())->toBe($surface->pointer())
        ->and(eglGetCurrentSurface(EGL_READ)?->pointer())->toBe($surface->pointer());

    eglMakeCurrent($display, null, null, null);

    expect(eglGetCurrentDisplay())->toBeNull()
        ->and(eglGetCurrentSurface(EGL_DRAW))->toBeNull();
    eglDestroySurface($display, $surface);
    eglDestroyContext($display, $context);
    // The suite's glContext() keeps its context current across tests: it goes back.
    if (! is_null($previous[3])) {
        eglMakeCurrent(...$previous);
    }
});

it('queries a surface and sets the swap interval of the current context', function (): void {
    $display = eglGetPlatformDisplay(EGL_PLATFORM_SURFACELESS_MESA, EGL_DEFAULT_DISPLAY, null);
    eglInitialize($display, $major, $minor);
    eglBindAPI(EGL_OPENGL_ES_API);
    eglChooseConfig($display, [EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT, EGL_SURFACE_TYPE, EGL_PBUFFER_BIT, EGL_NONE], $configs, 1, $count);
    $context = eglCreateContext($display, $configs[0], null, [EGL_CONTEXT_MAJOR_VERSION, 3, EGL_NONE]);
    $surface = eglCreatePbufferSurface($display, $configs[0], [EGL_WIDTH, 6, EGL_HEIGHT, 4, EGL_NONE]);
    $previous = [eglGetCurrentDisplay(), eglGetCurrentSurface(EGL_DRAW), eglGetCurrentSurface(EGL_READ), eglGetCurrentContext()];
    eglMakeCurrent($display, $surface, $surface, $context);

    expect(eglQuerySurface($display, $surface, EGL_WIDTH, $width))->toBeTrue()
        ->and(eglQuerySurface($display, $surface, EGL_HEIGHT, $height))->toBeTrue()
        ->and([$width, $height])->toBe([6, 4])
        ->and(eglQuerySurface($display, $surface, EGL_SWAP_BEHAVIOR, $behaviour))->toBeTrue()
        ->and($behaviour)->toBeIn([EGL_BUFFER_PRESERVED, EGL_BUFFER_DESTROYED])
        ->and(eglQuerySurface($display, $surface, 0x7FFF, $nothing))->toBeFalse()
        ->and(eglSwapInterval($display, 0))->toBeTrue();

    eglMakeCurrent($display, null, null, null);
    eglDestroySurface($display, $surface);
    eglDestroyContext($display, $context);
    if (! is_null($previous[3])) {
        eglMakeCurrent(...$previous);
    }
})->skip(MAC, 'EGL is the Linux build');

it('swaps a window surface with only the damaged rects', function (): void {
    // Taken before GLFW: creating its window releases whatever context the thread had current.
    $previous = [eglGetCurrentDisplay(), eglGetCurrentSurface(EGL_DRAW), eglGetCurrentSurface(EGL_READ), eglGetCurrentContext()];
    glfwInitHint(GLFW_WAYLAND_LIBDECOR, GLFW_WAYLAND_DISABLE_LIBDECOR);
    glfwInit() || throw new RuntimeException('glfwInit');
    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_CONTEXT_CREATION_API, GLFW_EGL_CONTEXT_API);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    $window = glfwCreateWindow(64, 48, 'ext-opengl damage');
    glfwMakeContextCurrent($window);
    $display = EGLDisplay::fromPointer(glfwGetEGLDisplay());
    $surface = EGLSurface::fromPointer(glfwGetEGLSurface($window));
    glfwPollEvents();

    $supported = str_contains((string) eglQueryString($display, EGL_EXTENSIONS), 'EGL_KHR_swap_buffers_with_damage');
    glClearColor(1.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    expect(eglSwapBuffersWithDamageKHR($display, $surface, [0, 0, 16, 16, 32, 16, 8, 8]))->toBe($supported)
        ->and(eglSwapBuffersWithDamageKHR($display, $surface, []))->toBe($supported)
        ->and(fn () => eglSwapBuffersWithDamageKHR($display, $surface, [0, 0, 16]))->toThrow(ValueError::class, 'must hold four ints a rect, got 3 ints')
        ->and($supported)->toBeTrue();

    glfwMakeContextCurrent(null);
    glfwDestroyWindow($window);
    if (! is_null($previous[3])) {
        eglMakeCurrent(...$previous);
    }
})->skip(MAC || ! extension_loaded('glfw') || getenv('WAYLAND_DISPLAY') === false, 'needs Linux, ext-glfw and the Wayland session');
