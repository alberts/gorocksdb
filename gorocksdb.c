#include "gorocksdb.h"
#include "_cgo_export.h"

/* Base */

void gorocksdb_destruct_handler(void* handler) { }

/* Comparator */

rocksdb_comparator_t* gorocksdb_comparator_create(void* handler) {
    return rocksdb_comparator_create(
        handler,
        gorocksdb_destruct_handler,
        (int (*)(void*, const char*, size_t, const char*, size_t))(gorocksdb_comparator_compare),
        (const char *(*)(void*))(gorocksdb_comparator_name));
}

/* Filter Policy */

rocksdb_filterpolicy_t* gorocksdb_filterpolicy_create(void* handler) {
    return rocksdb_filterpolicy_create(
        handler,
        gorocksdb_destruct_handler,
        (char* (*)(void*, const char* const*, const size_t*, int, size_t*))(gorocksdb_filterpolicy_create_filter),
        (unsigned char (*)(void*, const char*, size_t, const char*, size_t))(gorocksdb_filterpolicy_key_may_match),
        (const char *(*)(void*))(gorocksdb_filterpolicy_name));
}

/* Merge Operator */

rocksdb_mergeoperator_t* gorocksdb_mergeoperator_create(void* handler) {
    return rocksdb_mergeoperator_create(
        handler,
        gorocksdb_destruct_handler,
        (char* (*)(void*, const char*, size_t, const char*, size_t, const char* const*, const size_t*, int, unsigned char*, size_t*))(gorocksdb_mergeoperator_full_merge),
        (char* (*)(void*, const char*, size_t, const char*, size_t, const char*, size_t, unsigned char*, size_t*))(gorocksdb_mergeoperator_partial_merge),
        (const char* (*)(void*))(gorocksdb_mergeoperator_name));
}

/* Slice Transform */

rocksdb_slicetransform_t* gorocksdb_slicetransform_create(void* handler) {
    return rocksdb_slicetransform_create(
    	handler,
    	gorocksdb_destruct_handler,
    	(char* (*)(void*, const char*, size_t, size_t*))(gorocksdb_slicetransform_transform),
    	(unsigned char (*)(void*, const char*, size_t))(gorocksdb_slicetransform_in_domain),
    	(unsigned char (*)(void*, const char*, size_t))(gorocksdb_slicetransform_in_range),
    	(const char* (*)(void*))(gorocksdb_slicetransform_name));
}

/* Hacks */

char* gorocksdb_get_char_at_index(char **list, int idx) {
	return list[idx];
}

size_t gorocksdb_get_int_at_index(size_t *list, int idx) {
    return list[idx];
}