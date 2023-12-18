#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUART1_voidInit(USART_str * Add_UARTptr)
{
     switch (Add_UARTptr->baud_rate)
     {
     case USART_BAUD_RATE_9600 : MUART1->BRR = 0x341; break;
    
     default: break;
     }

     switch (Add_UARTptr->USART_mode)
     {
     case USART_MODE_SELECT_ASYNCHRONOUS : CLR_BIT(MUART1->CR2,11); break;
     case USART_MODE_SELECT_SYNCHRONOUS  : SET_BIT(MUART1->CR2,11);
    
     switch (Add_UARTptr->Clock_option)
     {
         case USART_RECIVE_FALLING_SEND_RISING :  MUART1->CR2 &= ~(0b11 << 9); MUART1->CR2 |= (USART_RECIVE_FALLING_SEND_RISING <<9); break;
         case USART_RECIVE_RISING_SEND_FALLING :  MUART1->CR2 &= ~(0b11 << 9); MUART1->CR2 |= (USART_RECIVE_RISING_SEND_FALLING <<9); break;
         case USART_SEND_FALLNIG_RECIVE_RISING :  MUART1->CR2 &= ~(0b11 << 9); MUART1->CR2 |= (USART_SEND_FALLNIG_RECIVE_RISING <<9);break;
         case USART_SEND_RISING_RECIVE_FALLING :  MUART1->CR2 &= ~(0b11 << 9); MUART1->CR2 |= (USART_SEND_RISING_RECIVE_FALLING <<9); break;
         default : break;
     }
      break;
     default : break;
     }

     switch (Add_UARTptr->Parity_Enable)
     {
     case USART_PARITY_DISABLE : CLR_BIT(MUART1->CR1,10); break;
     case USART_PARITY_ENABLE  : SET_BIT(MUART1->CR1,10);

         if (Add_UARTptr->Parity_Mode == USART_PARITY_MODE_EVEN)
         {
             CLR_BIT(MUART1->CR1,9);
         }
         else if (Add_UARTptr->Parity_Mode == USART_PARITY_MODE_ODD)
         {
             SET_BIT(MUART1->CR1,9);
         }
         else
         {
             /* RETURN<ERROR> */
         }
        
      break;

     default : break;

     }

     switch (Add_UARTptr->data_size)
     {
         case USART_DATA_SIZE_8_BIT :  CLR_BIT(MUART1->CR1,12); break;
         case USART_DATA_SIZE_9_BIT :  SET_BIT(MUART1->CR1,12); break;
     }

     switch (Add_UARTptr->num_of_Stop_bits)
     {
         case USART_STOP_ONE_BIT : MUART1->CR2 &= ~(0b11 << 12); MUART1->CR2 |= (USART_STOP_ONE_BIT << 12);
         break;

         case USART_STOP_ONE_AND_HALF_BIT : MUART1->CR2 &= ~(0b11 << 12); MUART1->CR2 |= (USART_STOP_ONE_AND_HALF_BIT << 12);
         break;

         case USART_STOP_HALF_BIT : MUART1->CR2 &= ~(0b11 << 12); MUART1->CR2 |= (USART_STOP_HALF_BIT << 12);
         break;

         case USART_STOP_TWO_BIT : MUART1->CR2 &= ~(0b11 << 12); MUART1->CR2 |= (USART_STOP_TWO_BIT << 12);
         break;

         default : break;
     }

    /*Enable TX, RX and USART*/
     //MUART1->BRR = 0x341;
     SET_BIT(MUART1->CR1,3); //EN TX
     SET_BIT(MUART1->CR1,2); //EN RX
     SET_BIT(MUART1->CR1,13); //EN UART

     MUART1->SR = 0;
    
}

void MUART1_voidSend(u8 arr[])
{
    u8 i = 0;
	while(arr[i] != '\0'){
		MUART1 -> DR = arr[i];
		while((GET_BIT((MUART1 -> SR), 6)) == 0);
		i++;
	}
}

u8   MUART1_u8Recive()
{
    
	u8 Loc_u8ReceivedData = 0;
	while((GET_BIT((MUART1 -> SR), 5)) == 0);
	Loc_u8ReceivedData = MUART1 -> DR;
	return (Loc_u8ReceivedData);

}
