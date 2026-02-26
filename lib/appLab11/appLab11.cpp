#include "appLab11.h"

led_t myBuiltinLed;

void appLab11Setup()
{
    srvSerialStdioSetup();
    myLedArduinoSetup(&myBuiltinLed, LED_BUILTIN);
    printf("lab11 start\r\n");

}
void appLab11Loop()
{
    char command[10]; // numarul 10 aloca spatiu in memorie pentru un sir scurt de caractere
    scanf("%9s", command); // numarul 9 ne asigura ca nu citim mai mult decat incape in buffer, lasand loc pentru final
    if (strcmp(command, "on") == 0) { // numarul 0 inseamna ca cele doua texte sunt identice
        ledOn(&myBuiltinLed);
        printf("LED ON\r\n");
    }
    else if (strcmp(command, "off") == 0) { // comparam rezultatul cu 0 pentru a gasi potrivirea exacta
        ledOff(&myBuiltinLed);
        printf("LED OFF\r\n");
    }
    else if (strcmp(command, "toggle") == 0) { // daca functia returneaza 0, am gasit comanda cautata
        printf("LED Toggling\r\n");
        for (int i = 0; i < 6; i++) { // incepem de la 0 si ne oprim la 6, executand bucla de exact 6 ori
            ledToggle(&myBuiltinLed);
            delay(500); // numarul 500 tine sistemul in pauza jumatate de secunda (milisecunde)
        }
    }
    else {
        printf("Unknown command\r\n");
    }
}