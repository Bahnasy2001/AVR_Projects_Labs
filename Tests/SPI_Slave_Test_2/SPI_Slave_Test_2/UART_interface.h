/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 15/6/2024       *************************/
/*************************      SWC: UART           *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

void UART_voidInit(void);

void UART_voidSendByte(u8 Copy_u8DataByte);

u8   UART_u8ReceiveByte(u8 * Copy_pu8RecByte);

u8   UART_u8SendStringSynch(u8 * Copy_pu8String);

u8   UART_u8ReceiveStringSynch(u8 * Copy_puReceivedString, u8 Copy_u8MessageSize);

u8   UART_u8SendStringAsynch(u8* Copy_pu8String, void(*Copy_pf)(void));

u8   UART_u8ReceiveStringAsynch(u8* Copy_pu8ReceivedString, void(*Copy_pf)(void), u8 Copy_u8MessageSize);

#endif