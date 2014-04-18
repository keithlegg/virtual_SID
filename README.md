Virtual SID with an AVR - a really crazy stupid experiment.

So it all started when some dillhole ripped me off on ebay and I bought 3 commodore 64's to pull the SID chips out of them.
Turns out dude already pulled the chips and sold me some C64's with no sound. To make lemonaide out of lemons, I decided to build
my own virtual SID chip with an AVR, just to see if I could.

Yes, I have actually soldered an AVR chip into a socket that plugs into the C64 motherboard.

So I went to work reading up on how the SID works, I still dont know exactly but I am getting there. 
Heres what I do know (at least I think I do)

The memory (commands) of the C64 are arranged into 65,535 registers. You can access those with the poke command a 16 bit address followed 
by a byte of command data. The SID chip has 29 registers, accessed by a 5 bit address port and an 8 bit data port.

The C64 memory address for SID are 54272-54296 (0xd400- 0xd418)

This is a proof of concept AVR program to see if you can access those registers by poking an address.

I know it is all wrong but it is halfway working. 

I havent implemented interrupts yet , this is all a big test.

Here is the pinout of my setup.

RST NC
02/CLK PC0
R/W PC1
CS PC2

ADDR0 PB0
ADDR1 PB1
ADDR2 PB2
ADDR3 PB3
ADDR4 PB4

PORTD will be my 8bit data bus when I get there. Because of the SID using 5 bit address, I mask off the top 3 most signifigant 
bits with a mask on PINB. (PINB & 0x1f ); 


For example:

POKE 54273,255 

would look like this in binary:

POKE 1101010000000001, 11111111

breaking down that address we get:

11010100 00000001

then "AND" masking the lower byte with 5 bits we get:

 00000001 -LOWER BYTE of C64 POKE. 
 00011111 -& 0x1f MASK. 
 xxx00001 -The resulting address masked out  
        

not sure if this will ever work , but eventually if I get the timing correect I will add the 8 bit data port and put 3 DAC chips on
the PCB to generate the 3 SID voices.

One word of advice - make sure you are very carefull to set EVERY pin properly. All pins not in use MUST bin the HI-Z state or the 
commodore will flip out and maybe even be damaged. I haven't hurt mine yet however. 


Keith Legg 
April 12, 2014












