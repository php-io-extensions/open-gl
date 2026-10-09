<?php

declare(strict_types=1);

/*
 * An EGL window surface made by hand on a GLFW window with no client API: the
 * colour space and HDR metadata a GL engine shows HDR with. Linux, in the
 * Wayland session.
 */

/** The first window config with exactly 8 bits of red: EGL lists deeper configs first, and Mesa takes an sRGB colour space only on 8-bit ones. */
function eightBitConfig(EGLDisplay $display): EGLConfig
{
    eglChooseConfig($display, [EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT, EGL_SURFACE_TYPE, EGL_WINDOW_BIT, EGL_RED_SIZE, 8, EGL_NONE], $configs, 64, $count);
    foreach ($configs as $config) {
        eglGetConfigAttrib($display, $config, EGL_RED_SIZE, $red);
        if ($red === 8) {
            return $config;
        }
    }

    throw new RuntimeException('no 8-bit window config');
}

/** @return array{GLFWwindow, EGLDisplay, int} the window, its display, the wl_egl_window (0 on X11) */
function eglWindow(int $width, int $height): array
{
    glfwInitHint(GLFW_WAYLAND_LIBDECOR, GLFW_WAYLAND_DISABLE_LIBDECOR);
    glfwInit() || throw new RuntimeException('glfwInit');
    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    $window = glfwCreateWindow($width, $height, 'ext-opengl window surface');
    $wayland = glfwGetPlatform() === GLFW_PLATFORM_WAYLAND;
    $display = eglGetPlatformDisplay($wayland ? EGL_PLATFORM_WAYLAND_KHR : EGL_PLATFORM_X11_KHR, $wayland ? glfwGetWaylandDisplay() : glfwGetX11Display(), null)
        ?? throw new RuntimeException('eglGetPlatformDisplay '.eglGetError());
    eglInitialize($display, $major, $minor) || throw new RuntimeException('eglInitialize '.eglGetError());
    eglBindAPI(EGL_OPENGL_ES_API);
    $native = $wayland ? wl_egl_window_create(glfwGetWaylandWindow($window), $width, $height) : 0;

    return [$window, $display, $native];
}

it('makes a window surface on a wl_egl_window or an X11 window, resizes and destroys it', function (): void {
    [$window, $display, $native] = eglWindow(64, 48);
    eglChooseConfig($display, [EGL_RENDERABLE_TYPE, EGL_OPENGL_ES3_BIT, EGL_SURFACE_TYPE, EGL_WINDOW_BIT, EGL_RED_SIZE, 8, EGL_NONE], $configs, 1, $count);
    $surface = eglCreateWindowSurface($display, $configs[0], $native !== 0 ? $native : glfwGetX11Window($window), null);

    expect($surface)->toBeInstanceOf(EGLSurface::class)
        ->and(eglGetConfigAttrib($display, $configs[0], EGL_RED_SIZE, $red))->toBeTrue()
        ->and($red)->toBeGreaterThanOrEqual(8)
        ->and(eglGetConfigAttrib($display, $configs[0], 0x7FFF, $nothing))->toBeFalse();
    if ($native !== 0) {
        wl_egl_window_resize($native, 80, 60, 0, 0);
    }
    eglDestroySurface($display, $surface);
    if ($native !== 0) {
        wl_egl_window_destroy($native);
    }
    glfwDestroyWindow($window);
})->skip(MAC || ! extension_loaded('glfw') || getenv('WAYLAND_DISPLAY') === false, 'needs Linux, ext-glfw and the Wayland session');

it('names a colour space and HDR10 metadata on a window surface where the display has them', function (): void {
    [$window, $display, $native] = eglWindow(32, 32);
    $extensions = (string) eglQueryString($display, EGL_EXTENSIONS);
    $configs = [eightBitConfig($display)];
    $where = $native !== 0 ? $native : glfwGetX11Window($window);

    if (! str_contains($extensions, 'EGL_KHR_gl_colorspace')) {
        expect(eglCreateWindowSurface($display, $configs[0], $where, [EGL_GL_COLORSPACE_KHR, EGL_GL_COLORSPACE_SRGB_KHR, EGL_NONE]))->toBeNull();
    } else {
        $surface = eglCreateWindowSurface($display, $configs[0], $where, [EGL_GL_COLORSPACE_KHR, EGL_GL_COLORSPACE_SRGB_KHR, EGL_NONE]);
        expect(eglQuerySurface($display, $surface, EGL_GL_COLORSPACE_KHR, $space))->toBeTrue()
            ->and($space)->toBe(EGL_GL_COLORSPACE_SRGB_KHR)
            // Mesa takes the attribute whether or not it lists the extension; listed, it must take it.
            ->and(eglSurfaceAttrib($display, $surface, EGL_SMPTE2086_MAX_LUMINANCE_EXT, 1000 * EGL_METADATA_SCALING_EXT) || ! str_contains($extensions, 'EGL_EXT_surface_SMPTE2086_metadata'))->toBeTrue();
        eglDestroySurface($display, $surface);
    }
    if ($native !== 0) {
        wl_egl_window_destroy($native);
    }
    glfwDestroyWindow($window);
})->skip(MAC || ! extension_loaded('glfw') || getenv('WAYLAND_DISPLAY') === false, 'needs Linux, ext-glfw and the Wayland session');

it('answers 0 for a wl_egl_window on no surface', function (): void {
    expect(wl_egl_window_create(0, 8, 8))->toBe(0);
})->skip(MAC, 'EGL is the Linux build');
