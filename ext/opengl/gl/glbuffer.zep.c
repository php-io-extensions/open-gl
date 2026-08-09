
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


/**
 * OpenGL buffer object (GLuint name).
 *
 * `fd` holds the GLuint buffer name as an opaque int (0 = none).
 */
ZEPHIR_INIT_CLASS(Opengl_GL_GlBuffer)
{
	ZEPHIR_REGISTER_CLASS(Opengl\\GL, GlBuffer, opengl, gl_glbuffer, NULL, 0);

	/** Opaque GLuint buffer name. 0 = unallocated / deleted. */
	zend_declare_property_long(opengl_gl_glbuffer_ce, SL("fd"), 0, ZEND_ACC_PUBLIC);
	/** Last bind target (e.g. GL_ARRAY_BUFFER). 0 = unset. */
	zend_declare_property_long(opengl_gl_glbuffer_ce, SL("target"), 0, ZEND_ACC_PUBLIC);
	/** Byte size of the last successful bufferData upload. */
	zend_declare_property_long(opengl_gl_glbuffer_ce, SL("size"), 0, ZEND_ACC_PUBLIC);
	/** Usage hint from the last bufferData call. */
	zend_declare_property_long(opengl_gl_glbuffer_ce, SL("usage"), 0, ZEND_ACC_PUBLIC);
	return SUCCESS;
}

