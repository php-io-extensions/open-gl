
extern zend_class_entry *opengl_gl_gl11_gl11_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL11_GL11);

PHP_METHOD(OpenGL_GL_GL11_GL11, glDrawArrays);
PHP_METHOD(OpenGL_GL_GL11_GL11, glDrawElements);
PHP_METHOD(OpenGL_GL_GL11_GL11, glGetPointerv);
PHP_METHOD(OpenGL_GL_GL11_GL11, glPolygonOffset);
PHP_METHOD(OpenGL_GL_GL11_GL11, glCopyTexImage1D);
PHP_METHOD(OpenGL_GL_GL11_GL11, glCopyTexImage2D);
PHP_METHOD(OpenGL_GL_GL11_GL11, glCopyTexSubImage1D);
PHP_METHOD(OpenGL_GL_GL11_GL11, glCopyTexSubImage2D);
PHP_METHOD(OpenGL_GL_GL11_GL11, glTexSubImage1D);
PHP_METHOD(OpenGL_GL_GL11_GL11, glTexSubImage2D);
PHP_METHOD(OpenGL_GL_GL11_GL11, glBindTexture);
PHP_METHOD(OpenGL_GL_GL11_GL11, glDeleteTextures);
PHP_METHOD(OpenGL_GL_GL11_GL11, glGenTextures);
PHP_METHOD(OpenGL_GL_GL11_GL11, glIsTexture);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_gldrawarrays, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, first, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_gldrawelements, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indices, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_glgetpointerv, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_glpolygonoffset, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, factor, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, units, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_glcopyteximage1d, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, border, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_glcopyteximage2d, 0, 8, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, border, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_glcopytexsubimage1d, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_glcopytexsubimage2d, 0, 8, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_gltexsubimage1d, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_gltexsubimage2d, 0, 9, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_glbindtexture, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_gldeletetextures, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, n, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, textures, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_glgentextures, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, n, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, textures, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl11_gl11_glistexture, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl11_gl11_method_entry) {
	PHP_ME(OpenGL_GL_GL11_GL11, glDrawArrays, arginfo_opengl_gl_gl11_gl11_gldrawarrays, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glDrawElements, arginfo_opengl_gl_gl11_gl11_gldrawelements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glGetPointerv, arginfo_opengl_gl_gl11_gl11_glgetpointerv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glPolygonOffset, arginfo_opengl_gl_gl11_gl11_glpolygonoffset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glCopyTexImage1D, arginfo_opengl_gl_gl11_gl11_glcopyteximage1d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glCopyTexImage2D, arginfo_opengl_gl_gl11_gl11_glcopyteximage2d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glCopyTexSubImage1D, arginfo_opengl_gl_gl11_gl11_glcopytexsubimage1d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glCopyTexSubImage2D, arginfo_opengl_gl_gl11_gl11_glcopytexsubimage2d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glTexSubImage1D, arginfo_opengl_gl_gl11_gl11_gltexsubimage1d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glTexSubImage2D, arginfo_opengl_gl_gl11_gl11_gltexsubimage2d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glBindTexture, arginfo_opengl_gl_gl11_gl11_glbindtexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glDeleteTextures, arginfo_opengl_gl_gl11_gl11_gldeletetextures, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glGenTextures, arginfo_opengl_gl_gl11_gl11_glgentextures, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL11_GL11, glIsTexture, arginfo_opengl_gl_gl11_gl11_glistexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
