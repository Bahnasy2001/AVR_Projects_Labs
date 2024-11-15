/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 29/2/2024       *************************/
/*************************      SWC: LCD            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define LCD_u8_LINE1    1
#define LCD_u8_LINE2    2

#define LCD_u8_CHAR0        0
#define LCD_u8_CHAR1        1
#define LCD_u8_CHAR2        2
#define LCD_u8_CHAR3        3
#define LCD_u8_CHAR4        4
#define LCD_u8_CHAR5        5
#define LCD_u8_CHAR6        6
#define LCD_u8_CHAR7        7

#define LCD_u8_FIRSTLINE_ADDRESS      0x80
#define LCD_u8_SECONDLINE_ADDRESS     0xC0

// Define macros for accessing custom characters in CGRAM
#define LCD_u8_CUSTOM_CHAR_0_ADDRESS  0x00 // Address of custom character 0 in CGRAM
#define LCD_u8_CUSTOM_CHAR_1_ADDRESS  0x08 // Address of custom character 1 in CGRAM
#define LCD_u8_CUSTOM_CHAR_2_ADDRESS  0x10 // Address of custom character 2 in CGRAM
#define LCD_u8_CUSTOM_CHAR_3_ADDRESS  0x18 // Address of custom character 3 in CGRAM
#define LCD_u8_CUSTOM_CHAR_4_ADDRESS  0x20 // Address of custom character 4 in CGRAM
#define LCD_u8_CUSTOM_CHAR_5_ADDRESS  0x28 // Address of custom character 5 in CGRAM
#define LCD_u8_CUSTOM_CHAR_6_ADDRESS  0x30 // Address of custom character 6 in CGRAM
#define LCD_u8_CUSTOM_CHAR_7_ADDRESS  0x38 // Address of custom character 7 in CGRAM
// Define macros for commands to access custom characters in CGRAM
#define LCD_SET_CGRAM_ADDRESS_COMMAND(address) ((address & 0b00111111) | 0b01000000)
#define LCD_u8_CUSTOM_CHAR_0_COMMAND LCD_SET_CGRAM_ADDRESS_COMMAND(LCD_u8_CUSTOM_CHAR_0_ADDRESS)
#define LCD_u8_CUSTOM_CHAR_1_COMMAND LCD_SET_CGRAM_ADDRESS_COMMAND(LCD_u8_CUSTOM_CHAR_1_ADDRESS)
#define LCD_u8_CUSTOM_CHAR_2_COMMAND LCD_SET_CGRAM_ADDRESS_COMMAND(LCD_u8_CUSTOM_CHAR_2_ADDRESS)
#define LCD_u8_CUSTOM_CHAR_3_COMMAND LCD_SET_CGRAM_ADDRESS_COMMAND(LCD_u8_CUSTOM_CHAR_3_ADDRESS)
#define LCD_u8_CUSTOM_CHAR_4_COMMAND LCD_SET_CGRAM_ADDRESS_COMMAND(LCD_u8_CUSTOM_CHAR_4_ADDRESS)
#define LCD_u8_CUSTOM_CHAR_5_COMMAND LCD_SET_CGRAM_ADDRESS_COMMAND(LCD_u8_CUSTOM_CHAR_5_ADDRESS)
#define LCD_u8_CUSTOM_CHAR_6_COMMAND LCD_SET_CGRAM_ADDRESS_COMMAND(LCD_u8_CUSTOM_CHAR_6_ADDRESS)
#define LCD_u8_CUSTOM_CHAR_7_COMMAND LCD_SET_CGRAM_ADDRESS_COMMAND(LCD_u8_CUSTOM_CHAR_7_ADDRESS)

// Define macros for shift patterns
#define LCD_u8_SHIFT_CURSOR_LEFT_CMND       0x10 // Shift cursor left (Decrement cursor position)
#define LCD_u8_SHIFT_CURSOR_RIGHT_CMND      0x14 // Shift cursor right (Increment cursor position)
#define LCD_u8_SHIFT_DISPLAY_LEFT_CMND      0x18 // Shift display left (Scroll display to the left)
#define LCD_u8_SHIFT_DISPLAY_RIGHT_CMND     0x1C // Shift display right (Scroll display to the right)

void LCD_voidInit(void);

void LCD_voidSendCmnd(u8 Copy_u8Cmnd);

void LCD_voidSendChar(u8 Copy_u8Char);

void LCD_voidWriteString(u8* Copy_pu8String);

void LCD_voidWriteNumber(u32 Copy_u32Number);

u8 LCD_u8GoToXY(u8 Copy_u8LineNum, u8 Copy_u8Location);

void LCD_voidClearScreen(void);

u8 LCD_voidWriteSpecialChar(u8 Copy_u8CharNum, u8* Copy_pu8Char,u8 Copy_u8LineNum, u8 Copy_u8Location);

void LCD_voidSendHalfCmnd(u8 Copy_u8HalfCmnd);


#endif