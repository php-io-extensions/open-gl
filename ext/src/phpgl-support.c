/*
 * phpgl-support.c — marshalling only. See phpgl-support.h.
 */

#include "phpgl-support.h"

zend_long phpgl_arg_long(zval *z)
{
    if (!z) {
        return 0;
    }
    if (Z_TYPE_P(z) == IS_LONG) {
        return Z_LVAL_P(z);
    }
    if (Z_TYPE_P(z) == IS_DOUBLE) {
        return (zend_long) Z_DVAL_P(z);
    }
    if (Z_TYPE_P(z) == IS_TRUE) {
        return 1;
    }
    if (Z_TYPE_P(z) == IS_FALSE || Z_TYPE_P(z) == IS_NULL) {
        return 0;
    }
    if (Z_TYPE_P(z) == IS_STRING) {
        return ZEND_STRTOL(Z_STRVAL_P(z), NULL, 10);
    }

    return 0;
}

double phpgl_arg_double(zval *z)
{
    if (!z) {
        return 0.0;
    }
    if (Z_TYPE_P(z) == IS_DOUBLE) {
        return Z_DVAL_P(z);
    }
    if (Z_TYPE_P(z) == IS_LONG) {
        return (double) Z_LVAL_P(z);
    }
    if (Z_TYPE_P(z) == IS_TRUE) {
        return 1.0;
    }
    if (Z_TYPE_P(z) == IS_STRING) {
        return zend_strtod(Z_STRVAL_P(z), NULL);
    }

    return 0.0;
}

int phpgl_arg_bool(zval *z)
{
    if (!z) {
        return 0;
    }

    return zend_is_true(z) ? 1 : 0;
}

const char *phpgl_arg_string(zval *z)
{
    if (!z || Z_TYPE_P(z) != IS_STRING) {
        return NULL;
    }

    return Z_STRVAL_P(z);
}

char **phpgl_arg_strv(zval *z, int *count_out)
{
    HashTable *ht;
    zval *entry;
    char **out;
    uint32_t n;
    uint32_t i = 0;

    if (count_out) {
        *count_out = 0;
    }
    if (!z || Z_TYPE_P(z) != IS_ARRAY) {
        return NULL;
    }

    ht = Z_ARRVAL_P(z);
    n = zend_hash_num_elements(ht);
    out = (char **) ecalloc((size_t) n + 1, sizeof(char *));

    ZEND_HASH_FOREACH_VAL(ht, entry)
    {
        zend_string *s;

        if (i >= n) {
            break;
        }
        if (Z_TYPE_P(entry) == IS_STRING) {
            out[i] = estrndup(Z_STRVAL_P(entry), Z_STRLEN_P(entry));
        } else {
            s = zval_get_string(entry);
            out[i] = estrndup(ZSTR_VAL(s), ZSTR_LEN(s));
            zend_string_release(s);
        }
        i++;
    }
    ZEND_HASH_FOREACH_END();

    out[i] = NULL;
    if (count_out) {
        *count_out = (int) i;
    }

    return out;
}

void phpgl_free_strv(char **v, int count)
{
    int i;

    if (!v) {
        return;
    }
    for (i = 0; i < count; i++) {
        if (v[i]) {
            efree(v[i]);
        }
    }
    efree(v);
}

void *phpgl_arg_ptr(zval *z)
{
    zend_long bits = phpgl_arg_long(z);

    if (bits == 0) {
        return NULL;
    }

    return (void *) (uintptr_t) bits;
}

void phpgl_ret_string(zval *return_value, const char *s)
{
    if (!s) {
        ZVAL_NULL(return_value);

        return;
    }
    ZVAL_STRING(return_value, s);
}

void phpgl_ret_ubytes(zval *return_value, const unsigned char *s)
{
    phpgl_ret_string(return_value, (const char *) s);
}
