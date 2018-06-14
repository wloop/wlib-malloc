#ifndef __WLIB_MEMORY_CONFIG_H__
#define __WLIB_MEMORY_CONFIG_H__

#if !defined(WLIB_MEMORY_SIZE)
#error "WLIB_MEMORY_SIZE must be defined"
#else
#define POOL_SIZE WLIB_MEMORY_SIZE
#endif

typedef unsigned char byte;

#endif
