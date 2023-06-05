#include <16F887.h>
#device ADC=10
#fuses hs
#use delay(CLOCK=20MHz)
#include <lcd.c>
#use rs232(BAUD=9600,BITS=8,STOP=1,PARITY=N,RCV=PIN_C7,XMIT=PIN_C6)

#define LED PIN_A0 

unsigned int8 rxdata ;
unsigned int8 temp1 , temp2 ;
unsigned int8 mode = 0 ; 


void main(){
   set_tris_c(0x80);
   set_tris_a(0b00000110);
   
   setup_adc(adc_clock_internal);
   setup_adc_ports(SAN1|SAN2|VSS_VDD);
   
   lcd_init();
   output_low(LED);

while(true){
   if(kbhit() == 1){
      rxdata = getc();
   }else ; 
   if(rxdata == "CH1"){
      mode = 1 ; 
   } else if (rxdata == "CH2"){
      mode = 2 ; 
   } else if (rxdata == "CH1&2"){
      mode = 3 ; 
   } else if (rxdata == "STOP"){
      mode = 0 ; 
   }else ;
    
    // lay du lieu nhiet do 1
    set_adc_channel(1);
    temp1 = read_adc()/2.046 ; 
    
    // lay du lieu nhiet do 2 
    set_adc_channel(2);
    temp2 = read_adc()/2.046 ; 
    
    if (mode == 1){   
         lcd_gotoxy(1,1);
         printf(lcd_putc,"CH1=%03u",temp1);
         lcd_putc(223);
         lcd_putc('C');
         
         lcd_gotoxy(1,2);
         lcd_putc("CH2=OFF");
         lcd_gotoxy(12,2);
         lcd_putc("[x]") ; 
            if ( temp1 >= 50 ){
                lcd_gotoxy(12,1);
                lcd_putc("[H]");
                output_high(LED);
         } else lcd_gotoxy(12,1);
                lcd_putc("[L]");
                output_low(LED);
    } else if (mode == 2){   
               lcd_gotoxy(1,2);
               printf(lcd_putc,"CH2=%03u",temp2);
               lcd_putc(223);
               lcd_putc('C');
               
               lcd_gotoxy(1,1);
               lcd_putc("CH1=OFF");
               lcd_gotoxy(12,1);
               lcd_putc("[x]") ; 
                  if ( temp2 >= 50 ){
                     lcd_gotoxy(12,2);
                     lcd_putc("[H]");
                     output_high(LED);
               } else lcd_gotoxy(12,2);
                      lcd_putc("[L]");
                      output_low(LED);
    }else if (mode == 3){   
               lcd_gotoxy(1,1);
               printf(lcd_putc,"CH1=%03u",temp1);
               lcd_putc(223);
               lcd_putc('C');
               
               lcd_gotoxy(1,2);
               printf(lcd_putc,"CH2=%03u",temp2);
               lcd_putc(223);
               lcd_putc('C');
                  
               if ( temp1 >= 50 ){
                  lcd_gotoxy(12,1);
                  lcd_putc("[H]");
                  output_high(LED);
               }  else if (temp1 < 50){ 
                      lcd_gotoxy(12,1);
                      lcd_putc("[L]");
                      output_low(LED);
               }else if ( temp2 >= 50 ){
                  lcd_gotoxy(12,2);
                  lcd_putc("[H]");
                  output_high(LED);
               }else if (temp2 < 50){ 
                      lcd_gotoxy(12,2);
                      lcd_putc("[L]");
                      output_low(LED);
               } else ; 
    }else if (mode == 0){
               output_low(LED);
               lcd_gotoxy(1,1);
               lcd_putc("CH1=OFF");
               lcd_gotoxy(12,1);
               lcd_putc("[x]") ;
               
               lcd_gotoxy(1,2);
               lcd_putc("CH2=OFF");
               lcd_gotoxy(12,2);
               lcd_putc("[x]") ; 
    
    }else ; 

}
}

