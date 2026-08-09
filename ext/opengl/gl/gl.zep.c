
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

#include "opengl-compat.h"
#include <stdio.h>
#include <string.h>



/**
 * OpenGL rendering entry points (static passthrough).
 *
 * Window/context creation lives in glfw/sdl3 — this class is draw-only.
 * Named OpenGL objects are returned as Zephir DTOs with an opaque `fd` (GLuint).
 * Token constants (GL_COLOR_BUFFER_BIT, …) live in a microscrap wrapper.
 */
ZEPHIR_INIT_CLASS(Opengl_GL_GL)
{
	ZEPHIR_REGISTER_CLASS(Opengl\\GL, GL, opengl, gl_gl, opengl_gl_gl_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Opengl_GL_GL, glClearColor)
{
	zval *red_param = NULL, *green_param = NULL, *blue_param = NULL, *alpha_param = NULL;
	double red, green, blue, alpha;

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
	
            glClearColor((GLfloat) red, (GLfloat) green, (GLfloat) blue, (GLfloat) alpha);
        
}

PHP_METHOD(Opengl_GL_GL, glClear)
{
	zval *mask_param = NULL;
	zend_long mask;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mask)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mask_param);
	
            glClear((GLbitfield) mask);
        
}

PHP_METHOD(Opengl_GL_GL, glViewport)
{
	zval *x_param = NULL, *y_param = NULL, *width_param = NULL, *height_param = NULL;
	zend_long x, y, width, height;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &x_param, &y_param, &width_param, &height_param);
	
            glViewport((GLint) x, (GLint) y, (GLsizei) width, (GLsizei) height);
        
}

PHP_METHOD(Opengl_GL_GL, glScissor)
{
	zval *x_param = NULL, *y_param = NULL, *width_param = NULL, *height_param = NULL;
	zend_long x, y, width, height;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &x_param, &y_param, &width_param, &height_param);
	
            glScissor((GLint) x, (GLint) y, (GLsizei) width, (GLsizei) height);
        
}

PHP_METHOD(Opengl_GL_GL, glEnable)
{
	zval *cap_param = NULL;
	zend_long cap;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(cap)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &cap_param);
	
            glEnable((GLenum) cap);
        
}

PHP_METHOD(Opengl_GL_GL, glDisable)
{
	zval *cap_param = NULL;
	zend_long cap;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(cap)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &cap_param);
	
            glDisable((GLenum) cap);
        
}

PHP_METHOD(Opengl_GL_GL, glFlush)
{

	
            glFlush();
        
}

PHP_METHOD(Opengl_GL_GL, glFinish)
{

	
            glFinish();
        
}

PHP_METHOD(Opengl_GL_GL, glGetError)
{
	zend_long result = 0;
	
            result = (zend_long) glGetError();
        
	RETURN_LONG(result);
}

PHP_METHOD(Opengl_GL_GL, glGetString)
{
	zval result;
	zval *name_param = NULL;
	zend_long name;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &name_param);
	
            const GLubyte *s = glGetString((GLenum) name);
            ZVAL_STRING(&result, s ? (const char *) s : "");
        
	RETURN_CTORW(&result);
}

PHP_METHOD(Opengl_GL_GL, glGetIntegerv)
{
	zval *pname_param = NULL;
	zend_long pname, result = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pname)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &pname_param);
	
            GLint value = 0;
            glGetIntegerv((GLenum) pname, &value);
            result = (zend_long) value;
        
	RETURN_LONG(result);
}

PHP_METHOD(Opengl_GL_GL, glColor4f)
{
	zval *red_param = NULL, *green_param = NULL, *blue_param = NULL, *alpha_param = NULL;
	double red, green, blue, alpha;

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
	
            glColor4f((GLfloat) red, (GLfloat) green, (GLfloat) blue, (GLfloat) alpha);
        
}

PHP_METHOD(Opengl_GL_GL, glBegin)
{
	zval *mode_param = NULL;
	zend_long mode;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mode_param);
	
            glBegin((GLenum) mode);
        
}

PHP_METHOD(Opengl_GL_GL, glEnd)
{

	
            glEnd();
        
}

