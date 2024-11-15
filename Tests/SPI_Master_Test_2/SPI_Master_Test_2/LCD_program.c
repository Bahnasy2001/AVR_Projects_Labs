/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 29/2/2024       *************************/
/*************************      SWC: LCD            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
/************* Lib Layer *********************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#define F_CPU 8000000UL
#include <util/delay.h>

/************* MCAL Layer ********************/
#include "DIO_interface.h"

/************* HAL Layer *********************/
#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

/************** APIs *************************/
void LCD_voidInit(void) 
{
	/* Step 1: delay more than 30 ms for waiting VDD raises to 4.5 V*/
	_delay_ms(35);
	/* Step 2: Function Set Command
	1- DL: 1 --> 8 bit-mode
	2- N:  1 --> 2 lines
	3- F:  0 --> 5 * 7 dots */
#if LCD_u8_MODE == LCD_u8_MODE_8_BIT
	LCD_voidSendCmnd(LCD_u8_FUNCTION_SET_CMND);
#elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
	LCD_voidSendHalfCmnd(0b0010);
	LCD_voidSendCmnd(LCD_u8_FUNCTION_SET_CMND);
#endif
	_delay_us(40); //Step 3: wait 39 us
	/* Step 4: DisplayControl Command
	1- D:  1 --> Display on
	2- C:  1 --> Cursor Display on
	3- B:  1 --> Blinking on */
	LCD_voidSendCmnd(LCD_u8_DISPLAY_CONTROL_CMND);
	_delay_us(40); //Step 5: wait 39 us
	/* Step 6: Display Clear Command*/
	LCD_voidSendCmnd(LCD_u8_DISPLAY_CLEAR_CMND);
	_delay_ms(2); //Step 7:wait more than 1.53 ms
	/* Step 8: Entry Mode Set Command
	1- I/D: 1 --> Increase
	2- SH: 0 --> no shift*/
	LCD_voidSendCmnd(LCD_u8_ENTRY_MODE_SET_CMND);


}

