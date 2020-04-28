#include "STD_TYPES.h"
#include"BIT_MATHs.h"
#include "DIO_interface.h"
#include "led_interface.h"
#include "led_private.h"
#include "led_config.h"




void SetLedOn(void)
{
  
  SetpinValue(LED_PORT,LED_PIN,LED_MODE);
  
}


void SetLedOff(void)
{


	//SetpinValue(LED_PORT,LED_PIN,TOGGLE_BIT(LED_MODE,0));

	SetpinValue(LED_PORT,LED_PIN,0);
}
