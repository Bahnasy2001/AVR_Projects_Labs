/*
 * main.c
 *
 *  Created on: Jun 7, 2024
 *      Author: Hassan Bahnasy
 */


/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"
#include "WDT_interface.h"

int main(void)
{
	DIO_voidInit();
	while(1)
	{
		//Enable WDT
		WDT_voidEnable();
		//Turn on Led
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
		_delay_ms(1000);
		//Turn off Led
		DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_LOW);
		while(1);//While Loop to check WDT work correct or no
		//Disable WDT
		WDT_voidDisable();
	}
	return 0;
}
