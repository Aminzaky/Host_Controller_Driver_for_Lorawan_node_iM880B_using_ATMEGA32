/*
 * lcd.h
 *
 *  Created on: 16 Nov 2019
 *      Author: amin
 */

#ifndef LCD_H_
#define LCD_H_

#include"Std_Types.h"

void LCD_vidInit4(void);
void LCD_VidWriteData4(uint8 u8Data);
void LCD_VidWriteCommand4(uint8 u8Command);
void LCD_String4(char* arr);
void LCD_Goto_row_coulmn4(uint8 y, uint8 x);
void LCD_Goto_coulmn_row4(uint8 x, uint8 y);


#endif /* LCD_H_ */
