/**
 ******************************************************************************
 * @file            Interrupts.c
 * @author          Maxime (FI)  
 * @brief           Source file for 8 bits PIC18 MCUs interrupt management API
 * @brief           See Interrupt.h 
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
//-----------------------------------

void EnableInterrupt(const uint16_t cnst)
{
    uint8_t var = (uint8_t)(cnst >> 8);             //!< Get the register code [0, 1, 2, 3]
    uint8_t config = (uint8_t)(cnst & 0xFF);        //!< Get the setting value
    //---------
    switch(var)
    {
        case 0:
            INTCON |= config;break; 
            
        case 1:
            INTCON3 |= config;break;
        
        case 2:
            PIE1 |= config;break;
            
        case 3:
            PIE2 |= config;break;
        default:break;
    }
    //---------
}
//-----------------------------------------

void DisableInterrupt(const uint16_t cnst)
{
    uint8_t var = (uint8_t)(cnst >> 8);             //!< Get the register code [0, 1, 2, 3]
    uint8_t config = (uint8_t)(cnst & 0xFF);        //!< Get the setting value
    //---------
    switch(var)
    {
        case 0:
            INTCON &= (uint8_t)(~config);break;
            
        case 1:
            INTCON3 &= (uint8_t)(~config);break;
        
        case 2:
            PIE1 &= (uint8_t)(~config);break;
            
        case 3:
            PIE2 &= (uint8_t)(~config);break;
        default:break;
    }
    //---------    
}
//-----------------------------------------

uint16_t GetInterruptFlag(const uint16_t cnst)
{
    uint8_t var = (uint8_t)(cnst >> 8);             //!< Get the register code [0, 1, 2, 3]
    uint8_t state = (uint8_t)(cnst & 0xFF);         //!< Get the setting value
    //---------
    switch(var)
    {
        case 0:
            state &= INTCON;break;
            
        case 1:
            state &= INTCON3;break;
        
        case 2:
            state &= PIR1;break;
            
        case 3:
            state &= PIR2;break;
        default:break;
    }
    //---------
return state;    
}
//-----------------------------------------

void SetInterruptPriorityHigh(const uint16_t cnst)
{
    uint8_t var = (uint8_t)(cnst >> 8);             //!< Get the register code [0, 1, 2, 3]
    uint8_t config = (uint8_t)(cnst & 0xFF);        //!< Get the setting value
    //---------
    switch(var)
    {
        case 0:
            INTCON2 |= config;break; 
            
        case 1:
            INTCON3 |= config;break;
        
        case 2:
            IPR1 |= config;break;
            
        case 3:
            IPR2 |= config;break;
        default:break;
    }
    //---------    
}
//-----------------------------------------

void SetInterruptPriorityLow(const uint16_t cnst)
{
    uint8_t var = (uint8_t)(cnst >> 8);             //!< Get the register code [0, 1, 2, 3]
    uint8_t config = (uint8_t)(cnst & 0xFF);        //!< Get the setting value
    //---------
    switch(var)
    {
        case 0:
            INTCON2 &= config;break; 
            
        case 1:
            INTCON3 &= config;break;
        
        case 2:
            IPR1 &= config;break;
            
        case 3:
            IPR2 &= config;break;
        default:break;
    }
    //---------     
}
//-----------------------------------------