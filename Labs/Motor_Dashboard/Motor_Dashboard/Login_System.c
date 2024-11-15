/*
 * Login_System.c
 *
 *  Created on: Mar 21, 2024
 *      Author: Hassan Bahnasy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>
#include "KPD_interface.h"
#include "LCD_interface.h"
#include "Login_System.h"

u8 Local_u8Index = 0; // Index for buffer
u8 Local_Au8InputBuffer[5] = {0}; // Buffer to store input
u8 trials = 0;
/* Function to append a key to buffer */
void appenedToBuffer(u8 *buffer,u8 key)
{
	if(Local_u8Index < 4) // Make sure buffer index is within range
	{
		*(buffer+Local_u8Index) = key; // Store the character in buffer
		Local_u8Index++; // Increment buffer index
		*(buffer+Local_u8Index) = '\0';// Null-terminate buffer
	}
}
/* Function to clear buffer */
void ClearBuffer(u8 *buffer,u8 size)
{
	u8 i;
	for (i = 0; i < size; i++)// Loop through buffer
	{
		buffer[i] = '\0';// Set each element to null character
	}
}
void CheckPassword(u8* buffer,u8* password,u8* Result)
{
	u8 i = 0; // Loop counter
	u8 Password_Flag = 0; // 0 mean incorrect
	while((*(buffer+i) != '\0') && (*(password+i)!= '\0'))
	{
		if(buffer[i] == password[i])
		{
			Password_Flag = 1;
		}
		else
		{
			Password_Flag = 0;
			break;
		}
		i++;
	}
	*Result = Password_Flag;
}
void login_system(const u8* password, u8* flag)
{
	u8 Local_u8Key;
	u8 Local_u8Result;
	LCD_voidWriteString((u8*)"Enter Password: ");
	LCD_u8GoToXY(LCD_u8_LINE2,0);
	while(1)
	{
		if(trials < 3)
		{
			KPD_u8GetKeyState(&Local_u8Key); // Get state of pressed key
			if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED) // If a key is pressed
			{
				if(Local_u8Key == '=') // If pressed key is '='
				{
					CheckPassword(Local_Au8InputBuffer,password,&Local_u8Result);
					if(Local_u8Result)
					{
						LCD_voidClearScreen();
						_delay_ms(20);
						LCD_voidWriteString((u8*)"Correct Password!");
						*flag = 1;
						break;
					}
					else
					{
						LCD_voidClearScreen();
						_delay_ms(20);
						LCD_voidWriteString((u8*)"Wrong Password!");
						_delay_ms(1000);
						if(trials < 2) // display try again for twice only
						{
							LCD_voidClearScreen();
							_delay_ms(20);
							LCD_voidWriteString((u8*)"Try Again!");
							_delay_ms(1000);
						}
						trials++;
						Local_u8Index = 0;
						ClearBuffer(Local_Au8InputBuffer,5);
						if(trials <= 2) // For Last trial that will not display try again
						{
							LCD_voidClearScreen();
							_delay_ms(20);
							LCD_voidWriteString((u8*)"Enter Password: ");
							LCD_u8GoToXY(LCD_u8_LINE2,0);
						}
					}
				}
				else  // If pressed key is a number or operator
				{
					appenedToBuffer(Local_Au8InputBuffer,Local_u8Key); // Append pressed key to buffer
					LCD_voidSendChar('*'); // Display pressed key on LCD
				}
			}
		}
		else if ( trials == 3) // to make sure this won't execute the else before trails run out
		{
			LCD_voidClearScreen();
			_delay_ms(20);
			LCD_voidWriteString((u8*)"Failed Login ");
			*flag = 0;
			break;
		}
	}
}
