#include <wlib/malloc>
#include <stdio.h>

enum { POOL_SIZE = 16400 };
static char memory[POOL_SIZE];

using namespace wlp;

int main(void) {
    if (!mem::init(memory, POOL_SIZE)) {
        printf("Memory init failed\n");
        return -1;
    }

    char *pStr = static_cast<char *>(mem::alloc(1024));
    if (nullptr == pStr) {
        printf("Memory alloc failed\n");
        return -1;
    }
    mem::free(pStr);

    printf("Test complete\n");
}
