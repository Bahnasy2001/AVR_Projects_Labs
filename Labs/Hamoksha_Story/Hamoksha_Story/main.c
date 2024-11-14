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
void FrameThree(void);
int main(void)
{
	setup();

	while(1)
	{
		FrameOne();
		_delay_ms(500);
		FrameTwo();
		_delay_ms(500);
		FrameThree();
		_delay_ms(500);
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
			0b00000100,
			0b00001010,
			0b00001010,
			0b00000100,
			0b00011111,
			0b00000100,
			0b00001010,
			0b00010001
	};
	for(i = 0;i <sizeof(customChar);i++)
	{
		LCD_voidSendChar(customChar[i]);
	}
}
void SpecialChar1(void)
{
	LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_1_COMMAND);
	u8 i;
	u8 customChar[] = {
			0b00001100,
			0b00010010,
			0b00010010,
			0b00001100,
			0b00001000,
			0b00001100,
			0b00001010,
			0b00001001
	};
	for(i = 0;i <sizeof(customChar);i++)
	{
		LCD_voidSendChar(customChar[i]);
	}
}
void SpecialChar2(void)//ball
{
	LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_2_COMMAND);
	u8 i;
	u8 customChar[] = {
			0b00000000,
			0b00000000,
			0b00000000,
			0b00001000,
			0b00010100,
			0b00010100,
			0b00001000,
			0b00000000
	};
	for(i = 0;i <sizeof(customChar);i++)
	{
		LCD_voidSendChar(customChar[i]);
	}
}
void SpecialChar3(void)//dance
{
	LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_3_COMMAND);
	u8 i;
	u8 customChar[] = {
			0b00000100,
			0b00001010,
			0b00001010,
			0b00010101,
			0b00001110,
			0b00000100,
			0b00011111,
			0b00000000
	};
	for(i = 0;i <sizeof(customChar);i++)
	{
		LCD_voidSendChar(customChar[i]);
	}
}
void FrameOne(void)
{
	LCD_u8GoToXY(LCD_u8_LINE1,2);
	LCD_voidWriteString("I am Hamoksha");
	SpecialChar0();
	LCD_u8GoToXY(LCD_u8_LINE2,7);
	LCD_voidSendChar(0);
	_delay_ms(500);
	LCD_voidClearScreen();
}
void FrameTwo(void)
{
	LCD_u8GoToXY(LCD_u8_LINE1,0);
	LCD_voidWriteString("I Play Football");
	SpecialChar1();
	SpecialChar2();
	LCD_u8GoToXY(LCD_u8_LINE2,7);
	LCD_voidSendChar(1);
	LCD_voidSendChar(2);
	_delay_ms(500);
	LCD_voidClearScreen();
}
void FrameThree(void)
{
	LCD_u8GoToXY(LCD_u8_LINE1,3);
	LCD_voidWriteString("I can dance");
	SpecialChar3();
	LCD_u8GoToXY(LCD_u8_LINE2,7);
	LCD_voidSendChar(3);
	_delay_ms(500);
	LCD_voidClearScreen();
}
