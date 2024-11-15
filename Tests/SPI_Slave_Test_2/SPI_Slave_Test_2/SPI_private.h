/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 26/6/2024       *************************/
/*************************      SWC: SPI            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* Registers & Bits Define */
/****************************************************************************/
#define SPI_u8_SPDR_REG                      *((volatile u8*)0x2F)
/****************************************************************************/

/***************************SPCR Reg******************************************/
#define SPI_u8_SPCR_REG                      *((volatile u8*)0x2D)
#define SPCR_SPIE                                  7  //SPI Interrupt Enable
#define SPCR_SPE                                   6  //SPI Enable
#define SPCR_DORD                                  5  //Data Order
#define SPCR_MSTR                                  4  //Master/Slave Select
#define SPCR_CPOL                                  3  //Clock Polarity
#define SPCR_CPHA                                  2  //Clock Phase
#define SPCR_SPR1                                  1  //SPI Clock Rate Select 1
#define SPCR_SPR0                                  0  //SPI Clock Rate Select 0
/****************************************************************************/


/***************************SPCR Reg******************************************/
#define SPI_u8_SPSR_REG                      *((volatile u8*)0x2E)
#define SPSR_SPIF                                  7  //SPI Interrupt Flag
#define SPSR_WCOL                                  6  //Write COLlision Flag
#define SPSR_SPI2X                                 0  //Double SPI Speed Bit





/****************************SPI Mode Select************************************/
#define SPI_u8_MASTER_MODE               1
#define SPI_u8_SLAVE_MODE                2

/****************************SPI ISR Select************************************/
#define SPI_u8_TX_ISR                    1
#define SPI_u8_RX_ISR                    2
#define SPI_u8_TXRX_ISR                  3
#endif