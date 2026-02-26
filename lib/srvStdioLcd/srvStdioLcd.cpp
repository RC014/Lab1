#include "srvStdioLcd.h"
#include "../../include/config.h"

#define CLEAR_KEY '\f' // caracterul # este folosit pentru a sterge continutul ecranului
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS); // initializam obiectul lcd cu parametrii definiti mai sus
int srvStdioLcdPutc( char c, FILE *stream) // functie care trimite un caracter catre ecran, compatibila cu fluxurile standard
{
if(c==CLEAR_KEY) // verificam daca caracterul primit este comanda de stergere
{
lcd.clear(); // stergem tot textul de pe ecran
lcd.setCursor(0, 0); // numerele 0 si 0 pozitioneaza cursorul la inceput (coloana 0, randul 0)
}else if(c == '\n') // verificam daca caracterul este linie noua
{
lcd.setCursor(0, 1); // mutam cursorul pe randul 2 (indexul 1)
}else{
lcd.print(c); // afisam caracterul propriu-zis pe ecran
}
return 0; // returnam 0 pentru a semnala succesul operatiei
}
void srvStdioLcdSetup()
{
lcd.init(); // initializam comunicatia cu ecranul
lcd.backlight(); // aprindem lumina de fundal a ecranului
lcd.clear(); // curatam ecranul de orice text anterior
lcd.setCursor(0, 0); // resetam cursorul la pozitia de start 0,0
FILE *srv_stdio_lcd_stream = fdevopen(srvStdioLcdPutc,NULL); // deschidem un flux de fisier virtual legat de functia noastra de afisare
stdout = srv_stdio_lcd_stream; // inlocuim iesirea standard (consola) cu ecranul lcd
}