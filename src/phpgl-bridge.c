/*
 * phpgl-bridge.c — loader and byte buffers. See phpgl-bridge.h.
 *
 * This file is glue: the parity guard's composite check exempts it, because
 * sampling the context version legitimately makes more than one native call.
 * No other file in this extension may make a native call except through
 * phpgl_entry().
 */

#include "phpgl-bridge.h"
#include "phpgl-support.h"

#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* ------------------------------------------------------------------ state */

/*
 * Process globals, exactly like ext-gtk's registry: the binding assumes one
 * PHP thread talks to one GL context, which is the CLI process model it
 * targets. Do not drive GL from parallel threads.
 */
static void *phpgl_lib_gl = NULL;  /* libGL.so.1 / OpenGL.framework */
static void *phpgl_lib_egl = NULL; /* libEGL.so.1 (Linux only) */
static int phpgl_loaded = 0;

/*
 * Bumped by every Bridge::load(). A slot whose generation is older than this
 * is re-resolved on next use, so a load() after the library situation changed
 * genuinely re-resolves instead of serving a latched "missing" forever.
 * Starts at 1 so a zero-initialised slot is always stale.
 */
static unsigned int phpgl_generation = 1;

/* eglGetProcAddress, when the platform has one. */
typedef void (*phpgl_anyfn)(void);
typedef phpgl_anyfn (*phpgl_egl_getproc)(const char *);
static phpgl_egl_getproc phpgl_egl_get_proc_address = NULL;

/* Context version sampled lazily; reset by Bridge::load(). */
static int phpgl_ctx_sampled = 0;
static int phpgl_ctx_major = 0;
static int phpgl_ctx_minor = 0;

/* Buffer registry: pointer bits -> byte size. */
static HashTable *phpgl_buffers = NULL;

#if defined(__APPLE__)
#define PHPGL_GL_LIBRARY "/System/Library/Frameworks/OpenGL.framework/OpenGL"
#else
#define PHPGL_GL_LIBRARY "libGL.so.1"
#define PHPGL_EGL_LIBRARY "libEGL.so.1"
#endif

/* ------------------------------------------------------------------ loader */

static void *phpgl_dlsym_any(const char *name)
{
    void *fn = NULL;

    if (phpgl_lib_gl) {
        fn = dlsym(phpgl_lib_gl, name);
    }
    if (!fn && phpgl_lib_egl) {
        fn = dlsym(phpgl_lib_egl, name);
    }
    if (!fn) {
        /* Already-linked image: the process may have the symbol without a
         * handle of its own (a host binary that links GL itself). */
        fn = dlsym(RTLD_DEFAULT, name);
    }

    return fn;
}

static void *phpgl_resolve(const char *name)
{
    void *fn = NULL;

    if (!phpgl_loaded) {
        return NULL;
    }

    /*
     * Linux: eglGetProcAddress first, dlsym second (D3). Darwin: dlsym on
     * the framework, which is the only path CGL and GL share there.
     */
    if (phpgl_egl_get_proc_address) {
        fn = (void *) phpgl_egl_get_proc_address(name);
    }
    if (!fn) {
        fn = phpgl_dlsym_any(name);
    }

    return fn;
}

/*
 * Is a GL context current on this thread?
 *
 * This has to be answered before any GL entry point is called, and it is the
 * one thing the loader genuinely cannot do without platform knowledge.
 * Calling glGetIntegerv with no context current does not return an error on
 * macOS — it dereferences a null dispatch table and kills the process
 * (reproduced on 24.4.0 with a two-line C program). So: ask the context API
 * first, and treat "cannot tell" as "no context", which downgrades every GL
 * call to the ordinary not-available warning instead of a crash.
 */
typedef void *(*phpgl_fn_current)(void);
static phpgl_fn_current phpgl_ctx_probes[3];
static unsigned int phpgl_ctx_probes_generation = 0;

static int phpgl_have_current_context(void)
{
    int i;

    /* Re-probed whenever load() bumps the generation: the table must not
     * freeze on the first answer for the life of the process. */
    if (phpgl_ctx_probes_generation != phpgl_generation) {
        phpgl_ctx_probes_generation = phpgl_generation;
        phpgl_ctx_probes[0] = (phpgl_fn_current) phpgl_dlsym_any("CGLGetCurrentContext");
        phpgl_ctx_probes[1] = (phpgl_fn_current) phpgl_dlsym_any("eglGetCurrentContext");
        phpgl_ctx_probes[2] = (phpgl_fn_current) phpgl_dlsym_any("glXGetCurrentContext");
    }

    for (i = 0; i < 3; i++) {
        if (phpgl_ctx_probes[i] && phpgl_ctx_probes[i]() != NULL) {
            return 1;
        }
    }

    return 0;
}

