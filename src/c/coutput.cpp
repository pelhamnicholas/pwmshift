#include "coutput.h"
#include <iostream>

void COutput::myShiftOut(const unsigned char & dataByte) {
    std::cout << (int)dataByte << std::endl;
}
