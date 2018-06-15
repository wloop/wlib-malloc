#include <string.h>
#include <wlib/tlsf>
#include <wlib/mem/Malloc.h>

static tlsf_t s_tlsf = nullptr;

bool wlp::mem::init(void *mem, size_t size) {
    if (s_tlsf) { return true; }
    s_tlsf = tlsf_create_with_pool(mem, size);
    return s_tlsf != nullptr;
}

void *wlp::mem::alloc(size_t bytes) {
    return tlsf_malloc(s_tlsf, bytes);
}

void *wlp::mem::align(size_t align, size_t bytes) {
    return tlsf_memalign(s_tlsf, align, bytes);
}

void *wlp::mem::calloc(size_t bytes) {
    void *ptr = wlp::mem::alloc(bytes);
    memset(ptr, 0, bytes);
    return ptr;
}

void *wlp::mem::realloc(void *ptr, size_t size) {
    return tlsf_realloc(s_tlsf, ptr, size);
}

void wlp::mem::free(void *ptr) {
    return tlsf_free(s_tlsf, ptr);
}

bool wlp::mem::deinit() {
    tlsf_destroy(s_tlsf);
    s_tlsf = nullptr;
    return true;
}
