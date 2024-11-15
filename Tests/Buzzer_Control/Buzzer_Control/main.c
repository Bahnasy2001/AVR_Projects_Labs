/*
 * main.c
 *
 *  Created on: Mar 14, 2024
 *      Author: Hassan Bahnasy
 */

/* Lib Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU   8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"

int main(void)
{
	DIO_voidInit();
	while(1)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		_delay_ms(500);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		_delay_ms(500);
	}
	return 0;
}
