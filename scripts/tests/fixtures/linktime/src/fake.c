/* Fixture implementation. */

#include "fake.h"
#include "phpgl-bridge.h"
#include "phpgl-support.h"

void phpgl_gl10_glclear(zval *mask)
{
    static phpgl_slot slot = PHPGL_SLOT_INIT;
    PFNGLCLEARPROC fn = (PFNGLCLEARPROC) phpgl_entry("glClear", &slot, 1, 0);

    if (!fn) {
        return;
    }

    /* NEGATIVE CONTROL: a link-time call by name instead of through fn. */
    glClear((GLbitfield) phpgl_arg_long(mask));
}

zend_long phpgl_gl10_glgeterror(void)
{
    static phpgl_slot slot = PHPGL_SLOT_INIT;
    PFNGLGETERRORPROC fn = (PFNGLGETERRORPROC) phpgl_entry("glGetError", &slot, 1, 0);

    if (!fn) {
        return 0;
    }

    return (zend_long) fn();
}
