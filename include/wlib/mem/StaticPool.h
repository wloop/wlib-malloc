#ifndef __WLIB_MALLOC_STATICPOOL_H__
#define __WLIB_MALLOC_STATICPOOL_H__

#include <stdint.h>
#include <wlib/mem/Byte.h>

namespace wlp {

    namespace det {
        class static_pool_base {
            void *const m_handle;
        public:
            explicit static_pool_base(void *mem, size_t size);
            ~static_pool_base();
            void *alloc(size_t bytes);
            void *align(size_t align, size_t bytes);
            void *calloc(size_t bytes);
            void *realloc(void *ptr, size_t size);
            void free(void *ptr);

            static_pool_base(static_pool_base const &) = delete;
            static_pool_base(static_pool_base &&) = delete;
            static_pool_base &operator=(static_pool_base const &) = delete;
            static_pool_base &operator=(static_pool_base &&) = delete;
        };
    }

    template<size_t sz>
    class static_pool : public det::static_pool_base {
        byte pool[sz];
    public:
        static_pool() : static_pool_base(pool, sz) {}
    };

}

#endif
