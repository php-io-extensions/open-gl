
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_OPENGL_H
#define PHP_OPENGL_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_OPENGL_NAME        "opengl"
#define PHP_OPENGL_VERSION     "0.7.0"
#define PHP_OPENGL_EXTNAME     "opengl"
#define PHP_OPENGL_AUTHOR      "Project Saturn Studios, LLC"
#define PHP_OPENGL_ZEPVERSION  "0.19.0-$Id$"
#define PHP_OPENGL_DESCRIPTION "PHP-Controllable OpenGL Rendering Extension"



ZEND_BEGIN_MODULE_GLOBALS(opengl)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(opengl)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(opengl)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(opengl, v)
#else
	#define ZEPHIR_GLOBAL(v) (opengl_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_opengl_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(opengl_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(opengl_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def opengl_globals
#define zend_zephir_globals_def zend_opengl_globals

extern zend_module_entry opengl_module_entry;
#define phpext_opengl_ptr &opengl_module_entry

#endif
