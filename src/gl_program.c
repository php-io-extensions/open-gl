#include "runtime.h"

/* glGetShaderInfoLog / glGetProgramInfoLog: GL writes at most bufSize bytes, NUL included, into a
 * buffer of that size; length is what it wrote without the NUL, infoLog those bytes. */
static void opengl_info_log(INTERNAL_FUNCTION_PARAMETERS, void (*get)(GLuint, GLsizei, GLsizei *, GLchar *))
{
	zend_long object, buf_size;
	zval *length_zv, *log_zv;
	GLsizei written = 0;
	char *buf;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(object)
		Z_PARAM_LONG(buf_size)
		Z_PARAM_ZVAL(length_zv)
		Z_PARAM_ZVAL(log_zv)
	ZEND_PARSE_PARAMETERS_END();

	buf = emalloc((GLsizei) buf_size > 0 ? (size_t) (GLsizei) buf_size : 1);
	get((GLuint) object, (GLsizei) buf_size, &written, buf);
	ZEND_TRY_ASSIGN_REF_LONG(length_zv, (zend_long) written);
	if (!EG(exception)) {
		ZEND_TRY_ASSIGN_REF_STRINGL(log_zv, buf, written > 0 ? (size_t) written : 0);
	}
	efree(buf);
}

static bool opengl_assign_int(zval *dest, GLint value)
{
	ZEND_TRY_ASSIGN_REF_LONG(dest, (zend_long) value);
	return EG(exception) == NULL;
}

ZEND_FUNCTION(glCreateShader)
{
	zend_long type;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) glCreateShader((GLenum) type));
}

ZEND_FUNCTION(glShaderSource)
{
	zend_long shader, count;
	HashTable *strings, *length = NULL;
	uint32_t n, i = 0, held;
	zval *zv;
	zend_string **held_strings = NULL;
	const GLchar **ptrs = NULL;
	int *lengths = NULL;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(shader)
		Z_PARAM_LONG(count)
		Z_PARAM_ARRAY_HT(strings)
		Z_PARAM_ARRAY_HT_OR_NULL(length)
	ZEND_PARSE_PARAMETERS_END();

	n = zend_hash_num_elements(strings);
	if (!opengl_list_count(count, n, 2, 3)
		|| (length != NULL && !opengl_list_count(count, zend_hash_num_elements(length), 2, 4))) {
		RETURN_THROWS();
	}
	if (!opengl_int_list(length, 4, &lengths)) {
		RETURN_THROWS();
	}

	/* Each element as PHP converts it to a string; PHP raises its own error for one that does not convert. */
	if (n > 0) {
		ptrs = safe_emalloc(n, sizeof(GLchar *), 0);
		held_strings = safe_emalloc(n, sizeof(zend_string *), 0);
		ZEND_HASH_FOREACH_VAL(strings, zv) {
			held_strings[i] = zval_try_get_string(zv);
			if (held_strings[i] == NULL) {
				break;
			}
			ptrs[i] = ZSTR_VAL(held_strings[i]);
			i++;
		} ZEND_HASH_FOREACH_END();
	}
	held = i;

	/* A null $length: GL reads each string to its NUL, which every PHP string ends with. */
	if (!EG(exception)) {
		glShaderSource((GLuint) shader, (GLsizei) count, ptrs, (const GLint *) lengths);
	}
	for (i = 0; i < held; i++) {
		zend_string_release(held_strings[i]);
	}
	if (ptrs != NULL) {
		efree(ptrs);
		efree(held_strings);
	}
	if (lengths != NULL) {
		efree(lengths);
	}
}

ZEND_FUNCTION(glCompileShader)
{
	zend_long shader;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(shader)
	ZEND_PARSE_PARAMETERS_END();

	glCompileShader((GLuint) shader);
}

