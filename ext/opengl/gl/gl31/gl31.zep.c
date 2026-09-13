
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
#include "src/gl-31.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL31_GL31)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL31, GL31, opengl, gl_gl31_gl31, opengl_gl_gl31_gl31_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glDrawArraysInstanced)
{
	zval *mode_param = NULL, *first_param = NULL, *count_param = NULL, *instancecount_param = NULL, _0, _1, _2, _3;
	zend_long mode, first, count, instancecount;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(first)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(instancecount)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &mode_param, &first_param, &count_param, &instancecount_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, first);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, instancecount);
	phpgl_gl31_gldrawarraysinstanced(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glDrawElementsInstanced)
{
	zval *mode_param = NULL, *count_param = NULL, *type_param = NULL, *indices_param = NULL, *instancecount_param = NULL, _0, _1, _2, _3, _4;
	zend_long mode, count, type, indices, instancecount;

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
		Z_PARAM_LONG(instancecount)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &mode_param, &count_param, &type_param, &indices_param, &instancecount_param);
	ZVAL_LONG(&_0, mode);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, type);
	ZVAL_LONG(&_3, indices);
	ZVAL_LONG(&_4, instancecount);
	phpgl_gl31_gldrawelementsinstanced(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glTexBuffer)
{
	zval *target_param = NULL, *internalformat_param = NULL, *buffer_param = NULL, _0, _1, _2;
	zend_long target, internalformat, buffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &internalformat_param, &buffer_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, internalformat);
	ZVAL_LONG(&_2, buffer);
	phpgl_gl31_gltexbuffer(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glPrimitiveRestartIndex)
{
	zval *index_param = NULL, _0;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &index_param);
	ZVAL_LONG(&_0, index);
	phpgl_gl31_glprimitiverestartindex(&_0);
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glCopyBufferSubData)
{
	zval *readTarget_param = NULL, *writeTarget_param = NULL, *readOffset_param = NULL, *writeOffset_param = NULL, *size_param = NULL, _0, _1, _2, _3, _4;
	zend_long readTarget, writeTarget, readOffset, writeOffset, size;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(readTarget)
		Z_PARAM_LONG(writeTarget)
		Z_PARAM_LONG(readOffset)
		Z_PARAM_LONG(writeOffset)
		Z_PARAM_LONG(size)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &readTarget_param, &writeTarget_param, &readOffset_param, &writeOffset_param, &size_param);
	ZVAL_LONG(&_0, readTarget);
	ZVAL_LONG(&_1, writeTarget);
	ZVAL_LONG(&_2, readOffset);
	ZVAL_LONG(&_3, writeOffset);
	ZVAL_LONG(&_4, size);
	phpgl_gl31_glcopybuffersubdata(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glGetUniformIndices)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval uniformNames;
	zval *program_param = NULL, *uniformCount_param = NULL, *uniformNames_param = NULL, *uniformIndices_param = NULL, _0, _1, _2;
	zend_long program, uniformCount, uniformIndices;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&uniformNames);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(uniformCount)
		Z_PARAM_ARRAY(uniformNames)
		Z_PARAM_LONG(uniformIndices)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &program_param, &uniformCount_param, &uniformNames_param, &uniformIndices_param);
	zephir_get_arrval(&uniformNames, uniformNames_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, uniformCount);
	ZVAL_LONG(&_2, uniformIndices);
	phpgl_gl31_glgetuniformindices(&_0, &_1, &uniformNames, &_2);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glGetActiveUniformsiv)
{
	zval *program_param = NULL, *uniformCount_param = NULL, *uniformIndices_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, uniformCount, uniformIndices, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(uniformCount)
		Z_PARAM_LONG(uniformIndices)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &uniformCount_param, &uniformIndices_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, uniformCount);
	ZVAL_LONG(&_2, uniformIndices);
	ZVAL_LONG(&_3, pname);
	ZVAL_LONG(&_4, params);
	phpgl_gl31_glgetactiveuniformsiv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glGetActiveUniformName)
{
	zval *program_param = NULL, *uniformIndex_param = NULL, *bufSize_param = NULL, *length_param = NULL, *uniformName_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, uniformIndex, bufSize, length, uniformName;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(uniformIndex)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(uniformName)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &uniformIndex_param, &bufSize_param, &length_param, &uniformName_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, uniformIndex);
	ZVAL_LONG(&_2, bufSize);
	ZVAL_LONG(&_3, length);
	ZVAL_LONG(&_4, uniformName);
	phpgl_gl31_glgetactiveuniformname(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glGetUniformBlockIndex)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval uniformBlockName;
	zval *program_param = NULL, *uniformBlockName_param = NULL, _0;
	zend_long program;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&uniformBlockName);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(program)
		Z_PARAM_STR(uniformBlockName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &program_param, &uniformBlockName_param);
	zephir_get_strval(&uniformBlockName, uniformBlockName_param);
	ZVAL_LONG(&_0, program);
	RETURN_MM_LONG(phpgl_gl31_glgetuniformblockindex(&_0, &uniformBlockName));
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glGetActiveUniformBlockiv)
{
	zval *program_param = NULL, *uniformBlockIndex_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2, _3;
	zend_long program, uniformBlockIndex, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(uniformBlockIndex)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &uniformBlockIndex_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, uniformBlockIndex);
	ZVAL_LONG(&_2, pname);
	ZVAL_LONG(&_3, params);
	phpgl_gl31_glgetactiveuniformblockiv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glGetActiveUniformBlockName)
{
	zval *program_param = NULL, *uniformBlockIndex_param = NULL, *bufSize_param = NULL, *length_param = NULL, *uniformBlockName_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, uniformBlockIndex, bufSize, length, uniformBlockName;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(uniformBlockIndex)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(uniformBlockName)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &uniformBlockIndex_param, &bufSize_param, &length_param, &uniformBlockName_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, uniformBlockIndex);
	ZVAL_LONG(&_2, bufSize);
	ZVAL_LONG(&_3, length);
	ZVAL_LONG(&_4, uniformBlockName);
	phpgl_gl31_glgetactiveuniformblockname(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL31_GL31, glUniformBlockBinding)
{
	zval *program_param = NULL, *uniformBlockIndex_param = NULL, *uniformBlockBinding_param = NULL, _0, _1, _2;
	zend_long program, uniformBlockIndex, uniformBlockBinding;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(uniformBlockIndex)
		Z_PARAM_LONG(uniformBlockBinding)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &program_param, &uniformBlockIndex_param, &uniformBlockBinding_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, uniformBlockIndex);
	ZVAL_LONG(&_2, uniformBlockBinding);
	phpgl_gl31_gluniformblockbinding(&_0, &_1, &_2);
}

