#include<avr/io.h>
#include<util/delay.h>

void main()

{
 int c,i;
 DDRB=0b00000000;
 DDRD=0b11111111;
 PORTB=0b11111111;
 
 
 while(1)
 {
  c=PINB;
  if(c==0b11111111)
  {
   PORTD=0b10000000;
  
  }
 }
 
}  