/**
 ******************************************************************************
 * @file            Interrupts.h
 * @author          Maxime (FI)  
 * @brief           header file for 8 bits PIC18 MCUs interrupt management API
 * @brief           This file provides constants, macros
 *                  and function definitions for PIC18 interrupt APIs.
 * 
 * 
 * @note            History:
 *                   - Jan 28, 2023: Initial release
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
#ifndef INTERRUPTS_H
#define	INTERRUPTS_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------  
#include <xc.h> 
#include "PIC18Types.h"
//-----------------------------------

/** @defgroup INTERRUPT_PRIORITY_CONFIG Enable high/low priority ISRs
 * @{
 * 
 */         
//#define USE_HIGH_LOW_ISR                                                //!< Comment this line if you don't want to use high/low pririty Interrupt Service Routines    
/**
  * @}
  */
    
/** @defgroup INTERRUPT_EN_DIS_CONSTANTS Interrupt enable/disable constants
 * @{
 * @brief These constants could be used as arguments of the EnableInterrupt() and DisableInterrupt() functions. 
 * See device datasheet for details about the registers associated with each constant group. 
 *  
 */
    
/** @defgroup INTERRUPT_EN_DIS_CONSTANTS_GROUP1 Interrupt enable/disable constants group1
 * @{
 * 
 */         
#define MCU_INT_ENABLE                              0x80                //!< Enable/disable global interrupts
#define PERIPHERAL_INT_ENABLE                       0x40                //!< Enable/disable peripheral interrupts   
#define TMR0_OVF_INT_ENABLE                         0x20                //!< Enable/disable timer 0 overflow interrupt
#define INT0_INT_ENABLE                             0x10                //!< Enable/disable external interrupt 0
#define PORTB_CHANGE_INT_ENABLE                     0x08                //!< Enable/disable PORTB[7:4] change interrupt
    
/**
  * @}
  */
    
/** @defgroup INTERRUPT_ENABLE_CONSTANTS_GROUP2 Interrupt enable/disable constants group2
 * @{
 * 
 */          
#define INT1_INT_ENABLE                             0x80                //!< Enable/disable external interrupt 1   
#define INT2_INT_ENABLE                             0x01                //!< Enable/disable external interrupt 2
/**
  * @}
  */ 
    
/** @defgroup INTERRUPT_ENABLE_CONSTANTS_GROUP3 Interrupt enable/disable constants group3
 * @{
 * 
 */          
#define PSP_RW_INT_ENABLE                           0x80                //!< Enable/disable Paralel Slave Port Read/Write interrupt   
#define ADC_INT_ENABLE                              0x40                //!< Enable/disable Analog/Digital converter interrupts
#define USART_RX_INT_ENABLE                         0x20                //!< Enable/disable USART receive interrupt
#define UART_TX_INT_ENABLE                          0x10                //!< Enable/disable USART transmit interrupt 
#define MSSP_INT_ENABLE                             0x08                //!< Enable/disable Master Synchronous Serial Port (MSSP) interrupt
#define CCP1_INT_ENABLE                             0x04                //!< Enable/disable Capture/Compare/PWM 1 (CCP1) interrupt
#define TMR2_PR2_INT_ENABLE                         0x02                //!< Enable/disable Timer 2 tà PR2 match interrupt
#define TMR1_OVF_INT_ENABLE                         0x01                //!< Enable/disable Timer 1 overflow interrupt
/**
  * @}
  */
    
/** @defgroup INTERRUPT_ENABLE_CONSTANTS_GROUP4 Interrupt enable/disable constants group4
 * @{
 * 
 */          
#define EE_FLASH_WRITE_INT_ENABLE                   0x01                //!< Enable/disable Data EEPROM/FLASH Write Operation Interrupt  
#define BCL_INT_ENABLE                              0x08                //!< Enable/disable Bus Collision Interrupt
#define LVD_INT_ENABLE                              0x04                //!< Enable/disable Low Voltage Detect Interrupt
#define TMR3_INT_ENABLE                             0x02                //!< Enable/disable Timer 3 overflow interrupt 
#define CCP2_INT_ENABLE                             0x01                //!< Enable/disable Capture Compare PWM 2 (CCP2) interrupt
/**
  * @}
  */    
    
    
