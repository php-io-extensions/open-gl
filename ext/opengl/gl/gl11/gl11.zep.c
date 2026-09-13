
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "src/gl-11.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL11_GL11)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL11, GL11, opengl, gl_gl11_gl11, opengl_gl_gl11_gl11_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glDrawArrays)
{
	zval *mode_param = NULL, *first_param = NULL, *count_param = NULL, _0, _1, _2;
	zend_long mode, first, count;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(first)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &mode_param, &first_param, &count_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, first);
	ZVAL_LONG(&_2, count);
	phpgl_gl11_gldrawarrays(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glDrawElements)
{
	zval *mode_param = NULL, *count_param = NULL, *type_param = NULL, *indices_param = NULL, _0, _1, _2, _3;
	zend_long mode, count, type, indices;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(indices)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &mode_param, &count_param, &type_param, &indices_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, type);
	ZVAL_LONG(&_3, indices);
	phpgl_gl11_gldrawelements(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glGetPointerv)
{
	zval *pname_param = NULL, *params_param = NULL, _0, _1;
	zend_long pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &params_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, params);
	phpgl_gl11_glgetpointerv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glPolygonOffset)
{
	zval *factor_param = NULL, *units_param = NULL, _0, _1;
	double factor, units;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(factor)
		Z_PARAM_ZVAL(units)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &factor_param, &units_param);
	factor = zephir_get_doubleval(factor_param);
	units = zephir_get_doubleval(units_param);
	ZVAL_DOUBLE(&_0, factor);
	ZVAL_DOUBLE(&_1, units);
	phpgl_gl11_glpolygonoffset(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glCopyTexImage1D)
{
	zval *target_param = NULL, *level_param = NULL, *internalformat_param = NULL, *x_param = NULL, *y_param = NULL, *width_param = NULL, *border_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long target, level, internalformat, x, y, width, border;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(border)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &target_param, &level_param, &internalformat_param, &x_param, &y_param, &width_param, &border_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, x);
	ZVAL_LONG(&_4, y);
	ZVAL_LONG(&_5, width);
	ZVAL_LONG(&_6, border);
	phpgl_gl11_glcopyteximage1d(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glCopyTexImage2D)
{
	zval *target_param = NULL, *level_param = NULL, *internalformat_param = NULL, *x_param = NULL, *y_param = NULL, *width_param = NULL, *height_param = NULL, *border_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zend_long target, level, internalformat, x, y, width, height, border;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(border)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(8, 0, &target_param, &level_param, &internalformat_param, &x_param, &y_param, &width_param, &height_param, &border_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, x);
	ZVAL_LONG(&_4, y);
	ZVAL_LONG(&_5, width);
	ZVAL_LONG(&_6, height);
	ZVAL_LONG(&_7, border);
	phpgl_gl11_glcopyteximage2d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glCopyTexSubImage1D)
{
	zval *target_param = NULL, *level_param = NULL, *xoffset_param = NULL, *x_param = NULL, *y_param = NULL, *width_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long target, level, xoffset, x, y, width;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(xoffset)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &target_param, &level_param, &xoffset_param, &x_param, &y_param, &width_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, xoffset);
	ZVAL_LONG(&_3, x);
	ZVAL_LONG(&_4, y);
	ZVAL_LONG(&_5, width);
	phpgl_gl11_glcopytexsubimage1d(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glCopyTexSubImage2D)
{
	zval *target_param = NULL, *level_param = NULL, *xoffset_param = NULL, *yoffset_param = NULL, *x_param = NULL, *y_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zend_long target, level, xoffset, yoffset, x, y, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(xoffset)
		Z_PARAM_LONG(yoffset)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(8, 0, &target_param, &level_param, &xoffset_param, &yoffset_param, &x_param, &y_param, &width_param, &height_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, xoffset);
	ZVAL_LONG(&_3, yoffset);
	ZVAL_LONG(&_4, x);
	ZVAL_LONG(&_5, y);
	ZVAL_LONG(&_6, width);
	ZVAL_LONG(&_7, height);
	phpgl_gl11_glcopytexsubimage2d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glTexSubImage1D)
{
	zval *target_param = NULL, *level_param = NULL, *xoffset_param = NULL, *width_param = NULL, *format_param = NULL, *type_param = NULL, *pixels_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long target, level, xoffset, width, format, type, pixels;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(xoffset)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(pixels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &target_param, &level_param, &xoffset_param, &width_param, &format_param, &type_param, &pixels_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, xoffset);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, format);
	ZVAL_LONG(&_5, type);
	ZVAL_LONG(&_6, pixels);
	phpgl_gl11_gltexsubimage1d(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glTexSubImage2D)
{
	zval *target_param = NULL, *level_param = NULL, *xoffset_param = NULL, *yoffset_param = NULL, *width_param = NULL, *height_param = NULL, *format_param = NULL, *type_param = NULL, *pixels_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zend_long target, level, xoffset, yoffset, width, height, format, type, pixels;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZEND_PARSE_PARAMETERS_START(9, 9)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(xoffset)
		Z_PARAM_LONG(yoffset)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(pixels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(9, 0, &target_param, &level_param, &xoffset_param, &yoffset_param, &width_param, &height_param, &format_param, &type_param, &pixels_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, xoffset);
	ZVAL_LONG(&_3, yoffset);
	ZVAL_LONG(&_4, width);
	ZVAL_LONG(&_5, height);
	ZVAL_LONG(&_6, format);
	ZVAL_LONG(&_7, type);
	ZVAL_LONG(&_8, pixels);
	phpgl_gl11_gltexsubimage2d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glBindTexture)
{
	zval *target_param = NULL, *texture_param = NULL, _0, _1;
	zend_long target, texture;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(texture)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &target_param, &texture_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, texture);
	phpgl_gl11_glbindtexture(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glDeleteTextures)
{
	zval *n_param = NULL, *textures_param = NULL, _0, _1;
	zend_long n, textures;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(textures)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &textures_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, textures);
	phpgl_gl11_gldeletetextures(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glGenTextures)
{
	zval *n_param = NULL, *textures_param = NULL, _0, _1;
	zend_long n, textures;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(textures)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &textures_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, textures);
	phpgl_gl11_glgentextures(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL11_GL11, glIsTexture)
{
	zval *texture_param = NULL, _0;
	zend_long texture, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(texture)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &texture_param);
	ZVAL_LONG(&_0, texture);
	r = phpgl_gl11_glistexture(&_0);
	RETURN_BOOL(r == 1);
}

