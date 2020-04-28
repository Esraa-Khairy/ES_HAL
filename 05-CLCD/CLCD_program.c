
#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "CLCD_interface.h"
#include "CLCD_config.h"
#include "PORT_config.h"
#include "Delay_interface.h"





void CLCD_voidSetDataPort(u8 Copy_u8Data)     // its private function no one outside this file cal call it  theres API opposite of private function
{

  u8 Local_u8BitVal;


  Local_u8BitVal = GET_BIT( Copy_u8Data,0);


  SetpinValue (CLCD_u8_D0_PORT,CLCD_u8_D0_PIN,Local_u8BitVal) ;    // no loop because its macro

  Local_u8BitVal=GET_BIT(Copy_u8Data,1);
  SetpinValue (CLCD_u8_D1_PORT,CLCD_u8_D1_PIN,Local_u8BitVal) ;


  Local_u8BitVal=GET_BIT( Copy_u8Data,2);
  SetpinValue (CLCD_u8_D2_PORT,CLCD_u8_D2_PIN,Local_u8BitVal) ;

  Local_u8BitVal=GET_BIT(Copy_u8Data,3);
  SetpinValue (CLCD_u8_D3_PORT,CLCD_u8_D3_PIN,Local_u8BitVal);

  Local_u8BitVal=GET_BIT(Copy_u8Data,4);
  SetpinValue (CLCD_u8_D4_PORT,CLCD_u8_D4_PIN,Local_u8BitVal);

  Local_u8BitVal=GET_BIT(Copy_u8Data,5);
  SetpinValue (CLCD_u8_D5_PORT,CLCD_u8_D5_PIN,Local_u8BitVal);

  Local_u8BitVal=GET_BIT(Copy_u8Data,6);
  SetpinValue (CLCD_u8_D6_PORT,CLCD_u8_D6_PIN,Local_u8BitVal);

  Local_u8BitVal=GET_BIT( Copy_u8Data,7);
  SetpinValue (CLCD_u8_D7_PORT,CLCD_u8_D7_PIN,Local_u8BitVal);

}


/* Description: This API shall initiaalize LCD      */
void CLCD_voidInitialize (void)
{
  delay_ms(40);
  CLCD_voidWriteCMD(0b00111000);
  CLCD_voidWriteCMD(0b00001100);
  CLCD_voidWriteCMD(0b00000001);
  

}

/* Description: this API shall display Data on LCD  */
void CLCD_voidWriteData (u8 Copy_u8Data)
{
  
  
  /* set rs =1*/
	SetpinValue(CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,1);
  /* set rw =0 */
	SetpinValue(CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
  /* set data on data port*/
	CLCD_voidSetDataPort(Copy_u8Data);
 
  /* enable pulse*/
  
	SetpinValue (CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
  delay_ms(1);
  SetpinValue (CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
  delay_ms(1);
  
}

/* Description: this API shall execute command      */
void CLCD_voidWriteCMD (u8 Copy_u8Cmd)
{
  
   /* set rs =0*/
	SetpinValue (CLCD_u8_RS_PORT,CLCD_u8_RS_PIN,0);
  /* set rw =0 */
	SetpinValue (CLCD_u8_RW_PORT,CLCD_u8_RW_PIN,0);
  /* set data on data port*/
	CLCD_voidSetDataPort(Copy_u8Cmd);
 
  /* enable pulse*/
  
	SetpinValue (CLCD_u8_E_PORT,CLCD_u8_E_PIN,1);
  delay_ms(1);
  SetpinValue (CLCD_u8_E_PORT,CLCD_u8_E_PIN,0);
  delay_ms(1);
  
  
}
/* Description: this API shall clear Data on LCD 	*/
void CLCD_voidClearData (void)
{
	CLCD_voidWriteCMD(0b00000001);
}
void CLCD_EnableSecondLine (void)
{
	CLCD_voidWriteCMD(0b110000000);
}

void CLCD_ShiftRDisplay (void)
{
	CLCD_voidWriteCMD(0b00000001);
}
void CLCD_ShiftLDisplay (void)
{
	CLCD_voidWriteCMD(0b00000011);
}

void CLCD_voidWriteString(u8 *copy_pu8String)
{
	u8 Local_u8Counter=0;
	while(copy_pu8String[Local_u8Counter]!='\0')
	{
		CLCD_voidWriteData (copy_pu8String[Local_u8Counter]);
		Local_u8Counter ++;
	}

}

void CLCD_voidGotoLocation(u8 copy_LineNb,u8 copy_Position)
{
	if (copy_LineNb==CLCD_LINE_1)
	{
		CLCD_voidWriteCMD(CLCD_LINE_1_CMD+copy_Position);

	}
	else if (copy_LineNb==CLCD_LINE_2)
	{
		CLCD_voidWriteCMD(CLCD_LINE_2_CMD+copy_Position);

	}
	else
	{}

}