/*
 * Sample the current context's core version. Only reached from glue, so the
 * several native calls here are not a composite-guard concern.
 */
static void phpgl_sample_context_version(void)
{
    typedef void (*fn_getintegerv)(unsigned int, int *);
    typedef const unsigned char *(*fn_getstring)(unsigned int);
    typedef unsigned int (*fn_geterror)(void);

    fn_getintegerv giv;
    fn_getstring gs;
    fn_geterror ge;
    int major = 0;
    int minor = 0;

    phpgl_ctx_sampled = 1;
    phpgl_ctx_major = 0;
    phpgl_ctx_minor = 0;

    if (!phpgl_loaded || !phpgl_have_current_context()) {
        return;
    }

    giv = (fn_getintegerv) phpgl_resolve("glGetIntegerv");
    ge = (fn_geterror) phpgl_resolve("glGetError");
    if (giv) {
        /* GL_MAJOR_VERSION 0x821B, GL_MINOR_VERSION 0x821C
         * (scripts/khronos/glcorearb.h, GL_VERSION_3_0 block). */
        giv(0x821Bu, &major);
        giv(0x821Cu, &minor);
        if (ge) {
            /* Drain, but never trust a driver to terminate the loop: a
             * broken or lost context can report an error forever. */
            int drain;
            for (drain = 0; drain < 64; drain++) {
                if (ge() == 0u) {
                    break;
                }
            }
        }
    }

    if (major == 0) {
        /* Fallback for a context that cannot answer GL_MAJOR_VERSION. */
        gs = (fn_getstring) phpgl_resolve("glGetString");
        if (gs) {
            /* GL_VERSION 0x1F02 (glcorearb.h, GL_VERSION_1_0 block). */
            const unsigned char *v = gs(0x1F02u);
            if (v) {
                int a = 0;
                int b = 0;
                if (sscanf((const char *) v, "%d.%d", &a, &b) == 2) {
                    major = a;
                    minor = b;
                }
            }
        }
    }

    if (major < 0 || major > 99) {
        major = 0;
        minor = 0;
    }
    phpgl_ctx_major = major;
    phpgl_ctx_minor = minor;
}

/*
 * A sampled version of 0.0 means "there was no context when we last looked",
 * which is a state the caller can leave at any time by making one current.
 * Re-sampling in that case costs one cached function-pointer call and saves
 * the caller from having to re-load() in the common "create context, then
 * draw" order. A real version is cached until the next Bridge::load().
 */
static void phpgl_ensure_context_version(void)
{
    if (!phpgl_ctx_sampled || phpgl_ctx_major == 0) {
        phpgl_sample_context_version();
    }
}

void *phpgl_entry(const char *name, phpgl_slot *slot, int major, int minor)
{
    if (!phpgl_loaded) {
        php_error_docref(NULL, E_WARNING,
            "%s is not available in the current context", name);

        return NULL;
    }

    if (major > 0) {
        /*
         * A version-gated name is a GL name, and a GL call with no context
         * current is undefined at best and fatal at worst (see
         * phpgl_have_current_context). "The context is new enough" is not
         * the same claim as "there is a context", so both are checked, every
         * call — the probe is a cached function-pointer call.
         */
        if (!phpgl_have_current_context()) {
            php_error_docref(NULL, E_WARNING,
                "%s is not available in the current context", name);

            return NULL;
        }
        phpgl_ensure_context_version();
        if (phpgl_ctx_major < major
            || (phpgl_ctx_major == major && phpgl_ctx_minor < minor)) {
            php_error_docref(NULL, E_WARNING,
                "%s is not available in the current context", name);

            return NULL;
        }
    }

    /* A slot from an older generation is stale: Bridge::load() may have
     * opened a library that was not there when this slot last resolved. */
    if (slot->state == 0 || slot->generation != phpgl_generation) {
        slot->fn = phpgl_resolve(name);
        slot->state = slot->fn ? 1 : 2;
        slot->generation = phpgl_generation;
    }
    if (slot->state != 1) {
        php_error_docref(NULL, E_WARNING,
            "%s is not available in the current context", name);

        return NULL;
    }

    return slot->fn;
}

