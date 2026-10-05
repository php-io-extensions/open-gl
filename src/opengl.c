/*
 * opengl: 1:1 bindings of the OpenGL 4.1 core and OpenGL ES 3 calls both
 * dialects share, plus CGL on macOS and EGL on Linux. Handles keep their C
 * names. Dropping the last PHP reference does not destroy the native object.
 */

#include "runtime.h"
#include "ext/standard/info.h"

ZEND_DECLARE_MODULE_GLOBALS(opengl)

static PHP_GINIT_FUNCTION(opengl)
{
#if defined(COMPILE_DL_OPENGL) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	zend_hash_init(&opengl_globals->boxes, 64, NULL, NULL, 1);
}

static PHP_GSHUTDOWN_FUNCTION(opengl)
{
	zend_hash_destroy(&opengl_globals->boxes);
}

PHP_MINIT_FUNCTION(opengl)
{
#ifdef __APPLE__
	opengl_register_cgl(module_number);
#else
	opengl_register_egl(module_number);
#endif
	opengl_register_gl_state(module_number);
	opengl_register_gl_buffer(module_number);

	return SUCCESS;
}

PHP_RINIT_FUNCTION(opengl)
{
#if defined(COMPILE_DL_OPENGL) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}

PHP_MINFO_FUNCTION(opengl)
{
	php_info_print_table_start();
	php_info_print_table_row(2, "opengl support", "enabled");
	php_info_print_table_row(2, "Version", PHP_OPENGL_VERSION);
#ifdef __APPLE__
	php_info_print_table_row(2, "Context", "CGL");
#else
	php_info_print_table_row(2, "Context", "EGL");
#endif
	php_info_print_table_end();
}

zend_module_entry opengl_module_entry = {
	STANDARD_MODULE_HEADER,
	"opengl",
	NULL,
	PHP_MINIT(opengl),
	NULL,
	PHP_RINIT(opengl),
	NULL,
	PHP_MINFO(opengl),
	PHP_OPENGL_VERSION,
	PHP_MODULE_GLOBALS(opengl),
	PHP_GINIT(opengl),
	PHP_GSHUTDOWN(opengl),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_OPENGL
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(opengl)
#endif
