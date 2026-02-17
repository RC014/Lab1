#include "srv_stdio_lcd.h"
#include <LiquidCrystal_I2C.h>
#define I2C_ADDR 0x27 // адрес экрана

#define LCD_COLUMNS 16
#define LCD_ROWS 2
#define CLEAR_KEY '#'//клавиша для очистки экрана
LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLUMNS, LCD_ROWS);//создаем экран
int srv_stdio_lcd_putc( char c, FILE *stream)//функция для вывода символа на экран
{
if(c==CLEAR_KEY)//если нажата клавиша очистки экрана
{
lcd.clear();
lcd.setCursor(0, 0);
}else{
lcd.print(c);//выводим символ на экран
}
return 0;
}
void srv_stdio_lcd_setup()
{
lcd.init();//инициализация
lcd.backlight();//подсветка
lcd.clear();//очистка
lcd.setCursor(0, 0);//установка курсора
FILE *srv_stdio_lcd_stream = fdevopen(srv_stdio_lcd_putc,
NULL); //создаем поток
stdout = srv_stdio_lcd_stream; //перенаправляем стандартный вывод чтобы он выводился на экран
}