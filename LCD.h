#pragma once

#include "Arduino.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

class LCD : public LiquidCrystal_I2C{
public:
  LCD(uint8_t, uint8_t, uint8_t);
  void printMsg(int, const char*);
  void start();
  void clearLine(int);
};