zend_long phpgl_bridge_load(void)
{
    if (!phpgl_lib_gl) {
        phpgl_lib_gl = dlopen(PHPGL_GL_LIBRARY, RTLD_NOW | RTLD_LOCAL);
    }
#ifdef PHPGL_EGL_LIBRARY
    if (!phpgl_lib_egl) {
        phpgl_lib_egl = dlopen(PHPGL_EGL_LIBRARY, RTLD_NOW | RTLD_LOCAL);
    }
    if (phpgl_lib_egl && !phpgl_egl_get_proc_address) {
        phpgl_egl_get_proc_address =
            (phpgl_egl_getproc) dlsym(phpgl_lib_egl, "eglGetProcAddress");
    }
#endif

    phpgl_loaded = (phpgl_lib_gl || phpgl_lib_egl) ? 1 : 0;

    /*
     * Idempotent for the libraries, deliberately NOT idempotent for anything
     * cached off them. Bumping the generation invalidates every entry-point
     * slot and the current-context probe table, so a load() after the
     * situation changed re-resolves instead of serving a latched answer; and
     * the context version is re-sampled, so a load() after a different
     * context is current re-gates every version-gated entry point against it.
     */
    phpgl_generation++;
    if (phpgl_generation == 0) {
        phpgl_generation = 1; /* 0 means "never resolved" in a fresh slot */
    }
    phpgl_ctx_sampled = 0;
    if (phpgl_loaded) {
        phpgl_sample_context_version();
    }

    if (!phpgl_loaded) {
        php_error_docref(NULL, E_WARNING,
            "no OpenGL library could be opened (%s)", PHPGL_GL_LIBRARY);
    }

    return phpgl_loaded ? 1 : 0;
}

zend_long phpgl_bridge_is_available(zval *name)
{
    const char *n = phpgl_arg_string(name);
    int major = 0;
    int minor = 0;

    if (!n || !phpgl_loaded) {
        return 0;
    }

    if (phpgl_registry_version(n, &major, &minor) && major > 0) {
        phpgl_ensure_context_version();
        if (phpgl_ctx_major < major
            || (phpgl_ctx_major == major && phpgl_ctx_minor < minor)) {
            return 0;
        }
    }

    return phpgl_resolve(n) ? 1 : 0;
}

zend_long phpgl_bridge_proc_address(zval *name)
{
    const char *n = phpgl_arg_string(name);

    if (!n) {
        return 0;
    }

    return (zend_long) (uintptr_t) phpgl_resolve(n);
}

void phpgl_bridge_context_version(zval *return_value)
{
    phpgl_ensure_context_version();

    array_init(return_value);
    add_assoc_long(return_value, "major", (zend_long) phpgl_ctx_major);
    add_assoc_long(return_value, "minor", (zend_long) phpgl_ctx_minor);
    add_assoc_bool(return_value, "loaded", phpgl_loaded ? 1 : 0);
}

void phpgl_bridge_shutdown(void)
{
    zend_ulong bits;

    /*
     * Buffers are plain malloc'd and tracked in a process-global registry,
     * so nothing else will ever reclaim them. A caller that forgot a
     * Bridge::free is not a leak the process has to carry to its grave.
     */
    if (phpgl_buffers) {
        ZEND_HASH_FOREACH_NUM_KEY(phpgl_buffers, bits)
        {
            free((void *) (uintptr_t) bits);
        }
        ZEND_HASH_FOREACH_END();

        zend_hash_destroy(phpgl_buffers);
        pefree(phpgl_buffers, 1);
        phpgl_buffers = NULL;
    }

    /*
     * Closing the handles here rather than in a library destructor: at
     * MSHUTDOWN the module is being unloaded deliberately and PHP is still
     * up, which is the only point where dlclose is well ordered against the
     * GL library's own teardown.
     */
    if (phpgl_lib_gl) {
        dlclose(phpgl_lib_gl);
        phpgl_lib_gl = NULL;
    }
    if (phpgl_lib_egl) {
        dlclose(phpgl_lib_egl);
        phpgl_lib_egl = NULL;
    }
    phpgl_egl_get_proc_address = NULL;
    phpgl_loaded = 0;
    phpgl_ctx_sampled = 0;
    phpgl_ctx_major = 0;
    phpgl_ctx_minor = 0;

    /* Every cached slot and the probe table are now stale. */
    phpgl_generation++;
    if (phpgl_generation == 0) {
        phpgl_generation = 1;
    }
}

/* ----------------------------------------------------------- byte buffers */

static void phpgl_buffers_init(void)
{
    if (phpgl_buffers) {
        return;
    }
    phpgl_buffers = (HashTable *) pemalloc(sizeof(HashTable), 1);
    zend_hash_init(phpgl_buffers, 16, NULL, NULL, 1);
}

