#include "Keyboard.h"

Keyboard::Keyboard(){
  for(int i = 0; i < 4; i++){
    this->rowPins[i] = this->colPins[i] = -1;
  }
}

Keyboard::Keyboard(byte start){
  byte k = start;
  for(int i = 0; i < 4; i++){
    this->rowPins[i] = k;
    k = k + 1;
  }  
  for(int i = 0; i < 4; i++){
    this->colPins[i] = k;
    k = k + 1;
  }

  this->keypad = Keypad(makeKeymap(keys), this->rowPins, this->colPins, ROWS, COLS);
}

byte* Keyboard::getRowPins(){
  return this->rowPins;
}

byte* Keyboard::getColPins(){
  return this->colPins;
}

char Keyboard::getKey(){
  char key = this->keypad.getKey();
  if(key)
    return key;
  else
    return '-';
}
