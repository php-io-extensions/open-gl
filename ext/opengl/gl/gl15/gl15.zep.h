
extern zend_class_entry *opengl_gl_gl15_gl15_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL15_GL15);

PHP_METHOD(OpenGL_GL_GL15_GL15, glGenQueries);
PHP_METHOD(OpenGL_GL_GL15_GL15, glDeleteQueries);
PHP_METHOD(OpenGL_GL_GL15_GL15, glIsQuery);
PHP_METHOD(OpenGL_GL_GL15_GL15, glBeginQuery);
PHP_METHOD(OpenGL_GL_GL15_GL15, glEndQuery);
PHP_METHOD(OpenGL_GL_GL15_GL15, glGetQueryiv);
PHP_METHOD(OpenGL_GL_GL15_GL15, glGetQueryObjectiv);
PHP_METHOD(OpenGL_GL_GL15_GL15, glGetQueryObjectuiv);
PHP_METHOD(OpenGL_GL_GL15_GL15, glBindBuffer);
PHP_METHOD(OpenGL_GL_GL15_GL15, glDeleteBuffers);
PHP_METHOD(OpenGL_GL_GL15_GL15, glGenBuffers);
PHP_METHOD(OpenGL_GL_GL15_GL15, glIsBuffer);
PHP_METHOD(OpenGL_GL_GL15_GL15, glBufferData);
PHP_METHOD(OpenGL_GL_GL15_GL15, glBufferSubData);
PHP_METHOD(OpenGL_GL_GL15_GL15, glGetBufferSubData);
PHP_METHOD(OpenGL_GL_GL15_GL15, glMapBuffer);
PHP_METHOD(OpenGL_GL_GL15_GL15, glUnmapBuffer);
PHP_METHOD(OpenGL_GL_GL15_GL15, glGetBufferParameteriv);
PHP_METHOD(OpenGL_GL_GL15_GL15, glGetBufferPointerv);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glgenqueries, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, n, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ids, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_gldeletequeries, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, n, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ids, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glisquery, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glbeginquery, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glendquery, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glgetqueryiv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glgetqueryobjectiv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glgetqueryobjectuiv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glbindbuffer, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_gldeletebuffers, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, n, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffers, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glgenbuffers, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, n, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffers, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glisbuffer, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glbufferdata, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, usage, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glbuffersubdata, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glgetbuffersubdata, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glmapbuffer, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, access, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glunmapbuffer, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glgetbufferparameteriv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl15_gl15_glgetbufferpointerv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl15_gl15_method_entry) {
	PHP_ME(OpenGL_GL_GL15_GL15, glGenQueries, arginfo_opengl_gl_gl15_gl15_glgenqueries, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glDeleteQueries, arginfo_opengl_gl_gl15_gl15_gldeletequeries, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glIsQuery, arginfo_opengl_gl_gl15_gl15_glisquery, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glBeginQuery, arginfo_opengl_gl_gl15_gl15_glbeginquery, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glEndQuery, arginfo_opengl_gl_gl15_gl15_glendquery, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glGetQueryiv, arginfo_opengl_gl_gl15_gl15_glgetqueryiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glGetQueryObjectiv, arginfo_opengl_gl_gl15_gl15_glgetqueryobjectiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glGetQueryObjectuiv, arginfo_opengl_gl_gl15_gl15_glgetqueryobjectuiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glBindBuffer, arginfo_opengl_gl_gl15_gl15_glbindbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glDeleteBuffers, arginfo_opengl_gl_gl15_gl15_gldeletebuffers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glGenBuffers, arginfo_opengl_gl_gl15_gl15_glgenbuffers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glIsBuffer, arginfo_opengl_gl_gl15_gl15_glisbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glBufferData, arginfo_opengl_gl_gl15_gl15_glbufferdata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glBufferSubData, arginfo_opengl_gl_gl15_gl15_glbuffersubdata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glGetBufferSubData, arginfo_opengl_gl_gl15_gl15_glgetbuffersubdata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glMapBuffer, arginfo_opengl_gl_gl15_gl15_glmapbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glUnmapBuffer, arginfo_opengl_gl_gl15_gl15_glunmapbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glGetBufferParameteriv, arginfo_opengl_gl_gl15_gl15_glgetbufferparameteriv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL15_GL15, glGetBufferPointerv, arginfo_opengl_gl_gl15_gl15_glgetbufferpointerv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
