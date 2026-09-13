
extern zend_class_entry *opengl_gl_gl12_gl12_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL12_GL12);

PHP_METHOD(OpenGL_GL_GL12_GL12, glDrawRangeElements);
PHP_METHOD(OpenGL_GL_GL12_GL12, glTexImage3D);
PHP_METHOD(OpenGL_GL_GL12_GL12, glTexSubImage3D);
PHP_METHOD(OpenGL_GL_GL12_GL12, glCopyTexSubImage3D);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl12_gl12_gldrawrangeelements, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, start, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, end, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indices, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl12_gl12_glteximage3d, 0, 10, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalformat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, border, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl12_gl12_gltexsubimage3d, 0, 11, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, zoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, depth, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, format, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl12_gl12_glcopytexsubimage3d, 0, 9, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, zoffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl12_gl12_method_entry) {
	PHP_ME(OpenGL_GL_GL12_GL12, glDrawRangeElements, arginfo_opengl_gl_gl12_gl12_gldrawrangeelements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL12_GL12, glTexImage3D, arginfo_opengl_gl_gl12_gl12_glteximage3d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL12_GL12, glTexSubImage3D, arginfo_opengl_gl_gl12_gl12_gltexsubimage3d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL12_GL12, glCopyTexSubImage3D, arginfo_opengl_gl_gl12_gl12_glcopytexsubimage3d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
