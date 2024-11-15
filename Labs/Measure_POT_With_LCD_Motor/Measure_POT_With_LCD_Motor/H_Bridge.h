/*
 * H_Bridge.h
 *
 *  Created on: Mar 22, 2024
 *      Author: Hassan Bahnasy
 */

#ifndef H_BRIDGE_H_
#define H_BRIDGE_H_

#define LOOP           1
#define WITHOUT_LOOP   2

#define H_BRIDGE_u8_PORT     DIO_u8_PORTB
#define H_BRIDGE_u8_PIN0     DIO_u8_PIN0
#define H_BRIDGE_u8_PIN1     DIO_u8_PIN1

#define H_BRIDGE_MODE        WITHOUT_LOOP

/* Function prototypes */
void H_BRIDGE_voidRotateCW(void);
void H_BRIDGE_voidRotateCCW(void);



#endif /* H_BRIDGE_H_ */
