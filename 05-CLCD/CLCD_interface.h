
/*******************************/
/* Author   : Esraa Awad       */
/* Version  : V01              */
/* Date     : 14 jan 2020      */
/*******************************/

#define CLCD_LINE_1	1
#define CLCD_LINE_2	2

#define CLCD_LINE_1_CMD	0x80
#define CLCD_LINE_2_CMD 0xc0

/* Description: This API shall initiaalize LCD      */
void CLCD_voidInitialize (void);

/* Description: this API shall display Data on LCD  */
void CLCD_voidWriteData (u8 Copy_u8Data);

/* Description: this API shall execute command      */
void CLCD_voidWriteCMD (u8 Copy_u8Cmd);

/* Description: this API shall clear Data on LCD 	*/
void CLCD_voidClearData (void);


void CLCD_EnableSecondLine (void);

void CLCD_ShiftRDisplay (void);

void CLCD_ShiftLDisplay (void);


void CLCD_voidWriteString(u8 *copy_pu8String);

void CLCD_voidGotoLocation(u8 copy_LineNb,u8 copy_Position);