/**
  * @}
  */    
    
/** @defgroup INTERRUPT_FLAG_CONSTANTS Interrupt flag constants
 * @{
 * @brief These constants could be used as arguments for the GetInterruptFlag() function
 */ 
    
/** @defgroup INTERRUPT_FLAG_CONSTANTS_GROUP1 Interrupt flag constants group1
 * @{
 * @brief These constants could be used as arguments for the GetInterruptFlag() function
 */     
#define TMR0_OVF_INT_FLAG                           0x04                //!< Timer 0 overflow interrupt flag
#define INT0_INT_FLAG                               0x02                //!< External interrupt 0 flag 
#define PORTB_INTCHANGE_FLAG                        0x01                //!< PORTB[7:4] change interrupt flag    
/**
  * @}
  */ 
    
/** @defgroup INTERRUPT_FLAG_CONSTANTS_GROUP2 Interrupt flag constants group2
 * @{
 * @brief These constants could be used as arguments for the GetInterruptFlag() function
 */     
#define INT1_INT_FLAG                               0x0102          //!< External interrupt 1 flag
#define INT2_INT_FLAG                               0x0101          //!< External interrupt 2 flag     
/**
  * @}
  */     
    
/** @defgroup INTERRUPT_FLAG_CONSTANTS_GROUP3 Interrupt flag constants group3
 * @{
 * @brief These constants could be used as arguments for the GetInterruptFlag() function
 */     
#define PSP_RW_INT_FLAG                             0x0280          //!< Paralel Slave Port FLAG   
#define ADC_INT_FLAG                                0x0240          //!< Analog/Digital Converter FLAG
#define USART_RX_INT_FLAG                           0x0220          //!< USART receive interrupt flag
#define UART_TX_INT_FLAG                            0x0201          //!< USART transmit interrupt flag
#define MSSP_INT_FLAG                               0x0208          //!< Master Synchronous Serial Port interrupt flag
#define CCP1_INT_FLAG                               0x0204          //!< Capture/Compare/PWM 1 interrupt flag
#define TMR2_PR2_INT_FLAG                           0x0202          //!< Timer 2 to PR2 match interrupt flag
#define TMR1_OVF_INT_FLAG                           0x0201          //!< Timr 1 overflow interrupt flag    
/**
  * @}
  */ 
    
/** @defgroup INTERRUPT_FLAG_CONSTANTS_GROUP4 Interrupt flag constants group4
 * @{
 * @brief These constants could be used as arguments for the GetInterruptFlag() function
 */     
#define EE_FLASH_WRITE_INT_FLAG                     0x0310          //!< EEPROM/FLASH Write interrupt flag  
#define BCL_INT_FLAG                                0x0308          //!< Bus Collision Interrupt flag
#define LVD_INT_FLAG                                0x0304          //!< Low Voltage Detect Interrupt flag
#define TMR3_INT_FLAG                               0x0302          //!< Timer 3 overflow interrupt  flag
#define CCP2_INT_FLAG                               0x0301          //!< Capture Compare PWM 2 interrupt flag  
/**
  * @}
  */     
    
    
/**
  * @}
  */    

/** @defgroup INTX_EDGE_SELECT_CONSTANTS External interrupt edge select constants
 * @{
 * @brief These constants could be used as arguments for the SetINTxEdgeRising() and SetINTxEdgeFalling() functions
 */     
#define INT0_INT_EDGE                               0x40                //!< INT0 interrupt edge  
#define INT1_INT_EDGE                               0x20                //!< INT1 interrupt edge 
#define INT2_INT_EDGE                               0x10                //!< INT2 interrupt edge     
/**
  * @}
  */ 
    
