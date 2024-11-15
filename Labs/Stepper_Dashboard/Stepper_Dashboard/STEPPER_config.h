/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 25/3/2024       *************************/
/*************************      SWC: STEPPER        *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/

#ifndef STEPPER_CONFIG_H
#define STEPPER_CONFIG_H

#define STEPPER_u8_PORT           DIO_u8_PORTB

/********************************************************/
/*Options:1- STEPPER_u8_SINGLE_PHASE         Angle +|- Step angle/2
		  2- STEPPER_u8_DOUBLE_PHASE         Angle */

#define STEPPER_u8_MODE           STEPPER_u8_DOUBLE_PHASE

#define STEPPER_u8_PIN0           DIO_u8_PIN0
#define STEPPER_u8_PIN1           DIO_u8_PIN1
#define STEPPER_u8_PIN2           DIO_u8_PIN2
#define STEPPER_u8_PIN3           DIO_u8_PIN3




#endif