/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 26/6/2024       *************************/
/*************************      SWC: SPI            *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef SPI_CONFIG
#define SPI_CONFIG

/* Options To Select Mode:
 	1-SPI_u8_MASTER_MODE
 	2-SPI_u8_SLAVE_MODE
*/
#define SPI_u8_MODE                SPI_u8_SLAVE_MODE

#define SPI_u32_TIMEOUT_MAX_VALUE     1000000

/* Options To Select ISR:
 	1-SPI_u8_TX_ISR
 	2-SPI_u8_RX_ISR
 	3-SPI_u8_TXRX_ISR
*/
#define SPI_u8_ISR                        SPI_u8_TXRX_ISR
#endif
