#ifndef DISPLAY_H
#define DISPLAY_H

#include "output.h"

class Display {
    private:
        int numLEDs;
        int * ledArray;
        int * ledPtr; // Find a better way to handle this
        unsigned char * outputByte;

        virtual bool resetClock() = 0;
        virtual bool setBit(int &) = 0;

    protected:
        int pwmMax;
        unsigned long lastTime;
        Output * _output;

    public:
        Display(int, int);
        ~Display();
        virtual void setOutput(const int &, const int &, const int &) 
            = 0;
        void update();
        void updateLED(const int &, const int &);
        void output();
};

#endif
