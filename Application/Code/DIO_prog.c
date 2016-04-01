/*
 * DIO_prog.c
 *
 *  Created on: Jan 27, 2016
 *      Author: mustafa
 */
#include "Types.h"
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"
#include "util.h"

 
 /*comment!:Ports Register */
volatile u8* const  DIO_u8PORTArr[]={DIO_u8PORTA, DIO_u8PORTB, DIO_u8PORTC, DIO_u8PORTD };
/*comment!:Pins Register */
volatile u8*  const  DIO_u8PINArr[]={ DIO_u8PINA, DIO_u8PINB, DIO_u8PINC, DIO_u8PIND };
/*comment!:Directions Register */
volatile u8*  const  DIO_u8DDRArr[]={ DIO_u8DDRA, DIO_u8DDRB, DIO_u8DDRC, DIO_u8DDRD };
/**************************************************************************/
/*****************************Functions ***********************************/
/**************************************************************************/

/*comment!:read port value*/
extern u8 DIO_u8ReadPortVal(u8 Copy_u8PortIdx, u8* Copy_u8PtrVal)
{
	u8 Local_u8State;
	if(Copy_u8PortIdx>NUMBER_OF_PINS)
	{
		Local_u8State = u8ERROR;
	}
		else
		{
			Local_u8State = u8OK;
			*Copy_u8PtrVal=*DIO_u8PINArr[Copy_u8PortIdx];
		}
	return Local_u8State;
}

/* Comment!: Write Port Value */
extern u8 DIO_u8WritePortVal(u8 Copy_u8PortIdx,u8 Copy_u8PortVal)
{
	u8 Local_u8State;
		if(Copy_u8PortIdx>NUMBER_OF_PINS)
		{
			Local_u8State = u8ERROR;
		}
			else
			{
				Local_u8State = u8OK;
				*DIO_u8PORTArr[Copy_u8PortIdx]=Copy_u8PortVal;
			}


	return Local_u8State;
}


/* Comment!: Write Port Direction */
extern u8 DIO_u8WritePortDir(u8 Copy_u8PortIdx,u8 Copy_u8PortDir)
{
	u8 Local_u8State;
			if(Copy_u8PortIdx>NUMBER_OF_PINS)
			{
				Local_u8State = u8ERROR;
			}
				else
				{
					Local_u8State = u8OK;
					*DIO_u8DDRArr[Copy_u8PortIdx]=Copy_u8PortDir;
				}


		return Local_u8State;
}
/* Comment!: Read Port Direction */
extern u8 DIO_u8ReadPortDir(u8 Copy_u8PortIdx,u8* Copy_u8PtrToDir)
{
	u8 Local_u8State;
			if(Copy_u8PortIdx>NUMBER_OF_PINS)
			{
				Local_u8State = u8ERROR;
			}
				else
				{
					Local_u8State = u8OK;
					*Copy_u8PtrToDir=*DIO_u8DDRArr[Copy_u8PortIdx];
				}


		return Local_u8State;
}
/* Comment!: Read Pin Value */
extern u8 DIO_u8ReadPinVal(u8 Copy_u8PinIdx,u8* Copy_u8PtrToVal)
{
	u8 Local_u8State;
	u8 Local_u8PortNum = Copy_u8PinIdx / NUMBER_OF_PINS_PORT;
	u8 Local_u8PinNum = Copy_u8PinIdx % NUMBER_OF_PINS_PORT;
	if(Copy_u8PinIdx >NUMBER_OF_PINS)
		{
		Local_u8State= u8ERROR;
		}
		else
		{
			Local_u8State = u8OK;
			*Copy_u8PtrToVal = GET_BIT(*DIO_u8PINArr[Local_u8PortNum], Local_u8PinNum);
		}
	return Local_u8State;
}

/* Comment!: Write Pin Value */

