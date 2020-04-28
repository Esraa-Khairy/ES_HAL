/* KEYPAD RAWS PINS CONFIG*/
#define KEYPAD_ROWSMAX 4
#define KEYPAD_COLSMAX 4

#define KEYPAD_R0_PORT 'A'
#define KEYPAD_R0_PIN   0
                       
#define KEYPAD_R1_PORT 'A'
#define KEYPAD_R1_PIN   1
                       
#define KEYPAD_R2_PORT 'A'
#define KEYPAD_R2_PIN   2
                       
#define KEYPAD_R3_PORT 'A'
#define KEYPAD_R3_PIN   3
                       
/* KEYPAD COL PINS CON IG*/
                       
#define KEYPAD_C0_PORT 'A'
#define KEYPAD_C0_PIN   4
                       
#define KEYPAD_C1_PORT 'A'
#define KEYPAD_C1_PIN   5
                       
#define KEYPAD_C2_PORT 'A'
#define KEYPAD_C2_PIN   6
                       
#define KEYPAD_C3_PORT 'A'
#define KEYPAD_C3_PIN   7

#define KEYPAD_COLS_PORTS {KEYPAD_C0_PORT,KEYPAD_C1_PORT,KEYPAD_C2_PORT,KEYPAD_C3_PORT}
#define KEYPAD_COLS_PINS  {KEYPAD_C0_PIN,KEYPAD_C1_PIN,KEYPAD_C2_PIN,KEYPAD_C3_PIN}

#define KEYPAD_ROWS_PORTS {KEYPAD_R0_PORT,KEYPAD_R1_PORT,KEYPAD_R2_PORT,KEYPAD_R3_PORT}
#define KEYPAD_ROWS_PINS  {KEYPAD_R0_PIN,KEYPAD_R1_PIN,KEYPAD_R2_PIN,KEYPAD_R3_PIN}


#define KEYPAD_KEYS {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}}
#define KEYPAD_NOKEYPRESSED 0xff   //255
