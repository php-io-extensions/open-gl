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
 * @cvalue EGL_DRAW
 */
const EGL_DRAW = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_READ
 */
const EGL_READ = UNKNOWN;

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

/**
 * @var int
 * @cvalue EGL_SWAP_BEHAVIOR
 */
const EGL_SWAP_BEHAVIOR = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_BUFFER_PRESERVED
 */
const EGL_BUFFER_PRESERVED = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_BUFFER_DESTROYED
 */
const EGL_BUFFER_DESTROYED = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_RENDER_BUFFER
 */
const EGL_RENDER_BUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_BACK_BUFFER
 */
const EGL_BACK_BUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SINGLE_BUFFER
 */
const EGL_SINGLE_BUFFER = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_PLATFORM_WAYLAND_KHR
 */
const EGL_PLATFORM_WAYLAND_KHR = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_PLATFORM_X11_KHR
 */
const EGL_PLATFORM_X11_KHR = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_WINDOW_BIT
 */
const EGL_WINDOW_BIT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_GL_COLORSPACE_KHR
 */
const EGL_GL_COLORSPACE_KHR = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_GL_COLORSPACE_SRGB_KHR
 */
const EGL_GL_COLORSPACE_SRGB_KHR = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_GL_COLORSPACE_LINEAR_KHR
 */
const EGL_GL_COLORSPACE_LINEAR_KHR = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_GL_COLORSPACE_SCRGB_LINEAR_EXT
 */
const EGL_GL_COLORSPACE_SCRGB_LINEAR_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_GL_COLORSPACE_BT2020_PQ_EXT
 */
const EGL_GL_COLORSPACE_BT2020_PQ_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_GL_COLORSPACE_DISPLAY_P3_EXT
 */
const EGL_GL_COLORSPACE_DISPLAY_P3_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_COLOR_COMPONENT_TYPE_EXT
 */
const EGL_COLOR_COMPONENT_TYPE_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_COLOR_COMPONENT_TYPE_FIXED_EXT
 */
const EGL_COLOR_COMPONENT_TYPE_FIXED_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_COLOR_COMPONENT_TYPE_FLOAT_EXT
 */
const EGL_COLOR_COMPONENT_TYPE_FLOAT_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SMPTE2086_DISPLAY_PRIMARY_RX_EXT
 */
const EGL_SMPTE2086_DISPLAY_PRIMARY_RX_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SMPTE2086_DISPLAY_PRIMARY_RY_EXT
 */
const EGL_SMPTE2086_DISPLAY_PRIMARY_RY_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SMPTE2086_DISPLAY_PRIMARY_GX_EXT
 */
const EGL_SMPTE2086_DISPLAY_PRIMARY_GX_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SMPTE2086_DISPLAY_PRIMARY_GY_EXT
 */
const EGL_SMPTE2086_DISPLAY_PRIMARY_GY_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SMPTE2086_DISPLAY_PRIMARY_BX_EXT
 */
const EGL_SMPTE2086_DISPLAY_PRIMARY_BX_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SMPTE2086_DISPLAY_PRIMARY_BY_EXT
 */
const EGL_SMPTE2086_DISPLAY_PRIMARY_BY_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SMPTE2086_WHITE_POINT_X_EXT
 */
const EGL_SMPTE2086_WHITE_POINT_X_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SMPTE2086_WHITE_POINT_Y_EXT
 */
const EGL_SMPTE2086_WHITE_POINT_Y_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SMPTE2086_MAX_LUMINANCE_EXT
 */
const EGL_SMPTE2086_MAX_LUMINANCE_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_SMPTE2086_MIN_LUMINANCE_EXT
 */
const EGL_SMPTE2086_MIN_LUMINANCE_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_CTA861_3_MAX_CONTENT_LIGHT_LEVEL_EXT
 */
const EGL_CTA861_3_MAX_CONTENT_LIGHT_LEVEL_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_CTA861_3_MAX_FRAME_AVERAGE_LEVEL_EXT
 */
const EGL_CTA861_3_MAX_FRAME_AVERAGE_LEVEL_EXT = UNKNOWN;

/**
 * @var int
 * @cvalue EGL_METADATA_SCALING_EXT
 */
const EGL_METADATA_SCALING_EXT = UNKNOWN;

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

/**
 * $native_window is the platform's window: an X11 Window id, or a
 * wl_egl_window address from wl_egl_window_create(). $attrib_list, when
 * given, is a list of ints ending with EGL_NONE. Null when EGL makes none.
 */
function eglCreateWindowSurface(EGLDisplay $display, EGLConfig $config, int $native_window, ?array $attrib_list): ?EGLSurface {}

/** $value receives the config's attribute. */
function eglGetConfigAttrib(EGLDisplay $display, EGLConfig $config, int $attribute, ?int &$value): bool {}

function eglSurfaceAttrib(EGLDisplay $display, EGLSurface $surface, int $attribute, int $value): bool {}

/** libwayland-egl: a wl_egl_window over the wl_surface at $surface; 0 when none is made. */
function wl_egl_window_create(int $surface, int $width, int $height): int {}

function wl_egl_window_resize(int $window, int $width, int $height, int $dx, int $dy): void {}

function wl_egl_window_destroy(int $window): void {}

function eglDestroySurface(EGLDisplay $display, EGLSurface $surface): bool {}

function eglMakeCurrent(EGLDisplay $display, ?EGLSurface $draw, ?EGLSurface $read, ?EGLContext $ctx): bool {}

function eglGetCurrentContext(): ?EGLContext {}

function eglGetCurrentDisplay(): ?EGLDisplay {}

/** $readdraw is EGL_DRAW or EGL_READ. */
function eglGetCurrentSurface(int $readdraw): ?EGLSurface {}

/** The current context's swap interval on $display: 0 off, 1 each refresh, and the driver's own minimum and maximum around them. */
function eglSwapInterval(EGLDisplay $display, int $interval): bool {}

/** $value receives the attribute's value. */
function eglQuerySurface(EGLDisplay $display, EGLSurface $surface, int $attribute, ?int &$value): bool {}

/**
 * EGL_KHR_swap_buffers_with_damage, through eglGetProcAddress: $rects is a flat list, four ints a rect
 * (x, y, width, height, origin bottom-left); an empty list damages the whole surface. False, with
 * nothing swapped, when $display does not list the extension.
 *
 * @throws ValueError When $rects is not a multiple of four ints.
 */
function eglSwapBuffersWithDamageKHR(EGLDisplay $display, EGLSurface $surface, array $rects): bool {}

function eglSwapBuffers(EGLDisplay $display, EGLSurface $surface): bool {}

function eglGetError(): int {}

function eglQueryString(?EGLDisplay $display, int $name): ?string {}
