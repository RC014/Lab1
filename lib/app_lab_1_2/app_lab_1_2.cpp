#include "app_lab_1_2.h"
#include <Arduino.h>
#include "../srv_stdio_keypad/srv_stdio_keypad.h"
#include "../srv_stdio_lcd/srv_stdio_lcd.h"
#include "../led/led.h"
// definim pinii pentru leduri

#define RED_LED 12 // numarul 12 este pinul fizic de pe placa arduino pentru ledul rosu
#define GREEN_LED 11 // numarul 11 este pinul fizic de pe placa arduino pentru ledul verde
// configuram ledurile si sistemul de intrare/iesire
void app_lab_1_2_setup()
{
srv_stdio_keypad_setup();
srv_stdio_lcd_setup();
my_led_setup(RED_LED);
my_led_setup(GREEN_LED);
}
// definirea parolei corecte
char code[4] = {'1','2','3','4'}; // numarul 4 defineste lungimea fixa a parolei
char input[4]; // numarul 4 rezerva memorie pentru cele 4 taste apasate de utilizator
void app_lab_1_2_loop()
{
printf("#"); // curatam ecranul inainte de a afisa promptul de introducere
printf("Scrierti parola:\n"); // cerem utilizatorului sa introduca codul si trecem la randul urmator
for(int i = 0; i < 4; i++) // bucla pentru a citi si afisa fiecare din cele 4 caractere
{
scanf("%c", &input[i]); // asteptam si citim o tasta
printf("%c", input[i]); // afisam tasta citita pe ecran pentru feedback vizual
}
// stergerea ecranului
printf("#");
if(input[0] == code[0] && input[1] == code[1] && input[2] == code[2] &&
input[3] == code[3]) // verificam indexii 0, 1, 2, 3 pentru a valida toata secventa
{
printf("Corect!"); // mesaj afisat daca parola este corecta
led_off(RED_LED);
led_on(GREEN_LED); // aprindem ledul verde
}
else
{
printf("Incorect!"); // mesaj afisat daca parola este gresita
led_off(GREEN_LED);
led_on(RED_LED); // aprindem ledul rosu
}
delay(2000); // asteptam 2 secunde pentru ca utilizatorul sa poata citi rezultatul
}