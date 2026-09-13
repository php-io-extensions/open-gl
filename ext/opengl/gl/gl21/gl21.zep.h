
extern zend_class_entry *opengl_gl_gl21_gl21_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL21_GL21);

PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix2x3fv);
PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix3x2fv);
PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix2x4fv);
PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix4x2fv);
PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix3x4fv);
PHP_METHOD(OpenGL_GL_GL21_GL21, glUniformMatrix4x3fv);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl21_gl21_gluniformmatrix2x3fv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl21_gl21_gluniformmatrix3x2fv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl21_gl21_gluniformmatrix2x4fv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl21_gl21_gluniformmatrix4x2fv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl21_gl21_gluniformmatrix3x4fv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl21_gl21_gluniformmatrix4x3fv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl21_gl21_method_entry) {
	PHP_ME(OpenGL_GL_GL21_GL21, glUniformMatrix2x3fv, arginfo_opengl_gl_gl21_gl21_gluniformmatrix2x3fv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL21_GL21, glUniformMatrix3x2fv, arginfo_opengl_gl_gl21_gl21_gluniformmatrix3x2fv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL21_GL21, glUniformMatrix2x4fv, arginfo_opengl_gl_gl21_gl21_gluniformmatrix2x4fv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL21_GL21, glUniformMatrix4x2fv, arginfo_opengl_gl_gl21_gl21_gluniformmatrix4x2fv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL21_GL21, glUniformMatrix3x4fv, arginfo_opengl_gl_gl21_gl21_gluniformmatrix3x4fv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL21_GL21, glUniformMatrix4x3fv, arginfo_opengl_gl_gl21_gl21_gluniformmatrix4x3fv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
