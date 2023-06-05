#include <16F887.h>
#fuses INTRC
#use delay(CLOCK=8MHz)
int8 varCount;
                     //"0"  "1"  "2"  "3"  "4"  "5"  "6"  "7"  "8"  "9"
int8 aryCode7Seg[16]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90,0x88,0x83,0xC6,0xA1,0x86,0x8E};
void main()
{
set_tris_b(0b11111111);
port_b_pullups(0b11111111);
set_tris_c(0b00000000);
while(TRUE)
{
varCount=input_b();
varCount=varCount&0b00001111;
output_c(aryCode7Seg[varCount]);
}
}

