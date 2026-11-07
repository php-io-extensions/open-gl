#include "runtime.h"

/* Bytes a pixel of format/type takes, from the GL 4.1 and ES 3.0 pixel tables. False for a pair
 * neither table has: GL answers GL_INVALID_ENUM or GL_INVALID_OPERATION and reads nothing. */
static bool opengl_pixel_bytes(GLenum format, GLenum type, size_t *bytes)
{
	size_t components, size;

	switch (type) {
#ifdef GL_UNSIGNED_BYTE_3_3_2
		case GL_UNSIGNED_BYTE_3_3_2:
		case GL_UNSIGNED_BYTE_2_3_3_REV:
			*bytes = 1;
			return true;
#endif
		case GL_UNSIGNED_SHORT_5_6_5:
		case GL_UNSIGNED_SHORT_4_4_4_4:
		case GL_UNSIGNED_SHORT_5_5_5_1:
#ifdef GL_UNSIGNED_SHORT_5_6_5_REV
		case GL_UNSIGNED_SHORT_5_6_5_REV:
		case GL_UNSIGNED_SHORT_4_4_4_4_REV:
		case GL_UNSIGNED_SHORT_1_5_5_5_REV:
#endif
			*bytes = 2;
			return true;
		case GL_UNSIGNED_INT_2_10_10_10_REV:
		case GL_UNSIGNED_INT_24_8:
		case GL_UNSIGNED_INT_10F_11F_11F_REV:
		case GL_UNSIGNED_INT_5_9_9_9_REV:
#ifdef GL_UNSIGNED_INT_8_8_8_8
		case GL_UNSIGNED_INT_8_8_8_8:
		case GL_UNSIGNED_INT_8_8_8_8_REV:
		case GL_UNSIGNED_INT_10_10_10_2:
#endif
			*bytes = 4;
			return true;
		case GL_FLOAT_32_UNSIGNED_INT_24_8_REV:
			*bytes = 8;
			return true;
		case GL_UNSIGNED_BYTE:
		case GL_BYTE:
			size = 1;
			break;
		case GL_UNSIGNED_SHORT:
		case GL_SHORT:
		case GL_HALF_FLOAT:
			size = 2;
			break;
		case GL_UNSIGNED_INT:
		case GL_INT:
		case GL_FLOAT:
			size = 4;
			break;
		default:
			return false;
	}

	switch (format) {
		case GL_RED:
		case GL_RED_INTEGER:
		case GL_DEPTH_COMPONENT:
#ifdef GL_STENCIL_INDEX
		case GL_STENCIL_INDEX:
		case GL_GREEN:
		case GL_BLUE:
#endif
#ifdef GL_ALPHA
		case GL_ALPHA:
#endif
#ifdef GL_LUMINANCE
		case GL_LUMINANCE:
#endif
			components = 1;
			break;
		case GL_RG:
		case GL_RG_INTEGER:
		case GL_DEPTH_STENCIL:
#ifdef GL_LUMINANCE_ALPHA
		case GL_LUMINANCE_ALPHA:
#endif
			components = 2;
			break;
		case GL_RGB:
		case GL_RGB_INTEGER:
#ifdef GL_BGR
		case GL_BGR:
		case GL_BGR_INTEGER:
#endif
			components = 3;
			break;
		case GL_RGBA:
		case GL_RGBA_INTEGER:
#ifdef GL_BGRA
		case GL_BGRA:
#endif
#ifdef GL_BGRA_INTEGER
		case GL_BGRA_INTEGER:
#endif
			components = 4;
			break;
		default:
			return false;
	}

	*bytes = components * size;
	return true;
}

/* Bytes GL reads for a width x height upload under the unpack state:
 * row length = UNPACK_ROW_LENGTH ?: width; stride = that times the pixel, rounded up to UNPACK_ALIGNMENT;
 * read = SKIP_ROWS * stride + SKIP_PIXELS * pixel + stride * (height - 1) + width * pixel.
 * 0 when GL reads nothing: a size of 0 or below, or a format/type pair GL refuses. */
