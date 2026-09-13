
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "src/egl.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_EGL_EGL)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\EGL, EGL, opengl, egl_egl, opengl_egl_egl_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_EGL_EGL, eglChooseConfig)
{
	zval *dpy_param = NULL, *attrib_list_param = NULL, *configs_param = NULL, *config_size_param = NULL, *num_config_param = NULL, _0, _1, _2, _3, _4;
	zend_long dpy, attrib_list, configs, config_size, num_config, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(attrib_list)
		Z_PARAM_LONG(configs)
		Z_PARAM_LONG(config_size)
		Z_PARAM_LONG(num_config)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &dpy_param, &attrib_list_param, &configs_param, &config_size_param, &num_config_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, attrib_list);
	ZVAL_LONG(&_2, configs);
	ZVAL_LONG(&_3, config_size);
	ZVAL_LONG(&_4, num_config);
	r = phpgl_egl_eglchooseconfig(&_0, &_1, &_2, &_3, &_4);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglCopyBuffers)
{
	zval *dpy_param = NULL, *surface_param = NULL, *target_param = NULL, _0, _1, _2;
	zend_long dpy, surface, target, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(target)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &dpy_param, &surface_param, &target_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, target);
	r = phpgl_egl_eglcopybuffers(&_0, &_1, &_2);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglCreateContext)
{
	zval *dpy_param = NULL, *config_param = NULL, *share_context_param = NULL, *attrib_list_param = NULL, _0, _1, _2, _3;
	zend_long dpy, config, share_context, attrib_list;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(config)
		Z_PARAM_LONG(share_context)
		Z_PARAM_LONG(attrib_list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &config_param, &share_context_param, &attrib_list_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, config);
	ZVAL_LONG(&_2, share_context);
	ZVAL_LONG(&_3, attrib_list);
	RETURN_LONG(phpgl_egl_eglcreatecontext(&_0, &_1, &_2, &_3));
}

PHP_METHOD(OpenGL_EGL_EGL, eglCreatePbufferSurface)
{
	zval *dpy_param = NULL, *config_param = NULL, *attrib_list_param = NULL, _0, _1, _2;
	zend_long dpy, config, attrib_list;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(config)
		Z_PARAM_LONG(attrib_list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &dpy_param, &config_param, &attrib_list_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, config);
	ZVAL_LONG(&_2, attrib_list);
	RETURN_LONG(phpgl_egl_eglcreatepbuffersurface(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_EGL_EGL, eglCreatePixmapSurface)
{
	zval *dpy_param = NULL, *config_param = NULL, *pixmap_param = NULL, *attrib_list_param = NULL, _0, _1, _2, _3;
	zend_long dpy, config, pixmap, attrib_list;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(config)
		Z_PARAM_LONG(pixmap)
		Z_PARAM_LONG(attrib_list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &config_param, &pixmap_param, &attrib_list_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, config);
	ZVAL_LONG(&_2, pixmap);
	ZVAL_LONG(&_3, attrib_list);
	RETURN_LONG(phpgl_egl_eglcreatepixmapsurface(&_0, &_1, &_2, &_3));
}

PHP_METHOD(OpenGL_EGL_EGL, eglCreateWindowSurface)
{
	zval *dpy_param = NULL, *config_param = NULL, *win_param = NULL, *attrib_list_param = NULL, _0, _1, _2, _3;
	zend_long dpy, config, win, attrib_list;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(config)
		Z_PARAM_LONG(win)
		Z_PARAM_LONG(attrib_list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &config_param, &win_param, &attrib_list_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, config);
	ZVAL_LONG(&_2, win);
	ZVAL_LONG(&_3, attrib_list);
	RETURN_LONG(phpgl_egl_eglcreatewindowsurface(&_0, &_1, &_2, &_3));
}

PHP_METHOD(OpenGL_EGL_EGL, eglDestroyContext)
{
	zval *dpy_param = NULL, *ctx_param = NULL, _0, _1;
	zend_long dpy, ctx, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &dpy_param, &ctx_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, ctx);
	r = phpgl_egl_egldestroycontext(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglDestroySurface)
{
	zval *dpy_param = NULL, *surface_param = NULL, _0, _1;
	zend_long dpy, surface, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &dpy_param, &surface_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, surface);
	r = phpgl_egl_egldestroysurface(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglGetConfigAttrib)
{
	zval *dpy_param = NULL, *config_param = NULL, *attribute_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long dpy, config, attribute, value, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(config)
		Z_PARAM_LONG(attribute)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &config_param, &attribute_param, &value_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, config);
	ZVAL_LONG(&_2, attribute);
	ZVAL_LONG(&_3, value);
	r = phpgl_egl_eglgetconfigattrib(&_0, &_1, &_2, &_3);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglGetConfigs)
{
	zval *dpy_param = NULL, *configs_param = NULL, *config_size_param = NULL, *num_config_param = NULL, _0, _1, _2, _3;
	zend_long dpy, configs, config_size, num_config, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(configs)
		Z_PARAM_LONG(config_size)
		Z_PARAM_LONG(num_config)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &configs_param, &config_size_param, &num_config_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, configs);
	ZVAL_LONG(&_2, config_size);
	ZVAL_LONG(&_3, num_config);
	r = phpgl_egl_eglgetconfigs(&_0, &_1, &_2, &_3);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglGetCurrentDisplay)
{

	RETURN_LONG(phpgl_egl_eglgetcurrentdisplay());
}

