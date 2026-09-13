/*
 * NEGATIVE CONTROL for gen-zep.php: the annotation promises two parameters
 * and the C prototype has one. The generator must refuse and write nothing.
 */

#ifndef FIXTURE_DRIFT_H
#define FIXTURE_DRIFT_H

#include <php.h>

/*@zep GL\GL10 glClear(int mask, int extra) -> void */
void phpgl_gl10_glclear(zval *mask);

#endif