void LCD_voidSendCmnd(u8 Copy_u8Cmnd)
{
#if LCD_u8_MODE == LCD_u8_MODE_8_BIT
	/* Step 1: RS = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/* Step 2: RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* Step 3: Write Command  */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd);
	/* Step 4: E = 1 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1); //wait tw = 230 ns
	/* Step 5: E = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	_delay_us(1); // wait tc = 500ns (not important because 1 us in step 4 is enough because >>> 230ns )
#elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
	/* Code to Send a Command at 4 bit mode*/
	/* Step 1: RS = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/* Step 2: RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* Step 3: Write Command  */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd);
	/* Step 4: E = 1 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1); //wait tw = 230 ns
	/* Step 5: E = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	_delay_us(1); // wait tc = 500ns (not important because 1 us in step 4 is enough because >>> 230ns )
	/* Step 6: Write Command << 4 */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Cmnd<<4);
	/* Step 7: E = 1 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1); //wait tw = 230 ns
	/* Step 8: E = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	_delay_us(1); // wait tc = 500ns (not important because 1 us in step 4 is enough because >>> 230ns )

#endif

}

void LCD_voidSendChar(u8 Copy_u8Char)
{
#if LCD_u8_MODE == LCD_u8_MODE_8_BIT
	/* Step 1: RS = 1 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	/* Step 2: RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* Step 3: Write Char  */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);
	/* Step 4: E = 1 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1); //wait tw = 230 ns
	/* Step 5: E = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	_delay_us(1); // wait tc = 500ns (not important because 1 us in step 4 is enough because >>> 230ns )
#elif LCD_u8_MODE == LCD_u8_MODE_4_BIT
	/* Step 1: RS = 1 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_HIGH);
	/* Step 2: RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* Step 3: Write Char  */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char);
	/* Step 4: E = 1 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1); //wait tw = 230 ns
	/* Step 5: E = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	_delay_us(1); // wait tc = 500ns (not important because 1 us in step 4 is enough because >>> 230ns )
	/* Step 6: Write Char <<4 */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8Char<<4);
	/* Step 7: E = 1 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1); //wait tw = 230 ns
	/* Step 8: E = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	_delay_us(1); // wait tc = 500ns (not important because 1 us in step 4 is enough because >>> 230ns )

#endif
}

void LCD_voidWriteString(u8* Copy_pu8String)
{
	// Iterate through the string until the null terminator ('\0') is encountered
	while(*Copy_pu8String != '\0')
	{
		// Send each character of the string to the LCD
		LCD_voidSendChar(*Copy_pu8String);
		// Move to the next character in the string
		Copy_pu8String++;
	}
}

void LCD_voidWriteNumber(u32 Copy_u32Number)
{
	// Temporary array to store digits of the number
	u8 digits[15];
	// Index to keep track of the current digit position
	s8 index = -1; // Start from -1 to accommodate numbers with zero
	s8 i;
	// Special case for handling zero separately
	if (Copy_u32Number == 0)
    {
        LCD_voidSendChar('0');
        return;
    }
    // Extract each digit of the number and store in the temporary array
    while(Copy_u32Number > 0)
    {
    	index++;
    	digits[index] = Copy_u32Number % 10; // Extract the last digit
    	Copy_u32Number /= 10; // Move to the next digit
    }

    // Write the digits to the LCD in reverse order
    for (i = index; i >= 0; i--)
    {
    	// Convert digit to character and send to LCD
    	LCD_voidSendChar(digits[i] +'0');
    }

}
u8 LCD_u8GoToXY(u8 Copy_u8LineNum, u8 Copy_u8Location)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if(Copy_u8Location <= 39)
	{
		switch(Copy_u8LineNum)
		{
			case LCD_u8_LINE1:LCD_voidSendCmnd(LCD_u8_FIRSTLINE_ADDRESS + Copy_u8Location);break;
			case LCD_u8_LINE2:LCD_voidSendCmnd(LCD_u8_SECONDLINE_ADDRESS + Copy_u8Location);break;
			default:Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	return Local_u8ErrorState;
}
void LCD_voidClearScreen(void)
{
	LCD_voidSendCmnd(LCD_u8_DISPLAY_CLEAR_CMND);
	_delay_ms(20);
}

u8 LCD_voidWriteSpecialChar(u8 Copy_u8CharNum, u8* Copy_pu8Char,u8 Copy_u8LineNum, u8 Copy_u8Location)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	const u8 size = 8;
	u8 i;
	switch(Copy_u8CharNum)
	{
	case LCD_u8_CHAR0:
		LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_0_COMMAND);
		for(i = 0;i < size; i++)
		{
			LCD_voidSendChar(Copy_pu8Char[i]);
		}
		LCD_u8GoToXY(Copy_u8LineNum,Copy_u8Location);
		LCD_voidSendChar(Copy_u8CharNum);
		break;
	case LCD_u8_CHAR1:
		LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_1_COMMAND);
		for(i = 0;i < size; i++)
		{
			LCD_voidSendChar(Copy_pu8Char[i]);
		}
		LCD_u8GoToXY(Copy_u8LineNum,Copy_u8Location);
		LCD_voidSendChar(Copy_u8CharNum);
		break;
	case LCD_u8_CHAR2:
		LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_2_COMMAND);
		for(i = 0;i < size; i++)
		{
			LCD_voidSendChar(Copy_pu8Char[i]);
		}
		LCD_u8GoToXY(Copy_u8LineNum,Copy_u8Location);
		LCD_voidSendChar(Copy_u8CharNum);
		break;
	case LCD_u8_CHAR3:
		LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_3_COMMAND);
		for(i = 0;i < size; i++)
		{
			LCD_voidSendChar(Copy_pu8Char[i]);
		}
		LCD_u8GoToXY(Copy_u8LineNum,Copy_u8Location);
		LCD_voidSendChar(Copy_u8CharNum);
		break;
	case LCD_u8_CHAR4:
		LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_4_COMMAND);
		for(i = 0;i < size; i++)
		{
			LCD_voidSendChar(Copy_pu8Char[i]);
		}
		LCD_u8GoToXY(Copy_u8LineNum,Copy_u8Location);
		LCD_voidSendChar(Copy_u8CharNum);
		break;
	case LCD_u8_CHAR5:
		LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_5_COMMAND);
		for(i = 0;i < size; i++)
		{
			LCD_voidSendChar(Copy_pu8Char[i]);
		}
		LCD_u8GoToXY(Copy_u8LineNum,Copy_u8Location);
		LCD_voidSendChar(Copy_u8CharNum);
		break;
	case LCD_u8_CHAR6:
		LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_6_COMMAND);
		for(i = 0;i < size; i++)
		{
			LCD_voidSendChar(Copy_pu8Char[i]);
		}
		LCD_u8GoToXY(Copy_u8LineNum,Copy_u8Location);
		LCD_voidSendChar(Copy_u8CharNum);
		break;
	case LCD_u8_CHAR7:
		LCD_voidSendCmnd(LCD_u8_CUSTOM_CHAR_7_COMMAND);
		for(i = 0;i < size; i++)
		{
			LCD_voidSendChar(Copy_pu8Char[i]);
		}
		LCD_u8GoToXY(Copy_u8LineNum,Copy_u8Location);
		LCD_voidSendChar(Copy_u8CharNum);
		break;
	default:Local_u8ErrorState = STD_TYPES_NOK;
	}
	return Local_u8ErrorState;
}

void LCD_voidSendHalfCmnd(u8 Copy_u8HalfCmnd)
{
	/* Step 1: RS = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RS_PIN,DIO_u8_LOW);
	/* Step 2: RW = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_RW_PIN,DIO_u8_LOW);
	/* Step 3: Write Command  */
	DIO_u8SetPortValue(LCD_u8_DATA_PORT,Copy_u8HalfCmnd<<4);
	/* Step 4: E = 1 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_HIGH);
	_delay_us(1); //wait tw = 230 ns
	/* Step 5: E = 0 */
	DIO_u8SetPinValue(LCD_u8_CTRL_PORT,LCD_u8_E_PIN,DIO_u8_LOW);
	_delay_us(1); // wait tc = 500ns (not important because 1 us in step 4 is enough because >>> 230ns )
}