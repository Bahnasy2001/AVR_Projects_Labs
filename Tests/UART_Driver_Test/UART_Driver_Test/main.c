/*
 * main.c
 *
 *  Created on: Jun 16, 2024
 *      Author: Hassan Bahnasy
 */

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "UART_interface.h"

int main(void)
{
	u8 Local_u8Data;
	DIO_voidInit();
	UART_voidInit();

	while(1)
	{
		UART_u8ReceiveByte(&Local_u8Data);
		if(Local_u8Data == 'a')
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
		}
		else if(Local_u8Data == 'b')
		{
			DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
		}
	}
	return 0;
}
