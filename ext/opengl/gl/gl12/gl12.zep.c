
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
#include "src/gl-12.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL12_GL12)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL12, GL12, opengl, gl_gl12_gl12, opengl_gl_gl12_gl12_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL12_GL12, glDrawRangeElements)
{
	zval *mode_param = NULL, *start_param = NULL, *end_param = NULL, *count_param = NULL, *type_param = NULL, *indices_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long mode, start, end, count, type, indices;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(start)
		Z_PARAM_LONG(end)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(indices)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &mode_param, &start_param, &end_param, &count_param, &type_param, &indices_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, start);
	ZVAL_LONG(&_2, end);
	ZVAL_LONG(&_3, count);
	ZVAL_LONG(&_4, type);
	ZVAL_LONG(&_5, indices);
	phpgl_gl12_gldrawrangeelements(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL12_GL12, glTexImage3D)
{
	zval *target_param = NULL, *level_param = NULL, *internalformat_param = NULL, *width_param = NULL, *height_param = NULL, *depth_param = NULL, *border_param = NULL, *format_param = NULL, *type_param = NULL, *pixels_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zend_long target, level, internalformat, width, height, depth, border, format, type, pixels;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZEND_PARSE_PARAMETERS_START(10, 10)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(depth)
		Z_PARAM_LONG(border)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(pixels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(10, 0, &target_param, &level_param, &internalformat_param, &width_param, &height_param, &depth_param, &border_param, &format_param, &type_param, &pixels_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, height);
	ZVAL_LONG(&_5, depth);
	ZVAL_LONG(&_6, border);
	ZVAL_LONG(&_7, format);
	ZVAL_LONG(&_8, type);
	ZVAL_LONG(&_9, pixels);
	phpgl_gl12_glteximage3d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8, &_9);
}

PHP_METHOD(OpenGL_GL_GL12_GL12, glTexSubImage3D)
{
	zval *target_param = NULL, *level_param = NULL, *xoffset_param = NULL, *yoffset_param = NULL, *zoffset_param = NULL, *width_param = NULL, *height_param = NULL, *depth_param = NULL, *format_param = NULL, *type_param = NULL, *pixels_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10;
	zend_long target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZEND_PARSE_PARAMETERS_START(11, 11)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(xoffset)
		Z_PARAM_LONG(yoffset)
		Z_PARAM_LONG(zoffset)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(depth)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(pixels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(11, 0, &target_param, &level_param, &xoffset_param, &yoffset_param, &zoffset_param, &width_param, &height_param, &depth_param, &format_param, &type_param, &pixels_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, xoffset);
	ZVAL_LONG(&_3, yoffset);
	ZVAL_LONG(&_4, zoffset);
	ZVAL_LONG(&_5, width);
	ZVAL_LONG(&_6, height);
	ZVAL_LONG(&_7, depth);
	ZVAL_LONG(&_8, format);
	ZVAL_LONG(&_9, type);
	ZVAL_LONG(&_10, pixels);
	phpgl_gl12_gltexsubimage3d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8, &_9, &_10);
}

PHP_METHOD(OpenGL_GL_GL12_GL12, glCopyTexSubImage3D)
{
	zval *target_param = NULL, *level_param = NULL, *xoffset_param = NULL, *yoffset_param = NULL, *zoffset_param = NULL, *x_param = NULL, *y_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zend_long target, level, xoffset, yoffset, zoffset, x, y, width, height;

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
		Z_PARAM_LONG(zoffset)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(9, 0, &target_param, &level_param, &xoffset_param, &yoffset_param, &zoffset_param, &x_param, &y_param, &width_param, &height_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, xoffset);
	ZVAL_LONG(&_3, yoffset);
	ZVAL_LONG(&_4, zoffset);
	ZVAL_LONG(&_5, x);
	ZVAL_LONG(&_6, y);
	ZVAL_LONG(&_7, width);
	ZVAL_LONG(&_8, height);
	phpgl_gl12_glcopytexsubimage3d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8);
}

