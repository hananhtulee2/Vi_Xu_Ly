#include <16F887.h>
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#include <lcd.c>
int8 PRODUCT,BOX ; 

void main()
{
set_tris_a(0xFF);//RA4/T0CKI:0b***1****


setup_timer_0(RTCC_DIV_4|RTCC_EXT_H_TO_L);
set_timer0(0);    
lcd_init();
BOX = 0 ; 
while(TRUE)
{
PRODUCT = get_timer0();
lcd_gotoxy(1,1);
printf(lcd_putc,"PRODUCT = %03u",PRODUCT) ; 
if(PRODUCT == 26){
BOX++ ;
set_timer0(1); 

}
lcd_gotoxy(1,2);
printf(lcd_putc,"BOX = %03u",BOX );

}
}
