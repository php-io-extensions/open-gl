
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
#include "src/gl-13.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL13_GL13)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL13, GL13, opengl, gl_gl13_gl13, opengl_gl_gl13_gl13_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL13_GL13, glActiveTexture)
{
	zval *texture_param = NULL, _0;
	zend_long texture;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(texture)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &texture_param);
	ZVAL_LONG(&_0, texture);
	phpgl_gl13_glactivetexture(&_0);
}

PHP_METHOD(OpenGL_GL_GL13_GL13, glSampleCoverage)
{
	zend_bool invert;
	zval *value_param = NULL, *invert_param = NULL, _0, _1;
	double value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(value)
		Z_PARAM_BOOL(invert)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &value_param, &invert_param);
	value = zephir_get_doubleval(value_param);
	ZVAL_DOUBLE(&_0, value);
	ZVAL_BOOL(&_1, (invert ? 1 : 0));
	phpgl_gl13_glsamplecoverage(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexImage3D)
{
	zval *target_param = NULL, *level_param = NULL, *internalformat_param = NULL, *width_param = NULL, *height_param = NULL, *depth_param = NULL, *border_param = NULL, *imageSize_param = NULL, *data_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zend_long target, level, internalformat, width, height, depth, border, imageSize, data;

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
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(depth)
		Z_PARAM_LONG(border)
		Z_PARAM_LONG(imageSize)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(9, 0, &target_param, &level_param, &internalformat_param, &width_param, &height_param, &depth_param, &border_param, &imageSize_param, &data_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, height);
	ZVAL_LONG(&_5, depth);
	ZVAL_LONG(&_6, border);
	ZVAL_LONG(&_7, imageSize);
	ZVAL_LONG(&_8, data);
	phpgl_gl13_glcompressedteximage3d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8);
}

PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexImage2D)
{
	zval *target_param = NULL, *level_param = NULL, *internalformat_param = NULL, *width_param = NULL, *height_param = NULL, *border_param = NULL, *imageSize_param = NULL, *data_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zend_long target, level, internalformat, width, height, border, imageSize, data;

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
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(border)
		Z_PARAM_LONG(imageSize)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(8, 0, &target_param, &level_param, &internalformat_param, &width_param, &height_param, &border_param, &imageSize_param, &data_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, height);
	ZVAL_LONG(&_5, border);
	ZVAL_LONG(&_6, imageSize);
	ZVAL_LONG(&_7, data);
	phpgl_gl13_glcompressedteximage2d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7);
}

PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexImage1D)
{
	zval *target_param = NULL, *level_param = NULL, *internalformat_param = NULL, *width_param = NULL, *border_param = NULL, *imageSize_param = NULL, *data_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long target, level, internalformat, width, border, imageSize, data;

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
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(border)
		Z_PARAM_LONG(imageSize)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &target_param, &level_param, &internalformat_param, &width_param, &border_param, &imageSize_param, &data_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, border);
	ZVAL_LONG(&_5, imageSize);
	ZVAL_LONG(&_6, data);
	phpgl_gl13_glcompressedteximage1d(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexSubImage3D)
{
	zval *target_param = NULL, *level_param = NULL, *xoffset_param = NULL, *yoffset_param = NULL, *zoffset_param = NULL, *width_param = NULL, *height_param = NULL, *depth_param = NULL, *format_param = NULL, *imageSize_param = NULL, *data_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10;
	zend_long target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data;

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
		Z_PARAM_LONG(imageSize)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(11, 0, &target_param, &level_param, &xoffset_param, &yoffset_param, &zoffset_param, &width_param, &height_param, &depth_param, &format_param, &imageSize_param, &data_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, xoffset);
	ZVAL_LONG(&_3, yoffset);
	ZVAL_LONG(&_4, zoffset);
	ZVAL_LONG(&_5, width);
	ZVAL_LONG(&_6, height);
	ZVAL_LONG(&_7, depth);
	ZVAL_LONG(&_8, format);
	ZVAL_LONG(&_9, imageSize);
	ZVAL_LONG(&_10, data);
	phpgl_gl13_glcompressedtexsubimage3d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8, &_9, &_10);
}

PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexSubImage2D)
{
	zval *target_param = NULL, *level_param = NULL, *xoffset_param = NULL, *yoffset_param = NULL, *width_param = NULL, *height_param = NULL, *format_param = NULL, *imageSize_param = NULL, *data_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zend_long target, level, xoffset, yoffset, width, height, format, imageSize, data;

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
		Z_PARAM_LONG(imageSize)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(9, 0, &target_param, &level_param, &xoffset_param, &yoffset_param, &width_param, &height_param, &format_param, &imageSize_param, &data_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, xoffset);
	ZVAL_LONG(&_3, yoffset);
	ZVAL_LONG(&_4, width);
	ZVAL_LONG(&_5, height);
	ZVAL_LONG(&_6, format);
	ZVAL_LONG(&_7, imageSize);
	ZVAL_LONG(&_8, data);
	phpgl_gl13_glcompressedtexsubimage2d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8);
}

PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexSubImage1D)
{
	zval *target_param = NULL, *level_param = NULL, *xoffset_param = NULL, *width_param = NULL, *format_param = NULL, *imageSize_param = NULL, *data_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long target, level, xoffset, width, format, imageSize, data;

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
		Z_PARAM_LONG(imageSize)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &target_param, &level_param, &xoffset_param, &width_param, &format_param, &imageSize_param, &data_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, xoffset);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, format);
	ZVAL_LONG(&_5, imageSize);
	ZVAL_LONG(&_6, data);
	phpgl_gl13_glcompressedtexsubimage1d(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(OpenGL_GL_GL13_GL13, glGetCompressedTexImage)
{
	zval *target_param = NULL, *level_param = NULL, *img_param = NULL, _0, _1, _2;
	zend_long target, level, img;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(img)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &level_param, &img_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, img);
	phpgl_gl13_glgetcompressedteximage(&_0, &_1, &_2);
}

