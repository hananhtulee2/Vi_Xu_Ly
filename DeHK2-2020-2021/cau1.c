#include <16F887.h>
#device ADC=10
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#include <lcd.c>
#use rs232(BAUD=9600,BITS=8,STOP=1,PARITY=N,RCV=PIN_C7,XMIT=PIN_C6)

unsigned int8 speed ; 
unsigned int8 rxdata ; 
unsigned int8 temp ,prev_temp ; 
int1 FULL = 0 ;
int1 STOP = 0;
int1 FW = 0 ; 
int1 REV = 0 ; 
unsigned int8 MAXDUTY = 500; 

void main(){
   
   set_tris_d(0x00);
   set_tris_c(0x80); 
   set_tris_e(0b0001);
   
   setup_ccp2(ccp_off); output_low(pin_C1);
   setup_ccp1(ccp_off); output_low(pin_C2);
   
   setup_timer_2(T2_DIV_BY_16,124,1);
   set_timer2(0);
   
   setup_adc(adc_clock_internal);
   setup_adc_ports(SAN5|VSS_VDD);
   
   lcd_init();
   
   
   while(true){
      
      set_adc_channel(5);
      temp = read_adc()/2.046 ; 
      lcd_gotoxy(1,1); printf(lcd_putc,"T=%03u",temp);
      
      if (temp == 50){
         STOP  = 1 ; 
         FW = 0 ;
         REV = 0 ; 
      } else if ( temp > 50){
         FW = 1 ;
         STOP  = 0 ;
         REV = 0 ;  
      } else if ( temp < 50 ){
         REV = 1 ; 
         STOP = 0 ; 
         FW  = 0 ; 
      }
      else ; 
      if ( kbhit() == 1 ){
         rxdata = getc(); 
         
      }
      if (rxdata >= '1' && rxdata <= '9' ){
         speed = rxdata -0x30 ; 
      }
      else if (rxdata == 'F'){
         FULL = 1 ; 
         speed = 10 ; 
         
      } else ; 
      
    if(FW == 1){
      setup_ccp2(ccp_pwm); set_pwm2_duty(500*speed/10) ; 
      setup_ccp1(ccp_off); output_low(pin_C2);
      lcd_gotoxy(1,2); lcd_putc("DIR=FW    "); 
   }
    if(REV == 1){
      setup_ccp1(ccp_pwm); set_pwm1_duty(500*speed/10) ; 
      setup_ccp2(ccp_off); output_low(pin_C1);
      lcd_gotoxy(1,2); lcd_putc("DIR=REV ");  
   }
    if(STOP == 1){
      setup_ccp2(ccp_off); output_low(pin_C1);
      setup_ccp1(ccp_off); output_low(pin_C2);
      lcd_gotoxy(1,2); lcd_putc("DIR=STOP");  
    }

      
    lcd_gotoxy(9,2);
    if(speed == MAXDUTY){
      lcd_putc("DUTY=100");lcd_putc("%");
    }else{
    printf(lcd_putc,"DUTY=%2u",(speed*10));lcd_putc("%");
    }
    
     //goi len may tinh
        if(temp!=prev_temp) {
            printf("T=%3u\r\n",temp); 
            prev_temp = temp;
        }       
   
   }

}
