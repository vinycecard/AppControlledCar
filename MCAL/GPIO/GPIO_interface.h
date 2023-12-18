#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_


/*                     PORT & PINS                         */
#define PORTA                                               1
#define PORTB                                               2
#define PORTC                                               3

#define PIN0                                                0
#define PIN1                                                1
#define PIN2                                                2
#define PIN3                                                3
#define PIN4                                                4
#define PIN5                                                5
#define PIN6                                                6
#define PIN7                                                7
#define PIN8                                                8
#define PIN9                                                9
#define PIN10                                               10
#define PIN11                                               11
#define PIN12                                               12
#define PIN13                                               13
#define PIN14                                               14
#define PIN15                                               15


/*                          PIN MODES                            */

#define GPIO_INPUT_ANALOG                                   0b0000
#define GPIO_INPUT_FLOATING                                 0b0100
#define GPIO_INPUT_PULL_UP_DOWN                             0b1000

#define GPIO_OUTPUT_10MHZ_PP                                0b0001
#define GPIO_OUTPUT_10MHZ_OD                                0b0101
#define GPIO_OUTPUT_10MHZ_AF_PP                             0b1001
#define GPIO_OUTPUT_10MHZ_AF_OD                             0b1101

#define GPIO_OUTPUT_2MHZ_PP                                 0b0010
#define GPIO_OUTPUT_2MHZ_OD                                 0b0110
#define GPIO_OUTPUT_2MHZ_AF_PP                              0b1010
#define GPIO_OUTPUT_2MHZ_AF_OD                              0b1110

#define GPIO_OUTPUT_50MHZ_PP                                0b0011
#define GPIO_OUTPUT_50MHZ_OD                                0b0111
#define GPIO_OUTPUT_50MHZ_AF_PP                             0b1011
#define GPIO_OUTPUT_50MHZ_AF_OD                             0b1111

/*                          PIN STATES                        */

#define GPIO_PIN_HIGH                                             1
#define GPIO_PIN_LOW                                              0

/*
 *                      FUNCTIONS PROTOTYPE                    */
void GPIO_Void_SetPinDirection(u8,u8,u8);
void GPIO_Void_SetPinValue(u8,u8,u8);
u8 GPIO_U8_GetPinValue(u8,u8);
void GPIO_Void_PinToggle(u8,u8);

#endif /* GPIO_GPIO_INTERFACE_H_ */
