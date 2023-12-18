#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

#define UART_BASE_ADDRESS 0x40013800

typedef struct 
{
    volatile u32   SR;
    volatile u32   DR;
    volatile u32   BRR;
    volatile u32   CR1;
    volatile u32   CR2;
    volatile u32   CR3;
    volatile u32   GTPR;
}UART_t;

#define MUART1   ((volatile UART_t *) UART_BASE_ADDRESS)


#endif /* MCAL_TIMER_TIMER_PRIVATE_H_ */
