#include <Cosa/Trace.hh>
#include <Cosa/UART.hh>

void setup() {
    uart.begin(19200);
    trace.begin(&uart);

    trace << "PROGRAM START" << endl;
}

void loop() {
    delay(200);
    trace << "Beep" << endl;
}

