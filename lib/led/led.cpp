#include "led.h"
#include <Arduino.h>
void myLedSetup(int pin){
pinMode(pin, OUTPUT);
digitalWrite(pin, LOW);
}
void ledOn(int pin) {
digitalWrite(pin, HIGH);
}
void ledOff(int pin) {
digitalWrite(pin, LOW);
}
void ledToggle(int pin){
digitalWrite(pin, !digitalRead(pin));
}