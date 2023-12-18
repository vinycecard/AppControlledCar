#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER_interface.h"
#include "TIMER_config.h"
#include "TIMER_private.h"



void TIMER2_Void_PwmInit(u8 Copy_U8_Channel)
{
   /* To disable timer , Enable auto Preload ARR */
   TIMER_CR1 = 0x0080;
   TIMER_ARR = 100;
	 switch(Copy_U8_Channel)
	 {

	   case TIMER2_CHANNEL1  :
		   /* To Enable Preload register on CCR1 */
		   SET_BIT(TIMER_CCMR1,3);
		   /* To Select PWM MODE 1 */
		   CLR_BIT(TIMER_CCMR1,4);
		   SET_BIT(TIMER_CCMR1,5);
		   SET_BIT(TIMER_CCMR1,6);
		   /* To Enable Capture compare to channel 1 */
		   SET_BIT(TIMER_CCER,0);                                 break;
	   case TIMER2_CHANNEL2  :
		   /* To Enable Preload register on CCR2 */
		   SET_BIT(TIMER_CCMR1,11);
		   /* To Select PWM MODE 1 */
		   CLR_BIT(TIMER_CCMR1,12);
		   SET_BIT(TIMER_CCMR1,13);
		   SET_BIT(TIMER_CCMR1,14);
		   /* To Enable Capture compare to channel 2 */
		   SET_BIT(TIMER_CCER,4);                                 break;
	   case TIMER2_CHANNEL3 :
		   /* To Enable Preload register on CCR3 */
		   SET_BIT(TIMER_CCMR2,3);
		   /* To Select PWM MODE 1 */
		   CLR_BIT(TIMER_CCMR2,4);
		   SET_BIT(TIMER_CCMR2,5);
		   SET_BIT(TIMER_CCMR2,6);
		   /* To Enable Capture compare to channel 3 */
		   SET_BIT(TIMER_CCER,8);                                 break;
	   default              :                                     break;


	 }

}
void TIMER2_Void_PwmSetDutyCycle(u8 Copy_U8_Channel,u32 Copy_U32_DutyCycle)
{
	switch(Copy_U8_Channel)
	{
	case TIMER2_CHANNEL1 :  TIMER_CCR1 = Copy_U32_DutyCycle;           break;
	case TIMER2_CHANNEL2 :  TIMER_CCR2 = Copy_U32_DutyCycle;           break;
	case TIMER2_CHANNEL3 :  TIMER_CCR3 = Copy_U32_DutyCycle;           break;
	default              :                                             break;

	}
}
void TIMER2_Void_PwmStart()
{
	SET_BIT(TIMER_CR1,0);
}

/**************************************** Timer 4 **********************************/
void TIMER4_Void_InitTimer()
{
	/* Disable timer , Select up counter mode , Enable auto reload */
	TIMER4_CR1 = 0x80;

	/* Enable update interrupt  */
	SET_BIT(TIMER4_DIER,0);


	/* Select prescaler to clock frequency --> timer of tick = 1 msec */
	TIMER4_PSC = 8000 ;

}
void TIMER4_Void_SetIntervalSingle(u32 Copy_U32_Ticks ,void(*Fptr)(void))
{
	/* Save call back function */
	Timer4_CallBack = Fptr ;

	/* Select timer mode as single interval */
	U8_Timer4Mode = 1 ;

	/* Set timer ticks */
	TIMER4_ARR = Copy_U32_Ticks ;

	/* Enable Timer  */
	SET_BIT(TIMER4_CR1 ,0);



}
void TIMER4_Void_SetIntervalPeriodic(u32 Copy_U32_Ticks ,void(*Fptr)(void))
{
	/* Save call back function */
	Timer4_CallBack = Fptr ;

	/* Select timer mode as single interval */
	U8_Timer4Mode = 2 ;

	/* Set timer ticks */
	TIMER4_ARR = Copy_U32_Ticks ;

	/* Enable Timer  */
	SET_BIT(TIMER4_CR1 ,0);



}

void TIMER4_Void_StopTimer()
{
	CLR_BIT(TIMER4_CR1 ,0);
}

void TIM4_IRQHandler(void)
{
	if(U8_Timer4Mode == 1)
	{
		/* Disable interrupt update  */
		CLR_BIT(TIMER4_DIER,0);
	}

	Timer4_CallBack();

	/* Clear interrupt update flag */
	CLR_BIT(TIMER4_SR,0);

}



