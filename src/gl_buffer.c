#include "runtime.h"
#include "../stubs/gl_arginfo.h"

zend_class_entry *opengl_ce_GLsync;

OPENGL_POINTER_METHODS(GLsync)

static bool opengl_gluint_list(HashTable *list, GLuint **out, uint32_t *count, uint32_t arg_num)
{
	uint32_t n = zend_hash_num_elements(list);
	uint32_t i = 0;
	zval *zv;

	*count = n;
	if (n == 0) {
		*out = NULL;
		return true;
	}

	*out = emalloc(sizeof(GLuint) * n);
	ZEND_HASH_FOREACH_VAL(list, zv) {
		if (Z_TYPE_P(zv) != IS_LONG || Z_LVAL_P(zv) < 0 || Z_LVAL_P(zv) > (zend_long) UINT32_MAX) {
			efree(*out);
			*out = NULL;
			if (Z_TYPE_P(zv) != IS_LONG) {
				zend_argument_type_error(arg_num, "must be a list of ints");
			} else {
				zend_argument_value_error(arg_num, "must be greater than or equal to 0");
			}
			return false;
		}
		(*out)[i++] = (GLuint) Z_LVAL_P(zv);
	} ZEND_HASH_FOREACH_END();

	return true;
}

static bool opengl_generate(zend_long n, void (*generate)(GLsizei, GLuint *), zval *return_value)
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

static bool opengl_destroy_names(HashTable *list, void (*destroy)(GLsizei, const GLuint *), uint32_t arg_num)
{
	GLuint *names = NULL;
	uint32_t count = 0;

	if (!opengl_gluint_list(list, &names, &count, arg_num)) {
		return false;
	}

	destroy((GLsizei) count, names);
	if (names != NULL) {
		efree(names);
	}

	return true;
}

static bool opengl_buffer_pointer(zend_string *bytes, zend_long address, bool is_null, bool allow_null, zend_long size, uint32_t size_arg, uint32_t data_arg, const void **out)
{
	if (size < 0) {
		zend_argument_value_error(size_arg, "must be greater than or equal to 0");
		return false;
	}

	if (bytes != NULL) {
		if (ZSTR_LEN(bytes) < (size_t) size) {
			zend_argument_value_error(data_arg, "must hold " ZEND_LONG_FMT " bytes, %zu given", size, ZSTR_LEN(bytes));
			return false;
		}
		*out = ZSTR_VAL(bytes);
		return true;
	}

	if (is_null) {
		if (!allow_null) {
			zend_argument_type_error(data_arg, "must be of type string|int, null given");
			return false;
		}
		*out = NULL;
		return true;
	}

	if (address == 0) {
		zend_argument_value_error(data_arg, "must not be a null address");
		return false;
	}

	*out = (const void *) (uintptr_t) address;
	return true;
}

ZEND_FUNCTION(glGenVertexArrays)
{
	zend_long n;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(n)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_generate(n, glGenVertexArrays, return_value)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glBindVertexArray)
{
	zend_long array;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(array)
	ZEND_PARSE_PARAMETERS_END();

	glBindVertexArray((GLuint) array);
}

ZEND_FUNCTION(glDeleteVertexArrays)
{
	HashTable *arrays;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(arrays)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_destroy_names(arrays, glDeleteVertexArrays, 1)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glGenBuffers)
{
	zend_long n;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(n)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_generate(n, glGenBuffers, return_value)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glBindBuffer)
{
	zend_long target, buffer;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();

	glBindBuffer((GLenum) target, (GLuint) buffer);
}

ZEND_FUNCTION(glBufferData)
{
	zend_long target, size, address = 0, usage;
	zend_string *data = NULL;
	bool is_null = false;
	const void *ptr;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(size)
		Z_PARAM_STR_OR_LONG_OR_NULL(data, address, is_null)
		Z_PARAM_LONG(usage)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_buffer_pointer(data, address, is_null, true, size, 2, 3, &ptr)) {
		RETURN_THROWS();
	}

	glBufferData((GLenum) target, (GLsizeiptr) size, ptr, (GLenum) usage);
}

