#ifndef SRV_STDIO_KEYPAD_H
#define SRV_STDIO_KEYPAD_H
#include <stdio.h>
#include <Keypad.h>
void srvStdioKeypadSetup();
int srvStdioKeypadGetKey(FILE *stream);
#endif /* SRV_STDIO_KEYPAD_H */