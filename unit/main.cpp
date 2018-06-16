#include "internal.h"

#include <stdio.h>
#include <wlib/malloc>
#include <wlib/byte>
#include <wlib/pool>

using namespace wlp;

static constexpr size_t POOL_SIZE = 1 << 12;
static byte s_pool[POOL_SIZE];
static static_pool<1024> s_static_pool;

int main(int argc, char *argv[]) {
    printf("Testing... ");
    status stat = ok;

    if (!mem::init(s_pool, POOL_SIZE))
    { stat = error; }

    auto *data = reinterpret_cast<char *>(mem::alloc(128));
    if (nullptr == data)
    { stat = error; }
    mem::free(data);

    auto *ptr = s_static_pool.calloc(64);
    if (nullptr == ptr)
    { stat = error; }
    s_static_pool.free(ptr);

    printf("done - %s\n", stat ? "ERROR" : "OK");
    return stat;
}
