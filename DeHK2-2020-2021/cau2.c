#include <16F887.h>
#fuses INTRC_IO
#use delay(CLOCK=8MHz)

#define ON   Pin_B1 
#define LED  Pin_E1
#define PULSE  Pin_E0
#bit TMR1IF = 0x0b.0

#int_ext 
void ngat_ngoai(){
   output_low(LED);
}

unsigned int8 product = 0 ; 
unsigned int8 box = 0 ;  
char Code7Seg[10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};

void main(){

set_tris_a(0xff);
set_tris_c(0x00);
set_tris_d(0x00); 
set_tris_e(0b0011);
set_tris_b(0x00);

setup_timer_0(RTCC_DIV_1|RTCC_EXT_H_TO_L);
set_timer0(0);  
setup_timer_1(t1_internal|t1_div_by_8);
set_timer1(65535);

enable_interrupts(global);
enable_interrupts(int_ext);
ext_int_edge(H_TO_L) ; 

while(true){
   product = get_timer0() ;
   if(Product==25) 
   {
      set_timer0(1);
      product=1;
      box++;
   }
   
   //xuat san pham ra led 7 doan 
   output_c(Code7Seg[product/10]);
   output_d(Code7Seg[product%10]);
   
   if(TMR1IF == 1){
      output_toggle(PULSE) ; 
      set_timer1(65535);
      TMR1IF = 0 ; 
   }
   if(input(ON)==0) {
      delay_ms(3000);
      output_toggle(LED);
      delay_ms(3000);
   }
   else ;

}
}

