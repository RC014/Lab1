#include "appLab12.h"
#include "../../include/config.h"

led_t hRedLed;
led_t hGreenLed;

// configuram ledurile si sistemul de intrare/iesire
void appLab12Setup()
{
    srvStdioKeypadSetup();
    srvStdioLcdSetup();
    myLedArduinoSetup(&hRedLed, RED_LED);
    myLedArduinoSetup(&hGreenLed, GREEN_LED);
}
// definirea parolei corecte
char code[4] = {'1','2','3','4'}; // numarul 4 defineste lungimea fixa a parolei, cifrele din acolade reprezinta pin-ul corect
char input[4]; // numarul 4 rezerva memorie pentru cele 4 taste apasate de utilizator
void appLab12Loop()
{
printf("\f"); // curatam ecranul inainte de a afisa promptul de introducere
printf("Scrierti parola:\n"); // cerem utilizatorului sa introduca codul si trecem la randul urmator
for(int i = 0; i < 4; i++) // bucla pentru a citi si afisa fiecare din cele 4 caractere
{
scanf("%c", &input[i]); // asteptam si citim o tasta
printf("%c", input[i]); // afisam tasta citita pe ecran pentru feedback vizual
}
// stergerea ecranului
printf("\f");
if(input[0] == code[0] && input[1] == code[1] && input[2] == code[2] &&
input[3] == code[3]) // verificam indexii 0, 1, 2, 3 pentru a valida toata secventa
{
    printf("Corect!"); // mesaj afisat daca parola este corecta
    ledOff(&hRedLed);
    ledOn(&hGreenLed); // aprindem ledul verde
}
else
{
    printf("Incorect!"); // mesaj afisat daca parola este gresita
    ledOff(&hGreenLed);
    ledOn(&hRedLed); // aprindem ledul rosu
}
delay(2000); // asteptam 2 secunde pentru ca utilizatorul sa poata citi rezultatul
ledOff(&hGreenLed);
ledOff(&hRedLed); // stingem ledurile inainte de a relua ciclul

}