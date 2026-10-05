#ifndef OPENGL_RUNTIME_H
#define OPENGL_RUNTIME_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "zend_exceptions.h"
#include "php_opengl.h"

#ifdef __APPLE__
# include <OpenGL/gl3.h>
# include <OpenGL/OpenGL.h>
# define OPENGL_HAS_CONTEXT() (CGLGetCurrentContext() != NULL)
#else
# include <GLES3/gl3.h>
# include <EGL/egl.h>
# include <EGL/eglext.h>
# define OPENGL_HAS_CONTEXT() (eglGetCurrentContext() != EGL_NO_CONTEXT)
#endif

#define OPENGL_REQUIRE_CONTEXT() do { \
	if (!OPENGL_HAS_CONTEXT()) { \
		zend_throw_error(NULL, "%s(): no current OpenGL context", ZSTR_VAL(EX(func)->common.function_name)); \
		RETURN_THROWS(); \
	} \
} while (0)

ZEND_BEGIN_MODULE_GLOBALS(opengl)
	HashTable boxes;               /* native address => zend_object*, live handles only, not refcounted */
ZEND_END_MODULE_GLOBALS(opengl)

ZEND_EXTERN_MODULE_GLOBALS(opengl)
#define OPENGL_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(opengl, v)

typedef struct {
	void *ptr;                     /* the native handle; NULL once released */
	zval keep;                     /* what the native object borrows from PHP: a string, one handle, or a list of handles */
	zend_object std;
} opengl_handle;

static zend_always_inline opengl_handle *opengl_handle_from(zend_object *obj)
{
	return (opengl_handle *) ((char *) obj - XtOffsetOf(opengl_handle, std));
}

/* The PHP object holding ptr, or a new one of class ce. NULL ptr → null. */
void opengl_box(zval *rv, void *ptr, zend_class_entry *ce);
/* The live pointer in a handle parameter; throws ValueError ("CGLContextObj has been destroyed") and answers NULL when released. */
void *opengl_handle_ptr(zval *zv, zend_class_entry *ce, uint32_t arg_num);
/* Marks a handle released: pointer cleared, identity entry dropped, borrowed value let go. Kept handles are released too. */
void opengl_release(zend_object *obj);
void opengl_handle_setup(zend_class_entry *ce);

/* A list of ints ending with terminator, copied into a C array (emalloc'd; the caller efree()s it). NULL list → NULL. */
int *opengl_attrib_list(HashTable *list, int terminator, uint32_t arg_num, bool *failed);

/* Moves a freshly boxed handle (or null) into a by-reference parameter. */
bool opengl_assign_handle(zval *dest, void *ptr, zend_class_entry *ce);

/* pointer() and fromPointer() for a handle class. An address other than 0 is trusted. */
#define OPENGL_POINTER_METHODS(cls) \
	ZEND_METHOD(cls, pointer) { ZEND_PARSE_PARAMETERS_NONE(); void *p = opengl_handle_ptr(ZEND_THIS, Z_OBJCE_P(ZEND_THIS), 0); if (!p) RETURN_THROWS(); RETURN_LONG((zend_long) (uintptr_t) p); } \
	ZEND_METHOD(cls, fromPointer) { zend_long p; ZEND_PARSE_PARAMETERS_START(1, 1) Z_PARAM_LONG(p) ZEND_PARSE_PARAMETERS_END(); \
		if (p == 0) { zend_argument_value_error(1, "must not be a null address"); RETURN_THROWS(); } \
		opengl_box(return_value, (void *) (uintptr_t) p, zend_get_called_scope(execute_data)); } \
	ZEND_METHOD(cls, __construct) { ZEND_PARSE_PARAMETERS_NONE(); zend_throw_error(NULL, "%s cannot be constructed", #cls); RETURN_THROWS(); }

#ifdef __APPLE__
extern zend_class_entry *opengl_ce_CGLPixelFormatObj;
extern zend_class_entry *opengl_ce_CGLContextObj;
void opengl_register_cgl(int module_number);
#else
extern zend_class_entry *opengl_ce_EGLDisplay;
extern zend_class_entry *opengl_ce_EGLConfig;
extern zend_class_entry *opengl_ce_EGLContext;
extern zend_class_entry *opengl_ce_EGLSurface;
void opengl_register_egl(int module_number);
#endif

void opengl_register_gl_state(int module_number);
void opengl_register_gl_buffer(int module_number);

extern zend_class_entry *opengl_ce_GLsync;

#endif
