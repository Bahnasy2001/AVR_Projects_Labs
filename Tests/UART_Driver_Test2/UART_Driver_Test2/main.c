/*
 * main.c
 *
 *  Created on: Jun 20, 2024
 *      Author: Hassan Bahnasy
 */

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"
#include "GI_interface.h"
#include "UART_interface.h"

/* HAL Layer */
#include "LCD_interface.h"

/* Global Variables */
u8 ReceivedString[16];
volatile u8 AsyncFlag = 0;

void ReceiveCallback(void);
int main(void)
{
	u8 Local_str[16];
	/* Initialization */
	DIO_voidInit();
	LCD_voidInit();
	UART_voidInit();
	GI_voidEnableGI();

	/* Display Initial Message */
	LCD_voidWriteString((u8 *)"Init...");

	while (1)
	{
		if (UART_u8ReceiveStringSynch(Local_str, 15) == STD_TYPES_OK) {
			Local_str[15] = '\0'; // Null-terminate the received string
			LCD_voidClearScreen();
			LCD_voidWriteString((u8 *)"Received: ");
			_delay_ms(500);
			LCD_voidClearScreen();
			LCD_voidWriteString(Local_str);
			_delay_ms(2000);
		}
		else {
			LCD_voidClearScreen();
			LCD_voidWriteString((u8 *)"Timeout/Error");
			_delay_ms(2000);
		}
	}

	return 0;
}

void ReceiveCallback(void)
{
	AsyncFlag = 1;
}
