#ifndef COUTPUT_H
#define COUTPUT_H

#include "output.h"

class COutput : public Output {
    private:

    public:
        COutput(const int & data, const int & clock, const int & latch)
            : Output(data, clock, latch) {};
        void myShiftOut(const unsigned char &);
};

#endif
