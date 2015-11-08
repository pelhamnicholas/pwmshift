#ifndef DISPLAY_H
#define DISPLAY_H

#include "output.h"

class Display {
    private:
        int numLEDs;
        int * ledArray;
        unsigned char * outputByte;
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
        void updateLEDrgb(const int &, const int &, const int &, 
                const int &);
        void updateALLrgb(const int &, const int &, const int &);
        void updateLEDhsv(const int &, const int &, const int &,
                const int &);
        void updateALLhsv(const int &, const int &, const int &);
        void output();
};

#endif
