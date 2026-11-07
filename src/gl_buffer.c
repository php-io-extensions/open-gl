#include "runtime.h"
#include "../stubs/gl_arginfo.h"

zend_class_entry *opengl_ce_GLsync;

OPENGL_POINTER_METHODS(GLsync)

bool opengl_gen_names(zend_long n, zval *dest, void (*generate)(GLsizei, GLuint *))
{
	GLsizei count = (GLsizei) n;
	GLuint *names = ecalloc(count > 0 ? (size_t) count : 1, sizeof(GLuint));
	zval list;
	GLsizei i;

	/* A negative n is GL_INVALID_VALUE: GL writes nothing and the list is empty. */
	generate(count, names);
	array_init_size(&list, count > 0 ? (uint32_t) count : 0);
	for (i = 0; i < count; i++) {
		add_next_index_long(&list, (zend_long) names[i]);
	}
	efree(names);
	ZEND_TRY_ASSIGN_REF_TMP(dest, &list);

	return EG(exception) == NULL;
}

bool opengl_delete_names(zend_long n, HashTable *list, uint32_t list_arg, void (*destroy)(GLsizei, const GLuint *))
{
	int *names;

	if (!opengl_int_list(list, list_arg, &names)) {
		return false;
	}
	if (!opengl_list_count(n, zend_hash_num_elements(list), list_arg - 1, list_arg)) {
		if (names != NULL) {
			efree(names);
		}
		return false;
	}

	destroy((GLsizei) n, (const GLuint *) names);
	if (names != NULL) {
		efree(names);
	}

	return true;
}

bool opengl_source(zend_string *bytes, zend_long address, size_t need, bool null_read, uint32_t arg_num, const void **out)
{
	if (bytes != NULL) {
		if (!OPENGL_PROBE_OFF("opengl-bytes-length") && ZSTR_LEN(bytes) < need) {
			zend_argument_value_error(arg_num, "must hold %zu bytes, %zu given", need, ZSTR_LEN(bytes)); /* binding:opengl-bytes-length */
			return false;
		}
		*out = ZSTR_VAL(bytes);
		return true;
	}

	if (!OPENGL_PROBE_OFF("opengl-null-address") && address == 0 && null_read) {
		zend_argument_value_error(arg_num, "must not be address 0, which GL reads"); /* binding:opengl-null-address */
		return false;
	}

	*out = (const void *) (uintptr_t) address;
	return true;
}

ZEND_FUNCTION(glGenVertexArrays)
{
	zend_long n;
	zval *arrays;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ZVAL(arrays)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_gen_names(n, arrays, glGenVertexArrays)) {
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
	zend_long n;
	HashTable *arrays;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ARRAY_HT(arrays)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_delete_names(n, arrays, 2, glDeleteVertexArrays)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glGenBuffers)
{
	zend_long n;
	zval *buffers;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ZVAL(buffers)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_gen_names(n, buffers, glGenBuffers)) {
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

	/* NULL (null or 0) allocates the store without data. */
	if (!opengl_source(data, address, size > 0 ? (size_t) size : 0, false, 3, &ptr)) {
		RETURN_THROWS();
	}

	glBufferData((GLenum) target, (GLsizeiptr) size, ptr, (GLenum) usage);
}

ZEND_FUNCTION(glBufferSubData)
{
	zend_long target, offset, size, address = 0;
	zend_string *data = NULL;
	const void *ptr;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(size)
		Z_PARAM_STR_OR_LONG(data, address)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_source(data, address, size > 0 ? (size_t) size : 0, size > 0, 4, &ptr)) {
		RETURN_THROWS();
	}

	glBufferSubData((GLenum) target, (GLintptr) offset, (GLsizeiptr) size, ptr);
}

ZEND_FUNCTION(glDeleteBuffers)
{
	zend_long n;
	HashTable *buffers;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(n)
		Z_PARAM_ARRAY_HT(buffers)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_delete_names(n, buffers, 2, glDeleteBuffers)) {
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

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(offset)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(access)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) (uintptr_t) glMapBufferRange((GLenum) target, (GLintptr) offset, (GLsizeiptr) length, (GLbitfield) access));
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

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(condition)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	opengl_box(return_value, glFenceSync((GLenum) condition, (GLbitfield) flags), opengl_ce_GLsync);
}

ZEND_FUNCTION(glClientWaitSync)
{
	zend_object *sync;
	zend_long flags, timeout;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(sync, opengl_ce_GLsync)
		Z_PARAM_LONG(flags)
		Z_PARAM_LONG(timeout)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) glClientWaitSync(opengl_ptr(sync), (GLbitfield) flags, (GLuint64) timeout));
}

ZEND_FUNCTION(glDeleteSync)
{
	zend_object *sync;

	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(sync, opengl_ce_GLsync)
	ZEND_PARSE_PARAMETERS_END();

	glDeleteSync(opengl_ptr(sync));
	opengl_release(sync);
}

void opengl_register_gl_buffer(int module_number)
{
	(void) module_number;
	(void) ext_functions;
	(void) register_gl_symbols;
	opengl_ce_GLsync = register_class_GLsync();
	opengl_handle_setup(opengl_ce_GLsync);
}
