
extern zend_class_entry *opengl_gl_gl32_gl32_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL32_GL32);

PHP_METHOD(OpenGL_GL_GL32_GL32, glDrawElementsBaseVertex);
PHP_METHOD(OpenGL_GL_GL32_GL32, glDrawRangeElementsBaseVertex);
PHP_METHOD(OpenGL_GL_GL32_GL32, glDrawElementsInstancedBaseVertex);
PHP_METHOD(OpenGL_GL_GL32_GL32, glMultiDrawElementsBaseVertex);
PHP_METHOD(OpenGL_GL_GL32_GL32, glProvokingVertex);
PHP_METHOD(OpenGL_GL_GL32_GL32, glFenceSync);
PHP_METHOD(OpenGL_GL_GL32_GL32, glIsSync);
PHP_METHOD(OpenGL_GL_GL32_GL32, glDeleteSync);
PHP_METHOD(OpenGL_GL_GL32_GL32, glClientWaitSync);
PHP_METHOD(OpenGL_GL_GL32_GL32, glWaitSync);
PHP_METHOD(OpenGL_GL_GL32_GL32, glGetInteger64v);
PHP_METHOD(OpenGL_GL_GL32_GL32, glGetSynciv);
PHP_METHOD(OpenGL_GL_GL32_GL32, glGetInteger64i_v);
PHP_METHOD(OpenGL_GL_GL32_GL32, glGetBufferParameteri64v);
PHP_METHOD(OpenGL_GL_GL32_GL32, glFramebufferTexture);
PHP_METHOD(OpenGL_GL_GL32_GL32, glTexImage2DMultisample);
PHP_METHOD(OpenGL_GL_GL32_GL32, glTexImage3DMultisample);
PHP_METHOD(OpenGL_GL_GL32_GL32, glGetMultisamplefv);
PHP_METHOD(OpenGL_GL_GL32_GL32, glSampleMaski);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_gldrawelementsbasevertex, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indices, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, basevertex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_gldrawrangeelementsbasevertex, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, start, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, end, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indices, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, basevertex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_gldrawelementsinstancedbasevertex, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indices, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instancecount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, basevertex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glmultidrawelementsbasevertex, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indices, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, drawcount, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, basevertex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glprovokingvertex, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glfencesync, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, condition, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glissync, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, sync, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_gldeletesync, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sync, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glclientwaitsync, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sync, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glwaitsync, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sync, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glgetinteger64v, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glgetsynciv, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sync, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, values, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glgetinteger64i_v, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glgetbufferparameteri64v, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glframebuffertexture, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attachment, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glteximage2dmultisample, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, samples, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fixedsamplelocations, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glteximage3dmultisample, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, samples, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fixedsamplelocations, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glgetmultisamplefv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, val, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl32_gl32_glsamplemaski, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, maskNumber, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl32_gl32_method_entry) {
	PHP_ME(OpenGL_GL_GL32_GL32, glDrawElementsBaseVertex, arginfo_opengl_gl_gl32_gl32_gldrawelementsbasevertex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glDrawRangeElementsBaseVertex, arginfo_opengl_gl_gl32_gl32_gldrawrangeelementsbasevertex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glDrawElementsInstancedBaseVertex, arginfo_opengl_gl_gl32_gl32_gldrawelementsinstancedbasevertex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glMultiDrawElementsBaseVertex, arginfo_opengl_gl_gl32_gl32_glmultidrawelementsbasevertex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glProvokingVertex, arginfo_opengl_gl_gl32_gl32_glprovokingvertex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glFenceSync, arginfo_opengl_gl_gl32_gl32_glfencesync, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glIsSync, arginfo_opengl_gl_gl32_gl32_glissync, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glDeleteSync, arginfo_opengl_gl_gl32_gl32_gldeletesync, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glClientWaitSync, arginfo_opengl_gl_gl32_gl32_glclientwaitsync, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glWaitSync, arginfo_opengl_gl_gl32_gl32_glwaitsync, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glGetInteger64v, arginfo_opengl_gl_gl32_gl32_glgetinteger64v, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glGetSynciv, arginfo_opengl_gl_gl32_gl32_glgetsynciv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glGetInteger64i_v, arginfo_opengl_gl_gl32_gl32_glgetinteger64i_v, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glGetBufferParameteri64v, arginfo_opengl_gl_gl32_gl32_glgetbufferparameteri64v, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glFramebufferTexture, arginfo_opengl_gl_gl32_gl32_glframebuffertexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glTexImage2DMultisample, arginfo_opengl_gl_gl32_gl32_glteximage2dmultisample, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glTexImage3DMultisample, arginfo_opengl_gl_gl32_gl32_glteximage3dmultisample, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glGetMultisamplefv, arginfo_opengl_gl_gl32_gl32_glgetmultisamplefv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL32_GL32, glSampleMaski, arginfo_opengl_gl_gl32_gl32_glsamplemaski, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
