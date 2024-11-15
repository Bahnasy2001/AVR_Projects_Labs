/*
 * main.c
 *
 *  Created on: Jun 27, 2024
 *      Author: Hassan Bahnasy
 */

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU   8000000UL
#include <util/delay.h>

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "UART_interface.h"

int main(void)
{
	static u8 Flag = 0;
	u8 Local_u8Data;
	DIO_voidInit();
	SPI_voidInit();
	UART_voidInit();

	while(1)
	{
		SPI_u8TransReceive('S',&Local_u8Data);
		UART_voidSendByte(Local_u8Data);
		if(Local_u8Data == 'M')
		{
			if(Flag == 0)
			{
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_HIGH);
				Flag = 1;
			}
			else
			{
				DIO_u8SetPinValue(DIO_u8_PORTA,DIO_u8_PIN0,DIO_u8_LOW);
				Flag = 0;
			}

		}
	}
	return 0;
}
