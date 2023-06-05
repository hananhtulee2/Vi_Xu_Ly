#include <16F887.h>
#device ADC=10
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#include <lcd.c>

unsigned int16 Value,iADC;
void main()
{
lcd_init();
set_tris_c(0b10111111);
set_tris_e(0xFF);
setup_adc_ports(NO_ANALOGS|sAN7|VSS_VDD);
setup_adc(ADC_CLOCK_INTERNAL);
while(TRUE)
{
putc('A');puts("106");
delay_ms(300);
putc('B');putc(13);
delay_ms(300);
puts("Hello World");
delay_ms(300);
printf("Count=%03Lu",Value);putc(13);
lcd_gotoxy(1,1);
printf(lcd_putc,"Count=%03Lu",Value);
Value++;

set_adc_channel(7);
delay_us(20);
iADC=read_adc()/2.046;
printf("Temperature=%03Lu",iADC);putc(13);
lcd_gotoxy(1,2);
printf(lcd_putc,"T=%03Lu",iADC);lcd_putc(223);lcd_putc('C');

}
}
