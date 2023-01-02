#pragma once

#include "Servo.h"
#include "Arduino.h"

class ServoMotor : public Servo{
  int mode;
  int pin;
public:
  ServoMotor();
  ServoMotor(int, int);
  void start();
  void turn(int);
  void setMode(int);
  int getMode();
};
