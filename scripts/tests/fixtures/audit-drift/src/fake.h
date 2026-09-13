/*
 * NEGATIVE CONTROL: the @audit block claims 3 prototypes; the header has 2.
 */

#ifndef FIXTURE_AUDIT_H
#define FIXTURE_AUDIT_H

#include <php.h>

/*@audit block GL\GL10 GL_VERSION_1_0 3 */

/*@zep GL\GL10 glClear(int mask) -> void */
void phpgl_gl10_glclear(zval *mask);

/*@zep GL\GL10 glGetError() -> int */
zend_long phpgl_gl10_glgeterror(void);

#endif
