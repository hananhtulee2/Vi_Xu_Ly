#include<16F887.h>
#fuses INTRC_IO
#use delay(CLOCK=8MHz)  //Fosc=8 MHz
#define btnFF     PIN_B0
#define btnREV    PIN_B1

void main()
{
set_tris_b(0b11111111);
port_b_pullups(0b11111111);
set_tris_c(0b11111001);
//PR2=(Period*Fosc)/(4*DIV)-1=(0.8*1000*8)/(4*16) -1 = 249
setup_timer_2(T2_DIV_BY_16,249,1);//T=PWM Period = 2ms; DIV=16;PR2=249

setup_ccp1(CCP_OFF);output_low(PIN_C2);
setup_ccp2(CCP_OFF);output_low(PIN_C1);

while(TRUE)
{
if(input(btnFF)==0)
{
//value=(Tpwm*Duty*Fosc)/(100%*DIV)=(2ms*70%*8MHz)/(100%*16)
set_pwm1_duty((int16)700);//Duty =70%
setup_ccp1(CCP_PWM);
setup_ccp2(CCP_OFF);output_low(PIN_C1);
}
else
if(input(btnREV)==0)
{
//value=(Tpwm*Duty*Fosc)/(100%*DIV)=(2ms*30%*8MHz)/(100%*16)
set_pwm2_duty((int16)300);//Duty =30%
setup_ccp2(CCP_PWM);
setup_ccp1(CCP_OFF);output_low(PIN_C2);
}
else;
}
}
