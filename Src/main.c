/*
 * File:   main.c
 * Author: Admin
 *
 */


#include <xc.h>
#include "../Inc/PIC18Types.h"
#include "../Inc/GPIO.h"
#include "../Inc/Interrupts.h"
//#include "../Inc/SystemTime.h"
#include "../../../Libraries/SystemTime.X/Inc/SystemTime.h"
#include "../Inc/USART.h"
#include "../Inc/SoftwareUART.h"

void main(void) {
    
    SystimeInit();
    GPIOClearPin(GPIOA, 0);
    GPIOSetOutput(GPIOA, 0);
    GPIOClearPin(GPIOB, 4);
    GPIOSetOutput(GPIOB, 4);
    
    SoftUARTInit();
    SoftUARTPrint("Hello World!\r");
    SoftUARTPrint("This is a software UART library test!\r");
    SoftUARTPrint("Designed by Firmware Engineer Team. Copyright 2023.\r");
    SoftUARTPrint("\r\r");
    SoftUARTPrint("Freely available source code on GitHub (https://github.com/Firmware-Engineers/PIC18-API)\r");
    
    while(1)
    {
        GPIOTogglePin(GPIOA, 0);
        Wait_ms(500);
    }
}

