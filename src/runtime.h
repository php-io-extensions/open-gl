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
#else
# include <GLES3/gl3.h>
# include <EGL/egl.h>
# include <EGL/eglext.h>
#endif

/*
 * The probe switch. A kept refusal site reads `if (!OPENGL_PROBE_OFF("<id>") && (<check>))`.
 * A build configured with --enable-opengl-probes lets env OPENGL_PROBE_OFF=<id> turn that one
 * site off, so tests/Probes can show the crash the site prevents. A release build compiles the
 * switch out.
 */
#ifdef OPENGL_PROBES
bool opengl_probe_off(const char *id);
# define OPENGL_PROBE_OFF(id) opengl_probe_off(id)
#else
# define OPENGL_PROBE_OFF(id) 0
#endif

/* macOS GL dereferences the current context: with none, every gl* call crashes. Linux's
 * libglvnd answers a call without a context with nothing, so no check there. */
#ifdef __APPLE__
# define OPENGL_REQUIRE_CONTEXT() do { \
	if (!OPENGL_PROBE_OFF("opengl-no-context") && CGLGetCurrentContext() == NULL) { \
		zend_throw_error(NULL, "%s(): no current OpenGL context", ZSTR_VAL(EX(func)->common.function_name)); /* binding:opengl-no-context */ \
		RETURN_THROWS(); \
	} \
} while (0)
#else
# define OPENGL_REQUIRE_CONTEXT() do { } while (0)
#endif

ZEND_BEGIN_MODULE_GLOBALS(opengl)
	HashTable boxes;               /* native address => zend_object*, live handles only, not refcounted */
ZEND_END_MODULE_GLOBALS(opengl)

ZEND_EXTERN_MODULE_GLOBALS(opengl)
#define OPENGL_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(opengl, v)

typedef struct {
	void *ptr;                     /* the native handle; NULL once released */
	zend_object std;
} opengl_handle;

static zend_always_inline opengl_handle *opengl_handle_from(zend_object *obj)
{
	return (opengl_handle *) ((char *) obj - XtOffsetOf(opengl_handle, std));
}

/* The native pointer of a handle: NULL for null and for a released handle. */
static zend_always_inline void *opengl_ptr(zend_object *obj)
{
	return obj == NULL ? NULL : opengl_handle_from(obj)->ptr;
}

/* The PHP object holding ptr, or a new one of class ce. NULL ptr → null. */
void opengl_box(zval *rv, void *ptr, zend_class_entry *ce);
/* Marks a handle released: pointer cleared, identity entry dropped. */
void opengl_release(zend_object *obj);
void opengl_handle_setup(zend_class_entry *ce);

/* A PHP list of ints as a C array, each value converted as C converts it (emalloc'd; the caller
 * efree()s it). NULL or an empty list → NULL. TypeError for a value that is not an int. */
bool opengl_int_list(HashTable *list, uint32_t arg_num, int **out);
/* A list the toolkit reads count elements of: count must not pass the n elements built from it. */
bool opengl_list_count(zend_long count, uint32_t n, uint32_t count_arg, uint32_t list_arg);

/* glGen*: n names GL writes, as a list into the by-reference dest. */
bool opengl_gen_names(zend_long n, zval *dest, void (*generate)(GLsizei, GLuint *));
/* glDelete* and glDrawBuffers: n names read from the list (argument list_arg, n is list_arg - 1). */
bool opengl_delete_names(zend_long n, HashTable *list, uint32_t list_arg, void (*destroy)(GLsizei, const GLuint *));
/* A `const void *` GL reads need bytes of: a string that holds them, or an address. null_read: GL
 * reads address 0 (no buffer object bound to take it as an offset). */
bool opengl_source(zend_string *bytes, zend_long address, size_t need, bool null_read, uint32_t arg_num, const void **out);

/* Moves a freshly boxed handle (or null) into a by-reference parameter. */
bool opengl_assign_handle(zval *dest, void *ptr, zend_class_entry *ce);

/* pointer() and fromPointer() for a handle class: pointer() is 0 once released, fromPointer(0) is null. */
#define OPENGL_POINTER_METHODS(cls) \
	ZEND_METHOD(cls, pointer) { ZEND_PARSE_PARAMETERS_NONE(); RETURN_LONG((zend_long) (uintptr_t) opengl_ptr(Z_OBJ_P(ZEND_THIS))); } \
	ZEND_METHOD(cls, fromPointer) { zend_long p; ZEND_PARSE_PARAMETERS_START(1, 1) Z_PARAM_LONG(p) ZEND_PARSE_PARAMETERS_END(); \
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
