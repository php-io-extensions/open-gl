#include "runtime.h"
#include "../stubs/gl_arginfo.h"

static int opengl_integerv_count(GLenum pname)
{
	switch (pname) {
		case GL_VIEWPORT:
		case GL_SCISSOR_BOX:
			return 4;
		case GL_MAX_VIEWPORT_DIMS:
			return 2;
		default:
			return 1;
	}
}

ZEND_FUNCTION(glGetError)
{
	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_NONE();
	RETURN_LONG((zend_long) glGetError());
}

ZEND_FUNCTION(glGetString)
{
	zend_long name;
	const GLubyte *value;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(name)
	ZEND_PARSE_PARAMETERS_END();

	value = glGetString((GLenum) name);
	if (value == NULL) {
		RETURN_NULL();
	}
	RETURN_STRING((const char *) value);
}

ZEND_FUNCTION(glGetIntegerv)
{
	zend_long pname;
	zval *data, values_zv;
	GLint values[4];
	int count, i;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();

	count = opengl_integerv_count((GLenum) pname);
	glGetIntegerv((GLenum) pname, values);

	array_init_size(&values_zv, (uint32_t) count);
	for (i = 0; i < count; i++) {
		add_next_index_long(&values_zv, (zend_long) values[i]);
	}
	ZEND_TRY_ASSIGN_REF_TMP(data, &values_zv);
}

ZEND_FUNCTION(glFlush)
{
	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_NONE();
	glFlush();
}

ZEND_FUNCTION(glFinish)
{
	OPENGL_REQUIRE_CONTEXT();
	ZEND_PARSE_PARAMETERS_NONE();
	glFinish();
}

void opengl_register_gl_state(int module_number)
{
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	register_gl_symbols(module_number);
}
