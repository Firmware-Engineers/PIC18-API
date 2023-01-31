/**
 ******************************************************************************
 * @file            PIC18Types.h
 * @author          Maxime (FI)  
 * @brief           header file for 8 bits PIC18 MCUs types and constants
 * @brief           This file provides constants, macros
 *                  and custom type definitions common to all PIC18 APIs.
 * 
 * 
 * @note            History:
 *                   - Jan 24, 2023: Initial release
 * 
 * @note            It has been successfully tested with:
 *                  IDE: 
 *                      - MPLAB X IDE v5.30
 *                  Compiler: 
 *                      - XC8 V1.45
 *                  Devices: 
 *                      - PIC 18F452
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; </center></h2>
 *
 *
 ******************************************************************************
 */

#ifndef PIC18TYPES_H
#define	PIC18TYPES_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------    
#include <stdint.h>
//-----------------------------------

/** @defgroup GPIO_TYPES 
 * General Purpose Input/Output Definitions
* @{
*/ 

/** @defgroup IO_PORT_CONSTANTS I/O port constants definition
 * @{
 * @brief These constants could be used as arguments for the GPIO API
 */    
#define GPIOA                               0x00    //!< GPIO PORT A   
#define GPIOB                               0x01    //!< GPIO PORT B     
#define GPIOC                               0x02    //!< GPIO PORT C
#define GPIOD                               0x03    //!< GPIO PORT D    
#define GPIOE                               0x04    //!< GPIO PORT E      
/**
  * @}
  */
         
#define GPIO_BASE                           0xF80   //!< I/O registers base address    



/** @defgroup IO_ADDRESS_OFFSET I/O addresses offset definition
  * @{
  */    
#define IO_LATCH_OFFSET                     9       //!< I/O LATCH register offset
#define IO_TRIS_OFFSET                      18      //!< I/O TRIS register offset 
#define IO_PORT_OFFSET                      0       //!< I/O PORT register offset
/**
  * @}
  */

/**
  * @brief  I/O registers memory map type
  */    
typedef union{
    struct{
        //---------        
        uint8_t PA;                                 //!< I/O PORTA register: address [@ref GPIO_BASE + @ref IO_PORT_OFFSET]
        uint8_t PB;                                 //!< I/O PORTB register: address [@ref GPIO_BASE + @ref IO_PORT_OFFSET + 1]
        uint8_t PC;                                 //!< I/O PORTC register: address [@ref GPIO_BASE + @ref IO_PORT_OFFSET + 2]
        uint8_t PD;                                 //!< I/O PORTD register: address [@ref GPIO_BASE + @ref IO_PORT_OFFSET + 3]
        uint8_t PE;                                 //!< I/O PORTE register: address [@ref GPIO_BASE + @ref IO_PORT_OFFSET + 4]        
        //---------
        uint32_t;
        //---------
        uint8_t LA;                                 //!< I/O LATCHA register: address [@ref GPIO_BASE + @ref IO_LATCH_OFFSET]
        uint8_t LB;                                 //!< I/O LATCHB register: address [@ref GPIO_BASE + @ref IO_LATCH_OFFSET + 1] 
        uint8_t LC;                                 //!< I/O LATCHC register: address [@ref GPIO_BASE + @ref IO_LATCH_OFFSET + 2]
        uint8_t LD;                                 //!< I/O LATCHD register: address [@ref GPIO_BASE + @ref IO_LATCH_OFFSET + 3]
        uint8_t LE;                                 //!< I/O LATCHE register: address [@ref GPIO_BASE + @ref IO_LATCH_OFFSET + 4]                                         
        //---------
        uint32_t;
        //---------
        uint8_t TA;                                 //!< I/O TRISA register: address [@ref GPIO_BASE + @ref IO_TRIS_OFFSET]
        uint8_t TB;                                 //!< I/O TRISA register: address [@ref GPIO_BASE + @ref IO_TRIS_OFFSET + 1]
        uint8_t TC;                                 //!< I/O TRISA register: address [@ref GPIO_BASE + @ref IO_TRIS_OFFSET + 2] 
        uint8_t TD;                                 //!< I/O TRISA register: address [@ref GPIO_BASE + @ref IO_TRIS_OFFSET + 3]
        uint8_t TE;                                 //!< I/O TRISA register: address [@ref GPIO_BASE + @ref IO_TRIS_OFFSET + 4]        
    };
    uint8_t Bytes[23];
}IORegistersMapType;
//----------------------

volatile IORegistersMapType IO              @GPIO_BASE;
#define GPIO                                IO
/** @} */


/** @defgroup GENERIC_CONSTS 
  * @{
  */    
#define TRUE                                1       //!<
#define FALSE                               0       //< 
#define INPUT                               1       //!< 
#define OUTPUT                              0       //!<  
/**
  * @}
  */ 

#ifdef	__cplusplus
}
#endif

#endif	/* PIC18TYPES_H */

