/*
 * main.c
 *
 *  Created on: Mar 5, 2024
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


void setup(void);
void SpecialChar0(void);
void SpecialChar1(void);
void SpecialChar2(void);
void SpecialChar3(void);
void FrameOne(void);
void FrameTwo(void);

int main(void)
{
	setup();

	while(1)
	{
		FrameOne();
		LCD_voidSendCmnd(LCD_u8_SHIFT_DISPLAY_RIGHT_CMND);
		_delay_ms(1000);
		FrameTwo();
	}
	return 0;
}
void setup(void)
{
	DIO_voidInit();
	LCD_voidInit();
}
void SpecialChar0(void)
{
	LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_0_COMMAND);
	u8 i;
	u8 customChar[] = {
			0b00000000,
			0b00000000,
			0b00011000,
			0b00000100,
			0b00000010,
			0b00011111,
			0b00000000,
			0b00000000
	};
	for(i = 0;i < sizeof(customChar);i++)
	{
		LCD_voidSendChar(customChar[i]);
	}
}
void SpecialChar1(void)
{
	LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_1_COMMAND);
	u8 i;
	u8 customChar[] = {
			0b00000000,
			0b00000000,
			0b00010101,
			0b00010101,
			0b00010101,
			0b00011111,
			0b00000000,
			0b00000000
	};
	for(i = 0;i < sizeof(customChar);i++)
	{
		LCD_voidSendChar(customChar[i]);
	}
}
void SpecialChar2(void)
{
	LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_2_COMMAND);
	u8 i;
	u8 customChar[] = {
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000000,
			0b00011111,
			0b00000000,
			0b00000000
	};
	for(i = 0;i < sizeof(customChar);i++)
	{
		LCD_voidSendChar(customChar[i]);
	}
}
void SpecialChar3(void)
{
	LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_3_COMMAND);
	u8 i;
	u8 customChar[] = {
			0b00000000,
			0b00000000,
			0b00000000,
			0b00000100,
			0b00010001,
			0b00010001,
			0b00001010,
			0b00000100
	};
	for(i = 0;i < sizeof(customChar);i++)
	{
		LCD_voidSendChar(customChar[i]);
	}
}
void FrameOne(void)
{
	LCD_voidWriteString(" Hassan");
	SpecialChar0();
	SpecialChar1();
	SpecialChar2();
	SpecialChar3();
	LCD_u8GoToXY(LCD_u8_LINE2,1);
	LCD_voidSendChar(3);
	LCD_voidSendChar(2);
	LCD_voidSendChar(1);
	LCD_voidSendChar(0);
	_delay_ms(1000);
	LCD_voidClearScreen();
}

void FrameTwo(void)
{
	SpecialChar0();
	SpecialChar1();
	SpecialChar2();
	SpecialChar3();
	LCD_u8GoToXY(LCD_u8_LINE1,7);
	LCD_voidSendChar(3);
	LCD_voidSendChar(2);
	LCD_voidSendChar(1);
	LCD_voidSendChar(0);
	LCD_u8GoToXY(LCD_u8_LINE2,6);
	LCD_voidWriteString(" Hassan");
	_delay_ms(1000);
	LCD_voidClearScreen();
}
