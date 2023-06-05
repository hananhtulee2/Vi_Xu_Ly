#include <16F887.h>
#fuses INTRC_IO
#use delay(CLOCK=8MHz)
#include <lcd.c>

#define START PIN_B0
#define STOP  PIN_B1
#define LCD_ENABLE_PIN  PIN_E0                            
#define LCD_RS_PIN      PIN_E1
#define LCD_RW_PIN      PIN_E2                                   
#define LCD_DATA4       PIN_D4                                  
#define LCD_DATA5       PIN_D5
#define LCD_DATA6       PIN_D6
unsigned int8 PRODUCT;

unsigned int8 st = 0;
void main()
{
    set_tris_d(0x00); //RA4/T0CKI:0b***1****
    set_tris_c(0x01);
    set_tris_b(0x03); 
    set_tris_e(0x00);
    setup_timer_1(T1_EXTERNAL|T1_DIV_BY_1);
    set_timer1(0);

    lcd_init();
    lcd_gotoxy(1, 1);
    lcd_putc("NHAN START");

    lcd_gotoxy(1, 2);
    lcd_putc("DE KHOI DONG");

    while (TRUE)
    {

        if (input(START) == 0)
        {

            delay_ms(50);
            st = 1;
            while (input(START) == 0) ;
            delay_ms(50);
        }
        if (st == 1)
        {
            
            delay_ms(10);
            PRODUCT = get_timer1();
            lcd_gotoxy(1, 1);
            lcd_putc("DEM SAN PHAM");

            lcd_gotoxy(1, 2);
            printf(lcd_putc, "SO LUONG = %02u", PRODUCT);

            if (PRODUCT == 30)
            {
                setup_timer_1(T1_disabled);
                lcd_send_byte(0,1);
                lcd_send_byte(0,6);
            }
            delay_ms(10);
        } 
        
        if (input(STOP) == 0)
        {

            delay_ms(50);
            st = 2 ; 
            while (input(STOP) == 0) ;
            delay_ms(50);
        }
        if (st == 2){
            setup_timer_1(T1_disabled);
        }
    }
}

