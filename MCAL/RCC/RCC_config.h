#ifndef RCC_RCC_CONFIG_H_
#define RCC_RCC_CONFIG_H_

/*  Clock System configurations */

#define RCC_CLOCK_SYSTEM              RCC_HSE_CRYSTAL_MODE



#if RCC_CLOCK_SYSTEM == RCC_PLL_MODE

#define RCC_PLL_SRC                 RCC_PLL_SRC_HSE


#define RCC_PLL_MUL                        14


#endif


#endif /* RCC_RCC_CONFIG_H_ */
