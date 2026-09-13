
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
#include "src/gl-15.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL15_GL15)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL15, GL15, opengl, gl_gl15_gl15, opengl_gl_gl15_gl15_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glGenQueries)
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
	phpgl_gl15_glgenqueries(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glDeleteQueries)
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
	phpgl_gl15_gldeletequeries(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glIsQuery)
{
	zval *id_param = NULL, _0;
	zend_long id, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &id_param);
	ZVAL_LONG(&_0, id);
	r = phpgl_gl15_glisquery(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glBeginQuery)
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
	phpgl_gl15_glbeginquery(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glEndQuery)
{
	zval *target_param = NULL, _0;
	zend_long target;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(target)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &target_param);
	ZVAL_LONG(&_0, target);
	phpgl_gl15_glendquery(&_0);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glGetQueryiv)
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
	phpgl_gl15_glgetqueryiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glGetQueryObjectiv)
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
	phpgl_gl15_glgetqueryobjectiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glGetQueryObjectuiv)
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
	phpgl_gl15_glgetqueryobjectuiv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glBindBuffer)
{
	zval *target_param = NULL, *buffer_param = NULL, _0, _1;
	zend_long target, buffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &target_param, &buffer_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, buffer);
	phpgl_gl15_glbindbuffer(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glDeleteBuffers)
{
	zval *n_param = NULL, *buffers_param = NULL, _0, _1;
	zend_long n, buffers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(buffers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &buffers_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, buffers);
	phpgl_gl15_gldeletebuffers(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glGenBuffers)
{
	zval *n_param = NULL, *buffers_param = NULL, _0, _1;
	zend_long n, buffers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_LONG(buffers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &buffers_param);
	ZVAL_LONG(&_0, n);
	ZVAL_LONG(&_1, buffers);
	phpgl_gl15_glgenbuffers(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glIsBuffer)
{
	zval *buffer_param = NULL, _0;
	zend_long buffer, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &buffer_param);
	ZVAL_LONG(&_0, buffer);
	r = phpgl_gl15_glisbuffer(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glBufferData)
{
	zval *target_param = NULL, *size_param = NULL, *data_param = NULL, *usage_param = NULL, _0, _1, _2, _3;
	zend_long target, size, data, usage;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(data)
		Z_PARAM_LONG(usage)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &size_param, &data_param, &usage_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, size);
	ZVAL_LONG(&_2, data);
	ZVAL_LONG(&_3, usage);
	phpgl_gl15_glbufferdata(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glBufferSubData)
{
	zval *target_param = NULL, *offset_param = NULL, *size_param = NULL, *data_param = NULL, _0, _1, _2, _3;
	zend_long target, offset, size, data;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &offset_param, &size_param, &data_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, offset);
	ZVAL_LONG(&_2, size);
	ZVAL_LONG(&_3, data);
	phpgl_gl15_glbuffersubdata(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glGetBufferSubData)
{
	zval *target_param = NULL, *offset_param = NULL, *size_param = NULL, *data_param = NULL, _0, _1, _2, _3;
	zend_long target, offset, size, data;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &offset_param, &size_param, &data_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, offset);
	ZVAL_LONG(&_2, size);
	ZVAL_LONG(&_3, data);
	phpgl_gl15_glgetbuffersubdata(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glMapBuffer)
{
	zval *target_param = NULL, *access_param = NULL, _0, _1;
	zend_long target, access;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(access)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &target_param, &access_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, access);
	RETURN_LONG(phpgl_gl15_glmapbuffer(&_0, &_1));
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glUnmapBuffer)
{
	zval *target_param = NULL, _0;
	zend_long target, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(target)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &target_param);
	ZVAL_LONG(&_0, target);
	r = phpgl_gl15_glunmapbuffer(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glGetBufferParameteriv)
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
	phpgl_gl15_glgetbufferparameteriv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL15_GL15, glGetBufferPointerv)
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
	phpgl_gl15_glgetbufferpointerv(&_0, &_1, &_2);
}