/** @defgroup INTERRUPT_PRIORITY_CONSTANTS Interrupt priority select constants
 * @{
 * @brief These constants could be used as arguments for the SetINTPriorityHigh(), SetINTPriorityLow() functions
 */ 

/** @defgroup INTERRUPT_PRIORITY_CONSTANTS_GROUP1 Interrupt priority constants group1
 * @{
 * 
 */     
#define TMRO_INT_PRIORITY                           0x04                //!< Timer 0 interrupt priority   
#define PORTB_CHANGEZ_INT_PRIORITY                  0x01                //!< PORTB change interrupt priority 
/**
  * @}
  */
    
/** @defgroup INTERRUPT_PRIORITY_CONSTANTS_GROUP2 Interrupt priority constants group2
 * @{
 * 
 */     
#define INT1_INT_PRIORITY                           0x40                //!< INT1 interrupt priority 
#define INT2_INT_PRIORITY                           0x80                //!< INT1 interrupt priority
/**
  * @}
  */

/** @defgroup INTERRUPT_PRIORITY_CONSTANTS_GROUP3 Interrupt priority constants group3
 * @{
 * 
 */     
#define PSP_INT_PRIORITY                            0x80                //!< Paralel Slave Port interrupt priority 
#define ADC_INT_PRIORITY                            0x40                //!< Analog/Digital Converter interrupt priority
#define USART_RX_INT_PRIORITY                       0x20                //!< USART Receive interrupt priority
#define USART_TX_INT_PRIORITY                       0x10                //!< USART Transmit interrupt priority
#define MSSP_INT_PRIORITY                           0x08                //!< Master Synchronous Serial Port interrupt priority
#define CCP1_INT_PRIORITY                           0x04                //!< Capture/Compare/PWM 1 (CCP1) interrupt priority
#define TMR2_INT_PRIORITY                           0x02                //!< Timer 2 to PR2 match interrupt priority
#define TMR1_INT_PRIORITY                           0x01                //!< Timer 1 overflow interrupt priority    
/**
  * @}
  */ 
    
/** @defgroup INTERRUPT_PRIORITY_CONSTANTS_GROUP4 Interrupt priority constants group4
 * @{
 * 
 */     
#define EE_FLASH_INT_PRIORITY                       0x10                //!< EEPROM/FLASH write interrupt priority 
#define BCL_INT_PRIORITY                            0x08                //!< Bus Collision interrupt priority
#define LVD_INT_PRIORITY                            0x04                //!< Low Voltage Detect interrupt priority
#define TMR3_INT_PRIORITY                           0x02                //!< Timer 3 overflow interrupt priority
#define CCP2_INT_PRIORITY                           0x01                //!< Capture/Compare/PWM 2 (CCP2) interrupt priority   
/**
  * @}
  */     
    
/**
  * @}
  */     
    
//-----------------------------------    
/**
 * @brief   Enable all interrupts
 * @param   none
 * @note    With interrupt priority enabled, this macro will enable all high-priority interrupts.
 *          Otherwise, it will enable all unmasked interrupts.   
 * @retval  none
 */    
#define MCUInterruptEnable()                        ei()
//----------------------------------- 
    
//-----------------------------------    
/**
 * @brief   Disable all interrupts
 * @param   none   
 * @retval  none
 */    
#define MCUInterruptDisable()                       di()
//-----------------------------------     

//-----------------------------------    
/**
 * @brief   Enable all peripheral interrupts
 * @param   none
 * @note    With interrupt priority enabled, this macro will enable all low-priority interrupts.
 *          Otherwise, it will enable all unmasked peripheral interrupts.   
 * @retval  none
 */    
#define PeripheralInterruptEnable()                 (INTCON = INTCON | 0x40)
//----------------------------------- 
    
//-----------------------------------    
/**
 * @brief   Disable all peripheral interrupts
 * @param   none   
 * @retval  none
 */    
#define PeripheralInterruptDisable()                (INTCON = INTCON & 0xB0)
//----------------------------------- 
    
//-----------------------------------    
/**
 * @brief   Enable interrupt priority
 * @param   none   
 * @retval  none
 */    
