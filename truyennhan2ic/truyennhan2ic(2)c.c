#include <16F887.h>

#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#use RS232(BAUD=9600,BITS=8,STOP=1,PARITY=N,xmit=PIN_C6,rcv=PIN_C7)
#include <lcd.c>
#define LED PIN_B1 
unsigned int8 tam  ;
unsigned int8 ND = 0;

void main()
{
   set_tris_b(0x00);
   set_tris_d(0x00);
   output_low(LED);
   lcd_init(); 
   while (TRUE){
      if (kbhit() ==1 )
      {
         tam = getc() ;
         if (tam == 'L')
            output_toggle(LED);
         else ND = tam; 
              
      }
      lcd_gotoxy(1,1); 
      if(input_state(LED) == 1) 
         printf(lcd_putc,"LED DANG SANG") ;
      else printf(lcd_putc,"LED DANG TAT") ;
      lcd_gotoxy(1,2); 
      printf(lcd_putc,"NHIET DO: %u ", ND) ;
      lcd_putc(0xdf);
      lcd_putc('C');
      
   }
}
