/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 7/3/2024        *************************/
/*************************      SWC: KPD            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#ifndef KPD_CONFIG_H
#define KPD_CONFIG_H


#define KPD_u8_PORT             DIO_u8_PORTC

#define KPD_u8_R1_PIN           DIO_u8_PIN0
#define KPD_u8_R2_PIN           DIO_u8_PIN1
#define KPD_u8_R3_PIN           DIO_u8_PIN2
#define KPD_u8_R4_PIN           DIO_u8_PIN3

#define KPD_u8_C1_PIN           DIO_u8_PIN4
#define KPD_u8_C2_PIN           DIO_u8_PIN5
#define KPD_u8_C3_PIN           DIO_u8_PIN6
#define KPD_u8_C4_PIN           DIO_u8_PIN7


#define C4  261
#define D4  293
#define E4  329
#define F4  349
#define G4  392
#define A4  440
#define B4  493
#define C5  523
#define D5  587
#define E5  659
#define F5  698
#define G5  783
#define A5  880
#define B5  987
#define C6  1046
#define D6  1174

#define KPD_KEYS               {{C4, D4, E4, F4},  \
								{G4, A4, B4, C5},  \
								{D5, E5, F5, G5},  \
								{A5, B5, C6, D6}}


#endif
