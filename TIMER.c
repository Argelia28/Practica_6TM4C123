
#include "lib/include.h"
extern void TIMER_CONFIGURACION (int f_clk, int seg){
    SYSCTL-> RCGCGPIO |= (1<<5); //PUERTO F
    GPIOF -> AFSEL &= ~(1<<2); //desactivar
    GPIOF -> DIR = (1<<2); //PIN F2
    GPIOF -> DEN = (1<<2);
    GPIOF -> DATA = (1<<2); //ENCENDER LED AZUL

    SYSCTL->RCGCTIMER |= (1<<0); //16 o 32 bits

    TIMER0 -> CTL &= ~(1<<0);
    TIMER0 -> CFG = 0X00000000;
    TIMER0 -> TAMR |= (0X2<<0); //Modo periodico
    TIMER0 -> TAMR &= ~(1<<4); //modo countdown
    TIMER0 -> TAILR = f_clk/seg; //f_clk*seg
    TIMER0 -> CTL |= (1<<0);

    

}