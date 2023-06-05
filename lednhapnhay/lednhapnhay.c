#include <16F887.h>
#fuses INTRC
#use delay(clock=8MHz)

#define Led    PIN_D0

void main()
{
set_tris_d(0b11111111);//RD0 la ngo ra
//output_low(Led);//xuat muc thap ra Led
while(TRUE)//1,#1 (#0)
{
output_high(Led);//xuat muc cao ra Led
delay_ms(500);//tri hoan 500ms
output_low(Led);//xuat muc thap ra Led
delay_ms(500);//tri hoan 500ms
}
}

