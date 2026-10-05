#include "runtime.h"

ZEND_FUNCTION(glViewport)
{
	zend_long x, y, width, height;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	glViewport((GLint) x, (GLint) y, (GLsizei) width, (GLsizei) height);
}

ZEND_FUNCTION(glScissor)
{
	zend_long x, y, width, height;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	glScissor((GLint) x, (GLint) y, (GLsizei) width, (GLsizei) height);
}

ZEND_FUNCTION(glEnable)
{
	zend_long cap;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(cap)
	ZEND_PARSE_PARAMETERS_END();

	glEnable((GLenum) cap);
}

ZEND_FUNCTION(glDisable)
{
	zend_long cap;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(cap)
	ZEND_PARSE_PARAMETERS_END();

	glDisable((GLenum) cap);
}

ZEND_FUNCTION(glBlendFunc)
{
	zend_long sfactor, dfactor;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(sfactor)
		Z_PARAM_LONG(dfactor)
	ZEND_PARSE_PARAMETERS_END();

	glBlendFunc((GLenum) sfactor, (GLenum) dfactor);
}

ZEND_FUNCTION(glBlendFuncSeparate)
{
	zend_long src_rgb, dst_rgb, src_alpha, dst_alpha;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(src_rgb)
		Z_PARAM_LONG(dst_rgb)
		Z_PARAM_LONG(src_alpha)
		Z_PARAM_LONG(dst_alpha)
	ZEND_PARSE_PARAMETERS_END();

	glBlendFuncSeparate((GLenum) src_rgb, (GLenum) dst_rgb, (GLenum) src_alpha, (GLenum) dst_alpha);
}

ZEND_FUNCTION(glBlendEquation)
{
	zend_long mode;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();

	glBlendEquation((GLenum) mode);
}

ZEND_FUNCTION(glColorMask)
{
	bool red, green, blue, alpha;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_BOOL(red)
		Z_PARAM_BOOL(green)
		Z_PARAM_BOOL(blue)
		Z_PARAM_BOOL(alpha)
	ZEND_PARSE_PARAMETERS_END();

	glColorMask(red ? GL_TRUE : GL_FALSE, green ? GL_TRUE : GL_FALSE, blue ? GL_TRUE : GL_FALSE, alpha ? GL_TRUE : GL_FALSE);
}

ZEND_FUNCTION(glClearColor)
{
	double red, green, blue, alpha;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_DOUBLE(red)
		Z_PARAM_DOUBLE(green)
		Z_PARAM_DOUBLE(blue)
		Z_PARAM_DOUBLE(alpha)
	ZEND_PARSE_PARAMETERS_END();

	glClearColor((GLfloat) red, (GLfloat) green, (GLfloat) blue, (GLfloat) alpha);
}

ZEND_FUNCTION(glClearStencil)
{
	zend_long s;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(s)
	ZEND_PARSE_PARAMETERS_END();

	glClearStencil((GLint) s);
}

ZEND_FUNCTION(glClear)
{
	zend_long mask;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();

	glClear((GLbitfield) mask);
}

ZEND_FUNCTION(glStencilFunc)
{
	zend_long func, ref, mask;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(func)
		Z_PARAM_LONG(ref)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();

	glStencilFunc((GLenum) func, (GLint) ref, (GLuint) mask);
}

ZEND_FUNCTION(glStencilOp)
{
	zend_long sfail, dpfail, dppass;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(sfail)
		Z_PARAM_LONG(dpfail)
		Z_PARAM_LONG(dppass)
	ZEND_PARSE_PARAMETERS_END();

	glStencilOp((GLenum) sfail, (GLenum) dpfail, (GLenum) dppass);
}

ZEND_FUNCTION(glStencilOpSeparate)
{
	zend_long face, sfail, dpfail, dppass;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(face)
		Z_PARAM_LONG(sfail)
		Z_PARAM_LONG(dpfail)
		Z_PARAM_LONG(dppass)
	ZEND_PARSE_PARAMETERS_END();

	glStencilOpSeparate((GLenum) face, (GLenum) sfail, (GLenum) dpfail, (GLenum) dppass);
}

ZEND_FUNCTION(glStencilMask)
{
	zend_long mask;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();

	glStencilMask((GLuint) mask);
}

ZEND_FUNCTION(glCullFace)
{
	zend_long mode;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();

	glCullFace((GLenum) mode);
}

ZEND_FUNCTION(glFrontFace)
{
	zend_long mode;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();

	glFrontFace((GLenum) mode);
}

ZEND_FUNCTION(glDrawArrays)
{
	zend_long mode, first, count;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(first)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();

	glDrawArrays((GLenum) mode, (GLint) first, (GLsizei) count);
}

ZEND_FUNCTION(glDrawElements)
{
	zend_long mode, count, type, indices;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(count)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(indices)
	ZEND_PARSE_PARAMETERS_END();

	glDrawElements((GLenum) mode, (GLsizei) count, (GLenum) type, (const void *) (uintptr_t) indices);
}
