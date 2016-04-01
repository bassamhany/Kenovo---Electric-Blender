

#include "Types.h"
#include "DIO_interface.h"
#include "TACTILE_interface.h"
#include"PWM_interface.h"
#include "DCMotor_interface.h"
#define SW1 1
#define SW2 2
#define FALSE 0
#define TRUE 1
#define RIGHT_DIR 0
#define LEFT_DIR 1
#define NULL 5
#define ON 1



 int main(void)
 {




u8 Local_u8SwCounter= 0;
u8 Local_u8Sw1Value,Local_u8Sw2Value,Flag1= FALSE,Flag2 = FALSE,State=0;
DIO_voidInit();
TACTILE_voidInit();
PWM_init();
DCMotor_voidInit();


 while(1)
 {
///////////////////////////////System State/////////////////////////////////////////
	 TACTILE_u8GetButtonState(SW2,&Local_u8Sw2Value);// Check the System Switch
	 if(Local_u8Sw2Value == PRESSED && Flag2 == FALSE)
	 {
		 Flag2 = TRUE;
		 State = ! State; // Toggle the System State ON or OFF
	 }
	 else if(Local_u8Sw2Value == RELEASED)
	 	 {
	 		 Flag2 = FALSE;
	 	 }
////////////////////////////////System Speed////////////////////////////////////////
	 if(State == ON)
	 {
	 TACTILE_u8GetButtonState(SW1,&Local_u8Sw1Value);// Check the System Speed
		 if(Local_u8Sw1Value == PRESSED && Flag1 == FALSE)
		 {
			 Flag1 = TRUE;

			 Local_u8SwCounter++;
			 if(Local_u8SwCounter == 4)
			 {
				 Local_u8SwCounter=0;

			 }
		 }
		 else if(Local_u8Sw1Value == RELEASED)
		 {
			 Flag1 = FALSE;

		 }
		 switch(Local_u8SwCounter)
		 {
		 case 0:
			 DCMotor_voidOff();
			 break;
		 case 1:
			 DCMotor_voidChangeSpeed(0);
			 break;
		 case 2:
			 DCMotor_voidChangeSpeed(1);

					 break;
		 case 3:
			 DCMotor_voidChangeSpeed(2);

						 break;
		 default :
			 break;

		 }

 }
/////////////////////////////////////////////////////////////////////////////////////////
	 else
	 {
		 DCMotor_voidOff();

	 }
 }
 return 0;
 }
