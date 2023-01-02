#include "LCD.h"

LCD::LCD(uint8_t a, uint8_t b, uint8_t c) : LiquidCrystal_I2C(a, b, c) {}

void LCD::printMsg(int line, const char *msg){
  this->clearLine(line);
  this->setCursor(0, line);
  this->print(msg);
}

void LCD::start(){
  this->init();
  this->backlight();
}

void LCD::clearLine(int line){
  for(int i = 0; i < 20; i++) {
    this->setCursor(i, line);
    this->print(" ");
  }
}
