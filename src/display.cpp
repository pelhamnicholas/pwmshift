#include "display.h"

Display::Display(int numLEDs, int pwmMax) {
    this->numLEDs = numLEDs;
    this->pwmMax = pwmMax;
    lastTime = 0;
    ledArray = new int[numLEDs*3];
    outputByte = new unsigned char[numLEDs*3/8];
}

Display::~Display() {
    delete ledArray;
    delete outputByte;
    delete _output;
}

/*
 * update: creates outputBytes to be shifted out
 *         This should probably be in output()
 *         update should probably update the ledArray
 */
void Display::createOutputBytes() {
    if (resetClock()) {
        for (int i = 0; i < numLEDs*3/8; ++i)
            outputByte[i] = 0;
    }
    for (int i = 0; i < numLEDs*3; ++i) {
        // set the bit in the byte
        // The ! is used specifically for the hardware
        // Because I am using common cathode RGB LEDs
        if (!setBit(ledArray[i]))
            outputByte[i/8] |= 1 << i;
        else
            outputByte[i/8] &= ~(1 << i);
    }
}

/*
   */
void Display::updateLED(const int & LED, const int & pwmVal) {
    ledArray[LED] = pwmVal;
}

/*
 *
 */
void Display::updateLED(const int & LED, const int & r, 
        const int & g, const int & b) {
    ledArray[LED] = r;
    ledArray[LED+1] = g;
    ledArray[LED+2] = b;
}

/*
 * output: outputs stuff
 */
void Display::output() {
    for (int i = 0; i < numLEDs*3/8; ++i)
        _output->myShiftOut(outputByte[i]);
    _output->toggleLatch();
}
