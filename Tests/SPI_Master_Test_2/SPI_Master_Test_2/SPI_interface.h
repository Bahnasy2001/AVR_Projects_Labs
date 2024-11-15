/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 26/6/2024       *************************/
/*************************      SWC: SPI            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void SPI_voidInit(void);

u8   SPI_u8TransReceive(u8 Copy_u8TransmittedByte, u8 * Copy_pu8ReceivedByte);

void SPI_voidSlaveSendByte (u8 Copy_u8DataByte);

u8   SPI_u8ReceiveByte(u8 * Copy_pu8ReceivedByte);

u8   SPI_u8SendStringSynch(u8 * Copy_pu8TransmittedString);

u8   SPI_u8ReceiveStringSynch(u8 * Copy_pu8ReceivedString);

u8   SPI_u8SendStringAsynch(u8 * Copy_pu8TransmittedString, void(*Copy_pf)(void));

u8   SPI_u8ReceiveStringAsynch(u8 * Copy_pu8ReceivedString,void(*Copy_pf)(void));

u8   SPI_u8SendReceiveStringSynch(u8 * Copy_pu8TransmittedString,u8 * Copy_pu8ReceivedString);

u8   SPI_u8SendReceiveStringAsynch(u8 * Copy_pu8TransmittedString,u8 * Copy_pu8ReceivedString,void(*Copy_pf)(void));

#endif