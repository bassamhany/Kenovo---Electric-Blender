/*
 * TACTILE_interface.h
 *
 *  Created on: Feb 16, 2016
 *      Author: bassam
 */

#ifndef TACTILE_INTERFACE_H_
#define TACTILE_INTERFACE_H_




#define PRESSED			1
#define RELEASED 		0

#define SINGLE			0
#define MULTI			1
extern void TACTILE_voidInit();

extern u8 TACTILE_u8GetButtonState(u8 Copy_u8ButtonIdx,u8 *Copy_u8ButtonVal);



#endif /* TACTILE_INTERFACE_H_ */
