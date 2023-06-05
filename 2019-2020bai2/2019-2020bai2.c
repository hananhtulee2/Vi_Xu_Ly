#include<16F887.h>
#device ADC=10
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#include <lcd.c>

UNSIGNED INT8 SP = 0 ; 
UNSIGNED INT16 BOX = 0 ; 
UNSIGNED INT ND = 0 ; 


void main()
{
   set_tris_E(0xFF);
   set_tris_C(0xFF);
   set_tris_D(0xFF);
   LCD_INIT();
   setup_timer_1(T1_EXTERNAL|T1_DIV_BY_1);
   set_timer1(0);
   setup_ADC(ADC_CLOCK_INTERNAL);
   setup_ADC_PORTS(SAN5|VSS_VDD);
   
   while(True)
   {
      set_ADC_channel(5);
      delay_us(20);
      ND = read_ADC()/2.046;
      
      if (ND <= 100)
      {
         setup_timer_1(T1_EXTERNAL|T1_DIV_BY_1);
      }
      else setup_timer_1(T1_DISABLED);
      
      SP = get_timer1();
      
      if (SP >=50 ){
         SP = 1 ; 
         set_timer1(0);
         BOX++ ; 
      }
      else ; 
      
      LCD_GOTOXY(1,1);
      printf(LCD_PUTC,"P = %02U", SP);
      LCD_GOTOXY(1,2);
      printf(LCD_PUTC,"BOX = %05lU",BOX);
      LCD_GOTOXY(10,1);
      printf(LCD_PUTC,"T = %03U", ND);
      LCD_PUTC(223);
      LCD_PUTC('C');
   }}
