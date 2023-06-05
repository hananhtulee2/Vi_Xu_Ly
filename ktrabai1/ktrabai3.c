
#include <16F887.h>
#device ADC=10
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#include <lcd.c>
#define LED PIN_A2

unsigned int16 Value1,Value2 ; 
unsigned int16 PV,MODE ; 
CONST UNSIGNED CHAR MA7DOAN[10]={0XC0, 0XF9, 0XA4, 0XB0, 0X99, 0X92,0X82,0XF8, 0X80, 0X90};

void main() {
   set_tris_a(0b00000011) ; 
   SET_TRIS_B(0X06);
   SET_TRIS_C(0X00);
   
   
   lcd_init() ;
   setup_adc_ports(sAN0|sAN1|sAN2|sAN3|VSS_VDD) ; 
   setup_adc(ADC_CLOCK_INTERNAL) ;
   while (TRUE) {
      set_adc_channel(3); 
      
      PV = 0.99*read_adc()/10.23 ; 
      
      
      set_adc_channel(2);
      MODE = read_adc()/10.23/10 ; 
         if (MODE > 3) MODE = 3 ;
         if (MODE < 1) MODE = 1 ;

     OUTPUT_B(MA7DOAN[MODE%10]);
   if  (MODE = 1 ){
      set_adc_channel(0);
      delay_us(20);
      Value1 = read_adc()/2.046;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"T=%03Lu",Value1);
      lcd_putc(223);
      lcd_putc('C');
   
         if (Value1 >= PV){
            lcd_gotoxy(14,1);
            lcd_putc("[H]");
        
           }
          else {
            lcd_gotoxy(14,1);
            lcd_putc("[L]");
          }}
    else if (MODE = 2){
      set_adc_channel(1);
      delay_us(20);
      Value2 = read_adc()/2.046;
      lcd_gotoxy(1,2);
      printf(lcd_putc,"T=%03Lu",Value2);
      lcd_putc(223);
      lcd_putc('C');   
          if (Value2 >= PV){
            lcd_gotoxy(14,2);
            lcd_putc("[H]");
        
           }
          else {
            lcd_gotoxy(14,2);
            lcd_putc("[L]");
          }
         }
         
      else if ( MODE =3 ){ 
         set_adc_channel(0);
         delay_us(20);
         Value1 = read_adc()/2.046;
         lcd_gotoxy(1,1);
         printf(lcd_putc,"T=%03Lu",Value1);
         lcd_putc(223);
         lcd_putc('C');
      
            if (Value1 >= PV){
               lcd_gotoxy(14,1);
               lcd_putc("[H]");
           
              }
             else {
               lcd_gotoxy(14,1);
               lcd_putc("[L]");
             }
         set_adc_channel(1);
         delay_us(20);
        Value2 = read_adc()/2.046;
        lcd_gotoxy(1,2);
          printf(lcd_putc,"T=%03Lu",Value2);
         lcd_putc(223);
        lcd_putc('C');   
          if (Value2 >= PV){
            lcd_gotoxy(14,2);
            lcd_putc("[H]");
        
           }
          else {
            lcd_gotoxy(14,2);
            lcd_putc("[L]");
          }
       
       
       
       
       if ( Value1 == Value2)
         {
            output_high(LED);
         }else 
            output_low(LED);
   
      }}


}
