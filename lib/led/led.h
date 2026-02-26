#ifndef LED_H
#define LED_H

#include <Arduino.h>

void myLedSetup(int pin);
void ledOn(int pin);
void ledOff(int pin);
void ledToggle(int pin);
#endif /* LED_H */