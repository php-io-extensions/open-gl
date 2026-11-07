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

/* eglGetPlatformDisplay reads EGLAttrib (pointer-wide): each value converted as C converts it. */
static bool egl_attrib_list(HashTable *list, uint32_t arg_num, EGLAttrib **out)
{
	uint32_t i = 0;
	zval *zv;

	*out = NULL;
	if (list == NULL || zend_hash_num_elements(list) == 0) {
		return true;
	}

	*out = safe_emalloc(zend_hash_num_elements(list), sizeof(EGLAttrib), 0);
	ZEND_HASH_FOREACH_VAL(list, zv) {
		ZVAL_DEREF(zv);
		if (Z_TYPE_P(zv) != IS_LONG) {
			efree(*out);
			*out = NULL;
			zend_argument_type_error(arg_num, "must be a list of ints, %s found", zend_zval_value_name(zv));
			return false;
		}
		(*out)[i++] = (EGLAttrib) Z_LVAL_P(zv);
	} ZEND_HASH_FOREACH_END();

	return true;
}

ZEND_FUNCTION(eglGetDisplay)
{
	zend_long display_id = 0;
	bool is_null = true;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG_OR_NULL(display_id, is_null)
	ZEND_PARSE_PARAMETERS_END();

	opengl_box(return_value, eglGetDisplay((EGLNativeDisplayType) (uintptr_t) display_id), opengl_ce_EGLDisplay);
}

ZEND_FUNCTION(eglGetPlatformDisplay)
{
	zend_long platform, native = 0;
	bool native_null = true;
	HashTable *attrib_list = NULL;
	EGLAttrib *attribs;
	EGLDisplay display;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(platform)
		Z_PARAM_LONG_OR_NULL(native, native_null)
		Z_PARAM_ARRAY_HT_OR_NULL(attrib_list)
	ZEND_PARSE_PARAMETERS_END();

	if (!egl_attrib_list(attrib_list, 3, &attribs)) {
		RETURN_THROWS();
	}

	display = eglGetPlatformDisplay((EGLenum) platform, (void *) (uintptr_t) native, attribs);
	if (attribs != NULL) {
		efree(attribs);
	}
	opengl_box(return_value, display, opengl_ce_EGLDisplay);
}

ZEND_FUNCTION(eglInitialize)
{
	zend_object *display;
	zval *major_zv, *minor_zv;
	EGLint major = 0, minor = 0;
	EGLBoolean ok;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_ZVAL(major_zv)
		Z_PARAM_ZVAL(minor_zv)
	ZEND_PARSE_PARAMETERS_END();

	ok = eglInitialize(opengl_ptr(display), &major, &minor);
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
	zend_object *display;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(eglTerminate(opengl_ptr(display)) == EGL_TRUE);
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
	zend_object *display;
	zval *configs_zv, *num_zv, chosen;
	HashTable *attrib_list = NULL;
	zend_long config_size;
	int *attribs;
	EGLConfig *configs = NULL;
	EGLint size, num = 0, i;
	EGLBoolean ok;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_ARRAY_HT_OR_NULL(attrib_list)
		Z_PARAM_ZVAL(configs_zv)
		Z_PARAM_LONG(config_size)
		Z_PARAM_ZVAL(num_zv)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_int_list(attrib_list, 2, &attribs)) {
		RETURN_THROWS();
	}

	/* The configs array holds config_size entries; with none, EGL answers only the count. */
	size = (EGLint) config_size;
	if (size > 0) {
		configs = safe_emalloc((size_t) size, sizeof(EGLConfig), 0);
	}
	ok = eglChooseConfig(opengl_ptr(display), (const EGLint *) attribs, configs, size, &num);
	if (attribs != NULL) {
		efree(attribs);
	}

	array_init(&chosen);
	if (ok == EGL_TRUE && configs != NULL) {
		for (i = 0; i < num && i < size; i++) {
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
	zend_object *display, *config = NULL, *share = NULL;
	HashTable *attrib_list = NULL;
	EGLContext created;
	int *attribs;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(config, opengl_ce_EGLConfig)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(share, opengl_ce_EGLContext)
		Z_PARAM_ARRAY_HT_OR_NULL(attrib_list)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_int_list(attrib_list, 4, &attribs)) {
		RETURN_THROWS();
	}

	created = eglCreateContext(opengl_ptr(display), opengl_ptr(config), opengl_ptr(share), (const EGLint *) attribs);
	if (attribs != NULL) {
		efree(attribs);
	}
	opengl_box(return_value, created, opengl_ce_EGLContext);
}

ZEND_FUNCTION(eglDestroyContext)
{
	zend_object *display, *context;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS(context, opengl_ce_EGLContext)
	ZEND_PARSE_PARAMETERS_END();

	RETVAL_BOOL(eglDestroyContext(opengl_ptr(display), opengl_ptr(context)) == EGL_TRUE);
	opengl_release(context);
}

ZEND_FUNCTION(eglCreatePbufferSurface)
{
	zend_object *display, *config;
	HashTable *attrib_list = NULL;
	EGLSurface surface;
	int *attribs;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS(config, opengl_ce_EGLConfig)
		Z_PARAM_ARRAY_HT_OR_NULL(attrib_list)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_int_list(attrib_list, 3, &attribs)) {
		RETURN_THROWS();
	}

	surface = eglCreatePbufferSurface(opengl_ptr(display), opengl_ptr(config), (const EGLint *) attribs);
	if (attribs != NULL) {
		efree(attribs);
	}
	opengl_box(return_value, surface, opengl_ce_EGLSurface);
}

