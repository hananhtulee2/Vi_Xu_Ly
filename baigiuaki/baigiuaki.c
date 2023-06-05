#include<16F887.h>
#device ADC=10
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#include <lcd.c>


const unsigned int8 ma7doan[]={ 0xc0 ,0xf9 , 0xa4,0xb0 , 0x99 , 0x92,0x82 ,0xf8 , 0x80, 0x90};
const unsigned arr[9] = {0b00000000, 0b00000001, 0b00000010,0b00000100 , 0b00001000,0b00010000 ,0b00100000,0b01000000,0b10000000};
unsigned int16 NUM = 0  ; 
unsigned int8 ND ; 

void main(){

   set_tris_c(0x00) ; 
   set_tris_b(0x00) ; 
   lcd_init();
   setup_ADC(ADC_CLOCK_INTERNAL);
   setup_ADC_PORTS(SAN5|SAN6|VSS_VDD);

while(TRUE){

   
   set_adc_channel(5);
   delay_us(50);
   NUM = read_adc()/10.23/10 ; 
   delay_us(50);
   output_b(ma7doan[NUM]) ; 
   
   set_adc_channel(6);
   delay_us(50);
   ND = read_adc()/2.046 ;
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"Nhiet do : %02u " , ND) ; 
   
   if ( NUM == 0 ) { 
    output_c(arr[0]) ;
   } 
   else {
   
   if( ND <= 50) {
      output_c(arr[NUM]) ; 
      delay_ms(300);
      output_c(arr[0]) ; 
      delay_ms(300); 
   } 
   else output_c(arr[NUM]) ; 
   
   }




}

}
