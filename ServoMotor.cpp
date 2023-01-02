#include "ServoMotor.h"

ServoMotor::ServoMotor(){
  this->mode = 0;
  this->pin = -1;
}

ServoMotor::ServoMotor(int mode, int pin){
  this->mode = mode;
  this->pin = pin;
}

void ServoMotor::start(){
  this->attach(this->pin);
  this->write(0);  
}

void ServoMotor::turn(int angle){
  int cAngle = this->read();
  if(cAngle > angle){
    for(int i = cAngle; i >= angle; i--){
      this->write(i);
      delay(5);
    }
  } else{
    for(int i = cAngle; i <= angle; i++){
      this->write(i);
      delay(5);
    }
  }
}

void ServoMotor::setMode(int mode){
  this->mode = mode;
}

int ServoMotor::getMode(){
  return this->mode;
}
