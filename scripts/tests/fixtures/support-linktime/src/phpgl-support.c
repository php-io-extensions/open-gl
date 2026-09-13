/*
 * NEGATIVE CONTROL for check-parity.php's whole-file scan.
 *
 * This file carries no @zep annotation at all, so the composite guard — which
 * only inspects annotated bodies — never looks at it. It still must not be
 * allowed to call a GL entry point by name.
 */

#include "phpgl-support.h"

void phpgl_helper_that_should_not_exist(void)
{
    glFlush();
}
