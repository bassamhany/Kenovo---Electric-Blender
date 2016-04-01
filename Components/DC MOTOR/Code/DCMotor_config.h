/*
 * DCMotor_config.h
 *
 *  Created on: Mar 30, 2016
 *      Author: LENOVO
 */

#ifndef DCMOTOR_CONFIG_H_
#define DCMOTOR_CONFIG_H_

/***************************************/
/************MOTOR PINS*****************/
/***************************************/

/*comment!: PIN intial direction*/
/*Range! : DIO_u8PIN0 ~ DIO_u8PIN31*/
#define DCMotor_u8PIN DIO_u8PIN11

/*comment!: DCmotor intial state*/
/*Range! : DCMotor_ON ~ DCMotor_OFF*/
#define DCMotor_INITSTATE DCMotor_ON

/*comment!: DCmotor intial speed*/
/*Range! : DCMotor_SPEED_1 ~ DCMotor_SPEED_3*/
#define DCMotor_INITSPEED DCMotor_SPEED_1






#endif /* DCMOTOR_CONFIG_H_ */
