
extern zend_class_entry *opengl_gl_gl14_gl14_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL14_GL14);

PHP_METHOD(OpenGL_GL_GL14_GL14, glBlendFuncSeparate);
PHP_METHOD(OpenGL_GL_GL14_GL14, glMultiDrawArrays);
PHP_METHOD(OpenGL_GL_GL14_GL14, glMultiDrawElements);
PHP_METHOD(OpenGL_GL_GL14_GL14, glPointParameterf);
PHP_METHOD(OpenGL_GL_GL14_GL14, glPointParameterfv);
PHP_METHOD(OpenGL_GL_GL14_GL14, glPointParameteri);
PHP_METHOD(OpenGL_GL_GL14_GL14, glPointParameteriv);
PHP_METHOD(OpenGL_GL_GL14_GL14, glBlendColor);
PHP_METHOD(OpenGL_GL_GL14_GL14, glBlendEquation);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl14_gl14_glblendfuncseparate, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sfactorRGB, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dfactorRGB, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sfactorAlpha, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dfactorAlpha, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl14_gl14_glmultidrawarrays, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, first, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, drawcount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl14_gl14_glmultidrawelements, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indices, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, drawcount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl14_gl14_glpointparameterf, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl14_gl14_glpointparameterfv, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl14_gl14_glpointparameteri, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl14_gl14_glpointparameteriv, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl14_gl14_glblendcolor, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl14_gl14_glblendequation, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl14_gl14_method_entry) {
	PHP_ME(OpenGL_GL_GL14_GL14, glBlendFuncSeparate, arginfo_opengl_gl_gl14_gl14_glblendfuncseparate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL14_GL14, glMultiDrawArrays, arginfo_opengl_gl_gl14_gl14_glmultidrawarrays, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL14_GL14, glMultiDrawElements, arginfo_opengl_gl_gl14_gl14_glmultidrawelements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL14_GL14, glPointParameterf, arginfo_opengl_gl_gl14_gl14_glpointparameterf, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL14_GL14, glPointParameterfv, arginfo_opengl_gl_gl14_gl14_glpointparameterfv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL14_GL14, glPointParameteri, arginfo_opengl_gl_gl14_gl14_glpointparameteri, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL14_GL14, glPointParameteriv, arginfo_opengl_gl_gl14_gl14_glpointparameteriv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL14_GL14, glBlendColor, arginfo_opengl_gl_gl14_gl14_glblendcolor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL14_GL14, glBlendEquation, arginfo_opengl_gl_gl14_gl14_glblendequation, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
