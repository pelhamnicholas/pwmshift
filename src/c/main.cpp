#include "cdisplay.h"

int main() {
    CDisplay cdisplay(8, 255);
    cdisplay.setOutput(1, 1, 1);

    for (int i = 0; i < 8*3; ++i) {
        cdisplay.updateLED(i, i*255/(8*3));
    }

    while (1) {
        cdisplay.update();
        cdisplay.output();
    }

    return 1;
}
