#include "arduinodisplay.h"

int numLEDs = 3;
int delayVal = 100;

ArduinoDisplay arduinodisplay(numLEDs,255);

//unsigned char dataByte;

void setup() {
//  ArduinoDisplay arduinodisplay(3,255);
  arduinodisplay.setOutput(11,13,8);
}

void loop() {
  /*
  for (int i = 0; i < 2048; ++i) {
    arduinodisplay.updateLEDrgb(0, 16, 4, 64);
    arduinodisplay.updateLEDrgb(1, 64, 16, 4);
    arduinodisplay.updateLEDrgb(2, 4, 64, 16);
    arduinodisplay.createOutputBytes();
    arduinodisplay.output();
  }
  for (int i = 0; i < 2048; ++i) {
    arduinodisplay.updateLEDrgb(0, 64, 16, 4);
    arduinodisplay.updateLEDrgb(1, 4, 64, 16);
    arduinodisplay.updateLEDrgb(2, 16, 4, 64);
    arduinodisplay.createOutputBytes();
    arduinodisplay.output();
  }
  for (int i = 0; i < 2048; ++i) {
    arduinodisplay.updateLEDrgb(0, 4, 64, 16);
    arduinodisplay.updateLEDrgb(1, 16, 4, 64);
    arduinodisplay.updateLEDrgb(2, 64, 16, 4);
    arduinodisplay.createOutputBytes();
    arduinodisplay.output();
  }
  */
  /*
  for (int i = 0, i < 255; ++i) {
    arduinodisplay.updateLEDrgb(0, 0, 4, 0);
    arduinodisplay.updateLEDrgb(1, 0, 16, 0);
    arduinodisplay.updateLEDrgb(2, 0, 64, 0);
    arduinodisplay.createOutputBytes();
    arduinodisplay.output();
  }
  */
  //arduinodisplay.updateLEDrgb(3, 255, 0, 0);
  //arduinodisplay.updateLEDrgb(4, 0, 0, 0);
  //arduinodisplay.updateLEDrgb(5, 255, 0, 0);
  //arduinodisplay.updateLEDrgb(6, 0, 0, 0);
  //arduinodisplay.updateLEDrgb(7, 0, 0, 0);
  
  //arduinodisplay.updateLEDhsv(0, 0, 255, 128);
  //arduinodisplay.updateLEDhsv(1, 0, 255, 32);
  //arduinodisplay.updateLEDhsv(2, 0, 255, 8);
  //arduinodisplay.updateLEDhsv(3, 0, 255, 128);
  //arduinodisplay.updateLEDhsv(4, 0, 255, 32);
  //arduinodisplay.updateLEDhsv(5, 0, 255, 8);
  
  //arduinodisplay.updateALLrgb(0, 0, 0);
  
  //for (int i = 0; i < 255; ++i) {
  //  arduinodisplay.updateLEDrgb(0, i, 0, 0);
  //  arduinodisplay.createOutputBytes();
    //arduinodisplay.output();
    //delay(delayVal);
  //}
  
  /*
  for (int i = 0; i < numLEDs; ++i) {
    for (int j = 0; j < 255; ++i) {
      arduinodisplay.updateLEDrgb(i, j, 0, 0);
      arduinodisplay.createOutputBytes();
      arduinodisplay.output();
      delay(delayVal);
    }
    for (int j = 0; j < 255; ++i) {
      arduinodisplay.updateLEDrgb(i, 255-j, 0, 0);
      arduinodisplay.createOutputBytes();
      arduinodisplay.output();
      delay(delayVal);
    }
  }
  */
  //arduinodisplay.createOutputBytes();
  //arduinodisplay.output();
  
  // hue shift
  //for (int hue = 0; hue < 32; hue = hue + 3) {
  //  arduinodisplay.updateLEDrgb(0, hue, 0, 0);
  //  arduinodisplay.updateLEDrgb(1, hue + 1, 0, 0);
  //  arduinodisplay.updateLEDrgb(2, hue + 2, 0, 0);
  //  arduinodisplay.createOutputBytes();
  //  arduinodisplay.output();
  //}
  
  
  // rainbow stuff
  for (int colorShift = 0; colorShift < 360; ++colorShift) {
    for (int led = 0; led < numLEDs; ++led) {
      int hue = ((led)*360/(numLEDs*4)+colorShift)%255;
      arduinodisplay.updateLEDhsv(led, hue, 255, 255);
      //arduinodisplay.createOutputBytes();
      //arduinodisplay.output();
    }
    for (int i = 0; i < 64; ++i) {
      arduinodisplay.createOutputBytes();
      arduinodisplay.output();
    }
    //delay(delayVal);
  }
  
}
