
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "src/cgl.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(OpenGL_CGL_CGL)
{
	ZEPHIR_REGISTER_CLASS(OpenGL\\CGL, CGL, opengl, cgl_cgl, opengl_cgl_cgl_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(OpenGL_CGL_CGL, CGLChoosePixelFormat)
{
	zval *attribs_param = NULL, *pix_param = NULL, *npix_param = NULL, _0, _1, _2;
	zend_long attribs, pix, npix;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(attribs)
		Z_PARAM_LONG(pix)
		Z_PARAM_LONG(npix)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &attribs_param, &pix_param, &npix_param);
	ZVAL_LONG(&_0, attribs);
	ZVAL_LONG(&_1, pix);
	ZVAL_LONG(&_2, npix);
	RETURN_LONG(phpgl_cgl_cglchoosepixelformat(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLDestroyPixelFormat)
{
	zval *pix_param = NULL, _0;
	zend_long pix;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pix)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pix_param);
	ZVAL_LONG(&_0, pix);
	RETURN_LONG(phpgl_cgl_cgldestroypixelformat(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLDescribePixelFormat)
{
	zval *pix_param = NULL, *pix_num_param = NULL, *attrib_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long pix, pix_num, attrib, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(pix)
		Z_PARAM_LONG(pix_num)
		Z_PARAM_LONG(attrib)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &pix_param, &pix_num_param, &attrib_param, &value_param);
	ZVAL_LONG(&_0, pix);
	ZVAL_LONG(&_1, pix_num);
	ZVAL_LONG(&_2, attrib);
	ZVAL_LONG(&_3, value);
	RETURN_LONG(phpgl_cgl_cgldescribepixelformat(&_0, &_1, &_2, &_3));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLReleasePixelFormat)
{
	zval *pix_param = NULL, _0;
	zend_long pix;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pix)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pix_param);
	ZVAL_LONG(&_0, pix);
	phpgl_cgl_cglreleasepixelformat(&_0);
}