PHP_METHOD(Opengl_GL_GL, glVertex2f)
{
	zval *x_param = NULL, *y_param = NULL;
	double x, y;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &x_param, &y_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	
            glVertex2f((GLfloat) x, (GLfloat) y);
        
}

PHP_METHOD(Opengl_GL_GL, glVertex3f)
{
	zval *x_param = NULL, *y_param = NULL, *z_param = NULL;
	double x, y, z;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_ZVAL(z)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &x_param, &y_param, &z_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	z = zephir_get_doubleval(z_param);
	
            glVertex3f((GLfloat) x, (GLfloat) y, (GLfloat) z);
        
}

PHP_METHOD(Opengl_GL_GL, glLoadIdentity)
{

	
            glLoadIdentity();
        
}

PHP_METHOD(Opengl_GL_GL, glMatrixMode)
{
	zval *mode_param = NULL;
	zend_long mode;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &mode_param);
	
            glMatrixMode((GLenum) mode);
        
}

PHP_METHOD(Opengl_GL_GL, glOrtho)
{
	zval *left_param = NULL, *right_param = NULL, *bottom_param = NULL, *top_param = NULL, *zNear_param = NULL, *zFar_param = NULL;
	double left, right, bottom, top, zNear, zFar;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_ZVAL(left)
		Z_PARAM_ZVAL(right)
		Z_PARAM_ZVAL(bottom)
		Z_PARAM_ZVAL(top)
		Z_PARAM_ZVAL(zNear)
		Z_PARAM_ZVAL(zFar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &left_param, &right_param, &bottom_param, &top_param, &zNear_param, &zFar_param);
	left = zephir_get_doubleval(left_param);
	right = zephir_get_doubleval(right_param);
	bottom = zephir_get_doubleval(bottom_param);
	top = zephir_get_doubleval(top_param);
	zNear = zephir_get_doubleval(zNear_param);
	zFar = zephir_get_doubleval(zFar_param);
	
            glOrtho(
                (GLdouble) left, (GLdouble) right,
                (GLdouble) bottom, (GLdouble) top,
                (GLdouble) zNear, (GLdouble) zFar
            );
        
}

/**
 * Allocate one buffer object; `fd` is the GLuint name.
 */
