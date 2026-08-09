
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
 * OpenGL shader object (GLuint name).
 *
 * `fd` holds the GLuint shader name as an opaque int (0 = none).
 */
ZEPHIR_INIT_CLASS(Opengl_GL_GlShader)
{
	ZEPHIR_REGISTER_CLASS(Opengl\\GL, GlShader, opengl, gl_glshader, NULL, 0);

	/** Opaque GLuint shader name. 0 = unallocated / deleted. */
	zend_declare_property_long(opengl_gl_glshader_ce, SL("fd"), 0, ZEND_ACC_PUBLIC);
	/** Shader type (GL_VERTEX_SHADER / GL_FRAGMENT_SHADER). */
	zend_declare_property_long(opengl_gl_glshader_ce, SL("type"), 0, ZEND_ACC_PUBLIC);
	/** Non-zero after a successful compile. */
	zend_declare_property_long(opengl_gl_glshader_ce, SL("compiled"), 0, ZEND_ACC_PUBLIC);
	return SUCCESS;
}

