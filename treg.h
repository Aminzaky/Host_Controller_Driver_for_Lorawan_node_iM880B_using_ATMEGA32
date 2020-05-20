/*
 * treg.h
 *
 *  Created on: 19 Dec 2019
 *      Author: amin
 */

#ifndef TREG_H_
#define TREG_H_

#define TCCR0 *((uint8*)(0x53))
#define TIFR *((uint8*)(0x58))
#define TCNT0 *((uint8*)(0x52))
#define OCR0 *((uint8*)(0x5C))
#define TIMSK *((uint8*)(0x59))
#define SREG *((uint8*)(0x5F))




#endif /* TREG_H_ */
