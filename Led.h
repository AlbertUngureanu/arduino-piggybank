#pragma once

#include "Arduino.h"

class Led{
  int pin;

public:
  Led();
  Led(int);

  void pulse(int);
  void turnOn();
  void turnOff();
};
