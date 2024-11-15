/*
 * main.c
 *
 *  Created on: Mar 1, 2024
 *      Author: Hassan Bahnasy
 */

/* Lib Layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#define F_CPU 8000000UL
#include <util/delay.h>
/* MCAL Layer */
#include "DIO_interface.h"


/* HAL Layer */
#include "LCD_interface.h"

int main(void)
{
	/*Initialization*/
	DIO_voidInit();
	LCD_voidInit();
	//	/* Code For Writing Special Char in CGRAM */
	//	/*Step 1: SET CGRAM Address in AC*/
	//	LCD_voidSendCmnd(0b01000000);//CGRAM first Byte
	//
	//	LCD_voidSendChar(0b00011111);
	//	LCD_voidSendChar(0b00001110);
	//	LCD_voidSendChar(0b00011111);
	//	LCD_voidSendChar(0b00000100);
	//	LCD_voidSendChar(0b00001110);
	//	LCD_voidSendChar(0b00011111);
	//	LCD_voidSendChar(0b00000100);
	//	LCD_voidSendChar(0b00000100);
	//
	//	/* Special Char 2 --> 16byte */
	//	LCD_voidSendCmnd(0b01010000);
	//
	//	LCD_voidSendChar(0b00011111);
	//	LCD_voidSendChar(0b00000000);
	//	LCD_voidSendChar(0b00001110);
	//	LCD_voidSendChar(0b00000100);
	//	LCD_voidSendChar(0b00001110);
	//	LCD_voidSendChar(0b00000100);
	//	LCD_voidSendChar(0b00000100);
	//	LCD_voidSendChar(0b00000100);
	//
	//	/* AC ==> DDRAM*/
	//	LCD_u8GoToXY(LCD_u8_LINE1,5);
	//
	//	LCD_voidSendChar(0);
	//	LCD_voidSendChar(2);
	u8 customChar0[] = {
			0b00000000,
			0b00000000,
			0b00001110,
			0b00001110,
			0b00001110,
			0b00001110,
			0b00001110,
			0b00001110
	};
	LCD_voidWriteSpecialChar(LCD_u8_CHAR0,customChar0,LCD_u8_LINE2,6);
	u8 customChar1[] = {
			0b00000000,
			0b00000111,
			0b00001000,
			0b00001000,
			0b00000111,
			0b00000010,
			0b00011100,
			0b00000000
	};
	LCD_voidWriteSpecialChar(LCD_u8_CHAR1,customChar1,LCD_u8_LINE1,6);
	while(1)
	{

	}

	return 0;
}
