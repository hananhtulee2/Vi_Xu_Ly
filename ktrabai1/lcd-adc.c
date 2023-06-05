#include <16F887.h>
#device ADC=10
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#include <lcd.c>

unsigned int16 Value;

void main()
{
set_tris_a(0xFF);
set_tris_b(0xFF);
set_tris_e(0xFF);

lcd_init();

setup_adc_ports(sAN0|sAN5|sAN11|VSS_VDD);
setup_adc(ADC_CLOCK_INTERNAL);
while(TRUE)
{
set_adc_channel(0);
delay_us(20);
Value = read_adc();
lcd_gotoxy(1,1);
printf(lcd_putc,"A00=%04Lu",Value);

set_adc_channel(5);
delay_us(20);
Value = read_adc()/2.046;
lcd_gotoxy(10,2);
printf(lcd_putc,"T=%03Lu",Value);
lcd_putc(223);
lcd_putc('C');

set_adc_channel(11);
delay_us(20);
Value = read_adc();
lcd_gotoxy(1,2);
printf(lcd_putc,"A11=%04Lu",Value);

}
}