extern u8 DIO_u8WritePinVal(u8 Copy_u8PinIdx,u8 Copy_u8PinVal)
{
	u8 Local_u8State;
	u8 Local_u8PortNum = Copy_u8PinIdx / NUMBER_OF_PINS_PORT;
	u8 Local_u8PinNum = Copy_u8PinIdx % NUMBER_OF_PINS_PORT;
	if(Copy_u8PinIdx >NUMBER_OF_PINS)
			{
			    Local_u8State= u8ERROR;
			}
			else
			{
				if(Copy_u8PinVal)
				{
			    *DIO_u8PORTArr[Local_u8PortNum]=SET_BIT(*DIO_u8PORTArr[Local_u8PortNum],Local_u8PinNum);
				}
				else
				{
				    *DIO_u8PORTArr[Local_u8PortNum]=CLR_BIT(*DIO_u8PORTArr[Local_u8PortNum],Local_u8PinNum);

				}
				Local_u8State = u8OK;

				}
		return Local_u8State;

}
/* Comment!: Write Pin Direction */
extern u8 DIO_u8WritePinDir(u8 Copy_u8PinIdx,u8 Copy_u8PinDir)
{
	u8 Local_u8State;
	u8 Local_u8PortNum = Copy_u8PinIdx / NUMBER_OF_PINS_PORT;
	u8 Local_u8PinNum = Copy_u8PinIdx % NUMBER_OF_PINS_PORT;
	if(Copy_u8PinIdx >NUMBER_OF_PINS)
			{
			Local_u8State= u8ERROR;
			}
			else
			{
				if(Copy_u8PinDir)
				{
				*DIO_u8DDRArr[Local_u8PortNum]= SET_BIT(*DIO_u8DDRArr[Local_u8PortNum],Local_u8PinNum);
				}
				else
				{
					*DIO_u8DDRArr[Local_u8PortNum]= CLR_BIT(*DIO_u8DDRArr[Local_u8PortNum],Local_u8PinNum);

				}
				Local_u8State = u8OK;

				}
		return Local_u8State;
}

/* Comment!: Read Pin Direction  */
extern u8 DIO_u8ReadPinDir(u8 Copy_u8PinIdx,u8* Copy_u8PtrToDir)
{
	u8 Local_u8State;
	u8 Local_u8PortNum = Copy_u8PinIdx / NUMBER_OF_PINS_PORT;
	u8 Local_u8PinNum = Copy_u8PinIdx % NUMBER_OF_PINS_PORT;
	if(Copy_u8PinIdx >NUMBER_OF_PINS)
	{
			Local_u8State= u8ERROR;
	}
			else
			{
				Local_u8State = u8OK;
				*Copy_u8PtrToDir = GET_BIT(*DIO_u8DDRArr[Local_u8PortNum], Local_u8PinNum);
			}

		return Local_u8State;
}


/* Comment!: Initialization Function */
extern void DIO_voidInit(void) {

	// Setting ports as input
	*DIO_u8DDRArr[DIO_u8PORT0] = DIO_u8PORTA_DIR;
	*DIO_u8DDRArr[DIO_u8PORT1] = DIO_u8PORTB_DIR;
	*DIO_u8DDRArr[DIO_u8PORT2] = DIO_u8PORTC_DIR;
	*DIO_u8DDRArr[DIO_u8PORT3] = DIO_u8PORTD_DIR;

	//output configuration
	/* OUTPUT=((D'PORT)+(DV)) */


	*DIO_u8PORTArr[DIO_u8PORT0]=((~DIO_u8PORTA_DIR & *DIO_u8PORTArr[DIO_u8PORT0]) | (DIO_u8PORTA_DIR & DIO_u8PORTA_VAL));
	*DIO_u8PORTArr[DIO_u8PORT1]=((~DIO_u8PORTB_DIR & *DIO_u8PORTArr[DIO_u8PORT1]) | (DIO_u8PORTB_DIR & DIO_u8PORTB_VAL));
	*DIO_u8PORTArr[DIO_u8PORT2]=((~DIO_u8PORTC_DIR & *DIO_u8PORTArr[DIO_u8PORT2]) | (DIO_u8PORTC_DIR & DIO_u8PORTC_VAL));
	*DIO_u8PORTArr[DIO_u8PORT3]=((~DIO_u8PORTD_DIR & *DIO_u8PORTArr[DIO_u8PORT3]) | (DIO_u8PORTD_DIR & DIO_u8PORTD_VAL));


}




