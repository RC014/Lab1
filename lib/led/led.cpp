#include "led.h"
#include <Arduino.h>
void myLedSetup(int pin){
pinMode(pin, OUTPUT); // setam pinul ca iesire
digitalWrite(pin, LOW); // stingem ledul initial
}
void ledOn(int pin) {
digitalWrite(pin, HIGH); // aprindem ledul
}
void ledOff(int pin) {
digitalWrite(pin, LOW); // stingem ledul
}
void ledToggle(int pin){
digitalWrite(pin, !digitalRead(pin)); // inversam starea ledului
}