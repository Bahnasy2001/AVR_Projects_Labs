/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 11/5/2024       *************************/
/*************************      SWC: TIMERS         *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMERS_voidTimer0Init(void);

void TIMERS_voidTimer1Init(void);

u8 TIMERS_u8GetTCNT0Value(u8 * Copy_pu8Value);

u8 TIMERS_u8Timer0SetCallBack(void(*Copy_pf)(void));

u8 TIMERS_u8Timer0CTCSetCallBack(void(*Copy_pf)(void));

u8 TIMERS_u8Timer1SetCallBack(void(*Copy_pf)(void));

u8 TIMERS_u8Timer1COMPASetCallBack(void(*Copy_pf)(void));

u8 TIMERS_u8Timer1COMPBSetCallBack(void(*Copy_pf)(void));

u8 TIMERS_u8Timer1CAPTSetCallBack(void(*Copy_pf)(void));

void TIMERS_voidTimer0SetCompareMatchValue(u8 Copy_u8OCR0Value);

void TIMERS_voidTimer1SetCompareMatchValueUnitA(u16 Copy_u16OCR1AValue);

void TIMERS_voidTimer1SetCompareMatchValueUnitB(u16 Copy_u16OCR1BValue);

void TIMERS_voidTimer1SetICR1Value(u16 Copy_u16ICR1Value);

u8 TIMERS_u8GetTCNT1Value(u16 * Copy_pu16Value);

void TIMERS_u8SetTCNT1Value(u16 * Copy_u16TCNT1Value);

#endif