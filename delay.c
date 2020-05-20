/*
 * delay.c
 *
 *  Created on: 19 Dec 2019
 *      Author: amin
 */


#include "Std_Types.h"
#include "Utils.h"
#include "treg.h"
#include "delay.h"





void delay_ms(uint32 ms)

{

	CLRPORT(TCNT0);
	ASSIGPORT(OCR0,60);
	SETBIT(TCCR0,1);
	SETBIT(TCCR0,3);

	uint32 counter=0;

	while(1)
	{
		if(GETBIT(TIFR,1)==1)
		{
		    SETBIT(TIFR,1);
		    counter++;
		}

		if(counter==(ms*25) )
		        {
	        CLRPORT(TCNT0);
		        	break;
		        }
	}

}
