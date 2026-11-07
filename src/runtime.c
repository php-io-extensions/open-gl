#include "runtime.h"

static zend_object_handlers opengl_handle_handlers;

static zend_object *opengl_create_object(zend_class_entry *ce)
{
	opengl_handle *intern = zend_object_alloc(sizeof(opengl_handle), ce);

	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);
	intern->std.handlers = &opengl_handle_handlers;
	intern->ptr = NULL;

	return &intern->std;
}

static void opengl_free_object(zend_object *object)
{
	opengl_release(object);
	zend_object_std_dtor(object);
}

void opengl_handle_setup(zend_class_entry *ce)
{
	static bool handlers_ready = false;

	if (!handlers_ready) {
		memcpy(&opengl_handle_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
		opengl_handle_handlers.offset = XtOffsetOf(opengl_handle, std);
		opengl_handle_handlers.free_obj = opengl_free_object;
		opengl_handle_handlers.clone_obj = NULL;
		handlers_ready = true;
	}

	ce->create_object = opengl_create_object;
	ce->default_object_handlers = &opengl_handle_handlers;
	ce->ce_flags |= ZEND_ACC_NOT_SERIALIZABLE | ZEND_ACC_FINAL;
}

void opengl_release(zend_object *obj)
{
	opengl_handle *intern = opengl_handle_from(obj);

	if (intern->ptr != NULL) {
		zend_hash_index_del(&OPENGL_G(boxes), (zend_ulong) (uintptr_t) intern->ptr);
		intern->ptr = NULL;
	}
}

void opengl_box(zval *rv, void *ptr, zend_class_entry *ce)
{
	zend_object *existing;

	if (ptr == NULL) {
		ZVAL_NULL(rv);
		return;
	}

	existing = zend_hash_index_find_ptr(&OPENGL_G(boxes), (zend_ulong) (uintptr_t) ptr);
	if (existing != NULL && instanceof_function(existing->ce, ce)) {
		ZVAL_OBJ_COPY(rv, existing);
		return;
	}

	if (existing != NULL) {
		/* A different class already boxed this address. Detach it so its free_obj cannot drop the new entry. */
		opengl_handle_from(existing)->ptr = NULL;
	}

	object_init_ex(rv, ce);
	opengl_handle_from(Z_OBJ_P(rv))->ptr = ptr;
	zend_hash_index_update_ptr(&OPENGL_G(boxes), (zend_ulong) (uintptr_t) ptr, Z_OBJ_P(rv));
}

bool opengl_assign_handle(zval *dest, void *ptr, zend_class_entry *ce)
{
	zval obj;

	opengl_box(&obj, ptr, ce);
	ZEND_TRY_ASSIGN_REF_TMP(dest, &obj);

	return EG(exception) == NULL;
}

#ifdef OPENGL_PROBES
bool opengl_probe_off(const char *id)
{
	const char *off = getenv("OPENGL_PROBE_OFF");

	return off != NULL && strcmp(off, id) == 0;
}
#endif

bool opengl_int_list(HashTable *list, uint32_t arg_num, int **out)
{
	uint32_t i = 0;
	zval *zv;

	*out = NULL;
	if (list == NULL || zend_hash_num_elements(list) == 0) {
		return true;
	}

	*out = safe_emalloc(zend_hash_num_elements(list), sizeof(int), 0);
	ZEND_HASH_FOREACH_VAL(list, zv) {
		ZVAL_DEREF(zv);
		if (Z_TYPE_P(zv) != IS_LONG) {
			efree(*out);
			*out = NULL;
			zend_argument_type_error(arg_num, "must be a list of ints, %s found", zend_zval_value_name(zv));
			return false;
		}
		(*out)[i++] = (int) Z_LVAL_P(zv);
	} ZEND_HASH_FOREACH_END();

	return true;
}

bool opengl_list_count(zend_long count, uint32_t n, uint32_t count_arg, uint32_t list_arg)
{
	/* GL reads count elements of the C array built from the list. A negative count is GL_INVALID_VALUE, read by nothing. */
	if (!OPENGL_PROBE_OFF("opengl-list-count") && count > 0 && (zend_ulong) count > n) {
		zend_argument_value_error(count_arg, "must not pass the length of argument #%u ($%s)", list_arg, get_active_function_arg_name(list_arg)); /* binding:opengl-list-count */
		return false;
	}

	return true;
}
