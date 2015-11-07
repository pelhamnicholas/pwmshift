#include "arduinooutput.h"

ArduinoOutput::ArduinoOutput(const int & data, const int & clock,
        const int & latch) : Output(data, clock, latch) {
}

void ArduinoOutput::myShiftOut(const unsigned char & dataByte) {
    shiftOut(dataPin, clockPin, MSBFIRST, dataByte);
}

void ArduinoOutput::toggleLatch() {
    digitalWrite(latchPin, HIGH);
    digitalWrite(latchPin, LOW);
}
