/**
 ******************************************************************************
 * @file            BitWise.h
 * @author          Maxime
 * @brief           header file for The bit wise library
 * @brief           This library provides bit manipulation operations such as:
 *                      - Reading a bit from a register
 *                      - Setting a bit in a register
 *                      - Modifying one or more bits in a register
 *                  and more.
 *                  See dependencies in the include section below
 * 
 * 
 * @note            History:
 *                   - Feb 3, 2023: Initial release
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

#ifndef BITWISE_H
#define	BITWISE_H

#ifdef	__cplusplus
extern "C" {
#endif

//-----------------------------------  
#include "PIC18Types.h"
//-----------------------------------
    
//-----------------------------------    
/**
 * @brief   Get a bit value from a register
 * @param   reg: register to read from
 * @param   bit: Bit position
 * @retval  value read value read (8 bits)
 */
#define BitRead(reg, bit)        		(uint8_t)((reg >> bit) & 0x01)    
//-----------------------------------   

//-----------------------------------
/**
 * @brief   Set a bit value in a register
 * @param   reg: register whose bit is to be changed 
 * @param   bit: bit position in the register
 * @retval  None
 */
#define BitSet(reg, bit)         		(uint8_t)(reg |= (1 << bit))
//-----------------------------------

//-----------------------------------
/**
 * @brief   Clear a bit value in a register
 * @param   reg: Register whose bit bit is to be cleared
 * @param   bit: Bit position in the byte
 * @retval  None
 */    
#define BitClear(reg, bit)       		(uint8)(reg &= ~(1 << bit))
//-----------------------------------

//-----------------------------------
/**
 * @brief   Modify one or many bits values in a register
 * @param   mask: modify mask 
 * @param   data: register to modify
 * @param   value: value to apply 
 * @retval  None
 * @Note    A mask bit value of 1 will allow change on the corresponding bit
 * @Note    A mask bit value of 0 will make no change on the corresponding bit
 */ 
#define BitModify(mask, data, value)    data = (uint8)((~(mask)&(data))|(value & mask))
//-----------------------------------

#ifdef	__cplusplus
}
#endif

#endif	/* BITWISE_H */

