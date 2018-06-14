# wlib-malloc

`malloc` and `free` replacements for WLib using `wlib-tlsf`.

### Install

```bash
wio pac add wlib-malloc
```

### Usage

`mem::meminit` must be called at program start with a user-provided memory pool
for the global allocator instance to manage.

```c++
static byte s_pool[POOL_SIZE];

using namespace wlp;

int main(int argc, char *argv[]) {
    mem::init(s_pool, POOL_SIZE);
    
    char *ptr = static_cast<char *>(mem::alloc(128));
    // ...
    mem::free(ptr);
}

```
