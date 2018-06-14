#ifndef __WLIB_MEMORY_MALLOC_H__
#define __WLIB_MEMORY_MALLOC_H__

#include <stddef.h>

namespace wlp {

    extern bool meminit(void *mem, size_t size);

    extern void *malloc(size_t bytes);
    extern void *memalign(size_t align, size_t bytes);
    extern void *realloc(void *ptr, size_t size);
    extern void free(void *ptr);

}

#endif
