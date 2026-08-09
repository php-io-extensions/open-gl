
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
 * OpenGL texture object (GLuint name).
 *
 * `fd` holds the GLuint texture name as an opaque int (0 = none).
 */
ZEPHIR_INIT_CLASS(Opengl_GL_GlTexture)
{
	ZEPHIR_REGISTER_CLASS(Opengl\\GL, GlTexture, opengl, gl_gltexture, NULL, 0);

	/** Opaque GLuint texture name. 0 = unallocated / deleted. */
	zend_declare_property_long(opengl_gl_gltexture_ce, SL("fd"), 0, ZEND_ACC_PUBLIC);
	/** Last bind target (e.g. GL_TEXTURE_2D). 0 = unset. */
	zend_declare_property_long(opengl_gl_gltexture_ce, SL("target"), 0, ZEND_ACC_PUBLIC);
	/** Width in texels (0 until set by caller after upload). */
	zend_declare_property_long(opengl_gl_gltexture_ce, SL("width"), 0, ZEND_ACC_PUBLIC);
	/** Height in texels (0 until set by caller after upload). */
	zend_declare_property_long(opengl_gl_gltexture_ce, SL("height"), 0, ZEND_ACC_PUBLIC);
	/** Internal / base format hint stored by caller (e.g. GL_RGBA). */
	zend_declare_property_long(opengl_gl_gltexture_ce, SL("format"), 0, ZEND_ACC_PUBLIC);
	return SUCCESS;
}

