/*
 * DIO.c
 *
 *  Created on: Nov 30, 2019
 *      Author: amin
 */

#ifndef DIO_C_
#define DIO_C_


#include "Utils.h"
#include "DIO_Local.h"
#include "DIO_config.h"
#include "DIO.h"


void DIO_voidInit(void)
{

}


void DIO_voidSetPortDir(uint8 Port, uint8 Dir)
{
	switch(Port)
	{
	case 0:
		if(Dir==Input)
		{
			CLRPORT(DDRA);

		}
		if(Dir==Output)
		{
			SETPORT(DDRA);

		}

		break;

	case 1:
		if(Dir==Input)
		{
			CLRPORT(DDRB);

		}
		if(Dir==Output)
		{
			SETPORT(DDRB);

		}
		break;

	case 2:
		if(Dir==Input)
		{
			CLRPORT(DDRC);

		}
		if(Dir==Output)
		{
			SETPORT(DDRC);

		}
		break;
	case 3:
		if(Dir==Input)
		{
			CLRPORT(DDRD);

		}
		if(Dir==Output)
		{
			SETPORT(DDRD);
		}
		break;

	}
}

void DIO_voidWritePortValue(uint8 Port, uint8 value)
{
	switch(Port)
	{
	case 0:
		PORTA=value;
		break;

	case 1:
		PORTB=value;
		break;

	case 2:
		PORTC=value;
		break;
	case 3:
		PORTD=value;
		break;

	}
}

uint8 DIO_U8ReadPortValue(uint8 Port)
{

	uint8 port;
	switch(Port)
	{
	case 0:
	    port=GETPORT(PINA);
		break;

	case 1:
		port=GETPORT(PINB);
		break;

	case 2:
		port=GETPORT(PINC);
		break;
	case 3:
		port=GETPORT(PIND);
		break;

	}

	return port;
}

void DIO_voidSetPinDir(uint8 pin_num, uint8 Dir)
{
	switch (Dir)
	{
		case 0:

			/*Input */

			if((pin_num>=pin_A0)&&(pin_num<pin_B0))
			{
				/*DDRA*/
				CLRBIT(DDRA, pin_num%8);
			}
			if((pin_num>=pin_B0)&&(pin_num<pin_C0))
			{
				/*DDRB*/
				CLRBIT(DDRB, pin_num%8);
			}
			if((pin_num>=pin_C0)&&(pin_num<pin_D0))
			{
				/*DDRC*/
				CLRBIT(DDRC, pin_num%8);
			}
			if((pin_num>=pin_D0)&&(pin_num<=pin_D7))
			{
				/*DDRD*/
				CLRBIT(DDRD, pin_num%8);
			}

			break;


		case 1:

			/* Output */


			if((pin_num>=pin_A0)&&(pin_num<pin_B0))
			{
				/*DDRA*/
				SETBIT(DDRA, pin_num%8);
			}
			if((pin_num>=pin_B0)&&(pin_num<pin_C0))
			{
				/*DDRB*/
				SETBIT(DDRB, pin_num%8);
			}
			if((pin_num>=pin_C0)&&(pin_num<pin_D0))
			{
				/*DDRC*/
				SETBIT(DDRC, pin_num%8);
			}
			if((pin_num>=pin_D0)&&(pin_num<=pin_D7))
			{
				/*DDRD*/
				SETBIT(DDRD, pin_num%8);
			}
			break;
		}

}

void DIO_voidWritePinValue(uint8 pin_num, uint8 value)
{
	if((pin_num>=pin_A0)&&(pin_num<pin_B0))
	{
		/*PORTA*/
		ASSIGNBIT(PORTA, pin_num%8, value);
	}
	if((pin_num>=pin_B0)&&(pin_num<pin_C0))
	{
		/*PORTB*/
		ASSIGNBIT(PORTB, pin_num%8, value);
	}
	if((pin_num>=pin_C0)&&(pin_num<pin_D0))
	{
		/*PORTC*/
		ASSIGNBIT(PORTC, pin_num%8, value);
	}
	if((pin_num>=pin_D0)&&(pin_num<=pin_D7))
	{
		/*PORTD*/
		ASSIGNBIT(PORTD, pin_num%8, value);
	}
}

uint8 DIO_U8ReadPinValue(uint8 pin_num)
{
	uint8 pin;
	if((pin_num>=pin_A0)&&(pin_num<pin_B0))
	{
		/*PINA*/
		pin= (GETBIT(PINA, pin_num%8));
	}
	if((pin_num>=pin_B0)&&(pin_num<pin_C0))
	{
		/*PINB*/
		pin= (GETBIT(PINB, pin_num%8));
	}
	if((pin_num>=pin_C0)&&(pin_num<pin_D0))
	{
		/*PINC*/
		pin= (GETBIT(PINC, pin_num%8));
	}
	if((pin_num>=pin_D0)&&(pin_num<=pin_D7))
	{
		/*PIND*/
		pin= (GETBIT(PIND, pin_num%8));
	}
    return pin;
}




#endif /* DIO_C_ */
