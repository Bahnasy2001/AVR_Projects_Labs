/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 15/6/2024       *************************/
/*************************      SWC: UART           *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef UART_CONFIG_H
#define UART_CONFIG_H

/* Options to Select Baud Rate */
/*
	1-UART_BAUDRATE_2400
	2-UART_BAUDRATE_4800
	3-UART_BAUDRATE_9600
	4-UART_BAUDRATE_14400
	5-UART_BAUDRATE_19200
	6-UART_BAUDRATE_28800
	7-UART_BAUDRATE_115200
*/
#define UART_u8_BAUD_RATE                  UART_BAUDRATE_9600


/* Options to Select Speed*/
/*
	1-UART_u8_NORMAL_SPEED
	2-UART_u8_DOUBLE_SPEED
*/
#define UART_u8_SPEED                      UART_u8_NORMAL_SPEED

/* Options to Multi-processor Communication Mode*/
/*
	1-UART_u8_DISABLE_MPM
	2-UART_u8_ENABLE_MPM
*/
#define UART_u8_MPM_MODE                   UART_u8_DISABLE_MPM 
/* Options to RX Interrupt Mode*/
/*
	1-UART_u8_DISABLE_RXCIE
	2-UART_u8_ENABLE_RXCIE
*/
#define UART_u8_RXCIE_MODE                 UART_u8_DISABLE_RXCIE


/* Options to TX Interrupt Mode*/
/*
	1-UART_u8_DISABLE_TXCIE
	2-UART_u8_ENABLE_TXCIE
*/
#define UART_u8_TXCIE_MODE                 UART_u8_DISABLE_TXCIE

/* Options to USART Data Register Empty Interrupt  Mode*/
/*
	1-UART_u8_DISABLE_UDRIE
	2-UART_u8_ENABLE_UDRIE
*/
#define UART_u8_UDRIE_MODE                 UART_u8_DISABLE_UDRIE

/* Options to Receiver Enable Mode*/
/*
	1-UART_u8_DISABLE_RXEN
	2-UART_u8_ENABLE_RXEN
*/
#define UART_u8_RXEN_MODE                  UART_u8_ENABLE_RXEN

/* Options to Transmitter Enable Mode*/
/*
	1-UART_u8_DISABLE_TXEN
	2-UART_u8_ENABLE_TXEN
*/
#define UART_u8_TXEN_MODE                  UART_u8_ENABLE_TXEN

/* Options to USART Mode Select*/
/*
	1-UART_u8_ASYNCH_MODE
	2-UART_u8_SYNCH_MODE
*/
#define UART_u8_USART_MODE                 UART_u8_ASYNCH_MODE

/* Options to Parity Mode*/
/*
	1-UART_u8_PARITY_DISABLE
	2-UART_u8_PARITY_EVEN
	3-UART_u8_PARITY_ODD
*/
#define UART_u8_PARITY_MODE                UART_u8_PARITY_DISABLE

/* Options to Stop Bit Select*/
/*
	1-UART_u8_ONE_BITS_STOP
	2-UART_u8_TWO_BITS_STOP
*/
#define UART_u8_NO_STOP_BITS              UART_u8_ONE_BITS_STOP

#define UART_u32_TIME_OUT_MAX_VALUE            500000
#endif
