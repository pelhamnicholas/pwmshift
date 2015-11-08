#include "display.h"

Display::Display(int numLEDs, int pwmMax) {
    this->numLEDs = numLEDs;
    this->pwmMax = pwmMax;
    //clock = 0;
    lastTime = 0;
    ledArray = new int[numLEDs*3];
    outputByte = new unsigned char[numLEDs*3/8];
}

Display::~Display() {
    delete ledArray;
    delete outputByte;
    delete _output;
}

bool Display::resetClock() {
    if (clock >= pwmMax) {
        clock = 0;
        return true;
    }
    return false;
}

bool Display::setBit(int & pwmVal) {
    if (++clock >= pwmVal) {
        return true;
    }
    return false;
}

/*
 * update: creates outputBytes to be shifted out
 *         This should probably be in output()
 *         update should probably update the ledArray
 */
void Display::createOutputBytes() {
    //clock = clock + numLEDs*3;
    if (resetClock()) {
        //for (int i = 0; i < numLEDs*3/8; ++i)
            //outputByte[i] = 255;
    }
    for (int i = 0; i < numLEDs*3; ++i) {
        // set the bit in the byte
        // The ! is used specifically for the hardware
        // Because I am using common cathode RGB LEDs
        if (setBit(ledArray[i]))
            outputByte[i/8] |= 1 << i;
        else
            outputByte[i/8] &= ~(1 << i);
        // with asm
        //addToByte(outputByte[i/8], clock, ledArray[i]);
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
    ledArray[LED*3] = r;
    ledArray[LED*3+1] = g;
    ledArray[LED*3+2] = b;
}

/*
 * output: outputs stuff
 */
void Display::output() {
    for (int i = 0; i < numLEDs*3/8; ++i)
        _output->myShiftOut(outputByte[i]);
    _output->toggleLatch();
}
