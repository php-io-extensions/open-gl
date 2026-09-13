
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
#include "src/gl-20.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL20_GL20)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL20, GL20, opengl, gl_gl20_gl20, opengl_gl_gl20_gl20_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glBlendEquationSeparate)
{
	zval *modeRGB_param = NULL, *modeAlpha_param = NULL, _0, _1;
	zend_long modeRGB, modeAlpha;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(modeRGB)
		Z_PARAM_LONG(modeAlpha)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &modeRGB_param, &modeAlpha_param);
	ZVAL_LONG(&_0, modeRGB);
	ZVAL_LONG(&_1, modeAlpha);
	phpgl_gl20_glblendequationseparate(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glDrawBuffers)
{
	zval *n_param = NULL, *bufs_param = NULL, _0, _1;
	zend_long n, bufs;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(bufs)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &bufs_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, bufs);
	phpgl_gl20_gldrawbuffers(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glStencilOpSeparate)
{
	zval *face_param = NULL, *sfail_param = NULL, *dpfail_param = NULL, *dppass_param = NULL, _0, _1, _2, _3;
	zend_long face, sfail, dpfail, dppass;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(face)
		Z_PARAM_LONG(sfail)
		Z_PARAM_LONG(dpfail)
		Z_PARAM_LONG(dppass)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &face_param, &sfail_param, &dpfail_param, &dppass_param);
	ZVAL_LONG(&_0, face);
	ZVAL_LONG(&_1, sfail);
	ZVAL_LONG(&_2, dpfail);
	ZVAL_LONG(&_3, dppass);
	phpgl_gl20_glstencilopseparate(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glStencilFuncSeparate)
{
	zval *face_param = NULL, *func_param = NULL, *ref_param = NULL, *mask_param = NULL, _0, _1, _2, _3;
	zend_long face, func, ref, mask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(face)
		Z_PARAM_LONG(func)
		Z_PARAM_LONG(ref)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &face_param, &func_param, &ref_param, &mask_param);
	ZVAL_LONG(&_0, face);
	ZVAL_LONG(&_1, func);
	ZVAL_LONG(&_2, ref);
	ZVAL_LONG(&_3, mask);
	phpgl_gl20_glstencilfuncseparate(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glStencilMaskSeparate)
{
	zval *face_param = NULL, *mask_param = NULL, _0, _1;
	zend_long face, mask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(face)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &face_param, &mask_param);
	ZVAL_LONG(&_0, face);
	ZVAL_LONG(&_1, mask);
	phpgl_gl20_glstencilmaskseparate(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glAttachShader)
{
	zval *program_param = NULL, *shader_param = NULL, _0, _1;
	zend_long program, shader;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(shader)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &program_param, &shader_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, shader);
	phpgl_gl20_glattachshader(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glBindAttribLocation)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *program_param = NULL, *index_param = NULL, *name_param = NULL, _0, _1;
	zend_long program, index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(index)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &program_param, &index_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, index);
	phpgl_gl20_glbindattriblocation(&_0, &_1, &name);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glCompileShader)
{
	zval *shader_param = NULL, _0;
	zend_long shader;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(shader)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &shader_param);
	ZVAL_LONG(&_0, shader);
	phpgl_gl20_glcompileshader(&_0);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glCreateProgram)
{

	RETURN_LONG(phpgl_gl20_glcreateprogram());
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glCreateShader)
{
	zval *type_param = NULL, _0;
	zend_long type;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &type_param);
	ZVAL_LONG(&_0, type);
	RETURN_LONG(phpgl_gl20_glcreateshader(&_0));
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glDeleteProgram)
{
	zval *program_param = NULL, _0;
	zend_long program;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &program_param);
	ZVAL_LONG(&_0, program);
	phpgl_gl20_gldeleteprogram(&_0);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glDeleteShader)
{
	zval *shader_param = NULL, _0;
	zend_long shader;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(shader)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &shader_param);
	ZVAL_LONG(&_0, shader);
	phpgl_gl20_gldeleteshader(&_0);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glDetachShader)
{
	zval *program_param = NULL, *shader_param = NULL, _0, _1;
	zend_long program, shader;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(shader)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &program_param, &shader_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, shader);
	phpgl_gl20_gldetachshader(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glDisableVertexAttribArray)
{
	zval *index_param = NULL, _0;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &index_param);
	ZVAL_LONG(&_0, index);
	phpgl_gl20_gldisablevertexattribarray(&_0);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glEnableVertexAttribArray)
{
	zval *index_param = NULL, _0;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &index_param);
	ZVAL_LONG(&_0, index);
	phpgl_gl20_glenablevertexattribarray(&_0);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetActiveAttrib)
{
	zval *program_param = NULL, *index_param = NULL, *bufSize_param = NULL, *length_param = NULL, *size_param = NULL, *type_param = NULL, *name_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long program, index, bufSize, length, size, type, name;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &program_param, &index_param, &bufSize_param, &length_param, &size_param, &type_param, &name_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, index);
	ZVAL_LONG(&_2, bufSize);
	ZVAL_LONG(&_3, length);
	ZVAL_LONG(&_4, size);
	ZVAL_LONG(&_5, type);
	ZVAL_LONG(&_6, name);
	phpgl_gl20_glgetactiveattrib(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetActiveUniform)
{
	zval *program_param = NULL, *index_param = NULL, *bufSize_param = NULL, *length_param = NULL, *size_param = NULL, *type_param = NULL, *name_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long program, index, bufSize, length, size, type, name;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &program_param, &index_param, &bufSize_param, &length_param, &size_param, &type_param, &name_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, index);
	ZVAL_LONG(&_2, bufSize);
	ZVAL_LONG(&_3, length);
	ZVAL_LONG(&_4, size);
	ZVAL_LONG(&_5, type);
	ZVAL_LONG(&_6, name);
	phpgl_gl20_glgetactiveuniform(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetAttachedShaders)
{
	zval *program_param = NULL, *maxCount_param = NULL, *count_param = NULL, *shaders_param = NULL, _0, _1, _2, _3;
	zend_long program, maxCount, count, shaders;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(maxCount)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(shaders)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &maxCount_param, &count_param, &shaders_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, maxCount);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, shaders);
	phpgl_gl20_glgetattachedshaders(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetAttribLocation)
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
	RETURN_MM_LONG(phpgl_gl20_glgetattriblocation(&_0, &name));
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetProgramiv)
{
	zval *program_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long program, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &program_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl20_glgetprogramiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetProgramInfoLog)
{
	zval *program_param = NULL, *bufSize_param = NULL, *length_param = NULL, *infoLog_param = NULL, _0, _1, _2, _3;
	zend_long program, bufSize, length, infoLog;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(infoLog)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &bufSize_param, &length_param, &infoLog_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, bufSize);
	ZVAL_LONG(&_2, length);
	ZVAL_LONG(&_3, infoLog);
	phpgl_gl20_glgetprograminfolog(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetShaderiv)
{
	zval *shader_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long shader, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(shader)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &shader_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, shader);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl20_glgetshaderiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetShaderInfoLog)
{
	zval *shader_param = NULL, *bufSize_param = NULL, *length_param = NULL, *infoLog_param = NULL, _0, _1, _2, _3;
	zend_long shader, bufSize, length, infoLog;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(shader)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(infoLog)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &shader_param, &bufSize_param, &length_param, &infoLog_param);
	ZVAL_LONG(&_0, shader);
	ZVAL_LONG(&_1, bufSize);
	ZVAL_LONG(&_2, length);
	ZVAL_LONG(&_3, infoLog);
	phpgl_gl20_glgetshaderinfolog(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetShaderSource)
{
	zval *shader_param = NULL, *bufSize_param = NULL, *length_param = NULL, *source_param = NULL, _0, _1, _2, _3;
	zend_long shader, bufSize, length, source;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(shader)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(source)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &shader_param, &bufSize_param, &length_param, &source_param);
	ZVAL_LONG(&_0, shader);
	ZVAL_LONG(&_1, bufSize);
	ZVAL_LONG(&_2, length);
	ZVAL_LONG(&_3, source);
	phpgl_gl20_glgetshadersource(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetUniformLocation)
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
	RETURN_MM_LONG(phpgl_gl20_glgetuniformlocation(&_0, &name));
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetUniformfv)
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
	phpgl_gl20_glgetuniformfv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetUniformiv)
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
	phpgl_gl20_glgetuniformiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetVertexAttribdv)
{
	zval *index_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long index, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &index_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl20_glgetvertexattribdv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetVertexAttribfv)
{
	zval *index_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long index, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &index_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl20_glgetvertexattribfv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetVertexAttribiv)
{
	zval *index_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long index, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &index_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl20_glgetvertexattribiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glGetVertexAttribPointerv)
{
	zval *index_param = NULL, *pname_param = NULL, *pointer_param = NULL, _0, _1, _2;
	zend_long index, pname, pointer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(pointer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &index_param, &pname_param, &pointer_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, pointer);
	phpgl_gl20_glgetvertexattribpointerv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glIsProgram)
{
	zval *program_param = NULL, _0;
	zend_long program, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &program_param);
	ZVAL_LONG(&_0, program);
	r = phpgl_gl20_glisprogram(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glIsShader)
{
	zval *shader_param = NULL, _0;
	zend_long shader, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(shader)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &shader_param);
	ZVAL_LONG(&_0, shader);
	r = phpgl_gl20_glisshader(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glLinkProgram)
{
	zval *program_param = NULL, _0;
	zend_long program;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &program_param);
	ZVAL_LONG(&_0, program);
	phpgl_gl20_gllinkprogram(&_0);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glShaderSource)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval string_;
	zval *shader_param = NULL, *count_param = NULL, *string__param = NULL, *length_param = NULL, _0, _1, _2;
	zend_long shader, count, length;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&string_);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(shader)
		Z_PARAM_LONG(count)
		Z_PARAM_ARRAY(string_)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &shader_param, &count_param, &string__param, &length_param);
	zephir_get_arrval(&string_, string__param);
	ZVAL_LONG(&_0, shader);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, length);
	phpgl_gl20_glshadersource(&_0, &_1, &string_, &_2);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUseProgram)
{
	zval *program_param = NULL, _0;
	zend_long program;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &program_param);
	ZVAL_LONG(&_0, program);
	phpgl_gl20_gluseprogram(&_0);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform1f)
{
	double v0;
	zval *location_param = NULL, *v0_param = NULL, _0, _1;
	zend_long location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &location_param, &v0_param);
	v0 = zephir_get_doubleval(v0_param);
	ZVAL_LONG(&_0, location);
	ZVAL_DOUBLE(&_1, v0);
	phpgl_gl20_gluniform1f(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform2f)
{
	double v0, v1;
	zval *location_param = NULL, *v0_param = NULL, *v1_param = NULL, _0, _1, _2;
	zend_long location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
		Z_PARAM_ZVAL(v1)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &location_param, &v0_param, &v1_param);
	v0 = zephir_get_doubleval(v0_param);
	v1 = zephir_get_doubleval(v1_param);
	ZVAL_LONG(&_0, location);
	ZVAL_DOUBLE(&_1, v0);
	ZVAL_DOUBLE(&_2, v1);
	phpgl_gl20_gluniform2f(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform3f)
{
	double v0, v1, v2;
	zval *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, _0, _1, _2, _3;
	zend_long location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
		Z_PARAM_ZVAL(v1)
		Z_PARAM_ZVAL(v2)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &v0_param, &v1_param, &v2_param);
	v0 = zephir_get_doubleval(v0_param);
	v1 = zephir_get_doubleval(v1_param);
	v2 = zephir_get_doubleval(v2_param);
	ZVAL_LONG(&_0, location);
	ZVAL_DOUBLE(&_1, v0);
	ZVAL_DOUBLE(&_2, v1);
	ZVAL_DOUBLE(&_3, v2);
	phpgl_gl20_gluniform3f(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform4f)
{
	double v0, v1, v2, v3;
	zval *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, *v3_param = NULL, _0, _1, _2, _3, _4;
	zend_long location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
		Z_PARAM_ZVAL(v1)
		Z_PARAM_ZVAL(v2)
		Z_PARAM_ZVAL(v3)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &location_param, &v0_param, &v1_param, &v2_param, &v3_param);
	v0 = zephir_get_doubleval(v0_param);
	v1 = zephir_get_doubleval(v1_param);
	v2 = zephir_get_doubleval(v2_param);
	v3 = zephir_get_doubleval(v3_param);
	ZVAL_LONG(&_0, location);
	ZVAL_DOUBLE(&_1, v0);
	ZVAL_DOUBLE(&_2, v1);
	ZVAL_DOUBLE(&_3, v2);
	ZVAL_DOUBLE(&_4, v3);
	phpgl_gl20_gluniform4f(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform1i)
{
	zval *location_param = NULL, *v0_param = NULL, _0, _1;
	zend_long location, v0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &location_param, &v0_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, v0);
	phpgl_gl20_gluniform1i(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform2i)
{
	zval *location_param = NULL, *v0_param = NULL, *v1_param = NULL, _0, _1, _2;
	zend_long location, v0, v1;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
		Z_PARAM_LONG(v1)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &location_param, &v0_param, &v1_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, v0);
	ZVAL_LONG(&_2, v1);
	phpgl_gl20_gluniform2i(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform3i)
{
	zval *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, _0, _1, _2, _3;
	zend_long location, v0, v1, v2;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
		Z_PARAM_LONG(v1)
		Z_PARAM_LONG(v2)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &location_param, &v0_param, &v1_param, &v2_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, v0);
	ZVAL_LONG(&_2, v1);
	ZVAL_LONG(&_3, v2);
	phpgl_gl20_gluniform3i(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform4i)
{
	zval *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, *v3_param = NULL, _0, _1, _2, _3, _4;
	zend_long location, v0, v1, v2, v3;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
		Z_PARAM_LONG(v1)
		Z_PARAM_LONG(v2)
		Z_PARAM_LONG(v3)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &location_param, &v0_param, &v1_param, &v2_param, &v3_param);
	ZVAL_LONG(&_0, location);
	ZVAL_LONG(&_1, v0);
	ZVAL_LONG(&_2, v1);
	ZVAL_LONG(&_3, v2);
	ZVAL_LONG(&_4, v3);
	phpgl_gl20_gluniform4i(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform1fv)
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
	phpgl_gl20_gluniform1fv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform2fv)
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
	phpgl_gl20_gluniform2fv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform3fv)
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
	phpgl_gl20_gluniform3fv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform4fv)
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
	phpgl_gl20_gluniform4fv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform1iv)
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
	phpgl_gl20_gluniform1iv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform2iv)
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
	phpgl_gl20_gluniform2iv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform3iv)
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
	phpgl_gl20_gluniform3iv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniform4iv)
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
	phpgl_gl20_gluniform4iv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniformMatrix2fv)
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
	phpgl_gl20_gluniformmatrix2fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniformMatrix3fv)
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
	phpgl_gl20_gluniformmatrix3fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glUniformMatrix4fv)
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
	phpgl_gl20_gluniformmatrix4fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glValidateProgram)
{
	zval *program_param = NULL, _0;
	zend_long program;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &program_param);
	ZVAL_LONG(&_0, program);
	phpgl_gl20_glvalidateprogram(&_0);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib1d)
{
	double x;
	zval *index_param = NULL, *x_param = NULL, _0, _1;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(x)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &x_param);
	x = zephir_get_doubleval(x_param);
	ZVAL_LONG(&_0, index);
	ZVAL_DOUBLE(&_1, x);
	phpgl_gl20_glvertexattrib1d(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib1dv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib1dv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib1f)
{
	double x;
	zval *index_param = NULL, *x_param = NULL, _0, _1;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(x)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &x_param);
	x = zephir_get_doubleval(x_param);
	ZVAL_LONG(&_0, index);
	ZVAL_DOUBLE(&_1, x);
	phpgl_gl20_glvertexattrib1f(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib1fv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib1fv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib1s)
{
	zval *index_param = NULL, *x_param = NULL, _0, _1;
	zend_long index, x;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(x)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &x_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, x);
	phpgl_gl20_glvertexattrib1s(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib1sv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib1sv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib2d)
{
	double x, y;
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, _0, _1, _2;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &index_param, &x_param, &y_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	ZVAL_LONG(&_0, index);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	phpgl_gl20_glvertexattrib2d(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib2dv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib2dv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib2f)
{
	double x, y;
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, _0, _1, _2;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &index_param, &x_param, &y_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	ZVAL_LONG(&_0, index);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	phpgl_gl20_glvertexattrib2f(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib2fv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib2fv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib2s)
{
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, _0, _1, _2;
	zend_long index, x, y;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &index_param, &x_param, &y_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, x);
	ZVAL_LONG(&_2, y);
	phpgl_gl20_glvertexattrib2s(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib2sv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib2sv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib3d)
{
	double x, y, z;
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, *z_param = NULL, _0, _1, _2, _3;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_ZVAL(z)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &x_param, &y_param, &z_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);
	ZVAL_LONG(&_0, index);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	ZVAL_DOUBLE(&_3, z);
	phpgl_gl20_glvertexattrib3d(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib3dv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib3dv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib3f)
{
	double x, y, z;
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, *z_param = NULL, _0, _1, _2, _3;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_ZVAL(z)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &x_param, &y_param, &z_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);
	ZVAL_LONG(&_0, index);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	ZVAL_DOUBLE(&_3, z);
	phpgl_gl20_glvertexattrib3f(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib3fv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib3fv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib3s)
{
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, *z_param = NULL, _0, _1, _2, _3;
	zend_long index, x, y, z;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(z)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &index_param, &x_param, &y_param, &z_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, x);
	ZVAL_LONG(&_2, y);
	ZVAL_LONG(&_3, z);
	phpgl_gl20_glvertexattrib3s(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib3sv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib3sv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4Nbv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4nbv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4Niv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4niv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4Nsv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4nsv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4Nub)
{
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, *z_param = NULL, *w_param = NULL, _0, _1, _2, _3, _4;
	zend_long index, x, y, z, w;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(z)
		Z_PARAM_LONG(w)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &index_param, &x_param, &y_param, &z_param, &w_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, x);
	ZVAL_LONG(&_2, y);
	ZVAL_LONG(&_3, z);
	ZVAL_LONG(&_4, w);
	phpgl_gl20_glvertexattrib4nub(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4Nubv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4nubv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4Nuiv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4nuiv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4Nusv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4nusv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4bv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4bv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4d)
{
	double x, y, z, w;
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, *z_param = NULL, *w_param = NULL, _0, _1, _2, _3, _4;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_ZVAL(z)
		Z_PARAM_ZVAL(w)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &index_param, &x_param, &y_param, &z_param, &w_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);
	w = zephir_get_doubleval(w_param);
	ZVAL_LONG(&_0, index);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	ZVAL_DOUBLE(&_3, z);
	ZVAL_DOUBLE(&_4, w);
	phpgl_gl20_glvertexattrib4d(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4dv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4dv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4f)
{
	double x, y, z, w;
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, *z_param = NULL, *w_param = NULL, _0, _1, _2, _3, _4;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_ZVAL(z)
		Z_PARAM_ZVAL(w)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &index_param, &x_param, &y_param, &z_param, &w_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);
	w = zephir_get_doubleval(w_param);
	ZVAL_LONG(&_0, index);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	ZVAL_DOUBLE(&_3, z);
	ZVAL_DOUBLE(&_4, w);
	phpgl_gl20_glvertexattrib4f(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4fv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4fv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4iv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4iv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4s)
{
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, *z_param = NULL, *w_param = NULL, _0, _1, _2, _3, _4;
	zend_long index, x, y, z, w;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(z)
		Z_PARAM_LONG(w)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &index_param, &x_param, &y_param, &z_param, &w_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, x);
	ZVAL_LONG(&_2, y);
	ZVAL_LONG(&_3, z);
	ZVAL_LONG(&_4, w);
	phpgl_gl20_glvertexattrib4s(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4sv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4sv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4ubv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4ubv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4uiv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4uiv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttrib4usv)
{
	zval *index_param = NULL, *v_param = NULL, _0, _1;
	zend_long index, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &index_param, &v_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, v);
	phpgl_gl20_glvertexattrib4usv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL20_GL20, glVertexAttribPointer)
{
	zend_bool normalized;
	zval *index_param = NULL, *size_param = NULL, *type_param = NULL, *normalized_param = NULL, *stride_param = NULL, *pointer_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long index, size, type, stride, pointer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(type)
		Z_PARAM_BOOL(normalized)
		Z_PARAM_LONG(stride)
		Z_PARAM_LONG(pointer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &index_param, &size_param, &type_param, &normalized_param, &stride_param, &pointer_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, size);
	ZVAL_LONG(&_2, type);
	ZVAL_BOOL(&_3, (normalized ? 1 : 0));
	ZVAL_LONG(&_4, stride);
	ZVAL_LONG(&_5, pointer);
	phpgl_gl20_glvertexattribpointer(&_0, &_1, &_2, &_3, &_4, &_5);
}