PHP_METHOD(OpenGL_CGL_CGL, CGLRetainPixelFormat)
{
	zval *pix_param = NULL, _0;
	zend_long pix;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pix)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pix_param);
	ZVAL_LONG(&_0, pix);
	RETURN_LONG(phpgl_cgl_cglretainpixelformat(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetPixelFormatRetainCount)
{
	zval *pix_param = NULL, _0;
	zend_long pix;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pix)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pix_param);
	ZVAL_LONG(&_0, pix);
	RETURN_LONG(phpgl_cgl_cglgetpixelformatretaincount(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLQueryRendererInfo)
{
	zval *display_mask_param = NULL, *rend_param = NULL, *nrend_param = NULL, _0, _1, _2;
	zend_long display_mask, rend, nrend;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(display_mask)
		Z_PARAM_LONG(rend)
		Z_PARAM_LONG(nrend)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &display_mask_param, &rend_param, &nrend_param);
	ZVAL_LONG(&_0, display_mask);
	ZVAL_LONG(&_1, rend);
	ZVAL_LONG(&_2, nrend);
	RETURN_LONG(phpgl_cgl_cglqueryrendererinfo(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLDestroyRendererInfo)
{
	zval *rend_param = NULL, _0;
	zend_long rend;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(rend)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &rend_param);
	ZVAL_LONG(&_0, rend);
	RETURN_LONG(phpgl_cgl_cgldestroyrendererinfo(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLDescribeRenderer)
{
	zval *rend_param = NULL, *rend_num_param = NULL, *prop_param = NULL, *value_param = NULL, _0, _1, _2, _3;
	zend_long rend, rend_num, prop, value;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(rend)
		Z_PARAM_LONG(rend_num)
		Z_PARAM_LONG(prop)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &rend_param, &rend_num_param, &prop_param, &value_param);
	ZVAL_LONG(&_0, rend);
	ZVAL_LONG(&_1, rend_num);
	ZVAL_LONG(&_2, prop);
	ZVAL_LONG(&_3, value);
	RETURN_LONG(phpgl_cgl_cgldescriberenderer(&_0, &_1, &_2, &_3));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLCreateContext)
{
	zval *pix_param = NULL, *share_param = NULL, *ctx_param = NULL, _0, _1, _2;
	zend_long pix, share, ctx;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(pix)
		Z_PARAM_LONG(share)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &pix_param, &share_param, &ctx_param);
	ZVAL_LONG(&_0, pix);
	ZVAL_LONG(&_1, share);
	ZVAL_LONG(&_2, ctx);
	RETURN_LONG(phpgl_cgl_cglcreatecontext(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLDestroyContext)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cgldestroycontext(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLCopyContext)
{
	zval *src_param = NULL, *dst_param = NULL, *mask_param = NULL, _0, _1, _2;
	zend_long src, dst, mask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(src)
		Z_PARAM_LONG(dst)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &src_param, &dst_param, &mask_param);
	ZVAL_LONG(&_0, src);
	ZVAL_LONG(&_1, dst);
	ZVAL_LONG(&_2, mask);
	RETURN_LONG(phpgl_cgl_cglcopycontext(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLRetainContext)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cglretaincontext(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLReleaseContext)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	phpgl_cgl_cglreleasecontext(&_0);
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetContextRetainCount)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cglgetcontextretaincount(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetPixelFormat)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cglgetpixelformat(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLCreatePBuffer)
{
	zval *width_param = NULL, *height_param = NULL, *target_param = NULL, *internalFormat_param = NULL, *max_level_param = NULL, *pbuffer_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long width, height, target, internalFormat, max_level, pbuffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(internalFormat)
		Z_PARAM_LONG(max_level)
		Z_PARAM_LONG(pbuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &width_param, &height_param, &target_param, &internalFormat_param, &max_level_param, &pbuffer_param);
	ZVAL_LONG(&_0, width);
	ZVAL_LONG(&_1, height);
	ZVAL_LONG(&_2, target);
	ZVAL_LONG(&_3, internalFormat);
	ZVAL_LONG(&_4, max_level);
	ZVAL_LONG(&_5, pbuffer);
	RETURN_LONG(phpgl_cgl_cglcreatepbuffer(&_0, &_1, &_2, &_3, &_4, &_5));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLDestroyPBuffer)
{
	zval *pbuffer_param = NULL, _0;
	zend_long pbuffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pbuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pbuffer_param);
	ZVAL_LONG(&_0, pbuffer);
	RETURN_LONG(phpgl_cgl_cgldestroypbuffer(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLDescribePBuffer)
{
	zval *obj_param = NULL, *width_param = NULL, *height_param = NULL, *target_param = NULL, *internalFormat_param = NULL, *mipmap_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long obj, width, height, target, internalFormat, mipmap;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(obj)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(internalFormat)
		Z_PARAM_LONG(mipmap)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &obj_param, &width_param, &height_param, &target_param, &internalFormat_param, &mipmap_param);
	ZVAL_LONG(&_0, obj);
	ZVAL_LONG(&_1, width);
	ZVAL_LONG(&_2, height);
	ZVAL_LONG(&_3, target);
	ZVAL_LONG(&_4, internalFormat);
	ZVAL_LONG(&_5, mipmap);
	RETURN_LONG(phpgl_cgl_cgldescribepbuffer(&_0, &_1, &_2, &_3, &_4, &_5));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLTexImagePBuffer)
{
	zval *ctx_param = NULL, *pbuffer_param = NULL, *source_param = NULL, _0, _1, _2;
	zend_long ctx, pbuffer, source;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(pbuffer)
		Z_PARAM_LONG(source)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &ctx_param, &pbuffer_param, &source_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, pbuffer);
	ZVAL_LONG(&_2, source);
	RETURN_LONG(phpgl_cgl_cglteximagepbuffer(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLRetainPBuffer)
{
	zval *pbuffer_param = NULL, _0;
	zend_long pbuffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pbuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pbuffer_param);
	ZVAL_LONG(&_0, pbuffer);
	RETURN_LONG(phpgl_cgl_cglretainpbuffer(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLReleasePBuffer)
{
	zval *pbuffer_param = NULL, _0;
	zend_long pbuffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pbuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pbuffer_param);
	ZVAL_LONG(&_0, pbuffer);
	phpgl_cgl_cglreleasepbuffer(&_0);
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetPBufferRetainCount)
{
	zval *pbuffer_param = NULL, _0;
	zend_long pbuffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pbuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pbuffer_param);
	ZVAL_LONG(&_0, pbuffer);
	RETURN_LONG(phpgl_cgl_cglgetpbufferretaincount(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLSetOffScreen)
{
	zval *ctx_param = NULL, *width_param = NULL, *height_param = NULL, *rowbytes_param = NULL, *baseaddr_param = NULL, _0, _1, _2, _3, _4;
	zend_long ctx, width, height, rowbytes, baseaddr;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(rowbytes)
		Z_PARAM_LONG(baseaddr)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &ctx_param, &width_param, &height_param, &rowbytes_param, &baseaddr_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, width);
	ZVAL_LONG(&_2, height);
	ZVAL_LONG(&_3, rowbytes);
	ZVAL_LONG(&_4, baseaddr);
	RETURN_LONG(phpgl_cgl_cglsetoffscreen(&_0, &_1, &_2, &_3, &_4));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetOffScreen)
{
	zval *ctx_param = NULL, *width_param = NULL, *height_param = NULL, *rowbytes_param = NULL, *baseaddr_param = NULL, _0, _1, _2, _3, _4;
	zend_long ctx, width, height, rowbytes, baseaddr;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_LONG(rowbytes)
		Z_PARAM_LONG(baseaddr)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &ctx_param, &width_param, &height_param, &rowbytes_param, &baseaddr_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, width);
	ZVAL_LONG(&_2, height);
	ZVAL_LONG(&_3, rowbytes);
	ZVAL_LONG(&_4, baseaddr);
	RETURN_LONG(phpgl_cgl_cglgetoffscreen(&_0, &_1, &_2, &_3, &_4));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLSetFullScreen)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cglsetfullscreen(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLSetFullScreenOnDisplay)
{
	zval *ctx_param = NULL, *display_mask_param = NULL, _0, _1;
	zend_long ctx, display_mask;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(display_mask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &ctx_param, &display_mask_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, display_mask);
	RETURN_LONG(phpgl_cgl_cglsetfullscreenondisplay(&_0, &_1));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLSetPBuffer)
{
	zval *ctx_param = NULL, *pbuffer_param = NULL, *face_param = NULL, *level_param = NULL, *screen_param = NULL, _0, _1, _2, _3, _4;
	zend_long ctx, pbuffer, face, level, screen;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(pbuffer)
		Z_PARAM_LONG(face)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(screen)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &ctx_param, &pbuffer_param, &face_param, &level_param, &screen_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, pbuffer);
	ZVAL_LONG(&_2, face);
	ZVAL_LONG(&_3, level);
	ZVAL_LONG(&_4, screen);
	RETURN_LONG(phpgl_cgl_cglsetpbuffer(&_0, &_1, &_2, &_3, &_4));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetPBuffer)
{
	zval *ctx_param = NULL, *pbuffer_param = NULL, *face_param = NULL, *level_param = NULL, *screen_param = NULL, _0, _1, _2, _3, _4;
	zend_long ctx, pbuffer, face, level, screen;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(pbuffer)
		Z_PARAM_LONG(face)
		Z_PARAM_LONG(level)
		Z_PARAM_LONG(screen)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &ctx_param, &pbuffer_param, &face_param, &level_param, &screen_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, pbuffer);
	ZVAL_LONG(&_2, face);
	ZVAL_LONG(&_3, level);
	ZVAL_LONG(&_4, screen);
	RETURN_LONG(phpgl_cgl_cglgetpbuffer(&_0, &_1, &_2, &_3, &_4));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLClearDrawable)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cglcleardrawable(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLFlushDrawable)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cglflushdrawable(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLEnable)
{
	zval *ctx_param = NULL, *pname_param = NULL, _0, _1;
	zend_long ctx, pname;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(pname)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &ctx_param, &pname_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, pname);
	RETURN_LONG(phpgl_cgl_cglenable(&_0, &_1));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLDisable)
{
	zval *ctx_param = NULL, *pname_param = NULL, _0, _1;
	zend_long ctx, pname;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(pname)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &ctx_param, &pname_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, pname);
	RETURN_LONG(phpgl_cgl_cgldisable(&_0, &_1));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLIsEnabled)
{
	zval *ctx_param = NULL, *pname_param = NULL, *enable_param = NULL, _0, _1, _2;
	zend_long ctx, pname, enable;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(enable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &ctx_param, &pname_param, &enable_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, enable);
	RETURN_LONG(phpgl_cgl_cglisenabled(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLSetParameter)
{
	zval *ctx_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long ctx, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &ctx_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	RETURN_LONG(phpgl_cgl_cglsetparameter(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetParameter)
{
	zval *ctx_param = NULL, *pname_param = NULL, *params_param = NULL, _0, _1, _2;
	zend_long ctx, pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &ctx_param, &pname_param, &params_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, pname);
	ZVAL_LONG(&_2, params);
	RETURN_LONG(phpgl_cgl_cglgetparameter(&_0, &_1, &_2));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLSetVirtualScreen)
{
	zval *ctx_param = NULL, *screen_param = NULL, _0, _1;
	zend_long ctx, screen;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(screen)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &ctx_param, &screen_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, screen);
	RETURN_LONG(phpgl_cgl_cglsetvirtualscreen(&_0, &_1));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetVirtualScreen)
{
	zval *ctx_param = NULL, *screen_param = NULL, _0, _1;
	zend_long ctx, screen;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(ctx)
		Z_PARAM_LONG(screen)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &ctx_param, &screen_param);
	ZVAL_LONG(&_0, ctx);
	ZVAL_LONG(&_1, screen);
	RETURN_LONG(phpgl_cgl_cglgetvirtualscreen(&_0, &_1));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLUpdateContext)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cglupdatecontext(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLSetGlobalOption)
{
	zval *pname_param = NULL, *params_param = NULL, _0, _1;
	zend_long pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &params_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, params);
	RETURN_LONG(phpgl_cgl_cglsetglobaloption(&_0, &_1));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetGlobalOption)
{
	zval *pname_param = NULL, *params_param = NULL, _0, _1;
	zend_long pname, params;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(params)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &pname_param, &params_param);
	ZVAL_LONG(&_0, pname);
	ZVAL_LONG(&_1, params);
	RETURN_LONG(phpgl_cgl_cglgetglobaloption(&_0, &_1));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLSetOption)
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
	RETURN_LONG(phpgl_cgl_cglsetoption(&_0, &_1));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetOption)
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
	RETURN_LONG(phpgl_cgl_cglgetoption(&_0, &_1));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLLockContext)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cgllockcontext(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLUnlockContext)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cglunlockcontext(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetVersion)
{
	zval *majorvers_param = NULL, *minorvers_param = NULL, _0, _1;
	zend_long majorvers, minorvers;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(majorvers)
		Z_PARAM_LONG(minorvers)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &majorvers_param, &minorvers_param);
	ZVAL_LONG(&_0, majorvers);
	ZVAL_LONG(&_1, minorvers);
	phpgl_cgl_cglgetversion(&_0, &_1);
}

PHP_METHOD(OpenGL_CGL_CGL, CGLErrorString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *error_param = NULL, result, _0;
	zend_long error;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(error)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &error_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, error);
	phpgl_cgl_cglerrorstring(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(OpenGL_CGL_CGL, CGLSetCurrentContext)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cglsetcurrentcontext(&_0));
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetCurrentContext)
{

	RETURN_LONG(phpgl_cgl_cglgetcurrentcontext());
}

PHP_METHOD(OpenGL_CGL_CGL, CGLGetShareGroup)
{
	zval *ctx_param = NULL, _0;
	zend_long ctx;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(ctx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &ctx_param);
	ZVAL_LONG(&_0, ctx);
	RETURN_LONG(phpgl_cgl_cglgetsharegroup(&_0));
}

