#include <string.h>
#include <wlib/tlsf>
#include <wlib/mem/Pool.h>

using namespace wlp;

memory_pool::memory_pool(void *mem, size_t size) :
    m_handle(tlsf_create_with_pool(mem, size)) {}
memory_pool::~memory_pool()
{ tlsf_destroy(m_handle); }

void *memory_pool::alloc(size_t bytes)
{ return tlsf_malloc(m_handle, bytes); }
void *memory_pool::align(size_t align, size_t bytes)
{ return tlsf_memalign(m_handle, align, bytes) ;}
void *memory_pool::realloc(void *ptr, size_t size)
{ return tlsf_realloc(m_handle, ptr, size); }
void memory_pool::free(void *ptr)
{ tlsf_free(m_handle, ptr); }
void *memory_pool::calloc(size_t bytes) {
    void *ptr = tlsf_malloc(m_handle, bytes);
    memset(ptr, 0, bytes);
    return ptr;
}
