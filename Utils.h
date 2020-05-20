/*
 * Utils.h
 *
 *  Created on: 15 Nov 2019
 *      Author: amin
 */

#ifndef UTILS_H_
#define UTILS_H_

#define SETBIT(REG, BITNO)   ((REG) |= (1 << (BITNO)))
#define CLRBIT(REG, BITNO)   (REG &= ~(1 << BITNO))
#define TOGGLEBIT(REG, BITNO)   ((REG) ^= (1 <<(BITNO)))
#define GETBIT(REG, BITNO)   ((REG >> BITNO) & (1))
#define ASSIGNBIT(REG, BITNO, VALUE)   ((REG) = (((REG) & ( ~(1 << (BITNO))))|(VALUE << BITNO)))

#define ROTATE_LEFT(REG, ROTNO, WORD)     ( REG << (ROTNO)) | (REG >> ((-ROTNO) + WORD))
#define ROTATE_RIGHT(REG, ROTNO, WORD)    ( REG >> (ROTNO ) | (REG <<(-ROTNO) + WORD-1))

#define SET_LOW_NIPPLE(REG) (REG|=0x0F)
#define CLR_LOW_NIPPLE(REG) (REG&=0xF0)
#define GET_LOW_NIPPLE(REG) (REG&0x0F)
#define TOG_LOW_NIPPLE(REG) (REG^=0x0F)
#define ASS_LOW_NIPPLE(REG,VALUE)   (REG=((VALUE&=0x0F) | (REG&0xF0)))

#define SET_HIGH_NIPPLE(REG) (REG|=0xF0)
#define CLR_HIGH_NIPPLE(REG) (REG&=0x0F)
#define GET_HIGH_NIPPLE(REG) ((REG>>4)&0x0F)
#define TOG_HIGH_NIPPLE(REG) (REG^=0xF0)
#define ASS_HIGH_NIPPLE(REG,VALUE)   (REG=((VALUE<<4) | (REG&0x0F)))

#define SETPORT(REG)   (REG|=0xFF)
#define CLRPORT(REG)   (REG&=0x00)
#define TOGGLEPORT(REG)   (REG^=0xFF)
#define GETPORT(REG)   (REG&0xFF)
#define ASSIGPORT(REG, VALUE)    (REG=((VALUE) | (REG&0x00)))


#endif /* UTILS_H_ */
