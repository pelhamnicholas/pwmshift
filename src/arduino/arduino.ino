#include "arduinodisplay.h"

ArduinoDisplay arduinodisplay(3,255);

//unsigned char dataByte;

void setup() {
  ArduinoDisplay arduinodisplay(3,255);
  arduinodisplay.setOutput(11,13,8);
  
  for (int i = 0; i < 3*3; ++i)
    arduinodisplay.updateLED(i, 255);
  //dataByte = 255;
}

void loop() {
  for (int i = 0; i < 3; ++i) {
    arduinodisplay.updateLED(i*3, 255, 0, 0);
  }
  arduinodisplay.createOutputBytes();
  arduinodisplay.output();
  //delay(1000);
  
  for (int i = 0; i < 3; ++i) {
    arduinodisplay.updateLED(i*3, 0, 255, 0);
  }
  arduinodisplay.createOutputBytes();
  arduinodisplay.output();
  //delay(1000);
  
  for (int i = 0; i < 3; ++i) {
    arduinodisplay.updateLED(i*3, 0, 0, 255);
  }
  arduinodisplay.createOutputBytes();
  arduinodisplay.output();
  //delay(1000);
}