PHP_METHOD(OpenGL_EGL_EGL, eglGetCurrentSurface)
{
	zval *readdraw_param = NULL, _0;
	zend_long readdraw;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(readdraw)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &readdraw_param);
	ZVAL_LONG(&_0, readdraw);
	RETURN_LONG(phpgl_egl_eglgetcurrentsurface(&_0));
}

PHP_METHOD(OpenGL_EGL_EGL, eglGetDisplay)
{
	zval *display_id_param = NULL, _0;
	zend_long display_id;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(display_id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &display_id_param);
	ZVAL_LONG(&_0, display_id);
	RETURN_LONG(phpgl_egl_eglgetdisplay(&_0));
}

PHP_METHOD(OpenGL_EGL_EGL, eglGetError)
{

	RETURN_LONG(phpgl_egl_eglgeterror());
}

PHP_METHOD(OpenGL_EGL_EGL, eglGetProcAddress)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *procname_param = NULL;
	zval procname;

	ZVAL_UNDEF(&procname);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(procname)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &procname_param);
	zephir_get_strval(&procname, procname_param);
	RETURN_MM_LONG(phpgl_egl_eglgetprocaddress(&procname));
}

PHP_METHOD(OpenGL_EGL_EGL, eglInitialize)
{
	zval *dpy_param = NULL, *major_param = NULL, *minor_param = NULL, _0, _1, _2;
	zend_long dpy, major, minor, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(major)
		Z_PARAM_LONG(minor)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &dpy_param, &major_param, &minor_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, major);
	ZVAL_LONG(&_2, minor);
	r = phpgl_egl_eglinitialize(&_0, &_1, &_2);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglMakeCurrent)
{
	zval *dpy_param = NULL, *draw_param = NULL, *read_param = NULL, *ctx_param = NULL, _0, _1, _2, _3;
	zend_long dpy, draw, read, ctx, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(draw)
		Z_PARAM_LONG(read)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &draw_param, &read_param, &ctx_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, draw);
	ZVAL_LONG(&_2, read);
	ZVAL_LONG(&_3, ctx);
	r = phpgl_egl_eglmakecurrent(&_0, &_1, &_2, &_3);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglQueryContext)
{
	zval *dpy_param = NULL, *ctx_param = NULL, *attribute_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long dpy, ctx, attribute, value, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(attribute)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &ctx_param, &attribute_param, &value_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, ctx);
	ZVAL_LONG(&_2, attribute);
	ZVAL_LONG(&_3, value);
	r = phpgl_egl_eglquerycontext(&_0, &_1, &_2, &_3);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglQueryString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *dpy_param = NULL, *name_param = NULL, result, _0, _1;
	zend_long dpy, name;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &dpy_param, &name_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, name);
	phpgl_egl_eglquerystring(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(OpenGL_EGL_EGL, eglQuerySurface)
{
	zval *dpy_param = NULL, *surface_param = NULL, *attribute_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long dpy, surface, attribute, value, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(attribute)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &surface_param, &attribute_param, &value_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, attribute);
	ZVAL_LONG(&_3, value);
	r = phpgl_egl_eglquerysurface(&_0, &_1, &_2, &_3);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglSwapBuffers)
{
	zval *dpy_param = NULL, *surface_param = NULL, _0, _1;
	zend_long dpy, surface, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &dpy_param, &surface_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, surface);
	r = phpgl_egl_eglswapbuffers(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglTerminate)
{
	zval *dpy_param = NULL, _0;
	zend_long dpy, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(dpy)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &dpy_param);
	ZVAL_LONG(&_0, dpy);
	r = phpgl_egl_eglterminate(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglWaitGL)
{
	zend_long r = 0;
	r = phpgl_egl_eglwaitgl();
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglWaitNative)
{
	zval *engine_param = NULL, _0;
	zend_long engine, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(engine)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &engine_param);
	ZVAL_LONG(&_0, engine);
	r = phpgl_egl_eglwaitnative(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglBindTexImage)
{
	zval *dpy_param = NULL, *surface_param = NULL, *buffer_param = NULL, _0, _1, _2;
	zend_long dpy, surface, buffer, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &dpy_param, &surface_param, &buffer_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, buffer);
	r = phpgl_egl_eglbindteximage(&_0, &_1, &_2);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglReleaseTexImage)
{
	zval *dpy_param = NULL, *surface_param = NULL, *buffer_param = NULL, _0, _1, _2;
	zend_long dpy, surface, buffer, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &dpy_param, &surface_param, &buffer_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, buffer);
	r = phpgl_egl_eglreleaseteximage(&_0, &_1, &_2);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglSurfaceAttrib)
{
	zval *dpy_param = NULL, *surface_param = NULL, *attribute_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long dpy, surface, attribute, value, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(surface)
		Z_PARAM_LONG(attribute)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &surface_param, &attribute_param, &value_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, surface);
	ZVAL_LONG(&_2, attribute);
	ZVAL_LONG(&_3, value);
	r = phpgl_egl_eglsurfaceattrib(&_0, &_1, &_2, &_3);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglSwapInterval)
{
	zval *dpy_param = NULL, *interval_param = NULL, _0, _1;
	zend_long dpy, interval, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(interval)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &dpy_param, &interval_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, interval);
	r = phpgl_egl_eglswapinterval(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglBindAPI)
{
	zval *api_param = NULL, _0;
	zend_long api, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(api)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &api_param);
	ZVAL_LONG(&_0, api);
	r = phpgl_egl_eglbindapi(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglQueryAPI)
{

	RETURN_LONG(phpgl_egl_eglqueryapi());
}