#define InterruptPriorityEnable()                   (RCON = RCON | 0x80)
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Enable interrupt priority
 * @param   none   
 * @retval  none
 */    
#define InterruptPriorityDisable()                  (RCON = RCON & 0x80)
//----------------------------------- 

/**
 * @brief   Set external interrupts edge to rising
 * @param   One or more of @ref INTX_EDGE_SELECT_CONSTANTS   
 * @retval  none
 * @note    
 *          - Example1: SetINTxEdgeRising(INT0_INT_EDGE | INT1_INT_EDGE); // Will set external interrupt edge for inputs 0 and 1 to rising. 
 *          - Example2: SetINTxEdgeRising(INT0_INT_EDGE); // Will set external interrupt edge for input 0 to rising.
 */    
#define INTxSetEdgeRising(cnst)                     (INTCON2 |= cnst)
//-----------------------------------

//-----------------------------------    
/**
 * @brief   Set external interrupts edge to falling
 * @param   One or more of @ref INTX_EDGE_SELECT_CONSTANTS   
 * @retval  none
 * @note    
 *          - Example1: SetINTxEdgeFalling(INT0_INT_EDGE | INT1_INT_EDGE); // Will set external interrupt edge for inputs 0 and 1 to falling. 
 *          - Example2: SetINTxEdgeFalling(INT0_INT_EDGE); // Will set external interrupt edge for input 0 to falling.
 */    
#define INTxSetEdgeFalling(cnst)                    INTCON2 &= (uint8_t)(~cnst)
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Enable specified interrupts
 * @param   cfg ConfigType variable that contains the group configuration settings, where each group field can only hold group constants of the same number. See usage below.   
 * @retval  none
 * @note    Usage:
 @verbatim void main(void)
            {
            ...
            ConfigType cfg;
            cfg.grp1 = MCU_INT_ENABLE | INT0_INT_ENABLE;                    // Enables interrupts using setting from INTERRUPT_EN_DIS_CONSTANTS_GROUP1
            cfg.grp2 = INT1_INT_ENABLE | INT2_INT_ENABLE;                   // Enables interrupts using setting from INTERRUPT_EN_DIS_CONSTANTS_GROUP2
            cfg.grp3 = 0;                                                   // No changes
            cfg.grp4 = EE_FLASH_WRITE_INT_ENABLE | BCL_INT_ENABLE;          // Enables interrupts using setting from INTERRUPT_EN_DIS_CONSTANTS_GROUP4
            InterruptEnable(cfg);
            ...
            while(1)
            {
            ...
            }
            }
 @endverbatim
 * @note See @ref INTERRUPT_EN_DIS_CONSTANTS. 
 */    
extern void InterruptEnable(ConfigType cfg);
//----------------------------------- 

//-----------------------------------    
/**
 * @brief   Disable specified interrupts
 * @param   cfg ConfigType variable that contains the group configuration settings, where each group field can only hold group constants of the same number. See usage below.   
 * @retval  none
 * @note    Usage:
 @verbatim void main(void)
            {
            ...
            ConfigType cfg;
            cfg.grp1 = MCU_INT_ENABLE | INT0_INT_ENABLE;                    // Disables interrupts using setting from INTERRUPT_EN_DIS_CONSTANTS_GROUP1
            cfg.grp2 = INT1_INT_ENABLE | INT2_INT_ENABLE;                   // Disables interrupts using setting from INTERRUPT_EN_DIS_CONSTANTS_GROUP2
            cfg.grp3 = 0;                                                   // No changes
            cfg.grp4 = EE_FLASH_WRITE_INT_ENABLE | BCL_INT_ENABLE;          // Disables interrupts using setting from INTERRUPT_EN_DIS_CONSTANTS_GROUP4
            InterruptDisable(cfg);
            ...
            while(1)
            {
            ...
            }
            }
 @endverbatim
 * @note See @ref INTERRUPT_EN_DIS_CONSTANTS. 
 */    
