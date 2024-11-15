/*
 * main.c
 *
 *  Created on: Jun 28, 2024
 *      Author: Hassan Bahnasy
 */
/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU    8000000UL
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"
#include "GI_interface.h"
#include "SPI_interface.h"
#include "UART_interface.h"

/* HAL Layer */
#include "LCD_interface.h"

volatile u8 AsyncFlag = 0;
void ReceiveCallback(void);
int main(void)
{
	u8 ReceivedString[16] = {0};
	DIO_voidInit();
	GI_voidEnableGI();
	SPI_voidInit();
	LCD_voidInit();
	UART_voidInit();
	LCD_voidWriteString((u8 *)"Init...");
	_delay_ms(1000); // Ensure initialization delay

	while(1)
	{

		// Transmit and receive data
		SPI_u8SendReceiveStringAsynch((u8 *)" Hello Slaves", ReceivedString, &ReceiveCallback);

		// Wait for the data reception to complete
		while (AsyncFlag == 0);
//		SPI_u8SendStringSynch(" Slave");
		// Clear the flag
		AsyncFlag = 0;

		// Process the received data
		LCD_voidClearScreen();
		LCD_voidWriteString((u8 *)"Received: ");
		_delay_ms(100);
		LCD_voidClearScreen();
//		LCD_voidSendChar(Local_u8Byte);
//		UART_voidSendByte(Local_u8Byte);
		UART_u8SendStringSynch(ReceivedString);
		LCD_voidWriteString(ReceivedString);
		_delay_ms(1000);
	}
	return 0;
}

void ReceiveCallback(void)
{
	DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_HIGH);
	_delay_ms(500);
	DIO_u8SetPinValue(DIO_u8_PORTA, DIO_u8_PIN3, DIO_u8_LOW);
	AsyncFlag = 1;
}
