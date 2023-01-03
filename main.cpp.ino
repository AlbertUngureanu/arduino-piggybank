#include "Keyboard.h"
#include "Led.h"
#include "ServoMotor.h"
#include "utils.h"
#include "LCD.h"



Keyboard K(6); // pini 6 -> 13
Led R(5); //red led - pin 5
Led G(3); //green led - pin 3
Led T(2); //led pentru fotorezistor - pin 2
ServoMotor S(0, A0); // servomotor pin A0;
LCD L(0x3F,16,2);

char PIN[5] = "1234";
float Money = 0;
int k, value;
char Goal[5] = "100";
bool Lchange = true;
char MS[16], MG[5];
char opt;

void setup() {
  Serial.begin(9600);

  S.start();
  L.start();
}

void loop() {
  switch(K.getKey()){
    case '-':
      L.clearLine(1);
      dtostrf(Money, 4, 2, MS);
      //ftoa(Money, MS, 10);
      strcat(MS, " / ");
      strcat(MS, Goal);
      strcat(MS, " lei.");
      if(Lchange){
        L.printMsg(0, MS);
        Lchange = false;
      }
      break;
    case '*': //Adaugare/Schimbare PIN:
      if(strcmp(PIN, "1234") == 0){ //daca e cel default, putem schimba direct;
        L.printMsg(0, "Introduceti un");
        L.printMsg(1, "pin nou.");
        R.turnOn();
        delay(2000);
        L.clearLine(0);
        L.clearLine(1);
        Lchange = true;
        strcpy(PIN, readPass(K, L));
        R.turnOff();
      } else{ //daca pin-ul a fost schimbat deja, va trebui prima data sa introducem pin-ul curent;
          L.printMsg(0, "Introduceti");
          L.printMsg(1, "pin-ul curent.");
          Lchange = true;
          R.turnOn();
          delay(2000);
          L.clearLine(0);
          L.clearLine(1);
          if(strcmp(PIN, readPass(K, L)) == 0){
            L.printMsg(0, "Introduceti");
            L.printMsg(1, "un pin nou.");
            Lchange = true;
            R.turnOff();
            G.turnOn();
            delay(2000);
            L.clearLine(0);
            L.clearLine(1);
            strcpy(PIN, readPass(K, L));
            G.turnOff();
          }else{
            L.printMsg(0, "Pin gresit.");
            Lchange = true; 
            R.turnOff();
           }
        }
      break;
    case '#': //Verificare PIN / Inchidere capac;
      if(S.getMode() == 0){
        L.printMsg(0, "Introdu pin-ul.");
        Lchange = true;
        R.turnOn();
        if(strcmp(PIN, readPass(K, L)) == 0){
          L.printMsg(1, "Se deschide...");
          R.turnOff();
          G.pulse(5);
          S.turn(180);
          S.setMode(1);

          //Scoatere bani
          L.printMsg(0, "Introdu suma:");
          L.printMsg(1, "**.** lei");
          k = 0;
          while(k < 2){
            MG[k] = K.getKey();
            if(MG[k] != '-'){
              L.setCursor(k, 1);
              L.print(MG[k]);
              k++;
            }
          }
          MG[k] = '.';
          k++;
          while(k < 5){
            MG[k] = K.getKey();
            if(MG[k] != '-'){
              L.setCursor(k, 1);
              L.print(MG[k]);
              k++;
            }
          }
          Money -= atof(MG);
        }
        else{
          L.printMsg(1, "Pin gresit");
          R.turnOff();
          R.pulse(5);
        }
      } else{
        L.printMsg(1, "Se inchide...");
        R.pulse(5);
        S.turn(0);
        S.setMode(0);
      }
      break;
   case 'A':  //Adaugare bani
      R.turnOn();
      L.printMsg(0, "1. 50 bani");
      L.printMsg(1, "2. 10 bani");
      opt = '-';
      while(opt == '-'){
        opt = K.getKey();
      }
      switch(opt){
        case '1':
          L.printMsg(0, "Introdu de 50");
          L.printMsg(1, "D - final");
          T.turnOn();
          while(K.getKey() != 'D'){
              value = map(analogRead(A1), 1, 20, 1, 10);
              if(value <= 5){ //daca se introduce un banut
                  Money += 0.50;
                  G.pulse(2);
              }
          }
          T.turnOff();
          break;
        case '2':
          L.printMsg(0, "Introdu de 10");
          L.printMsg(1, "D - final");
          T.turnOn();
          while(K.getKey() != 'D'){
              value = map(analogRead(A1), 1, 20, 1, 10);
              if(value <= 5){ //daca se introduce un banut
                  Money += 0.10;
                  G.pulse(2);
              }
          }
          T.turnOff();
          break;
        default:
          break;
      }
      Lchange = true;
      R.turnOff();
      break;
  }
}