static size_t opengl_upload_bytes(GLenum format, GLenum type, zend_long width, zend_long height)
{
	size_t pixel, stride;
	GLint alignment = 4, row_length = 0, skip_rows = 0, skip_pixels = 0;

	if ((GLsizei) width <= 0 || (GLsizei) height <= 0 || !opengl_pixel_bytes(format, type, &pixel)) {
		return 0;
	}

	glGetIntegerv(GL_UNPACK_ALIGNMENT, &alignment);
	glGetIntegerv(GL_UNPACK_ROW_LENGTH, &row_length);
	glGetIntegerv(GL_UNPACK_SKIP_ROWS, &skip_rows);
	glGetIntegerv(GL_UNPACK_SKIP_PIXELS, &skip_pixels);
	if (alignment < 1) {
		alignment = 1;
	}

	stride = (size_t) (row_length > 0 ? row_length : (GLsizei) width) * pixel;
	stride = (stride + (size_t) alignment - 1) / (size_t) alignment * (size_t) alignment;

	return (size_t) (skip_rows > 0 ? skip_rows : 0) * stride + (size_t) (skip_pixels > 0 ? skip_pixels : 0) * pixel
		+ stride * (size_t) ((GLsizei) height - 1) + (size_t) (GLsizei) width * pixel;
}

static bool opengl_buffer_bound(GLenum binding)
{
	GLint bound = 0;

	glGetIntegerv(binding, &bound);
	return bound != 0;
}

ZEND_FUNCTION(glGenTextures)
{
	zend_long n;
	zval *textures;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ZVAL(textures)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_gen_names(n, textures, glGenTextures)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glBindTexture)
{
	zend_long target, texture;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(texture)
	ZEND_PARSE_PARAMETERS_END();

	glBindTexture((GLenum) target, (GLuint) texture);
}

ZEND_FUNCTION(glTexImage2D)
{
	zend_long target, level, internalformat, width, height, border, format, type, address = 0;
	zend_string *pixels = NULL;
	bool is_null = false;
	const void *ptr;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(9, 9)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(border)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_STR_OR_LONG_OR_NULL(pixels, address, is_null)
	ZEND_PARSE_PARAMETERS_END();

	/* NULL (null or 0) allocates the image without data. */
	if (!opengl_source(pixels, address, pixels != NULL ? opengl_upload_bytes((GLenum) format, (GLenum) type, width, height) : 0, false, 9, &ptr)) {
		RETURN_THROWS();
	}

	glTexImage2D((GLenum) target, (GLint) level, (GLint) internalformat, (GLsizei) width, (GLsizei) height, (GLint) border, (GLenum) format, (GLenum) type, ptr);
}

ZEND_FUNCTION(glTexSubImage2D)
{
	zend_long target, level, xoffset, yoffset, width, height, format, type, address = 0;
	zend_string *pixels = NULL;
	const void *ptr;
	size_t need;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(9, 9)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(xoffset)
		Z_PARAM_LONG(yoffset)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_STR_OR_LONG(pixels, address)
	ZEND_PARSE_PARAMETERS_END();

	need = opengl_upload_bytes((GLenum) format, (GLenum) type, width, height);
	if (!opengl_source(pixels, address, need, need > 0 && pixels == NULL && !opengl_buffer_bound(GL_PIXEL_UNPACK_BUFFER_BINDING), 9, &ptr)) {
		RETURN_THROWS();
	}

	glTexSubImage2D((GLenum) target, (GLint) level, (GLint) xoffset, (GLint) yoffset, (GLsizei) width, (GLsizei) height, (GLenum) format, (GLenum) type, ptr);
}

ZEND_FUNCTION(glTexParameteri)
{
	zend_long target, pname, param;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();

	glTexParameteri((GLenum) target, (GLenum) pname, (GLint) param);
}

ZEND_FUNCTION(glActiveTexture)
{
	zend_long texture;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(texture)
	ZEND_PARSE_PARAMETERS_END();

	glActiveTexture((GLenum) texture);
}

ZEND_FUNCTION(glDeleteTextures)
{
	zend_long n;
	HashTable *textures;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ARRAY_HT(textures)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_delete_names(n, textures, 2, glDeleteTextures)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glPixelStorei)
{
	zend_long pname, param;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();

	glPixelStorei((GLenum) pname, (GLint) param);
}

ZEND_FUNCTION(glGenFramebuffers)
{
	zend_long n;
	zval *framebuffers;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ZVAL(framebuffers)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_gen_names(n, framebuffers, glGenFramebuffers)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glBindFramebuffer)
{
	zend_long target, framebuffer;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(framebuffer)
	ZEND_PARSE_PARAMETERS_END();

	glBindFramebuffer((GLenum) target, (GLuint) framebuffer);
}

