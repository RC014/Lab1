#ifndef SRV_SERIAL_STDIO_H_
#define SRV_SERIAL_STDIO_H_
#include <stdio.h>
int srvSerialPutChar(char ch, FILE *f);
int srvSerialGetChar(FILE *f);
void srvSerialStdioSetup();
#endif // SRV_SERIAL_STDIO_H_