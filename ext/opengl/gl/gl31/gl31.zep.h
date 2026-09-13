
extern zend_class_entry *opengl_gl_gl31_gl31_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL31_GL31);

PHP_METHOD(OpenGL_GL_GL31_GL31, glDrawArraysInstanced);
PHP_METHOD(OpenGL_GL_GL31_GL31, glDrawElementsInstanced);
PHP_METHOD(OpenGL_GL_GL31_GL31, glTexBuffer);
PHP_METHOD(OpenGL_GL_GL31_GL31, glPrimitiveRestartIndex);
PHP_METHOD(OpenGL_GL_GL31_GL31, glCopyBufferSubData);
PHP_METHOD(OpenGL_GL_GL31_GL31, glGetUniformIndices);
PHP_METHOD(OpenGL_GL_GL31_GL31, glGetActiveUniformsiv);
PHP_METHOD(OpenGL_GL_GL31_GL31, glGetActiveUniformName);
PHP_METHOD(OpenGL_GL_GL31_GL31, glGetUniformBlockIndex);
PHP_METHOD(OpenGL_GL_GL31_GL31, glGetActiveUniformBlockiv);
PHP_METHOD(OpenGL_GL_GL31_GL31, glGetActiveUniformBlockName);
PHP_METHOD(OpenGL_GL_GL31_GL31, glUniformBlockBinding);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_gldrawarraysinstanced, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, first, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instancecount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_gldrawelementsinstanced, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indices, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instancecount, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_gltexbuffer, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_glprimitiverestartindex, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_glcopybuffersubdata, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, readTarget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, writeTarget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, readOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, writeOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_glgetuniformindices, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformCount, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, uniformNames, 0)
	ZEND_ARG_TYPE_INFO(0, uniformIndices, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_glgetactiveuniformsiv, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformCount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformIndices, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_glgetactiveuniformname, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bufSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformName, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_glgetuniformblockindex, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformBlockName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_glgetactiveuniformblockiv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformBlockIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_glgetactiveuniformblockname, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformBlockIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bufSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformBlockName, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl31_gl31_gluniformblockbinding, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformBlockIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, uniformBlockBinding, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl31_gl31_method_entry) {
	PHP_ME(OpenGL_GL_GL31_GL31, glDrawArraysInstanced, arginfo_opengl_gl_gl31_gl31_gldrawarraysinstanced, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glDrawElementsInstanced, arginfo_opengl_gl_gl31_gl31_gldrawelementsinstanced, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glTexBuffer, arginfo_opengl_gl_gl31_gl31_gltexbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glPrimitiveRestartIndex, arginfo_opengl_gl_gl31_gl31_glprimitiverestartindex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glCopyBufferSubData, arginfo_opengl_gl_gl31_gl31_glcopybuffersubdata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glGetUniformIndices, arginfo_opengl_gl_gl31_gl31_glgetuniformindices, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glGetActiveUniformsiv, arginfo_opengl_gl_gl31_gl31_glgetactiveuniformsiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glGetActiveUniformName, arginfo_opengl_gl_gl31_gl31_glgetactiveuniformname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glGetUniformBlockIndex, arginfo_opengl_gl_gl31_gl31_glgetuniformblockindex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glGetActiveUniformBlockiv, arginfo_opengl_gl_gl31_gl31_glgetactiveuniformblockiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glGetActiveUniformBlockName, arginfo_opengl_gl_gl31_gl31_glgetactiveuniformblockname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL31_GL31, glUniformBlockBinding, arginfo_opengl_gl_gl31_gl31_gluniformblockbinding, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
