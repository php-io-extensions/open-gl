#include "runtime.h"
#include "../stubs/EGL_arginfo.h"
#include <wayland-egl.h>

zend_class_entry *opengl_ce_EGLDisplay;
zend_class_entry *opengl_ce_EGLConfig;
zend_class_entry *opengl_ce_EGLContext;
zend_class_entry *opengl_ce_EGLSurface;

OPENGL_POINTER_METHODS(EGLDisplay)
OPENGL_POINTER_METHODS(EGLConfig)
OPENGL_POINTER_METHODS(EGLContext)
OPENGL_POINTER_METHODS(EGLSurface)

static void *egl_required(zval *zv, zend_class_entry *ce, uint32_t arg_num)
{
	return opengl_handle_ptr(zv, ce, arg_num);
}

static void *egl_optional(zend_object *obj, zend_class_entry *ce, uint32_t arg_num)
{
	zval tmp;

	if (obj == NULL) {
		return NULL;
	}

	ZVAL_OBJ(&tmp, obj);
	return opengl_handle_ptr(&tmp, ce, arg_num);
}

/* eglGetPlatformDisplay reads EGLAttrib (pointer-wide). Every other EGL list is EGLint. */
static EGLAttrib *egl_platform_attribs(HashTable *list, uint32_t arg_num, bool *failed)
{
	int *raw;
	uint32_t n = 0, i;
	EGLAttrib *wide;

	raw = opengl_attrib_list(list, EGL_NONE, arg_num, failed);
	if (*failed || raw == NULL) {
		return NULL;
	}

	while (raw[n] != EGL_NONE) {
		n++;
	}
	n++;

	wide = emalloc(sizeof(EGLAttrib) * n);
	for (i = 0; i < n; i++) {
		wide[i] = (EGLAttrib) raw[i];
	}
	efree(raw);

	return wide;
}

static void *egl_native_display(zend_long id, bool is_null)
{
	if (is_null || id == 0) {
		return EGL_DEFAULT_DISPLAY;
	}

	return (void *) (uintptr_t) id;
}

ZEND_FUNCTION(eglGetDisplay)
{
	zend_long display_id = 0;
	bool is_null = true;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG_OR_NULL(display_id, is_null)
	ZEND_PARSE_PARAMETERS_END();

	opengl_box(return_value, eglGetDisplay(egl_native_display(display_id, is_null)), opengl_ce_EGLDisplay);
}

ZEND_FUNCTION(eglGetPlatformDisplay)
{
	zend_long platform, native = 0;
	bool native_null = true;
	HashTable *attrib_list = NULL;
	bool failed = false;
	EGLAttrib *attribs;
	EGLDisplay display;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(platform)
		Z_PARAM_LONG_OR_NULL(native, native_null)
		Z_PARAM_ARRAY_HT_OR_NULL(attrib_list)
	ZEND_PARSE_PARAMETERS_END();

	attribs = egl_platform_attribs(attrib_list, 3, &failed);
	if (failed) {
		RETURN_THROWS();
	}

	display = eglGetPlatformDisplay((EGLenum) platform, egl_native_display(native, native_null), attribs);
	if (attribs != NULL) {
		efree(attribs);
	}
	opengl_box(return_value, display, opengl_ce_EGLDisplay);
}

ZEND_FUNCTION(eglInitialize)
{
	zval *display_zv, *major_zv, *minor_zv;
	EGLDisplay display;
	EGLint major = 0, minor = 0;
	EGLBoolean ok;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_ZVAL(major_zv)
		Z_PARAM_ZVAL(minor_zv)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	if (display == NULL) {
		RETURN_THROWS();
	}

	ok = eglInitialize(display, &major, &minor);
	ZEND_TRY_ASSIGN_REF_LONG(major_zv, (zend_long) major);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	ZEND_TRY_ASSIGN_REF_LONG(minor_zv, (zend_long) minor);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(ok == EGL_TRUE);
}

ZEND_FUNCTION(eglTerminate)
{
	zval *display_zv;
	EGLDisplay display;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	if (display == NULL) {
		RETURN_THROWS();
	}

	RETURN_BOOL(eglTerminate(display) == EGL_TRUE);
}

ZEND_FUNCTION(eglBindAPI)
{
	zend_long api;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(api)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(eglBindAPI((EGLenum) api) == EGL_TRUE);
}

