
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
 * OpenGL program object (GLuint name).
 *
 * `fd` holds the GLuint program name as an opaque int (0 = none).
 */
ZEPHIR_INIT_CLASS(Opengl_GL_GlProgram)
{
	ZEPHIR_REGISTER_CLASS(Opengl\\GL, GlProgram, opengl, gl_glprogram, NULL, 0);

	/** Opaque GLuint program name. 0 = unallocated / deleted. */
	zend_declare_property_long(opengl_gl_glprogram_ce, SL("fd"), 0, ZEND_ACC_PUBLIC);
	/** Non-zero after a successful link. */
	zend_declare_property_long(opengl_gl_glprogram_ce, SL("linked"), 0, ZEND_ACC_PUBLIC);
	return SUCCESS;
}

