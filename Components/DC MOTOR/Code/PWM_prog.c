/*
 * PWM_prog.c
 *
 *  Created on: Mar 31, 2016
 *      Author: LENOVO
 */

#include "types.h"
#include "PWM_private.h"
#include "PWM_interface.h"
// initialize PWM
void PWM_init()
{
    // initialize timer0 in PWM mode
    TCCR0 |= (1<<WGM00)|(1<<COM01)|(1<<WGM01)|(1<<CS00);
    // make sure to make OC0 pin (pin PB3 for atmega32) as output pin
}

////////////
//set duty cycle
void PWM_Set_Duty_Cycle(u8 copy_u8Duty)
{
	u8 local_u8Duty= copy_u8Duty;

	OCR0=local_u8Duty;
}
