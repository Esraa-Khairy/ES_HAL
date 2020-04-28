#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "DIO_interface.h"
#include "seg_config.h"
#include "seg_interface.h"


u8 last_num=SEVENSEG_INIT_VAL;

//int arr[11]={0x3f,0x06,0x5B,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x80};
//{0b00111111,.....};
void SevenSeg_SetNumber (u8 Num )
{
 u8 SevenSeg_Numbers[11]={0x3f,0x06,0x5B,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x80};
  ///u8 SevenSeg_Numbers[6]={0x01,0x02,0x04,0x08,0x10,0x20};
  
  #if SEVENSEG_MODE == 1      //cathode
  	SetpinValue(SEVENSEG_PIN_A_PORT,SEVENSEG_PIN_A_NUM,GET_BIT(SevenSeg_Numbers[Num],0));
  	SetpinValue(SEVENSEG_PIN_B_PORT,SEVENSEG_PIN_B_NUM,GET_BIT(SevenSeg_Numbers[Num],1));
    SetpinValue(SEVENSEG_PIN_C_PORT,SEVENSEG_PIN_C_NUM,GET_BIT(SevenSeg_Numbers[Num],2));
    SetpinValue(SEVENSEG_PIN_D_PORT,SEVENSEG_PIN_D_NUM,GET_BIT(SevenSeg_Numbers[Num],3));
    SetpinValue(SEVENSEG_PIN_E_PORT,SEVENSEG_PIN_E_NUM,GET_BIT(SevenSeg_Numbers[Num],4));
    SetpinValue(SEVENSEG_PIN_F_PORT,SEVENSEG_PIN_F_NUM,GET_BIT(SevenSeg_Numbers[Num],5));
    SetpinValue(SEVENSEG_PIN_G_PORT,SEVENSEG_PIN_G_NUM,GET_BIT(SevenSeg_Numbers[Num],6));
  //  SetpinValue(SEVENSEG_PIN_H_PORT,SEVENSEG_PIN_H_NUM,GET_BIT(SevenSeg_Numbers[Num],7));
  
  #else 
    SetpinValue(SEVENSEG_PIN_A_PORT,SEVENSEG_PIN_A_NUM,GET_BIT(SevenSeg_Numbers[Num],0)^0x01);
    SetpinValue(SEVENSEG_PIN_B_PORT,SEVENSEG_PIN_B_NUM,GET_BIT(SevenSeg_Numbers[Num],1)^0x01);
    SetpinValue(SEVENSEG_PIN_C_PORT,SEVENSEG_PIN_C_NUM,GET_BIT(SevenSeg_Numbers[Num],2)^0x01);
    SetpinValue(SEVENSEG_PIN_D_PORT,SEVENSEG_PIN_D_NUM,GET_BIT(SevenSeg_Numbers[Num],3)^0x01);
    SetpinValue(SEVENSEG_PIN_E_PORT,SEVENSEG_PIN_E_NUM,GET_BIT(SevenSeg_Numbers[Num],4)^0x01);
    SetpinValue(SEVENSEG_PIN_F_PORT,SEVENSEG_PIN_F_NUM,GET_BIT(SevenSeg_Numbers[Num],5)^0x01);
    SetpinValue(SEVENSEG_PIN_G_PORT,SEVENSEG_PIN_G_NUM,GET_BIT(SevenSeg_Numbers[Num],6)^0x01);
    SetpinValue(SEVENSEG_PIN_H_PORT,SEVENSEG_PIN_H_NUM,GET_BIT(SevenSeg_Numbers[Num],7)^0x01);
  
 #endif
 
 last_num = Num;
 
}

u8 SEVENSEG_ENABLE_PORTS[2]={SEVENSEGONE_ENABLE_PORT,SEVENSEGTWO_ENABLE_PORT}; // IF I HAVE MANY SEGMENTS SOLOTION IS ARRAY

u8 SEVENSEG_ENABLE_PINS[2]={SEVENSEGONE_ENABLE_PIN,SEVENSEGTWO_ENABLE_PIN};

u8 counter;







void SevenSeg_Enable (u8 SEVENSEGNUMBER)
{


	  	 #if SEVENSEG_MODE ==1 //cathode

	      SetpinValue(SEVENSEG_ENABLE_PORTS[SEVENSEGNUMBER],SEVENSEG_ENABLE_PINS[SEVENSEGNUMBER],0);

		#elif SEVENSEG_MODE ==0 //Anode
	      SetpinValue(SEVENSEG_ENABLE_PORTS[SEVENSEGNUMBER],SEVENSEG_ENABLE_PINS[SEVENSEGNUMBER],1);
	      SevenSeg_SetNumber (last_num);
		#endif
	      SevenSeg_SetNumber (last_num);
  
  
}

void SevenSeg_Disable (u8 SEVENSEGNUMBER)
{
		#if SEVENSEG_MODE ==1 //cathode
	      SetpinValue(SEVENSEG_ENABLE_PORTS[SEVENSEGNUMBER],SEVENSEG_ENABLE_PINS[SEVENSEGNUMBER],1);
		#elif SEVENSEG_MODE ==0 //Anode
	      SetpinValue(SEVENSEG_ENABLE_PORTS[SEVENSEGNUMBER],SEVENSEG_ENABLE_PINS[SEVENSEGNUMBER],0);
		#endif
}
  

