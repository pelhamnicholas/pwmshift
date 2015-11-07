#include "arduinooutput.h"

void ArduinoOutput::shiftOut(const unsigned char & dataByte) {
    shiftOut(data, clock, LSBFIRST, dataByte);
}
