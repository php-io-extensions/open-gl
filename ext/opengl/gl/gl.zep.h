
extern zend_class_entry *opengl_gl_gl_ce;

ZEPHIR_INIT_CLASS(Opengl_GL_GL);

PHP_METHOD(Opengl_GL_GL, glClearColor);
PHP_METHOD(Opengl_GL_GL, glClear);
PHP_METHOD(Opengl_GL_GL, glViewport);
PHP_METHOD(Opengl_GL_GL, glScissor);
PHP_METHOD(Opengl_GL_GL, glEnable);
PHP_METHOD(Opengl_GL_GL, glDisable);
PHP_METHOD(Opengl_GL_GL, glFlush);
PHP_METHOD(Opengl_GL_GL, glFinish);
PHP_METHOD(Opengl_GL_GL, glGetError);
PHP_METHOD(Opengl_GL_GL, glGetString);
PHP_METHOD(Opengl_GL_GL, glGetIntegerv);
PHP_METHOD(Opengl_GL_GL, glColor4f);
PHP_METHOD(Opengl_GL_GL, glBegin);
PHP_METHOD(Opengl_GL_GL, glEnd);
PHP_METHOD(Opengl_GL_GL, glVertex2f);
PHP_METHOD(Opengl_GL_GL, glVertex3f);
PHP_METHOD(Opengl_GL_GL, glLoadIdentity);
PHP_METHOD(Opengl_GL_GL, glMatrixMode);
PHP_METHOD(Opengl_GL_GL, glOrtho);
PHP_METHOD(Opengl_GL_GL, glGenBuffer);
PHP_METHOD(Opengl_GL_GL, glBindBuffer);
PHP_METHOD(Opengl_GL_GL, glBufferData);
PHP_METHOD(Opengl_GL_GL, glBufferDataObject);
PHP_METHOD(Opengl_GL_GL, glDeleteBuffer);
PHP_METHOD(Opengl_GL_GL, glGenTexture);
PHP_METHOD(Opengl_GL_GL, glBindTexture);
PHP_METHOD(Opengl_GL_GL, glTexParameteri);
PHP_METHOD(Opengl_GL_GL, glDeleteTexture);
PHP_METHOD(Opengl_GL_GL, glCreateShader);
PHP_METHOD(Opengl_GL_GL, glShaderSource);
PHP_METHOD(Opengl_GL_GL, glCompileShader);
PHP_METHOD(Opengl_GL_GL, glGetShaderInfoLog);
PHP_METHOD(Opengl_GL_GL, glDeleteShader);
PHP_METHOD(Opengl_GL_GL, glCreateProgram);
PHP_METHOD(Opengl_GL_GL, glAttachShader);
PHP_METHOD(Opengl_GL_GL, glLinkProgram);
PHP_METHOD(Opengl_GL_GL, glGetProgramInfoLog);
PHP_METHOD(Opengl_GL_GL, glUseProgram);
PHP_METHOD(Opengl_GL_GL, glUseProgramNone);
PHP_METHOD(Opengl_GL_GL, glDeleteProgram);
PHP_METHOD(Opengl_GL_GL, glDrawArrays);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glclearcolor, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glclear, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mask, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glviewport, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glscissor, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glenable, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, cap, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_gldisable, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, cap, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glflush, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glfinish, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glgeterror, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glgetstring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glgetintegerv, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glcolor4f, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, red, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, green, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, blue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, alpha, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glbegin, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glend, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glvertex2f, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glvertex3f, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glloadidentity, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glmatrixmode, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glortho, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, left, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, right, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, bottom, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, top, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, zNear, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, zFar, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_opengl_gl_gl_glgenbuffer, 0, 0, Opengl\\GL\\GlBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glbindbuffer, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, buffer, Opengl\\GL\\GlBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glbufferdata, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, usage, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glbufferdataobject, 0, 3, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, buffer, Opengl\\GL\\GlBuffer, 0)
	ZEND_ARG_TYPE_INFO(0, data, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, usage, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_gldeletebuffer, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, buffer, Opengl\\GL\\GlBuffer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_opengl_gl_gl_glgentexture, 0, 0, Opengl\\GL\\GlTexture, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glbindtexture, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, texture, Opengl\\GL\\GlTexture, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_gltexparameteri, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_gldeletetexture, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, texture, Opengl\\GL\\GlTexture, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_opengl_gl_gl_glcreateshader, 0, 1, Opengl\\GL\\GlShader, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glshadersource, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, shader, Opengl\\GL\\GlShader, 0)
	ZEND_ARG_TYPE_INFO(0, source, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glcompileshader, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, shader, Opengl\\GL\\GlShader, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glgetshaderinfolog, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, shader, Opengl\\GL\\GlShader, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_gldeleteshader, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, shader, Opengl\\GL\\GlShader, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_opengl_gl_gl_glcreateprogram, 0, 0, Opengl\\GL\\GlProgram, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glattachshader, 0, 2, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, prog, Opengl\\GL\\GlProgram, 0)
	ZEND_ARG_OBJ_INFO(0, sh, Opengl\\GL\\GlShader, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_gllinkprogram, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, prog, Opengl\\GL\\GlProgram, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_glgetprograminfolog, 0, 1, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, prog, Opengl\\GL\\GlProgram, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_gluseprogram, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, prog, Opengl\\GL\\GlProgram, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_gluseprogramnone, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_gldeleteprogram, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, prog, Opengl\\GL\\GlProgram, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl_gldrawarrays, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, first, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl_method_entry) {
	PHP_ME(Opengl_GL_GL, glClearColor, arginfo_opengl_gl_gl_glclearcolor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glClear, arginfo_opengl_gl_gl_glclear, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glViewport, arginfo_opengl_gl_gl_glviewport, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glScissor, arginfo_opengl_gl_gl_glscissor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glEnable, arginfo_opengl_gl_gl_glenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glDisable, arginfo_opengl_gl_gl_gldisable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glFlush, arginfo_opengl_gl_gl_glflush, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glFinish, arginfo_opengl_gl_gl_glfinish, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glGetError, arginfo_opengl_gl_gl_glgeterror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glGetString, arginfo_opengl_gl_gl_glgetstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glGetIntegerv, arginfo_opengl_gl_gl_glgetintegerv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glColor4f, arginfo_opengl_gl_gl_glcolor4f, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glBegin, arginfo_opengl_gl_gl_glbegin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glEnd, arginfo_opengl_gl_gl_glend, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glVertex2f, arginfo_opengl_gl_gl_glvertex2f, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glVertex3f, arginfo_opengl_gl_gl_glvertex3f, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glLoadIdentity, arginfo_opengl_gl_gl_glloadidentity, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glMatrixMode, arginfo_opengl_gl_gl_glmatrixmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glOrtho, arginfo_opengl_gl_gl_glortho, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glGenBuffer, arginfo_opengl_gl_gl_glgenbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glBindBuffer, arginfo_opengl_gl_gl_glbindbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glBufferData, arginfo_opengl_gl_gl_glbufferdata, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glBufferDataObject, arginfo_opengl_gl_gl_glbufferdataobject, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glDeleteBuffer, arginfo_opengl_gl_gl_gldeletebuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glGenTexture, arginfo_opengl_gl_gl_glgentexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glBindTexture, arginfo_opengl_gl_gl_glbindtexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glTexParameteri, arginfo_opengl_gl_gl_gltexparameteri, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glDeleteTexture, arginfo_opengl_gl_gl_gldeletetexture, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glCreateShader, arginfo_opengl_gl_gl_glcreateshader, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glShaderSource, arginfo_opengl_gl_gl_glshadersource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glCompileShader, arginfo_opengl_gl_gl_glcompileshader, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glGetShaderInfoLog, arginfo_opengl_gl_gl_glgetshaderinfolog, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glDeleteShader, arginfo_opengl_gl_gl_gldeleteshader, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glCreateProgram, arginfo_opengl_gl_gl_glcreateprogram, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glAttachShader, arginfo_opengl_gl_gl_glattachshader, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glLinkProgram, arginfo_opengl_gl_gl_gllinkprogram, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glGetProgramInfoLog, arginfo_opengl_gl_gl_glgetprograminfolog, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glUseProgram, arginfo_opengl_gl_gl_gluseprogram, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glUseProgramNone, arginfo_opengl_gl_gl_gluseprogramnone, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glDeleteProgram, arginfo_opengl_gl_gl_gldeleteprogram, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Opengl_GL_GL, glDrawArrays, arginfo_opengl_gl_gl_gldrawarrays, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
