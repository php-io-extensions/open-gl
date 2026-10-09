#include "runtime.h"

static bool opengl_names(zend_long n, void (*generate)(GLsizei, GLuint *), zval *return_value)
{
	GLuint *names;
	zend_long i;

	if (n < 0 || n > INT_MAX) {
		zend_argument_value_error(1, "must be greater than or equal to 0");
		return false;
	}

	names = ecalloc(n == 0 ? 1 : (size_t) n, sizeof(GLuint));
	if (n > 0) {
		generate((GLsizei) n, names);
	}
	array_init_size(return_value, (uint32_t) n);
	for (i = 0; i < n; i++) {
		add_next_index_long(return_value, (zend_long) names[i]);
	}
	efree(names);

	return true;
}

static bool opengl_forget(HashTable *list, void (*destroy)(GLsizei, const GLuint *), uint32_t arg_num)
{
	uint32_t n = zend_hash_num_elements(list);
	uint32_t i = 0;
	GLuint *names = NULL;
	zval *zv;

	if (n > 0) {
		names = emalloc(sizeof(GLuint) * n);
		ZEND_HASH_FOREACH_VAL(list, zv) {
			if (Z_TYPE_P(zv) != IS_LONG || Z_LVAL_P(zv) < 0 || Z_LVAL_P(zv) > (zend_long) UINT32_MAX) {
				efree(names);
				if (Z_TYPE_P(zv) != IS_LONG) {
					zend_argument_type_error(arg_num, "must be a list of ints");
				} else {
					zend_argument_value_error(arg_num, "must be greater than or equal to 0");
				}
				return false;
			}
			names[i++] = (GLuint) Z_LVAL_P(zv);
		} ZEND_HASH_FOREACH_END();
	}

	destroy((GLsizei) n, names);
	if (names != NULL) {
		efree(names);
	}

	return true;
}

static bool opengl_pixel_bytes(GLenum format, GLenum type, size_t *bytes)
{
	if (type == GL_UNSIGNED_BYTE && format == GL_RGBA) {
		*bytes = 4;
		return true;
	}
	if (type == GL_UNSIGNED_BYTE && format == GL_RGB) {
		*bytes = 3;
		return true;
	}
	if (type == GL_UNSIGNED_BYTE && format == GL_RED) {
		*bytes = 1;
		return true;
	}
	if (type == GL_HALF_FLOAT && format == GL_RGBA) {
		*bytes = 8;
		return true;
	}
	if (type == GL_UNSIGNED_INT_2_10_10_10_REV && format == GL_RGBA) {
		*bytes = 4;
		return true;
	}
	if (type == GL_FLOAT && format == GL_RGBA) {
		*bytes = 16;
		return true;
	}

	return false;
}

/* row length = ROW_LENGTH ?: width; stride = that times bytes, rounded up to ALIGNMENT;
 * required = SKIP_ROWS * stride + SKIP_PIXELS * bytes + stride * (height - 1) + width * bytes.
 * Unpack state for uploads, pack state for reads. */
static bool opengl_image_bytes(GLenum format, GLenum type, zend_long width, zend_long height, bool unpack, size_t *required)
{
	size_t pixel, columns, row, stride;
	GLint alignment = 4, row_length = 0, skip_rows = 0, skip_pixels = 0;

	if (width < 0 || height < 0 || !opengl_pixel_bytes(format, type, &pixel)) {
		return false;
	}

	if (unpack) {
		glGetIntegerv(GL_UNPACK_ALIGNMENT, &alignment);
		glGetIntegerv(GL_UNPACK_ROW_LENGTH, &row_length);
		glGetIntegerv(GL_UNPACK_SKIP_ROWS, &skip_rows);
		glGetIntegerv(GL_UNPACK_SKIP_PIXELS, &skip_pixels);
	} else {
		glGetIntegerv(GL_PACK_ALIGNMENT, &alignment);
		glGetIntegerv(GL_PACK_ROW_LENGTH, &row_length);
		glGetIntegerv(GL_PACK_SKIP_ROWS, &skip_rows);
		glGetIntegerv(GL_PACK_SKIP_PIXELS, &skip_pixels);
	}
	if (alignment < 1) {
		alignment = 1;
	}

	columns = (size_t) (row_length > 0 ? row_length : width);
	row = columns * pixel;
	stride = ((row + (size_t) alignment - 1) / (size_t) alignment) * (size_t) alignment;
	if (skip_rows < 0) {
		skip_rows = 0;
	}
	if (skip_pixels < 0) {
		skip_pixels = 0;
	}
	*required = height == 0 || width == 0 ? 0
		: (size_t) skip_rows * stride + (size_t) skip_pixels * pixel + stride * (size_t) (height - 1) + (size_t) width * pixel;

	return true;
}

