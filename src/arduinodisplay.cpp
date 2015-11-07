#include "arduinodisplay.h"

/*
 * resetClock:
 */
bool ArduinoDisplay::resetClock() {
    unsigned long currentTime = millis();//clock();
    if (currentTime - lastTime >= pwmMax) {
        lastTime = currentTime;
        return true;
    }
    return false;
}

/*
 * setBit: returns true if timer is less than pwmVal
 */
bool ArduinoDisplay::setBit(int & pwmVal) {
    unsigned long currentTime = millis();//clock();
    if (currentTime - lastTime >= pwmMax) {
        return true;
    }
    return false;
}

void ArduinoDisplay::setOutput(const int & data, const int & clock,
        const int & latch) {
    _output = new ArduinoOutput(data, clock, latch);
}
