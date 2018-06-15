#include <string.h>
#include <wlib/tlsf>
#include <wlib/mem/StaticPool.h>

using namespace wlp;

det::static_pool_base::static_pool_base(void *mem, size_t size) :
    m_handle(tlsf_create_with_pool(mem, size)) {}
det::static_pool_base::~static_pool_base()
{ tlsf_destroy(m_handle); }

void *det::static_pool_base::alloc(size_t bytes)
{ return tlsf_malloc(m_handle, bytes); }
void *det::static_pool_base::align(size_t align, size_t bytes)
{ return tlsf_memalign(m_handle, align, bytes) ;}
void *det::static_pool_base::realloc(void *ptr, size_t size)
{ return tlsf_realloc(m_handle, ptr, size); }
void det::static_pool_base::free(void *ptr)
{ tlsf_free(m_handle, ptr); }
void *det::static_pool_base::calloc(size_t bytes) {
    void *ptr = tlsf_malloc(m_handle, bytes);
    memset(ptr, 0, bytes);
    return ptr;
}
