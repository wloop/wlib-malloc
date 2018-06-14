#include "internal.h"

#include <wlib/malloc>

using namespace wlp;

static constexpr size_t POOL_SIZE = 1 << 12;
static byte s_pool[POOL_SIZE];

int main(int argc, char *argv[]) {
    status stat = ok;

    if (!mem::init(s_pool, POOL_SIZE))
    { stat = error; }

    auto *data = reinterpret_cast<char *>(mem::alloc(128));
    if (nullptr == data)
    { stat = error; }
    mem::free(data);

    return stat;
}
