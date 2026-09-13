/*
 * POSITIVE CONTROL: the same shortfall, sanctioned by @audit partial, must audit PARTIAL and pass.
 */

#ifndef FIXTURE_AUDIT_H
#define FIXTURE_AUDIT_H

#include <php.h>

/*@audit block GL\GL10 GL_VERSION_1_0 2 */
/*@audit partial GL\GL10 fixture: only glClear is bound so far */

/*@zep GL\GL10 glClear(int mask) -> void */
void phpgl_gl10_glclear(zval *mask);

#endif
