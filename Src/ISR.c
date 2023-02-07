/**
 ******************************************************************************
 * @file            ISR.c
 * @author          Maxime (FI)  
 * @brief           Source file for 8 bits PIC18 MCUs interrupt Service Routines
 * @brief           See MPLAB XC8 C Compiler User Guide for more details
 * @note            This file is optional, the ISR functions can be declared
 *                  in any source file, just make sure to declare that function 
 *                  only once and to deactivate/remove this file from the active
 *                  project.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; </center></h2>
 *
 *
 ******************************************************************************
 */

//-----------------------------------
#include "../Inc/Interrupts.h"
#include "../Inc/GPIO.h"
#include "../Inc/SystemTime.h"
//-----------------------------------

#if defined(USE_HIGH_LOW_ISR)

//-----------------------------------    
/**
 * @brief   High priority Interrupt Service Routine function
 * @param   none   
 * @retval  none
 * @note    All interrupt code to be executed in high priority mode (address 0x18) must be placed here 
 */
void high_priority interrupt HighIsr(void)
{
    
}
//-----------------------------------

//-----------------------------------    
/**
 * @brief   High priority Interrupt Service Routine function
 * @param   none   
 * @retval  none
 * @note    All interrupt code to be executed in low priority mode (address 0x08) must be placed here 
 */
void low_priority interrupt LowIsr(void)
{
    
}
//-----------------------------------

#else

//-----------------------------------    
/**
 * @brief   High priority Interrupt Service Routine function
 * @param   none   
 * @retval  none
 * @note    All interrupt code to be executed in midrange compatibility mode (address 0x08) must be placed here 
 */
void interrupt Isr(void)
{
    SysTimeCallBack();
}
//-----------------------------------

#endif