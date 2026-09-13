
extern zend_class_entry *opengl_egl_egl_ce;

ZEPHIR_INIT_CLASS(OpenGL_EGL_EGL);

PHP_METHOD(OpenGL_EGL_EGL, eglChooseConfig);
PHP_METHOD(OpenGL_EGL_EGL, eglCopyBuffers);
PHP_METHOD(OpenGL_EGL_EGL, eglCreateContext);
PHP_METHOD(OpenGL_EGL_EGL, eglCreatePbufferSurface);
PHP_METHOD(OpenGL_EGL_EGL, eglCreatePixmapSurface);
PHP_METHOD(OpenGL_EGL_EGL, eglCreateWindowSurface);
PHP_METHOD(OpenGL_EGL_EGL, eglDestroyContext);
PHP_METHOD(OpenGL_EGL_EGL, eglDestroySurface);
PHP_METHOD(OpenGL_EGL_EGL, eglGetConfigAttrib);
PHP_METHOD(OpenGL_EGL_EGL, eglGetConfigs);
PHP_METHOD(OpenGL_EGL_EGL, eglGetCurrentDisplay);
PHP_METHOD(OpenGL_EGL_EGL, eglGetCurrentSurface);
PHP_METHOD(OpenGL_EGL_EGL, eglGetDisplay);
PHP_METHOD(OpenGL_EGL_EGL, eglGetError);
PHP_METHOD(OpenGL_EGL_EGL, eglGetProcAddress);
PHP_METHOD(OpenGL_EGL_EGL, eglInitialize);
PHP_METHOD(OpenGL_EGL_EGL, eglMakeCurrent);
PHP_METHOD(OpenGL_EGL_EGL, eglQueryContext);
PHP_METHOD(OpenGL_EGL_EGL, eglQueryString);
PHP_METHOD(OpenGL_EGL_EGL, eglQuerySurface);
PHP_METHOD(OpenGL_EGL_EGL, eglSwapBuffers);
PHP_METHOD(OpenGL_EGL_EGL, eglTerminate);
PHP_METHOD(OpenGL_EGL_EGL, eglWaitGL);
PHP_METHOD(OpenGL_EGL_EGL, eglWaitNative);
PHP_METHOD(OpenGL_EGL_EGL, eglBindTexImage);
PHP_METHOD(OpenGL_EGL_EGL, eglReleaseTexImage);
PHP_METHOD(OpenGL_EGL_EGL, eglSurfaceAttrib);
PHP_METHOD(OpenGL_EGL_EGL, eglSwapInterval);
PHP_METHOD(OpenGL_EGL_EGL, eglBindAPI);
PHP_METHOD(OpenGL_EGL_EGL, eglQueryAPI);
PHP_METHOD(OpenGL_EGL_EGL, eglCreatePbufferFromClientBuffer);
PHP_METHOD(OpenGL_EGL_EGL, eglReleaseThread);
PHP_METHOD(OpenGL_EGL_EGL, eglWaitClient);
PHP_METHOD(OpenGL_EGL_EGL, eglGetCurrentContext);
PHP_METHOD(OpenGL_EGL_EGL, eglCreateSync);
PHP_METHOD(OpenGL_EGL_EGL, eglDestroySync);
PHP_METHOD(OpenGL_EGL_EGL, eglClientWaitSync);
PHP_METHOD(OpenGL_EGL_EGL, eglGetSyncAttrib);
PHP_METHOD(OpenGL_EGL_EGL, eglCreateImage);
PHP_METHOD(OpenGL_EGL_EGL, eglDestroyImage);
PHP_METHOD(OpenGL_EGL_EGL, eglGetPlatformDisplay);
PHP_METHOD(OpenGL_EGL_EGL, eglCreatePlatformWindowSurface);
PHP_METHOD(OpenGL_EGL_EGL, eglCreatePlatformPixmapSurface);
PHP_METHOD(OpenGL_EGL_EGL, eglWaitSync);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglchooseconfig, 0, 5, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, configs, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, config_size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, num_config, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglcopybuffers, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglcreatecontext, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, config, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, share_context, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglcreatepbuffersurface, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, config, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglcreatepixmapsurface, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, config, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixmap, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglcreatewindowsurface, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, config, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, win, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_egldestroycontext, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_egldestroysurface, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglgetconfigattrib, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, config, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglgetconfigs, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, configs, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, config_size, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, num_config, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglgetcurrentdisplay, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglgetcurrentsurface, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, readdraw, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglgetdisplay, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, display_id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglgeterror, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglgetprocaddress, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, procname, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglinitialize, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, major, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, minor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglmakecurrent, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, draw, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, read, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglquerycontext, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_opengl_egl_egl_eglquerystring, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglquerysurface, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglswapbuffers, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglterminate, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglwaitgl, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglwaitnative, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, engine, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglbindteximage, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglreleaseteximage, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglsurfaceattrib, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglswapinterval, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, interval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglbindapi, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, api, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglqueryapi, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglcreatepbufferfromclientbuffer, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buftype, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, config, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglreleasethread, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglwaitclient, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglgetcurrentcontext, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglcreatesync, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_egldestroysync, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sync, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglclientwaitsync, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sync, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timeout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglgetsyncattrib, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sync, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglcreateimage, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ctx, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_egldestroyimage, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglgetplatformdisplay, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, platform, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, native_display, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglcreateplatformwindowsurface, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, config, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, native_window, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglcreateplatformpixmapsurface, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, config, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, native_pixmap, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, attrib_list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_egl_egl_eglwaitsync, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, dpy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sync, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_egl_egl_method_entry) {
	PHP_ME(OpenGL_EGL_EGL, eglChooseConfig, arginfo_opengl_egl_egl_eglchooseconfig, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglCopyBuffers, arginfo_opengl_egl_egl_eglcopybuffers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglCreateContext, arginfo_opengl_egl_egl_eglcreatecontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglCreatePbufferSurface, arginfo_opengl_egl_egl_eglcreatepbuffersurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglCreatePixmapSurface, arginfo_opengl_egl_egl_eglcreatepixmapsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglCreateWindowSurface, arginfo_opengl_egl_egl_eglcreatewindowsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglDestroyContext, arginfo_opengl_egl_egl_egldestroycontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglDestroySurface, arginfo_opengl_egl_egl_egldestroysurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglGetConfigAttrib, arginfo_opengl_egl_egl_eglgetconfigattrib, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglGetConfigs, arginfo_opengl_egl_egl_eglgetconfigs, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglGetCurrentDisplay, arginfo_opengl_egl_egl_eglgetcurrentdisplay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglGetCurrentSurface, arginfo_opengl_egl_egl_eglgetcurrentsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglGetDisplay, arginfo_opengl_egl_egl_eglgetdisplay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglGetError, arginfo_opengl_egl_egl_eglgeterror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglGetProcAddress, arginfo_opengl_egl_egl_eglgetprocaddress, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglInitialize, arginfo_opengl_egl_egl_eglinitialize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglMakeCurrent, arginfo_opengl_egl_egl_eglmakecurrent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglQueryContext, arginfo_opengl_egl_egl_eglquerycontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglQueryString, arginfo_opengl_egl_egl_eglquerystring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglQuerySurface, arginfo_opengl_egl_egl_eglquerysurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglSwapBuffers, arginfo_opengl_egl_egl_eglswapbuffers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglTerminate, arginfo_opengl_egl_egl_eglterminate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglWaitGL, arginfo_opengl_egl_egl_eglwaitgl, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglWaitNative, arginfo_opengl_egl_egl_eglwaitnative, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglBindTexImage, arginfo_opengl_egl_egl_eglbindteximage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglReleaseTexImage, arginfo_opengl_egl_egl_eglreleaseteximage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglSurfaceAttrib, arginfo_opengl_egl_egl_eglsurfaceattrib, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglSwapInterval, arginfo_opengl_egl_egl_eglswapinterval, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglBindAPI, arginfo_opengl_egl_egl_eglbindapi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglQueryAPI, arginfo_opengl_egl_egl_eglqueryapi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglCreatePbufferFromClientBuffer, arginfo_opengl_egl_egl_eglcreatepbufferfromclientbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglReleaseThread, arginfo_opengl_egl_egl_eglreleasethread, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglWaitClient, arginfo_opengl_egl_egl_eglwaitclient, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglGetCurrentContext, arginfo_opengl_egl_egl_eglgetcurrentcontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglCreateSync, arginfo_opengl_egl_egl_eglcreatesync, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglDestroySync, arginfo_opengl_egl_egl_egldestroysync, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglClientWaitSync, arginfo_opengl_egl_egl_eglclientwaitsync, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglGetSyncAttrib, arginfo_opengl_egl_egl_eglgetsyncattrib, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglCreateImage, arginfo_opengl_egl_egl_eglcreateimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglDestroyImage, arginfo_opengl_egl_egl_egldestroyimage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglGetPlatformDisplay, arginfo_opengl_egl_egl_eglgetplatformdisplay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglCreatePlatformWindowSurface, arginfo_opengl_egl_egl_eglcreateplatformwindowsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglCreatePlatformPixmapSurface, arginfo_opengl_egl_egl_eglcreateplatformpixmapsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_EGL_EGL, eglWaitSync, arginfo_opengl_egl_egl_eglwaitsync, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
