#include "srvStdioKeypad.h"
#include "../../include/config.h"

#define SRV_KEYPAD_REPEAT_DELAY 100 // numarul 100 reprezinta milisecundele de pauza intre citiri pentru a evita citirile multiple accidentale
char keys[KEYPAD_ROWS][KEYPAD_COLS] = { // matricea de caractere asociata butoanelor

{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[KEYPAD_ROWS] = {KEYPAD_R1_PIN, KEYPAD_R2_PIN, KEYPAD_R3_PIN, KEYPAD_R4_PIN}; // Pinii digitali pentru randurile tastaturii
byte colPins[KEYPAD_COLS] = {KEYPAD_C1_PIN, KEYPAD_C2_PIN, KEYPAD_C3_PIN, KEYPAD_C4_PIN}; // Pinii digitali pentru coloanele tastaturii
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, KEYPAD_ROWS,
KEYPAD_COLS); // initializam obiectul tastaturii cu configuratia definita mai sus
int srvStdioKeypadGetKey(FILE *stream) // functia care preia caracterele, compatibila cu standardul c
{
int customKey; // variabila temporara pentru tasta citita
do { // bucla care asteapta pana cand utilizatorul apasa o tasta
customKey = customKeypad.getKey(); // interogam hardware-ul
} while (customKey == NO_KEY); // cat timp rezultatul este no_key (adica 0), continuam sa asteptam
delay(SRV_KEYPAD_REPEAT_DELAY); // asteptam 100ms definit mai sus pentru a preveni inregistrarea dubla a unei apasari
return customKey; // returnam caracterul gasit catre sistem
}
void srvStdioKeypadSetup()
{
FILE *myStream = fdevopen(NULL, srvStdioKeypadGetKey); // deschidem un flux de date standard conectat la functia noastra de citire
stdin = myStream; // inlocuim intrarea standard (tastatura pc-ului) cu tastatura noastra matriciala
}