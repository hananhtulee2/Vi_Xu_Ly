#include<16F887.h>
#fuses INTRC_IO
#use delay(CLOCK=8MHz)  //Fosc=8 MHz
#define ADJ PIN_E0
#define Pulse PIN_C2 


const unsigned int8 ma7doan[]={ 0xc0 ,0xf9 , 0xa4,0xb0 , 0x99 , 0x92,0x82 ,0xf8 , 0x80, 0x90};
int8 LEVEL = 0 ; 
void main()
{  
   set_tris_c(0x00) ;   
   set_tris_e(0xff) ; 
   set_tris_d(0x00) ; 
   output_d(ma7doan[0]);
   setup_timer_2(T2_DIV_BY_16,249,1);
   set_timer2(0);
   setup_ccp1(CCP_PWM);

while(TRUE)
{
   if(input(ADJ) == 0  ){
      delay_ms(50);
      LEVEL++ ; 
      while(input(ADJ) == 0 ) ; 
      delay_ms(50);   
   }
   if (LEVEL > 9) {
      LEVEL = 0 ;
   }
   

   set_PWM1_DUTY((unsigned int16)LEVEL*100);
   output_d(ma7doan[LEVEL]) ; 


   
}
}