ZEND_FUNCTION(eglChooseConfig)
{
	zval *display_zv, *configs_zv, *num_zv, chosen;
	HashTable *attrib_list = NULL;
	zend_long config_size;
	EGLDisplay display;
	int *attribs;
	bool failed = false;
	EGLConfig *configs = NULL;
	EGLint num = 0;
	EGLBoolean ok = EGL_FALSE;
	EGLint i;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_ARRAY_HT_OR_NULL(attrib_list)
		Z_PARAM_ZVAL(configs_zv)
		Z_PARAM_LONG(config_size)
		Z_PARAM_ZVAL(num_zv)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	if (display == NULL) {
		RETURN_THROWS();
	}
	if (config_size < 0 || config_size > INT_MAX) {
		zend_argument_value_error(4, "must be greater than or equal to 0");
		RETURN_THROWS();
	}

	attribs = opengl_attrib_list(attrib_list, EGL_NONE, 2, &failed);
	if (failed) {
		RETURN_THROWS();
	}

	if (config_size > 0) {
		configs = ecalloc((size_t) config_size, sizeof(EGLConfig));
	}
	ok = eglChooseConfig(display, attribs, configs, (EGLint) config_size, &num);
	if (attribs != NULL) {
		efree(attribs);
	}

	array_init(&chosen);
	if (ok == EGL_TRUE && configs != NULL) {
		EGLint limit = num > (EGLint) config_size ? (EGLint) config_size : num;
		for (i = 0; i < limit; i++) {
			zval cfg;
			opengl_box(&cfg, configs[i], opengl_ce_EGLConfig);
			add_next_index_zval(&chosen, &cfg);
		}
	}
	if (configs != NULL) {
		efree(configs);
	}

	ZEND_TRY_ASSIGN_REF_TMP(configs_zv, &chosen);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	ZEND_TRY_ASSIGN_REF_LONG(num_zv, (zend_long) num);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(ok == EGL_TRUE);
}

ZEND_FUNCTION(eglCreateContext)
{
	zval *display_zv;
	zend_object *config = NULL, *share = NULL;
	HashTable *attrib_list = NULL;
	EGLDisplay display;
	EGLConfig config_ptr = NULL;
	EGLContext share_ptr = NULL, created;
	int *attribs;
	bool failed = false;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(config, opengl_ce_EGLConfig)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(share, opengl_ce_EGLContext)
		Z_PARAM_ARRAY_HT_OR_NULL(attrib_list)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	if (display == NULL) {
		RETURN_THROWS();
	}
	if (config != NULL) {
		config_ptr = egl_optional(config, opengl_ce_EGLConfig, 2);
		if (config_ptr == NULL) {
			RETURN_THROWS();
		}
	}
	if (share != NULL) {
		share_ptr = egl_optional(share, opengl_ce_EGLContext, 3);
		if (share_ptr == NULL) {
			RETURN_THROWS();
		}
	}

	attribs = opengl_attrib_list(attrib_list, EGL_NONE, 4, &failed);
	if (failed) {
		RETURN_THROWS();
	}

	created = eglCreateContext(display, config_ptr, share_ptr, attribs);
	if (attribs != NULL) {
		efree(attribs);
	}
	opengl_box(return_value, created, opengl_ce_EGLContext);
}

ZEND_FUNCTION(eglDestroyContext)
{
	zval *display_zv, *context_zv;
	EGLDisplay display;
	EGLContext context;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJECT_OF_CLASS(context_zv, opengl_ce_EGLContext)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	context = display != NULL ? egl_required(context_zv, opengl_ce_EGLContext, 2) : NULL;
	if (display == NULL || context == NULL) {
		RETURN_THROWS();
	}

	if (eglGetCurrentContext() == context) {
		eglMakeCurrent(display, EGL_NO_SURFACE, EGL_NO_SURFACE, EGL_NO_CONTEXT);
	}

	RETVAL_BOOL(eglDestroyContext(display, context) == EGL_TRUE);
	opengl_release(Z_OBJ_P(context_zv));
}

