#include <16f887.h>
#fuses intrc
#device adc =10 
#use delay(clock=8M)
#include <lcd.c>       

int8 Value1,Value2 ; 


void main(){

   set_tris_a(0xFF);
   set_tris_b(0xFF);
   set_tris_e(0xFF);
   
   setup_adc_ports(sAN0|sAN5|VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);
while(TRUE){
   
   set_adc_channel(0);
   delay_us(20);
   Value1 = read_adc()/2.046;
   lcd_gotoxy(1,1);
   printf(lcd_putc,"T1=%02u",Value1);
   lcd_putc(223);
   lcd_putc('C');
   
   set_adc_channel(5);
   delay_us(20);
   Value2 = read_adc()/2.046;
   lcd_gotoxy(10,1);
   printf(lcd_putc,"T2=%02u",Value2);
   lcd_putc(223);
   lcd_putc('C');
   
   
   if(Value1 > 60)
   {
      lcd_gotoxy(6,2);
      lcd_putc("QUA NHIET K1 ");
   }
   else if(Value2 > 60){
      lcd_gotoxy(6,2);
      lcd_putc("QUA NHIET K2 ");
   }
   else if ( (Value1 >60) && (Value2 > 60) ){
      lcd_gotoxy(6,2);
      lcd_putc("QUA NHIET 2K ");
   }else ; 
}
}


                     

   
   

