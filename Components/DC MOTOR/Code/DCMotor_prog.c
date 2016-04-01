/*
 * DCMotor_prog.c
 *
 *  Created on: Mar 30, 2016
 *      Author: LENOVO
 */

#include"types.h"
#include"DCMotor_config.h"
#include"DCMotor_private.h"
#include"DCMotor_interface.h"
#include"PWM_interface.h"

static u8 DCMotor_u8Speedflag;

const static  u8 DCMotor_ArrayOfSpeeds[3] = { DCMotor_SPEED1, DCMotor_SPEED2, DCMotor_SPEED3 };

extern void DCMotor_voidInit(void)
{
	DCMotor_u8Speedflag = DCMotor_INITSPEED;
#if DCMotor_INITSTATE == DCMotor_OFF
	PWM_Set_Duty_Cycle(DCMotor_OFF);

#elif DCMotor_INITSTATE == DCMotor_ON
	PWM_Set_Duty_Cycle(DCMotor_ArrayOfSpeeds[DCMotor_u8Speedflag]);

#endif
}

extern void DCMotor_voidOn(void)
{
	PWM_Set_Duty_Cycle(DCMotor_ArrayOfSpeeds[DCMotor_u8Speedflag]);
}

extern void DCMotor_voidOff(void)
{
	PWM_Set_Duty_Cycle(DCMotor_OFF);
}

extern void DCMotor_voidChangeSpeed(u8 copy_u8Speed)
{
	DCMotor_u8Speedflag = copy_u8Speed;
	PWM_Set_Duty_Cycle(DCMotor_ArrayOfSpeeds[DCMotor_u8Speedflag]);
}
