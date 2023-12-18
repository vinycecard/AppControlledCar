#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void GPIO_Void_SetPinDirection(u8 Copy_U8_Port,u8 Copy_U8_Pin,u8 Copy_U8_Mode)
{
	if(Copy_U8_Pin<=7)
	{
		switch(Copy_U8_Port)
		{
		 case PORTA :  PORTA_CRL &=~ (0b1111 << (Copy_U8_Pin * 4));
		               PORTA_CRL |=  (Copy_U8_Mode << (Copy_U8_Pin * 4));      break;

		 case PORTB :  PORTB_CRL &=~ (0b1111 << (Copy_U8_Pin * 4));
		               PORTB_CRL |=  (Copy_U8_Mode << (Copy_U8_Pin * 4));      break;


		 case PORTC :  PORTC_CRL &=~ (0b1111 << (Copy_U8_Pin * 4));
		               PORTC_CRL |=  (Copy_U8_Mode << (Copy_U8_Pin * 4));      break;

		 default :                                                             break;

		}

	}
	else if(Copy_U8_Pin<=15)
	{
	       Copy_U8_Pin = Copy_U8_Pin - 8 ;
		switch(Copy_U8_Port)
		{
		 case PORTA :  PORTA_CRH &=~ (0b1111 << (Copy_U8_Pin * 4));
		               PORTA_CRH |= (Copy_U8_Mode << (Copy_U8_Pin * 4));      break;

		 case PORTB :  PORTB_CRH &=~ (0b1111 << (Copy_U8_Pin * 4));
		               PORTB_CRH |= (Copy_U8_Mode << (Copy_U8_Pin * 4));      break;


		 case PORTC :  PORTC_CRH &=~ (0b1111 << (Copy_U8_Pin * 4));
		               PORTC_CRH |= (Copy_U8_Mode << (Copy_U8_Pin * 4));      break;

		 default :                                                            break;

		}

	}
	else
	{
		printf("Error: Invalid Pin Number. Pin Number must be between 0 and 15.\n");

	}

}
void GPIO_Void_SetPinValue(u8 Copy_U8_Port,u8 Copy_U8_Pin,u8 Copy_U8_State)
{

	 if(Copy_U8_State == GPIO_PIN_HIGH)
	 {
#if  GPIO_SET_REG  == GPIO_ODR_REG
       switch(Copy_U8_Port)
       {
       case PORTA :  SET_BIT(PORTA_ODR,Copy_U8_Pin);                    break;
       case PORTB :  SET_BIT(PORTB_ODR,Copy_U8_Pin);                    break;
       case PORTC :  SET_BIT(PORTC_ODR,Copy_U8_Pin);                    break;
       default    :                                                     break;
       }
#elif GPIO_SET_REG == GPIO_BSRR_REG
       switch(Copy_U8_Port)
       {
       case PORTA :   PORTA_BSRR = (1<<Copy_U8_Pin);                    break;
       case PORTB :   PORTB_BSRR = (1<<Copy_U8_Pin);                    break;
       case PORTC :   PORTC_BSRR = (1<<Copy_U8_Pin);                    break;
       default    :                                                     break;
       }
#endif
	 }

	 else if (Copy_U8_State == GPIO_PIN_LOW)
	 {
#if  GPIO_CLR_REG  == GPIO_ODR_REG
	       switch(Copy_U8_Port)
	       {
	       case PORTA :  CLR_BIT(PORTA_ODR,Copy_U8_Pin);                break;
	       case PORTB :  CLR_BIT(PORTB_ODR,Copy_U8_Pin);                break;
	       case PORTC :  CLR_BIT(PORTC_ODR,Copy_U8_Pin);                break;
	       default    :                                                 break;
	       }
#elif GPIO_CLR_REG == GPIO_BRR_REG
	       switch(Copy_U8_Port)
	       {
	       case PORTA :  PORTA_BRR = (1<<Copy_U8_Pin);                  break;
	       case PORTB :  PORTB_BRR = (1<<Copy_U8_Pin);                  break;
	       case PORTC :  PORTC_BRR = (1<<Copy_U8_Pin);                  break;
	       default    :                                                 break;
	       }
#endif
	 }
	 else
	 {
		printf("Error: Invalid State. State must be GPIO_PIN_HIGH or GPIO_PIN_LOW.\n");
	 }

}
u8 GPIO_U8_GetPinValue(u8 Copy_U8_Port,u8 Copy_U8_Pin)
{
	u8 Local_U8_PinValue = 0;

	switch(Copy_U8_Port)
	{
	case PORTA  :   Local_U8_PinValue = GET_BIT(PORTA_IDR,Copy_U8_Pin);   				   break;
	case PORTB  :   Local_U8_PinValue = GET_BIT(PORTB_IDR,Copy_U8_Pin);    				   break;
	case PORTC  :   Local_U8_PinValue = GET_BIT(PORTC_IDR,Copy_U8_Pin);    				   break;
	default     :   printf("Error: Invalid Port. Port must be PORTA, PORTB, or PORTC.\n"); break;
	}

	return Local_U8_PinValue ;

}

void GPIO_Void_PinToggle(u8 Copy_U8_Port,u8 Copy_U8_Pin)
{


	switch(Copy_U8_Port)
	{
	case PORTA  :   TOG_BIT(PORTA_ODR,Copy_U8_Pin);                         			   break;
	case PORTB  :   TOG_BIT(PORTB_ODR,Copy_U8_Pin);                         			   break;
	case PORTC  :   TOG_BIT(PORTC_ODR,Copy_U8_Pin);                       				   break;
	default     :   printf("Error: Invalid Port. Port must be PORTA, PORTB, or PORTC.\n"); break;
	}



}


