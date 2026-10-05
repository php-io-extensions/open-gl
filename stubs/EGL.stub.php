<?php

/** @generate-class-entries */

/**
 * An address other than 0 is trusted: the binding does not check that it points at a live object.
 * EGL owns the display; this handle is never released.
 *
 * @not-serializable
 */
final class EGLDisplay
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * An address other than 0 is trusted: the binding does not check that it points at a live object.
 * EGL owns the config; this handle is never released.
 *
 * @not-serializable
 */
final class EGLConfig
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * An address other than 0 is trusted: the binding does not check that it points at a live object.
 *
 * @not-serializable
 */
final class EGLContext
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * An address other than 0 is trusted: the binding does not check that it points at a live object.
 *
 * @not-serializable
 */
final class EGLSurface
{
    private function __construct() {}

    public function pointer(): int {}

    public static function fromPointer(int $pointer): static {}
}

/**
 * EGL_DEFAULT_DISPLAY is a null native display. The C macro is a pointer cast, so the PHP constant is 0.
 *
 * @var int
 */
const EGL_DEFAULT_DISPLAY = 0;

/**
 * @var int
 * @cvalue EGL_PLATFORM_SURFACELESS_MESA
 */
const EGL_PLATFORM_SURFACELESS_MESA = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_NONE
 */
const EGL_NONE = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SUCCESS
 */
const EGL_SUCCESS = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_OPENGL_ES_API
 */
const EGL_OPENGL_ES_API = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_RENDERABLE_TYPE
 */
const EGL_RENDERABLE_TYPE = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_OPENGL_ES3_BIT
 */
const EGL_OPENGL_ES3_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SURFACE_TYPE
 */
const EGL_SURFACE_TYPE = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_PBUFFER_BIT
 */
const EGL_PBUFFER_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_RED_SIZE
 */
const EGL_RED_SIZE = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_GREEN_SIZE
 */
const EGL_GREEN_SIZE = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_BLUE_SIZE
 */
const EGL_BLUE_SIZE = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_ALPHA_SIZE
 */
const EGL_ALPHA_SIZE = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_DEPTH_SIZE
 */
const EGL_DEPTH_SIZE = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_STENCIL_SIZE
 */
const EGL_STENCIL_SIZE = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_WIDTH
 */
const EGL_WIDTH = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_HEIGHT
 */
const EGL_HEIGHT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_CONTEXT_MAJOR_VERSION
 */
const EGL_CONTEXT_MAJOR_VERSION = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_CONTEXT_MINOR_VERSION
 */
const EGL_CONTEXT_MINOR_VERSION = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_VENDOR
 */
const EGL_VENDOR = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_VERSION
 */
const EGL_VERSION = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_EXTENSIONS
 */
const EGL_EXTENSIONS = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_CLIENT_APIS
 */
const EGL_CLIENT_APIS = UNKNOWN;

function eglGetDisplay(?int $display_id): ?EGLDisplay {}

/** $attrib_list, when given, is a list of ints ending with EGL_NONE. Values are widened to EGLAttrib. */
function eglGetPlatformDisplay(int $platform, ?int $native_display, ?array $attrib_list): ?EGLDisplay {}

function eglInitialize(EGLDisplay $display, ?int &$major, ?int &$minor): bool {}

function eglTerminate(EGLDisplay $display): bool {}

function eglBindAPI(int $api): bool {}

/** $attrib_list, when given, is a list of ints ending with EGL_NONE. */
function eglChooseConfig(EGLDisplay $display, ?array $attrib_list, ?array &$configs, int $config_size, ?int &$num_config): bool {}

/** $attrib_list, when given, is a list of ints ending with EGL_NONE. */
function eglCreateContext(EGLDisplay $display, ?EGLConfig $config, ?EGLContext $share_context, ?array $attrib_list): ?EGLContext {}

function eglDestroyContext(EGLDisplay $display, EGLContext $context): bool {}

/** $attrib_list, when given, is a list of ints ending with EGL_NONE. */
function eglCreatePbufferSurface(EGLDisplay $display, EGLConfig $config, ?array $attrib_list): ?EGLSurface {}

function eglDestroySurface(EGLDisplay $display, EGLSurface $surface): bool {}

function eglMakeCurrent(EGLDisplay $display, ?EGLSurface $draw, ?EGLSurface $read, ?EGLContext $ctx): bool {}

function eglGetCurrentContext(): ?EGLContext {}

function eglSwapBuffers(EGLDisplay $display, EGLSurface $surface): bool {}

function eglGetError(): int {}

function eglQueryString(?EGLDisplay $display, int $name): ?string {}
