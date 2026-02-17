#include "srv_stdio_keypad.h"
#include <Keypad.h>
#define SRV_KEYPAD_REPEAT_DELAY 100 // numarul 100 reprezinta milisecundele de pauza intre citiri pentru a evita citirile multiple accidentale
const byte ROWS = 4; // numarul 4 defineste cate randuri fizice are tastatura
const byte COLS = 4; // numarul 4 defineste cate coloane fizice are tastatura
char keys[ROWS][COLS] = { // matricea de caractere asociata butoanelor

{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}
};
byte rowPins[ROWS] = {12, 11, 10, 9}; // numerele 12, 11, 10, 9 sunt pinii digitali de pe placa arduino conectati la randurile tastaturii
byte colPins[COLS] = {8, 7, 6, 5}; // numerele 8, 7, 6, 5 sunt pinii digitali de pe placa arduino conectati la coloanele tastaturii
Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS,
COLS); // initializam obiectul tastaturii cu configuratia definita mai sus
int srv_stdio_keypad_get_key(FILE *stream) // functia care preia caracterele, compatibila cu standardul c
{
int customKey; // variabila temporara pentru tasta citita
do { // bucla care asteapta pana cand utilizatorul apasa o tasta
customKey = customKeypad.getKey(); // interogam hardware-ul
} while (customKey == NO_KEY); // cat timp rezultatul este no_key (adica 0), continuam sa asteptam
delay(SRV_KEYPAD_REPEAT_DELAY); // asteptam 100ms definit mai sus pentru a preveni inregistrarea dubla a unei apasari
return customKey; // returnam caracterul gasit catre sistem
}
void srv_stdio_keypad_setup()
{
FILE *my_stream = fdevopen(NULL, srv_stdio_keypad_get_key); // deschidem un flux de date standard conectat la functia noastra de citire
stdin = my_stream; // inlocuim intrarea standard (tastatura pc-ului) cu tastatura noastra matriciala
}