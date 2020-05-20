/*
 * UART_config.h
 *
 *  Created on: 7 Feb 2020
 *      Author: amin
 */

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define F_OSC	((uint32)16000000 )

typedef enum{
	BR_9600 = 9600,
	BR_19200 = 19200,
	BR_28800 = 28800,
	BR_38400 = 38400,
	BR_57600 = 57600,
	BR_115200 = 115200,
	BR_250000 = 250000,
	BR_500000 = 500000
}Uart_BR_t;

typedef enum{
	Parity_None = 0,
	Parity_Even,
	Parity_Odd
}Uart_Parity_t;

typedef enum{
	Stop_One = 0,
	Stop_Two
}Uart_Stop_t;

typedef enum{
	DL_5 = 0,
	DL_6,
	DL_7,
	DL_8,
	DL_9
}Uart_DL_t;

typedef struct{
	Uart_BR_t BaudRate;
	Uart_DL_t Data_Len;
	Uart_Parity_t Parity;
	Uart_Stop_t Stop;
}Uart_cfg_t;

extern const Uart_cfg_t Uart_cfg[];



#endif /* UART_CONFIG_H_ */
