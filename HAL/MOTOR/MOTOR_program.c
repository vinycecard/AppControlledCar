#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "TIMER_interface.h"

#include "MOTOR_interface.h"
#include "MOTOR_config.h"
#include "MOTOR_private.h"

void MOTOR_Void_MotorInit()
{
	/* To Set motor pins as output */
	GPIO_Void_SetPinDirection(MOTOR_IN1_PORT , MOTOR_IN1_PIN , GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(MOTOR_IN2_PORT , MOTOR_IN2_PIN , GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(MOTOR_IN3_PORT , MOTOR_IN3_PIN , GPIO_OUTPUT_10MHZ_PP);
	GPIO_Void_SetPinDirection(MOTOR_IN4_PORT , MOTOR_IN4_PIN , GPIO_OUTPUT_10MHZ_PP);

	/* To select ENA , ENB Pins as Alternative function to generate PWM */
	GPIO_Void_SetPinDirection(MOTOR_ENA_PORT , MOTOR_ENA_PIN , GPIO_OUTPUT_10MHZ_AF_PP);
	GPIO_Void_SetPinDirection(MOTOR_ENB_PORT , MOTOR_ENB_PIN , GPIO_OUTPUT_10MHZ_AF_PP);

	/* To Initiate PWM Channel 1 & 2 (TIMER2) */
	TIMER2_Void_PwmInit(TIMER2_CHANNEL1);
	TIMER2_Void_PwmInit(TIMER2_CHANNEL2);

	TIMER2_Void_PwmStart();


}
void MOTOR_Void_MotorSetSpeed(u8 Copy_U8_Speed)
{
	TIMER2_Void_PwmSetDutyCycle(TIMER2_CHANNEL1,Copy_U8_Speed);
	TIMER2_Void_PwmSetDutyCycle(TIMER2_CHANNEL2,Copy_U8_Speed);
}
void MOTOR_Void_MotorForward()
{
	GPIO_Void_SetPinValue(MOTOR_IN1_PORT , MOTOR_IN1_PIN , GPIO_PIN_HIGH);
	GPIO_Void_SetPinValue(MOTOR_IN2_PORT , MOTOR_IN2_PIN , GPIO_PIN_LOW);

	GPIO_Void_SetPinValue(MOTOR_IN3_PORT , MOTOR_IN3_PIN , GPIO_PIN_LOW);
	GPIO_Void_SetPinValue(MOTOR_IN4_PORT , MOTOR_IN4_PIN , GPIO_PIN_HIGH);

}
void MOTOR_Void_MotorBackward()
{
	GPIO_Void_SetPinValue(MOTOR_IN1_PORT , MOTOR_IN1_PIN , GPIO_PIN_LOW);
	GPIO_Void_SetPinValue(MOTOR_IN2_PORT , MOTOR_IN2_PIN , GPIO_PIN_HIGH);

	GPIO_Void_SetPinValue(MOTOR_IN3_PORT , MOTOR_IN3_PIN , GPIO_PIN_HIGH);
	GPIO_Void_SetPinValue(MOTOR_IN4_PORT , MOTOR_IN4_PIN , GPIO_PIN_LOW);


}
void MOTOR_Void_MotorRight()
{
	GPIO_Void_SetPinValue(MOTOR_IN1_PORT , MOTOR_IN1_PIN , GPIO_PIN_LOW);
	GPIO_Void_SetPinValue(MOTOR_IN2_PORT , MOTOR_IN2_PIN , GPIO_PIN_HIGH);

	GPIO_Void_SetPinValue(MOTOR_IN3_PORT , MOTOR_IN3_PIN , GPIO_PIN_LOW);
	GPIO_Void_SetPinValue(MOTOR_IN4_PORT , MOTOR_IN4_PIN , GPIO_PIN_HIGH);


}
void MOTOR_Void_MotorLeft()
{
	GPIO_Void_SetPinValue(MOTOR_IN1_PORT , MOTOR_IN1_PIN , GPIO_PIN_HIGH);
	GPIO_Void_SetPinValue(MOTOR_IN2_PORT , MOTOR_IN2_PIN , GPIO_PIN_LOW);

	GPIO_Void_SetPinValue(MOTOR_IN3_PORT , MOTOR_IN3_PIN , GPIO_PIN_HIGH);
	GPIO_Void_SetPinValue(MOTOR_IN4_PORT , MOTOR_IN4_PIN , GPIO_PIN_LOW);


}
void MOTOR_Void_MotorStop()
{
	GPIO_Void_SetPinValue(MOTOR_IN1_PORT , MOTOR_IN1_PIN , GPIO_PIN_LOW);
	GPIO_Void_SetPinValue(MOTOR_IN2_PORT , MOTOR_IN2_PIN , GPIO_PIN_LOW);

	GPIO_Void_SetPinValue(MOTOR_IN3_PORT , MOTOR_IN3_PIN , GPIO_PIN_LOW);
	GPIO_Void_SetPinValue(MOTOR_IN4_PORT , MOTOR_IN4_PIN , GPIO_PIN_LOW);


}





