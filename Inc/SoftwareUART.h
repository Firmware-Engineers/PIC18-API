/* 
 * File:   SoftwareUART.h
 * Author: Admin
 * 
 */

/**
 ******************************************************************************
 * @file            SoftwareUART.h
 * @author  
 * @brief           header file for PIC18 UART bit banging library
 * @brief           This file provides macros, functions and types definitions 
 *                  for the PIC18 UART bit banging library. 
 * 
 * @note            The current version of this driver has the following characteristics:
 * @note            Supported Oscillator frequencies (in HZ)                  
 *                      - 4000000
 *                      - 8000000
 *                      - 12000000 
 *                      - 16000000
 *                      - 20000000
 *                      - 25000000
 *                      - 40000000                      
 * 
 * @note            Supported baud rates for transmission are:
 *                      - 9600
 *                      - 19200
 *                      - 38400
 *                      - 57600
 *                      - 115200
 *                      - 128000
 * @note            Supported baud rates for reception are:
 *                      - 9600
 *                      - 19200
 *                      - 38400
 *                      - 57600
 * 
 * @note            Communication settings:
 *                      - 8 bits data transmission/reception
 *                      - 1 start, 1 stop bit
 *                      - No parity
 * 
 * @note            Global, peripheral and external interrupts (INTx) are all
 *                  enable to for data reception.
 * 
 * @note            To use the reception functionality, make sure to include the 
 *                  @ref suart_isr() function in the interrupts file (ISR.c).
 * 
 * @attention       Global interrupts are disabled during transmission/reception
 * 
 * @brief           Supported devices are listed below.
 * @brief           See dependencies in the include section below.
 * 
@verbatim
 Library file description:
 
                             --1--  --2-- --3-- --4--  -5-  -6-
                file layout: SUART - v10 - 16 - 9600 - B0 - B1.a
                             
                    1. SUART: Software UART library
                    2. v10: Software version 1.0
                    3. 16: Oscillator frequency  = 16MHZ
                    4. 9600: Baud Rate = 9600
                    5. B0: Reception is configured on PORTB[0] (INT0)
                    6. B3: Transmission is configured on PORTB[3] 
  
@endverbatim
 * 
 * @note            History:
 *                  - Feb 11, 2023: Initial release
 * 
 * @note            It has been successfully tested with:
 *                  - IDEs: 
 *                      * MPLAB X IDE v5.30
 *                  - Compilers: 
 *                      * XC8 V2.36, V1.45
 *                  - Devices: 
 *                      * PIC 18F452
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; </center></h2>
 *
 *
 ******************************************************************************
 */
#ifndef SOFTWAREUART_H
#define	SOFTWAREUART_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include "../../../M8M_APIs/PIC18.X/Inc/GPIO.h"
//-----------------------------------        

/**
 * @brief   Software UART status type
 * 
 */    
typedef union{
    uint8_t Byte;
    struct{
        unsigned Buf:1;                                                         //!< Buffer overflow flag
        unsigned Ferr:1;                                                        //!< Frame error flag
        unsigned:6;                                                             //!< Reserved
    };
}SoftUARTStatusType;

//-----------------------------------    
/**
 * @brief        Initialize the software UART driver
 * @parameter    None
 * @returnValue  None 
 * 
 */
extern void SoftUARTInit(void);                                                                                 
//-----------------------------------

//-----------------------------------    
/**
 * @brief        Checks whether there is data available in the receive buffer 
 * @parameter    None
 * @returnValue     - 0: No data in the buffer
 *                  - 1: Data present in the buffer
 * 
 */
extern uint8_t SoftUARTRxAvailable(void);                                                                                 
//-----------------------------------

//-----------------------------------    
/**
 * @brief        Transmit a byte
 * @parameter    data: Data to be transmitted
 * @returnValue  None 
 * 
 */
extern void SoftUARTTransmitByte(uint8_t data);                                                                                 
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Receive a byte
 * @param   none  
 * @retval      - byte received
 *              - -1: Buffer empty, no data available
 * 
 */    
extern int SoftUARTReceiveByte(void);
//-----------------------------------

//-----------------------------------    
/**
 * @brief        Transmit an array of bytes
 * @param   data: data to be transmitted
 * @param   cnt: number of byte to transmit
 * @returnValue  None 
 * 
 */
extern void SoftUARTTransmitBytes(uint8_t *data, uint16_t cnt);                                                                                 
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Receive an array of bytes
 * @param   data: byte array to load the value into 
 * @param   cnt: number of byte to get 
 * @param   tout: time-out value 
 * @retval  number of byte received
 * 
 */    
extern uint16_t SoftUARTReceiveBytes(uint8_t *data, uint16_t cnt, uint32_t tout);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Sends a char array through the USART module
 * @param   str: string to be transmitted  
 * @retval  none
 * 
 */    
extern void SoftUARTPrint(const char *str);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Suspend software UART driver operations
 * @param   none 
 * @retval  none
 * 
 */    
extern void SoftUARTSuspend(void);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Resume software UART driver operations
 * @param   none 
 * @retval  none
 * 
 */    
extern void SoftUARTResume(void);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Flush software UART receive buffer
 * @param   none 
 * @retval  none
 * 
 */    
extern void SoftUARTFlushRx(void);
//-----------------------------------

#pragma intrinsic(_suart_isr)                   //!< Inline directive
extern void suart_isr(void);


#ifdef	__cplusplus
}
#endif

#endif	/* SOFTWAREUART_H */