ZEND_FUNCTION(glFramebufferTexture2D)
{
	zend_long target, attachment, textarget, texture, level;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(attachment)
		Z_PARAM_LONG(textarget)
		Z_PARAM_LONG(texture)
		Z_PARAM_LONG(level)
	ZEND_PARSE_PARAMETERS_END();

	glFramebufferTexture2D((GLenum) target, (GLenum) attachment, (GLenum) textarget, (GLuint) texture, (GLint) level);
}

ZEND_FUNCTION(glCheckFramebufferStatus)
{
	zend_long target;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(target)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) glCheckFramebufferStatus((GLenum) target));
}

ZEND_FUNCTION(glDeleteFramebuffers)
{
	zend_long n;
	HashTable *framebuffers;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ARRAY_HT(framebuffers)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_delete_names(n, framebuffers, 2, glDeleteFramebuffers)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glGenRenderbuffers)
{
	zend_long n;
	zval *renderbuffers;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ZVAL(renderbuffers)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_gen_names(n, renderbuffers, glGenRenderbuffers)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glBindRenderbuffer)
{
	zend_long target, renderbuffer;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(renderbuffer)
	ZEND_PARSE_PARAMETERS_END();

	glBindRenderbuffer((GLenum) target, (GLuint) renderbuffer);
}

ZEND_FUNCTION(glRenderbufferStorage)
{
	zend_long target, internalformat, width, height;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	glRenderbufferStorage((GLenum) target, (GLenum) internalformat, (GLsizei) width, (GLsizei) height);
}

ZEND_FUNCTION(glRenderbufferStorageMultisample)
{
	zend_long target, samples, internalformat, width, height;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(samples)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	glRenderbufferStorageMultisample((GLenum) target, (GLsizei) samples, (GLenum) internalformat, (GLsizei) width, (GLsizei) height);
}

ZEND_FUNCTION(glFramebufferRenderbuffer)
{
	zend_long target, attachment, renderbuffertarget, renderbuffer;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(attachment)
		Z_PARAM_LONG(renderbuffertarget)
		Z_PARAM_LONG(renderbuffer)
	ZEND_PARSE_PARAMETERS_END();

	glFramebufferRenderbuffer((GLenum) target, (GLenum) attachment, (GLenum) renderbuffertarget, (GLuint) renderbuffer);
}

ZEND_FUNCTION(glDeleteRenderbuffers)
{
	zend_long n;
	HashTable *renderbuffers;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ARRAY_HT(renderbuffers)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_delete_names(n, renderbuffers, 2, glDeleteRenderbuffers)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glBlitFramebuffer)
{
	zend_long srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(10, 10)
		Z_PARAM_LONG(srcX0)
		Z_PARAM_LONG(srcY0)
		Z_PARAM_LONG(srcX1)
		Z_PARAM_LONG(srcY1)
		Z_PARAM_LONG(dstX0)
		Z_PARAM_LONG(dstY0)
		Z_PARAM_LONG(dstX1)
		Z_PARAM_LONG(dstY1)
		Z_PARAM_LONG(mask)
		Z_PARAM_LONG(filter)
	ZEND_PARSE_PARAMETERS_END();

	glBlitFramebuffer((GLint) srcX0, (GLint) srcY0, (GLint) srcX1, (GLint) srcY1, (GLint) dstX0, (GLint) dstY0, (GLint) dstX1, (GLint) dstY1, (GLbitfield) mask, (GLenum) filter);
}

ZEND_FUNCTION(glDrawBuffers)
{
	zend_long n;
	HashTable *bufs;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ARRAY_HT(bufs)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_delete_names(n, bufs, 2, (void (*)(GLsizei, const GLuint *)) glDrawBuffers)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glReadBuffer)
{
	zend_long src;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(src)
	ZEND_PARSE_PARAMETERS_END();

	glReadBuffer((GLenum) src);
}

ZEND_FUNCTION(glReadPixels)
{
	zend_long x, y, width, height, format, type, address = 0;
	bool is_null = false;
	const void *ptr;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG_OR_NULL(address, is_null)
	ZEND_PARSE_PARAMETERS_END();

	/* GL writes to address 0 unless a pixel-pack buffer takes it as an offset. */
	if (!opengl_source(NULL, address, 0, (GLsizei) width > 0 && (GLsizei) height > 0 && !opengl_buffer_bound(GL_PIXEL_PACK_BUFFER_BINDING), 7, &ptr)) {
		RETURN_THROWS();
	}

	glReadPixels((GLint) x, (GLint) y, (GLsizei) width, (GLsizei) height, (GLenum) format, (GLenum) type, (void *) ptr);
}
