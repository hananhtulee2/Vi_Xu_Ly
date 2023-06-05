#include <16F877.h>
#fuses XT,NOWDT,NOPROTECT,NOLVP
#use delay(clock=4000000)
#define btn_UP  PIN_B0
#define btn_DOWN  PIN_B1
#define btn_STP PIN_B2 
#include <LCD.c>

signed int8 varCount ; 

void main()
{
    varCount = 0 ; 
    lcd_init();
    lcd_gotoxy(1,1);
    printf(lcd_putc,"HanAnhTu");
//!    // printf(lcd_putc,"Value = %03d",varCount) ;

    set_tris_b(0xFF);
    port_b_pullups(0xFF);
    
//!    printf(lcd_putc,"btn_UP = %u",input(btn_UP)) ;
//!    printf(lcd_putc,"btn_DOWN = %u",input(btn_DOWN)) ;
//!    printf(lcd_putc,"btn_STP = %u",input(btn_STP));



    while(TRUE) 
    {
        if(input(btn_UP) == 0)
        {
            delay_ms(50);
            varCount++ ; 
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Value = %03d",varCount) ;
            while(input(btn_UP) == 0)
                delay_ms(50);
        }
        else if(input(btn_DOWN) == 0)
        {
            delay_ms(50);
            varCount-- ; 
            if(varCount == -1)
                varCount = 0 ; 
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Value = %03d",varCount) ;
            while(input(btn_DOWN) == 0)
                delay_ms(50);
        }
        else if(input(btn_STP) == 0)
        {
            delay_ms(50);
            varCount = 0 ; 
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Value = %03d",varCount) ;
            while(input(btn_STP) == 0)
                delay_ms(50);
        }
    }
}

