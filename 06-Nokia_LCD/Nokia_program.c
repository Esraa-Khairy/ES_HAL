/*
 * Nokia_program.c
 *
 *  Created on: Apr 22, 2020
 *      Author: pc
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"   // for delay
#include "Nokia_interface.h"
#include "Nokia_private.h"




 void Write_Data (u8 Copy_u8Data)
{
	/*clr ce pin */
	DIO_SetPinVal('A',3,0);


	/* DC =1 for data */

	DIO_SetPinVal('A',1,1);

	/* Send data over SPI */
	SPI_u8SendSynch(Copy_u8Data);

	/* set ce pin */
	DIO_SetPinVal('A',3,1);


}


 void Write_Cmd (u8 Copy_u8Cmd)
{


	/*clr ce pin */
		DIO_SetPinVal('A',3,0);


		/* DC =0 for data */

		DIO_SetPinVal('A',1,0);

		/* Send data over SPI */
		SPI_u8SendSynch(Copy_u8Cmd);

		/* set ce pin */
		DIO_SetPinVal('A',3,1);



}

void Nokia_voidInit(void)
{

	/* Reset pulse H 2ms L 2ms H*/
	DIO_SetPinVal('A',2,1);
	STK_voidBusyDelay(2000);

	DIO_SetPinVal('A',2,0);
	STK_voidBusyDelay(2000);

	DIO_SetPinVal('A',2,1);

	/* Init Commands */
	/* 1- Go for extended mode */
	Write_Cmd(0b00100001);

	/* temperatire coeff command */
	Write_Cmd(0b00000110);
	/* Bias system 1: 48*/
	Write_Cmd(0b000010011);
	/* Set Vop -> Contrast (recommended value ) */
	Write_Cmd(0xBE);

	/* 2- Go back for the normal mode */
	Write_Cmd (0b00100000);

	/* Display Control command */
	Write_Cmd(0b00001100);



}


void Nokia_voidDisplay (u8 * Copy_DataArray)
{
	u16 i;
	/* x = 0 and y =0 */
	Write_Cmd(0b01000000); /* y = 0*/
	Write_Cmd(0b10000000); /* x = 0*/
	/*4048 /8 as it will be send as 1 byte*/
	for ( i = 0 ; i<504 ; i++)
	{
		Write_Data(Copy_DataArray[i]);


	}


}



