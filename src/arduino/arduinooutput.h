#ifndef ARDUINOOUT_H
#define ARDUINOOUT_H

#include <Arduino.h>
#include "output.h"

class ArduinoOutput : public Output {
    private:

    public:
        ArduinoOutput(const int &, const int &, const int &);
        void myShiftOut(const unsigned char &);
        void toggleLatch();
};

#endif
