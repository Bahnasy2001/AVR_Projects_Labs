/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 11/5/2024       *************************/
/*************************      SWC: TIMERS         *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

void TIMERS_voidTimer0Init(void);

u8 TIMERS_u8GetTCNT0Value(u8 * Copy_pu8Value);

u8 TIMERS_u8Timer0SetCallBack(void(*Copy_pf)(void));

u8 TIMERS_u8Timer0CTCSetCallBack(void(*Copy_pf)(void));

#endif