/*
 * NEGATIVE CONTROL: the block has 2 prototypes and only 1 is bound, with no @audit partial to sanction the shortfall.
 */

#ifndef FIXTURE_AUDIT_H
#define FIXTURE_AUDIT_H

#include <php.h>

/*@audit block GL\GL10 GL_VERSION_1_0 2 */

/*@zep GL\GL10 glClear(int mask) -> void */
void phpgl_gl10_glclear(zval *mask);

#endif
