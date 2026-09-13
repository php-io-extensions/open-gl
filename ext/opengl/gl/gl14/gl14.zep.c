
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
#include "src/gl-14.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL14_GL14)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL14, GL14, opengl, gl_gl14_gl14, opengl_gl_gl14_gl14_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL14_GL14, glBlendFuncSeparate)
{
	zval *sfactorRGB_param = NULL, *dfactorRGB_param = NULL, *sfactorAlpha_param = NULL, *dfactorAlpha_param = NULL, _0, _1, _2, _3;
	zend_long sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(sfactorRGB)
		Z_PARAM_LONG(dfactorRGB)
		Z_PARAM_LONG(sfactorAlpha)
		Z_PARAM_LONG(dfactorAlpha)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &sfactorRGB_param, &dfactorRGB_param, &sfactorAlpha_param, &dfactorAlpha_param);
	ZVAL_LONG(&_0, sfactorRGB);
	ZVAL_LONG(&_1, dfactorRGB);
	ZVAL_LONG(&_2, sfactorAlpha);
	ZVAL_LONG(&_3, dfactorAlpha);
	phpgl_gl14_glblendfuncseparate(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL14_GL14, glMultiDrawArrays)
{
	zval *mode_param = NULL, *first_param = NULL, *count_param = NULL, *drawcount_param = NULL, _0, _1, _2, _3;
	zend_long mode, first, count, drawcount;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(first)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(drawcount)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &mode_param, &first_param, &count_param, &drawcount_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, first);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, drawcount);
	phpgl_gl14_glmultidrawarrays(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL14_GL14, glMultiDrawElements)
{
	zval *mode_param = NULL, *count_param = NULL, *type_param = NULL, *indices_param = NULL, *drawcount_param = NULL, _0, _1, _2, _3, _4;
	zend_long mode, count, type, indices, drawcount;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(indices)
		Z_PARAM_LONG(drawcount)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &mode_param, &count_param, &type_param, &indices_param, &drawcount_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, type);
	ZVAL_LONG(&_3, indices);
	ZVAL_LONG(&_4, drawcount);
	phpgl_gl14_glmultidrawelements(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL14_GL14, glPointParameterf)
{
	double param;
	zval *pname_param = NULL, *param_param = NULL, _0, _1;
	zend_long pname;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_ZVAL(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &param_param);
	param = zephir_get_doubleval(param_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_DOUBLE(&_1, param);
	phpgl_gl14_glpointparameterf(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL14_GL14, glPointParameterfv)
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
	phpgl_gl14_glpointparameterfv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL14_GL14, glPointParameteri)
{
	zval *pname_param = NULL, *param_param = NULL, _0, _1;
	zend_long pname, param;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &param_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, param);
	phpgl_gl14_glpointparameteri(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL14_GL14, glPointParameteriv)
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
	phpgl_gl14_glpointparameteriv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL14_GL14, glBlendColor)
{
	zval *red_param = NULL, *green_param = NULL, *blue_param = NULL, *alpha_param = NULL, _0, _1, _2, _3;
	double red, green, blue, alpha;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_ZVAL(red)
		Z_PARAM_ZVAL(green)
		Z_PARAM_ZVAL(blue)
		Z_PARAM_ZVAL(alpha)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &red_param, &green_param, &blue_param, &alpha_param);
	red = zephir_get_doubleval(red_param);
	green = zephir_get_doubleval(green_param);
	blue = zephir_get_doubleval(blue_param);
	alpha = zephir_get_doubleval(alpha_param);
	ZVAL_DOUBLE(&_0, red);
	ZVAL_DOUBLE(&_1, green);
	ZVAL_DOUBLE(&_2, blue);
	ZVAL_DOUBLE(&_3, alpha);
	phpgl_gl14_glblendcolor(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL14_GL14, glBlendEquation)
{
	zval *mode_param = NULL, _0;
	zend_long mode;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mode_param);
	ZVAL_LONG(&_0, mode);
	phpgl_gl14_glblendequation(&_0);
}

