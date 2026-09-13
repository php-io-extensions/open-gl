
extern zend_class_entry *opengl_gl_gl33_gl33_ce;

ZEPHIR_INIT_CLASS(OpenGL_GL_GL33_GL33);

PHP_METHOD(OpenGL_GL_GL33_GL33, glBindFragDataLocationIndexed);
PHP_METHOD(OpenGL_GL_GL33_GL33, glGetFragDataIndex);
PHP_METHOD(OpenGL_GL_GL33_GL33, glGenSamplers);
PHP_METHOD(OpenGL_GL_GL33_GL33, glDeleteSamplers);
PHP_METHOD(OpenGL_GL_GL33_GL33, glIsSampler);
PHP_METHOD(OpenGL_GL_GL33_GL33, glBindSampler);
PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameteri);
PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameteriv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameterf);
PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameterfv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameterIiv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glSamplerParameterIuiv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glGetSamplerParameteriv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glGetSamplerParameterIiv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glGetSamplerParameterfv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glGetSamplerParameterIuiv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glQueryCounter);
PHP_METHOD(OpenGL_GL_GL33_GL33, glGetQueryObjecti64v);
PHP_METHOD(OpenGL_GL_GL33_GL33, glGetQueryObjectui64v);
PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribDivisor);
PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP1ui);
PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP1uiv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP2ui);
PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP2uiv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP3ui);
PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP3uiv);
PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP4ui);
PHP_METHOD(OpenGL_GL_GL33_GL33, glVertexAttribP4uiv);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glbindfragdatalocationindexed, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, colorNumber, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glgetfragdataindex, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, program, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glgensamplers, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, samplers, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_gldeletesamplers, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, count, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, samplers, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glissampler, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glbindsampler, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, unit, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glsamplerparameteri, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glsamplerparameteriv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glsamplerparameterf, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glsamplerparameterfv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glsamplerparameteriiv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glsamplerparameteriuiv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, param, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glgetsamplerparameteriv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glgetsamplerparameteriiv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glgetsamplerparameterfv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glgetsamplerparameteriuiv, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sampler, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glquerycounter, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, target, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glgetqueryobjecti64v, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glgetqueryobjectui64v, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pname, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, params, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glvertexattribdivisor, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, divisor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glvertexattribp1ui, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, normalized, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glvertexattribp1uiv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, normalized, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glvertexattribp2ui, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, normalized, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glvertexattribp2uiv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, normalized, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glvertexattribp3ui, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, normalized, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glvertexattribp3uiv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, normalized, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glvertexattribp4ui, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, normalized, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_opengl_gl_gl33_gl33_glvertexattribp4uiv, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, normalized, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(opengl_gl_gl33_gl33_method_entry) {
	PHP_ME(OpenGL_GL_GL33_GL33, glBindFragDataLocationIndexed, arginfo_opengl_gl_gl33_gl33_glbindfragdatalocationindexed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glGetFragDataIndex, arginfo_opengl_gl_gl33_gl33_glgetfragdataindex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glGenSamplers, arginfo_opengl_gl_gl33_gl33_glgensamplers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glDeleteSamplers, arginfo_opengl_gl_gl33_gl33_gldeletesamplers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glIsSampler, arginfo_opengl_gl_gl33_gl33_glissampler, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glBindSampler, arginfo_opengl_gl_gl33_gl33_glbindsampler, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glSamplerParameteri, arginfo_opengl_gl_gl33_gl33_glsamplerparameteri, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glSamplerParameteriv, arginfo_opengl_gl_gl33_gl33_glsamplerparameteriv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glSamplerParameterf, arginfo_opengl_gl_gl33_gl33_glsamplerparameterf, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glSamplerParameterfv, arginfo_opengl_gl_gl33_gl33_glsamplerparameterfv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glSamplerParameterIiv, arginfo_opengl_gl_gl33_gl33_glsamplerparameteriiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glSamplerParameterIuiv, arginfo_opengl_gl_gl33_gl33_glsamplerparameteriuiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glGetSamplerParameteriv, arginfo_opengl_gl_gl33_gl33_glgetsamplerparameteriv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glGetSamplerParameterIiv, arginfo_opengl_gl_gl33_gl33_glgetsamplerparameteriiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glGetSamplerParameterfv, arginfo_opengl_gl_gl33_gl33_glgetsamplerparameterfv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glGetSamplerParameterIuiv, arginfo_opengl_gl_gl33_gl33_glgetsamplerparameteriuiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glQueryCounter, arginfo_opengl_gl_gl33_gl33_glquerycounter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glGetQueryObjecti64v, arginfo_opengl_gl_gl33_gl33_glgetqueryobjecti64v, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glGetQueryObjectui64v, arginfo_opengl_gl_gl33_gl33_glgetqueryobjectui64v, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glVertexAttribDivisor, arginfo_opengl_gl_gl33_gl33_glvertexattribdivisor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glVertexAttribP1ui, arginfo_opengl_gl_gl33_gl33_glvertexattribp1ui, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glVertexAttribP1uiv, arginfo_opengl_gl_gl33_gl33_glvertexattribp1uiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glVertexAttribP2ui, arginfo_opengl_gl_gl33_gl33_glvertexattribp2ui, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glVertexAttribP2uiv, arginfo_opengl_gl_gl33_gl33_glvertexattribp2uiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glVertexAttribP3ui, arginfo_opengl_gl_gl33_gl33_glvertexattribp3ui, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glVertexAttribP3uiv, arginfo_opengl_gl_gl33_gl33_glvertexattribp3uiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glVertexAttribP4ui, arginfo_opengl_gl_gl33_gl33_glvertexattribp4ui, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(OpenGL_GL_GL33_GL33, glVertexAttribP4uiv, arginfo_opengl_gl_gl33_gl33_glvertexattribp4uiv, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
