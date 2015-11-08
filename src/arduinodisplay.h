#ifndef ARDUINODISPLAY_H
#define ARDUINODISPLAY_H

#include <Arduino.h>
#include "arduinooutput.h"
#include "display.h"

class ArduinoDisplay : public Display {
    private:

    public:
        ArduinoDisplay(int, int);
        ~ArduinoDisplay();
        void setOutput(const int &, const int &, const int &);
};

#endif
