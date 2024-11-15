/*
 * main.c
 *
 *  Created on: Mar 24, 2024
 *      Author: Hassan Bahnasy
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "H_Bridge.h"

int main(void)
{
	DIO_voidInit();
	while(1)
	{
//		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW); // Turn off Relay
//		_delay_ms(2000);
//		DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH); // Turn on Relay
//		_delay_ms(2000);
		H_BRIDGE_voidRotateCW(5000);
		H_BRIDGE_voidRotateCCW(5000);

	}
	return 0;
}
