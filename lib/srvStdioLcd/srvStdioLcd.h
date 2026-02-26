#ifndef SRV_STDIO_LCD_H
#define SRV_STDIO_LCD_H

#include <stdio.h>
#include <LiquidCrystal_I2C.h>

void srvStdioLcdSetup();
int srvStdioLcdPutc(char c, FILE *stream);
#endif /* SRV_STDIO_LCD_H */