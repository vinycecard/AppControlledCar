#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "IR_interface.h"
#include "IR_config.h"
#include "IR_private.h"


void IR_Void_IRInit()
{
	/* To select IR1 output pin as input floating  */
	GPIO_Void_SetPinDirection(IR1_OUTPUT_PORT , IR1_OUTPUT_PIN ,GPIO_INPUT_FLOATING);

	/* To select IR2 output pin as input floating  */
	GPIO_Void_SetPinDirection(IR2_OUTPUT_PORT , IR2_OUTPUT_PIN ,GPIO_INPUT_FLOATING);


}
u8 IR_U8_IRRightState()
{
	u8 Local_U8_State ;

	Local_U8_State = GPIO_U8_GetPinValue(IR1_OUTPUT_PORT , IR1_OUTPUT_PIN);

	return Local_U8_State ;


}

u8 IR_U8_IRLeftState()
{
	u8 Local_U8_State = 1;

	Local_U8_State = GPIO_U8_GetPinValue(IR2_OUTPUT_PORT , IR2_OUTPUT_PIN);

	return Local_U8_State ;


}
