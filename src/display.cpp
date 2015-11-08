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
    resetClock();
    //clock++;
    for (int i = 0; i < numLEDs*3; ++i) {
        // set the bit in the byte
        if (setBit(ledArray[i]))
            outputByte[i/8] |= (1 << i);
        else
            outputByte[i/8] &= ~(1 << i);
    }
}

/*
 *
 */
void Display::updateLEDrgb(const int & LED, const int & r, 
        const int & g, const int & b) {
    ledArray[LED*3] = r;
    ledArray[LED*3+1] = g;
    ledArray[LED*3+2] = b;
}

void Display::updateALLrgb(const int & r, const int & g,
        const int & b) {
    for (int i = 0; i < numLEDs*3; ++i)
        updateLEDrgb(i, r, g, b);
}

void Display::updateLEDhsv(const int & LED, const int & h,
        const int & s, const int & v) {
    unsigned char r, g, b;
    unsigned int accent = h / 60;
    unsigned int top = v;
    unsigned int bottom = ((255 - s) * v) >> 8;
    unsigned char rising = ((top - bottom)
            * (h % 60)) / 60 + bottom;
    unsigned char falling = ((top - bottom)
            * (60 - h % 60)) / 60 + bottom;

    switch (accent) {
        case 0:
            r = top;
            g = rising;
            b = bottom;
            break;
        case 1:
            r = falling;
            g = top;
            b = bottom;
            break;
        case 2:
            r = bottom;
            g = top;
            b = rising;
            break;
        case 3:
            r = bottom;
            g = falling;
            b = top;
            break;
        case 4:
            r = rising;
            g = bottom;
            b = falling;
            break;
        case 5:
        default:
            r = top;
            g = bottom;
            b = falling;
    }
    updateLEDrgb(LED, r, g, b);
}

void Display::updateALLhsv(const int & h, const int & s,
        const int & v) {
    for (int i = 0; i < numLEDs*3; ++i)
        updateLEDhsv(i*3, h, s, v);
}

/*
 * output: outputs stuff
 */
void Display::output() {
    for (int i = 0; i < numLEDs*3/8; ++i)
        _output->myShiftOut(outputByte[i]);
    _output->toggleLatch();
}
