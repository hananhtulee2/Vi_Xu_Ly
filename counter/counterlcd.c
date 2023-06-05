#include <16F887.h>
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#include <lcd.c>
int8 cnt ; 

void main()
{
set_tris_a(0xFF);//RA4/T0CKI:0b***1****


setup_timer_0(RTCC_DIV_1|RTCC_EXT_H_TO_L);
set_timer0(0);    
lcd_init();
while(TRUE)
{

if( get_timer0() == 100){
set_timer0(0);
}
lcd_gotoxy(1,1);
printf(lcd_putc,"Count=%03u",get_timer0());
}
}
