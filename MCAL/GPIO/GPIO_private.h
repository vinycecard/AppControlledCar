#ifndef GPIO_GPIO_PRIVATE_H_
#define GPIO_GPIO_PRIVATE_H_

/*                    PORTS BASE ADDRESS                    */

#define PORTA_BASE_ADDRESS                   0x40010800
#define PORTB_BASE_ADDRESS                   0x40010C00
#define PORTC_BASE_ADDRESS                   0x40011000


/*                       PORTA REGISTERS                    */

#define PORTA_CRL                           *((volatile u32*)(PORTA_BASE_ADDRESS + 0x00))
#define PORTA_CRH                           *((volatile u32*)(PORTA_BASE_ADDRESS + 0x04))
#define PORTA_IDR                           *((volatile u32*)(PORTA_BASE_ADDRESS + 0x08))
#define PORTA_ODR                           *((volatile u32*)(PORTA_BASE_ADDRESS + 0x0C))
#define PORTA_BSRR                          *((volatile u32*)(PORTA_BASE_ADDRESS + 0x10))
#define PORTA_BRR                           *((volatile u32*)(PORTA_BASE_ADDRESS + 0x14))
#define PORTA_LCKR                          *((volatile u32*)(PORTA_BASE_ADDRESS + 0x18))

/*                       PORTB REGISTERS                    */

#define PORTB_CRL                           *((volatile u32*)(PORTB_BASE_ADDRESS + 0x00))
#define PORTB_CRH                           *((volatile u32*)(PORTB_BASE_ADDRESS + 0x04))
#define PORTB_IDR                           *((volatile u32*)(PORTB_BASE_ADDRESS + 0x08))
#define PORTB_ODR                           *((volatile u32*)(PORTB_BASE_ADDRESS + 0x0C))
#define PORTB_BSRR                          *((volatile u32*)(PORTB_BASE_ADDRESS + 0x10))
#define PORTB_BRR                           *((volatile u32*)(PORTB_BASE_ADDRESS + 0x14))
#define PORTB_LCKR                          *((volatile u32*)(PORTB_BASE_ADDRESS + 0x18))


/*                       PORTC REGISTERS                    */

#define PORTC_CRL                           *((volatile u32*)(PORTC_BASE_ADDRESS + 0x00))
#define PORTC_CRH                           *((volatile u32*)(PORTC_BASE_ADDRESS + 0x04))
#define PORTC_IDR                           *((volatile u32*)(PORTC_BASE_ADDRESS + 0x08))
#define PORTC_ODR                           *((volatile u32*)(PORTC_BASE_ADDRESS + 0x0C))
#define PORTC_BSRR                          *((volatile u32*)(PORTC_BASE_ADDRESS + 0x10))
#define PORTC_BRR                           *((volatile u32*)(PORTC_BASE_ADDRESS + 0x14))
#define PORTC_LCKR                          *((volatile u32*)(PORTC_BASE_ADDRESS + 0x18))


/*              SET / CLR  REGISTERS CONFIGURATION             */
#define GPIO_ODR_REG                             1
#define GPIO_BSRR_REG                            2
#define GPIO_BRR_REG                             3




#endif /* GPIO_GPIO_PRIVATE_H_ */
