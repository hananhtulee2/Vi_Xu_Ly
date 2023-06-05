#include <16F887.h>
#fuses INTRC_IO
#use delay(CLOCK=8MHz)


void main()
{
set_tris_a(0xFF);//RA4/T0CKI:0b***1****
set_tris_d(0x00);

setup_timer_0(RTCC_DIV_1|RTCC_EXT_H_TO_L);
set_timer0(0);    

while(TRUE)
{
output_d(get_timer0());
}
}
