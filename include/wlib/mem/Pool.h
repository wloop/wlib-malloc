#ifndef __WLIB_MALLOC_POOL_H__
#define __WLIB_MALLOC_POOL_H__

#include <stdint.h>
#include <wlib/mem/Byte.h>

namespace wlp {

    class memory_pool {
        void *const m_handle;
    public:
        explicit memory_pool(void *mem, size_t size);
        ~memory_pool();
        void *alloc(size_t bytes);
        void *align(size_t align, size_t bytes);
        void *calloc(size_t bytes);
        void *realloc(void *ptr, size_t size);
        void free(void *ptr);

        memory_pool(memory_pool const &) = delete;
        memory_pool(memory_pool &&) = delete;
        memory_pool &operator=(memory_pool const &) = delete;
        memory_pool &operator=(memory_pool &&) = delete;
    };

    template<size_t sz>
    class static_pool : public memory_pool {
        byte pool[sz];
    public:
        static_pool() : memory_pool(pool, sz) {}
    };

}

#endif
