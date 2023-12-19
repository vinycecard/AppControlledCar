/************************************** INCLUDES ******************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "IR_interface.h"
#include "MOTOR_interface.h"
#include "TIMER_interface.h"
#include "UART_interface.h"

/******************************** FUNCTIONS DECLARTATION ********************************/
void System_Init();


int main()
{
	  /* UART configurations as struct data type */
	  USART_str UART1 = {

		.USART_mode = USART_MODE_SELECT_ASYNCHRONOUS,              /* Select UART asynchronous mode*/

		.baud_rate = USART_BAUD_RATE_9600,                         /* Select 9600 baudrate */

		.Clock_option = 0xFF,                                      /* Turn off clock options --> Asynchronous */

		.Parity_Enable = USART_PARITY_DISABLE,                     /* Disable parity bit */

		.Parity_Mode = 0xFF,                                       /* Turn off --> no parity option  */

		.data_size = USART_DATA_SIZE_8_BIT,                        /* Select 8 bits data size */

		.num_of_Stop_bits = USART_STOP_ONE_BIT                     /* Select one stop bit */

	};

	 System_Init();                                                   /* RCC Initialization */

	 MUART1_voidInit(&UART1);                                      /* UART Initialization */

	 MOTOR_Void_MotorInit();                                       /* Motor Initialization */

	 IR_Void_IRInit();                                             /* IR Sensors Initialization */

	 MOTOR_Void_MotorSetSpeed(80);                                 /* Set motor speed with 80% duty cycle */


	/* Configure TX pin as output push pull alternative function */
    GPIO_Void_SetPinDirection(PORTA , PIN9 , GPIO_OUTPUT_50MHZ_AF_PP);

    /* Configure RX pin as input floating */
    GPIO_Void_SetPinDirection(PORTA , PIN10 , GPIO_INPUT_FLOATING);

    /* Define local variable to receive data sent by UART for car controlled mode */
    u8 Local_U8_Data ;

    /* Define local variable to receive car mode sent by UART  */
    u8 Local_u8Mode;

    /* Receive car mode from user */
    Local_u8Mode = MUART1_u8Recive();

   while (1)
   {
	 /* First car mode --> Controlling car using mobile application */
	 while(Local_u8Mode == 'N')
     {
		/* Receive data sent by user --> Direction of moving  */
		Local_U8_Data = MUART1_u8Recive();


       if(Local_U8_Data == 'F')
       {
    	   MOTOR_Void_MotorForward();
       }

       else if(Local_U8_Data == 'R')
       {
    	   MOTOR_Void_MotorRight();
       }

       else if(Local_U8_Data == 'L')
	   {
    	   MOTOR_Void_MotorLeft();
	   }

       else if(Local_U8_Data == 'B')
       {
    	   MOTOR_Void_MotorBackward();
       }

       else if(Local_U8_Data == 'S')
       {
           MOTOR_Void_MotorStop();
       }

       /* Switching to second mode */
       else if (Local_U8_Data == 'M')
       {
    	   Local_u8Mode = 'M';
    	   break;
       }

     }

	 /* Second car mode --> Autonomous car line tracking */
	 while (Local_u8Mode == 'M')
	 {
		 if(IR_U8_IRLeftState() == IR_WHITE && IR_U8_IRRightState() == IR_WHITE)
		 {
			 MOTOR_Void_MotorForward();
			 MOTOR_Void_MotorSetSpeed(70);
		 }

		 if(IR_U8_IRLeftState() == IR_BLACK && IR_U8_IRRightState() == IR_WHITE)
		 {
			 MOTOR_Void_MotorLeft();
			 MOTOR_Void_MotorSetSpeed(85);
		 }

		 if(IR_U8_IRLeftState() == IR_WHITE && IR_U8_IRRightState() == IR_BLACK)
		 {
			 MOTOR_Void_MotorRight();
			MOTOR_Void_MotorSetSpeed(85);
		 }

		 if(IR_U8_IRLeftState() == IR_BLACK && IR_U8_IRRightState() == IR_BLACK)
		 {
			 MOTOR_Void_MotorStop();
		 }

 	}
  }

}


void System_Init()
{
    RCC_Void_InitClockSystem();              /* Initiate clock system as HSE Crystal */

    RCC_Void_EnableClock(RCC_APB2 , 2);      /* Enable PORTA clock                   */

    RCC_Void_EnableClock(RCC_APB2 , 3);      /* Enable PORTB clock                   */

    RCC_Void_EnableClock(RCC_APB2 , 0);      /* Enable AFIO clock                    */

    RCC_Void_EnableClock(RCC_APB1 , 0);      /* Enable Timer 2 clock                 */

    RCC_Void_EnableClock(RCC_APB2 , 14);     /* Enable UART clock                    */

}

