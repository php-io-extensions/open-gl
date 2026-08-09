
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "opengl.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *opengl_gl_gl_ce;
zend_class_entry *opengl_gl_glbuffer_ce;
zend_class_entry *opengl_gl_glprogram_ce;
zend_class_entry *opengl_gl_glshader_ce;
zend_class_entry *opengl_gl_gltexture_ce;

ZEND_DECLARE_MODULE_GLOBALS(opengl)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(opengl)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Opengl_GL_GL);
	ZEPHIR_INIT(Opengl_GL_GlBuffer);
	ZEPHIR_INIT(Opengl_GL_GlProgram);
	ZEPHIR_INIT(Opengl_GL_GlShader);
	ZEPHIR_INIT(Opengl_GL_GlTexture);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(opengl)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

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
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(opengl),
#else
	NULL,
#endif
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
