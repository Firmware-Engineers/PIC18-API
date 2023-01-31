/*
 * File:   main.c
 * Author: Admin
 *
 */


#include <xc.h>
#include "../Inc/PIC18Types.h"
#include "../Inc/GPIO.h"
#include "../Inc/Interrupts.h"

void main(void) {
    
    //SetPin(GPIOA, _PORTA_RA1_POSN);
    SetOutput(GPIOA, _PORTA_RA0_POSN);
    //SetPort (GPIOA, OUTPUT); 
    //EnableInterrupt(MCU_INT_ENABLE | INT0_INT_ENABLE);
    SetINTxEdgeRising(INT0_INT_EDGE);
    while(1)
    {
        
        
    }
}

