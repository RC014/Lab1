#include <Arduino.h>
#include "../lib/appLab11/appLab11.h"
#include "../lib/appLab12/appLab12.h"

#define USE_APP_LAB_1_1 11
#define USE_APP_LAB_1_2 12

#define APP_USED USE_APP_LAB_1_2
void setup() {
#if APP_USED == USE_APP_LAB_1_1
appLab11Setup();
#elif APP_USED == USE_APP_LAB_1_2
appLab12Setup();
#endif
}

void loop() {
#if APP_USED == USE_APP_LAB_1_1
appLab11Loop();
#elif APP_USED == USE_APP_LAB_1_2
appLab12Loop();
#endif
}