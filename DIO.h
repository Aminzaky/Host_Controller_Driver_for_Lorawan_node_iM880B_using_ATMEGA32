/*
 * DIO.h
 *
 *  Created on: Nov 30, 2019
 *      Author: amin
 */

#ifndef DIO_H_
#define DIO_H_



#include "Std_Types.h"


/* Pin directions */
#define Input 			0
#define Output			1

/* PORTS */
#define PORT_A	0
#define PORT_B	1
#define PORT_C	2
#define PORT_D	3

/* Port Pins */
#define pin_A0	0
#define pin_A1	1
#define pin_A2	2
#define pin_A3	3
#define pin_A4	4
#define pin_A5	5
#define pin_A6	6
#define pin_A7	7

#define pin_B0	8
#define pin_B1	9
#define pin_B2	10
#define pin_B3	11
#define pin_B4	12
#define pin_B5	13
#define pin_B6	14
#define pin_B7	15

#define pin_C0	16
#define pin_C1	17
#define pin_C2	18
#define pin_C3	19
#define pin_C4	20
#define pin_C5	21
#define pin_C6	22
#define pin_C7	23

#define pin_D0	24
#define pin_D1	25
#define pin_D2	26
#define pin_D3	27
#define pin_D4	28
#define pin_D5	29
#define pin_D6	30
#define pin_D7	31





void DIO_voidInit(void);

void DIO_voidSetPinDir(uint8 pin_num, uint8 Dir);
void DIO_voidSetPortDir(uint8 Port_num, uint8 Dir);

void DIO_voidWritePinValue(uint8 pin_num, uint8 value);
void DIO_voidWritePortValue(uint8 Port, uint8 value);

uint8 DIO_U8ReadPinValue(uint8 pin_num);
uint8 DIO_U8ReadPortValue(uint8 Port);









#endif /* DIO_H_ */
