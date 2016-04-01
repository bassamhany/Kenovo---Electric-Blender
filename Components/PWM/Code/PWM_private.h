/*
 * PWM_private.h
 *
 *  Created on: ???/???/????
 *      Author: Ismailia Laptop
 */

#ifndef PWM_PRIVATE_H_
#define PWM_PRIVATE_H_

#define TCCR0      *((volatile u8*)(0x53))
#define DDRB       *((volatile u8*)(0x37))
#define OCR0       *((volatile u8*)(0x5C))


#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7

#define PB0     0
#define PB1     1
#define PB2     2
#define PB3     3
#define PB4     4
#define PB5     5
#define PB6     6
#define PB7     7

#endif /* PWM_PRIVATE_H_ */
