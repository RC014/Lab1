#include "led.h"
#include <Arduino.h>
void my_led_setup(int pin){
pinMode(pin, OUTPUT);
digitalWrite(pin, LOW);
}
void led_on(int pin) {
digitalWrite(pin, HIGH);
}
void led_off(int pin) {
digitalWrite(pin, LOW);
}
void led_toggle(int pin){
digitalWrite(pin, !digitalRead(pin));
}