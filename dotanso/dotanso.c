#include <16f887.h>
#fuses hs 
#use delay(clock =20M)
#use rs232(BAUD=9600,BITS=8,STOP=1,PARITY=N,RCV=PIN_C7,XMIT=PIN_C6)

unsigned int8 bdt ; 
unsigned int8 pulse =0;

#int_timer1
void ngat_timer1(){
   bdt++;
   set_timer1(3036);
   if(bdt == 10){ 
      pulse = get_timer0();
      bdt = 0 ; 
      set_timer0(0);
      printf("HZ=%03u\r\n", pulse) ;
      
   
   }
}


void main(){
   set_tris_c(0x80);
   
   setup_timer_0(T0_DIV_1|T0_EXT_L_TO_H); 
   set_timer0(0);
   
   setup_timer_1(T1_DIV_BY_8|T1_INTERNAL);
   set_timer1(3036);
   
   enable_interrupts(global);
   enable_interrupts(int_timer1);
   
   while(true){
   }

}
