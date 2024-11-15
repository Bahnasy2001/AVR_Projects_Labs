/****************************************************************************/
/************************* Name: Hassan Bahnasy     *************************/
/*************************    Date: 15/6/2024       *************************/
/*************************      SWC: UART           *************************/
/*************************    Version: 1.0          *************************/
/****************************************************************************/
#ifndef UART_PRIVATE_H
#define UART_PRIVATE_H

/* Registers & Bits Define */
#define UART_u8_UBRRH_REG               *((volatile u8*)0x40)
/***************************UCSRC Reg******************************************/
#define UART_u8_UCSRC_REG               *((volatile u8*)0x40)
#define UCSRC_URSEL                                7   //Register Select
#define UCSRC_UMSEL                                6   //USART Mode Select
#define UCSRC_UPM1                                 5   //Parity Mode bit 1
#define UCSRC_UPM0                                 4   //Parity Mode bit 0
#define UCSRC_USBS                                 3   //Stop Bit Select
#define UCSRC_UCSZ1                                2   //Character Size bit 1
#define UCSRC_UCSZ0                                1   //Character Size bit 0
#define UCSRC_UCPOL                                0   //Clock Polarity
/****************************************************************************/

#define UART_u8_UDR_REG                 *((volatile u8*)0x2C)

/***************************UCSRA Reg******************************************/
#define UART_u8_UCSRA_REG               *((volatile u8*)0x2B)
#define UCSRA_RXC                                 7  //USART Receive Complete
#define UCSRA_TXC                                 6  //USART Transmit Complete
#define UCSRA_UDRE                                5  //USART Data Register Empty
#define UCSRA_FE                                  4  //Frame Error
#define UCSRA_DOR                                 3  //Data OverRun
#define UCSRA_PE                                  2  //Parity Error
#define UCSRA_U2X                                 1  //Double the USART Transmission Speed
#define UCSRA_MPCM                                0  //Multi-processor Communication Mode
/****************************************************************************/

/***************************UCSRB Reg******************************************/
#define UART_u8_UCSRB_REG               *((volatile u8*)0x2A)
#define UCSRB_RXCIE                              7   //RX Complete Interrupt Enable
#define UCSRB_TXCIE                              6   //TX Complete Interrupt Enable
#define UCSRB_UDRIE                              5   //USART Data Register Empty Interrupt Enable
#define UCSRB_RXEN                               4   //Receiver Enable
#define UCSRB_TXEN                               3   //Transmitter Enable
#define UCSRB_UCSZ2                              2   //Character Size bit 2
#define UCSRB_RXB8                               1   //Receive Data Bit 8
#define UCSRB_TXB8                               0   //Transmit Data Bit 8
/****************************************************************************/
#define UART_u8_UBRRL_REG               *((volatile u8*)0x29)



/****************************Baud Rate*********************************/
#define UART_BAUDRATE_2400                 207
#define UART_BAUDRATE_4800                 103
#define UART_BAUDRATE_9600                 51
#define UART_BAUDRATE_14400                34 
#define UART_BAUDRATE_19200                25
#define UART_BAUDRATE_28800                16
#define UART_BAUDRATE_115200               3

/****************************UART Speed*********************************/
#define UART_u8_NORMAL_SPEED               1
#define UART_u8_DOUBLE_SPEED               2

/******************Multi-processor Communication Mode*******************/
#define UART_u8_DISABLE_MPM                1
#define UART_u8_ENABLE_MPM                 2


/****************************RX Interrupt Mode*********************************/
#define UART_u8_DISABLE_RXCIE              1
#define UART_u8_ENABLE_RXCIE               2

/****************************TX Interrupt Mode*********************************/
#define UART_u8_DISABLE_TXCIE              1
#define UART_u8_ENABLE_TXCIE               2

/****************************UDRIE Interrupt Mode*********************************/
#define UART_u8_DISABLE_UDRIE              1
#define UART_u8_ENABLE_UDRIE               2

/****************************Receiver Enable Mode*********************************/
#define UART_u8_DISABLE_RXEN               1
#define UART_u8_ENABLE_RXEN                2

/****************************Transmitter Enable Mode*********************************/
#define UART_u8_DISABLE_TXEN               1
#define UART_u8_ENABLE_TXEN                2

/****************************USART Mode Select************************************/
#define UART_u8_ASYNCH_MODE                1
#define UART_u8_SYNCH_MODE                 2

/****************************Parity Mode Select************************************/
#define UART_u8_PARITY_DISABLE             1
#define UART_u8_PARITY_EVEN                2
#define UART_u8_PARITY_ODD                 3

/****************************No of Stop Bit Select************************************/
#define UART_u8_ONE_BITS_STOP              1
#define UART_u8_TWO_BITS_STOP              2

#endif