/*
 * main.c
 *
 *  Created on: Feb 25, 2024
 *      Author: Hassan Bahnasy
 */

/*LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/*MCAL Layer */
#include "DIO_interface.h"

int main()
{
	/* Configure PC7 output */
	DIO_voidInit();

	while(1)
	{
		//Turn on LED
		DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_HIGH);
		_delay_ms(1000);
		//Turn off LED
		DIO_u8SetPinValue(DIO_u8_PORTC,DIO_u8_PIN7,DIO_u8_LOW);
		_delay_ms(1000);
	}
	return 0;
}
