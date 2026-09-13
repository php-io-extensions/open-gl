
extern zend_class_entry *opengl_gl_gl40_gl40_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL40_GL40);

PHP_METHOD(OpenGL_GL_GL40_GL40, glMinSampleShading);
PHP_METHOD(OpenGL_GL_GL40_GL40, glBlendEquationi);
PHP_METHOD(OpenGL_GL_GL40_GL40, glBlendEquationSeparatei);
PHP_METHOD(OpenGL_GL_GL40_GL40, glBlendFunci);
PHP_METHOD(OpenGL_GL_GL40_GL40, glBlendFuncSeparatei);
PHP_METHOD(OpenGL_GL_GL40_GL40, glDrawArraysIndirect);
PHP_METHOD(OpenGL_GL_GL40_GL40, glDrawElementsIndirect);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform1d);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform2d);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform3d);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform4d);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform1dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform2dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform3dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniform4dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix2dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix3dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix4dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix2x3dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix2x4dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix3x2dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix3x4dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix4x2dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformMatrix4x3dv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glGetUniformdv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glGetSubroutineUniformLocation);
PHP_METHOD(OpenGL_GL_GL40_GL40, glGetSubroutineIndex);
PHP_METHOD(OpenGL_GL_GL40_GL40, glGetActiveSubroutineUniformiv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glGetActiveSubroutineUniformName);
PHP_METHOD(OpenGL_GL_GL40_GL40, glGetActiveSubroutineName);
PHP_METHOD(OpenGL_GL_GL40_GL40, glUniformSubroutinesuiv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glGetUniformSubroutineuiv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glGetProgramStageiv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glPatchParameteri);
PHP_METHOD(OpenGL_GL_GL40_GL40, glPatchParameterfv);
PHP_METHOD(OpenGL_GL_GL40_GL40, glBindTransformFeedback);
PHP_METHOD(OpenGL_GL_GL40_GL40, glDeleteTransformFeedbacks);
PHP_METHOD(OpenGL_GL_GL40_GL40, glGenTransformFeedbacks);
PHP_METHOD(OpenGL_GL_GL40_GL40, glIsTransformFeedback);
PHP_METHOD(OpenGL_GL_GL40_GL40, glPauseTransformFeedback);
PHP_METHOD(OpenGL_GL_GL40_GL40, glResumeTransformFeedback);
PHP_METHOD(OpenGL_GL_GL40_GL40, glDrawTransformFeedback);
PHP_METHOD(OpenGL_GL_GL40_GL40, glDrawTransformFeedbackStream);
PHP_METHOD(OpenGL_GL_GL40_GL40, glBeginQueryIndexed);
PHP_METHOD(OpenGL_GL_GL40_GL40, glEndQueryIndexed);
PHP_METHOD(OpenGL_GL_GL40_GL40, glGetQueryIndexediv);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glminsampleshading, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glblendequationi, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, buf, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glblendequationseparatei, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, buf, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, modeRGB, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, modeAlpha, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glblendfunci, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, buf, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, src, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dst, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glblendfuncseparatei, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, buf, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcRGB, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstRGB, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, srcAlpha, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, dstAlpha, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gldrawarraysindirect, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indirect, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gldrawelementsindirect, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indirect, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniform1d, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniform2d, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniform3d, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniform4d, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, z, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, w, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniform1dv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniform2dv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniform3dv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniform4dv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniformmatrix2dv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniformmatrix3dv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniformmatrix4dv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniformmatrix2x3dv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniformmatrix2x4dv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniformmatrix3x2dv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniformmatrix3x4dv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniformmatrix4x2dv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniformmatrix4x3dv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transpose, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glgetuniformdv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glgetsubroutineuniformlocation, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, shadertype, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glgetsubroutineindex, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, shadertype, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glgetactivesubroutineuniformiv, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, shadertype, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, values, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glgetactivesubroutineuniformname, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, shadertype, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bufSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glgetactivesubroutinename, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, shadertype, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bufSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gluniformsubroutinesuiv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, shadertype, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indices, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glgetuniformsubroutineuiv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, shadertype, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glgetprogramstageiv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, shadertype, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, values, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glpatchparameteri, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glpatchparameterfv, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, values, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glbindtransformfeedback, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gldeletetransformfeedbacks, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, n, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ids, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glgentransformfeedbacks, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, n, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ids, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glistransformfeedback, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glpausetransformfeedback, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glresumetransformfeedback, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gldrawtransformfeedback, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_gldrawtransformfeedbackstream, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stream, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glbeginqueryindexed, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glendqueryindexed, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl40_gl40_glgetqueryindexediv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl40_gl40_method_entry) {
	PHP_ME(OpenGL_GL_GL40_GL40, glMinSampleShading, arginfo_opengl_gl_gl40_gl40_glminsampleshading, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glBlendEquationi, arginfo_opengl_gl_gl40_gl40_glblendequationi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glBlendEquationSeparatei, arginfo_opengl_gl_gl40_gl40_glblendequationseparatei, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glBlendFunci, arginfo_opengl_gl_gl40_gl40_glblendfunci, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glBlendFuncSeparatei, arginfo_opengl_gl_gl40_gl40_glblendfuncseparatei, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glDrawArraysIndirect, arginfo_opengl_gl_gl40_gl40_gldrawarraysindirect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glDrawElementsIndirect, arginfo_opengl_gl_gl40_gl40_gldrawelementsindirect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniform1d, arginfo_opengl_gl_gl40_gl40_gluniform1d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniform2d, arginfo_opengl_gl_gl40_gl40_gluniform2d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniform3d, arginfo_opengl_gl_gl40_gl40_gluniform3d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniform4d, arginfo_opengl_gl_gl40_gl40_gluniform4d, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniform1dv, arginfo_opengl_gl_gl40_gl40_gluniform1dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniform2dv, arginfo_opengl_gl_gl40_gl40_gluniform2dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniform3dv, arginfo_opengl_gl_gl40_gl40_gluniform3dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniform4dv, arginfo_opengl_gl_gl40_gl40_gluniform4dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniformMatrix2dv, arginfo_opengl_gl_gl40_gl40_gluniformmatrix2dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniformMatrix3dv, arginfo_opengl_gl_gl40_gl40_gluniformmatrix3dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniformMatrix4dv, arginfo_opengl_gl_gl40_gl40_gluniformmatrix4dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniformMatrix2x3dv, arginfo_opengl_gl_gl40_gl40_gluniformmatrix2x3dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniformMatrix2x4dv, arginfo_opengl_gl_gl40_gl40_gluniformmatrix2x4dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniformMatrix3x2dv, arginfo_opengl_gl_gl40_gl40_gluniformmatrix3x2dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniformMatrix3x4dv, arginfo_opengl_gl_gl40_gl40_gluniformmatrix3x4dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniformMatrix4x2dv, arginfo_opengl_gl_gl40_gl40_gluniformmatrix4x2dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniformMatrix4x3dv, arginfo_opengl_gl_gl40_gl40_gluniformmatrix4x3dv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glGetUniformdv, arginfo_opengl_gl_gl40_gl40_glgetuniformdv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glGetSubroutineUniformLocation, arginfo_opengl_gl_gl40_gl40_glgetsubroutineuniformlocation, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glGetSubroutineIndex, arginfo_opengl_gl_gl40_gl40_glgetsubroutineindex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glGetActiveSubroutineUniformiv, arginfo_opengl_gl_gl40_gl40_glgetactivesubroutineuniformiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glGetActiveSubroutineUniformName, arginfo_opengl_gl_gl40_gl40_glgetactivesubroutineuniformname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glGetActiveSubroutineName, arginfo_opengl_gl_gl40_gl40_glgetactivesubroutinename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glUniformSubroutinesuiv, arginfo_opengl_gl_gl40_gl40_gluniformsubroutinesuiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glGetUniformSubroutineuiv, arginfo_opengl_gl_gl40_gl40_glgetuniformsubroutineuiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glGetProgramStageiv, arginfo_opengl_gl_gl40_gl40_glgetprogramstageiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glPatchParameteri, arginfo_opengl_gl_gl40_gl40_glpatchparameteri, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glPatchParameterfv, arginfo_opengl_gl_gl40_gl40_glpatchparameterfv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glBindTransformFeedback, arginfo_opengl_gl_gl40_gl40_glbindtransformfeedback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glDeleteTransformFeedbacks, arginfo_opengl_gl_gl40_gl40_gldeletetransformfeedbacks, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glGenTransformFeedbacks, arginfo_opengl_gl_gl40_gl40_glgentransformfeedbacks, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glIsTransformFeedback, arginfo_opengl_gl_gl40_gl40_glistransformfeedback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glPauseTransformFeedback, arginfo_opengl_gl_gl40_gl40_glpausetransformfeedback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glResumeTransformFeedback, arginfo_opengl_gl_gl40_gl40_glresumetransformfeedback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glDrawTransformFeedback, arginfo_opengl_gl_gl40_gl40_gldrawtransformfeedback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glDrawTransformFeedbackStream, arginfo_opengl_gl_gl40_gl40_gldrawtransformfeedbackstream, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glBeginQueryIndexed, arginfo_opengl_gl_gl40_gl40_glbeginqueryindexed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glEndQueryIndexed, arginfo_opengl_gl_gl40_gl40_glendqueryindexed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL40_GL40, glGetQueryIndexediv, arginfo_opengl_gl_gl40_gl40_glgetqueryindexediv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
