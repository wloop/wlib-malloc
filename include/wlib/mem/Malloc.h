#ifndef __WLIB_MALLOC_MALLOC_H__
#define __WLIB_MALLOC_MALLOC_H__

#include <stdint.h>

namespace wlp {
    namespace mem {
        extern bool init(void *mem, size_t size);
        extern void *alloc(size_t bytes);
        extern void *align(size_t align, size_t bytes);
        extern void *calloc(size_t bytes);
        extern void *realloc(void *ptr, size_t size);
        extern void free(void *ptr);
        extern bool deinit();
    }
}

#endif
