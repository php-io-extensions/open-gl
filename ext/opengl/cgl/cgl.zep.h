
extern zend_class_entry *opengl_cgl_cgl_ce;

ZEPHIR_INIT_CLASS(OpenGL_CGL_CGL);

PHP_METHOD(OpenGL_CGL_CGL, CGLChoosePixelFormat);
PHP_METHOD(OpenGL_CGL_CGL, CGLDestroyPixelFormat);
PHP_METHOD(OpenGL_CGL_CGL, CGLDescribePixelFormat);
PHP_METHOD(OpenGL_CGL_CGL, CGLReleasePixelFormat);
PHP_METHOD(OpenGL_CGL_CGL, CGLRetainPixelFormat);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetPixelFormatRetainCount);
PHP_METHOD(OpenGL_CGL_CGL, CGLQueryRendererInfo);
PHP_METHOD(OpenGL_CGL_CGL, CGLDestroyRendererInfo);
PHP_METHOD(OpenGL_CGL_CGL, CGLDescribeRenderer);
PHP_METHOD(OpenGL_CGL_CGL, CGLCreateContext);
PHP_METHOD(OpenGL_CGL_CGL, CGLDestroyContext);
PHP_METHOD(OpenGL_CGL_CGL, CGLCopyContext);
PHP_METHOD(OpenGL_CGL_CGL, CGLRetainContext);
PHP_METHOD(OpenGL_CGL_CGL, CGLReleaseContext);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetContextRetainCount);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetPixelFormat);
PHP_METHOD(OpenGL_CGL_CGL, CGLCreatePBuffer);
PHP_METHOD(OpenGL_CGL_CGL, CGLDestroyPBuffer);
PHP_METHOD(OpenGL_CGL_CGL, CGLDescribePBuffer);
PHP_METHOD(OpenGL_CGL_CGL, CGLTexImagePBuffer);
PHP_METHOD(OpenGL_CGL_CGL, CGLRetainPBuffer);
PHP_METHOD(OpenGL_CGL_CGL, CGLReleasePBuffer);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetPBufferRetainCount);
PHP_METHOD(OpenGL_CGL_CGL, CGLSetOffScreen);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetOffScreen);
PHP_METHOD(OpenGL_CGL_CGL, CGLSetFullScreen);
PHP_METHOD(OpenGL_CGL_CGL, CGLSetFullScreenOnDisplay);
PHP_METHOD(OpenGL_CGL_CGL, CGLSetPBuffer);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetPBuffer);
PHP_METHOD(OpenGL_CGL_CGL, CGLClearDrawable);
PHP_METHOD(OpenGL_CGL_CGL, CGLFlushDrawable);
PHP_METHOD(OpenGL_CGL_CGL, CGLEnable);
PHP_METHOD(OpenGL_CGL_CGL, CGLDisable);
PHP_METHOD(OpenGL_CGL_CGL, CGLIsEnabled);
PHP_METHOD(OpenGL_CGL_CGL, CGLSetParameter);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetParameter);
PHP_METHOD(OpenGL_CGL_CGL, CGLSetVirtualScreen);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetVirtualScreen);
PHP_METHOD(OpenGL_CGL_CGL, CGLUpdateContext);
PHP_METHOD(OpenGL_CGL_CGL, CGLSetGlobalOption);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetGlobalOption);
PHP_METHOD(OpenGL_CGL_CGL, CGLSetOption);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetOption);
PHP_METHOD(OpenGL_CGL_CGL, CGLLockContext);
PHP_METHOD(OpenGL_CGL_CGL, CGLUnlockContext);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetVersion);
PHP_METHOD(OpenGL_CGL_CGL, CGLErrorString);
PHP_METHOD(OpenGL_CGL_CGL, CGLSetCurrentContext);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetCurrentContext);
PHP_METHOD(OpenGL_CGL_CGL, CGLGetShareGroup);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglchoosepixelformat, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attribs, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pix, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, npix, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cgldestroypixelformat, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pix, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cgldescribepixelformat, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pix, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pix_num, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglreleasepixelformat, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pix, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglretainpixelformat, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pix, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetpixelformatretaincount, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pix, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglqueryrendererinfo, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, display_mask, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rend, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nrend, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cgldestroyrendererinfo, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rend, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cgldescriberenderer, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rend, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rend_num, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, prop, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglcreatecontext, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pix, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, share, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cgldestroycontext, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglcopycontext, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, src, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dst, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglretaincontext, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglreleasecontext, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetcontextretaincount, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetpixelformat, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglcreatepbuffer, 0, 6, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalFormat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, max_level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pbuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cgldestroypbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pbuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cgldescribepbuffer, 0, 6, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, obj, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, internalFormat, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mipmap, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglteximagepbuffer, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pbuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, source, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglretainpbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pbuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglreleasepbuffer, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pbuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetpbufferretaincount, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pbuffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglsetoffscreen, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rowbytes, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, baseaddr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetoffscreen, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rowbytes, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, baseaddr, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglsetfullscreen, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglsetfullscreenondisplay, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, display_mask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglsetpbuffer, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pbuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, face, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, screen, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetpbuffer, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pbuffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, face, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, screen, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglcleardrawable, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglflushdrawable, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglenable, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cgldisable, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglisenabled, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, enable, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglsetparameter, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetparameter, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglsetvirtualscreen, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, screen, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetvirtualscreen, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, screen, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglupdatecontext, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglsetglobaloption, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetglobaloption, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglsetoption, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetoption, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cgllockcontext, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglunlockcontext, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetversion, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, majorvers, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, minorvers, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_opengl_cgl_cgl_cglerrorstring, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, error, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglsetcurrentcontext, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetcurrentcontext, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_cgl_cgl_cglgetsharegroup, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_cgl_cgl_method_entry) {
	PHP_ME(OpenGL_CGL_CGL, CGLChoosePixelFormat, arginfo_opengl_cgl_cgl_cglchoosepixelformat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLDestroyPixelFormat, arginfo_opengl_cgl_cgl_cgldestroypixelformat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLDescribePixelFormat, arginfo_opengl_cgl_cgl_cgldescribepixelformat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLReleasePixelFormat, arginfo_opengl_cgl_cgl_cglreleasepixelformat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLRetainPixelFormat, arginfo_opengl_cgl_cgl_cglretainpixelformat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetPixelFormatRetainCount, arginfo_opengl_cgl_cgl_cglgetpixelformatretaincount, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLQueryRendererInfo, arginfo_opengl_cgl_cgl_cglqueryrendererinfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLDestroyRendererInfo, arginfo_opengl_cgl_cgl_cgldestroyrendererinfo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLDescribeRenderer, arginfo_opengl_cgl_cgl_cgldescriberenderer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLCreateContext, arginfo_opengl_cgl_cgl_cglcreatecontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLDestroyContext, arginfo_opengl_cgl_cgl_cgldestroycontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLCopyContext, arginfo_opengl_cgl_cgl_cglcopycontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLRetainContext, arginfo_opengl_cgl_cgl_cglretaincontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLReleaseContext, arginfo_opengl_cgl_cgl_cglreleasecontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetContextRetainCount, arginfo_opengl_cgl_cgl_cglgetcontextretaincount, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetPixelFormat, arginfo_opengl_cgl_cgl_cglgetpixelformat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLCreatePBuffer, arginfo_opengl_cgl_cgl_cglcreatepbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLDestroyPBuffer, arginfo_opengl_cgl_cgl_cgldestroypbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLDescribePBuffer, arginfo_opengl_cgl_cgl_cgldescribepbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLTexImagePBuffer, arginfo_opengl_cgl_cgl_cglteximagepbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLRetainPBuffer, arginfo_opengl_cgl_cgl_cglretainpbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLReleasePBuffer, arginfo_opengl_cgl_cgl_cglreleasepbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetPBufferRetainCount, arginfo_opengl_cgl_cgl_cglgetpbufferretaincount, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLSetOffScreen, arginfo_opengl_cgl_cgl_cglsetoffscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetOffScreen, arginfo_opengl_cgl_cgl_cglgetoffscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLSetFullScreen, arginfo_opengl_cgl_cgl_cglsetfullscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLSetFullScreenOnDisplay, arginfo_opengl_cgl_cgl_cglsetfullscreenondisplay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLSetPBuffer, arginfo_opengl_cgl_cgl_cglsetpbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetPBuffer, arginfo_opengl_cgl_cgl_cglgetpbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLClearDrawable, arginfo_opengl_cgl_cgl_cglcleardrawable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLFlushDrawable, arginfo_opengl_cgl_cgl_cglflushdrawable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLEnable, arginfo_opengl_cgl_cgl_cglenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLDisable, arginfo_opengl_cgl_cgl_cgldisable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLIsEnabled, arginfo_opengl_cgl_cgl_cglisenabled, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLSetParameter, arginfo_opengl_cgl_cgl_cglsetparameter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetParameter, arginfo_opengl_cgl_cgl_cglgetparameter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLSetVirtualScreen, arginfo_opengl_cgl_cgl_cglsetvirtualscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetVirtualScreen, arginfo_opengl_cgl_cgl_cglgetvirtualscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLUpdateContext, arginfo_opengl_cgl_cgl_cglupdatecontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLSetGlobalOption, arginfo_opengl_cgl_cgl_cglsetglobaloption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetGlobalOption, arginfo_opengl_cgl_cgl_cglgetglobaloption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLSetOption, arginfo_opengl_cgl_cgl_cglsetoption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetOption, arginfo_opengl_cgl_cgl_cglgetoption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLLockContext, arginfo_opengl_cgl_cgl_cgllockcontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLUnlockContext, arginfo_opengl_cgl_cgl_cglunlockcontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetVersion, arginfo_opengl_cgl_cgl_cglgetversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLErrorString, arginfo_opengl_cgl_cgl_cglerrorstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLSetCurrentContext, arginfo_opengl_cgl_cgl_cglsetcurrentcontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetCurrentContext, arginfo_opengl_cgl_cgl_cglgetcurrentcontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_CGL_CGL, CGLGetShareGroup, arginfo_opengl_cgl_cgl_cglgetsharegroup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
