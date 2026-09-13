
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
#include "src/gl-21.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL21_GL21)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL21, GL21, opengl, gl_gl21_gl21, opengl_gl_gl21_gl21_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix2x3fv)
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
	phpgl_gl21_gluniformmatrix2x3fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix3x2fv)
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
	phpgl_gl21_gluniformmatrix3x2fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix2x4fv)
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
	phpgl_gl21_gluniformmatrix2x4fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix4x2fv)
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
	phpgl_gl21_gluniformmatrix4x2fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix3x4fv)
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
	phpgl_gl21_gluniformmatrix3x4fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix4x3fv)
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
	phpgl_gl21_gluniformmatrix4x3fv(&_0, &_1, &_2, &_3);
}

