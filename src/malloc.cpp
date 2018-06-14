#include <wlib/tlsf>
#include <wlib/memory>

#include "config.h"

static byte s_pool[POOL_SIZE];
static tlsf_t s_tlsf = nullptr;

using namespace wlp;

bool meminit() {
    if (s_tlsf) { return true; }
    s_tlsf = tlsf_create_with_pool(s_pool, POOL_SIZE);
    return s_tlsf != nullptr;
}

void *malloc(size_t bytes) {
    return tlsf_malloc(s_tlsf, bytes);
}

void *memalign(size_t align, size_t bytes) {
    return tlsf_memalign(s_tlsf, align, bytes);
}

void *realloc(void *ptr, size_t size) {
    return tlsf_realloc(s_tlsf, ptr, size);
}

void free(void *ptr) {
    return tlsf_free(s_tlsf, ptr);
}
