/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 14/4/2024       *************************/
/*************************      SWC: ADC            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H


#define ADC_u8_CHANNEL_0                   0
#define ADC_u8_CHANNEL_1                   1
#define ADC_u8_CHANNEL_2                   2
#define ADC_u8_CHANNEL_3                   3
#define ADC_u8_CHANNEL_4                   4
#define ADC_u8_CHANNEL_5                   5
#define ADC_u8_CHANNEL_6                   6
#define ADC_u8_CHANNEL_7                   7
#define ADC_u8_CHANNEL_00x10               8
#define ADC_u8_CHANNEL_10x10               9
#define ADC_u8_CHANNEL_00x200              10
#define ADC_u8_CHANNEL_10x200              11
#define ADC_u8_CHANNEL_22x10               12
#define ADC_u8_CHANNEL_32x10               13
#define ADC_u8_CHANNEL_22x200              14
#define ADC_u8_CHANNEL_32x200              15
#define ADC_u8_CHANNEL_01x1                16
#define ADC_u8_CHANNEL_11x1                17
#define ADC_u8_CHANNEL_21x1                18
#define ADC_u8_CHANNEL_31x1                19
#define ADC_u8_CHANNEL_41x1                20
#define ADC_u8_CHANNEL_51x1                21
#define ADC_u8_CHANNEL_61x1                22
#define ADC_u8_CHANNEL_71x1                23
#define ADC_u8_CHANNEL_02x1                24
#define ADC_u8_CHANNEL_12x1                25
#define ADC_u8_CHANNEL_22x1                26
#define ADC_u8_CHANNEL_32x1                27
#define ADC_u8_CHANNEL_42x1                28
#define ADC_u8_CHANNEL_52x1                29
#define ADC_u8_CHANNEL_VBG                 30
#define ADC_u8_CHANNEL_GND                 31




void ADC_voidInit(void);

u8 ADC_u8GetDigitalValueSynchNonBlocking(u8 Copy_u8ChannelNb, u16 *Copy_pu16DigitalValue);

u8 ADC_u8GetDigitalValueAsynch(u8 Copy_u8ChannelNb, void (*Copy_pfNotification) (u16));

u8 ADC_u8GetADCRegValue (u16 * Copy_pu16ADCValue);

#endif