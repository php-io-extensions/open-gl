
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"

/* PHPGL module teardown */
#include "src/phpgl-bridge.h"
#include "opengl.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *opengl_bridge_bridge_ce;
zend_class_entry *opengl_cgl_cgl_ce;
zend_class_entry *opengl_egl_egl_ce;
zend_class_entry *opengl_gl_gl10_gl10_ce;
zend_class_entry *opengl_gl_gl11_gl11_ce;
zend_class_entry *opengl_gl_gl12_gl12_ce;
zend_class_entry *opengl_gl_gl13_gl13_ce;
zend_class_entry *opengl_gl_gl14_gl14_ce;
zend_class_entry *opengl_gl_gl15_gl15_ce;
zend_class_entry *opengl_gl_gl20_gl20_ce;
zend_class_entry *opengl_gl_gl21_gl21_ce;
zend_class_entry *opengl_gl_gl30_gl30_ce;
zend_class_entry *opengl_gl_gl31_gl31_ce;
zend_class_entry *opengl_gl_gl32_gl32_ce;
zend_class_entry *opengl_gl_gl33_gl33_ce;
zend_class_entry *opengl_gl_gl40_gl40_ce;
zend_class_entry *opengl_gl_gl41_gl41_ce;

ZEND_DECLARE_MODULE_GLOBALS(opengl)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(opengl)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(OpenGL_Bridge_Bridge);
	ZEPHIR_INIT(OpenGL_CGL_CGL);
	ZEPHIR_INIT(OpenGL_EGL_EGL);
	ZEPHIR_INIT(OpenGL_GL_GL10_GL10);
	ZEPHIR_INIT(OpenGL_GL_GL11_GL11);
	ZEPHIR_INIT(OpenGL_GL_GL12_GL12);
	ZEPHIR_INIT(OpenGL_GL_GL13_GL13);
	ZEPHIR_INIT(OpenGL_GL_GL14_GL14);
	ZEPHIR_INIT(OpenGL_GL_GL15_GL15);
	ZEPHIR_INIT(OpenGL_GL_GL20_GL20);
	ZEPHIR_INIT(OpenGL_GL_GL21_GL21);
	ZEPHIR_INIT(OpenGL_GL_GL30_GL30);
	ZEPHIR_INIT(OpenGL_GL_GL31_GL31);
	ZEPHIR_INIT(OpenGL_GL_GL32_GL32);
	ZEPHIR_INIT(OpenGL_GL_GL33_GL33);
	ZEPHIR_INIT(OpenGL_GL_GL40_GL40);
	ZEPHIR_INIT(OpenGL_GL_GL41_GL41);
	
	return SUCCESS;
}

static PHP_MSHUTDOWN_FUNCTION(opengl)
{
	/* PHPGL module teardown: free the byte buffers the caller did not,
	 * destroy the registry, and close the loader's dlopen handles. */
	phpgl_bridge_shutdown();
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_opengl_globals *opengl_globals)
{
	opengl_globals->initialized = 0;

	/* Cache Enabled */
	opengl_globals->cache_enabled = 1;

	/* Recursive Lock */
	opengl_globals->recursive_lock = 0;

	/* Static cache */
	memset(opengl_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_opengl_globals *opengl_globals)
{
	
}

static PHP_RINIT_FUNCTION(opengl)
{
	zend_opengl_globals *opengl_globals_ptr;
	opengl_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(opengl_globals_ptr);
	zephir_initialize_memory(opengl_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(opengl)
{
	
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(opengl)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_OPENGL_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_OPENGL_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_OPENGL_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_OPENGL_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_OPENGL_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(opengl)
{
#if defined(COMPILE_DL_OPENGL) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(opengl_globals);
	php_zephir_init_module_globals(opengl_globals);
}

static PHP_GSHUTDOWN_FUNCTION(opengl)
{
	
}


zend_function_entry php_opengl_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_opengl_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry opengl_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_opengl_deps,
	PHP_OPENGL_EXTNAME,
	php_opengl_functions,
	PHP_MINIT(opengl),
	PHP_MSHUTDOWN(opengl),
	PHP_RINIT(opengl),
	PHP_RSHUTDOWN(opengl),
	PHP_MINFO(opengl),
	PHP_OPENGL_VERSION,
	ZEND_MODULE_GLOBALS(opengl),
	PHP_GINIT(opengl),
	PHP_GSHUTDOWN(opengl),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(opengl),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_OPENGL
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(opengl)
#endif
