
extern zend_class_entry *opengl_gl_gl13_gl13_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL13_GL13);

PHP_METHOD(OpenGL_GL_GL13_GL13, glActiveTexture);
PHP_METHOD(OpenGL_GL_GL13_GL13, glSampleCoverage);
PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexImage3D);
PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexImage2D);
PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexImage1D);
PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexSubImage3D);
PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexSubImage2D);
PHP_METHOD(OpenGL_GL_GL13_GL13, glCompressedTexSubImage1D);
PHP_METHOD(OpenGL_GL_GL13_GL13, glGetCompressedTexImage);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl13_gl13_glactivetexture, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, texture, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl13_gl13_glsamplecoverage, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, invert, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl13_gl13_glcompressedteximage3d, 0, 9, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, border, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl13_gl13_glcompressedteximage2d, 0, 8, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, border, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl13_gl13_glcompressedteximage1d, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, border, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl13_gl13_glcompressedtexsubimage3d, 0, 11, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, zoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl13_gl13_glcompressedtexsubimage2d, 0, 9, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl13_gl13_glcompressedtexsubimage1d, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, imageSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl13_gl13_glgetcompressedteximage, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, img, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl13_gl13_method_entry) {
	PHP_ME(OpenGL_GL_GL13_GL13, glActiveTexture, arginfo_opengl_gl_gl13_gl13_glactivetexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL13_GL13, glSampleCoverage, arginfo_opengl_gl_gl13_gl13_glsamplecoverage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL13_GL13, glCompressedTexImage3D, arginfo_opengl_gl_gl13_gl13_glcompressedteximage3d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL13_GL13, glCompressedTexImage2D, arginfo_opengl_gl_gl13_gl13_glcompressedteximage2d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL13_GL13, glCompressedTexImage1D, arginfo_opengl_gl_gl13_gl13_glcompressedteximage1d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL13_GL13, glCompressedTexSubImage3D, arginfo_opengl_gl_gl13_gl13_glcompressedtexsubimage3d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL13_GL13, glCompressedTexSubImage2D, arginfo_opengl_gl_gl13_gl13_glcompressedtexsubimage2d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL13_GL13, glCompressedTexSubImage1D, arginfo_opengl_gl_gl13_gl13_glcompressedtexsubimage1d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL13_GL13, glGetCompressedTexImage, arginfo_opengl_gl_gl13_gl13_glgetcompressedteximage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