ZEND_FUNCTION(glGetShaderiv)
{
	zend_long shader, pname;
	zval *params;
	GLint value = 0;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(shader)
		Z_PARAM_LONG(pname)
		Z_PARAM_ZVAL(params)
	ZEND_PARSE_PARAMETERS_END();

	glGetShaderiv((GLuint) shader, (GLenum) pname, &value);
	if (!opengl_assign_int(params, value)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glGetShaderInfoLog)
{
	OPENGL_REQUIRE_CONTEXT();
	opengl_info_log(INTERNAL_FUNCTION_PARAM_PASSTHRU, glGetShaderInfoLog);
}

ZEND_FUNCTION(glDeleteShader)
{
	zend_long shader;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(shader)
	ZEND_PARSE_PARAMETERS_END();

	glDeleteShader((GLuint) shader);
}

ZEND_FUNCTION(glCreateProgram)
{
	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG((zend_long) glCreateProgram());
}

ZEND_FUNCTION(glAttachShader)
{
	zend_long program, shader;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(shader)
	ZEND_PARSE_PARAMETERS_END();

	glAttachShader((GLuint) program, (GLuint) shader);
}

ZEND_FUNCTION(glBindAttribLocation)
{
	zend_long program, index;
	zend_string *name;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(index)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	glBindAttribLocation((GLuint) program, (GLuint) index, ZSTR_VAL(name));
}

ZEND_FUNCTION(glLinkProgram)
{
	zend_long program;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();

	glLinkProgram((GLuint) program);
}

ZEND_FUNCTION(glGetProgramiv)
{
	zend_long program, pname;
	zval *params;
	GLint value = 0;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(program)
		Z_PARAM_LONG(pname)
		Z_PARAM_ZVAL(params)
	ZEND_PARSE_PARAMETERS_END();

	glGetProgramiv((GLuint) program, (GLenum) pname, &value);
	if (!opengl_assign_int(params, value)) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(glGetProgramInfoLog)
{
	OPENGL_REQUIRE_CONTEXT();
	opengl_info_log(INTERNAL_FUNCTION_PARAM_PASSTHRU, glGetProgramInfoLog);
}

ZEND_FUNCTION(glUseProgram)
{
	zend_long program;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();

	glUseProgram((GLuint) program);
}

ZEND_FUNCTION(glDeleteProgram)
{
	zend_long program;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();

	glDeleteProgram((GLuint) program);
}

ZEND_FUNCTION(glGetUniformLocation)
{
	zend_long program;
	zend_string *name;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(program)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) glGetUniformLocation((GLuint) program, ZSTR_VAL(name)));
}

ZEND_FUNCTION(glGetAttribLocation)
{
	zend_long program;
	zend_string *name;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(program)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) glGetAttribLocation((GLuint) program, ZSTR_VAL(name)));
}

ZEND_FUNCTION(glUniform1i)
{
	zend_long location, v0;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(v0)
	ZEND_PARSE_PARAMETERS_END();

	glUniform1i((GLint) location, (GLint) v0);
}

ZEND_FUNCTION(glUniform1f)
{
	zend_long location;
	double v0;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(location)
		Z_PARAM_DOUBLE(v0)
	ZEND_PARSE_PARAMETERS_END();

	glUniform1f((GLint) location, (GLfloat) v0);
}

ZEND_FUNCTION(glUniform2f)
{
	zend_long location;
	double v0, v1;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(location)
		Z_PARAM_DOUBLE(v0)
		Z_PARAM_DOUBLE(v1)
	ZEND_PARSE_PARAMETERS_END();

	glUniform2f((GLint) location, (GLfloat) v0, (GLfloat) v1);
}

ZEND_FUNCTION(glUniform4f)
{
	zend_long location;
	double v0, v1, v2, v3;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(location)
		Z_PARAM_DOUBLE(v0)
		Z_PARAM_DOUBLE(v1)
		Z_PARAM_DOUBLE(v2)
		Z_PARAM_DOUBLE(v3)
	ZEND_PARSE_PARAMETERS_END();

	glUniform4f((GLint) location, (GLfloat) v0, (GLfloat) v1, (GLfloat) v2, (GLfloat) v3);
}

ZEND_FUNCTION(glUniformMatrix4fv)
{
	zend_long location, count;
	bool transpose;
	HashTable *value;
	uint32_t n, i = 0;
	zval *zv;
	GLfloat *matrix = NULL;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(location)
		Z_PARAM_LONG(count)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_ARRAY_HT(value)
	ZEND_PARSE_PARAMETERS_END();

	/* GL reads 16 floats a matrix. */
	n = zend_hash_num_elements(value);
	if (!opengl_list_count(count, n / 16, 2, 4)) {
		RETURN_THROWS();
	}

	/* Each element as PHP's (float) converts it. */
	if (n > 0) {
		matrix = safe_emalloc(n, sizeof(GLfloat), 0);
		ZEND_HASH_FOREACH_VAL(value, zv) {
			matrix[i++] = (GLfloat) zval_get_double(zv);
		} ZEND_HASH_FOREACH_END();
	}

	glUniformMatrix4fv((GLint) location, (GLsizei) count, transpose ? GL_TRUE : GL_FALSE, matrix);
	if (matrix != NULL) {
		efree(matrix);
	}
}
