
extern zend_class_entry *opengl_bridge_bridge_ce;

ZEPHIR_INIT_CLASS(OpenGL_Bridge_Bridge);

PHP_METHOD(OpenGL_Bridge_Bridge, load);
PHP_METHOD(OpenGL_Bridge_Bridge, isAvailable);
PHP_METHOD(OpenGL_Bridge_Bridge, procAddress);
PHP_METHOD(OpenGL_Bridge_Bridge, contextVersion);
PHP_METHOD(OpenGL_Bridge_Bridge, alloc);
PHP_METHOD(OpenGL_Bridge_Bridge, free);
PHP_METHOD(OpenGL_Bridge_Bridge, write);
PHP_METHOD(OpenGL_Bridge_Bridge, read);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_bridge_bridge_load, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_bridge_bridge_isavailable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_bridge_bridge_procaddress, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_bridge_bridge_contextversion, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_bridge_bridge_alloc, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_bridge_bridge_free, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_bridge_bridge_write, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bytes, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_opengl_bridge_bridge_read, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, ptr, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_bridge_bridge_method_entry) {
	PHP_ME(OpenGL_Bridge_Bridge, load, arginfo_opengl_bridge_bridge_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_Bridge_Bridge, isAvailable, arginfo_opengl_bridge_bridge_isavailable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_Bridge_Bridge, procAddress, arginfo_opengl_bridge_bridge_procaddress, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_Bridge_Bridge, contextVersion, arginfo_opengl_bridge_bridge_contextversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_Bridge_Bridge, alloc, arginfo_opengl_bridge_bridge_alloc, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_Bridge_Bridge, free, arginfo_opengl_bridge_bridge_free, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_Bridge_Bridge, write, arginfo_opengl_bridge_bridge_write, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_Bridge_Bridge, read, arginfo_opengl_bridge_bridge_read, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
