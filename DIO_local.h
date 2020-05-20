/*
 * DIO.h
 *
 *  Created on: 15 Nov 2019
 *      Author: amin
 */

#ifndef DIO_local_H_
#define DIO_local_H_

#define PORTA *((uint8*)(0x3B))
#define DDRA *((uint8*)(0x3A))
#define PINA *((uint8*)(0x39))

#define PORTB *((uint8*)(0x38))
#define DDRB *((uint8*)(0x37))
#define PINB *((uint8*)(0x36))

#define PORTC *((uint8*)(0x35))
#define DDRC *((uint8*)(0x34))
#define PINC *((uint8*)(0x33))

#define PORTD *((uint8*)(0x32))
#define DDRD *((uint8*)(0x31))
#define PIND *((uint8*)(0x30))


#endif /* DIO_local_H_ */
