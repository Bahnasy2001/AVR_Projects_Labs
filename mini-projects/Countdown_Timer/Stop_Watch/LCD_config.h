/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 29/2/2024       *************************/
/*************************      SWC: LCD            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

/******************** Macros for LCD ********************/
/*Options: 1- DIO_u8_PORTA
		   2- DIO_u8_PORTB
		   3- DIO_u8_PORTC
           4- DIO_u8_PORTD */

#define LCD_u8_CTRL_PORT  DIO_u8_PORTA
#define LCD_u8_DATA_PORT  DIO_u8_PORTD

/*Options: 1- DIO_u8_PIN0
		   2- DIO_u8_PIN1
		   3- DIO_u8_PIN2
           4- DIO_u8_PIN3
           5- DIO_u8_PIN4
           6- DIO_u8_PIN5
           7- DIO_u8_PIN6
           8- DIO_u8_PIN7 */

#define LCD_u8_RS_PIN     DIO_u8_PIN0
#define LCD_u8_RW_PIN     DIO_u8_PIN1
#define LCD_u8_E_PIN      DIO_u8_PIN2

/********************************************************/
/*Options:1- LCD_u8_MODE_8_BIT
		  2- LCD_u8_MODE_4_BIT*/

#define LCD_u8_MODE       LCD_u8_MODE_8_BIT
/*********** Macros for LCD Commands ********************/
/*Options:  1- 0x38 --> 8bit-mode , 2 Lines , 5*7 dots
			2- 0x28 --> 4bit-mode , 2 Lines , 5*7 dots*/
#define LCD_u8_FUNCTION_SET_CMND  0x38
/********************************************************/
/*Options:  1- 0x0F --> Display on , Cursor Display on , Blinking on
			2-*/
#define LCD_u8_DISPLAY_CONTROL_CMND  0x0F
/********************************************************/
#define LCD_u8_DISPLAY_CLEAR_CMND   0x01
/********************************************************/
/*Options:  1- 0x06 --> Increase , no shift
			2-*/
#define LCD_u8_ENTRY_MODE_SET_CMND   0x06
/********************************************************/



#endif