ZEND_FUNCTION(eglCreatePbufferSurface)
{
	zval *display_zv, *config_zv;
	HashTable *attrib_list = NULL;
	EGLDisplay display;
	EGLConfig config;
	EGLSurface surface;
	int *attribs;
	bool failed = false;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJECT_OF_CLASS(config_zv, opengl_ce_EGLConfig)
		Z_PARAM_ARRAY_HT_OR_NULL(attrib_list)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	config = display != NULL ? egl_required(config_zv, opengl_ce_EGLConfig, 2) : NULL;
	if (display == NULL || config == NULL) {
		RETURN_THROWS();
	}

	attribs = opengl_attrib_list(attrib_list, EGL_NONE, 3, &failed);
	if (failed) {
		RETURN_THROWS();
	}

	surface = eglCreatePbufferSurface(display, config, attribs);
	if (attribs != NULL) {
		efree(attribs);
	}
	opengl_box(return_value, surface, opengl_ce_EGLSurface);
}

ZEND_FUNCTION(eglCreateWindowSurface)
{
	zval *display_zv, *config_zv;
	zend_long native;
	HashTable *attrib_list = NULL;
	EGLDisplay display;
	EGLConfig config;
	EGLSurface surface;
	int *attribs;
	bool failed = false;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJECT_OF_CLASS(config_zv, opengl_ce_EGLConfig)
		Z_PARAM_LONG(native)
		Z_PARAM_ARRAY_HT_OR_NULL(attrib_list)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	config = display != NULL ? egl_required(config_zv, opengl_ce_EGLConfig, 2) : NULL;
	if (display == NULL || config == NULL) {
		RETURN_THROWS();
	}

	attribs = opengl_attrib_list(attrib_list, EGL_NONE, 4, &failed);
	if (failed) {
		RETURN_THROWS();
	}

	/* EGLNativeWindowType is an X11 Window or a wl_egl_window pointer here: both fit an integer. */
	surface = eglCreateWindowSurface(display, config, (EGLNativeWindowType) (uintptr_t) native, attribs);
	if (attribs != NULL) {
		efree(attribs);
	}
	if (surface == EGL_NO_SURFACE) {
		RETURN_NULL();
	}
	opengl_box(return_value, surface, opengl_ce_EGLSurface);
}

ZEND_FUNCTION(eglGetConfigAttrib)
{
	zval *display_zv, *config_zv, *value_zv;
	zend_long attribute;
	EGLDisplay display;
	EGLConfig config;
	EGLint value = 0;
	EGLBoolean ok;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJECT_OF_CLASS(config_zv, opengl_ce_EGLConfig)
		Z_PARAM_LONG(attribute)
		Z_PARAM_ZVAL(value_zv)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	config = display != NULL ? egl_required(config_zv, opengl_ce_EGLConfig, 2) : NULL;
	if (display == NULL || config == NULL) {
		RETURN_THROWS();
	}

	ok = eglGetConfigAttrib(display, config, (EGLint) attribute, &value);
	ZEND_TRY_ASSIGN_REF_LONG(value_zv, value);
	RETURN_BOOL(ok == EGL_TRUE);
}

ZEND_FUNCTION(eglSurfaceAttrib)
{
	zval *display_zv, *surface_zv;
	zend_long attribute, value;
	EGLDisplay display;
	EGLSurface surface;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJECT_OF_CLASS(surface_zv, opengl_ce_EGLSurface)
		Z_PARAM_LONG(attribute)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	surface = display != NULL ? egl_required(surface_zv, opengl_ce_EGLSurface, 2) : NULL;
	if (display == NULL || surface == NULL) {
		RETURN_THROWS();
	}

	RETURN_BOOL(eglSurfaceAttrib(display, surface, (EGLint) attribute, (EGLint) value) == EGL_TRUE);
}

ZEND_FUNCTION(wl_egl_window_create)
{
	zend_long surface, width, height;
	struct wl_egl_window *window;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	if (width < 1 || height < 1 || width > INT32_MAX || height > INT32_MAX) {
		zend_argument_value_error(width < 1 || width > INT32_MAX ? 2 : 3, "must be between 1 and %d", INT32_MAX);
		RETURN_THROWS();
	}
	if (surface == 0) {
		RETURN_LONG(0);
	}
	window = wl_egl_window_create((struct wl_surface *) (uintptr_t) surface, (int) width, (int) height);
	RETURN_LONG((zend_long) (uintptr_t) window);
}

ZEND_FUNCTION(wl_egl_window_resize)
{
	zend_long window, width, height, dx, dy;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(window)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(dx)
		Z_PARAM_LONG(dy)
	ZEND_PARSE_PARAMETERS_END();

	if (window == 0) {
		zend_argument_value_error(1, "must be a wl_egl_window address, got 0");
		RETURN_THROWS();
	}
	wl_egl_window_resize((struct wl_egl_window *) (uintptr_t) window, (int) width, (int) height, (int) dx, (int) dy);
}

