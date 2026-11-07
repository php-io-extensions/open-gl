#include "runtime.h"
#include "../stubs/CGL_arginfo.h"

zend_class_entry *opengl_ce_CGLPixelFormatObj;
zend_class_entry *opengl_ce_CGLContextObj;

OPENGL_POINTER_METHODS(CGLPixelFormatObj)
OPENGL_POINTER_METHODS(CGLContextObj)

/* CGL reads attributes up to the 0 that ends the list: without it, it reads past the array. */
static bool cgl_attribs(HashTable *list, uint32_t arg_num, int **out)
{
	uint32_t n = zend_hash_num_elements(list);

	if (!opengl_int_list(list, arg_num, out)) {
		return false;
	}
	if (!OPENGL_PROBE_OFF("opengl-attrib-terminator") && (n == 0 || (*out)[n - 1] != 0)) {
		if (*out != NULL) {
			efree(*out);
			*out = NULL;
		}
		zend_argument_value_error(arg_num, "must end with 0"); /* binding:opengl-attrib-terminator */
		return false;
	}

	return true;
}

ZEND_FUNCTION(CGLChoosePixelFormat)
{
	HashTable *attribs;
	zval *pix, *npix;
	int *list;
	CGLPixelFormatObj format = NULL;
	GLint count = 0;
	CGLError err;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY_HT(attribs)
		Z_PARAM_ZVAL(pix)
		Z_PARAM_ZVAL(npix)
	ZEND_PARSE_PARAMETERS_END();

	if (!cgl_attribs(attribs, 1, &list)) {
		RETURN_THROWS();
	}

	err = CGLChoosePixelFormat((const CGLPixelFormatAttribute *) list, &format, &count);
	if (list != NULL) {
		efree(list);
	}

	if (!opengl_assign_handle(pix, format, opengl_ce_CGLPixelFormatObj)) {
		RETURN_THROWS();
	}
	ZEND_TRY_ASSIGN_REF_LONG(npix, (zend_long) count);
	if (EG(exception)) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) err);
}

ZEND_FUNCTION(CGLDestroyPixelFormat)
{
	zend_object *pix;
	CGLError err;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(pix, opengl_ce_CGLPixelFormatObj)
	ZEND_PARSE_PARAMETERS_END();

	err = CGLDestroyPixelFormat(opengl_ptr(pix));
	opengl_release(pix);
	RETURN_LONG((zend_long) err);
}

ZEND_FUNCTION(CGLCreateContext)
{
	zend_object *pix, *share = NULL;
	zval *ctx;
	CGLContextObj created = NULL;
	CGLError err;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(pix, opengl_ce_CGLPixelFormatObj)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(share, opengl_ce_CGLContextObj)
		Z_PARAM_ZVAL(ctx)
	ZEND_PARSE_PARAMETERS_END();

	err = CGLCreateContext(opengl_ptr(pix), opengl_ptr(share), &created);
	if (!opengl_assign_handle(ctx, created, opengl_ce_CGLContextObj)) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) err);
}

ZEND_FUNCTION(CGLReleaseContext)
{
	zend_object *ctx;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(ctx, opengl_ce_CGLContextObj)
	ZEND_PARSE_PARAMETERS_END();

	CGLReleaseContext(opengl_ptr(ctx));
	opengl_release(ctx);
}

ZEND_FUNCTION(CGLSetCurrentContext)
{
	zend_object *ctx = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(ctx, opengl_ce_CGLContextObj)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) CGLSetCurrentContext(opengl_ptr(ctx)));
}

ZEND_FUNCTION(CGLGetCurrentContext)
{
	ZEND_PARSE_PARAMETERS_NONE();
	opengl_box(return_value, CGLGetCurrentContext(), opengl_ce_CGLContextObj);
}

ZEND_FUNCTION(CGLErrorString)
{
	zend_long error;
	const char *text;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(error)
	ZEND_PARSE_PARAMETERS_END();

	text = CGLErrorString((CGLError) error);
	if (text == NULL) {
		RETURN_NULL();
	}
	RETURN_STRING(text);
}

ZEND_FUNCTION(CGLFlushDrawable)
{
	zend_object *ctx;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(ctx, opengl_ce_CGLContextObj)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) CGLFlushDrawable(opengl_ptr(ctx)));
}

ZEND_FUNCTION(CGLSetParameter)
{
	zend_object *ctx;
	zend_long pname;
	HashTable *params;
	int *values;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(ctx, opengl_ce_CGLContextObj)
		Z_PARAM_LONG(pname)
		Z_PARAM_ARRAY_HT(params)
	ZEND_PARSE_PARAMETERS_END();

	if (!opengl_int_list(params, 3, &values)) {
		RETURN_THROWS();
	}

	RETVAL_LONG((zend_long) CGLSetParameter(opengl_ptr(ctx), (CGLContextParameter) pname, (const GLint *) values));
	if (values != NULL) {
		efree(values);
	}
}

void opengl_register_cgl(int module_number)
{
	zend_register_functions(NULL, ext_functions, NULL, MODULE_PERSISTENT);
	register_CGL_symbols(module_number);

	opengl_ce_CGLPixelFormatObj = register_class_CGLPixelFormatObj();
	opengl_handle_setup(opengl_ce_CGLPixelFormatObj);
	opengl_ce_CGLContextObj = register_class_CGLContextObj();
	opengl_handle_setup(opengl_ce_CGLContextObj);
}
