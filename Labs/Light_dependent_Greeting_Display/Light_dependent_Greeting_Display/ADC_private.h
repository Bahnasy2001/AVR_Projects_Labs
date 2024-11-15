/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 14/4/2024       *************************/
/*************************      SWC: ADC            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef ADC_PRIVATE_H
#define ADC_PRIVATE_H


/* Define for ADC Registers */

#define ADC_u8_ADMUX_REG       *((volatile u8 *)0x27)
#define ADC_u8_ADCSRA_REG      *((volatile u8 *)0x26)
#define ADC_u8_ADCH_REG        *((volatile u8 *)0x25)
#define ADC_u8_ADCL_REG        *((volatile u8 *)0x24)


#define ADC_u16_ADC_REG        *((volatile u16 *)0x24)

#define ADC_u8_SFIOR_REG        *((volatile u8 *)0x50)




/* Define Macros for Options Vref */
#define ADC_u8_VREF_AREF         1
#define ADC_u8_VREF_AVCC         2
#define ADC_u8_VREF_VINTERNAL    3

/* Define Macros for Options adjust */
#define ADC_u8_RIGHT_ADJUST      1
#define ADC_u8_LEFT_ADJUST       2

/* Define Macros for Options auto trigger */
#define ADC_u8_AUTO_TRIGGER_DISABLE     1
#define ADC_u8_AUTO_TRIGGER_ENABLE      2

/* Define Macros for Options prescaler */
#define ADC_u8_PRESCALER_2              1
#define ADC_u8_PRESCALER_4              2
#define ADC_u8_PRESCALER_8              3
#define ADC_u8_PRESCALER_16             4
#define ADC_u8_PRESCALER_32             5
#define ADC_u8_PRESCALER_64             6
#define ADC_u8_PRESCALER_128            7

/* Define macros for ADC auto-trigger source selections */
#define ADC_u8_AUTO_TRIGGER_FREE_RUNNING                1       // Free running mode (no auto-trigger)
#define ADC_u8_AUTO_TRIGGER_ANALOG_COMPARATOR           2       // Analog Comparator
#define ADC_u8_AUTO_TRIGGER_EXTERNAL_INTERRUPT          3       // External Interrupt Request 0
#define ADC_u8_AUTO_TRIGGER_TIMER0_COMPARE_MATCH_A      4       // Timer/Counter0 Compare Match A
#define ADC_u8_AUTO_TRIGGER_TIMER0_OVERFLOW             5       // Timer/Counter0 Overflow
#define ADC_u8_AUTO_TRIGGER_TIMER_COMPARE_MATCH_B       6       // Timer/Counter Compare Match B
#define ADC_u8_AUTO_TRIGGER_TIMER1_OVERFLOW             7       // Timer/Counter1 Overflow
#define ADC_u8_AUTO_TRIGGER_TIMER1_CAPTURE_EVENT        8       // Timer/Counter1 Capture Event

#endif