ZEND_FUNCTION(wl_egl_window_destroy)
{
	zend_long window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();

	if (window == 0) {
		zend_argument_value_error(1, "must be a wl_egl_window address, got 0");
		RETURN_THROWS();
	}
	wl_egl_window_destroy((struct wl_egl_window *) (uintptr_t) window);
}

ZEND_FUNCTION(eglDestroySurface)
{
	zval *display_zv, *surface_zv;
	EGLDisplay display;
	EGLSurface surface;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJECT_OF_CLASS(surface_zv, opengl_ce_EGLSurface)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	surface = display != NULL ? egl_required(surface_zv, opengl_ce_EGLSurface, 2) : NULL;
	if (display == NULL || surface == NULL) {
		RETURN_THROWS();
	}

	RETVAL_BOOL(eglDestroySurface(display, surface) == EGL_TRUE);
	opengl_release(Z_OBJ_P(surface_zv));
}

ZEND_FUNCTION(eglMakeCurrent)
{
	zval *display_zv;
	zend_object *draw = NULL, *read = NULL, *ctx = NULL;
	EGLDisplay display;
	EGLSurface draw_s = EGL_NO_SURFACE, read_s = EGL_NO_SURFACE;
	EGLContext context = EGL_NO_CONTEXT;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(draw, opengl_ce_EGLSurface)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(read, opengl_ce_EGLSurface)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(ctx, opengl_ce_EGLContext)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	if (display == NULL) {
		RETURN_THROWS();
	}
	if (draw != NULL) {
		draw_s = egl_optional(draw, opengl_ce_EGLSurface, 2);
		if (draw_s == NULL) {
			RETURN_THROWS();
		}
	}
	if (read != NULL) {
		read_s = egl_optional(read, opengl_ce_EGLSurface, 3);
		if (read_s == NULL) {
			RETURN_THROWS();
		}
	}
	if (ctx != NULL) {
		context = egl_optional(ctx, opengl_ce_EGLContext, 4);
		if (context == NULL) {
			RETURN_THROWS();
		}
	}

	RETURN_BOOL(eglMakeCurrent(display, draw_s, read_s, context) == EGL_TRUE);
}

ZEND_FUNCTION(eglGetCurrentContext)
{
	ZEND_PARSE_PARAMETERS_NONE();
	opengl_box(return_value, eglGetCurrentContext(), opengl_ce_EGLContext);
}

ZEND_FUNCTION(eglGetCurrentDisplay)
{
	ZEND_PARSE_PARAMETERS_NONE();
	opengl_box(return_value, eglGetCurrentDisplay(), opengl_ce_EGLDisplay);
}

ZEND_FUNCTION(eglGetCurrentSurface)
{
	zend_long readdraw;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(readdraw)
	ZEND_PARSE_PARAMETERS_END();

	opengl_box(return_value, eglGetCurrentSurface((EGLint) readdraw), opengl_ce_EGLSurface);
}

ZEND_FUNCTION(eglSwapInterval)
{
	zval *display_zv;
	zend_long interval;
	EGLDisplay display;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_LONG(interval)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	if (display == NULL) {
		RETURN_THROWS();
	}

	RETURN_BOOL(eglSwapInterval(display, (EGLint) interval) == EGL_TRUE);
}

ZEND_FUNCTION(eglQuerySurface)
{
	zval *display_zv, *surface_zv, *value_zv;
	zend_long attribute;
	EGLDisplay display;
	EGLSurface surface;
	EGLint value = 0;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJECT_OF_CLASS(surface_zv, opengl_ce_EGLSurface)
		Z_PARAM_LONG(attribute)
		Z_PARAM_ZVAL(value_zv)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	surface = display != NULL ? egl_required(surface_zv, opengl_ce_EGLSurface, 2) : NULL;
	if (display == NULL || surface == NULL) {
		RETURN_THROWS();
	}

	if (eglQuerySurface(display, surface, (EGLint) attribute, &value) != EGL_TRUE) {
		RETURN_FALSE;
	}
	ZEND_TRY_ASSIGN_REF_LONG(value_zv, value);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_TRUE;
}

