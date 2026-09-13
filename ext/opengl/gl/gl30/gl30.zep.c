
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
#include "src/gl-30.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL30_GL30)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL30, GL30, opengl, gl_gl30_gl30, opengl_gl_gl30_gl30_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glColorMaski)
{
	zend_bool r, g, b, a;
	zval *index_param = NULL, *r_param = NULL, *g_param = NULL, *b_param = NULL, *a_param = NULL, _0, _1, _2, _3, _4;
	zend_long index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(index)
		Z_PARAM_BOOL(r)
		Z_PARAM_BOOL(g)
		Z_PARAM_BOOL(b)
		Z_PARAM_BOOL(a)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &index_param, &r_param, &g_param, &b_param, &a_param);
	ZVAL_LONG(&_0, index);
	ZVAL_BOOL(&_1, (r ? 1 : 0));
	ZVAL_BOOL(&_2, (g ? 1 : 0));
	ZVAL_BOOL(&_3, (b ? 1 : 0));
	ZVAL_BOOL(&_4, (a ? 1 : 0));
	phpgl_gl30_glcolormaski(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetBooleani_v)
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
	phpgl_gl30_glgetbooleani_v(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetIntegeri_v)
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
	phpgl_gl30_glgetintegeri_v(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glEnablei)
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
	phpgl_gl30_glenablei(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glDisablei)
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
	phpgl_gl30_gldisablei(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glIsEnabledi)
{
	zval *target_param = NULL, *index_param = NULL, _0, _1;
	zend_long target, index, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &target_param, &index_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, index);
	r = phpgl_gl30_glisenabledi(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glBeginTransformFeedback)
{
	zval *primitiveMode_param = NULL, _0;
	zend_long primitiveMode;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(primitiveMode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &primitiveMode_param);
	ZVAL_LONG(&_0, primitiveMode);
	phpgl_gl30_glbegintransformfeedback(&_0);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glEndTransformFeedback)
{

	phpgl_gl30_glendtransformfeedback();
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glBindBufferRange)
{
	zval *target_param = NULL, *index_param = NULL, *buffer_param = NULL, *offset_param = NULL, *size_param = NULL, _0, _1, _2, _3, _4;
	zend_long target, index, buffer, offset, size;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(size)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &target_param, &index_param, &buffer_param, &offset_param, &size_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, index);
	ZVAL_LONG(&_2, buffer);
	ZVAL_LONG(&_3, offset);
	ZVAL_LONG(&_4, size);
	phpgl_gl30_glbindbufferrange(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glBindBufferBase)
{
	zval *target_param = NULL, *index_param = NULL, *buffer_param = NULL, _0, _1, _2;
	zend_long target, index, buffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &index_param, &buffer_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, index);
	ZVAL_LONG(&_2, buffer);
	phpgl_gl30_glbindbufferbase(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glTransformFeedbackVaryings)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval varyings;
	zval *program_param = NULL, *count_param = NULL, *varyings_param = NULL, *bufferMode_param = NULL, _0, _1, _2;
	zend_long program, count, bufferMode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&varyings);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(count)
		Z_PARAM_ARRAY(varyings)
		Z_PARAM_LONG(bufferMode)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &program_param, &count_param, &varyings_param, &bufferMode_param);
	zephir_get_arrval(&varyings, varyings_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, count);
	ZVAL_LONG(&_2, bufferMode);
	phpgl_gl30_gltransformfeedbackvaryings(&_0, &_1, &varyings, &_2);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetTransformFeedbackVarying)
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
	phpgl_gl30_glgettransformfeedbackvarying(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glClampColor)
{
	zval *target_param = NULL, *clamp_param = NULL, _0, _1;
	zend_long target, clamp;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(clamp)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &target_param, &clamp_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, clamp);
	phpgl_gl30_glclampcolor(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glBeginConditionalRender)
{
	zval *id_param = NULL, *mode_param = NULL, _0, _1;
	zend_long id, mode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(id)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &id_param, &mode_param);
	ZVAL_LONG(&_0, id);
	ZVAL_LONG(&_1, mode);
	phpgl_gl30_glbeginconditionalrender(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glEndConditionalRender)
{

	phpgl_gl30_glendconditionalrender();
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribIPointer)
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
	phpgl_gl30_glvertexattribipointer(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetVertexAttribIiv)
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
	phpgl_gl30_glgetvertexattribiiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetVertexAttribIuiv)
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
	phpgl_gl30_glgetvertexattribiuiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI1i)
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
	phpgl_gl30_glvertexattribi1i(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI2i)
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
	phpgl_gl30_glvertexattribi2i(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI3i)
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
	phpgl_gl30_glvertexattribi3i(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI4i)
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
	phpgl_gl30_glvertexattribi4i(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI1ui)
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
	phpgl_gl30_glvertexattribi1ui(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI2ui)
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
	phpgl_gl30_glvertexattribi2ui(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI3ui)
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
	phpgl_gl30_glvertexattribi3ui(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI4ui)
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
	phpgl_gl30_glvertexattribi4ui(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI1iv)
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
	phpgl_gl30_glvertexattribi1iv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI2iv)
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
	phpgl_gl30_glvertexattribi2iv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI3iv)
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
	phpgl_gl30_glvertexattribi3iv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI4iv)
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
	phpgl_gl30_glvertexattribi4iv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI1uiv)
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
	phpgl_gl30_glvertexattribi1uiv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI2uiv)
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
	phpgl_gl30_glvertexattribi2uiv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI3uiv)
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
	phpgl_gl30_glvertexattribi3uiv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI4uiv)
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
	phpgl_gl30_glvertexattribi4uiv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI4bv)
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
	phpgl_gl30_glvertexattribi4bv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI4sv)
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
	phpgl_gl30_glvertexattribi4sv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI4ubv)
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
	phpgl_gl30_glvertexattribi4ubv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glVertexAttribI4usv)
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
	phpgl_gl30_glvertexattribi4usv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetUniformuiv)
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
	phpgl_gl30_glgetuniformuiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glBindFragDataLocation)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *program_param = NULL, *color_param = NULL, *name_param = NULL, _0, _1;
	zend_long program, color;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(color)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &program_param, &color_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, program);
	ZVAL_LONG(&_1, color);
	phpgl_gl30_glbindfragdatalocation(&_0, &_1, &name);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetFragDataLocation)
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
	RETURN_MM_LONG(phpgl_gl30_glgetfragdatalocation(&_0, &name));
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glUniform1ui)
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
	phpgl_gl30_gluniform1ui(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glUniform2ui)
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
	phpgl_gl30_gluniform2ui(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glUniform3ui)
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
	phpgl_gl30_gluniform3ui(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glUniform4ui)
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
	phpgl_gl30_gluniform4ui(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glUniform1uiv)
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
	phpgl_gl30_gluniform1uiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glUniform2uiv)
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
	phpgl_gl30_gluniform2uiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glUniform3uiv)
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
	phpgl_gl30_gluniform3uiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glUniform4uiv)
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
	phpgl_gl30_gluniform4uiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glTexParameterIiv)
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
	phpgl_gl30_gltexparameteriiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glTexParameterIuiv)
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
	phpgl_gl30_gltexparameteriuiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetTexParameterIiv)
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
	phpgl_gl30_glgettexparameteriiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetTexParameterIuiv)
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
	phpgl_gl30_glgettexparameteriuiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glClearBufferiv)
{
	zval *buffer_param = NULL, *drawbuffer_param = NULL, *value_param = NULL, _0, _1, _2;
	zend_long buffer, drawbuffer, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(drawbuffer)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &buffer_param, &drawbuffer_param, &value_param);
	ZVAL_LONG(&_0, buffer);
	ZVAL_LONG(&_1, drawbuffer);
	ZVAL_LONG(&_2, value);
	phpgl_gl30_glclearbufferiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glClearBufferuiv)
{
	zval *buffer_param = NULL, *drawbuffer_param = NULL, *value_param = NULL, _0, _1, _2;
	zend_long buffer, drawbuffer, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(drawbuffer)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &buffer_param, &drawbuffer_param, &value_param);
	ZVAL_LONG(&_0, buffer);
	ZVAL_LONG(&_1, drawbuffer);
	ZVAL_LONG(&_2, value);
	phpgl_gl30_glclearbufferuiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glClearBufferfv)
{
	zval *buffer_param = NULL, *drawbuffer_param = NULL, *value_param = NULL, _0, _1, _2;
	zend_long buffer, drawbuffer, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(drawbuffer)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &buffer_param, &drawbuffer_param, &value_param);
	ZVAL_LONG(&_0, buffer);
	ZVAL_LONG(&_1, drawbuffer);
	ZVAL_LONG(&_2, value);
	phpgl_gl30_glclearbufferfv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glClearBufferfi)
{
	double depth;
	zval *buffer_param = NULL, *drawbuffer_param = NULL, *depth_param = NULL, *stencil_param = NULL, _0, _1, _2, _3;
	zend_long buffer, drawbuffer, stencil;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(buffer)
		Z_PARAM_LONG(drawbuffer)
		Z_PARAM_ZVAL(depth)
		Z_PARAM_LONG(stencil)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &buffer_param, &drawbuffer_param, &depth_param, &stencil_param);
	depth = zephir_get_doubleval(depth_param);
	ZVAL_LONG(&_0, buffer);
	ZVAL_LONG(&_1, drawbuffer);
	ZVAL_DOUBLE(&_2, depth);
	ZVAL_LONG(&_3, stencil);
	phpgl_gl30_glclearbufferfi(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetStringi)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, *index_param = NULL, result, _0, _1;
	zend_long name, index;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(name)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &name_param, &index_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, name);
	ZVAL_LONG(&_1, index);
	phpgl_gl30_glgetstringi(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glIsRenderbuffer)
{
	zval *renderbuffer_param = NULL, _0;
	zend_long renderbuffer, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(renderbuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &renderbuffer_param);
	ZVAL_LONG(&_0, renderbuffer);
	r = phpgl_gl30_glisrenderbuffer(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glBindRenderbuffer)
{
	zval *target_param = NULL, *renderbuffer_param = NULL, _0, _1;
	zend_long target, renderbuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(renderbuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &target_param, &renderbuffer_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, renderbuffer);
	phpgl_gl30_glbindrenderbuffer(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glDeleteRenderbuffers)
{
	zval *n_param = NULL, *renderbuffers_param = NULL, _0, _1;
	zend_long n, renderbuffers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(renderbuffers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &renderbuffers_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, renderbuffers);
	phpgl_gl30_gldeleterenderbuffers(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGenRenderbuffers)
{
	zval *n_param = NULL, *renderbuffers_param = NULL, _0, _1;
	zend_long n, renderbuffers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(renderbuffers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &renderbuffers_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, renderbuffers);
	phpgl_gl30_glgenrenderbuffers(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glRenderbufferStorage)
{
	zval *target_param = NULL, *internalformat_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2, _3;
	zend_long target, internalformat, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &internalformat_param, &width_param, &height_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, internalformat);
	ZVAL_LONG(&_2, width);
	ZVAL_LONG(&_3, height);
	phpgl_gl30_glrenderbufferstorage(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetRenderbufferParameteriv)
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
	phpgl_gl30_glgetrenderbufferparameteriv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glIsFramebuffer)
{
	zval *framebuffer_param = NULL, _0;
	zend_long framebuffer, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(framebuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &framebuffer_param);
	ZVAL_LONG(&_0, framebuffer);
	r = phpgl_gl30_glisframebuffer(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glBindFramebuffer)
{
	zval *target_param = NULL, *framebuffer_param = NULL, _0, _1;
	zend_long target, framebuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(framebuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &target_param, &framebuffer_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, framebuffer);
	phpgl_gl30_glbindframebuffer(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glDeleteFramebuffers)
{
	zval *n_param = NULL, *framebuffers_param = NULL, _0, _1;
	zend_long n, framebuffers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(framebuffers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &framebuffers_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, framebuffers);
	phpgl_gl30_gldeleteframebuffers(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGenFramebuffers)
{
	zval *n_param = NULL, *framebuffers_param = NULL, _0, _1;
	zend_long n, framebuffers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(framebuffers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &framebuffers_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, framebuffers);
	phpgl_gl30_glgenframebuffers(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glCheckFramebufferStatus)
{
	zval *target_param = NULL, _0;
	zend_long target;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(target)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &target_param);
	ZVAL_LONG(&_0, target);
	RETURN_LONG(phpgl_gl30_glcheckframebufferstatus(&_0));
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glFramebufferTexture1D)
{
	zval *target_param = NULL, *attachment_param = NULL, *textarget_param = NULL, *texture_param = NULL, *level_param = NULL, _0, _1, _2, _3, _4;
	zend_long target, attachment, textarget, texture, level;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(attachment)
		Z_PARAM_LONG(textarget)
		Z_PARAM_LONG(texture)
		Z_PARAM_LONG(level)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &target_param, &attachment_param, &textarget_param, &texture_param, &level_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, attachment);
	ZVAL_LONG(&_2, textarget);
	ZVAL_LONG(&_3, texture);
	ZVAL_LONG(&_4, level);
	phpgl_gl30_glframebuffertexture1d(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glFramebufferTexture2D)
{
	zval *target_param = NULL, *attachment_param = NULL, *textarget_param = NULL, *texture_param = NULL, *level_param = NULL, _0, _1, _2, _3, _4;
	zend_long target, attachment, textarget, texture, level;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(attachment)
		Z_PARAM_LONG(textarget)
		Z_PARAM_LONG(texture)
		Z_PARAM_LONG(level)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &target_param, &attachment_param, &textarget_param, &texture_param, &level_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, attachment);
	ZVAL_LONG(&_2, textarget);
	ZVAL_LONG(&_3, texture);
	ZVAL_LONG(&_4, level);
	phpgl_gl30_glframebuffertexture2d(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glFramebufferTexture3D)
{
	zval *target_param = NULL, *attachment_param = NULL, *textarget_param = NULL, *texture_param = NULL, *level_param = NULL, *zoffset_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long target, attachment, textarget, texture, level, zoffset;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(attachment)
		Z_PARAM_LONG(textarget)
		Z_PARAM_LONG(texture)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(zoffset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &target_param, &attachment_param, &textarget_param, &texture_param, &level_param, &zoffset_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, attachment);
	ZVAL_LONG(&_2, textarget);
	ZVAL_LONG(&_3, texture);
	ZVAL_LONG(&_4, level);
	ZVAL_LONG(&_5, zoffset);
	phpgl_gl30_glframebuffertexture3d(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glFramebufferRenderbuffer)
{
	zval *target_param = NULL, *attachment_param = NULL, *renderbuffertarget_param = NULL, *renderbuffer_param = NULL, _0, _1, _2, _3;
	zend_long target, attachment, renderbuffertarget, renderbuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(attachment)
		Z_PARAM_LONG(renderbuffertarget)
		Z_PARAM_LONG(renderbuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &attachment_param, &renderbuffertarget_param, &renderbuffer_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, attachment);
	ZVAL_LONG(&_2, renderbuffertarget);
	ZVAL_LONG(&_3, renderbuffer);
	phpgl_gl30_glframebufferrenderbuffer(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGetFramebufferAttachmentParameteriv)
{
	zval *target_param = NULL, *attachment_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2, _3;
	zend_long target, attachment, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(attachment)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &attachment_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, attachment);
	ZVAL_LONG(&_2, pname);
	ZVAL_LONG(&_3, params);
	phpgl_gl30_glgetframebufferattachmentparameteriv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGenerateMipmap)
{
	zval *target_param = NULL, _0;
	zend_long target;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(target)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &target_param);
	ZVAL_LONG(&_0, target);
	phpgl_gl30_glgeneratemipmap(&_0);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glBlitFramebuffer)
{
	zval *srcX0_param = NULL, *srcY0_param = NULL, *srcX1_param = NULL, *srcY1_param = NULL, *dstX0_param = NULL, *dstY0_param = NULL, *dstX1_param = NULL, *dstY1_param = NULL, *mask_param = NULL, *filter_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9;
	zend_long srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter;

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
		Z_PARAM_LONG(srcX0)
		Z_PARAM_LONG(srcY0)
		Z_PARAM_LONG(srcX1)
		Z_PARAM_LONG(srcY1)
		Z_PARAM_LONG(dstX0)
		Z_PARAM_LONG(dstY0)
		Z_PARAM_LONG(dstX1)
		Z_PARAM_LONG(dstY1)
		Z_PARAM_LONG(mask)
		Z_PARAM_LONG(filter)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(10, 0, &srcX0_param, &srcY0_param, &srcX1_param, &srcY1_param, &dstX0_param, &dstY0_param, &dstX1_param, &dstY1_param, &mask_param, &filter_param);
	ZVAL_LONG(&_0, srcX0);
	ZVAL_LONG(&_1, srcY0);
	ZVAL_LONG(&_2, srcX1);
	ZVAL_LONG(&_3, srcY1);
	ZVAL_LONG(&_4, dstX0);
	ZVAL_LONG(&_5, dstY0);
	ZVAL_LONG(&_6, dstX1);
	ZVAL_LONG(&_7, dstY1);
	ZVAL_LONG(&_8, mask);
	ZVAL_LONG(&_9, filter);
	phpgl_gl30_glblitframebuffer(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8, &_9);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glRenderbufferStorageMultisample)
{
	zval *target_param = NULL, *samples_param = NULL, *internalformat_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2, _3, _4;
	zend_long target, samples, internalformat, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(samples)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &target_param, &samples_param, &internalformat_param, &width_param, &height_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, samples);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, height);
	phpgl_gl30_glrenderbufferstoragemultisample(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glFramebufferTextureLayer)
{
	zval *target_param = NULL, *attachment_param = NULL, *texture_param = NULL, *level_param = NULL, *layer_param = NULL, _0, _1, _2, _3, _4;
	zend_long target, attachment, texture, level, layer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(attachment)
		Z_PARAM_LONG(texture)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(layer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &target_param, &attachment_param, &texture_param, &level_param, &layer_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, attachment);
	ZVAL_LONG(&_2, texture);
	ZVAL_LONG(&_3, level);
	ZVAL_LONG(&_4, layer);
	phpgl_gl30_glframebuffertexturelayer(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glMapBufferRange)
{
	zval *target_param = NULL, *offset_param = NULL, *length_param = NULL, *access_param = NULL, _0, _1, _2, _3;
	zend_long target, offset, length, access;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(access)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &offset_param, &length_param, &access_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, offset);
	ZVAL_LONG(&_2, length);
	ZVAL_LONG(&_3, access);
	RETURN_LONG(phpgl_gl30_glmapbufferrange(&_0, &_1, &_2, &_3));
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glFlushMappedBufferRange)
{
	zval *target_param = NULL, *offset_param = NULL, *length_param = NULL, _0, _1, _2;
	zend_long target, offset, length;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &offset_param, &length_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, offset);
	ZVAL_LONG(&_2, length);
	phpgl_gl30_glflushmappedbufferrange(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glBindVertexArray)
{
	zval *array__param = NULL, _0;
	zend_long array_;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(array_)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &array__param);
	ZVAL_LONG(&_0, array_);
	phpgl_gl30_glbindvertexarray(&_0);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glDeleteVertexArrays)
{
	zval *n_param = NULL, *arrays_param = NULL, _0, _1;
	zend_long n, arrays;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(arrays)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &arrays_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, arrays);
	phpgl_gl30_gldeletevertexarrays(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glGenVertexArrays)
{
	zval *n_param = NULL, *arrays_param = NULL, _0, _1;
	zend_long n, arrays;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(arrays)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &arrays_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, arrays);
	phpgl_gl30_glgenvertexarrays(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL30_GL30, glIsVertexArray)
{
	zval *array__param = NULL, _0;
	zend_long array_, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(array_)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &array__param);
	ZVAL_LONG(&_0, array_);
	r = phpgl_gl30_glisvertexarray(&_0);
	RETURN_BOOL(r == 1);
}

