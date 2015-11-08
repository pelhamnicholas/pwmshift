#ifndef DISPLAY_H
#define DISPLAY_H

#include "output.h"

class Display {
    private:
        int numLEDs;
        int * ledArray;
        int * ledPtr; // Find a better way to handle this
        unsigned char * outputByte;
        //unsigned char clock;
        unsigned char clock;
        
        bool resetClock();
        bool setBit(int &);

    protected:
        int pwmMax;
        unsigned long lastTime;
        Output * _output;

    public:
        Display(int, int);
        ~Display();
        virtual void setOutput(const int &, const int &, const int &) 
            = 0;
        void createOutputBytes();
        void updateLED(const int &, const int &);
        void updateLED(const int &, const int &, const int &, 
                const int &);
        void output();
};

#define addToByte(outputByte, clock, pwmVal) \
{ \
    asm volatile ("cp %0, %1" : : "r" (clock), "r" (pwmVal): ); \
    asm volatile ("ror %0" : "+r" (outputByte) : "r" (outputByte) : ); \
}


#endif
