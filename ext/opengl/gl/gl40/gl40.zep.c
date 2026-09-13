
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
#include "src/gl-40.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL40_GL40)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL40, GL40, opengl, gl_gl40_gl40, opengl_gl_gl40_gl40_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glMinSampleShading)
{
	zval *value_param = NULL, _0;
	double value;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &value_param);
	value = zephir_get_doubleval(value_param);
	ZVAL_DOUBLE(&_0, value);
	phpgl_gl40_glminsampleshading(&_0);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glBlendEquationi)
{
	zval *buf_param = NULL, *mode_param = NULL, _0, _1;
	zend_long buf, mode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(buf)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &buf_param, &mode_param);
	ZVAL_LONG(&_0, buf);
	ZVAL_LONG(&_1, mode);
	phpgl_gl40_glblendequationi(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glBlendEquationSeparatei)
{
	zval *buf_param = NULL, *modeRGB_param = NULL, *modeAlpha_param = NULL, _0, _1, _2;
	zend_long buf, modeRGB, modeAlpha;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(buf)
		Z_PARAM_LONG(modeRGB)
		Z_PARAM_LONG(modeAlpha)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &buf_param, &modeRGB_param, &modeAlpha_param);
	ZVAL_LONG(&_0, buf);
	ZVAL_LONG(&_1, modeRGB);
	ZVAL_LONG(&_2, modeAlpha);
	phpgl_gl40_glblendequationseparatei(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glBlendFunci)
{
	zval *buf_param = NULL, *src_param = NULL, *dst_param = NULL, _0, _1, _2;
	zend_long buf, src, dst;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(buf)
		Z_PARAM_LONG(src)
		Z_PARAM_LONG(dst)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &buf_param, &src_param, &dst_param);
	ZVAL_LONG(&_0, buf);
	ZVAL_LONG(&_1, src);
	ZVAL_LONG(&_2, dst);
	phpgl_gl40_glblendfunci(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glBlendFuncSeparatei)
{
	zval *buf_param = NULL, *srcRGB_param = NULL, *dstRGB_param = NULL, *srcAlpha_param = NULL, *dstAlpha_param = NULL, _0, _1, _2, _3, _4;
	zend_long buf, srcRGB, dstRGB, srcAlpha, dstAlpha;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(buf)
		Z_PARAM_LONG(srcRGB)
		Z_PARAM_LONG(dstRGB)
		Z_PARAM_LONG(srcAlpha)
		Z_PARAM_LONG(dstAlpha)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &buf_param, &srcRGB_param, &dstRGB_param, &srcAlpha_param, &dstAlpha_param);
	ZVAL_LONG(&_0, buf);
	ZVAL_LONG(&_1, srcRGB);
	ZVAL_LONG(&_2, dstRGB);
	ZVAL_LONG(&_3, srcAlpha);
	ZVAL_LONG(&_4, dstAlpha);
	phpgl_gl40_glblendfuncseparatei(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glDrawArraysIndirect)
{
	zval *mode_param = NULL, *indirect_param = NULL, _0, _1;
	zend_long mode, indirect;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(indirect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &mode_param, &indirect_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, indirect);
	phpgl_gl40_gldrawarraysindirect(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glDrawElementsIndirect)
{
	zval *mode_param = NULL, *type_param = NULL, *indirect_param = NULL, _0, _1, _2;
	zend_long mode, type, indirect;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(indirect)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &mode_param, &type_param, &indirect_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, type);
	ZVAL_LONG(&_2, indirect);
	phpgl_gl40_gldrawelementsindirect(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform1d)
{
	double x;
	zval *location_param = NULL, *x_param = NULL, _0, _1;
	zend_long location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(x)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &location_param, &x_param);
	x = zephir_get_doubleval(x_param);
	ZVAL_LONG(&_0, location);
	ZVAL_DOUBLE(&_1, x);
	phpgl_gl40_gluniform1d(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform2d)
{
	double x, y;
	zval *location_param = NULL, *x_param = NULL, *y_param = NULL, _0, _1, _2;
	zend_long location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &location_param, &x_param, &y_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	ZVAL_LONG(&_0, location);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	phpgl_gl40_gluniform2d(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform3d)
{
	double x, y, z;
	zval *location_param = NULL, *x_param = NULL, *y_param = NULL, *z_param = NULL, _0, _1, _2, _3;
	zend_long location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_ZVAL(z)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &x_param, &y_param, &z_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);
	ZVAL_LONG(&_0, location);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	ZVAL_DOUBLE(&_3, z);
	phpgl_gl40_gluniform3d(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform4d)
{
	double x, y, z, w;
	zval *location_param = NULL, *x_param = NULL, *y_param = NULL, *z_param = NULL, *w_param = NULL, _0, _1, _2, _3, _4;
	zend_long location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_ZVAL(z)
		Z_PARAM_ZVAL(w)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &location_param, &x_param, &y_param, &z_param, &w_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);
	w = zephir_get_doubleval(w_param);
	ZVAL_LONG(&_0, location);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	ZVAL_DOUBLE(&_3, z);
	ZVAL_DOUBLE(&_4, w);
	phpgl_gl40_gluniform4d(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform1dv)
{
	zval *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, value);
	phpgl_gl40_gluniform1dv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform2dv)
{
	zval *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, value);
	phpgl_gl40_gluniform2dv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform3dv)
{
	zval *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, value);
	phpgl_gl40_gluniform3dv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform4dv)
{
	zval *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, value);
	phpgl_gl40_gluniform4dv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix2dv)
{
	zend_bool transpose;
	zval *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_BOOL(&_2, (transpose ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl40_gluniformmatrix2dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix3dv)
{
	zend_bool transpose;
	zval *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_BOOL(&_2, (transpose ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl40_gluniformmatrix3dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix4dv)
{
	zend_bool transpose;
	zval *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_BOOL(&_2, (transpose ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl40_gluniformmatrix4dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix2x3dv)
{
	zend_bool transpose;
	zval *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_BOOL(&_2, (transpose ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl40_gluniformmatrix2x3dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix2x4dv)
{
	zend_bool transpose;
	zval *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_BOOL(&_2, (transpose ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl40_gluniformmatrix2x4dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix3x2dv)
{
	zend_bool transpose;
	zval *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_BOOL(&_2, (transpose ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl40_gluniformmatrix3x2dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix3x4dv)
{
	zend_bool transpose;
	zval *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_BOOL(&_2, (transpose ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl40_gluniformmatrix3x4dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix4x2dv)
{
	zend_bool transpose;
	zval *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_BOOL(&_2, (transpose ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl40_gluniformmatrix4x2dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix4x3dv)
{
	zend_bool transpose;
	zval *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, count);
	ZVAL_BOOL(&_2, (transpose ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl40_gluniformmatrix4x3dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glGetUniformdv)
{
	zval *program_param = NULL, *location_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long program, location, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &program_param, &location_param, &params_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, params);
	phpgl_gl40_glgetuniformdv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glGetSubroutineUniformLocation)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *program_param = NULL, *shadertype_param = NULL, *name_param = NULL, _0, _1;
	zend_long program, shadertype;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(shadertype)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &program_param, &shadertype_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, shadertype);
	RETURN_MM_LONG(phpgl_gl40_glgetsubroutineuniformlocation(&_0, &_1, &name));
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glGetSubroutineIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *program_param = NULL, *shadertype_param = NULL, *name_param = NULL, _0, _1;
	zend_long program, shadertype;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(shadertype)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &program_param, &shadertype_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, shadertype);
	RETURN_MM_LONG(phpgl_gl40_glgetsubroutineindex(&_0, &_1, &name));
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glGetActiveSubroutineUniformiv)
{
	zval *program_param = NULL, *shadertype_param = NULL, *index_param = NULL, *pname_param = NULL, *values_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, shadertype, index, pname, values;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(shadertype)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(values)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &shadertype_param, &index_param, &pname_param, &values_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, shadertype);
	ZVAL_LONG(&_2, index);
	ZVAL_LONG(&_3, pname);
	ZVAL_LONG(&_4, values);
	phpgl_gl40_glgetactivesubroutineuniformiv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glGetActiveSubroutineUniformName)
{
	zval *program_param = NULL, *shadertype_param = NULL, *index_param = NULL, *bufSize_param = NULL, *length_param = NULL, *name_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long program, shadertype, index, bufSize, length, name;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(shadertype)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &program_param, &shadertype_param, &index_param, &bufSize_param, &length_param, &name_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, shadertype);
	ZVAL_LONG(&_2, index);
	ZVAL_LONG(&_3, bufSize);
	ZVAL_LONG(&_4, length);
	ZVAL_LONG(&_5, name);
	phpgl_gl40_glgetactivesubroutineuniformname(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glGetActiveSubroutineName)
{
	zval *program_param = NULL, *shadertype_param = NULL, *index_param = NULL, *bufSize_param = NULL, *length_param = NULL, *name_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long program, shadertype, index, bufSize, length, name;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(shadertype)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &program_param, &shadertype_param, &index_param, &bufSize_param, &length_param, &name_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, shadertype);
	ZVAL_LONG(&_2, index);
	ZVAL_LONG(&_3, bufSize);
	ZVAL_LONG(&_4, length);
	ZVAL_LONG(&_5, name);
	phpgl_gl40_glgetactivesubroutinename(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformSubroutinesuiv)
{
	zval *shadertype_param = NULL, *count_param = NULL, *indices_param = NULL, _0, _1, _2;
	zend_long shadertype, count, indices;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(shadertype)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(indices)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &shadertype_param, &count_param, &indices_param);
	ZVAL_LONG(&_0, shadertype);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, indices);
	phpgl_gl40_gluniformsubroutinesuiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glGetUniformSubroutineuiv)
{
	zval *shadertype_param = NULL, *location_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long shadertype, location, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(shadertype)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &shadertype_param, &location_param, &params_param);
	ZVAL_LONG(&_0, shadertype);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, params);
	phpgl_gl40_glgetuniformsubroutineuiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glGetProgramStageiv)
{
	zval *program_param = NULL, *shadertype_param = NULL, *pname_param = NULL, *values_param = NULL, _0, _1, _2, _3;
	zend_long program, shadertype, pname, values;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(shadertype)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(values)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &shadertype_param, &pname_param, &values_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, shadertype);
	ZVAL_LONG(&_2, pname);
	ZVAL_LONG(&_3, values);
	phpgl_gl40_glgetprogramstageiv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glPatchParameteri)
{
	zval *pname_param = NULL, *value_param = NULL, _0, _1;
	zend_long pname, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &value_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, value);
	phpgl_gl40_glpatchparameteri(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glPatchParameterfv)
{
	zval *pname_param = NULL, *values_param = NULL, _0, _1;
	zend_long pname, values;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(values)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &values_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, values);
	phpgl_gl40_glpatchparameterfv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glBindTransformFeedback)
{
	zval *target_param = NULL, *id_param = NULL, _0, _1;
	zend_long target, id;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &target_param, &id_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, id);
	phpgl_gl40_glbindtransformfeedback(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glDeleteTransformFeedbacks)
{
	zval *n_param = NULL, *ids_param = NULL, _0, _1;
	zend_long n, ids;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(ids)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &ids_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, ids);
	phpgl_gl40_gldeletetransformfeedbacks(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glGenTransformFeedbacks)
{
	zval *n_param = NULL, *ids_param = NULL, _0, _1;
	zend_long n, ids;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(ids)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &ids_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, ids);
	phpgl_gl40_glgentransformfeedbacks(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glIsTransformFeedback)
{
	zval *id_param = NULL, _0;
	zend_long id, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &id_param);
	ZVAL_LONG(&_0, id);
	r = phpgl_gl40_glistransformfeedback(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glPauseTransformFeedback)
{

	phpgl_gl40_glpausetransformfeedback();
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glResumeTransformFeedback)
{

	phpgl_gl40_glresumetransformfeedback();
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glDrawTransformFeedback)
{
	zval *mode_param = NULL, *id_param = NULL, _0, _1;
	zend_long mode, id;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &mode_param, &id_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, id);
	phpgl_gl40_gldrawtransformfeedback(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glDrawTransformFeedbackStream)
{
	zval *mode_param = NULL, *id_param = NULL, *stream_param = NULL, _0, _1, _2;
	zend_long mode, id, stream;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(id)
		Z_PARAM_LONG(stream)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &mode_param, &id_param, &stream_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, id);
	ZVAL_LONG(&_2, stream);
	phpgl_gl40_gldrawtransformfeedbackstream(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glBeginQueryIndexed)
{
	zval *target_param = NULL, *index_param = NULL, *id_param = NULL, _0, _1, _2;
	zend_long target, index, id;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &index_param, &id_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, index);
	ZVAL_LONG(&_2, id);
	phpgl_gl40_glbeginqueryindexed(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glEndQueryIndexed)
{
	zval *target_param = NULL, *index_param = NULL, _0, _1;
	zend_long target, index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &target_param, &index_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, index);
	phpgl_gl40_glendqueryindexed(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL40_GL40, glGetQueryIndexediv)
{
	zval *target_param = NULL, *index_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2, _3;
	zend_long target, index, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &index_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, index);
	ZVAL_LONG(&_2, pname);
	ZVAL_LONG(&_3, params);
	phpgl_gl40_glgetqueryindexediv(&_0, &_1, &_2, &_3);
}

