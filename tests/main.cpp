#include <Cosa/UART.hh>

#include <stdio.h>
#include <stdarg.h>

static char buffer[64];
static int wrt;

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
    uart.begin(9600);
    wrt = sprintf(buffer, "%s\n", "Hello");
    uart.write(buffer, wrt);
}

void loop() {
    delay(500);
    wrt = sprintf(buffer, "%s\n", "Beep");
    uart.write(buffer, wrt);
}
