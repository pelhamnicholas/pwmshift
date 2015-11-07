#include "output.h"

Output::Output(const int & data, const int & clock, 
        const int & latch) {
    dataPin = data;
    clockPin = clock;
    latchPin = latch;
}

Output::~Output() {
}