ZEND_FUNCTION(eglSwapBuffersWithDamageKHR)
{
	zval *display_zv, *surface_zv, *item;
	HashTable *rects;
	EGLDisplay display;
	EGLSurface surface;
	const char *extensions;
	PFNEGLSWAPBUFFERSWITHDAMAGEKHRPROC swap;
	EGLint *flat = NULL;
	uint32_t n, i = 0;
	EGLBoolean swapped;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJECT_OF_CLASS(surface_zv, opengl_ce_EGLSurface)
		Z_PARAM_ARRAY_HT(rects)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	surface = display != NULL ? egl_required(surface_zv, opengl_ce_EGLSurface, 2) : NULL;
	if (display == NULL || surface == NULL) {
		RETURN_THROWS();
	}
	n = zend_hash_num_elements(rects);
	if (n % 4 != 0) {
		zend_argument_value_error(3, "must hold four ints a rect, got %u ints", n);
		RETURN_THROWS();
	}

	/* A procedure address alone does not say the display supports it: its extension string does. */
	extensions = eglQueryString(display, EGL_EXTENSIONS);
	if (extensions == NULL || strstr(extensions, "EGL_KHR_swap_buffers_with_damage") == NULL) {
		RETURN_FALSE;
	}
	swap = (PFNEGLSWAPBUFFERSWITHDAMAGEKHRPROC) eglGetProcAddress("eglSwapBuffersWithDamageKHR");
	if (swap == NULL) {
		RETURN_FALSE;
	}

	if (n > 0) {
		flat = safe_emalloc(n, sizeof(EGLint), 0);
		ZEND_HASH_FOREACH_VAL(rects, item) {
			ZVAL_DEREF(item);
			if (Z_TYPE_P(item) != IS_LONG) {
				efree(flat);
				zend_argument_type_error(3, "must be a list of int, %s found", zend_zval_value_name(item));
				RETURN_THROWS();
			}
			flat[i++] = (EGLint) Z_LVAL_P(item);
		} ZEND_HASH_FOREACH_END();
	}
	swapped = swap(display, surface, flat, (EGLint) (n / 4));
	if (flat != NULL) {
		efree(flat);
	}
	RETURN_BOOL(swapped == EGL_TRUE);
}

ZEND_FUNCTION(eglSwapBuffers)
{
	zval *display_zv, *surface_zv;
	EGLDisplay display;
	EGLSurface surface;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(display_zv, opengl_ce_EGLDisplay)
		Z_PARAM_OBJECT_OF_CLASS(surface_zv, opengl_ce_EGLSurface)
	ZEND_PARSE_PARAMETERS_END();

	display = egl_required(display_zv, opengl_ce_EGLDisplay, 1);
	surface = display != NULL ? egl_required(surface_zv, opengl_ce_EGLSurface, 2) : NULL;
	if (display == NULL || surface == NULL) {
		RETURN_THROWS();
	}

	RETURN_BOOL(eglSwapBuffers(display, surface) == EGL_TRUE);
}

ZEND_FUNCTION(eglGetError)
{
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG((zend_long) eglGetError());
}

ZEND_FUNCTION(eglQueryString)
{
	zend_object *display = NULL;
	zend_long name;
	EGLDisplay native = EGL_NO_DISPLAY;
	const char *value;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(display, opengl_ce_EGLDisplay)
		Z_PARAM_LONG(name)
	ZEND_PARSE_PARAMETERS_END();

	if (display != NULL) {
		native = egl_optional(display, opengl_ce_EGLDisplay, 1);
		if (native == NULL) {
			RETURN_THROWS();
		}
	}

	value = eglQueryString(native, (EGLint) name);
	if (value == NULL) {
		RETURN_NULL();
	}
	RETURN_STRING(value);
}

void opengl_register_egl(int module_number)
{
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	register_EGL_symbols(module_number);

	opengl_ce_EGLDisplay = register_class_EGLDisplay();
	opengl_handle_setup(opengl_ce_EGLDisplay);
	opengl_ce_EGLConfig = register_class_EGLConfig();
	opengl_handle_setup(opengl_ce_EGLConfig);
	opengl_ce_EGLContext = register_class_EGLContext();
	opengl_handle_setup(opengl_ce_EGLContext);
	opengl_ce_EGLSurface = register_class_EGLSurface();
	opengl_handle_setup(opengl_ce_EGLSurface);
}
