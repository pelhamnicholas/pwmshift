#ifndef ARDUINODISPLAY_H
#define ARDUINODISPLAY_H

#include <Arduino.h>
#include "arduinooutput.h"

class ArduinoDisplay : public Display {
    private:
        bool resetclock();
        bool setBit(int &);

    public:
        void setOutput(const int &, const int &, const int &);
};

#endif