static bool opengl_upload(zend_string *bytes, zend_long address, bool is_null, bool allow_null, GLenum format, GLenum type, zend_long width, zend_long height, uint32_t arg_num, const void **out)
{
	size_t need = 0;

	if (bytes == NULL && is_null) {
		if (!allow_null) {
			zend_argument_type_error(arg_num, "must be of type string|int, null given");
			return false;
		}
		*out = NULL;
		return true;
	}

	if (bytes != NULL) {
		if (!opengl_image_bytes(format, type, width, height, true, &need)) {
			zend_argument_value_error(arg_num, "cannot size format 0x%x type 0x%x for a string; pass an address", (unsigned) format, (unsigned) type);
			return false;
		}
		if (ZSTR_LEN(bytes) < need) {
			zend_argument_value_error(arg_num, "must hold %zu bytes, %zu given", need, ZSTR_LEN(bytes));
			return false;
		}
		*out = ZSTR_VAL(bytes);
		return true;
	}

	if (address == 0) {
		zend_argument_value_error(arg_num, "must not be a null address");
		return false;
	}

	*out = (const void *) (uintptr_t) address;
	return true;
}

ZEND_FUNCTION(glGenTextures)
{
	zend_long n;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(n)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_names(n, glGenTextures, return_value)) {
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

	if (!opengl_upload(pixels, address, is_null, true, (GLenum) format, (GLenum) type, width, height, 9, &ptr)) {
		RETURN_THROWS();
	}

	glTexImage2D((GLenum) target, (GLint) level, (GLint) internalformat, (GLsizei) width, (GLsizei) height, (GLint) border, (GLenum) format, (GLenum) type, ptr);
}

ZEND_FUNCTION(glTexSubImage2D)
{
	zend_long target, level, xoffset, yoffset, width, height, format, type, address = 0;
	zend_string *pixels = NULL;
	bool is_null = false;
	const void *ptr;

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

	if (!opengl_upload(pixels, address, is_null, false, (GLenum) format, (GLenum) type, width, height, 9, &ptr)) {
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
	HashTable *textures;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(textures)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_forget(textures, glDeleteTextures, 1)) {
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

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(n)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_names(n, glGenFramebuffers, return_value)) {
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
	HashTable *framebuffers;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(framebuffers)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_forget(framebuffers, glDeleteFramebuffers, 1)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glGenRenderbuffers)
{
	zend_long n;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(n)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_names(n, glGenRenderbuffers, return_value)) {
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
	HashTable *renderbuffers;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(renderbuffers)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_forget(renderbuffers, glDeleteRenderbuffers, 1)) {
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
	HashTable *bufs;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(bufs)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_forget(bufs, (void (*)(GLsizei, const GLuint *)) glDrawBuffers, 1)) {
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
	bool is_null = true;
	GLint pack = 0;
	size_t need = 0;
	zend_string *out;

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

	glGetIntegerv(GL_PIXEL_PACK_BUFFER_BINDING, &pack);

	if (is_null) {
		if (pack != 0) {
			zend_argument_value_error(7, "cannot read into a string while a pixel-pack buffer is bound");
			RETURN_THROWS();
		}
		if (!opengl_image_bytes((GLenum) format, (GLenum) type, width, height, false, &need)) {
			zend_argument_value_error(5, "cannot size format 0x%x type 0x%x for a string; pass an address", (unsigned) format, (unsigned) type);
			RETURN_THROWS();
		}
		out = zend_string_alloc(need, 0);
		glReadPixels((GLint) x, (GLint) y, (GLsizei) width, (GLsizei) height, (GLenum) format, (GLenum) type, ZSTR_VAL(out));
		RETURN_STR(out);
	}

	if (address == 0 && pack == 0) {
		zend_argument_value_error(7, "must not be a null address");
		RETURN_THROWS();
	}

	glReadPixels((GLint) x, (GLint) y, (GLsizei) width, (GLsizei) height, (GLenum) format, (GLenum) type, (void *) (uintptr_t) address);
	RETURN_NULL();
}
