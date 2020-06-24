/*
 * CRC16.h
 *
 *  Created on: Apr 30, 2020
 *      Author: AminZaky
 */

#ifndef CRC16_H_
#define CRC16_H_

//------------------------------------------------------------------------------
//
// Section Defines & Declarations
//
//------------------------------------------------------------------------------

#define CRC16_INIT_VALUE 0xFFFF // initial value for CRC algorithem
#define CRC16_GOOD_VALUE 0x0F47 // constant compare value for check
#define CRC16_POLYNOM 0x8408 // 16-BIT CRC CCITT POLYNOM
//------------------------------------------------------------------------------
//
// Function Prototypes
//
//------------------------------------------------------------------------------
// Calc CRC16
uint16 CRC16_Calc(uint8* data, uint16 length, uint16 initVal);
// Calc & Check CRC16
bool CRC16_Check(uint8* data, uint16 length, uint16 initVal);

#endif /* CRC16_H_ */
