
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
#include "src/gl-41.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL41_GL41)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL41, GL41, opengl, gl_gl41_gl41, opengl_gl_gl41_gl41_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glReleaseShaderCompiler)
{

	phpgl_gl41_glreleaseshadercompiler();
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glShaderBinary)
{
	zval *count_param = NULL, *shaders_param = NULL, *binaryFormat_param = NULL, *binary_param = NULL, *length_param = NULL, _0, _1, _2, _3, _4;
	zend_long count, shaders, binaryFormat, binary, length;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(shaders)
		Z_PARAM_LONG(binaryFormat)
		Z_PARAM_LONG(binary)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &count_param, &shaders_param, &binaryFormat_param, &binary_param, &length_param);
	ZVAL_LONG(&_0, count);
	ZVAL_LONG(&_1, shaders);
	ZVAL_LONG(&_2, binaryFormat);
	ZVAL_LONG(&_3, binary);
	ZVAL_LONG(&_4, length);
	phpgl_gl41_glshaderbinary(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glGetShaderPrecisionFormat)
{
	zval *shadertype_param = NULL, *precisiontype_param = NULL, *range_param = NULL, *precision_param = NULL, _0, _1, _2, _3;
	zend_long shadertype, precisiontype, range, precision;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(shadertype)
		Z_PARAM_LONG(precisiontype)
		Z_PARAM_LONG(range)
		Z_PARAM_LONG(precision)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &shadertype_param, &precisiontype_param, &range_param, &precision_param);
	ZVAL_LONG(&_0, shadertype);
	ZVAL_LONG(&_1, precisiontype);
	ZVAL_LONG(&_2, range);
	ZVAL_LONG(&_3, precision);
	phpgl_gl41_glgetshaderprecisionformat(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glDepthRangef)
{
	zval *n_param = NULL, *f_param = NULL, _0, _1;
	double n, f;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(n)
		Z_PARAM_ZVAL(f)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &f_param);
	n = zephir_get_doubleval(n_param);
	f = zephir_get_doubleval(f_param);
	ZVAL_DOUBLE(&_0, n);
	ZVAL_DOUBLE(&_1, f);
	phpgl_gl41_gldepthrangef(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glClearDepthf)
{
	zval *d_param = NULL, _0;
	double d;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(d)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &d_param);
	d = zephir_get_doubleval(d_param);
	ZVAL_DOUBLE(&_0, d);
	phpgl_gl41_glcleardepthf(&_0);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glGetProgramBinary)
{
	zval *program_param = NULL, *bufSize_param = NULL, *length_param = NULL, *binaryFormat_param = NULL, *binary_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, bufSize, length, binaryFormat, binary;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(binaryFormat)
		Z_PARAM_LONG(binary)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &bufSize_param, &length_param, &binaryFormat_param, &binary_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, bufSize);
	ZVAL_LONG(&_2, length);
	ZVAL_LONG(&_3, binaryFormat);
	ZVAL_LONG(&_4, binary);
	phpgl_gl41_glgetprogrambinary(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramBinary)
{
	zval *program_param = NULL, *binaryFormat_param = NULL, *binary_param = NULL, *length_param = NULL, _0, _1, _2, _3;
	zend_long program, binaryFormat, binary, length;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(binaryFormat)
		Z_PARAM_LONG(binary)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &binaryFormat_param, &binary_param, &length_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, binaryFormat);
	ZVAL_LONG(&_2, binary);
	ZVAL_LONG(&_3, length);
	phpgl_gl41_glprogrambinary(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramParameteri)
{
	zval *program_param = NULL, *pname_param = NULL, *value_param = NULL, _0, _1, _2;
	zend_long program, pname, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &program_param, &pname_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, value);
	phpgl_gl41_glprogramparameteri(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glUseProgramStages)
{
	zval *pipeline_param = NULL, *stages_param = NULL, *program_param = NULL, _0, _1, _2;
	zend_long pipeline, stages, program;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(pipeline)
		Z_PARAM_LONG(stages)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &pipeline_param, &stages_param, &program_param);
	ZVAL_LONG(&_0, pipeline);
	ZVAL_LONG(&_1, stages);
	ZVAL_LONG(&_2, program);
	phpgl_gl41_gluseprogramstages(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glActiveShaderProgram)
{
	zval *pipeline_param = NULL, *program_param = NULL, _0, _1;
	zend_long pipeline, program;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pipeline)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pipeline_param, &program_param);
	ZVAL_LONG(&_0, pipeline);
	ZVAL_LONG(&_1, program);
	phpgl_gl41_glactiveshaderprogram(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glCreateShaderProgramv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval strings;
	zval *type_param = NULL, *count_param = NULL, *strings_param = NULL, _0, _1;
	zend_long type, count;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&strings);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(count)
		Z_PARAM_ARRAY(strings)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &type_param, &count_param, &strings_param);
	zephir_get_arrval(&strings, strings_param);
	ZVAL_LONG(&_0, type);
	ZVAL_LONG(&_1, count);
	RETURN_MM_LONG(phpgl_gl41_glcreateshaderprogramv(&_0, &_1, &strings));
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glBindProgramPipeline)
{
	zval *pipeline_param = NULL, _0;
	zend_long pipeline;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pipeline)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pipeline_param);
	ZVAL_LONG(&_0, pipeline);
	phpgl_gl41_glbindprogrampipeline(&_0);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glDeleteProgramPipelines)
{
	zval *n_param = NULL, *pipelines_param = NULL, _0, _1;
	zend_long n, pipelines;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(pipelines)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &pipelines_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, pipelines);
	phpgl_gl41_gldeleteprogrampipelines(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glGenProgramPipelines)
{
	zval *n_param = NULL, *pipelines_param = NULL, _0, _1;
	zend_long n, pipelines;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(pipelines)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &pipelines_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, pipelines);
	phpgl_gl41_glgenprogrampipelines(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glIsProgramPipeline)
{
	zval *pipeline_param = NULL, _0;
	zend_long pipeline, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pipeline)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pipeline_param);
	ZVAL_LONG(&_0, pipeline);
	r = phpgl_gl41_glisprogrampipeline(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glGetProgramPipelineiv)
{
	zval *pipeline_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long pipeline, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(pipeline)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &pipeline_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, pipeline);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl41_glgetprogrampipelineiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform1i)
{
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, _0, _1, _2;
	zend_long program, location, v0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &program_param, &location_param, &v0_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, v0);
	phpgl_gl41_glprogramuniform1i(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform1iv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform1iv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform1f)
{
	double v0;
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, _0, _1, _2;
	zend_long program, location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &program_param, &location_param, &v0_param);
	v0 = zephir_get_doubleval(v0_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_DOUBLE(&_2, v0);
	phpgl_gl41_glprogramuniform1f(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform1fv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform1fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform1d)
{
	double v0;
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, _0, _1, _2;
	zend_long program, location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &program_param, &location_param, &v0_param);
	v0 = zephir_get_doubleval(v0_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_DOUBLE(&_2, v0);
	phpgl_gl41_glprogramuniform1d(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform1dv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform1dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform1ui)
{
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, _0, _1, _2;
	zend_long program, location, v0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &program_param, &location_param, &v0_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, v0);
	phpgl_gl41_glprogramuniform1ui(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform1uiv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform1uiv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform2i)
{
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, _0, _1, _2, _3;
	zend_long program, location, v0, v1;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
		Z_PARAM_LONG(v1)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &v0_param, &v1_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, v0);
	ZVAL_LONG(&_3, v1);
	phpgl_gl41_glprogramuniform2i(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform2iv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform2iv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform2f)
{
	double v0, v1;
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, _0, _1, _2, _3;
	zend_long program, location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
		Z_PARAM_ZVAL(v1)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &v0_param, &v1_param);
	v0 = zephir_get_doubleval(v0_param);
	v1 = zephir_get_doubleval(v1_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_DOUBLE(&_2, v0);
	ZVAL_DOUBLE(&_3, v1);
	phpgl_gl41_glprogramuniform2f(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform2fv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform2fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform2d)
{
	double v0, v1;
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, _0, _1, _2, _3;
	zend_long program, location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
		Z_PARAM_ZVAL(v1)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &v0_param, &v1_param);
	v0 = zephir_get_doubleval(v0_param);
	v1 = zephir_get_doubleval(v1_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_DOUBLE(&_2, v0);
	ZVAL_DOUBLE(&_3, v1);
	phpgl_gl41_glprogramuniform2d(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform2dv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform2dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform2ui)
{
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, _0, _1, _2, _3;
	zend_long program, location, v0, v1;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
		Z_PARAM_LONG(v1)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &v0_param, &v1_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, v0);
	ZVAL_LONG(&_3, v1);
	phpgl_gl41_glprogramuniform2ui(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform2uiv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform2uiv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform3i)
{
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, v0, v1, v2;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
		Z_PARAM_LONG(v1)
		Z_PARAM_LONG(v2)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &v0_param, &v1_param, &v2_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, v0);
	ZVAL_LONG(&_3, v1);
	ZVAL_LONG(&_4, v2);
	phpgl_gl41_glprogramuniform3i(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform3iv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform3iv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform3f)
{
	double v0, v1, v2;
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
		Z_PARAM_ZVAL(v1)
		Z_PARAM_ZVAL(v2)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &v0_param, &v1_param, &v2_param);
	v0 = zephir_get_doubleval(v0_param);
	v1 = zephir_get_doubleval(v1_param);
	v2 = zephir_get_doubleval(v2_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_DOUBLE(&_2, v0);
	ZVAL_DOUBLE(&_3, v1);
	ZVAL_DOUBLE(&_4, v2);
	phpgl_gl41_glprogramuniform3f(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform3fv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform3fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform3d)
{
	double v0, v1, v2;
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
		Z_PARAM_ZVAL(v1)
		Z_PARAM_ZVAL(v2)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &v0_param, &v1_param, &v2_param);
	v0 = zephir_get_doubleval(v0_param);
	v1 = zephir_get_doubleval(v1_param);
	v2 = zephir_get_doubleval(v2_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_DOUBLE(&_2, v0);
	ZVAL_DOUBLE(&_3, v1);
	ZVAL_DOUBLE(&_4, v2);
	phpgl_gl41_glprogramuniform3d(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform3dv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform3dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform3ui)
{
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, v0, v1, v2;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
		Z_PARAM_LONG(v1)
		Z_PARAM_LONG(v2)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &v0_param, &v1_param, &v2_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, v0);
	ZVAL_LONG(&_3, v1);
	ZVAL_LONG(&_4, v2);
	phpgl_gl41_glprogramuniform3ui(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform3uiv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform3uiv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform4i)
{
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, *v3_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long program, location, v0, v1, v2, v3;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
		Z_PARAM_LONG(v1)
		Z_PARAM_LONG(v2)
		Z_PARAM_LONG(v3)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &program_param, &location_param, &v0_param, &v1_param, &v2_param, &v3_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, v0);
	ZVAL_LONG(&_3, v1);
	ZVAL_LONG(&_4, v2);
	ZVAL_LONG(&_5, v3);
	phpgl_gl41_glprogramuniform4i(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform4iv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform4iv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform4f)
{
	double v0, v1, v2, v3;
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, *v3_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long program, location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
		Z_PARAM_ZVAL(v1)
		Z_PARAM_ZVAL(v2)
		Z_PARAM_ZVAL(v3)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &program_param, &location_param, &v0_param, &v1_param, &v2_param, &v3_param);
	v0 = zephir_get_doubleval(v0_param);
	v1 = zephir_get_doubleval(v1_param);
	v2 = zephir_get_doubleval(v2_param);
	v3 = zephir_get_doubleval(v3_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_DOUBLE(&_2, v0);
	ZVAL_DOUBLE(&_3, v1);
	ZVAL_DOUBLE(&_4, v2);
	ZVAL_DOUBLE(&_5, v3);
	phpgl_gl41_glprogramuniform4f(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform4fv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform4fv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform4d)
{
	double v0, v1, v2, v3;
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, *v3_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long program, location;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_ZVAL(v0)
		Z_PARAM_ZVAL(v1)
		Z_PARAM_ZVAL(v2)
		Z_PARAM_ZVAL(v3)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &program_param, &location_param, &v0_param, &v1_param, &v2_param, &v3_param);
	v0 = zephir_get_doubleval(v0_param);
	v1 = zephir_get_doubleval(v1_param);
	v2 = zephir_get_doubleval(v2_param);
	v3 = zephir_get_doubleval(v3_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_DOUBLE(&_2, v0);
	ZVAL_DOUBLE(&_3, v1);
	ZVAL_DOUBLE(&_4, v2);
	ZVAL_DOUBLE(&_5, v3);
	phpgl_gl41_glprogramuniform4d(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform4dv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform4dv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform4ui)
{
	zval *program_param = NULL, *location_param = NULL, *v0_param = NULL, *v1_param = NULL, *v2_param = NULL, *v3_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long program, location, v0, v1, v2, v3;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
		Z_PARAM_LONG(v1)
		Z_PARAM_LONG(v2)
		Z_PARAM_LONG(v3)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &program_param, &location_param, &v0_param, &v1_param, &v2_param, &v3_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, v0);
	ZVAL_LONG(&_3, v1);
	ZVAL_LONG(&_4, v2);
	ZVAL_LONG(&_5, v3);
	phpgl_gl41_glprogramuniform4ui(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniform4uiv)
{
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &program_param, &location_param, &count_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_LONG(&_3, value);
	phpgl_gl41_glprogramuniform4uiv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix2fv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix2fv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix3fv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix3fv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix4fv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix4fv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix2dv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix2dv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix3dv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix3dv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix4dv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix4dv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix2x3fv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix2x3fv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix3x2fv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix3x2fv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix2x4fv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix2x4fv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix4x2fv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix4x2fv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix3x4fv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix3x4fv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix4x3fv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix4x3fv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix2x3dv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix2x3dv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix3x2dv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix3x2dv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix2x4dv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix2x4dv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix4x2dv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix4x2dv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix3x4dv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix3x4dv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glProgramUniformMatrix4x3dv)
{
	zend_bool transpose;
	zval *program_param = NULL, *location_param = NULL, *count_param = NULL, *transpose_param = NULL, *value_param = NULL, _0, _1, _2, _3, _4;
	zend_long program, location, count, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &program_param, &location_param, &count_param, &transpose_param, &value_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, location);
	ZVAL_LONG(&_2, count);
	ZVAL_BOOL(&_3, (transpose ? 1 : 0));
	ZVAL_LONG(&_4, value);
	phpgl_gl41_glprogramuniformmatrix4x3dv(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glValidateProgramPipeline)
{
	zval *pipeline_param = NULL, _0;
	zend_long pipeline;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pipeline)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pipeline_param);
	ZVAL_LONG(&_0, pipeline);
	phpgl_gl41_glvalidateprogrampipeline(&_0);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glGetProgramPipelineInfoLog)
{
	zval *pipeline_param = NULL, *bufSize_param = NULL, *length_param = NULL, *infoLog_param = NULL, _0, _1, _2, _3;
	zend_long pipeline, bufSize, length, infoLog;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(pipeline)
		Z_PARAM_LONG(bufSize)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(infoLog)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &pipeline_param, &bufSize_param, &length_param, &infoLog_param);
	ZVAL_LONG(&_0, pipeline);
	ZVAL_LONG(&_1, bufSize);
	ZVAL_LONG(&_2, length);
	ZVAL_LONG(&_3, infoLog);
	phpgl_gl41_glgetprogrampipelineinfolog(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glVertexAttribL1d)
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
	phpgl_gl41_glvertexattribl1d(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glVertexAttribL2d)
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
	phpgl_gl41_glvertexattribl2d(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glVertexAttribL3d)
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
	phpgl_gl41_glvertexattribl3d(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glVertexAttribL4d)
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
	phpgl_gl41_glvertexattribl4d(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glVertexAttribL1dv)
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
	phpgl_gl41_glvertexattribl1dv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glVertexAttribL2dv)
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
	phpgl_gl41_glvertexattribl2dv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glVertexAttribL3dv)
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
	phpgl_gl41_glvertexattribl3dv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glVertexAttribL4dv)
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
	phpgl_gl41_glvertexattribl4dv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glVertexAttribLPointer)
{
	zval *index_param = NULL, *size_param = NULL, *type_param = NULL, *stride_param = NULL, *pointer_param = NULL, _0, _1, _2, _3, _4;
	zend_long index, size, type, stride, pointer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(stride)
		Z_PARAM_LONG(pointer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &index_param, &size_param, &type_param, &stride_param, &pointer_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, size);
	ZVAL_LONG(&_2, type);
	ZVAL_LONG(&_3, stride);
	ZVAL_LONG(&_4, pointer);
	phpgl_gl41_glvertexattriblpointer(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glGetVertexAttribLdv)
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
	phpgl_gl41_glgetvertexattribldv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glViewportArrayv)
{
	zval *first_param = NULL, *count_param = NULL, *v_param = NULL, _0, _1, _2;
	zend_long first, count, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(first)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &first_param, &count_param, &v_param);
	ZVAL_LONG(&_0, first);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, v);
	phpgl_gl41_glviewportarrayv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glViewportIndexedf)
{
	double x, y, w, h;
	zval *index_param = NULL, *x_param = NULL, *y_param = NULL, *w_param = NULL, *h_param = NULL, _0, _1, _2, _3, _4;
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
		Z_PARAM_ZVAL(w)
		Z_PARAM_ZVAL(h)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &index_param, &x_param, &y_param, &w_param, &h_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	w = zephir_get_doubleval(w_param);
	h = zephir_get_doubleval(h_param);
	ZVAL_LONG(&_0, index);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	ZVAL_DOUBLE(&_3, w);
	ZVAL_DOUBLE(&_4, h);
	phpgl_gl41_glviewportindexedf(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glViewportIndexedfv)
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
	phpgl_gl41_glviewportindexedfv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glScissorArrayv)
{
	zval *first_param = NULL, *count_param = NULL, *v_param = NULL, _0, _1, _2;
	zend_long first, count, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(first)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &first_param, &count_param, &v_param);
	ZVAL_LONG(&_0, first);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, v);
	phpgl_gl41_glscissorarrayv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glScissorIndexed)
{
	zval *index_param = NULL, *left_param = NULL, *bottom_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2, _3, _4;
	zend_long index, left, bottom, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(left)
		Z_PARAM_LONG(bottom)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &index_param, &left_param, &bottom_param, &width_param, &height_param);
	ZVAL_LONG(&_0, index);
	ZVAL_LONG(&_1, left);
	ZVAL_LONG(&_2, bottom);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, height);
	phpgl_gl41_glscissorindexed(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glScissorIndexedv)
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
	phpgl_gl41_glscissorindexedv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glDepthRangeArrayv)
{
	zval *first_param = NULL, *count_param = NULL, *v_param = NULL, _0, _1, _2;
	zend_long first, count, v;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(first)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(v)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &first_param, &count_param, &v_param);
	ZVAL_LONG(&_0, first);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, v);
	phpgl_gl41_gldepthrangearrayv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glDepthRangeIndexed)
{
	double n, f;
	zval *index_param = NULL, *n_param = NULL, *f_param = NULL, _0, _1, _2;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(index)
		Z_PARAM_ZVAL(n)
		Z_PARAM_ZVAL(f)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &index_param, &n_param, &f_param);
	n = zephir_get_doubleval(n_param);
	f = zephir_get_doubleval(f_param);
	ZVAL_LONG(&_0, index);
	ZVAL_DOUBLE(&_1, n);
	ZVAL_DOUBLE(&_2, f);
	phpgl_gl41_gldepthrangeindexed(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glGetFloati_v)
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
	phpgl_gl41_glgetfloati_v(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL41_GL41, glGetDoublei_v)
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
	phpgl_gl41_glgetdoublei_v(&_0, &_1, &_2);
}