PHP_METHOD(Opengl_GL_GL, glGenBuffer)
{
	zval buffer, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, fd = 0;

	ZVAL_UNDEF(&buffer);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	
            GLuint name = 0;
            glGenBuffers(1, &name);
            fd = (zend_long) name;
        
	ZEPHIR_INIT_VAR(&buffer);
	object_init_ex(&buffer, opengl_gl_glbuffer_ce);
	if (zephir_has_constructor(&buffer)) {
		ZEPHIR_CALL_METHOD(NULL, &buffer, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, fd);
	zephir_update_property_zval(&buffer, ZEND_STRL("fd"), &_0);
	RETURN_CCTOR(&buffer);
}

PHP_METHOD(Opengl_GL_GL, glBindBuffer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *target_param = NULL, *buffer, buffer_sub, _0, _1;
	zend_long target, fd = 0;

	ZVAL_UNDEF(&buffer_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_OBJECT_OF_CLASS(buffer, opengl_gl_glbuffer_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &target_param, &buffer);
	ZEPHIR_SEPARATE_PARAM(buffer);
	zephir_read_property(&_0, buffer, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	fd = zephir_get_numberval(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, target);
	zephir_update_property_zval(buffer, ZEND_STRL("target"), &_1);
	
            glBindBuffer((GLenum) target, (GLuint) fd);
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glBufferData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval data;
	zval *target_param = NULL, *data_param = NULL, *usage_param = NULL;
	zend_long target, usage;

	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(usage)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &target_param, &data_param, &usage_param);
	zephir_get_strval(&data, data_param);
	
            glBufferData(
                (GLenum) target,
                (GLsizeiptr) Z_STRLEN(data),
                (const void *) Z_STRVAL(data),
                (GLenum) usage
            );
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glBufferDataObject)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long usage, target = 0, fd = 0, size = 0;
	zval data;
	zval *buffer, buffer_sub, *data_param = NULL, *usage_param = NULL, _0, _1, _2;

	ZVAL_UNDEF(&buffer_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&data);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(buffer, opengl_gl_glbuffer_ce)
		Z_PARAM_STR(data)
		Z_PARAM_LONG(usage)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &buffer, &data_param, &usage_param);
	ZEPHIR_SEPARATE_PARAM(buffer);
	zephir_get_strval(&data, data_param);
	zephir_read_property(&_0, buffer, ZEND_STRL("target"), PH_NOISY_CC | PH_READONLY);
	target = zephir_get_numberval(&_0);
	zephir_read_property(&_1, buffer, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	fd = zephir_get_numberval(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, usage);
	zephir_update_property_zval(buffer, ZEND_STRL("usage"), &_2);
	
            size = (zend_long) Z_STRLEN(data);
            glBindBuffer((GLenum) target, (GLuint) fd);
            glBufferData(
                (GLenum) target,
                (GLsizeiptr) Z_STRLEN(data),
                (const void *) Z_STRVAL(data),
                (GLenum) usage
            );
        
	ZVAL_UNDEF(&_2);
	ZVAL_LONG(&_2, size);
	zephir_update_property_zval(buffer, ZEND_STRL("size"), &_2);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glDeleteBuffer)
{
	zend_long fd = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *buffer, buffer_sub, _0, _1;

	ZVAL_UNDEF(&buffer_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(buffer, opengl_gl_glbuffer_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &buffer);
	ZEPHIR_SEPARATE_PARAM(buffer);
	zephir_read_property(&_0, buffer, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	fd = zephir_get_numberval(&_0);
	
            GLuint name = (GLuint) fd;
            if (name != 0) {
                glDeleteBuffers(1, &name);
            }
        
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(buffer, ZEND_STRL("fd"), &_1);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(buffer, ZEND_STRL("size"), &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glGenTexture)
{
	zval texture, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, fd = 0;

	ZVAL_UNDEF(&texture);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	
            GLuint name = 0;
            glGenTextures(1, &name);
            fd = (zend_long) name;
        
	ZEPHIR_INIT_VAR(&texture);
	object_init_ex(&texture, opengl_gl_gltexture_ce);
	if (zephir_has_constructor(&texture)) {
		ZEPHIR_CALL_METHOD(NULL, &texture, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, fd);
	zephir_update_property_zval(&texture, ZEND_STRL("fd"), &_0);
	RETURN_CCTOR(&texture);
}

PHP_METHOD(Opengl_GL_GL, glBindTexture)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *target_param = NULL, *texture, texture_sub, _0, _1;
	zend_long target, fd = 0;

	ZVAL_UNDEF(&texture_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(target)
		Z_PARAM_OBJECT_OF_CLASS(texture, opengl_gl_gltexture_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &target_param, &texture);
	ZEPHIR_SEPARATE_PARAM(texture);
	zephir_read_property(&_0, texture, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	fd = zephir_get_numberval(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, target);
	zephir_update_property_zval(texture, ZEND_STRL("target"), &_1);
	
            glBindTexture((GLenum) target, (GLuint) fd);
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glTexParameteri)
{
	zval *target_param = NULL, *pname_param = NULL, *param_param = NULL;
	zend_long target, pname, param;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(target)
		Z_PARAM_LONG(pname)
		Z_PARAM_LONG(param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &target_param, &pname_param, &param_param);
	
            glTexParameteri((GLenum) target, (GLenum) pname, (GLint) param);
        
}

PHP_METHOD(Opengl_GL_GL, glDeleteTexture)
{
	zend_long fd = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *texture, texture_sub, _0, _1;

	ZVAL_UNDEF(&texture_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(texture, opengl_gl_gltexture_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &texture);
	ZEPHIR_SEPARATE_PARAM(texture);
	zephir_read_property(&_0, texture, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	fd = zephir_get_numberval(&_0);
	
            GLuint name = (GLuint) fd;
            if (name != 0) {
                glDeleteTextures(1, &name);
            }
        
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(texture, ZEND_STRL("fd"), &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glCreateShader)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *type_param = NULL, shader, _0;
	zend_long type, ZEPHIR_LAST_CALL_STATUS, fd = 0;

	ZVAL_UNDEF(&shader);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &type_param);
	
            fd = (zend_long) glCreateShader((GLenum) type);
        
	ZEPHIR_INIT_VAR(&shader);
	object_init_ex(&shader, opengl_gl_glshader_ce);
	if (zephir_has_constructor(&shader)) {
		ZEPHIR_CALL_METHOD(NULL, &shader, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, fd);
	zephir_update_property_zval(&shader, ZEND_STRL("fd"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, type);
	zephir_update_property_zval(&shader, ZEND_STRL("type"), &_0);
	RETURN_CCTOR(&shader);
}

PHP_METHOD(Opengl_GL_GL, glShaderSource)
{
	zend_long fd = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval source;
	zval *shader, shader_sub, *source_param = NULL, _0;

	ZVAL_UNDEF(&shader_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&source);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(shader, opengl_gl_glshader_ce)
		Z_PARAM_STR(source)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &shader, &source_param);
	zephir_get_strval(&source, source_param);
	zephir_read_property(&_0, shader, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	fd = zephir_get_numberval(&_0);
	
            const char *src = Z_STRVAL(source);
            GLint len = (GLint) Z_STRLEN(source);
            glShaderSource((GLuint) fd, 1, &src, &len);
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glCompileShader)
{
	zend_long fd = 0, status = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *shader, shader_sub, _0, _1;

	ZVAL_UNDEF(&shader_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shader, opengl_gl_glshader_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &shader);
	ZEPHIR_SEPARATE_PARAM(shader);
	zephir_read_property(&_0, shader, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	fd = zephir_get_numberval(&_0);
	
            GLint ok = 0;
            glCompileShader((GLuint) fd);
            glGetShaderiv((GLuint) fd, GL_COMPILE_STATUS, &ok);
            status = (zend_long) ok;
        
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, status);
	zephir_update_property_zval(shader, ZEND_STRL("compiled"), &_1);
	RETURN_MM_BOOL(status != 0);
}

PHP_METHOD(Opengl_GL_GL, glGetShaderInfoLog)
{
	zval result;
	zend_long fd = 0;
	zval *shader, shader_sub, _0;

	ZVAL_UNDEF(&shader_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shader, opengl_gl_glshader_ce)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &shader);
	zephir_read_property(&_0, shader, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	fd = zephir_get_numberval(&_0);
	
            GLint log_len = 0;
            glGetShaderiv((GLuint) fd, GL_INFO_LOG_LENGTH, &log_len);
            if (log_len <= 1) {
                ZVAL_STRING(&result, "");
            } else {
                char *buf = (char *) emalloc((size_t) log_len);
                GLsizei written = 0;
                glGetShaderInfoLog((GLuint) fd, log_len, &written, buf);
                ZVAL_STRINGL(&result, buf, written > 0 ? written : 0);
                efree(buf);
            }
        
	RETURN_CTORW(&result);
}

PHP_METHOD(Opengl_GL_GL, glDeleteShader)
{
	zend_long fd = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *shader, shader_sub, _0, _1;

	ZVAL_UNDEF(&shader_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(shader, opengl_gl_glshader_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &shader);
	ZEPHIR_SEPARATE_PARAM(shader);
	zephir_read_property(&_0, shader, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	fd = zephir_get_numberval(&_0);
	
            if (fd != 0) {
                glDeleteShader((GLuint) fd);
            }
        
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(shader, ZEND_STRL("fd"), &_1);
	ZVAL_UNDEF(&_1);
	ZVAL_LONG(&_1, 0);
	zephir_update_property_zval(shader, ZEND_STRL("compiled"), &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glCreateProgram)
{
	zval prog, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, fd = 0;

	ZVAL_UNDEF(&prog);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	
            fd = (zend_long) glCreateProgram();
        
	ZEPHIR_INIT_VAR(&prog);
	object_init_ex(&prog, opengl_gl_glprogram_ce);
	if (zephir_has_constructor(&prog)) {
		ZEPHIR_CALL_METHOD(NULL, &prog, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, fd);
	zephir_update_property_zval(&prog, ZEND_STRL("fd"), &_0);
	RETURN_CCTOR(&prog);
}

PHP_METHOD(Opengl_GL_GL, glAttachShader)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prog, prog_sub, *sh, sh_sub, pfd, sfd;

	ZVAL_UNDEF(&prog_sub);
	ZVAL_UNDEF(&sh_sub);
	ZVAL_UNDEF(&pfd);
	ZVAL_UNDEF(&sfd);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJECT_OF_CLASS(prog, opengl_gl_glprogram_ce)
		Z_PARAM_OBJECT_OF_CLASS(sh, opengl_gl_glshader_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &prog, &sh);
	zephir_memory_observe(&pfd);
	zephir_read_property(&pfd, prog, ZEND_STRL("fd"), PH_NOISY_CC);
	zephir_memory_observe(&sfd);
	zephir_read_property(&sfd, sh, ZEND_STRL("fd"), PH_NOISY_CC);
	
            glAttachShader((GLuint) Z_LVAL(pfd), (GLuint) Z_LVAL(sfd));
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glLinkProgram)
{
	zend_long status = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prog, prog_sub, fd, _0;

	ZVAL_UNDEF(&prog_sub);
	ZVAL_UNDEF(&fd);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(prog, opengl_gl_glprogram_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &prog);
	ZEPHIR_SEPARATE_PARAM(prog);
	zephir_read_property(&_0, prog, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&fd, &_0);
	
            GLint ok = 0;
            glLinkProgram((GLuint) Z_LVAL(fd));
            glGetProgramiv((GLuint) Z_LVAL(fd), GL_LINK_STATUS, &ok);
            status = (zend_long) ok;
        
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, status);
	zephir_update_property_zval(prog, ZEND_STRL("linked"), &_0);
	RETURN_MM_BOOL(status != 0);
}

PHP_METHOD(Opengl_GL_GL, glGetProgramInfoLog)
{
	zval result;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prog, prog_sub, fd, _0;

	ZVAL_UNDEF(&prog_sub);
	ZVAL_UNDEF(&fd);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(prog, opengl_gl_glprogram_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &prog);
	zephir_read_property(&_0, prog, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&fd, &_0);
	
            GLint log_len = 0;
            glGetProgramiv((GLuint) Z_LVAL(fd), GL_INFO_LOG_LENGTH, &log_len);
            if (log_len <= 1) {
                ZVAL_STRING(&result, "");
            } else {
                char *buf = (char *) emalloc((size_t) log_len);
                GLsizei written = 0;
                glGetProgramInfoLog((GLuint) Z_LVAL(fd), log_len, &written, buf);
                ZVAL_STRINGL(&result, buf, written > 0 ? written : 0);
                efree(buf);
            }
        
	RETURN_CTOR(&result);
}

PHP_METHOD(Opengl_GL_GL, glUseProgram)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prog, prog_sub, fd, _0;

	ZVAL_UNDEF(&prog_sub);
	ZVAL_UNDEF(&fd);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(prog, opengl_gl_glprogram_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &prog);
	zephir_read_property(&_0, prog, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&fd, &_0);
	
            glUseProgram((GLuint) Z_LVAL(fd));
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glUseProgramNone)
{

	
            glUseProgram(0);
        
}

PHP_METHOD(Opengl_GL_GL, glDeleteProgram)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prog, prog_sub, fd, _0;

	ZVAL_UNDEF(&prog_sub);
	ZVAL_UNDEF(&fd);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(prog, opengl_gl_glprogram_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &prog);
	ZEPHIR_SEPARATE_PARAM(prog);
	zephir_read_property(&_0, prog, ZEND_STRL("fd"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&fd, &_0);
	
            if (Z_LVAL(fd) != 0) {
                glDeleteProgram((GLuint) Z_LVAL(fd));
            }
        
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(prog, ZEND_STRL("fd"), &_0);
	ZVAL_UNDEF(&_0);
	ZVAL_LONG(&_0, 0);
	zephir_update_property_zval(prog, ZEND_STRL("linked"), &_0);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Opengl_GL_GL, glDrawArrays)
{
	zval *mode_param = NULL, *first_param = NULL, *count_param = NULL;
	zend_long mode, first, count;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(mode)
		Z_PARAM_LONG(first)
		Z_PARAM_LONG(count)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &mode_param, &first_param, &count_param);
	
            glDrawArrays((GLenum) mode, (GLint) first, (GLsizei) count);
        
}