ZEND_FUNCTION(eglCreateWindowSurface)
{
	zend_object *display, *config;
	zend_long native;
	HashTable *attrib_list = NULL;
	EGLSurface surface;
	int *attribs;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS(config, opengl_ce_EGLConfig)
		Z_PARAM_LONG(native)
		Z_PARAM_ARRAY_HT_OR_NULL(attrib_list)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_int_list(attrib_list, 4, &attribs)) {
		RETURN_THROWS();
	}

	/* EGLNativeWindowType is an X11 Window or a wl_egl_window pointer here: both fit an integer. */
	surface = eglCreateWindowSurface(opengl_ptr(display), opengl_ptr(config), (EGLNativeWindowType) (uintptr_t) native, (const EGLint *) attribs);
	if (attribs != NULL) {
		efree(attribs);
	}
	opengl_box(return_value, surface, opengl_ce_EGLSurface);
}

ZEND_FUNCTION(eglGetConfigAttrib)
{
	zend_object *display, *config;
	zval *value_zv;
	zend_long attribute;
	EGLint value = 0;
	EGLBoolean ok;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS(config, opengl_ce_EGLConfig)
		Z_PARAM_LONG(attribute)
		Z_PARAM_ZVAL(value_zv)
	ZEND_PARSE_PARAMETERS_END();

	ok = eglGetConfigAttrib(opengl_ptr(display), opengl_ptr(config), (EGLint) attribute, &value);
	ZEND_TRY_ASSIGN_REF_LONG(value_zv, value);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(ok == EGL_TRUE);
}

ZEND_FUNCTION(eglSurfaceAttrib)
{
	zend_object *display, *surface;
	zend_long attribute, value;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS(surface, opengl_ce_EGLSurface)
		Z_PARAM_LONG(attribute)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(eglSurfaceAttrib(opengl_ptr(display), opengl_ptr(surface), (EGLint) attribute, (EGLint) value) == EGL_TRUE);
}

ZEND_FUNCTION(wl_egl_window_create)
{
	zend_long surface, width, height;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) (uintptr_t) wl_egl_window_create((struct wl_surface *) (uintptr_t) surface, (int) width, (int) height));
}

/* wayland-egl dereferences the window it is given, NULL included. */
static bool egl_wl_window(zend_long window)
{
	if (!OPENGL_PROBE_OFF("opengl-wl-null-window") && window == 0) {
		zend_argument_value_error(1, "must not be address 0, which wayland-egl dereferences"); /* binding:opengl-wl-null-window */
		return false;
	}

	return true;
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

	if (!egl_wl_window(window)) {
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

	if (!egl_wl_window(window)) {
		RETURN_THROWS();
	}
	wl_egl_window_destroy((struct wl_egl_window *) (uintptr_t) window);
}

ZEND_FUNCTION(eglDestroySurface)
{
	zend_object *display, *surface;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS(surface, opengl_ce_EGLSurface)
	ZEND_PARSE_PARAMETERS_END();

	RETVAL_BOOL(eglDestroySurface(opengl_ptr(display), opengl_ptr(surface)) == EGL_TRUE);
	opengl_release(surface);
}

ZEND_FUNCTION(eglMakeCurrent)
{
	zend_object *display, *draw = NULL, *read = NULL, *ctx = NULL;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(draw, opengl_ce_EGLSurface)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(read, opengl_ce_EGLSurface)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(ctx, opengl_ce_EGLContext)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(eglMakeCurrent(opengl_ptr(display), opengl_ptr(draw), opengl_ptr(read), opengl_ptr(ctx)) == EGL_TRUE);
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
	zend_object *display;
	zend_long interval;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_LONG(interval)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(eglSwapInterval(opengl_ptr(display), (EGLint) interval) == EGL_TRUE);
}

ZEND_FUNCTION(eglQuerySurface)
{
	zend_object *display, *surface;
	zval *value_zv;
	zend_long attribute;
	EGLint value = 0;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS(surface, opengl_ce_EGLSurface)
		Z_PARAM_LONG(attribute)
		Z_PARAM_ZVAL(value_zv)
	ZEND_PARSE_PARAMETERS_END();

	if (eglQuerySurface(opengl_ptr(display), opengl_ptr(surface), (EGLint) attribute, &value) != EGL_TRUE) {
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
	zend_object *display, *surface;
	HashTable *rects;
	zend_long n_rects;
	PFNEGLSWAPBUFFERSWITHDAMAGEKHRPROC swap;
	int *flat;
	EGLBoolean swapped;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS(surface, opengl_ce_EGLSurface)
		Z_PARAM_ARRAY_HT(rects)
		Z_PARAM_LONG(n_rects)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_int_list(rects, 3, &flat)) {
		RETURN_THROWS();
	}

	/* An extension entry point: libglvnd answers every egl* name with a dispatch stub. */
	swap = (PFNEGLSWAPBUFFERSWITHDAMAGEKHRPROC) eglGetProcAddress("eglSwapBuffersWithDamageKHR");
	swapped = swap(opengl_ptr(display), opengl_ptr(surface), (const EGLint *) flat, (EGLint) n_rects);
	if (flat != NULL) {
		efree(flat);
	}
	RETURN_BOOL(swapped == EGL_TRUE);
}

ZEND_FUNCTION(eglSwapBuffers)
{
	zend_object *display, *surface;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(display, opengl_ce_EGLDisplay)
		Z_PARAM_OBJ_OF_CLASS(surface, opengl_ce_EGLSurface)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(eglSwapBuffers(opengl_ptr(display), opengl_ptr(surface)) == EGL_TRUE);
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
	const char *value;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(display, opengl_ce_EGLDisplay)
		Z_PARAM_LONG(name)
	ZEND_PARSE_PARAMETERS_END();

	value = eglQueryString(opengl_ptr(display), (EGLint) name);
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
