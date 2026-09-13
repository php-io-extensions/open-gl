
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
#include "src/gl-32.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL32_GL32)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL32, GL32, opengl, gl_gl32_gl32, opengl_gl_gl32_gl32_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glDrawElementsBaseVertex)
{
	zval *mode_param = NULL, *count_param = NULL, *type_param = NULL, *indices_param = NULL, *basevertex_param = NULL, _0, _1, _2, _3, _4;
	zend_long mode, count, type, indices, basevertex;

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
		Z_PARAM_LONG(basevertex)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &mode_param, &count_param, &type_param, &indices_param, &basevertex_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, type);
	ZVAL_LONG(&_3, indices);
	ZVAL_LONG(&_4, basevertex);
	phpgl_gl32_gldrawelementsbasevertex(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glDrawRangeElementsBaseVertex)
{
	zval *mode_param = NULL, *start_param = NULL, *end_param = NULL, *count_param = NULL, *type_param = NULL, *indices_param = NULL, *basevertex_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long mode, start, end, count, type, indices, basevertex;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(start)
		Z_PARAM_LONG(end)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(indices)
		Z_PARAM_LONG(basevertex)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &mode_param, &start_param, &end_param, &count_param, &type_param, &indices_param, &basevertex_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, start);
	ZVAL_LONG(&_2, end);
	ZVAL_LONG(&_3, count);
	ZVAL_LONG(&_4, type);
	ZVAL_LONG(&_5, indices);
	ZVAL_LONG(&_6, basevertex);
	phpgl_gl32_gldrawrangeelementsbasevertex(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glDrawElementsInstancedBaseVertex)
{
	zval *mode_param = NULL, *count_param = NULL, *type_param = NULL, *indices_param = NULL, *instancecount_param = NULL, *basevertex_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long mode, count, type, indices, instancecount, basevertex;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(indices)
		Z_PARAM_LONG(instancecount)
		Z_PARAM_LONG(basevertex)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &mode_param, &count_param, &type_param, &indices_param, &instancecount_param, &basevertex_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, type);
	ZVAL_LONG(&_3, indices);
	ZVAL_LONG(&_4, instancecount);
	ZVAL_LONG(&_5, basevertex);
	phpgl_gl32_gldrawelementsinstancedbasevertex(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glMultiDrawElementsBaseVertex)
{
	zval *mode_param = NULL, *count_param = NULL, *type_param = NULL, *indices_param = NULL, *drawcount_param = NULL, *basevertex_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long mode, count, type, indices, drawcount, basevertex;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(indices)
		Z_PARAM_LONG(drawcount)
		Z_PARAM_LONG(basevertex)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &mode_param, &count_param, &type_param, &indices_param, &drawcount_param, &basevertex_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, type);
	ZVAL_LONG(&_3, indices);
	ZVAL_LONG(&_4, drawcount);
	ZVAL_LONG(&_5, basevertex);
	phpgl_gl32_glmultidrawelementsbasevertex(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glProvokingVertex)
{
	zval *mode_param = NULL, _0;
	zend_long mode;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mode_param);
	ZVAL_LONG(&_0, mode);
	phpgl_gl32_glprovokingvertex(&_0);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glFenceSync)
{
	zval *condition_param = NULL, *flags_param = NULL, _0, _1;
	zend_long condition, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(condition)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &condition_param, &flags_param);
	ZVAL_LONG(&_0, condition);
	ZVAL_LONG(&_1, flags);
	RETURN_LONG(phpgl_gl32_glfencesync(&_0, &_1));
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glIsSync)
{
	zval *sync_param = NULL, _0;
	zend_long sync, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(sync)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &sync_param);
	ZVAL_LONG(&_0, sync);
	r = phpgl_gl32_glissync(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glDeleteSync)
{
	zval *sync_param = NULL, _0;
	zend_long sync;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(sync)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &sync_param);
	ZVAL_LONG(&_0, sync);
	phpgl_gl32_gldeletesync(&_0);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glClientWaitSync)
{
	zval *sync_param = NULL, *flags_param = NULL, *timeout_param = NULL, _0, _1, _2;
	zend_long sync, flags, timeout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sync)
		Z_PARAM_LONG(flags)
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sync_param, &flags_param, &timeout_param);
	ZVAL_LONG(&_0, sync);
	ZVAL_LONG(&_1, flags);
	ZVAL_LONG(&_2, timeout);
	RETURN_LONG(phpgl_gl32_glclientwaitsync(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glWaitSync)
{
	zval *sync_param = NULL, *flags_param = NULL, *timeout_param = NULL, _0, _1, _2;
	zend_long sync, flags, timeout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sync)
		Z_PARAM_LONG(flags)
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &sync_param, &flags_param, &timeout_param);
	ZVAL_LONG(&_0, sync);
	ZVAL_LONG(&_1, flags);
	ZVAL_LONG(&_2, timeout);
	phpgl_gl32_glwaitsync(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glGetInteger64v)
{
	zval *pname_param = NULL, *data_param = NULL, _0, _1;
	zend_long pname, data;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &data_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, data);
	phpgl_gl32_glgetinteger64v(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glGetSynciv)
{
	zval *sync_param = NULL, *pname_param = NULL, *count_param = NULL, *length_param = NULL, *values_param = NULL, _0, _1, _2, _3, _4;
	zend_long sync, pname, count, length, values;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(sync)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(values)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &sync_param, &pname_param, &count_param, &length_param, &values_param);
	ZVAL_LONG(&_0, sync);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, length);
	ZVAL_LONG(&_4, values);
	phpgl_gl32_glgetsynciv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glGetInteger64i_v)
{
	zval *target_param = NULL, *index_param = NULL, *data_param = NULL, _0, _1, _2;
	zend_long target, index, data;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &index_param, &data_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, index);
	ZVAL_LONG(&_2, data);
	phpgl_gl32_glgetinteger64i_v(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glGetBufferParameteri64v)
{
	zval *target_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long target, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl32_glgetbufferparameteri64v(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glFramebufferTexture)
{
	zval *target_param = NULL, *attachment_param = NULL, *texture_param = NULL, *level_param = NULL, _0, _1, _2, _3;
	zend_long target, attachment, texture, level;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(attachment)
		Z_PARAM_LONG(texture)
		Z_PARAM_LONG(level)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &attachment_param, &texture_param, &level_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, attachment);
	ZVAL_LONG(&_2, texture);
	ZVAL_LONG(&_3, level);
	phpgl_gl32_glframebuffertexture(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glTexImage2DMultisample)
{
	zend_bool fixedsamplelocations;
	zval *target_param = NULL, *samples_param = NULL, *internalformat_param = NULL, *width_param = NULL, *height_param = NULL, *fixedsamplelocations_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long target, samples, internalformat, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(samples)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_BOOL(fixedsamplelocations)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &target_param, &samples_param, &internalformat_param, &width_param, &height_param, &fixedsamplelocations_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, samples);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, height);
	ZVAL_BOOL(&_5, (fixedsamplelocations ? 1 : 0));
	phpgl_gl32_glteximage2dmultisample(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glTexImage3DMultisample)
{
	zend_bool fixedsamplelocations;
	zval *target_param = NULL, *samples_param = NULL, *internalformat_param = NULL, *width_param = NULL, *height_param = NULL, *depth_param = NULL, *fixedsamplelocations_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long target, samples, internalformat, width, height, depth;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(samples)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(depth)
		Z_PARAM_BOOL(fixedsamplelocations)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &target_param, &samples_param, &internalformat_param, &width_param, &height_param, &depth_param, &fixedsamplelocations_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, samples);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, height);
	ZVAL_LONG(&_5, depth);
	ZVAL_BOOL(&_6, (fixedsamplelocations ? 1 : 0));
	phpgl_gl32_glteximage3dmultisample(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glGetMultisamplefv)
{
	zval *pname_param = NULL, *index_param = NULL, *val_param = NULL, _0, _1, _2;
	zend_long pname, index, val;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(val)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &pname_param, &index_param, &val_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, index);
	ZVAL_LONG(&_2, val);
	phpgl_gl32_glgetmultisamplefv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL32_GL32, glSampleMaski)
{
	zval *maskNumber_param = NULL, *mask_param = NULL, _0, _1;
	zend_long maskNumber, mask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(maskNumber)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &maskNumber_param, &mask_param);
	ZVAL_LONG(&_0, maskNumber);
	ZVAL_LONG(&_1, mask);
	phpgl_gl32_glsamplemaski(&_0, &_1);
}

