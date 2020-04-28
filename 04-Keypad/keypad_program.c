#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include "DIO_interface.h"

#include "keypad_config.h"
#include "keypad_interface.h"


u8 KEYPAD_GetPressedKey(void)
{
  // 4 arrays ports  and pin for rows and cols not global 3shan msh ay 7ad y2dr yt3mlhom extern w yl3b fehom we msh local 3shan msh kol lma a3ml call hy7sl push we pop ll array kol shwya fn5leha static we keda keda hya const values 
  u8 RawsCounter;
  u8 ColsCounter;
  u8 PressedKey=KEYPAD_NOKEYPRESSED;   //according to misera just one return for each function
  
  static u8 KEYPAD_ColsPortArray[KEYPAD_COLSMAX]=KEYPAD_COLS_PORTS;
  static u8 KEYPAD_ColsPinArray[ KEYPAD_COLSMAX]=KEYPAD_COLS_PINS;
  
  static u8 KEYPAD_RowsPinArray[KEYPAD_ROWSMAX]=KEYPAD_ROWS_PINS;   //@pad.config for user readablily and modificatio
  static u8 KEYPAd_RowsPortArray[KEYPAD_ROWSMAX]=KEYPAD_ROWS_PORTS;

  static u8 KEYPAD_KeysArray[KEYPAD_ROWSMAX][KEYPAD_COLSMAX]= KEYPAD_KEYS;
  
  
  for(RawsCounter=0;RawsCounter<KEYPAD_ROWSMAX;RawsCounter++)
  {
    /* put on each row value =0 */
    SetpinValue(KEYPAd_RowsPortArray[RawsCounter],KEYPAD_RowsPinArray[RawsCounter],0);  // raws -> output
    /* check on each col */
    for (ColsCounter=0;ColsCounter<KEYPAD_COLSMAX;ColsCounter++)    // cols -> input
    {
      if(!GetPinValue(KEYPAD_ColsPortArray[ColsCounter],KEYPAD_ColsPinArray[ColsCounter]))
      {
        PressedKey=KEYPAD_KeysArray[RawsCounter][ColsCounter];
        
        while (!GetPinValue(KEYPAD_ColsPortArray[ColsCounter],KEYPAD_ColsPinArray[ColsCounter]));
        
      }
    }
    SetpinValue(KEYPAd_RowsPortArray[RawsCounter],KEYPAD_RowsPinArray[RawsCounter],1);
    
  }
  return PressedKey;
    
}