PHP_METHOD(OpenGL_EGL_EGL, eglCreatePbufferFromClientBuffer)
{
	zval *dpy_param = NULL, *buftype_param = NULL, *buffer_param = NULL, *config_param = NULL, *attrib_list_param = NULL, _0, _1, _2, _3, _4;
	zend_long dpy, buftype, buffer, config, attrib_list;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(buftype)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(config)
		Z_PARAM_LONG(attrib_list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &dpy_param, &buftype_param, &buffer_param, &config_param, &attrib_list_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, buftype);
	ZVAL_LONG(&_2, buffer);
	ZVAL_LONG(&_3, config);
	ZVAL_LONG(&_4, attrib_list);
	RETURN_LONG(phpgl_egl_eglcreatepbufferfromclientbuffer(&_0, &_1, &_2, &_3, &_4));
}

PHP_METHOD(OpenGL_EGL_EGL, eglReleaseThread)
{
	zend_long r = 0;
	r = phpgl_egl_eglreleasethread();
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglWaitClient)
{
	zend_long r = 0;
	r = phpgl_egl_eglwaitclient();
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglGetCurrentContext)
{

	RETURN_LONG(phpgl_egl_eglgetcurrentcontext());
}

PHP_METHOD(OpenGL_EGL_EGL, eglCreateSync)
{
	zval *dpy_param = NULL, *type_param = NULL, *attrib_list_param = NULL, _0, _1, _2;
	zend_long dpy, type, attrib_list;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(attrib_list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &dpy_param, &type_param, &attrib_list_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, type);
	ZVAL_LONG(&_2, attrib_list);
	RETURN_LONG(phpgl_egl_eglcreatesync(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_EGL_EGL, eglDestroySync)
{
	zval *dpy_param = NULL, *sync_param = NULL, _0, _1;
	zend_long dpy, sync, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(sync)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &dpy_param, &sync_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, sync);
	r = phpgl_egl_egldestroysync(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglClientWaitSync)
{
	zval *dpy_param = NULL, *sync_param = NULL, *flags_param = NULL, *timeout_param = NULL, _0, _1, _2, _3;
	zend_long dpy, sync, flags, timeout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(sync)
		Z_PARAM_LONG(flags)
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &sync_param, &flags_param, &timeout_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, sync);
	ZVAL_LONG(&_2, flags);
	ZVAL_LONG(&_3, timeout);
	RETURN_LONG(phpgl_egl_eglclientwaitsync(&_0, &_1, &_2, &_3));
}

PHP_METHOD(OpenGL_EGL_EGL, eglGetSyncAttrib)
{
	zval *dpy_param = NULL, *sync_param = NULL, *attribute_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long dpy, sync, attribute, value, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(sync)
		Z_PARAM_LONG(attribute)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &sync_param, &attribute_param, &value_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, sync);
	ZVAL_LONG(&_2, attribute);
	ZVAL_LONG(&_3, value);
	r = phpgl_egl_eglgetsyncattrib(&_0, &_1, &_2, &_3);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglCreateImage)
{
	zval *dpy_param = NULL, *ctx_param = NULL, *target_param = NULL, *buffer_param = NULL, *attrib_list_param = NULL, _0, _1, _2, _3, _4;
	zend_long dpy, ctx, target, buffer, attrib_list;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(attrib_list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &dpy_param, &ctx_param, &target_param, &buffer_param, &attrib_list_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, ctx);
	ZVAL_LONG(&_2, target);
	ZVAL_LONG(&_3, buffer);
	ZVAL_LONG(&_4, attrib_list);
	RETURN_LONG(phpgl_egl_eglcreateimage(&_0, &_1, &_2, &_3, &_4));
}

