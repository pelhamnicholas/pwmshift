#include "arduinodisplay.h"

ArduinoDisplay::ArduinoDisplay(int numLEDs, int pwmMax)
    : Display(numLEDs, pwmMax) {
}

ArduinoDisplay::~ArduinoDisplay() {}

/*
bool ArduinoDisplay::resetClock() {
    unsigned long currentTime = millis();
    if (currentTime - lastTime >= pwmMax) {
        lastTime = currentTime;
        return true;
    }
    return false;
}

bool ArduinoDisplay::setBit(int & pwmVal) {
    if (millis() - lastTime  >= pwmVal) {
        return true;
    }
    return false;
}
*/

bool ArduinoDisplay::resetClock() {
    if (clock >= pwmMax) {
        clock = 0;
        return true;
    }
    return false;
}

bool ArduinoDisplay::setBit(int & pwmVal) {
    if (++clock >= pwmVal) {
        return true;
    }
    return false;
}

void ArduinoDisplay::setOutput(const int & data, const int & clock,
        const int & latch) {
    _output = new ArduinoOutput(data, clock, latch);
}
