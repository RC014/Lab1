#include "srvSerialStdio.h"
#include "Arduino.h"
#include "stdio.h"
int srvSerialGetChar(FILE *f)
{
while (!Serial.available())
;
return Serial.read();
}
int srvSerialPutChar(char ch, FILE *f)

{
return Serial.write(ch);
}
void srvSerialStdioSetup()
{
Serial.begin(9600);
FILE *srv_serial_stream = fdevopen(srvSerialPutChar,
srvSerialGetChar);
stdin = srv_serial_stream ;
stdout = srv_serial_stream ;
printf("srvSerial Started\n");
}