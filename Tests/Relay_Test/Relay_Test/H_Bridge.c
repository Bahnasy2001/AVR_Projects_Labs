/*
 * H_Bridge.c
 *
 *  Created on: Mar 22, 2024
 *      Author: Hassan Bahnasy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "DIO_interface.h"

#include "H_Bridge.h"


void H_BRIDGE_voidRotateCW(u32 msec)
{
	while(1)
	{
		DIO_u8SetPinValue(H_BRIDGE_u8_PORT,H_BRIDGE_u8_PIN0,DIO_u8_LOW);
		DIO_u8SetPinValue(H_BRIDGE_u8_PORT,H_BRIDGE_u8_PIN1,DIO_u8_HIGH);
		_delay_ms(msec);
		break;
	}
}
void H_BRIDGE_voidRotateCCW(u32 msec)
{
	while(1)
	{
		DIO_u8SetPinValue(H_BRIDGE_u8_PORT,H_BRIDGE_u8_PIN1,DIO_u8_LOW);
		DIO_u8SetPinValue(H_BRIDGE_u8_PORT,H_BRIDGE_u8_PIN0,DIO_u8_HIGH);
		_delay_ms(msec);
		break;
	}
}


