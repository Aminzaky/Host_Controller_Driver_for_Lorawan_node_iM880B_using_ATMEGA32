/*
 * UART_loacl.h
 *
 *  Created on: 7 Feb 2020
 *      Author: amin
 */

#ifndef UART_LOACL_H_
#define UART_LOACL_H_

#define UDR *((uint8*)(0x2C))
#define UCSRA *((uint8*)(0x2B))
#define UCSRB *((uint8*)(0x2A))
#define UCSRC *((uint8*)(0x40))
#define UBRRL *((uint8*)(0x29))
#define UBRRH *((uint8*)(0x40))
#define SREG *((uint8*)(0x5F))

#define RXC 7
#define TXC 6
#define UDRE 5
#define FE 4
#define DOR 3
#define PE 2
#define U2X 1
#define MPCM 0

#define RXCIE 7
#define TXCIE 6
#define UDRIE 5
#define RXEN 4
#define TXEN 3
#define UCSZ2 2
#define RXB8 1
#define TXB8 0

#define URSEL 7
#define UMSEL 6
#define UPM1 5
#define UPM0 4
#define USBS 3
#define UCSZ1 2
#define UCSZ0 1
#define UCPOL 0

#endif /* UART_LOACL_H_ */
