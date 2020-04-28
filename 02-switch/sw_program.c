#include "STD_TYPES.h"
#include"BIT_MATHS.h"

#include "sw_interface.h"
#include "sw_private.h"
#include "sw_config.h"
#include "DIO_interface.h"




u8 Sw_return(void)
{

  u8 result = GetPinValue(SW_PORT,SW_PIN);
  
  if(RELEASE_STATE==1)   //pulldown
  {
      return result;
  }
  else
  {
    return result^1;
  }
  
  
}



