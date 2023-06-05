#include <16F887.h>
#fuses INTRC 
#use delay(clock = 8 MHZ)
#define btn_DIR  PIN_B0 


unsigned int8 sangdich_array[5] = {0b0001,0b0010,0b0100,0b1000,0b0000} ;
unsigned int8 tatdich_array[5] = {0b1111,0b0111,0b0011,0b0001,0b0000}; 

signed int8 mode ;  
signed int8 i ; 
signed int8 j ;
void sangdich_motor()
{
   for( i = 0 ; i <= 4 ; i++){
      for ( j = 0 ; i<=4 ; j ++ ){ 
   output_d(sangdich_array[i]); 
   delay_ms(500);
      }
      }
}

void tatdich_motor(){

for( i = 0 ; i <= 4 ; i++){
   for ( j = 0 ; j <= 4 ; j++ ){
   output_d(tatdich_array[i]); 
   delay_ms(500);
   }
   }
}

void main(){


set_tris_d(0b0000) ; 

mode = 0 ; 

WHILE(TRUE)

{
  
   if(btn_DIR == 0 ){ 
   delay_ms(50) ; 
   output_b(0b00000000);
   output_low(LED1); 
   output_low(LED2);
   delay_ms(50);
   // output ... 
   mode += 1 ; 
   while ( input(btn_DIR == 0)){ 
    delay_ms(50); 
   }
   
   }
   if (btn_DIR == 0 && mode == 1 ) 
   {
   // output .... 
      sangdich_motor();
//!      delay ....    
      mode += 1 ;  
    while ( input(btn_DIR == 0)){ 
    delay_ms(50); 
   }
   }
   if (btn_DIR == 0 && mode == 2)
   {
   // output ....
      tatdich_motor();
      mode = 0 ; 
   }
}
}

