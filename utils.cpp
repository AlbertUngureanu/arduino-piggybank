#include "utils.h"

char *readPass(Keyboard KeyB, LCD L){
  char *pass = new char[5];
  char key = '-';
  int nr = 0;
  while(nr < 4){
    key = KeyB.getKey();
    L.setCursor(nr,1);
    if(key != '-'){
      pass[nr] = key;
      L.setCursor(nr,1);
      L.print("*");
      nr++;
    }
  }
  pass[nr] = '\0';
  Serial.println();
  return pass;
}
