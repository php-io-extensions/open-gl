#include "runtime.h"

static zend_string *opengl_info_log(GLuint object, bool shader)
{
	GLint length = 0;
	GLsizei written = 0;
	char *buf;
	zend_string *text;

	if (shader) {
		glGetShaderiv(object, GL_INFO_LOG_LENGTH, &length);
	} else {
		glGetProgramiv(object, GL_INFO_LOG_LENGTH, &length);
	}
	if (length <= 1) {
		return zend_string_init("", 0, 0);
	}

	buf = emalloc((size_t) length);
	if (shader) {
		glGetShaderInfoLog(object, length, &written, buf);
	} else {
		glGetProgramInfoLog(object, length, &written, buf);
	}
	text = zend_string_init(buf, written > 0 ? (size_t) written : 0, 0);
	efree(buf);

	return text;
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
	zend_long shader;
	HashTable *strings;
	uint32_t n, i = 0;
	zval *zv;
	const GLchar **ptrs = NULL;
	GLint *lengths = NULL;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(shader)
		Z_PARAM_ARRAY_HT(strings)
	ZEND_PARSE_PARAMETERS_END();

	n = zend_hash_num_elements(strings);
	if (n > 0) {
		ptrs = emalloc(sizeof(GLchar *) * n);
		lengths = emalloc(sizeof(GLint) * n);
		ZEND_HASH_FOREACH_VAL(strings, zv) {
			if (Z_TYPE_P(zv) != IS_STRING) {
				efree(ptrs);
				efree(lengths);
				zend_argument_type_error(2, "must be a list of strings");
				RETURN_THROWS();
			}
			if (ZSTR_LEN(Z_STR_P(zv)) > (size_t) INT_MAX) {
				efree(ptrs);
				efree(lengths);
				zend_argument_value_error(2, "must hold at most %d bytes a string", INT_MAX);
				RETURN_THROWS();
			}
			ptrs[i] = ZSTR_VAL(Z_STR_P(zv));
			lengths[i] = (GLint) ZSTR_LEN(Z_STR_P(zv));
			i++;
		} ZEND_HASH_FOREACH_END();
	}

	glShaderSource((GLuint) shader, (GLsizei) n, ptrs, lengths);
	if (ptrs != NULL) {
		efree(ptrs);
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
	zend_long shader;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(shader)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_STR(opengl_info_log((GLuint) shader, true));
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
	zend_long program;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(program)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_STR(opengl_info_log((GLuint) program, false));
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
	zend_long location;
	bool transpose;
	HashTable *value;
	uint32_t n, i = 0;
	zval *zv;
	GLfloat *matrix = NULL;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(location)
		Z_PARAM_BOOL(transpose)
		Z_PARAM_ARRAY_HT(value)
	ZEND_PARSE_PARAMETERS_END();

	n = zend_hash_num_elements(value);
	if ((n % 16) != 0) {
		zend_argument_value_error(3, "must be a multiple of 16");
		RETURN_THROWS();
	}

	if (n > 0) {
		matrix = emalloc(sizeof(GLfloat) * n);
		ZEND_HASH_FOREACH_VAL(value, zv) {
			if (Z_TYPE_P(zv) == IS_DOUBLE) {
				matrix[i++] = (GLfloat) Z_DVAL_P(zv);
			} else if (Z_TYPE_P(zv) == IS_LONG) {
				matrix[i++] = (GLfloat) Z_LVAL_P(zv);
			} else {
				efree(matrix);
				zend_argument_type_error(3, "must be a list of floats");
				RETURN_THROWS();
			}
		} ZEND_HASH_FOREACH_END();
	}

	glUniformMatrix4fv((GLint) location, (GLsizei) (n / 16), transpose ? GL_TRUE : GL_FALSE, matrix);
	if (matrix != NULL) {
		efree(matrix);
	}
}
