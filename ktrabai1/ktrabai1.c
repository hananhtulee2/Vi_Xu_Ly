#include <16F887.h>
#fuses INTRC_IO
#use delay(CLOCK=8MHz)

#define btnON_OFF PIN_B0
#define btnMODE    PIN_B1

int8 i, j, k, mode = 0;

int8 RD5_RD0[6]={0b00100000,0b00010000,0b00001000,0b00000100,0b00000010,0b00000001};
int8 RC7_RC3[5]={0b10000000,0b01000000,0b00100000,0b00010000,0b00001000};

void main()
{
    set_tris_b(0b00000011);
    set_tris_c(0b00000000);
    set_tris_d(0b00000000);

    while(TRUE)
    {
        if(input(btnON_OFF) == 0) {
            delay_ms(50);
            if(mode == 0) {
                mode = 1; // m?ch ch?y
            }
            else {
                mode = 0; // m?ch d?ng
                output_c(0x00);
                output_d(0x00);
            }
            while(input(btnON_OFF) == 0);
            delay_ms(50);
        }
        
        if(input(btnMODE) == 0) {
            delay_ms(50);
            mode++;
            if(mode == 1) { // t?t 16 led
                output_c(0x00);
                output_d(0x00);
            }
            else if(mode == 2) { // sáng d?n r?i t?t d?n 16 led, l?p l?i 4 l?n
                for(k = 0; k < 4; k++) {
                    for(i = 0; i < 6; i++) {
                        output_c(RD5_RD0[i]);
                        output_d(RD5_RD0[i]);
                        delay_ms(50);
                    }
                    for(j = 0; j < 5; j++) {
                        output_c(RC7_RC3[j]);
                        output_d(RC7_RC3[j]);
                        delay_ms(50);
                    }
                }
            }
            else if(mode == 3) { // ði?m sáng d?ch 16 led t? trên xu?ng và t? dý?i lên, l?p l?i 4 l?n
                for(k = 0; k < 4; k++) {
                    for(i = 0; i < 8; i++) {
                        output_c(1 << i);
                        output_d(1 << i);
                        delay_ms(50);
                    }
                    for(j = 0; j < 8; j++) {
                        output_c(0x80 >> j);
                        output_d(0x80 >> j);
                        delay_ms(50);
                    }
                }
            }
            else if(mode == 4) { // quay l?i mode 1
                mode = 1;
            }
            while(input(btnMODE) == 0);
            delay_ms(50);
        }
    }
}
