/*
 * UART.c
 *
 *  Created on: 7 Feb 2020
 *      Author: amin
 */

#include "Std_Types.h"
#include "Utils.h"
#include "UART_loacl.h"
#include "UART_config.h"
#include <string.h>
#include "DIO.h"

volatile char string[100];
static uint8 Rx_Data[20];
uint8 Rx_Count = 0;

/*	Description: Configure the specification of the Needed UART */
Uart_cfg_t const Uart_cfg[] = { { BR_115200, DL_8, Parity_None, Stop_One } };

int UART_VIDint(void) {

	DIO_voidSetPinDir(pin_D0,Input);
	DIO_voidSetPinDir(pin_D1,Output);
	uint8 Control_Register;

	/*	Comment:	This function used to choose the baud rate */
	uint16 BaudRate = (F_OSC / (16 * Uart_cfg[0].BaudRate)) - 1;
	UBRRH = (uint8) (BaudRate >> 8);
	UBRRL = (uint8) BaudRate;
	if (F_OSC > 8000000) {
		UBRRL += 1; //approximation
	}
	/*	Comment:	Enable the UART Transmitter and Receiver	*/
	UCSRB = (1 << RXEN) | (1 << TXEN);

	/*	Comment:	Choose the Parity bits specification	*/
	if (Uart_cfg[0].Parity == Parity_None) {
	} else if (Uart_cfg[0].Parity == Parity_Even) {
		Control_Register = UBRRH;
		Control_Register = UCSRC;
		UCSRC = (Control_Register | ((1 << UPM1)));
	} else if (Uart_cfg[0].Parity == Parity_Odd) {
		Control_Register = UBRRH;
		Control_Register = UCSRC;
		UCSRC = Control_Register | (1 << UPM1) | (1 << UPM0);
	} else {
	}

	/*	Comment:	Choose 1 or 2 stop Bits	*/
	if (Uart_cfg[0].Stop == Stop_One) {
	} else if (Uart_cfg[0].Stop == Stop_Two) {
		Control_Register = UCSRC;
		Control_Register = UCSRC;
		UCSRC = Control_Register | (1 << URSEL) | (1 << USBS);
	} else {
	}

	/*Comment:	Choose the lenght of Data per frame*/
	if (Uart_cfg[0].Data_Len == DL_5) {
		Control_Register = UCSRC;
		Control_Register = UCSRC;
		UCSRC = (Control_Register | (1 << URSEL)) & (~(1 << UCSZ0))
				& (~(1 << UCSZ1));
	} else if (Uart_cfg[0].Data_Len == DL_6) {
		Control_Register = UCSRC;
		Control_Register = UCSRC;
		UCSRC = ((Control_Register | (1 << URSEL) | (1 << UCSZ0))
				& (~(1 << UCSZ1)));
	} else if (Uart_cfg[0].Data_Len == DL_7) {
		Control_Register = UCSRC;
		Control_Register = UCSRC;
		UCSRC = Control_Register | (1 << URSEL) | (2 << UCSZ0);
	} else if (Uart_cfg[0].Data_Len == DL_8) {

	} else if (Uart_cfg[0].Data_Len == DL_9) {
		Control_Register = UCSRC;
		Control_Register = UCSRC;
		UCSRC = Control_Register | (1 << URSEL) | (3 << UCSZ0);
		UCSRB |= (1 << UCSZ2);
	} else {
	}

	UCSRB |= (1 << RXCIE); //RX completion interrupt enable
	SETBIT(SREG, 7); //global interrupt enable

	return 1;
}

void UART_send_char(uint8 data) {

	while (GETBIT(UCSRA,5) == 0)
		;
	UDR = data;

}

uint8 UART_U8recievechar(void) {

	while (GETBIT(UCSRA,7) == 0)
		;
	return UDR;

}

void UART_send_string(char* arr) {
	for (int x = 0; x < strlen(arr); x++) {
		UART_send_char(arr[x]);
	}

}

int Uart_Transmit(uint8* Data, uint8 Len) {
	uint16 index;
	for (index = 0; index < Len; index++) {
		while (!(UCSRA & (1 << UDRE)))
			;
		UDR = Data[index];
	}
	return 1;

}

void UART_recieve_string(void) {

	int x, i = 0;

	//receive the characters until ENTER is pressed (ASCII for ENTER = 13)
	while (((x = UART_U8recievechar()) != ('\n'))
			|| ((x = UART_U8recievechar()) != ('\r'))) {
		//and store the received characters into the array string[] one-by-one
		string[i++] = x;
	}

	//insert NULL to terminate the string
	string[i] = 10;

}

void Uart_Receive_with_recieve_interrupt(uint8* Data, uint8 Len) {
	UCSRB &= ~(1 << RXCIE);
	uint16 i;
	if (Rx_Count != 0) {
		for (i = 0; i < Len; i++) {
			Data[i] = Rx_Data[i];
		}
		Rx_Count = 0;
	} else {
		Rx_Count = 0;
	}
	UCSRB |= (1 << RXCIE);
}

void Uart_Receive_with_NO_recieve_interrupt(uint8* Data, uint8 len) {
	for (int x = 0; x < len; x++) {
		(Data[x]) = UART_U8recievechar();
	}
}

void __vector_13(void) __attribute__((signal,used));
void __vector_13(void) {
	Rx_Data[Rx_Count] = UDR;
	Rx_Count++;
	if(Rx_Count>20)
	{
		Rx_Count=0;
	}
}

