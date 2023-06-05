#include<16F887.h>
#device ADC=10
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#include <lcd.c>


unsigned int8 ND ; 

void main(){

   set_tris_e(0xff) ; 
   lcd_init();
   setup_ADC(ADC_CLOCK_INTERNAL);
   setup_ADC_PORTS(SAN5|VSS_VDD);

while(TRUE){

   set_adc_channel(5);
   delay_us(50);
   ND = read_adc()/2.046 ; 
   delay_us(50);
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"LM35:%02u ", ND) ; 
   lcd_putc(223);
   lcd_putc('C');
}
}
