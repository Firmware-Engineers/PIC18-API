/**
 ******************************************************************************
 * @file            Interrupts.c
 * @author          Maxime   
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
void InterruptEnable(ConfigType cfg)
{
    //---------
    INTCON |= cfg.grp1;
    INTCON3 |= cfg.grp2;
    PIE1 |= cfg.grp3;
    PIE2 |= cfg.grp4;
    //---------
}
//-----------------------------------------

void InterruptDisable(ConfigType cfg)
{
    //---------
    INTCON &= (uint8_t)(~cfg.grp1);
    INTCON3 &= (uint8_t)(~cfg.grp2);
    PIE1 &= (uint8_t)(~cfg.grp3);
    PIE2 &= (uint8_t)(~cfg.grp4);
    //---------   
}
//-----------------------------------------

uint16_t InterruptGetFlag(uint16_t cnst)
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

void InterruptSetPriorityHigh(ConfigType cfg)
{
    //---------
    INTCON2 |= cfg.grp1;
    INTCON3 |= cfg.grp2;
    IPR1 |= cfg.grp3;
    IPR2 |= cfg.grp4;
    //---------   
}
//-----------------------------------------

void InterruptSetPriorityLow(ConfigType cfg)
{
    //---------
    INTCON2 &= (uint8_t)(~cfg.grp1);
    INTCON3 &= (uint8_t)(~cfg.grp2);
    IPR1 &= (uint8_t)(~cfg.grp3);
    IPR2 &= (uint8_t)(~cfg.grp4);
    //---------     
}
//-----------------------------------------