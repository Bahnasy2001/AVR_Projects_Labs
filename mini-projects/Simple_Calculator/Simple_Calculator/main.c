/*
 * main.c
 *
 *  Created on: Mar 9, 2024
 *      Author: Hassan Bahnasy
 */

/* This code implements a simple calculator using an LCD and a keypad.
 It takes input from the keypad,
 stores it in a buffer, and evaluates the expression when the equals '=' key is pressed.
 The result is then displayed on the LCD.
 The code also handles clearing the screen and displaying error messages for invalid input.
 * */


/*Lib Layer*/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <util/delay.h>

/* MCAL Layer */
#include "DIO_interface.h"
/* HAL Layer */
#include "LCD_interface.h"
#include "KPD_interface.h"

u8 Local_u8Index = 0; // Index for buffer
u8 Local_Au8InputBuffer[10]= {0}; // Buffer to store input

/* Function prototypes */
void appenedToBuffer(u8 *buffer,u8 key);
void ClearBuffer(u8 *buffer,u8 size);
void evaluateExpression(u8 *buffer,u32 *Result);

int main(void)
{
	u8 Local_u8Key; // Variable to store pressed key
	u32 Local_u32Result = 0; // Variable to store result
	DIO_voidInit(); // Initialize DIO
	LCD_voidInit(); // Initialize LCD

	while(1)
	{
		KPD_u8GetKeyState(&Local_u8Key); // Get state of pressed key
		if(Local_u8Key != KPD_u8_KEY_NOT_PRESSED) // If a key is pressed
		{
			if(Local_u8Key == '=') // If pressed key is '='
			{
				LCD_voidSendChar(Local_u8Key); // Display '=' on LCD
				evaluateExpression(Local_Au8InputBuffer,&Local_u32Result);// Evaluate expression stored in buffer
				if(Local_u32Result != ' ')// If result is not an error
				{
					LCD_voidWriteNumber(Local_u32Result); // Display result on LCD
				}
			}
			else if(Local_u8Key == 'C') // If pressed key is 'C'
			{
				LCD_voidClearScreen(); // Clear LCD screen
				_delay_ms(20); // Delay for screen to clear
				ClearBuffer(Local_Au8InputBuffer,10);// Clear input buffer
				Local_u8Index = 0; // Reset buffer index
			}
			else // If pressed key is a number or operator
			{
				appenedToBuffer(Local_Au8InputBuffer,Local_u8Key); // Append pressed key to buffer
				LCD_voidSendChar(Local_u8Key); // Display pressed key on LCD
			}
		}
	}

	return 0;
}
/* Function to append a key to buffer */
void appenedToBuffer(u8 *buffer,u8 key)
{
	//while(*buffer != '\0')
	if (Local_u8Index < 10) // Check if buffer has space
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
	for (u8 i = 0; i < size; i++)// Loop through buffer
	{
		buffer[i] = '\0';// Set each element to null character
	}
}
/* Function to evaluate expression stored in buffer */
void evaluateExpression(u8 *buffer,u32 *Result)
{
	u16 num = 0; // Variable to store current number
	u32 resAddorSub = 0; // Variable to store addition/subtraction result
	u32 resMulorDiv = 1; // Variable to store multiplication/division result
	u8 op; // Variable to store current operator
	u8 i = 0; // Loop counter
	while(*(buffer+i) != '\0') // Loop until end of buffer is reached
	{
		if (buffer[i] >= '0' && buffer[i] <= '9') // If current character is a digit
		{
			// Build the number digit by digit
			num = num * 10 + (buffer[i] - '0');
		}
		else if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
		{
			// Update the operator
			op = buffer[i];
			// Perform the operation based on the previous operator
			switch (op)
			{
			case '+':
				resAddorSub += num;
				break;
			case '-':
				resAddorSub = num - resAddorSub;
				break;
			case '*':
				resMulorDiv *= num;
				break;
			case '/':
				resMulorDiv = num / resMulorDiv;
				break;
			}
			num = 0; // Reset number for next operand
		}
		i++; // Move to next character in buffer
	}
	// Perform final operation based on last operator
	switch (op)
	{
	case '+':
		resAddorSub += num;
		break;
	case '-':
		if(resAddorSub < num) // Check for negative result in subtraction
		{
			LCD_voidClearScreen(); // Clear LCD screen
			_delay_ms(20); // Delay for screen to clear
			LCD_voidWriteString((u8*)"Negative Num!  "); // Display error message
			*Result = ' '; // Indicate error
			return;
		}
		else
		{
			resAddorSub -= num;
		}
		break;
	case '*':
		resMulorDiv *= num;
		break;
	case '/':
		// Handle division by zero
		if (num != 0)
		{
			resMulorDiv /= num;
		}
		else
		{
			LCD_voidClearScreen(); // Clear LCD screen
			_delay_ms(20); // Delay for screen to clear
			LCD_voidWriteString((u8*)"Invalid!"); // Display error message
			*Result = ' '; // Indicate error
			return;
		}
		break;
	}
	// Set result to addition/subtraction result if last operator was '+' or '-',
	// otherwise set it to multiplication/division result
	*Result = (op == '*' || op == '/') ? resMulorDiv : resAddorSub;
}
