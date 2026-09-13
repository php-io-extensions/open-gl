/*
 * phpgl-bridge.h — the only glue in the extension.
 *
 * Two jobs, and nothing else:
 *
 *   1. The loader. Every entry point in this extension is resolved at
 *      RUNTIME through phpgl_entry(), never at link time, so one .so serves
 *      a GL 3.1 driver and a GL 4.1 driver alike. An entry point the current
 *      context or driver does not have raises
 *      E_WARNING("<name> is not available in the current context") and the
 *      binding returns 0/void. There is no error side channel.
 *
 *   2. Byte buffers. The pointer rule (binding-rules.md D2) sends every
 *      pointer across as raw bits, so PHP needs somewhere to put bytes.
 *      alloc/free/write/read are that somewhere; pack()/unpack() do the
 *      typing. write and read are bounds-checked against the allocation
 *      they name.
 *
 * Nothing here decides anything about how OpenGL is used.
 */

#ifndef PHPGL_BRIDGE_H
#define PHPGL_BRIDGE_H

#include <php.h>
#include <stdint.h>

/*
 * One cached entry point. Generated bodies declare a function-static slot,
 * so a resolved pointer costs one predictable branch per call.
 */
typedef struct {
    void *fn;
    int state;                /* 0 = unresolved, 1 = resolved, 2 = missing */
    unsigned int generation;  /* the Bridge::load() epoch this answer is from */
} phpgl_slot;

#define PHPGL_SLOT_INIT {NULL, 0, 0}

/*
 * Resolve one entry point, or warn and return NULL.
 *
 * major/minor is the GL core version the name first appeared in; (0, 0)
 * means "not version gated" (EGL and CGL). A gated name is refused when the
 * current context is older than its block, which is what makes
 * GL41::glProgramUniform1f live on a 4.1 Mac and warn on a 3.1 Pi from the
 * same binary.
 */
void *phpgl_entry(const char *name, phpgl_slot *slot, int major, int minor);

/* The registry generated from the vendored headers: name -> first version.
 * Returns 1 and writes *major/*minor when the name is known. */
int phpgl_registry_version(const char *name, int *major, int *minor);

/*
 * Module teardown: free every buffer the caller did not, destroy the
 * registry, and close the library handles. Called from the extension's
 * MSHUTDOWN, which scripts/patch-mshutdown.php wires into the generated
 * ext/opengl.c (Zephir compiles its own MSHUTDOWN out of a release build).
 * Safe to call more than once.
 */
void phpgl_bridge_shutdown(void);

/* ---- OpenGL\Bridge\Bridge ---- */

/*@zep Bridge\Bridge load() -> bool */
zend_long phpgl_bridge_load(void);

/*@zep Bridge\Bridge isAvailable(string name) -> bool */
zend_long phpgl_bridge_is_available(zval *name);

/*@zep Bridge\Bridge procAddress(string name) -> int */
zend_long phpgl_bridge_proc_address(zval *name);

/*@zep Bridge\Bridge contextVersion() -> array */
void phpgl_bridge_context_version(zval *return_value);

/*@zep Bridge\Bridge alloc(int size) -> int */
zend_long phpgl_bridge_alloc(zval *size);

/*@zep Bridge\Bridge free(int ptr) -> void */
void phpgl_bridge_free(zval *ptr);

/*@zep Bridge\Bridge write(int ptr, int offset, string bytes) -> bool */
zend_long phpgl_bridge_write(zval *ptr, zval *offset, zval *bytes);

/*@zep Bridge\Bridge read(int ptr, int offset, int length) -> var */
void phpgl_bridge_read(zval *return_value, zval *ptr, zval *offset, zval *length);

#endif /* PHPGL_BRIDGE_H */