ZEND_FUNCTION(glBufferSubData)
{
	zend_long target, offset, size, address = 0;
	zend_string *data = NULL;
	bool is_null = false;
	const void *ptr;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(size)
		Z_PARAM_STR_OR_LONG(data, address)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_buffer_pointer(data, address, is_null, false, size, 3, 4, &ptr)) {
		RETURN_THROWS();
	}

	glBufferSubData((GLenum) target, (GLintptr) offset, (GLsizeiptr) size, ptr);
}

ZEND_FUNCTION(glDeleteBuffers)
{
	HashTable *buffers;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(buffers)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_destroy_names(buffers, glDeleteBuffers, 1)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glEnableVertexAttribArray)
{
	zend_long index;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();

	glEnableVertexAttribArray((GLuint) index);
}

ZEND_FUNCTION(glDisableVertexAttribArray)
{
	zend_long index;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();

	glDisableVertexAttribArray((GLuint) index);
}

ZEND_FUNCTION(glVertexAttribPointer)
{
	zend_long index, size, type, stride, pointer;
	bool normalized;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(index)
		Z_PARAM_LONG(size)
		Z_PARAM_LONG(type)
		Z_PARAM_BOOL(normalized)
		Z_PARAM_LONG(stride)
		Z_PARAM_LONG(pointer)
	ZEND_PARSE_PARAMETERS_END();

	glVertexAttribPointer((GLuint) index, (GLint) size, (GLenum) type, normalized ? GL_TRUE : GL_FALSE, (GLsizei) stride, (const void *) (uintptr_t) pointer);
}

ZEND_FUNCTION(glMapBufferRange)
{
	zend_long target, offset, length, access;
	void *mapped;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(access)
	ZEND_PARSE_PARAMETERS_END();

	mapped = glMapBufferRange((GLenum) target, (GLintptr) offset, (GLsizeiptr) length, (GLbitfield) access);
	RETURN_LONG(mapped == NULL ? 0 : (zend_long) (uintptr_t) mapped);
}

ZEND_FUNCTION(glUnmapBuffer)
{
	zend_long target;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(target)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(glUnmapBuffer((GLenum) target) == GL_TRUE);
}

ZEND_FUNCTION(glFenceSync)
{
	zend_long condition, flags;
	GLsync sync;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(condition)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	sync = glFenceSync((GLenum) condition, (GLbitfield) flags);
	opengl_box(return_value, sync, opengl_ce_GLsync);
}

ZEND_FUNCTION(glClientWaitSync)
{
	zval *sync_zv;
	zend_long flags, timeout;
	GLsync sync;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(sync_zv, opengl_ce_GLsync)
		Z_PARAM_LONG(flags)
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();

	sync = opengl_handle_ptr(sync_zv, opengl_ce_GLsync, 1);
	if (sync == NULL) {
		RETURN_THROWS();
	}
	if (timeout < 0) {
		zend_argument_value_error(3, "must be greater than or equal to 0");
		RETURN_THROWS();
	}

	RETURN_LONG((zend_long) glClientWaitSync(sync, (GLbitfield) flags, (GLuint64) timeout));
}

ZEND_FUNCTION(glDeleteSync)
{
	zval *sync_zv;
	GLsync sync;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(sync_zv, opengl_ce_GLsync)
	ZEND_PARSE_PARAMETERS_END();

	sync = opengl_handle_ptr(sync_zv, opengl_ce_GLsync, 1);
	if (sync == NULL) {
		RETURN_THROWS();
	}

	glDeleteSync(sync);
	opengl_release(Z_OBJ_P(sync_zv));
}

void opengl_register_gl_buffer(int module_number)
{
	(void) module_number;
	(void) ext_functions;
	(void) register_gl_symbols;
	opengl_ce_GLsync = register_class_GLsync();
	opengl_handle_setup(opengl_ce_GLsync);
}
