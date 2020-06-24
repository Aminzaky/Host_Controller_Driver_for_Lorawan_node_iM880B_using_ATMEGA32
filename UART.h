/*
 * UART.h
 *
 *  Created on: 7 Feb 2020
 *      Author: amin
 */

#ifndef UART_H_
#define UART_H_



int UART_VIDint(void);
void UART_send_char(uint8 data);
uint8 UART_U8recievechar(void);
void UART_send_string(char *arr);
void UART_recieve_string(void);
int Uart_Transmit (uint8* Data, uint8 len);
void Uart_Receive_with_recieve_interrupt (uint8* Data, uint8 Len);
void Uart_Receive_with_NO_recieve_interrupt (uint8* Data, uint8 Len);


#endif /* UART_H_ */
