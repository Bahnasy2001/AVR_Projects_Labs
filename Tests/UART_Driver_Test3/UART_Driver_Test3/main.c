/*
 * main.c
 *
 *  Created on: Jun 25, 2024
 *      Author: Hassan Bahnasy
 */

/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU  8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"
#include "GI_interface.h"
#include "UART_interface.h"

/* HAL Layer */
#include "LCD_interface.h"

/* Global Definitions */
u8 ReceivedString[16];
volatile u8 AsyncFlag = 0;
void SendCallback(void);
void ReceiveCallback(void);
int main(void)
{
	DIO_voidInit();
	GI_voidEnableGI();
	LCD_voidInit();
	UART_voidInit();
	/* Display Initial Message */
	LCD_voidWriteString((u8 *)"Init...");

	// Send a test message
	UART_u8SendStringAsynch((u8*) "I Love Zamalek ", &SendCallback);

	// Receive string asynchronously
	UART_u8ReceiveStringAsynch(ReceivedString, &ReceiveCallback, sizeof(ReceivedString) - 1);
	while(1)
	{
		if (AsyncFlag)
		{
			LCD_voidClearScreen();
			LCD_voidWriteString((u8 *)"Async Recv: ");
			_delay_ms(500);
			LCD_voidClearScreen();
			LCD_voidWriteString(ReceivedString);
			AsyncFlag = 0;

			// Re-enable reception for next message
			UART_u8ReceiveStringAsynch(ReceivedString, &ReceiveCallback, sizeof(ReceivedString) - 1);
		}
	}
	return 0;
}
void SendCallback(void)
{
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
}
void ReceiveCallback(void)
{
	AsyncFlag = 1;
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN1,DIO_u8_HIGH);
}
