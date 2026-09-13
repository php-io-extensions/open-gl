/*
 * phpgl-support.h — the only marshalling layer.
 *
 * Every generated binding body reaches PHP values through these helpers and
 * through nothing else. They are pure translation: no GL, EGL or CGL call is
 * ever made here, and none of them decides anything about how the API is
 * used.
 *
 * The pointer rule (binding-rules.md, D2): every pointer parameter that is
 * not `const GLchar *` (string in) or `const GLchar *const *` (array of
 * strings in) crosses the boundary as raw pointer bits in a PHP int, 0 =
 * NULL. PHP builds and reads those bytes with Bridge::alloc/write/read and
 * pack()/unpack().
 *
 * This header carries no binding annotations of its own; the parity guard
 * skips it for that reason.
 */

#ifndef PHPGL_SUPPORT_H
#define PHPGL_SUPPORT_H

#include <php.h>
#include <stdint.h>

/* ---- scalars in ---- */

zend_long phpgl_arg_long(zval *z);
double phpgl_arg_double(zval *z);
int phpgl_arg_bool(zval *z);

/* ---- strings in ---- */

/* Borrowed NUL-terminated bytes; NULL when the zval is null. */
const char *phpgl_arg_string(zval *z);

/*
 * Array of strings -> char **, emalloc'd, one entry per array element plus a
 * trailing NULL. *count_out receives the element count. Returns NULL (and
 * sets *count_out to 0) when the zval is not an array.
 */
char **phpgl_arg_strv(zval *z, int *count_out);
void phpgl_free_strv(char **v, int count);

/* ---- pointers in ---- */

/* Raw pointer bits -> void *; 0 -> NULL. No validation: see the
 * pointer-bits-only trap. */
void *phpgl_arg_ptr(zval *z);

/* ---- values out ---- */

void phpgl_ret_string(zval *return_value, const char *s);
void phpgl_ret_ubytes(zval *return_value, const unsigned char *s);

#endif /* PHPGL_SUPPORT_H */
