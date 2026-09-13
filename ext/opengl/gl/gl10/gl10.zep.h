
extern zend_class_entry *opengl_gl_gl10_gl10_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL10_GL10);

PHP_METHOD(OpenGL_GL_GL10_GL10, glCullFace);
PHP_METHOD(OpenGL_GL_GL10_GL10, glFrontFace);
PHP_METHOD(OpenGL_GL_GL10_GL10, glHint);
PHP_METHOD(OpenGL_GL_GL10_GL10, glLineWidth);
PHP_METHOD(OpenGL_GL_GL10_GL10, glPointSize);
PHP_METHOD(OpenGL_GL_GL10_GL10, glPolygonMode);
PHP_METHOD(OpenGL_GL_GL10_GL10, glScissor);
PHP_METHOD(OpenGL_GL_GL10_GL10, glTexParameterf);
PHP_METHOD(OpenGL_GL_GL10_GL10, glTexParameterfv);
PHP_METHOD(OpenGL_GL_GL10_GL10, glTexParameteri);
PHP_METHOD(OpenGL_GL_GL10_GL10, glTexParameteriv);
PHP_METHOD(OpenGL_GL_GL10_GL10, glTexImage1D);
PHP_METHOD(OpenGL_GL_GL10_GL10, glTexImage2D);
PHP_METHOD(OpenGL_GL_GL10_GL10, glDrawBuffer);
PHP_METHOD(OpenGL_GL_GL10_GL10, glClear);
PHP_METHOD(OpenGL_GL_GL10_GL10, glClearColor);
PHP_METHOD(OpenGL_GL_GL10_GL10, glClearStencil);
PHP_METHOD(OpenGL_GL_GL10_GL10, glClearDepth);
PHP_METHOD(OpenGL_GL_GL10_GL10, glStencilMask);
PHP_METHOD(OpenGL_GL_GL10_GL10, glColorMask);
PHP_METHOD(OpenGL_GL_GL10_GL10, glDepthMask);
PHP_METHOD(OpenGL_GL_GL10_GL10, glDisable);
PHP_METHOD(OpenGL_GL_GL10_GL10, glEnable);
PHP_METHOD(OpenGL_GL_GL10_GL10, glFinish);
PHP_METHOD(OpenGL_GL_GL10_GL10, glFlush);
PHP_METHOD(OpenGL_GL_GL10_GL10, glBlendFunc);
PHP_METHOD(OpenGL_GL_GL10_GL10, glLogicOp);
PHP_METHOD(OpenGL_GL_GL10_GL10, glStencilFunc);
PHP_METHOD(OpenGL_GL_GL10_GL10, glStencilOp);
PHP_METHOD(OpenGL_GL_GL10_GL10, glDepthFunc);
PHP_METHOD(OpenGL_GL_GL10_GL10, glPixelStoref);
PHP_METHOD(OpenGL_GL_GL10_GL10, glPixelStorei);
PHP_METHOD(OpenGL_GL_GL10_GL10, glReadBuffer);
PHP_METHOD(OpenGL_GL_GL10_GL10, glReadPixels);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetBooleanv);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetDoublev);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetError);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetFloatv);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetIntegerv);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetString);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetTexImage);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetTexParameterfv);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetTexParameteriv);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetTexLevelParameterfv);
PHP_METHOD(OpenGL_GL_GL10_GL10, glGetTexLevelParameteriv);
PHP_METHOD(OpenGL_GL_GL10_GL10, glIsEnabled);
PHP_METHOD(OpenGL_GL_GL10_GL10, glDepthRange);
PHP_METHOD(OpenGL_GL_GL10_GL10, glViewport);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glcullface, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glfrontface, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glhint, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gllinewidth, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glpointsize, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, size, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glpolygonmode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, face, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glscissor, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gltexparameterf, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gltexparameterfv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gltexparameteri, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gltexparameteriv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glteximage1d, 0, 8, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, border, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glteximage2d, 0, 9, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, border, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gldrawbuffer, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, buf, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glclear, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glclearcolor, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glclearstencil, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, s, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glcleardepth, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, depth, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glstencilmask, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glcolormask, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, red, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, green, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, blue, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gldepthmask, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, flag, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gldisable, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, cap, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glenable, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, cap, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glfinish, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glflush, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glblendfunc, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sfactor, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dfactor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gllogicop, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, opcode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glstencilfunc, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, func, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ref, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glstencilop, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, fail, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, zfail, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, zpass, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gldepthfunc, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, func, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glpixelstoref, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glpixelstorei, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glreadbuffer, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, src, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glreadpixels, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgetbooleanv, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgetdoublev, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgeterror, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgetfloatv, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgetintegerv, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgetstring, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgetteximage, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgettexparameterfv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgettexparameteriv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgettexlevelparameterfv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glgettexlevelparameteriv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glisenabled, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, cap, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_gldepthrange, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, n, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, f, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl10_gl10_glviewport, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl10_gl10_method_entry) {
	PHP_ME(OpenGL_GL_GL10_GL10, glCullFace, arginfo_opengl_gl_gl10_gl10_glcullface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glFrontFace, arginfo_opengl_gl_gl10_gl10_glfrontface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glHint, arginfo_opengl_gl_gl10_gl10_glhint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glLineWidth, arginfo_opengl_gl_gl10_gl10_gllinewidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glPointSize, arginfo_opengl_gl_gl10_gl10_glpointsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glPolygonMode, arginfo_opengl_gl_gl10_gl10_glpolygonmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glScissor, arginfo_opengl_gl_gl10_gl10_glscissor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glTexParameterf, arginfo_opengl_gl_gl10_gl10_gltexparameterf, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glTexParameterfv, arginfo_opengl_gl_gl10_gl10_gltexparameterfv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glTexParameteri, arginfo_opengl_gl_gl10_gl10_gltexparameteri, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glTexParameteriv, arginfo_opengl_gl_gl10_gl10_gltexparameteriv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glTexImage1D, arginfo_opengl_gl_gl10_gl10_glteximage1d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glTexImage2D, arginfo_opengl_gl_gl10_gl10_glteximage2d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glDrawBuffer, arginfo_opengl_gl_gl10_gl10_gldrawbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glClear, arginfo_opengl_gl_gl10_gl10_glclear, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glClearColor, arginfo_opengl_gl_gl10_gl10_glclearcolor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glClearStencil, arginfo_opengl_gl_gl10_gl10_glclearstencil, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glClearDepth, arginfo_opengl_gl_gl10_gl10_glcleardepth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glStencilMask, arginfo_opengl_gl_gl10_gl10_glstencilmask, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glColorMask, arginfo_opengl_gl_gl10_gl10_glcolormask, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glDepthMask, arginfo_opengl_gl_gl10_gl10_gldepthmask, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glDisable, arginfo_opengl_gl_gl10_gl10_gldisable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glEnable, arginfo_opengl_gl_gl10_gl10_glenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glFinish, arginfo_opengl_gl_gl10_gl10_glfinish, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glFlush, arginfo_opengl_gl_gl10_gl10_glflush, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glBlendFunc, arginfo_opengl_gl_gl10_gl10_glblendfunc, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glLogicOp, arginfo_opengl_gl_gl10_gl10_gllogicop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glStencilFunc, arginfo_opengl_gl_gl10_gl10_glstencilfunc, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glStencilOp, arginfo_opengl_gl_gl10_gl10_glstencilop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glDepthFunc, arginfo_opengl_gl_gl10_gl10_gldepthfunc, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glPixelStoref, arginfo_opengl_gl_gl10_gl10_glpixelstoref, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glPixelStorei, arginfo_opengl_gl_gl10_gl10_glpixelstorei, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glReadBuffer, arginfo_opengl_gl_gl10_gl10_glreadbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glReadPixels, arginfo_opengl_gl_gl10_gl10_glreadpixels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetBooleanv, arginfo_opengl_gl_gl10_gl10_glgetbooleanv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetDoublev, arginfo_opengl_gl_gl10_gl10_glgetdoublev, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetError, arginfo_opengl_gl_gl10_gl10_glgeterror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetFloatv, arginfo_opengl_gl_gl10_gl10_glgetfloatv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetIntegerv, arginfo_opengl_gl_gl10_gl10_glgetintegerv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetString, arginfo_opengl_gl_gl10_gl10_glgetstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetTexImage, arginfo_opengl_gl_gl10_gl10_glgetteximage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetTexParameterfv, arginfo_opengl_gl_gl10_gl10_glgettexparameterfv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetTexParameteriv, arginfo_opengl_gl_gl10_gl10_glgettexparameteriv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetTexLevelParameterfv, arginfo_opengl_gl_gl10_gl10_glgettexlevelparameterfv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glGetTexLevelParameteriv, arginfo_opengl_gl_gl10_gl10_glgettexlevelparameteriv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glIsEnabled, arginfo_opengl_gl_gl10_gl10_glisenabled, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glDepthRange, arginfo_opengl_gl_gl10_gl10_gldepthrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL10_GL10, glViewport, arginfo_opengl_gl_gl10_gl10_glviewport, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
