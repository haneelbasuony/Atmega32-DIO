/*
 * DIO.c
 *
 *  Created on: Oct 17, 2021
 *      Author: LENOVO
 */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "DIO_int.h"
#include "DIO_private.h"

/* IO Pins */
void DIO_SetPinValue(u8 Port , u8 PinId, u8 PinVal)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Port <= PORTD) && (PinId <= PIN7))
	{
		if (PinVal == HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Port)
			{
				case PORTA: SET_BIT(PORTA_Register,PinId); break;
				case PORTB: SET_BIT(PORTB_Register,PinId); break;
				case PORTC: SET_BIT(PORTC_Register,PinId); break;
				case PORTD: SET_BIT(PORTD_Register,PinId); break;
			}

		}

		else if (PinVal == LOW)
		{
			/* Check on the Required PORT Number */
			switch (Port)
			{
				case PORTA: CLR_BIT(PORTA_Register,PinId); break;
				case PORTB: CLR_BIT(PORTB_Register,PinId); break;
				case PORTC: CLR_BIT(PORTC_Register,PinId); break;
				case PORTD: CLR_BIT(PORTD_Register,PinId); break;
			}
		}

		else
		{
			/* Do nothing, Wrong value to set */
		}
	}

	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}

u8 DIO_GetPinValue(u8 Port, u8 PinId)
{
	/* Define Local Variable to get the BIT Value */
	u8 u8ResultLocal=0;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Port <= PORTD) && (PinId <= PIN7))
	{
		/* Check on the Required PORT Number */
		switch (Port)
		{
			case PORTA: u8ResultLocal= GET_BIT(PINA_Register,PinId); break;
			case PORTB: u8ResultLocal= GET_BIT(PINB_Register,PinId); break;
			case PORTC: u8ResultLocal= GET_BIT(PINC_Register,PinId); break;
			case PORTD: u8ResultLocal= GET_BIT(PIND_Register,PinId); break;
		}
	}

	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		u8ResultLocal = 0xFF;
	}

	return u8ResultLocal;
}

void DIO_SetPinDirection (u8 Port, u8 PinId, u8 PinDir)
{
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Port <= PORTD) && (PinId <= PIN7))
	{
		if (PinDir == OUTPUT )
		{
			/* Check on the Required PORT Number */
			switch (Port)
			{
				case PORTA: SET_BIT(DDRA_Register,PinId); break;
				case PORTB: SET_BIT(DDRB_Register,PinId); break;
				case PORTC: SET_BIT(DDRC_Register,PinId); break;
				case PORTD: SET_BIT(DDRD_Register,PinId); break;
			}
		}

		else if ( PinDir == INPUT )
		{
			/* Check on the Required PORT Number */
			switch (Port)
			{
				case PORTA: CLR_BIT(DDRA_Register,PinId); break;
				case PORTB: CLR_BIT(DDRB_Register,PinId); break;
				case PORTC: CLR_BIT(DDRC_Register,PinId); break;
				case PORTD: CLR_BIT(DDRD_Register,PinId); break;
			}
		}

		else
		{
			/* Do nothing, Wrong Direction Required */
		}
	}

	else
	{
		/* Do nothing, Error in the Pin ID or PORT ID */
	}
}


/* IO Ports */
void DIO_SetPortDirection (u8 Port, u8 PortDir)
{
	/* Check on the Required PORT Number */
	switch (Port)
	{
		case     PORTA: DDRA_Register = PortDir; break;
		case     PORTB: DDRB_Register = PortDir; break;
		case     PORTC: DDRC_Register = PortDir; break;
		case     PORTD: DDRD_Register = PortDir; break;
		default: /* Wrong Port ID */       break;
	}
}

void DIO_SetPortValue (u8 Port, u8 PortVal)
{
	/* Check on the Required PORT Number */
	switch (Port)
	{
		case     PORTA: PORTA_Register = PortVal; break;
		case     PORTB: PORTB_Register = PortVal; break;
		case     PORTC: PORTC_Register = PortVal; break;
		case     PORTD: PORTD_Register = PortVal; break;
		default: /* Wrong Port ID */        break;
	}
}