PHP_METHOD(OpenGL_EGL_EGL, eglDestroyImage)
{
	zval *dpy_param = NULL, *image_param = NULL, _0, _1;
	zend_long dpy, image, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(image)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &dpy_param, &image_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, image);
	r = phpgl_egl_egldestroyimage(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_EGL_EGL, eglGetPlatformDisplay)
{
	zval *platform_param = NULL, *native_display_param = NULL, *attrib_list_param = NULL, _0, _1, _2;
	zend_long platform, native_display, attrib_list;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(platform)
		Z_PARAM_LONG(native_display)
		Z_PARAM_LONG(attrib_list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &platform_param, &native_display_param, &attrib_list_param);
	ZVAL_LONG(&_0, platform);
	ZVAL_LONG(&_1, native_display);
	ZVAL_LONG(&_2, attrib_list);
	RETURN_LONG(phpgl_egl_eglgetplatformdisplay(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_EGL_EGL, eglCreatePlatformWindowSurface)
{
	zval *dpy_param = NULL, *config_param = NULL, *native_window_param = NULL, *attrib_list_param = NULL, _0, _1, _2, _3;
	zend_long dpy, config, native_window, attrib_list;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(config)
		Z_PARAM_LONG(native_window)
		Z_PARAM_LONG(attrib_list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &config_param, &native_window_param, &attrib_list_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, config);
	ZVAL_LONG(&_2, native_window);
	ZVAL_LONG(&_3, attrib_list);
	RETURN_LONG(phpgl_egl_eglcreateplatformwindowsurface(&_0, &_1, &_2, &_3));
}

PHP_METHOD(OpenGL_EGL_EGL, eglCreatePlatformPixmapSurface)
{
	zval *dpy_param = NULL, *config_param = NULL, *native_pixmap_param = NULL, *attrib_list_param = NULL, _0, _1, _2, _3;
	zend_long dpy, config, native_pixmap, attrib_list;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(config)
		Z_PARAM_LONG(native_pixmap)
		Z_PARAM_LONG(attrib_list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &dpy_param, &config_param, &native_pixmap_param, &attrib_list_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, config);
	ZVAL_LONG(&_2, native_pixmap);
	ZVAL_LONG(&_3, attrib_list);
	RETURN_LONG(phpgl_egl_eglcreateplatformpixmapsurface(&_0, &_1, &_2, &_3));
}

PHP_METHOD(OpenGL_EGL_EGL, eglWaitSync)
{
	zval *dpy_param = NULL, *sync_param = NULL, *flags_param = NULL, _0, _1, _2;
	zend_long dpy, sync, flags, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(dpy)
		Z_PARAM_LONG(sync)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &dpy_param, &sync_param, &flags_param);
	ZVAL_LONG(&_0, dpy);
	ZVAL_LONG(&_1, sync);
	ZVAL_LONG(&_2, flags);
	r = phpgl_egl_eglwaitsync(&_0, &_1, &_2);
	RETURN_BOOL(r == 1);
}

