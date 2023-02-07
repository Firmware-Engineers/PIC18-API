/*
 * File:   main.c
 * Author: Admin
 *
 */


#include <xc.h>
#include "../Inc/PIC18Types.h"
#include "../Inc/GPIO.h"
#include "../Inc/Interrupts.h"
#include "../Inc/SystemTime.h"
#include "../Inc/USART.h"

void main(void) {
    SystimeInit();
    GPIOSetOutput(GPIOA, _PORTA_RA0_POSN);
    GPIOClearPin (GPIOA, _PORTA_RA0_POSN);
    ConfigType cfg;
    cfg.grp1 = USART_TX_ENABLE | USART_MODE_ASYNC | USART_BR_SPEED_HIGH;
    cfg.grp2 = USART_ENABLE | USART_RX_ENABLE;
    //USARTAsyncInit(25);
    USARTInit(cfg);
    //USARTSetBGR(25);
    USARTSetBaudRate(9600);
    USARTPrint("Initialization...");
    
    while(1)
    {
        GPIOTogglePin(GPIOA, _PORTA_RA0_POSN);
        Wait_ms(500);
        
    }
}

