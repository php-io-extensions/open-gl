/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 05da8854ec6ee94e860cf9390d46c16c66bbe04a */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CGLChoosePixelFormat, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attribs, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(1, pix, CGLPixelFormatObj, 1)
	ZEND_ARG_TYPE_INFO(1, npix, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CGLDestroyPixelFormat, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, pix, CGLPixelFormatObj, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CGLCreateContext, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, pix, CGLPixelFormatObj, 0)
	ZEND_ARG_OBJ_INFO(0, share, CGLContextObj, 1)
	ZEND_ARG_OBJ_INFO(1, ctx, CGLContextObj, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CGLReleaseContext, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, ctx, CGLContextObj, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CGLSetCurrentContext, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, ctx, CGLContextObj, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_CGLGetCurrentContext, 0, 0, CGLContextObj, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CGLErrorString, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, error, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CGLFlushDrawable, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, ctx, CGLContextObj, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_CGLSetParameter, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, ctx, CGLContextObj, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_CGLPixelFormatObj___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_CGLPixelFormatObj_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_CGLPixelFormatObj_fromPointer, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, pointer, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_CGLContextObj___construct arginfo_class_CGLPixelFormatObj___construct

#define arginfo_class_CGLContextObj_pointer arginfo_class_CGLPixelFormatObj_pointer

#define arginfo_class_CGLContextObj_fromPointer arginfo_class_CGLPixelFormatObj_fromPointer

ZEND_FUNCTION(CGLChoosePixelFormat);
ZEND_FUNCTION(CGLDestroyPixelFormat);
ZEND_FUNCTION(CGLCreateContext);
ZEND_FUNCTION(CGLReleaseContext);
ZEND_FUNCTION(CGLSetCurrentContext);
ZEND_FUNCTION(CGLGetCurrentContext);
ZEND_FUNCTION(CGLErrorString);
ZEND_FUNCTION(CGLFlushDrawable);
ZEND_FUNCTION(CGLSetParameter);
ZEND_METHOD(CGLPixelFormatObj, __construct);
ZEND_METHOD(CGLPixelFormatObj, pointer);
ZEND_METHOD(CGLPixelFormatObj, fromPointer);
ZEND_METHOD(CGLContextObj, __construct);
ZEND_METHOD(CGLContextObj, pointer);
ZEND_METHOD(CGLContextObj, fromPointer);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(CGLChoosePixelFormat, arginfo_CGLChoosePixelFormat)
	ZEND_FE(CGLDestroyPixelFormat, arginfo_CGLDestroyPixelFormat)
	ZEND_FE(CGLCreateContext, arginfo_CGLCreateContext)
	ZEND_FE(CGLReleaseContext, arginfo_CGLReleaseContext)
	ZEND_FE(CGLSetCurrentContext, arginfo_CGLSetCurrentContext)
	ZEND_FE(CGLGetCurrentContext, arginfo_CGLGetCurrentContext)
	ZEND_FE(CGLErrorString, arginfo_CGLErrorString)
	ZEND_FE(CGLFlushDrawable, arginfo_CGLFlushDrawable)
	ZEND_FE(CGLSetParameter, arginfo_CGLSetParameter)
	ZEND_FE_END
};

static const zend_function_entry class_CGLPixelFormatObj_methods[] = {
	ZEND_ME(CGLPixelFormatObj, __construct, arginfo_class_CGLPixelFormatObj___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(CGLPixelFormatObj, pointer, arginfo_class_CGLPixelFormatObj_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(CGLPixelFormatObj, fromPointer, arginfo_class_CGLPixelFormatObj_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_CGLContextObj_methods[] = {
	ZEND_ME(CGLContextObj, __construct, arginfo_class_CGLContextObj___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(CGLContextObj, pointer, arginfo_class_CGLContextObj_pointer, ZEND_ACC_PUBLIC)
	ZEND_ME(CGLContextObj, fromPointer, arginfo_class_CGLContextObj_fromPointer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static void register_CGL_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("kCGLPFAOpenGLProfile", kCGLPFAOpenGLProfile, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCGLOGLPVersion_3_2_Core", kCGLOGLPVersion_3_2_Core, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCGLOGLPVersion_GL4_Core", kCGLOGLPVersion_GL4_Core, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCGLPFAColorSize", kCGLPFAColorSize, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCGLPFAAlphaSize", kCGLPFAAlphaSize, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCGLPFADepthSize", kCGLPFADepthSize, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCGLPFAStencilSize", kCGLPFAStencilSize, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCGLPFAAccelerated", kCGLPFAAccelerated, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCGLPFAAllowOfflineRenderers", kCGLPFAAllowOfflineRenderers, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCGLCPSwapInterval", kCGLCPSwapInterval, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("kCGLNoError", kCGLNoError, CONST_PERSISTENT);
}

static zend_class_entry *register_class_CGLPixelFormatObj(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CGLPixelFormatObj", class_CGLPixelFormatObj_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_CGLContextObj(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CGLContextObj", class_CGLContextObj_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
