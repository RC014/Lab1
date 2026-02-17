#ifndef SRV_STDIO_LCD_H
#define SRV_STDIO_LCD_H
#include <stdio.h>
void srv_stdio_lcd_setup();
int srv_stdio_lcd_putc(char c, FILE *stream);
#endif /* SRV_STDIO_LCD_H */