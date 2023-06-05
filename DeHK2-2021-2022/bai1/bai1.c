#include <16F887.h>
#fuses INTRC_IO
#use delay(CLOCK=8MHz)


unsigned char Code7Seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
unsigned int8 Count;

 
void main()
{

set_tris_b(0b00000000);
set_tris_d(0b00000000);

setup_timer_0(RTCC_DIV_1|RTCC_EXT_H_TO_L);
set_timer0(0);    

while(TRUE)
{
Count = get_timer0();
if(Count > 12 ){ 
   Count = 1 ;
   set_timer0(1); 
}
output_b(Code7Seg[Count%10]) ;
output_d(Code7Seg[Count/10]) ;

}
}
