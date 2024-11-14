/*
 * main.c
 *
 *  Created on: May 13, 2024
 *      Author: Hassan Bahnasy
 */
/* LIB Layer */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/* MCAL Layer */
#include "DIO_interface.h"
#include "GI_interface.h"
#include "TIMERS_interface.h"
/* HAL Layer */
#include "LCD_interface.h"
#include "KPD_interface.h"

volatile u8 hours = 0;
volatile u8 minutes = 0;
volatile u8 seconds = 0;
static u8 Cursor = 8;//Set Cursor equal 8 because this index the LCD stopped on it
void Stop_Watch(void);
void LCD_Display_Time(void);
void move_CursorRight(void);
void move_CursorLeft(void);
void Set_Number(u8 * Key);
void Check_Correct(void);
void LED_ON(void);
int main(void)
{
	u8 Local_u8Key;
	DIO_voidInit();
	GI_voidEnableGI();
	LCD_voidInit();
	TIMERS_u8Timer0CTCSetCallBack(&Stop_Watch);
	LCD_voidWriteString((u8*)"--:--:--");
	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key);
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED)
		{
			if(Local_u8Key >= '0'  && Local_u8Key <= '9')
			{
				LCD_voidSendChar(Local_u8Key);
				Set_Number(&Local_u8Key);
			}
			else if( Local_u8Key == '+')
			{
				if (Cursor == 8)
				{

				}
				else
				{
					move_CursorRight();
				}
			}
			else if(Local_u8Key == '-')
			{
				if (Cursor == 0)
				{

				}
				else
				{
					move_CursorLeft();
				}
			}
			else if (Local_u8Key == '=')
			{
				Cursor = 0;
				LCD_u8GoToXY(LCD_u8_LINE1,Cursor);
				Check_Correct();
				LCD_Display_Time();
				TIMERS_voidTimer0Init();
			}
		}
	}
	return 0;
}

void Stop_Watch(void)
{
	LCD_voidClearScreen();
	if (seconds > 0)
	{
		seconds--;
	}
	else
	{
		if (minutes > 0)
		{
			minutes--;
			seconds = 59;
		}
		else
		{
			if (hours > 0)
			{
				hours--;
				minutes = 59;
				seconds = 59;
			}
		}
	}
	LCD_Display_Time();
}

void LCD_Display_Time(void)
{
	LCD_voidWriteNumberTwoDigits((u32)hours);
	LCD_voidWriteString((u8*)":");
	LCD_voidWriteNumberTwoDigits((u32)minutes);
	LCD_voidWriteString((u8*)":");
	LCD_voidWriteNumberTwoDigits((u32)seconds);
	if(seconds == 0 && minutes == 0 && hours == 0 )
	{
		LCD_voidClearScreen();
		LCD_voidWriteString((u8 *)"Finish!");
		while(1)
		{
			LED_ON();
		}
	}
}
void move_CursorRight(void)
{
	LCD_u8GoToXY(LCD_u8_LINE1,++Cursor);
}
void move_CursorLeft(void)
{
	LCD_u8GoToXY(LCD_u8_LINE1,--Cursor);
}
void Set_Number(u8 * Key)
{
	switch(Cursor)
	{
	case 0:
		hours += 10 * (*Key - '0');
		break;
	case 1:
		hours += *Key - '0';
		break;
	case 2:
		break;
	case 3:
		minutes += 10 * (*Key - '0');
		break;
	case 4:
		minutes += *Key - '0';
		break;
	case 5:
		break;
	case 6:
		seconds += 10 * (*Key - '0');
		break;
	case 7:
		seconds += *Key - '0';
		break;
	default:
		break;
	}
}
void Check_Correct(void)
{
	if (seconds > 59 || minutes > 59 || hours > 23)
	{
		LCD_voidClearScreen();
		LCD_voidWriteString((u8 *)"Invalid Stop Watch");
		while(1);
	}
}
void LED_ON(void)
{
	DIO_u8SetPinValue(DIO_u8_PORTB,DIO_u8_PIN0,DIO_u8_HIGH);
}
