/*
 * H_Bridge.c
 *
 *  Created on: Mar 22, 2024
 *      Author: Hassan Bahnasy
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "H_Bridge.h"


void H_BRIDGE_voidRotateCW(void)
{
	while(1)
	{
		DIO_u8SetPinValue(H_BRIDGE_u8_PORT,H_BRIDGE_u8_PIN0,DIO_u8_LOW);
		DIO_u8SetPinValue(H_BRIDGE_u8_PORT,H_BRIDGE_u8_PIN1,DIO_u8_HIGH);
	}
}
void H_BRIDGE_voidRotateCCW(void)
{
	while(1)
	{
		DIO_u8SetPinValue(H_BRIDGE_u8_PORT,H_BRIDGE_u8_PIN1,DIO_u8_LOW);
		DIO_u8SetPinValue(H_BRIDGE_u8_PORT,H_BRIDGE_u8_PIN0,DIO_u8_HIGH);

	}
}


