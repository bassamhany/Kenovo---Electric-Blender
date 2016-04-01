/*
 * TACTILE_prog.c
 *
 *  Created on: Feb 16, 2016
 *      Author: bassam
 */
#include "Types.h"
#include "TACTILE_private.h"
#include "TACTILE_interface.h"
#include "TACTILE_config.h"
#include "DIO_interface.h"

u8 SwitchPinArr[16]={SWITCH1PIN,SWITCH2PIN,SWITCH3PIN,SWITCH4PIN,SWITCH5PIN,SWITCH6PIN,SWITCH7PIN,SWITCH8PIN,SWITCH9PIN,SWITCH10PIN,SWITCH11PIN,
		SWITCH12PIN,SWITCH13PIN,SWITCH14PIN,SWITCH15PIN,SWITCH16PIN
};

static u8 ButtonsState[16]={RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED};

static u8 ButtonsPressedFlag[16]={RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED,RELEASED};

static u8 ButtonsLowCounter[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

static u8 ButtonsHighCounter[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


static u8 ButtonVal=0;



extern void TACTILE_voidInit()
{}



extern void TACTILE_u8GetButtonState(u8 Copy_u8ButtonIdx,u8 *Copy_u8ButtonVal)
{
	DIO_u8ReadPinVal(SwitchPinArr[Copy_u8ButtonIdx-1],&ButtonVal);
	switch (ButtonsState[Copy_u8ButtonIdx-1])
		{
		case RELEASED:
			if(ButtonVal==1)
				{
					ButtonsState[Copy_u8ButtonIdx-1]=BOUNCE;
					ButtonsPressedFlag[Copy_u8ButtonIdx-1]=RELEASED;
					*Copy_u8ButtonVal=RELEASED;
				}
			else
			{
				*Copy_u8ButtonVal=RELEASED;
			}
			break;
		case PRESSED:
			if(ButtonVal==0)
					{
				ButtonsState[Copy_u8ButtonIdx-1]=BOUNCE;
				ButtonsPressedFlag[Copy_u8ButtonIdx-1]=PRESSED;
				*Copy_u8ButtonVal=PRESSED;
					}
			else
			{
				*Copy_u8ButtonVal=PRESSED;
			}
			break;
		case BOUNCE:
			if(ButtonVal==1)
			{
				ButtonsLowCounter[Copy_u8ButtonIdx-1]=0;
				ButtonsHighCounter[Copy_u8ButtonIdx-1]+=1;
				*Copy_u8ButtonVal=ButtonsPressedFlag[Copy_u8ButtonIdx-1];
			}
			else
			{
				ButtonsHighCounter[Copy_u8ButtonIdx-1]=0;
				ButtonsLowCounter[Copy_u8ButtonIdx-1]+=1;
				*Copy_u8ButtonVal=ButtonsPressedFlag[Copy_u8ButtonIdx-1];
			}
			if(ButtonsHighCounter[Copy_u8ButtonIdx-1]==BOUNCETIME)
			{
				ButtonsState[Copy_u8ButtonIdx-1]=PRESSED;
				ButtonsHighCounter[Copy_u8ButtonIdx-1]=0;
				*Copy_u8ButtonVal=PRESSED;
			}
			else if (ButtonsLowCounter[Copy_u8ButtonIdx-1]==BOUNCETIME)
			{
				ButtonsState[Copy_u8ButtonIdx-1]=RELEASED;
				ButtonsLowCounter[Copy_u8ButtonIdx-1]=0;
				*Copy_u8ButtonVal=RELEASED;
			}
			else
			{

			}

			break;
		default:
			break;
		}

}
