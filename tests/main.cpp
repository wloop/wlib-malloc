#include <Cosa/UART.hh>

#include <stdio.h>
#include <stdarg.h>

#include <wlib/malloc>

enum { POOL_SIZE = 1024 };

static char pool[POOL_SIZE];
static char buffer[64];
static char *memory;
static int wrt;
static int count;

void tlsf_printf(const char *str, ...) {
    va_list args;
    va_start(args, str);
    int num = vsprintf(buffer, str, args);
    if (num >= 0) { uart.write(buffer, num); }
    va_end(args);
}

void tlsf_assert(bool expr, const char *msg) {
    if (expr) { uart.write(msg, strlen(msg)); }
}

void setup() {
    wlp::mem::init(pool, POOL_SIZE);

    uart.begin(9600);
    wrt = sprintf(buffer, "%s\n", "Hello");
    uart.write(buffer, wrt);
}

void loop() {
    wrt = snprintf(nullptr, 0, "Counter: %i\n", count);
    memory = static_cast<char *>(wlp::mem::alloc(wrt + 1));
    sprintf(memory, "Counter: %i\n", count);
    uart.write(memory, wrt);
    wlp::mem::free(memory);
    delay(1000);
    count += 16;
}
