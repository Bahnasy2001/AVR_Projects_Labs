/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 14/4/2024       *************************/
/*************************      SWC: ADC            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

#define ADC_u32_TIME_OUT_MAX_VALUE            50000


/* Options for Vref
	1-ADC_u8_VREF_AREF
	2-ADC_u8_VREF_AVCC
	3-ADC_u8_VREF_VINTERNAL*/
#define ADC_u8_VREF_OPTION                   ADC_u8_VREF_AVCC

/* Options for Adjust
	1-ADC_u8_RIGHT_ADJUST
	2-ADC_u8_LEFT_ADJUST*/
#define ADC_u8_ADJUST_OPTION                ADC_u8_RIGHT_ADJUST

/* Options for auto trigger
	1-ADC_u8_AUTO_TRIGGER_DISABLE
	2-ADC_u8_AUTO_TRIGGER_ENABLE*/
#define ADC_u8_AUTO_TRIGGER_MODE            ADC_u8_AUTO_TRIGGER_DISABLE
/* Options for prescaler 
	1-ADC_u8_PRESCALER_2
	2-ADC_u8_PRESCALER_4
	3-ADC_u8_PRESCALER_8
	4-ADC_u8_PRESCALER_16
	5-ADC_u8_PRESCALER_32
	6-ADC_u8_PRESCALER_64
	7-ADC_u8_PRESCALER_128*/
#define ADC_u8_PRESCALER                    ADC_u8_PRESCALER_64
/* Options for ADC auto-trigger source
	1-ADC_u8_AUTO_TRIGGER_FREE_RUNNING
	2-ADC_u8_AUTO_TRIGGER_ANALOG_COMPARATOR
	3-ADC_u8_AUTO_TRIGGER_EXTERNAL_INTERRUPT
	4-ADC_u8_AUTO_TRIGGER_TIMER0_COMPARE_MATCH_A
	5-ADC_u8_AUTO_TRIGGER_TIMER0_OVERFLOW
	6-ADC_u8_AUTO_TRIGGER_TIMER_COMPARE_MATCH_B
	7-ADC_u8_AUTO_TRIGGER_TIMER1_OVERFLOW
	8-ADC_u8_AUTO_TRIGGER_TIMER1_CAPTURE_EVENT*/
#define ADC_u8_AUTO_TRIGGER_MODE            ADC_u8_AUTO_TRIGGER_FREE_RUNNING


#endif