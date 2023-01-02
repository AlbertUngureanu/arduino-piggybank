#include "Led.h"

Led::Led(){
  this->pin = -1;
}

Led::Led(int pin){
  this->pin = pin;

  pinMode(pin, OUTPUT);
  analogWrite(pin, 0);
}

void Led::pulse(int S){
   for(int i = 0; i <= 255; i++){
    analogWrite(this->pin, i);
    delay(S);
  }

  for(int i = 255; i >= 0; i--){
    analogWrite(this->pin, i);
    delay(S);
  }
}

void Led::turnOn(){
  for(int i = 0; i <= 255; i++){
    analogWrite(this->pin, i);
    delay(1);
  }
}

void Led::turnOff(){
  for(int i = 255; i >= 0; i--){
    analogWrite(this->pin, i);
    delay(1);
  }
}
