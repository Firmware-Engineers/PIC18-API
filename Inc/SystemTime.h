/**
 ******************************************************************************
 * @file            SystemTime.h
 * @author  		Maxime
 * @brief           header file for PIC18 System Time library
 * @brief           This library provides common time management function for
 *                  microcontroller applications. It makes use of one of the
 *                  available microcontroller hardware timers as time generation
 *                  engine.
 * 
 * @note            This library uses the device's timer 0 for its operations. Therefore, 
 *                  the same timer must not be used when this library is in operation,  
 *                  to prevent unpredictable behaviors.
 * 
 * @note            Device oscillator frequency can be adjusted depending on the 
 *                  application, by modifying the @ref OSC_FREQ constant value.
 *                
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
 *                      * XC8 V2.36
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

#ifndef SYSTEMTIME_H
#define	SYSTEMTIME_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------  
#include <xc.h> 
#include <stdint.h>
//-----------------------------------  
    
//-----------------------------------
const uint8_t OSC_FREQ = 4;                                                    //!< Change this value to the device oscillator frequency in megahertz. Maximum value is 40
//-----------------------------------   
    
//-----------------------------------
/**
 * @brief        Initialize the System Time library  
 * @param       none
 * @retval      none
 * 
 * 
 * @note         The timer 0 is configured as follow:
 *               - The timer increment on every internal clock cycle
 *               - Timer prescaler is assigned to timer 0
 *               - "Timer mode" of operation is selected
 * 
 */    
extern void SystimeInit(void);
//-----------------------------------

//-----------------------------------
/**
 * @brief       Give the amount of time elapsed, in milliseconds, since the last hardware reset  
 * @param       none
 * @retval      amount of time elapsed in milliseconds.
 * 
 */    
extern uint32_t Tick_ms(void);
//-----------------------------------

//-----------------------------------
/**
 * @brief       Give the amount of time elapsed, in microseconds, since the last hardware reset  
 * @param       none
 * @retval      amount of time elapsed in microseconds.
 * 
 */    
extern uint32_t Tick_us(void);
//-----------------------------------

//-----------------------------------
/**
 * @brief       Blocks the program for a given time in milliseconds 
 * @param       none
 * @retval      none
 * 
 */    
extern void Wait_ms(uint32_t value);
//-----------------------------------

//-----------------------------------
/**
 * @brief       Call-back function for the System Time library, to be place inside the interrupt service routines.
 *              See ISR.c file.  
 * @param       none
 * @retval      none
 * 
 */    
extern void SysTimeCallBack(void);
//-----------------------------------

//-----------------------------------
/**
 * @brief       Suspend System Time operations 
 * @param       none
 * @retval      none
 * @note        This will deactivate the timer used by the library and therefore time management functions such as Tick_ms().
 * 
 */    
extern void SysTimeSuspend(void);
//-----------------------------------

//-----------------------------------
/**
 * @brief       Resume System Time operations 
 * @param       none
 * @retval      none
 * @note        This will reactivate the timer used by the library, re-enabling the 
 *              usage of Time management functions.
 * 
 */    
extern void SysTimeResume(void);
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEMTIME_H */

