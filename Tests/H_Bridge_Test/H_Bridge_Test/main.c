/*
 * main.c
 *
 *  Created on: Mar 15, 2024
 *      Author: Hassan Bahnasy
 */


/*  LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU   8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"

int main(void)
{
	DIO_voidInit();
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
	while(1)
	{
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_LOW);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		_delay_ms(5000);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN1,DIO_u8_HIGH);
		_delay_ms(5000);
	}
	return 0;
}
