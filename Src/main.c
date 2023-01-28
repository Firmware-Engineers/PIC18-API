/*
 * File:   main.c
 * Author: Admin
 *
 * Created on January 24, 2023, 10:28 AM
 */


#include <xc.h>
#include "../Common/PIC18Types.h"
#include "../CDP/GPIO.h"

void main(void) {
    
    //SetPin(GPIOA, _PORTA_RA1_POSN);
    SetOutput(GPIOA, _PORTA_RA1_POSN);
    SetPort (GPIOA, OUTPUT);
    while(1)
    {
        
    }
}

