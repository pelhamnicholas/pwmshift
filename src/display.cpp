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
void Display::update() {
    if (resetClock()) {
        for (int i = 0; i < numLEDs*3/8; ++i)
            outputByte[i] = 0;
    }
    for (int i = 0; i < numLEDs*3; ++i) {
        // set the bit in the byte
        if (setBit(ledArray[i]))
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
 * output: outputs stuff
 */
void Display::output() {
    for (int i = 0; i < numLEDs*3/8; ++i)
        _output->shiftOut(outputByte[i]);
}
