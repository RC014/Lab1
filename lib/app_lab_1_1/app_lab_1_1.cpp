#include "app_lab_1_1.h"
#include <Arduino.h>
#include <string.h>
#include "stdio.h"
#include "../led/led.h"
#include "../srv_serial_stdio/srv_serial_stdio.h"
void app_lab_1_1_setup()
{
srv_serial_stdio_setup();
my_led_setup(LED_BUILTIN);
printf("lab_1_1 start\n");

}
void app_lab_1_1_loop()
{
char command[10]; // numarul 10 aloca spatiu in memorie pentru un sir scurt de caractere
scanf("%9s", command); // numarul 9 ne asigura ca nu citim mai mult decat incape in buffer, lasand loc pentru final
if (strcmp(command, "on") == 0) { // numarul 0 inseamna ca cele doua texte sunt identice
led_on(LED_BUILTIN);
printf("LED ON\n");
}
else if (strcmp(command, "off") == 0) { // comparam rezultatul cu 0 pentru a gasi potrivirea exacta
led_off(LED_BUILTIN);
printf("LED OFF\n");
}
else if (strcmp(command, "toggle") == 0) { // daca functia returneaza 0, am gasit comanda cautata
printf("LED Toggling\n");
for (int i = 0; i < 6; i++) { // incepem de la 0 si ne oprim la 6, executand bucla de exact 6 ori
led_toggle(LED_BUILTIN);
delay(500); // numarul 500 tine sistemul in pauza jumatate de secunda (milisecunde)
}
}
else {
printf("Unknown command\n");
}
}