/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 7/6/2024        *************************/
/*************************      SWC: WDT            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef WDT_PRIVATE_H
#define WDT_PRIVATE_H

/* Registers Define */
#define WDT_u8_WDTCR_REG                  *((volatile u8*)0x41)

/* Define Macros For Options for Selecting Clock Source */
#define WDT_u8_PRESCALER_16                    1       //16.3 ms
#define WDT_u8_PRESCALER_32                    2       //32.5 ms
#define WDT_u8_PRESCALER_64                    3       //65 ms
#define WDT_u8_PRESCALER_128                   4       //0.13 s
#define WDT_u8_PRESCALER_256                   5       //0.26 s
#define WDT_u8_PRESCALER_512                   6       //0.52 s
#define WDT_u8_PRESCALER_1024                  7       //1.0 s
#define WDT_u8_PRESCALER_2048                  8       //2.1 s


#endif