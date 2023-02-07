/* 
 * File:   USART.h
 * Author: Admin
 *
 */

/**
 ******************************************************************************
 * @file            USART.h
 * @author  
 * @brief           header file for PIC18 USART API
 * @brief           This file provides macros and function definitions 
 *                  for PIC18 USART API. 
 * @brief           Supported devices are listed below.
 * @brief           See dependencies in the include section below.
 * 
 * 
 * @note            History:
 *                  - Feb 3, 2023: Initial release
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

#ifndef USART_H
#define	USART_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------  
#include <xc.h> 
#include "PIC18Types.h"
//-----------------------------------
    
/** @defgroup USART_INIT_CONSTANTS USART initialization/configuration constants
 * @{
 * @brief These constants could be used as arguments of the USARTInit(). 
 * See device datasheet for details about the registers associated with each constant group. 
 *  
 */
    
/** @defgroup USART_INIT_CONSTANTS_GROUP1 USART initialization/configuration constants group1
 * @{
 * 
 */         
#define USART_CLK_SRC_BRG                           0x80                //!< Select the Baud Rate Generator (BRG) as clock source (synchronous mode only)
#define USART_CLK_SRC_EXT                           0x00                //!< Select external source as clock source (synchronous mode only)    
#define USART_MODE_TX9                              0x40                //!< Select 9 bits mode for USART transmission
#define USART_MODE_TX8                              0x00                //!< Select 8 bits mode for USART transmission
#define USART_TX_ENABLE                             0x20                //!< Enable transmitter 
#define USART_TX_DISABLE                            0x00                //!< Disable transmitter    
#define USART_MODE_SYNC                             0x10                //!< Select USART synchronous mode
#define USART_MODE_ASYNC                            0x00                //!< Select USART synchronous mode    
#define USART_BR_SPEED_HIGH                         0x04                //!< Select high speed baudrate (asynchronous mode only)
#define USART_BR_SPEED_LOW                          0x00                //!< Select low speed baudrate (asynchronous mode only)
    
/**
  * @}
  */
    
/** @defgroup USART_INIT_CONSTANTS_GROUP2 USART initialization/configuration constants group2
 * @{
 * 
 */         
#define USART_ENABLE                                0x80                //!< Enable serial port
#define USART_DISABLE                               0x00                //!< Enable serial port    
#define USART_MODE_RX9                              0x40                //!< Select 9 bits mode for USART transmission
#define USART_MODE_RX8                              0x00                //!< Select 8 bits mode for USART transmission
#define USART_MODE_SINGLE_RX_ENABLE                 0x20                //!< Enable single reception (synchronous Master mode only)
#define USART_MODE_SINGLE_RX_DISABLE                0x00                //!< Disable single reception (synchronous Master mode only)    
#define USART_RX_ENABLE                             0x10                //!< Enable receiver (asynchronous mode). Enable continous reception (synchronous mode)
#define USART_RX_DISABLE                            0x00                //!< Disable receiver (asynchronous mode). Enable continous reception (synchronous mode)   
#define USART_ADDR_DETECT_ENABLE                    0x08                //!< Enable address detection (asynchronous 9 bits mode only)
#define USART_ADDR_DETECT_DISABLE                   0x00                //!< Disable address detection (asynchronous 9 bits mode only)
    
/**
  * @}
  */ 
               
/**
  * @}
  */

//-----------------------------------    
/**
 * @brief   Enable USART module
 * @param   none   
 * @retval  none
 */    
#define USARTEnable()                               (RCSTA |= 0x80)
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Disable USART module
 * @param   none   
 * @retval  none
 */    
#define USARTDisable()                              (RCSTA &= 0x7F)
//-----------------------------------    
    
//-----------------------------------    
/**
 * @brief   Enable USART transmitter
 * @param   none   
 * @retval  none
 */    
#define USARTTxEnable()                              (RCSTA |= 0x20)
//----------------------------------- 
    
//-----------------------------------    
/**
 * @brief   Disable USART transmitter
 * @param   none   
 * @retval  none
 */    
#define USARTTxDisable()                              (RCSTA &= 0xDF)
//----------------------------------- 

//-----------------------------------    
/**
 * @brief   Enable USART receiver
 * @param   none   
 * @retval  none
 */    
#define USARTRxEnable()                              (RCSTA &= 0x10)
//----------------------------------- 
    
//-----------------------------------    
/**
 * @brief   Disable USART receiver
 * @param   none   
 * @retval  none
 */    
#define USARTRxDisable()                              (RCSTA &= 0xEF)
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Checks whether there is data available in the USART receive buffer
 * @param   none   
 * @retval  none
 */    
#define USARTRxAvailable()                          (PIR1,RCIF)
//-----------------------------------    

//-----------------------------------    
/**
 * @brief   Transmit a byte in 8 bits mode over the USART module
 * @param   data: byte to be transmitted   
 * @retval  none
 * 
 */    
