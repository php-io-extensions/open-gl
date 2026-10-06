/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 22b8fc7a43ccd8b585dcc60200ac4d72ec9ec073 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_eglGetDisplay, 0, 1, EGLDisplay, 1)
	ZEND_ARG_TYPE_INFO(0, display_id, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_eglGetPlatformDisplay, 0, 3, EGLDisplay, 1)
	ZEND_ARG_TYPE_INFO(0, platform, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, native_display, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_eglInitialize, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, display, EGLDisplay, 0)
	ZEND_ARG_TYPE_INFO(1, major, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(1, minor, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_eglTerminate, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, display, EGLDisplay, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_eglBindAPI, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, api, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_eglChooseConfig, 0, 5, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, display, EGLDisplay, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(1, configs, IS_ARRAY, 1)
	ZEND_ARG_TYPE_INFO(0, config_size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(1, num_config, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_eglCreateContext, 0, 4, EGLContext, 1)
	ZEND_ARG_OBJ_INFO(0, display, EGLDisplay, 0)
	ZEND_ARG_OBJ_INFO(0, config, EGLConfig, 1)
	ZEND_ARG_OBJ_INFO(0, share_context, EGLContext, 1)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_eglDestroyContext, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, display, EGLDisplay, 0)
	ZEND_ARG_OBJ_INFO(0, context, EGLContext, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_eglCreatePbufferSurface, 0, 3, EGLSurface, 1)
	ZEND_ARG_OBJ_INFO(0, display, EGLDisplay, 0)
	ZEND_ARG_OBJ_INFO(0, config, EGLConfig, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_eglDestroySurface, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, display, EGLDisplay, 0)
	ZEND_ARG_OBJ_INFO(0, surface, EGLSurface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_eglMakeCurrent, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, display, EGLDisplay, 0)
	ZEND_ARG_OBJ_INFO(0, draw, EGLSurface, 1)
	ZEND_ARG_OBJ_INFO(0, read, EGLSurface, 1)
	ZEND_ARG_OBJ_INFO(0, ctx, EGLContext, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_eglGetCurrentContext, 0, 0, EGLContext, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_eglGetCurrentDisplay, 0, 0, EGLDisplay, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_eglGetCurrentSurface, 0, 1, EGLSurface, 1)
	ZEND_ARG_TYPE_INFO(0, readdraw, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_eglSwapBuffers arginfo_eglDestroySurface

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_eglGetError, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_eglQueryString, 0, 2, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, display, EGLDisplay, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_EGLDisplay___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_EGLDisplay_pointer arginfo_eglGetError

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_EGLDisplay_fromPointer, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pointer, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_EGLConfig___construct arginfo_class_EGLDisplay___construct

#define arginfo_class_EGLConfig_pointer arginfo_eglGetError

#define arginfo_class_EGLConfig_fromPointer arginfo_class_EGLDisplay_fromPointer

#define arginfo_class_EGLContext___construct arginfo_class_EGLDisplay___construct

#define arginfo_class_EGLContext_pointer arginfo_eglGetError

#define arginfo_class_EGLContext_fromPointer arginfo_class_EGLDisplay_fromPointer

#define arginfo_class_EGLSurface___construct arginfo_class_EGLDisplay___construct

#define arginfo_class_EGLSurface_pointer arginfo_eglGetError

#define arginfo_class_EGLSurface_fromPointer arginfo_class_EGLDisplay_fromPointer

ZEND_FUNCTION(eglGetDisplay);
ZEND_FUNCTION(eglGetPlatformDisplay);
ZEND_FUNCTION(eglInitialize);
ZEND_FUNCTION(eglTerminate);
ZEND_FUNCTION(eglBindAPI);
ZEND_FUNCTION(eglChooseConfig);
ZEND_FUNCTION(eglCreateContext);
ZEND_FUNCTION(eglDestroyContext);
ZEND_FUNCTION(eglCreatePbufferSurface);
ZEND_FUNCTION(eglDestroySurface);
ZEND_FUNCTION(eglMakeCurrent);
ZEND_FUNCTION(eglGetCurrentContext);
ZEND_FUNCTION(eglGetCurrentDisplay);
ZEND_FUNCTION(eglGetCurrentSurface);
ZEND_FUNCTION(eglSwapBuffers);
ZEND_FUNCTION(eglGetError);
ZEND_FUNCTION(eglQueryString);
ZEND_METHOD(EGLDisplay, __construct);
ZEND_METHOD(EGLDisplay, pointer);
ZEND_METHOD(EGLDisplay, fromPointer);
ZEND_METHOD(EGLConfig, __construct);
ZEND_METHOD(EGLConfig, pointer);
ZEND_METHOD(EGLConfig, fromPointer);
ZEND_METHOD(EGLContext, __construct);
ZEND_METHOD(EGLContext, pointer);
ZEND_METHOD(EGLContext, fromPointer);
ZEND_METHOD(EGLSurface, __construct);
ZEND_METHOD(EGLSurface, pointer);
ZEND_METHOD(EGLSurface, fromPointer);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(eglGetDisplay, arginfo_eglGetDisplay)
	ZEND_FE(eglGetPlatformDisplay, arginfo_eglGetPlatformDisplay)
	ZEND_FE(eglInitialize, arginfo_eglInitialize)
	ZEND_FE(eglTerminate, arginfo_eglTerminate)
	ZEND_FE(eglBindAPI, arginfo_eglBindAPI)
	ZEND_FE(eglChooseConfig, arginfo_eglChooseConfig)
	ZEND_FE(eglCreateContext, arginfo_eglCreateContext)
	ZEND_FE(eglDestroyContext, arginfo_eglDestroyContext)
	ZEND_FE(eglCreatePbufferSurface, arginfo_eglCreatePbufferSurface)
	ZEND_FE(eglDestroySurface, arginfo_eglDestroySurface)
	ZEND_FE(eglMakeCurrent, arginfo_eglMakeCurrent)
	ZEND_FE(eglGetCurrentContext, arginfo_eglGetCurrentContext)
	ZEND_FE(eglGetCurrentDisplay, arginfo_eglGetCurrentDisplay)
	ZEND_FE(eglGetCurrentSurface, arginfo_eglGetCurrentSurface)
	ZEND_FE(eglSwapBuffers, arginfo_eglSwapBuffers)
	ZEND_FE(eglGetError, arginfo_eglGetError)
	ZEND_FE(eglQueryString, arginfo_eglQueryString)
	ZEND_FE_END
};

static const zend_function_entry class_EGLDisplay_methods[] = {
	ZEND_ME(EGLDisplay, __construct, arginfo_class_EGLDisplay___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(EGLDisplay, pointer, arginfo_class_EGLDisplay_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(EGLDisplay, fromPointer, arginfo_class_EGLDisplay_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_EGLConfig_methods[] = {
	ZEND_ME(EGLConfig, __construct, arginfo_class_EGLConfig___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(EGLConfig, pointer, arginfo_class_EGLConfig_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(EGLConfig, fromPointer, arginfo_class_EGLConfig_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_EGLContext_methods[] = {
	ZEND_ME(EGLContext, __construct, arginfo_class_EGLContext___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(EGLContext, pointer, arginfo_class_EGLContext_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(EGLContext, fromPointer, arginfo_class_EGLContext_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_EGLSurface_methods[] = {
	ZEND_ME(EGLSurface, __construct, arginfo_class_EGLSurface___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(EGLSurface, pointer, arginfo_class_EGLSurface_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(EGLSurface, fromPointer, arginfo_class_EGLSurface_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static void register_EGL_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("EGL_DEFAULT_DISPLAY", 0, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_PLATFORM_SURFACELESS_MESA", EGL_PLATFORM_SURFACELESS_MESA, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_NONE", EGL_NONE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_SUCCESS", EGL_SUCCESS, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_OPENGL_ES_API", EGL_OPENGL_ES_API, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_RENDERABLE_TYPE", EGL_RENDERABLE_TYPE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_OPENGL_ES3_BIT", EGL_OPENGL_ES3_BIT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_SURFACE_TYPE", EGL_SURFACE_TYPE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_PBUFFER_BIT", EGL_PBUFFER_BIT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_RED_SIZE", EGL_RED_SIZE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_GREEN_SIZE", EGL_GREEN_SIZE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_BLUE_SIZE", EGL_BLUE_SIZE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_ALPHA_SIZE", EGL_ALPHA_SIZE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_DEPTH_SIZE", EGL_DEPTH_SIZE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_STENCIL_SIZE", EGL_STENCIL_SIZE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_WIDTH", EGL_WIDTH, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_HEIGHT", EGL_HEIGHT, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_DRAW", EGL_DRAW, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_READ", EGL_READ, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_CONTEXT_MAJOR_VERSION", EGL_CONTEXT_MAJOR_VERSION, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_CONTEXT_MINOR_VERSION", EGL_CONTEXT_MINOR_VERSION, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_VENDOR", EGL_VENDOR, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_VERSION", EGL_VERSION, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_EXTENSIONS", EGL_EXTENSIONS, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("EGL_CLIENT_APIS", EGL_CLIENT_APIS, CONST_PERSISTENT);
}

static zend_class_entry *register_class_EGLDisplay(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "EGLDisplay", class_EGLDisplay_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_EGLConfig(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "EGLConfig", class_EGLConfig_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_EGLContext(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "EGLContext", class_EGLContext_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_EGLSurface(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "EGLSurface", class_EGLSurface_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
