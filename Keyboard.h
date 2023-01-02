#pragma once

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

const char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

class Keyboard{
  byte rowPins[ROWS];
  byte colPins[COLS];

  Keypad keypad = Keypad(0, 0, 0, 0, 0);

public:
  Keyboard();
  Keyboard(byte);
  byte* getRowPins();
  byte* getColPins();
  char getKey();
};
