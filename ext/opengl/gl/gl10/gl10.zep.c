
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "src/gl-10.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_GL_GL10_GL10)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\GL\\GL10, GL10, opengl, gl_gl10_gl10, opengl_gl_gl10_gl10_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glCullFace)
{
	zval *mode_param = NULL, _0;
	zend_long mode;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mode_param);
	ZVAL_LONG(&_0, mode);
	phpgl_gl10_glcullface(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glFrontFace)
{
	zval *mode_param = NULL, _0;
	zend_long mode;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mode_param);
	ZVAL_LONG(&_0, mode);
	phpgl_gl10_glfrontface(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glHint)
{
	zval *target_param = NULL, *mode_param = NULL, _0, _1;
	zend_long target, mode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &target_param, &mode_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, mode);
	phpgl_gl10_glhint(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glLineWidth)
{
	zval *width_param = NULL, _0;
	double width;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(width)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &width_param);
	width = zephir_get_doubleval(width_param);
	ZVAL_DOUBLE(&_0, width);
	phpgl_gl10_gllinewidth(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glPointSize)
{
	zval *size_param = NULL, _0;
	double size;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(size)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &size_param);
	size = zephir_get_doubleval(size_param);
	ZVAL_DOUBLE(&_0, size);
	phpgl_gl10_glpointsize(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glPolygonMode)
{
	zval *face_param = NULL, *mode_param = NULL, _0, _1;
	zend_long face, mode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(face)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &face_param, &mode_param);
	ZVAL_LONG(&_0, face);
	ZVAL_LONG(&_1, mode);
	phpgl_gl10_glpolygonmode(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glScissor)
{
	zval *x_param = NULL, *y_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2, _3;
	zend_long x, y, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &x_param, &y_param, &width_param, &height_param);
	ZVAL_LONG(&_0, x);
	ZVAL_LONG(&_1, y);
	ZVAL_LONG(&_2, width);
	ZVAL_LONG(&_3, height);
	phpgl_gl10_glscissor(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glTexParameterf)
{
	double param;
	zval *target_param = NULL, *pname_param = NULL, *param_param = NULL, _0, _1, _2;
	zend_long target, pname;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(pname)
		Z_PARAM_ZVAL(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &pname_param, &param_param);
	param = zephir_get_doubleval(param_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, pname);
	ZVAL_DOUBLE(&_2, param);
	phpgl_gl10_gltexparameterf(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glTexParameterfv)
{
	zval *target_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long target, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl10_gltexparameterfv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glTexParameteri)
{
	zval *target_param = NULL, *pname_param = NULL, *param_param = NULL, _0, _1, _2;
	zend_long target, pname, param;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &pname_param, &param_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, param);
	phpgl_gl10_gltexparameteri(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glTexParameteriv)
{
	zval *target_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long target, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl10_gltexparameteriv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glTexImage1D)
{
	zval *target_param = NULL, *level_param = NULL, *internalformat_param = NULL, *width_param = NULL, *border_param = NULL, *format_param = NULL, *type_param = NULL, *pixels_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7;
	zend_long target, level, internalformat, width, border, format, type, pixels;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(border)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(pixels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(8, 0, &target_param, &level_param, &internalformat_param, &width_param, &border_param, &format_param, &type_param, &pixels_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, border);
	ZVAL_LONG(&_5, format);
	ZVAL_LONG(&_6, type);
	ZVAL_LONG(&_7, pixels);
	phpgl_gl10_glteximage1d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glTexImage2D)
{
	zval *target_param = NULL, *level_param = NULL, *internalformat_param = NULL, *width_param = NULL, *height_param = NULL, *border_param = NULL, *format_param = NULL, *type_param = NULL, *pixels_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zend_long target, level, internalformat, width, height, border, format, type, pixels;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZEND_PARSE_PARAMETERS_START(9, 9)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(internalformat)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(border)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(pixels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(9, 0, &target_param, &level_param, &internalformat_param, &width_param, &height_param, &border_param, &format_param, &type_param, &pixels_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, internalformat);
	ZVAL_LONG(&_3, width);
	ZVAL_LONG(&_4, height);
	ZVAL_LONG(&_5, border);
	ZVAL_LONG(&_6, format);
	ZVAL_LONG(&_7, type);
	ZVAL_LONG(&_8, pixels);
	phpgl_gl10_glteximage2d(&_0, &_1, &_2, &_3, &_4, &_5, &_6, &_7, &_8);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glDrawBuffer)
{
	zval *buf_param = NULL, _0;
	zend_long buf;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(buf)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &buf_param);
	ZVAL_LONG(&_0, buf);
	phpgl_gl10_gldrawbuffer(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glClear)
{
	zval *mask_param = NULL, _0;
	zend_long mask;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mask_param);
	ZVAL_LONG(&_0, mask);
	phpgl_gl10_glclear(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glClearColor)
{
	zval *red_param = NULL, *green_param = NULL, *blue_param = NULL, *alpha_param = NULL, _0, _1, _2, _3;
	double red, green, blue, alpha;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_ZVAL(red)
		Z_PARAM_ZVAL(green)
		Z_PARAM_ZVAL(blue)
		Z_PARAM_ZVAL(alpha)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &red_param, &green_param, &blue_param, &alpha_param);
	red = zephir_get_doubleval(red_param);
	green = zephir_get_doubleval(green_param);
	blue = zephir_get_doubleval(blue_param);
	alpha = zephir_get_doubleval(alpha_param);
	ZVAL_DOUBLE(&_0, red);
	ZVAL_DOUBLE(&_1, green);
	ZVAL_DOUBLE(&_2, blue);
	ZVAL_DOUBLE(&_3, alpha);
	phpgl_gl10_glclearcolor(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glClearStencil)
{
	zval *s_param = NULL, _0;
	zend_long s;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(s)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &s_param);
	ZVAL_LONG(&_0, s);
	phpgl_gl10_glclearstencil(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glClearDepth)
{
	zval *depth_param = NULL, _0;
	double depth;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(depth)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &depth_param);
	depth = zephir_get_doubleval(depth_param);
	ZVAL_DOUBLE(&_0, depth);
	phpgl_gl10_glcleardepth(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glStencilMask)
{
	zval *mask_param = NULL, _0;
	zend_long mask;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mask_param);
	ZVAL_LONG(&_0, mask);
	phpgl_gl10_glstencilmask(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glColorMask)
{
	zval *red_param = NULL, *green_param = NULL, *blue_param = NULL, *alpha_param = NULL, _0, _1, _2, _3;
	zend_bool red, green, blue, alpha;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_BOOL(red)
		Z_PARAM_BOOL(green)
		Z_PARAM_BOOL(blue)
		Z_PARAM_BOOL(alpha)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &red_param, &green_param, &blue_param, &alpha_param);
	ZVAL_BOOL(&_0, (red ? 1 : 0));
	ZVAL_BOOL(&_1, (green ? 1 : 0));
	ZVAL_BOOL(&_2, (blue ? 1 : 0));
	ZVAL_BOOL(&_3, (alpha ? 1 : 0));
	phpgl_gl10_glcolormask(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glDepthMask)
{
	zval *flag_param = NULL, _0;
	zend_bool flag;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(flag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flag_param);
	ZVAL_BOOL(&_0, (flag ? 1 : 0));
	phpgl_gl10_gldepthmask(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glDisable)
{
	zval *cap_param = NULL, _0;
	zend_long cap;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(cap)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &cap_param);
	ZVAL_LONG(&_0, cap);
	phpgl_gl10_gldisable(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glEnable)
{
	zval *cap_param = NULL, _0;
	zend_long cap;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(cap)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &cap_param);
	ZVAL_LONG(&_0, cap);
	phpgl_gl10_glenable(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glFinish)
{

	phpgl_gl10_glfinish();
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glFlush)
{

	phpgl_gl10_glflush();
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glBlendFunc)
{
	zval *sfactor_param = NULL, *dfactor_param = NULL, _0, _1;
	zend_long sfactor, dfactor;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(sfactor)
		Z_PARAM_LONG(dfactor)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &sfactor_param, &dfactor_param);
	ZVAL_LONG(&_0, sfactor);
	ZVAL_LONG(&_1, dfactor);
	phpgl_gl10_glblendfunc(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glLogicOp)
{
	zval *opcode_param = NULL, _0;
	zend_long opcode;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(opcode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &opcode_param);
	ZVAL_LONG(&_0, opcode);
	phpgl_gl10_gllogicop(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glStencilFunc)
{
	zval *func_param = NULL, *ref_param = NULL, *mask_param = NULL, _0, _1, _2;
	zend_long func, ref, mask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(func)
		Z_PARAM_LONG(ref)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &func_param, &ref_param, &mask_param);
	ZVAL_LONG(&_0, func);
	ZVAL_LONG(&_1, ref);
	ZVAL_LONG(&_2, mask);
	phpgl_gl10_glstencilfunc(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glStencilOp)
{
	zval *fail_param = NULL, *zfail_param = NULL, *zpass_param = NULL, _0, _1, _2;
	zend_long fail, zfail, zpass;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(fail)
		Z_PARAM_LONG(zfail)
		Z_PARAM_LONG(zpass)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &fail_param, &zfail_param, &zpass_param);
	ZVAL_LONG(&_0, fail);
	ZVAL_LONG(&_1, zfail);
	ZVAL_LONG(&_2, zpass);
	phpgl_gl10_glstencilop(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glDepthFunc)
{
	zval *func_param = NULL, _0;
	zend_long func;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(func)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &func_param);
	ZVAL_LONG(&_0, func);
	phpgl_gl10_gldepthfunc(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glPixelStoref)
{
	double param;
	zval *pname_param = NULL, *param_param = NULL, _0, _1;
	zend_long pname;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_ZVAL(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &param_param);
	param = zephir_get_doubleval(param_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_DOUBLE(&_1, param);
	phpgl_gl10_glpixelstoref(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glPixelStorei)
{
	zval *pname_param = NULL, *param_param = NULL, _0, _1;
	zend_long pname, param;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &param_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, param);
	phpgl_gl10_glpixelstorei(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glReadBuffer)
{
	zval *src_param = NULL, _0;
	zend_long src;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(src)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &src_param);
	ZVAL_LONG(&_0, src);
	phpgl_gl10_glreadbuffer(&_0);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glReadPixels)
{
	zval *x_param = NULL, *y_param = NULL, *width_param = NULL, *height_param = NULL, *format_param = NULL, *type_param = NULL, *pixels_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long x, y, width, height, format, type, pixels;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(pixels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &x_param, &y_param, &width_param, &height_param, &format_param, &type_param, &pixels_param);
	ZVAL_LONG(&_0, x);
	ZVAL_LONG(&_1, y);
	ZVAL_LONG(&_2, width);
	ZVAL_LONG(&_3, height);
	ZVAL_LONG(&_4, format);
	ZVAL_LONG(&_5, type);
	ZVAL_LONG(&_6, pixels);
	phpgl_gl10_glreadpixels(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetBooleanv)
{
	zval *pname_param = NULL, *data_param = NULL, _0, _1;
	zend_long pname, data;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &data_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, data);
	phpgl_gl10_glgetbooleanv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetDoublev)
{
	zval *pname_param = NULL, *data_param = NULL, _0, _1;
	zend_long pname, data;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &data_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, data);
	phpgl_gl10_glgetdoublev(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetError)
{

	RETURN_LONG(phpgl_gl10_glgeterror());
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetFloatv)
{
	zval *pname_param = NULL, *data_param = NULL, _0, _1;
	zend_long pname, data;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &data_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, data);
	phpgl_gl10_glgetfloatv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetIntegerv)
{
	zval *pname_param = NULL, *data_param = NULL, _0, _1;
	zend_long pname, data;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(data)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &data_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, data);
	phpgl_gl10_glgetintegerv(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL, result, _0;
	zend_long name;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, name);
	phpgl_gl10_glgetstring(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetTexImage)
{
	zval *target_param = NULL, *level_param = NULL, *format_param = NULL, *type_param = NULL, *pixels_param = NULL, _0, _1, _2, _3, _4;
	zend_long target, level, format, type, pixels;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(format)
		Z_PARAM_LONG(type)
		Z_PARAM_LONG(pixels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &target_param, &level_param, &format_param, &type_param, &pixels_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, format);
	ZVAL_LONG(&_3, type);
	ZVAL_LONG(&_4, pixels);
	phpgl_gl10_glgetteximage(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetTexParameterfv)
{
	zval *target_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long target, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl10_glgettexparameterfv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetTexParameteriv)
{
	zval *target_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long target, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	phpgl_gl10_glgettexparameteriv(&_0, &_1, &_2);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetTexLevelParameterfv)
{
	zval *target_param = NULL, *level_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2, _3;
	zend_long target, level, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &level_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, pname);
	ZVAL_LONG(&_3, params);
	phpgl_gl10_glgettexlevelparameterfv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glGetTexLevelParameteriv)
{
	zval *target_param = NULL, *level_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2, _3;
	zend_long target, level, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &target_param, &level_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, target);
	ZVAL_LONG(&_1, level);
	ZVAL_LONG(&_2, pname);
	ZVAL_LONG(&_3, params);
	phpgl_gl10_glgettexlevelparameteriv(&_0, &_1, &_2, &_3);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glIsEnabled)
{
	zval *cap_param = NULL, _0;
	zend_long cap, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(cap)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &cap_param);
	ZVAL_LONG(&_0, cap);
	r = phpgl_gl10_glisenabled(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glDepthRange)
{
	zval *n_param = NULL, *f_param = NULL, _0, _1;
	double n, f;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(n)
		Z_PARAM_ZVAL(f)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &n_param, &f_param);
	n = zephir_get_doubleval(n_param);
	f = zephir_get_doubleval(f_param);
	ZVAL_DOUBLE(&_0, n);
	ZVAL_DOUBLE(&_1, f);
	phpgl_gl10_gldepthrange(&_0, &_1);
}

PHP_METHOD(OpenGL_GL_GL10_GL10, glViewport)
{
	zval *x_param = NULL, *y_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2, _3;
	zend_long x, y, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &x_param, &y_param, &width_param, &height_param);
	ZVAL_LONG(&_0, x);
	ZVAL_LONG(&_1, y);
	ZVAL_LONG(&_2, width);
	ZVAL_LONG(&_3, height);
	phpgl_gl10_glviewport(&_0, &_1, &_2, &_3);
}

