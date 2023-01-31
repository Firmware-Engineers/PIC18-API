/* 
 * File:   GPIO.h
 * Author: Admin
 *
 * Created on January 24, 2023, 1:48 PM
 */


/**
 ******************************************************************************
 * @file            GPIO.h
 * @author  
 * @brief           header file for PIC18 I/O API
 * @brief           This file provides macros and function definitions 
 *                  for PIC18 I/O API. Supported devices are listed below.
 * 
 * 
 * @note            History:
 *                  - Jan 24, 2023: Initial release
 * 
 * @note            It has been successfully tested with:
 *                  - IDEs: 
 *                      * MPLAB X IDE v5.30
 *                  - Compilers: 
 *                      * XC8 V1.45
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

#ifndef GPIO_H
#define	GPIO_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------
#include "../Inc/PIC18Types.h"
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Configures a given I/O pin to output 
 * @param   PORT: The I/O port name constant (See IO_PORT_CONSTANTS in PIC18Type.h)
 * @param   PIN: The pin to configure on the given I/O port (see pic18fxxx.h file)
 * @retval  None
 * @note    Example: SetOutput(GPIOA, _PORTA_RA0_POSN);     // Will set PORTA, bit 0 as output.
 *          
 */     
#define SetOutput(PORT, PIN)                GPIO.Bytes[(uint8_t)PORT + IO_TRIS_OFFSET] &= ~(1 << PIN)
//-----------------------------------

//-----------------------------------
/**
 * @brief   Configures a given I/O pin to input 
 * @param   PORT: The I/O port name constant (See IO_PORT_CONSTANTS in PIC18Type.h)
 * @param   PIN: The pin to configure on the given I/O port (see pic18fxxx.h file)
 * @retval  None
 * @note    Example: SetInput(GPIOA, _PORTA_RA0_POSN);      // Will set PORTA, bit 0 as input.
 */     
#define SetInput(PORT, PIN)                 (GPIO.Bytes[PORT + IO_TRIS_OFFSET] |= (1 << PIN))
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Configure I/O port direction  
 * @param   PORT: The I/O port name constant (See IO_PORT_CONSTANTS in PIC18Type.h)
 * @param   DIR: The direction setting
 * @retval  None
 * @note    The DIR parameter is a 8 bit value, with '1' and '0' configuring the specified PORT
 *          as respectively "INPUT" and "OUTPUT"
 * @note    Example: SetPort(GPIOA, 0x03);                  // Will set bits 0 and 1 as input, bits 2 to 7 as output on PORTA. 
 */    
#define SetPort(PORT, DIR)                   GPIO.Bytes[PORT + IO_TRIS_OFFSET] = DIR
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Sets the given I/O pin to logic '1'
 * @param   PORT: The I/O port name constant (See IO_PORT_CONSTANTS in PIC18Type.h)
 * @param   PIN: The pin to set on the given I/O port (see pic18fxxx.h file)
 * @retval  None
 * @note    Example: SetPin(GPIOA, _PORTA_RA0_POSN);        // Will set PORTA, bit 0 to '1'.
 */     
#define SetPin(PORT, PIN)                   GPIO.Bytes[PORT + IO_LATCH_OFFSET] |= (1 << PIN)
//-----------------------------------   

//-----------------------------------    
/**
 * @brief   Sets the given I/O pin to logic '0' 
 * @param   PORT: The I/O port name constant (See IO_PORT_CONSTANTS in PIC18Type.h)
 * @param   PIN: The pin to clear on the given I/O port (see pic18fxxx.h file)
 * @retval  None
 * @note    Example: ClearPin(GPIOA, _PORTA_RA0_POSN);      // Will set PORTA, bit 0 to '0'.
 */    
#define ClearPin(PORT, PIN)                 GPIO.Bytes[PORT + IO_LATCH_OFFSET] &= (~(1 << PIN))
//-----------------------------------

//----------------------------------- 
/**
 * @brief   Toggles the I/O pin state, from '0' to '1' and vise versa 
 * @param   PORT: The I/O port name constant (See IO_PORT_CONSTANTS in PIC18Type.h)
 * @param   PIN: The pin to toggle on the given I/O port (see pic18fxxx.h file)
 * @retval  None
 * @note    Example: TogglePin(GPIOA, _PORTA_RA0_POSN);     // Will toggle PORTA, bit 0 state.
 */     
#define TogglePin(PORT,PIN)                 GPIO.Bytes[PORT + IO_LATCH_OFFSET] ^= (1 << PIN)   
//-----------------------------------

//-----------------------------------
/**
 * @brief   Gets the given I/O pin logic state
 * @param   PORT: The I/O port name constant (See IO_PORT_CONSTANTS in PIC18Type.h)
 * @param   PIN: The pin to read the state from (see pic18fxxx.h file)
 * @retval  0 or 1 
 * @note    Example: uint8_t state = GetPin(GPIOA, _PORTA_RA0_POSN);
 */    
#define GetPin(PORT,PIN)                    (uint8_t)((GPIO.Bytes[PORT + IO_PORT_OFFSET] >> PIN) & 0x01)
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Writes a value to a I/O port 
 * @param   PORT: The I/O port name constant (See IO_PORT_CONSTANTS in PIC18Type.h)
 * @param   VALUE: The byte-sized value to write
 * @retval  None
 * @note    Example: WritePort(GPIOA, 0);                   // Will write the value 0 to PORTA 
 */    
#define WritePort(PORT, VALUE)              GPIO.Bytes[PORT + IO_LATCH_OFFSET] = VALUE
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Gets the I/O port state
 * @param   PORT   : The I/O port name constant (See IO_PORT_CONSTANTS in PIC18Type.h)
 * @retval  VALUE  : Value read from the port
 * @note    Example: uint8_t value = ReadPort(GPIOA, 0);    // Will read the PORTA pins states
 */    
#define ReadPort(PORT)                      (uint8_t)(GPIO.Bytes[PORT + IO_PORT_OFFSET])
//-----------------------------------        
    
//-----------------------------------    
/**
 * @brief   Enable PORTB pull-ups
 * @param   none   
 * @retval  none
 */    
#define RBPUEnable()                        (INTCON2 = INTCON2 & 0x7F)
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Disable PORTB pull-ups
 * @param   none   
 * @retval  none
 */    
#define RBPUDisable()                       (INTCON2 = INTCON2 | 0x80)
//-----------------------------------    
    
#ifdef	__cplusplus
}
#endif

#endif	/* GPIO_H */

