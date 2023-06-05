#include <16F887.h>
#fuses INTRC_IO  
#use delay(CLOCK=8MHz)

unsigned arr[15] = {0b00000001, 0b00000011, 0b00000111,0b00001111 , 0b00011111,0b000111111 ,0b00111111,0b01111111 ,0b11111111 ,0b00000000,0b10000001,0b01000010,0b00100100,0b00011000,0b00000000 
} ; 

signed int i ; 




void main(){

set_tris_b(0b00000000);
while(TRUE){
   for ( i = 0 ; i<=14 ; i++){
      output_b(arr[i]);
      delay_ms(100);
   
   }

}
}
