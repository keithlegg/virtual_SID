  
//PORTC - TIMING AND LEDS 

//LED outputs   
#define LED1 0x04 //pc4
#define LED2 0x08 //pc5 

//SID clock pins  
#define SID_MSTR_CLK PC0
#define SID_RW PC1
#define SID_CS PC2

/**************/

//PORTB - 5 ADDRESS LINES
//SID address lines
#define SID_A0 PB0
#define SID_A1 PB1
#define SID_A2 PB2
#define SID_A3 PB3
#define SID_A4 PB4

/**************/

//PORTD - 8bit DATAPORT //IF RW GOES HIGH C64 READS 
//SID bi-data lines
#define SID_D0 PD0
#define SID_D1 PD1
#define SID_D2 PD2
#define SID_D3 PD3
#define SID_D4 PD4
#define SID_D5 PD5
#define SID_D6 PD6
#define SID_D7 PD7
 
