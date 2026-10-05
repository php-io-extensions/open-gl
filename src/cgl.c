#include "runtime.h"
#include "../stubs/CGL_arginfo.h"

zend_class_entry *opengl_ce_CGLPixelFormatObj;
zend_class_entry *opengl_ce_CGLContextObj;

OPENGL_POINTER_METHODS(CGLPixelFormatObj)
OPENGL_POINTER_METHODS(CGLContextObj)

static void *cgl_required(zval *zv, zend_class_entry *ce, uint32_t arg_num)
{
	void *ptr = opengl_handle_ptr(zv, ce, arg_num);

	if (ptr == NULL) {
		return NULL;
	}

	return ptr;
}

static void *cgl_optional(zend_object *obj, zend_class_entry *ce, uint32_t arg_num)
{
	zval tmp;

	if (obj == NULL) {
		return NULL;
	}

	ZVAL_OBJ(&tmp, obj);
	return opengl_handle_ptr(&tmp, ce, arg_num);
}

static bool cgl_gint_list(HashTable *list, GLint **out, uint32_t arg_num)
{
	uint32_t n = zend_hash_num_elements(list);
	uint32_t i = 0;
	zval *zv;

	if (n == 0) {
		zend_argument_value_error(arg_num, "must contain at least one int");
		return false;
	}

	*out = emalloc(sizeof(GLint) * n);
	ZEND_HASH_FOREACH_VAL(list, zv) {
		if (Z_TYPE_P(zv) != IS_LONG || Z_LVAL_P(zv) > INT_MAX || Z_LVAL_P(zv) < INT_MIN) {
			efree(*out);
			*out = NULL;
			if (Z_TYPE_P(zv) != IS_LONG) {
				zend_argument_type_error(arg_num, "must be a list of ints");
			} else {
				zend_argument_value_error(arg_num, "must fit in a 32-bit int");
			}
			return false;
		}
		(*out)[i++] = (GLint) Z_LVAL_P(zv);
	} ZEND_HASH_FOREACH_END();

	return true;
}

ZEND_FUNCTION(CGLChoosePixelFormat)
{
	HashTable *attribs;
	zval *pix, *npix;
	int *list;
	bool failed = false;
	CGLPixelFormatObj format = NULL;
	GLint count = 0;
	CGLError err;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ARRAY_HT(attribs)
		Z_PARAM_ZVAL(pix)
		Z_PARAM_ZVAL(npix)
	ZEND_PARSE_PARAMETERS_END();

	list = opengl_attrib_list(attribs, 0, 1, &failed);
	if (failed) {
		RETURN_THROWS();
	}

	err = CGLChoosePixelFormat((const CGLPixelFormatAttribute *) list, &format, &count);
	efree(list);

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
	zval *pix_zv;
	CGLPixelFormatObj pix;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(pix_zv, opengl_ce_CGLPixelFormatObj)
	ZEND_PARSE_PARAMETERS_END();

	pix = cgl_required(pix_zv, opengl_ce_CGLPixelFormatObj, 1);
	if (pix == NULL) {
		RETURN_THROWS();
	}

	CGLDestroyPixelFormat(pix);
	opengl_release(Z_OBJ_P(pix_zv));
}

ZEND_FUNCTION(CGLCreateContext)
{
	zval *pix_zv, *ctx;
	zend_object *share = NULL;
	CGLPixelFormatObj pix;
	CGLContextObj share_ctx = NULL, created = NULL;
	CGLError err;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(pix_zv, opengl_ce_CGLPixelFormatObj)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(share, opengl_ce_CGLContextObj)
		Z_PARAM_ZVAL(ctx)
	ZEND_PARSE_PARAMETERS_END();

	pix = cgl_required(pix_zv, opengl_ce_CGLPixelFormatObj, 1);
	if (pix == NULL) {
		RETURN_THROWS();
	}
	if (share != NULL) {
		share_ctx = cgl_optional(share, opengl_ce_CGLContextObj, 2);
		if (share_ctx == NULL) {
			RETURN_THROWS();
		}
	}

	err = CGLCreateContext(pix, share_ctx, &created);
	if (!opengl_assign_handle(ctx, created, opengl_ce_CGLContextObj)) {
		RETURN_THROWS();
	}
	RETURN_LONG((zend_long) err);
}

ZEND_FUNCTION(CGLReleaseContext)
{
	zval *ctx_zv;
	CGLContextObj ctx;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(ctx_zv, opengl_ce_CGLContextObj)
	ZEND_PARSE_PARAMETERS_END();

	ctx = cgl_required(ctx_zv, opengl_ce_CGLContextObj, 1);
	if (ctx == NULL) {
		RETURN_THROWS();
	}

	if (CGLGetCurrentContext() == ctx) {
		CGLSetCurrentContext(NULL);
	}
	CGLReleaseContext(ctx);
	opengl_release(Z_OBJ_P(ctx_zv));
}

ZEND_FUNCTION(CGLSetCurrentContext)
{
	zend_object *ctx = NULL;
	CGLContextObj native = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(ctx, opengl_ce_CGLContextObj)
	ZEND_PARSE_PARAMETERS_END();

	if (ctx != NULL) {
		native = cgl_optional(ctx, opengl_ce_CGLContextObj, 1);
		if (native == NULL) {
			RETURN_THROWS();
		}
	}

	RETURN_LONG((zend_long) CGLSetCurrentContext(native));
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
	RETURN_STRING(text != NULL ? text : "");
}

ZEND_FUNCTION(CGLFlushDrawable)
{
	zval *ctx_zv;
	CGLContextObj ctx;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(ctx_zv, opengl_ce_CGLContextObj)
	ZEND_PARSE_PARAMETERS_END();

	ctx = cgl_required(ctx_zv, opengl_ce_CGLContextObj, 1);
	if (ctx == NULL) {
		RETURN_THROWS();
	}

	RETURN_LONG((zend_long) CGLFlushDrawable(ctx));
}

ZEND_FUNCTION(CGLSetParameter)
{
	zval *ctx_zv;
	zend_long pname;
	HashTable *params;
	CGLContextObj ctx;
	GLint *values = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(ctx_zv, opengl_ce_CGLContextObj)
		Z_PARAM_LONG(pname)
		Z_PARAM_ARRAY_HT(params)
	ZEND_PARSE_PARAMETERS_END();

	ctx = cgl_required(ctx_zv, opengl_ce_CGLContextObj, 1);
	if (ctx == NULL) {
		RETURN_THROWS();
	}
	if (!cgl_gint_list(params, &values, 3)) {
		RETURN_THROWS();
	}

	RETVAL_LONG((zend_long) CGLSetParameter(ctx, (CGLContextParameter) pname, values));
	efree(values);
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
