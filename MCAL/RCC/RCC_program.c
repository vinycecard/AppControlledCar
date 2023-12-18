#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


//////////////// Need to be checked ////////////////////////
void RCC_Void_InitClockSystem(void)
{
#if RCC_CLOCK_SYSTEM == RCC_HSI_MODE

	  RCC_CR   = 0x00000081;                  // To Enable HSI Mode

	  RCC_CFGR = 0x00000000;                // To select HSI as clock source



#elif RCC_CLOCK_SYSTEM == RCC_HSE_RC_MODE

	  RCC_CR = 0x00050000;                  // To Enable HSE RC Mode

	  RCC_CFGR = 0x00000001;                // To select HSE as clock source


#elif RCC_CLOCK_SYSTEM == RCC_HSE_CRYSTAL_MODE

	  RCC_CR = 0x00010000;                  // To Enable HSE Crystal Mode

	  RCC_CFGR = 0x00000001;                // To select HSE as clock source



#elif RCC_CLOCK_SYSTEM == RCC_PLL_MODE

  #if   RCC_PLL_SRC  == RCC_PLL_SRC_HSI_DIV_2

	   RCC_CFGR = 0x00000002;                // To select PLL (HSI/2 as input) as clock source

  #elif RCC_PLL_SRC == RCC_PLL_SRC_HSE

	   RCC_CFGR = 0x00010002;                // To select PLL (HSE as input) as clock source

  #endif

  #if   RCC_PLL_MUL  == 2
	  CLR_BIT(RCC_CFGR,18);                // To select PLL output Multiplied by 2
	  CLR_BIT(RCC_CFGR,19);
	  CLR_BIT(RCC_CFGR,20);
	  CLR_BIT(RCC_CFGR,21);

  #elif RCC_PLL_MUL  == 3                 // To select PLL output Multiplied by 3
	  SET_BIT(RCC_CFGR,18);
	  CLR_BIT(RCC_CFGR,19);
	  CLR_BIT(RCC_CFGR,20);
	  CLR_BIT(RCC_CFGR,21);

  #elif RCC_PLL_MUL  == 4                 // To select PLL output Multiplied by 4
	  CLR_BIT(RCC_CFGR,18);
	  SET_BIT(RCC_CFGR,19);
	  CLR_BIT(RCC_CFGR,20);
	  CLR_BIT(RCC_CFGR,21);

  #elif RCC_PLL_MUL  == 5                // To select PLL output Multiplied by 5
	  SET_BIT(RCC_CFGR,18);
	  SET_BIT(RCC_CFGR,19);
	  CLR_BIT(RCC_CFGR,20);
	  CLR_BIT(RCC_CFGR,21);

  #elif RCC_PLL_MUL  == 6               // To select PLL output Multiplied by 6
	  CLR_BIT(RCC_CFGR,18);
	  CLR_BIT(RCC_CFGR,19);
	  SET_BIT(RCC_CFGR,20);
	  CLR_BIT(RCC_CFGR,21);

  #elif RCC_PLL_MUL  == 7              // To select PLL output Multiplied by 7
	  SET_BIT(RCC_CFGR,18);
	  CLR_BIT(RCC_CFGR,19);
	  SET_BIT(RCC_CFGR,20);
	  CLR_BIT(RCC_CFGR,21);

  #elif RCC_PLL_MUL  == 8            // To select PLL output Multiplied by 8
	  CLR_BIT(RCC_CFGR,18);
	  SET_BIT(RCC_CFGR,19);
	  SET_BIT(RCC_CFGR,20);
	  CLR_BIT(RCC_CFGR,21);

#elif RCC_PLL_MUL  == 9            // To select PLL output Multiplied by 9
	  SET_BIT(RCC_CFGR,18);
	  SET_BIT(RCC_CFGR,19);
	  SET_BIT(RCC_CFGR,20);
	  CLR_BIT(RCC_CFGR,21);

#elif RCC_PLL_MUL  == 10            // To select PLL output Multiplied by 10
	  CLR_BIT(RCC_CFGR,18);
	  CLR_BIT(RCC_CFGR,19);
	  CLR_BIT(RCC_CFGR,20);
	  SET_BIT(RCC_CFGR,21);

#elif RCC_PLL_MUL  == 11            // To select PLL output Multiplied by 11
	  SET_BIT(RCC_CFGR,18);
	  CLR_BIT(RCC_CFGR,19);
	  CLR_BIT(RCC_CFGR,20);
	  SET_BIT(RCC_CFGR,21);

#elif RCC_PLL_MUL  == 12            // To select PLL output Multiplied by 12
	  CLR_BIT(RCC_CFGR,18);
	  SET_BIT(RCC_CFGR,19);
	  CLR_BIT(RCC_CFGR,20);
	  SET_BIT(RCC_CFGR,21);

#elif RCC_PLL_MUL  == 13           // To select PLL output Multiplied by 13
	  SET_BIT(RCC_CFGR,18);
	  SET_BIT(RCC_CFGR,19);
	  CLR_BIT(RCC_CFGR,20);
	  SET_BIT(RCC_CFGR,21);

#elif RCC_PLL_MUL  == 14            // To select PLL output Multiplied by 14
	  CLR_BIT(RCC_CFGR,18);
	  CLR_BIT(RCC_CFGR,19);
	  SET_BIT(RCC_CFGR,20);
	  SET_BIT(RCC_CFGR,21);

#elif RCC_PLL_MUL  == 15            // To select PLL output Multiplied by 15
	  SET_BIT(RCC_CFGR,18);
	  CLR_BIT(RCC_CFGR,19);
	  SET_BIT(RCC_CFGR,20);
	  SET_BIT(RCC_CFGR,21);

#elif RCC_PLL_MUL  == 16            // To select PLL output Multiplied by 16
	  SET_BIT(RCC_CFGR,18);
	  _BIT(RCC_CFGR,19);
	  SET_BIT(RCC_CFGR,20);
	  SET_BIT(RCC_CFGR,21);


  #endif

	  RCC_CR = 0x01000000;                   // To Enable PLL Mode


#endif


}



void RCC_Void_EnableClock(u8 Copy_U8_BusId , u8 Copy_U8_PerId)
{
	if(Copy_U8_PerId<=31)
	{
		switch(Copy_U8_BusId)
		{
		case RCC_AHB   :   SET_BIT(RCC_AHBENR,Copy_U8_PerId) ;                    break;
		case RCC_APB2  :   SET_BIT(RCC_APB2ENR,Copy_U8_PerId);                    break;
		case RCC_APB1  :   SET_BIT(RCC_APB1ENR,Copy_U8_PerId);                    break;
		default        :    printf("Error, Copy_U8_BusId is not valid");          break;
		}

	}
	else
	{
		return("Error, variable is not on right range");
	}
}
void RCC_Void_DisableClock(u8 Copy_U8_BusId , u8 Copy_U8_PerId)
{
	if(Copy_U8_PerId<=31)
		{
			switch(Copy_U8_BusId)
			{
			case RCC_AHB   :   CLR_BIT(RCC_AHBENR,Copy_U8_PerId) ;                    break;
			case RCC_APB2  :   CLR_BIT(RCC_APB2ENR,Copy_U8_PerId);                    break;
			case RCC_APB1  :   CLR_BIT(RCC_APB1ENR,Copy_U8_PerId);                    break;
			default        :   printf("Error, Copy_U8_BusId is not valid");           break;
			}

		}
		else
		{
			return("Error, variable is not on right range");
		}
}



