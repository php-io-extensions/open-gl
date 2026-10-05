#include "runtime.h"

static zend_object_handlers opengl_handle_handlers;

static zend_object *opengl_create_object(zend_class_entry *ce)
{
	opengl_handle *intern = zend_object_alloc(sizeof(opengl_handle), ce);

	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);
	intern->std.handlers = &opengl_handle_handlers;
	intern->ptr = NULL;
	ZVAL_UNDEF(&intern->keep);

	return &intern->std;
}

static void opengl_free_object(zend_object *object)
{
	opengl_handle *intern = opengl_handle_from(object);

	if (intern->ptr != NULL) {
		zend_hash_index_del(&OPENGL_G(boxes), (zend_ulong) (uintptr_t) intern->ptr);
		intern->ptr = NULL;
	}

	zval_ptr_dtor(&intern->keep);
	ZVAL_UNDEF(&intern->keep);
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

static void opengl_release_kept(opengl_handle *intern)
{
	if (Z_TYPE(intern->keep) == IS_ARRAY) {
		zval *zv;

		ZEND_HASH_FOREACH_VAL(Z_ARRVAL(intern->keep), zv) {
			if (Z_TYPE_P(zv) == IS_OBJECT && Z_OBJ_P(zv)->handlers == &opengl_handle_handlers) {
				opengl_release(Z_OBJ_P(zv));
			}
		} ZEND_HASH_FOREACH_END();
	} else if (Z_TYPE(intern->keep) == IS_OBJECT && Z_OBJ(intern->keep)->handlers == &opengl_handle_handlers) {
		opengl_release(Z_OBJ(intern->keep));
	}
}

void opengl_release(zend_object *obj)
{
	opengl_handle *intern = opengl_handle_from(obj);

	if (intern->ptr != NULL) {
		zend_hash_index_del(&OPENGL_G(boxes), (zend_ulong) (uintptr_t) intern->ptr);
		intern->ptr = NULL;
	}

	opengl_release_kept(intern);
	zval_ptr_dtor(&intern->keep);
	ZVAL_UNDEF(&intern->keep);
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

void *opengl_handle_ptr(zval *zv, zend_class_entry *ce, uint32_t arg_num)
{
	opengl_handle *intern;

	if (Z_TYPE_P(zv) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(zv), ce)) {
		if (arg_num == 0) {
			zend_type_error("must be an instance of %s", ZSTR_VAL(ce->name));
		} else {
			zend_argument_type_error(arg_num, "must be of type %s", ZSTR_VAL(ce->name));
		}
		return NULL;
	}

	intern = opengl_handle_from(Z_OBJ_P(zv));
	if (intern->ptr == NULL) {
		if (arg_num == 0) {
			zend_value_error("%s has been destroyed", ZSTR_VAL(ce->name));
		} else {
			zend_argument_value_error(arg_num, "%s has been destroyed", ZSTR_VAL(ce->name));
		}
		return NULL;
	}

	return intern->ptr;
}

bool opengl_assign_handle(zval *dest, void *ptr, zend_class_entry *ce)
{
	zval obj;

	opengl_box(&obj, ptr, ce);
	ZEND_TRY_ASSIGN_REF_TMP(dest, &obj);

	return EG(exception) == NULL;
}

int *opengl_attrib_list(HashTable *list, int terminator, uint32_t arg_num, bool *failed)
{
	uint32_t n, i = 0;
	int *out;
	zval *zv;

	*failed = false;
	if (list == NULL) {
		return NULL;
	}

	n = zend_hash_num_elements(list);
	if (n == 0) {
		zend_argument_value_error(arg_num, "must end with %d", terminator);
		*failed = true;
		return NULL;
	}

	out = emalloc(sizeof(int) * n);
	ZEND_HASH_FOREACH_VAL(list, zv) {
		if (Z_TYPE_P(zv) != IS_LONG || Z_LVAL_P(zv) > INT_MAX || Z_LVAL_P(zv) < INT_MIN) {
			efree(out);
			if (Z_TYPE_P(zv) != IS_LONG) {
				zend_argument_type_error(arg_num, "must be a list of ints");
			} else {
				zend_argument_value_error(arg_num, "must fit in a 32-bit int");
			}
			*failed = true;
			return NULL;
		}
		out[i++] = (int) Z_LVAL_P(zv);
	} ZEND_HASH_FOREACH_END();

	if (out[n - 1] != terminator) {
		efree(out);
		zend_argument_value_error(arg_num, "must end with %d", terminator);
		*failed = true;
		return NULL;
	}

	return out;
}
