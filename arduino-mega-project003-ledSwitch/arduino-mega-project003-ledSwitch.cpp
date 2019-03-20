#include <Arduino.h>

int switchPin=4;
int ledPin=2;
boolean lastButton=false;
boolean currentButton=false;
boolean LenON=false;

// on-off led with the switch
void setup() {

  pinMode(ledPin,OUTPUT);
  pinMode(switchPin,INPUT);

}

boolean checkFlag(boolean last){
  boolean current=digitalRead(switchPin);
  if(last != current){
    delay(5);
    current=digitalRead(switchPin);
    }
    return current;
}

void loop() {

  currentButton=checkFlag(lastButton);
  if(currentButton==HIGH && lastButton==LOW){
  LenON = !LenON;
  }
  lastButton=currentButton;
  digitalWrite(ledPin,LenON);
}
