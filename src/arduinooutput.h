#ifndef ARDUINOOUT_H
#define ARDUINOOUT_H

#include <Arduino.h>
#include "output.h"

class ArduinoOutput : public Output {
    private:

    public:
        ArduinoOutput(const int data, const int clock, const int latch)
            : Output(data, clock, latch) {};
        ~ArduinoOutput() {Output::~Output();};
        void shiftOut(const unsigned char &);
};

#endif
