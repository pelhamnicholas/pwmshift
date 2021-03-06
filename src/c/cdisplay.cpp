#include "cdisplay.h"

CDisplay::CDisplay(int numLEDs, int pwmMax) 
    : Display(numLEDs, pwmMax) {
        clock = 0;
}

CDisplay::~CDisplay() {}

/*
bool CDisplay::resetClock() {
    unsigned long currentTime = clock();
    if (currentTime - lastTime >= pwmMax) {
        lastTime = currentTime;
        return true;
    }
    return false;
}

bool CDisplay::setBit(int & pwmVal) {
    unsigned long currentTime = clock();
    if (currentTime - lastTime >= pwmVal) {
        return true;
    }
    return false;
}
*/

bool CDisplay::resetClock() {
    if (++clock >= pwmMax) {
        clock = 0;
        return true;
    }
    return false;
}

bool CDisplay::setBit(int & pwmVal) {
    if (clock >= pwmVal) {
        return true;
    }
    return false;
}

void CDisplay::setOutput(const int & data, const int & clock, 
        const int & latch) {
    _output = new COutput(data, clock, latch);
}