/* Returns 1 and writes *size when the pointer is a live Bridge allocation. */
static int phpgl_buffer_size(zend_ulong bits, size_t *size)
{
    zval *found;

    if (!phpgl_buffers || bits == 0) {
        return 0;
    }
    found = zend_hash_index_find(phpgl_buffers, bits);
    if (!found) {
        return 0;
    }
    if (size) {
        *size = (size_t) Z_LVAL_P(found);
    }

    return 1;
}

zend_long phpgl_bridge_alloc(zval *size)
{
    zend_long want = phpgl_arg_long(size);
    void *block;
    zval entry;

    if (want <= 0) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::alloc size must be greater than zero");

        return 0;
    }

    /*
     * Plain malloc, NOT pemalloc. pemalloc routes a failed allocation through
     * zend_out_of_memory(), which prints and calls exit(1) - so asking for a
     * buffer that cannot exist would kill the process instead of returning
     * an error a caller can see. A size guard cannot substitute for this:
     * on a 64-bit box zend_long and size_t are the same width, so the
     * "greater than SIZE_MAX" test that used to stand here was dead code and
     * alloc(PHP_INT_MAX) went straight to the fatal path.
     *
     * malloc returns NULL instead, which is the whole point. It is also the
     * right lifetime: the registry below is a process global, and a
     * request-scoped block would dangle in it after request shutdown.
     * Callers free explicitly with Bridge::free, and MSHUTDOWN sweeps
     * whatever they missed.
     */
    block = malloc((size_t) want);
    if (!block) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::alloc could not allocate " ZEND_LONG_FMT " byte(s)", want);

        return 0;
    }
    memset(block, 0, (size_t) want);

    phpgl_buffers_init();
    ZVAL_LONG(&entry, (zend_long) want);
    zend_hash_index_update(phpgl_buffers, (zend_ulong) (uintptr_t) block, &entry);

    return (zend_long) (uintptr_t) block;
}

void phpgl_bridge_free(zval *ptr)
{
    zend_ulong bits = (zend_ulong) phpgl_arg_long(ptr);

    if (bits == 0) {
        return;
    }
    if (!phpgl_buffer_size(bits, NULL)) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::free was given a pointer this extension did not allocate");

        return;
    }
    zend_hash_index_del(phpgl_buffers, bits);
    free((void *) (uintptr_t) bits);
}

zend_long phpgl_bridge_write(zval *ptr, zval *offset, zval *bytes)
{
    zend_ulong bits = (zend_ulong) phpgl_arg_long(ptr);
    zend_long off = phpgl_arg_long(offset);
    size_t size = 0;
    size_t len;

    if (!bytes || Z_TYPE_P(bytes) != IS_STRING) {
        php_error_docref(NULL, E_WARNING, "Bridge::write expects a string");

        return 0;
    }
    if (!phpgl_buffer_size(bits, &size)) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::write was given a pointer this extension did not allocate");

        return 0;
    }
    if (off < 0) {
        php_error_docref(NULL, E_WARNING, "Bridge::write offset is negative");

        return 0;
    }
    len = Z_STRLEN_P(bytes);
    if ((size_t) off > size || len > size - (size_t) off) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::write of " ZEND_LONG_FMT " byte(s) at offset " ZEND_LONG_FMT
            " exceeds the " ZEND_LONG_FMT " byte allocation",
            (zend_long) len, off, (zend_long) size);

        return 0;
    }

    memcpy((char *) (uintptr_t) bits + off, Z_STRVAL_P(bytes), len);

    return 1;
}

void phpgl_bridge_read(zval *return_value, zval *ptr, zval *offset, zval *length)
{
    zend_ulong bits = (zend_ulong) phpgl_arg_long(ptr);
    zend_long off = phpgl_arg_long(offset);
    zend_long len = phpgl_arg_long(length);
    size_t size = 0;

    if (!phpgl_buffer_size(bits, &size)) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::read was given a pointer this extension did not allocate");
        ZVAL_NULL(return_value);

        return;
    }
    if (off < 0 || len < 0) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::read offset and length must not be negative");
        ZVAL_NULL(return_value);

        return;
    }
    if ((size_t) off > size || (size_t) len > size - (size_t) off) {
        php_error_docref(NULL, E_WARNING,
            "Bridge::read of " ZEND_LONG_FMT " byte(s) at offset " ZEND_LONG_FMT
            " exceeds the " ZEND_LONG_FMT " byte allocation",
            len, off, (zend_long) size);
        ZVAL_NULL(return_value);

        return;
    }

    ZVAL_STRINGL(return_value, (const char *) (uintptr_t) bits + off, (size_t) len);
}
