
#include <avr/io.h>

#include "vsid.h"

#define F_CPU 16000000UL //AVR Clock Speed in MHZ
#include <util/delay.h>  //max delay is  262.14 ms / F_CPU in MHz.


/*
  //C64 to AVR pin mapping
  
  //PORTC- SID timing control 
  0x04 - CS   pin
  0x02 - R/W  pin -active low , SID read
  0x01 - CLK  pin
  
  //PORTB - SID addresses
  0x01 - sid_addr0
  0x02 - sid_addr1
  0x03 - sid_addr2
  0x04 - sid_addr3
  0x05 - sid_addr4
   
  //PORTD - SID data bus
  
   
 */
  
 
int count,c2 = 0;

//test to count clock pulses - tested at 1 Mhz
inline void count_clock(void){

  	
	  //read a single pin by AND'ing the value
	  if(PINC & 0x01) 
      {
		 if (c2>=1000){  
           PORTC ^= 0x10; //flash output LED 
	       c2=0;
	     } 
	       
         if (count>=1000){
             count =0;
             c2++;
	     }
         count++;
      }
      
}

//simple LED output to see whats going on 
void blinky(int num){
   
   //all off
   PORTC = ~0x10;
        
   //flash pulses     
   int a=0;
   for (a=0;a<num;a++){
     PORTC = 0x10;
     _delay_ms(300);
     PORTC = ~0x10;
     _delay_ms(300);
                    
   } 
   _delay_ms(700); 
                         
}




int main (void)
{
  DDRB  = 0x00; // set PORTB for input
  DDRD  = 0x00; // set PORTD for input
 
  DDRC  = 0x00;  //all input  //DDRC = 0xf8;  //0b11111000 //this works too 
  DDRC |= 0x10; //pc5 - led output
 
  
  unsigned char sid_address;

  int blinker = 0;
    
  // &_BV(6) 
  
     					 
  while (1)
  {

    //if R/W is low
    //if (PINC & 0x02==0x00) 
    
    
    // if CS goes low - C64 is sending SID some data
    if (!(PINC & 0x04))     
	{
	   
	   while (!(PINC & 0x01)) {}; //spinlock for low clock
	   
	   
	   //clock is high
	   if (PINC & 0x01) {

	      //mask off the top 3 signifgant digits (0x1f)
	      sid_address = (PINB & 0x1f ); 
	      
	      //there are 29 registers on SID - each of these addresses
	      switch( sid_address ) {

	          case 0x1: // 54273 - 0xD401 
	            blinky(1);
	          break;
	          
	          case 0x2: // 54274 -11010100000 00010 
	            blinky(2);
	          break;
	          	          
	          case 0x3: // 54275 -11010100000 00011
	            blinky(3);
	          break;

	          case 0x4: // 54276 -11010100000 00100
	            blinky(4);
	          break;
	          
	          case 0x5: // 54277 -11010100000 00101
	            blinky(5);
	          break;
	          
	          case 0x6: // 54278 - 11010100000 00110 
	            blinky(6);
	          break;
	          
	          case 0x7: // 54279 - 11010100000 00111
	            blinky(7);
	          break;
	          
	          case 0x8: // 54280 - 11010100000 01000
	            blinky(8);
	          break;
	          	          	          	          	          	          	          	          
	          case 0x9: // 54281 - 11010100000 01001
	            blinky(9);
	          break;

	          case 0xA: // 54282 - 11010100000 01010 
	            blinky(10);
	          break;
	          
	          case 0xB: // 54283 - 11010100000 01011
	            blinky(11);
	          break;
	          	          
	          case 0xC: // 54284 - 11010100000 01100
	            blinky(12);
	          break;

	          case 0xD: // 54285 - 11010100000 01101
	            blinky(13);
	          break;
	          
	          case 0xE: // 54286 - 11010100000 01110
	            blinky(14);
	          break;
	          
	          case 0xF: // 54287 - 11010100000 01111
	            blinky(15);
	          break;
	          
	          case 0x10: // 54288 - 11010100000 10000
	            blinky(16);
	          break;
	          
	          case 0x11: // 54289 - 11010100000 10001
	            blinky(17);
	          break;
     
	          case 0x12: // 54290 -11010100000 10010
	            blinky(18);
	          break;
	          
	          case 0x13: // 54291 - 11010100000 10011
	            blinky(19);
	          break;
	          	          
	          case 0x14: // 54292 - 11010100000 10100
	            blinky(20);
	          break;

	          case 0x15: // 54293 - 11010100000 10101
	            blinky(21);
	          break;
	          
	          case 0x16: // 54294 - 11010100000 10110
	            blinky(22);
	          break;
	          
	          case 0x17: // 54295 - 11010100000 10111
	            blinky(23);
	          break;
	          
	          case 0x18: // 54296 - 11010100000 11000
	            blinky(24);
	          break;
	          
    	          	          	          	          	          
		  }//end switch
     
	   };// high clock
 
    }//CS low
	              
  }

  return 1;
}



//INTERRUPTS