#define USARTTransmitByte(data)                     while(TXSTA,TRMT == 0);\
                                                        TXREG = data;
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Set USART Baud Rate Generator value
 * @param   bgr: Baud Rate Generator value. See calculation below.   
 * @retval  none
 * @note    Equation:
 @verbatim 
                                    FOSC (HZ)            
                           brg =  ------------- - 1, in asynchronous high speed mode. 
                                    16 * BAUD
 
                                    FOSC (HZ)            
                           brg =  ------------- - 1, in asynchronous low speed mode. 
                                    64 * BAUD

                                    FOSC (HZ)            
                           brg =  ------------- - 1, in synchronous mode. 
                                    4 * BAUD
 
 Where: 
        - FOSC (HZ) is the oscillator frequency in hertz
        - BAUD is the desired baudrate in bits/s
        - brg is the byte-sized value (0 - 255} to be loaded in the BRG register 
 See device datasheet for more informations. 
 
 @endverbatim
 * 
 */    
extern void USARTSetBGR(uint8_t bgr);
//----------------------------------- 

//-----------------------------------    
/**
 * @brief   Set USART Baud Rate
 * @param   br: Baud Rate value in bits/s. See usage below.   
 * @retval  none
 * @note    Prior to using this function, make sure to define the global macro FOSC_MHZ, with the MCU crystal frequency in megahertz, in the project settings.
 * @note    In MPLAB X, go to project properties -> XC8 Global Options -> XC8 Compiler -> Define macros.
 * @note    Usage:
 @verbatim void main(void)
            {
            ...
            USARTSetBaudRate(19200);
            ...
            while(1)
            {
            ...
            }
            }
 @endverbatim
 * 
 */    
extern void USARTSetBaudRate(uint32_t baud);
//----------------------------------- 

//-----------------------------------    
/**
 * @brief   Initialize the USART module with the specified configurations.
 * @param   cfg ConfigType variable that contains the group configuration settings, where each group field can only hold group constants of the same number. See usage below.   
 * @retval  none
 * @note    Usage:
 @verbatim void main(void)
            {
            ...
            ConfigType cfg;
            cfg.grp1 = USART_MODE_TX8 | USART_TX_ENABLE | USART_MODE_ASYNC 
                        | USART_BR_SPEED_HIGH;                              // Set USART initialization using setting from USART_INIT_CONSTANTS_GROUP1
            cfg.grp2 = USART_ENABLE | USART_MODE_RX8 | USART_RX_ENABLE;     // Set USART initialization using setting from USART_INIT_CONSTANTS_GROUP2
            cfg.grp3 = 0;                                                   // Ignored 
            cfg.grp4 = 0;                                                   // Ignored
            USARTInit(cfg);
            ...
            while(1)
            {
            ...
            }
            }
 @endverbatim
 * @note See @ref USART_INIT_CONSTANTS. 
 */    
extern void USARTInit(ConfigType cfg);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Initialize the USART module with:
 *              - USART module Enabled
 *              - Asynchronous high speed mode
 *              - 8 bits transmission/reception 
 *              - Transmitter and receiver disabled.
 * @note This is a popular configuration.
 * @param   bgr: Baud Rate Generator value. See USARTSetBGR() for calculation.   
 * @retval  none
 * @note    Usage:
 @verbatim void main(void)
            {
            ...
            USARTAsyncInit(19200);
            ...
            USARTRxEnable();
            USARTTxEnable();
            ...
            while(1)
            {
            ...
            }
            }
 @endverbatim
 * 
 */    
extern void USARTAsyncInit(uint8_t bgr);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Transmit a byte in 9 bits mode over the USART module
 * @param   data: 9-bit value to be transmitted    
 * @retval  none
 * 
 */    
extern void USARTTransmitByte9(uint16_t data);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Transmit an array of bytes in 8 bits mode over the USART module
 * @param   data: byte array to be transmitted 
 * @param   cnt:    number of byte to transmit  
 * @retval  none
 * 
 */    
extern void USARTTransmitBytes(uint8_t *data, uint16_t cnt);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Transmit an array of bytes in 9 bits mode over the USART module
 * @param   data: byte array to be transmitted 
 * @param   cnt:    number of 9-bits values to transmit  
 * @retval  none
 * 
 */    
extern void USARTTransmitBytes9(uint16_t *data, uint16_t cnt);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Sends a char array through the USART module
 * @param   str: string to be transmitted  
 * @retval  none
 * 
 */    
extern void USARTPrint(const char *str);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Get a byte in 8 bits mode from the USART module
 * @param   none  
 * @retval  data received
 * 
 */    
extern uint8_t USARTReceiveByte(void);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Get a byte in 9 bits mode from the USART module
 * @param   none  
 * @retval  data received
 * 
 */    
extern uint16_t USARTReceiveByte9(void);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Get an array of bytes in 8 bits mode from the USART module
 * @param   data: byte array to load the value into 
 * @param   cnt:    number of byte to get 
 * @param   tout: time-out value 
 * @retval  number of byte received
 * 
 */    
extern uint16_t USARTReceiveBytes(uint8_t *data, uint16_t cnt, uint32_t tout);
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Get an array of bytes in 9 bits mode from the USART module
 * @param   data: byte array to load the value into 
 * @param   cnt:    number of byte to get 
 * @param   tout: time-out value 
 * @retval  none
 * 
 */    
extern uint16_t USARTReceiveBytes9(uint16_t *data, uint16_t cnt, uint32_t tout);
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* USART_H */

