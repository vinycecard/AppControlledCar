#ifndef RCC_RCC_PRIVATE_H_
#define RCC_RCC_PRIVATE_H_

/*    Registers Description  */


#define RCC_CR            *((volatile u32*)0x40021000)
#define RCC_CFGR          *((volatile u32*)0x40021004)
#define RCC_CIR           *((volatile u32*)0x40021008)
#define RCC_APB2RSTR      *((volatile u32*)0x4002100C)
#define RCC_APB1RSTR      *((volatile u32*)0x40021010)
#define RCC_AHBENR        *((volatile u32*)0x40021014)
#define RCC_APB2ENR       *((volatile u32*)0x40021018)
#define RCC_APB1ENR       *((volatile u32*)0x4002101C)
#define RCC_BDCR          *((volatile u32*)0x40021020)
#define RCC_CSR           *((volatile u32*)0x40021024)


/*   Clock System Modes    */

#define RCC_HSI_MODE                           1
#define RCC_HSE_RC_MODE                        2
#define RCC_HSE_CRYSTAL_MODE                   3
#define RCC_PLL_MODE                           4

/*  PLL Source              */
#define RCC_PLL_SRC_HSI_DIV_2                  1
#define RCC_PLL_SRC_HSE                        2






#endif /* RCC_RCC_PRIVATE_H_ */
