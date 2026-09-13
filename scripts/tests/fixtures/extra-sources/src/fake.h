/*
 * Fixture header: two well-formed bindings, one of each return shape the
 * parity guard has to understand.
 */

#ifndef FIXTURE_FAKE_H
#define FIXTURE_FAKE_H

#include <php.h>

/*@zep GL\GL10 glClear(int mask) -> void */
void phpgl_gl10_glclear(zval *mask);

/*@zep GL\GL10 glGetError() -> int */
zend_long phpgl_gl10_glgeterror(void);

#endif
