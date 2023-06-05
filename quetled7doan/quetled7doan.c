#include <16F887.h>
#fuses INTRC_IO
#use delay(CLOCK=8MHz)

#define Q_TENS     PIN_E0
#define Q_UNITS    PIN_E1
unsigned char Code7Seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
unsigned int8 Count;
void delay_msScanLED(unsigned int16 t);
void main()
{
set_tris_e(0b00000011);
set_tris_d(0b00000000);

while(TRUE)
{
for(Count=0;Count<=99;Count++)
{
delay_msScanLED(300);
}
}
}

void delay_msScanLED(unsigned int16 t)
{
unsigned int16 i;
for(i=0;i<t/10;i++)
{
output_low(Q_TENS);
output_high(Q_UNITS);
output_d(Code7Seg[Count/10]);
delay_ms(5);

output_high(Q_TENS);
output_low(Q_UNITS);
output_d(Code7Seg[Count%10]);
delay_ms(5);
}
}
