/*
 * lcd.c
 *
 *  Created on: 16 Nov 2019
 *      Author: amin
 */

#include "Std_Types.h"
#include "Utils.h"
#include "DIO.h"
#include "DIO_local.h"
#include "delay.h"
#include <string.h>

void LCD_VidWriteData4(uint8 u8Data) {

	// Rs=1
	SETBIT(PORTB, 1);
	// R/W=0
	CLRBIT(PORTB, 2);
	// send data
	ASS_HIGH_NIPPLE(PORTA, GET_HIGH_NIPPLE(u8Data));
	//latch E=1 delay E=0
	SETBIT(PORTB, 3);
	delay_ms(5);
	CLRBIT(PORTB, 3);

	ASS_HIGH_NIPPLE(PORTA, GET_LOW_NIPPLE(u8Data));
	//latch E=1 delay E=0
	SETBIT(PORTB, 3);
	delay_ms(5);
	CLRBIT(PORTB, 3);

}

void LCD_VidWriteCommand4(uint8 u8Command) {

	CLRBIT(PORTB, 1);

	CLRBIT(PORTB, 2);

	ASS_HIGH_NIPPLE(PORTA, GET_HIGH_NIPPLE(u8Command));
//latch E=1 delay E=0
	SETBIT(PORTB, 3);
	delay_ms(5);
	CLRBIT(PORTB, 3);

	ASS_HIGH_NIPPLE(PORTA, GET_LOW_NIPPLE(u8Command));
//latch E=1 delay E=0
	SETBIT(PORTB, 3);
	delay_ms(5);
	CLRBIT(PORTB, 3);

}

void LCD_String4(char* arr) {
	uint8 i;
	for (i = 0; i < strlen(arr); i++)/* Send each char of string till the NULL */
	{
		LCD_VidWriteData4(arr[i]);
	}
}

void LCD_Goto_row_coulmn4(uint8 y, uint8 x) {
	uint8 firstcharAdr[] = { 0x80, 0xC0, 0x94, 0xD4 };
	LCD_VidWriteCommand4(firstcharAdr[y] + x);
	delay_ms(1);
}

void LCD_Goto_coulmn_row4(uint8 x, uint8 y) {
	uint8 firstcharAdr[] = { 0x80, 0xC0, 0x94, 0xD4 };
	LCD_VidWriteCommand4(firstcharAdr[y] + x);
	delay_ms(1);
}

void LCD_vidInit4(void) {

	SET_HIGH_NIPPLE(DDRA);
	SET_LOW_NIPPLE(DDRB);

//delay(>30)
	delay_ms(40);
//0x3c function set N=1,F=1
	LCD_VidWriteCommand4(0x02);
//delay(>30)
	delay_ms(5);
	LCD_VidWriteCommand4(0x28);
//delay(>30)
	delay_ms(5);
//0x0c D=1 c=0 b=1
	LCD_VidWriteCommand4(0x0C);
//delay(>30)
	delay_ms(5);
//clr screen 0x01
	LCD_VidWriteCommand4(0x01);
//delay(>135)
	delay_ms(10);

}
