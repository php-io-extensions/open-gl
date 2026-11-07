#include "runtime.h"
#include "../stubs/gl_arginfo.h"

/* How many ints glGetIntegerv writes for pname: the GL 4.1 and ES 3.0 state tables. A list pname
 * writes as many as its GL_NUM_* query answers. */
static GLint opengl_integerv_count(GLenum pname)
{
	GLint n = 0;

	switch (pname) {
		case GL_VIEWPORT:
		case GL_SCISSOR_BOX:
		case GL_COLOR_WRITEMASK:
		case GL_COLOR_CLEAR_VALUE:
		case GL_BLEND_COLOR:
			return 4;
		case GL_MAX_VIEWPORT_DIMS:
		case GL_DEPTH_RANGE:
		case GL_ALIASED_LINE_WIDTH_RANGE:
#ifdef GL_ALIASED_POINT_SIZE_RANGE
		case GL_ALIASED_POINT_SIZE_RANGE:
#endif
#ifdef GL_POINT_SIZE_RANGE
		case GL_POINT_SIZE_RANGE:
#endif
#ifdef GL_LINE_WIDTH_RANGE
		case GL_LINE_WIDTH_RANGE:
#endif
#ifdef GL_VIEWPORT_BOUNDS_RANGE
		case GL_VIEWPORT_BOUNDS_RANGE:
#endif
			return 2;
		case GL_COMPRESSED_TEXTURE_FORMATS:
			glGetIntegerv(GL_NUM_COMPRESSED_TEXTURE_FORMATS, &n);
			return n;
		case GL_PROGRAM_BINARY_FORMATS:
			glGetIntegerv(GL_NUM_PROGRAM_BINARY_FORMATS, &n);
			return n;
		case GL_SHADER_BINARY_FORMATS:
			glGetIntegerv(GL_NUM_SHADER_BINARY_FORMATS, &n);
			return n;
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
	GLint *values, count, i;

	OPENGL_REQUIRE_CONTEXT();

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();

	/* At least 16 ints, so a multi-value pname outside the table cannot write past the array. */
	count = opengl_integerv_count((GLenum) pname);
	values = ecalloc(count > 16 ? (size_t) count : 16, sizeof(GLint));
	glGetIntegerv((GLenum) pname, values);

	array_init_size(&values_zv, count > 0 ? (uint32_t) count : 0);
	for (i = 0; i < count; i++) {
		add_next_index_long(&values_zv, (zend_long) values[i]);
	}
	efree(values);
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
