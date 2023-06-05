#include <16F887.h>
#device ADC=10
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#use RS232(BAUD=9600,BITS=8,STOP=1,PARITY=N,xmit=PIN_C6,rcv=PIN_C7)

#define LED PIN_B4 
#define ND PIN_B5
unsigned int8 temp;
unsigned int16 ndo;

void main()
{
set_tris_b(0xff) ; 
port_b_pullups(TRUE);
setup_adc(adc_clock_internal);
setup_adc_ports(SAN5|VSS_VDD);
set_adc_channel(5);
delay_us(10);

while(TRUE)
{

set_adc_channel(5);
delay_us(10);
ndo = read_adc()/2.046 ; 
temp = ndo ; 
if (input(LED) == 0 ){
   delay_ms(10);
   while (input(LED) == 0);
   putc('L');
}
if (input(ND) == 0 ){
   delay_ms(10);
   while (input(ND) == 0);
   putc(temp); 
   
}
delay_ms(10); 
}
}
