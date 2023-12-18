#ifndef UART_INTERFACE_H_
#define UART_INTERFACE_H_


/* USART Mode Select */

#define USART_MODE_SELECT_ASYNCHRONOUS          0
#define USART_MODE_SELECT_SYNCHRONOUS           1

/* Parity Enable */

#define USART_PARITY_DISABLE                    0
#define USART_PARITY_ENABLE                     1


/* Parity Mode */

#define USART_PARITY_MODE_EVEN                  0
#define USART_PARITY_MODE_ODD                   1


/* Stop Bit Select*/

#define  USART_STOP_ONE_BIT                       0b00
#define  USART_STOP_HALF_BIT                      0b01
#define  USART_STOP_ONE_AND_HALF_BIT              0b11
#define  USART_STOP_TWO_BIT                       0b10

/*Data size*/

#define USART_DATA_SIZE_8_BIT                   0
#define USART_DATA_SIZE_9_BIT                   1


/* Clock options */
//(FOR SYNCHRONOUS MODE ONLY! )
#define USART_RECIVE_RISING_SEND_FALLING        0b00   
#define USART_SEND_RISING_RECIVE_FALLING        0b01
#define USART_RECIVE_FALLING_SEND_RISING        0b10
#define USART_SEND_FALLNIG_RECIVE_RISING        0b11



/*Baud Rate (bps)  (FOR 8MHZ only)*/
#define USART_BAUD_RATE_2400 0
#define USART_BAUD_RATE_4800 1
#define USART_BAUD_RATE_9600 2
#define USART_BAUD_RATE_14400 3
#define USART_BAUD_RATE_19200 4
#define USART_BAUD_RATE_28800 5
#define USART_BAUD_RATE_38400 6
#define USART_BAUD_RATE_57600 7
#define USART_BAUD_RATE_76800 8





/*USART struct */

typedef struct {

	u8 baud_rate;
	u8 USART_mode;
	u8 Clock_option;
    u8 Parity_Enable;
	u8 Parity_Mode;
	u8 num_of_Stop_bits;
	u8 data_size;
}USART_str;


void MUART1_voidInit(USART_str * Add_UARTptr);
void MUART1_voidSend(u8 arr[]);
u8   MUART1_u8Recive();

#endif
