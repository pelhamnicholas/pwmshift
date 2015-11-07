#ifndef CDISPLAY_H
#define CDISPLAY_H

#include "display.h"
#include "coutput.h"

class CDisplay : public Display {
    private:
        bool resetClock();
        bool setBit(int &);

    public:
        CDisplay(int, int);
        ~CDisplay();
        void setOutput(const int &, const int &, const int &);
};

#endif
