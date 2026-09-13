
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
#include "src/gl-33.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL33_GL33)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL33, GL33, opengl, gl_gl33_gl33, opengl_gl_gl33_gl33_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glBindFragDataLocationIndexed)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *program_param = NULL, *colorNumber_param = NULL, *index_param = NULL, *name_param = NULL, _0, _1, _2;
	zend_long program, colorNumber, index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(colorNumber)
		Z_PARAM_LONG(index)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &program_param, &colorNumber_param, &index_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, colorNumber);
	ZVAL_LONG(&_2, index);
	phpgl_gl33_glbindfragdatalocationindexed(&_0, &_1, &_2, &name);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glGetFragDataIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *program_param = NULL, *name_param = NULL, _0;
	zend_long program;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(program)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &program_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, program);
	RETURN_MM_LONG(phpgl_gl33_glgetfragdataindex(&_0, &name));
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glGenSamplers)
{
	zval *count_param = NULL, *samplers_param = NULL, _0, _1;
	zend_long count, samplers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(samplers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &count_param, &samplers_param);
	ZVAL_LONG(&_0, count);
	ZVAL_LONG(&_1, samplers);
	phpgl_gl33_glgensamplers(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glDeleteSamplers)
{
	zval *count_param = NULL, *samplers_param = NULL, _0, _1;
	zend_long count, samplers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(samplers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &count_param, &samplers_param);
	ZVAL_LONG(&_0, count);
	ZVAL_LONG(&_1, samplers);
	phpgl_gl33_gldeletesamplers(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glIsSampler)
{
	zval *sampler_param = NULL, _0;
	zend_long sampler, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(sampler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &sampler_param);
	ZVAL_LONG(&_0, sampler);
	r = phpgl_gl33_glissampler(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glBindSampler)
{
	zval *unit_param = NULL, *sampler_param = NULL, _0, _1;
	zend_long unit, sampler;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(unit)
		Z_PARAM_LONG(sampler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &unit_param, &sampler_param);
	ZVAL_LONG(&_0, unit);
	ZVAL_LONG(&_1, sampler);
	phpgl_gl33_glbindsampler(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameteri)
{
	zval *sampler_param = NULL, *pname_param = NULL, *param_param = NULL, _0, _1, _2;
	zend_long sampler, pname, param;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sampler_param, &pname_param, &param_param);
	ZVAL_LONG(&_0, sampler);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, param);
	phpgl_gl33_glsamplerparameteri(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameteriv)
{
	zval *sampler_param = NULL, *pname_param = NULL, *param_param = NULL, _0, _1, _2;
	zend_long sampler, pname, param;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sampler_param, &pname_param, &param_param);
	ZVAL_LONG(&_0, sampler);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, param);
	phpgl_gl33_glsamplerparameteriv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameterf)
{
	double param;
	zval *sampler_param = NULL, *pname_param = NULL, *param_param = NULL, _0, _1, _2;
	zend_long sampler, pname;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pname)
		Z_PARAM_ZVAL(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sampler_param, &pname_param, &param_param);
	param = zephir_get_doubleval(param_param);
	ZVAL_LONG(&_0, sampler);
	ZVAL_LONG(&_1, pname);
	ZVAL_DOUBLE(&_2, param);
	phpgl_gl33_glsamplerparameterf(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameterfv)
{
	zval *sampler_param = NULL, *pname_param = NULL, *param_param = NULL, _0, _1, _2;
	zend_long sampler, pname, param;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sampler_param, &pname_param, &param_param);
	ZVAL_LONG(&_0, sampler);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, param);
	phpgl_gl33_glsamplerparameterfv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameterIiv)
{
	zval *sampler_param = NULL, *pname_param = NULL, *param_param = NULL, _0, _1, _2;
	zend_long sampler, pname, param;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sampler_param, &pname_param, &param_param);
	ZVAL_LONG(&_0, sampler);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, param);
	phpgl_gl33_glsamplerparameteriiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameterIuiv)
{
	zval *sampler_param = NULL, *pname_param = NULL, *param_param = NULL, _0, _1, _2;
	zend_long sampler, pname, param;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sampler_param, &pname_param, &param_param);
	ZVAL_LONG(&_0, sampler);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, param);
	phpgl_gl33_glsamplerparameteriuiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glGetSamplerParameteriv)
{
	zval *sampler_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long sampler, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sampler_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, sampler);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl33_glgetsamplerparameteriv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glGetSamplerParameterIiv)
{
	zval *sampler_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long sampler, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sampler_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, sampler);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl33_glgetsamplerparameteriiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glGetSamplerParameterfv)
{
	zval *sampler_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long sampler, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sampler_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, sampler);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl33_glgetsamplerparameterfv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glGetSamplerParameterIuiv)
{
	zval *sampler_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long sampler, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sampler)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sampler_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, sampler);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl33_glgetsamplerparameteriuiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glQueryCounter)
{
	zval *id_param = NULL, *target_param = NULL, _0, _1;
	zend_long id, target;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(id)
		Z_PARAM_LONG(target)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &id_param, &target_param);
	ZVAL_LONG(&_0, id);
	ZVAL_LONG(&_1, target);
	phpgl_gl33_glquerycounter(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glGetQueryObjecti64v)
{
	zval *id_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long id, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(id)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &id_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, id);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl33_glgetqueryobjecti64v(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glGetQueryObjectui64v)
{
	zval *id_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long id, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(id)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &id_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, id);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl33_glgetqueryobjectui64v(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribDivisor)
{
	zval *index_param = NULL, *divisor_param = NULL, _0, _1;
	zend_long index, divisor;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(divisor)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &divisor_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, divisor);
	phpgl_gl33_glvertexattribdivisor(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP1ui)
{
	zend_bool normalized;
	zval *index_param = NULL, *type_param = NULL, *normalized_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long index, type, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(type)
		Z_PARAM_BOOL(normalized)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &type_param, &normalized_param, &value_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, type);
	ZVAL_BOOL(&_2, (normalized ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl33_glvertexattribp1ui(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP1uiv)
{
	zend_bool normalized;
	zval *index_param = NULL, *type_param = NULL, *normalized_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long index, type, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(type)
		Z_PARAM_BOOL(normalized)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &type_param, &normalized_param, &value_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, type);
	ZVAL_BOOL(&_2, (normalized ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl33_glvertexattribp1uiv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP2ui)
{
	zend_bool normalized;
	zval *index_param = NULL, *type_param = NULL, *normalized_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long index, type, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(type)
		Z_PARAM_BOOL(normalized)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &type_param, &normalized_param, &value_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, type);
	ZVAL_BOOL(&_2, (normalized ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl33_glvertexattribp2ui(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP2uiv)
{
	zend_bool normalized;
	zval *index_param = NULL, *type_param = NULL, *normalized_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long index, type, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(type)
		Z_PARAM_BOOL(normalized)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &type_param, &normalized_param, &value_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, type);
	ZVAL_BOOL(&_2, (normalized ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl33_glvertexattribp2uiv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP3ui)
{
	zend_bool normalized;
	zval *index_param = NULL, *type_param = NULL, *normalized_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long index, type, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(type)
		Z_PARAM_BOOL(normalized)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &type_param, &normalized_param, &value_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, type);
	ZVAL_BOOL(&_2, (normalized ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl33_glvertexattribp3ui(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP3uiv)
{
	zend_bool normalized;
	zval *index_param = NULL, *type_param = NULL, *normalized_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long index, type, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(type)
		Z_PARAM_BOOL(normalized)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &type_param, &normalized_param, &value_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, type);
	ZVAL_BOOL(&_2, (normalized ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl33_glvertexattribp3uiv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP4ui)
{
	zend_bool normalized;
	zval *index_param = NULL, *type_param = NULL, *normalized_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long index, type, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(type)
		Z_PARAM_BOOL(normalized)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &type_param, &normalized_param, &value_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, type);
	ZVAL_BOOL(&_2, (normalized ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl33_glvertexattribp4ui(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP4uiv)
{
	zend_bool normalized;
	zval *index_param = NULL, *type_param = NULL, *normalized_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long index, type, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(type)
		Z_PARAM_BOOL(normalized)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &type_param, &normalized_param, &value_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, type);
	ZVAL_BOOL(&_2, (normalized ? 1 : 0));
	ZVAL_LONG(&_3, value);
	phpgl_gl33_glvertexattribp4uiv(&_0, &_1, &_2, &_3);
}

