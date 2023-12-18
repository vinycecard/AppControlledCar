#ifndef MCAL_TIMER_TIMER_INTERFACE_H_
#define MCAL_TIMER_TIMER_INTERFACE_H_

/*                                        TIMER 2                                       */
void TIMER2_Void_PwmInit(u8);
void TIMER2_Void_PwmSetDutyCycle(u8,u32);
void TIMER2_Void_PwmStart();

#define TIMER2_CHANNEL1                            1
#define TIMER2_CHANNEL2                            2
#define TIMER2_CHANNEL3                            3


/*                                         TIMER 4                                     */

void TIMER4_Void_InitTimer();
void TIMER4_Void_SetIntervalSingle(u32 ,void(*)(void));
void TIMER4_Void_SetIntervalPeriodic(u32 ,void(*)(void));
void TIMER4_Void_StopTimer();
//void TIMER4_Void_SetBusyWait(u32);


#endif /* MCAL_TIMER_TIMER_INTERFACE_H_ */
