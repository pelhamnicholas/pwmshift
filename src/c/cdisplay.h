#ifndef CDISPLAY_H
#define CDISPLAY_H

#include "display.h"
#include "coutput.h"
#include <time.h>

class CDisplay : public Display {
    private:
        bool resetClock();
        bool setBit(int &);
        int clock;

    public:
        CDisplay(int, int);
        ~CDisplay();
        void setOutput(const int &, const int &, const int &);
};

#endif