extern void InterruptDisable(ConfigType cfg);
//----------------------------------- 

//-----------------------------------    
/**
 * @brief   Get the specified interrupt flag
 * @param   One or more of @ref INTERRUPT_FLAG_CONSTANTS   
 * @retval  State, can be one or more of @ref INTERRUPT_FLAG_CONSTANTS
 * @note    Only constants of the same group number can be ORed together. See example below.
 * @note    Usage:
   @verbatim    if(InterruptGetFlag(TMR0_OVF_INT_FLAG | INT0_INT_FLAG) == TMR0_OVF_INT_FLAG | INT0_INT_FLAG)
                {
                    // Do something;
                } 
                        ...
 
                if(InterruptGetFlag(TMR0_OVF_INT_FLAG) == TMR0_OVF_INT_FLAG)
                {
                    // Do something;
                } 

                        ...
 
                if((InterruptGetFlag(TMR0_OVF_INT_FLAG) == TMR0_OVF_INT_FLAG) != 0)
                {
                    // Do something; 
                }
   @endverbatim
 *  
 */    
extern uint16_t InterruptGetFlag(uint16_t cnst);
//----------------------------------- 

//-----------------------------------    

//-----------------------------------    
/**
 * @brief   Set specified interrupt priorities to high
 * @param   cfg ConfigType variable that contains the group configuration settings, where each group field can only hold group constants of the same number. See usage below.   
 * @retval  none
 * @note    Usage:
 @verbatim void main(void)
            {
            ...
            ConfigType cfg;
            cfg.grp1 = TMRO_INT_PRIORITY | PORTB_CHANGEZ_INT_PRIORITY;      // Set interrupts priority using setting from INTERRUPT_PRIORITY_CONSTANTS_GROUP1
            cfg.grp2 = INT1_INT_PRIORITY | INT2_INT_PRIORITY;               // Set interrupts priority using setting from INTERRUPT_PRIORITY_CONSTANTS_GROUP2
            cfg.grp3 = 0;                                                   // No changes 
            cfg.grp4 = EE_FLASH_INT_PRIORITY | BCL_INT_PRIORITY;            // Set interrupts priority using setting from INTERRUPT_PRIORITY_CONSTANTS_GROUP4
            InterruptSetPriorityHigh(cfg);
            ...
            while(1)
            {
            ...
            }
            }
 @endverbatim
 * @note See @ref INTERRUPT_PRIORITY_CONSTANTS. 
 */    
extern void InterruptSetPriorityHigh(ConfigType cfg);
//----------------------------------- 

//-----------------------------------    
/**
 * @brief   Set specified interrupt priorities to low
 * @param   cfg ConfigType variable that contains the group configuration settings, where each group field can only hold group constants of the same number. See usage below.   
 * @retval  none
 * @note    Usage:
 @verbatim void main(void)
            {
            ...
            ConfigType cfg;
            cfg.grp1 = TMRO_INT_PRIORITY | PORTB_CHANGEZ_INT_PRIORITY;      // Set interrupts priority using setting from INTERRUPT_PRIORITY_CONSTANTS_GROUP1
            cfg.grp2 = INT1_INT_PRIORITY | INT2_INT_PRIORITY;               // Set interrupts priority using setting from INTERRUPT_PRIORITY_CONSTANTS_GROUP2
            cfg.grp3 = 0;                                                   // No changes 
            cfg.grp4 = EE_FLASH_INT_PRIORITY | BCL_INT_PRIORITY;            // Set interrupts priority using setting from INTERRUPT_PRIORITY_CONSTANTS_GROUP4
            InterruptSetPriorityLow(cfg);
            ...
            while(1)
            {
            ...
            }
            }
 @endverbatim
 * @note See @ref INTERRUPT_PRIORITY_CONSTANTS. 
 */    
extern void InterruptSetPriorityLow(ConfigType cfg);
//----------------------------------- 

#ifdef	__cplusplus
}
#endif

#endif	/* INTERRUPTS_H */

