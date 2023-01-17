#include "lib/include.h"

int main(void)
{
    int8_t word[2];
    uint16_t count = 0;

    Configurar_PLL(_20MHZ);  //Confiuracion de velocidad de reloj 50MHZ
    Configurar_GPIO();
    Configurar_UART0();
    Configurar_SSI2();
    TIMER_CONFIGURACION(1,20000000);
    while(1){
        if((TIMER0 -> RIS & 0x00000001) == 1){
            TIMER0 -> ICR |= (1<<0);
            GPIOF -> DATA ^= (1<<2);
        }
    }
}

