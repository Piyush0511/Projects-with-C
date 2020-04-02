#include<avr/io.h>
#include<util/delay.h>

void main()
{
 DDRD=0b00000000;  //SEtting part D as input
 DDRB=0b11111111;  //setting part b as output
 PORTD=0b11111111; //Pulling up D
 int c;
 while(1)
 {
  c=PIND;
  
  if(c==0b11111111) //no obstacle
   PORTB=0b00001010; //Forward
	
  if(c==0b11111110) //obstacle to the right
   PORTB=0b00000110; //turn left
   
  if(c==0b11111101)//obstacle at center
  {
   PORTB=0b00000101;//back
   _delay_ms(600);
   PORTB=0b00001001;//right
   _delay_ms(400);
  }
 
  if(c==0b11111100)//o at c and r
  {
   PORTB=0b00000101;//back
   _delay_ms(600);
   PORTB=0b00000110;//left
   _delay_ms(500);
  }
 
  if(c==0b11111011)//o to the left
  {
   PORTB=00001001;//turn left
  }

  if(c==0b11111010)//o on both sides
  {
   PORTB=0b00000101;//go back
   _delay_ms(600);
   PORTB=0b00001001;//turn right
   _delay_ms(500);
  }
 
  if(c==0b11111001)//o on c and r
  {
   PORTB=0b00000101;//back
   _delay_ms(600);
   PORTB=0b00001001;//right
   _delay_ms(500);
  }
  
  if(c==0b11111000) //o an all sides
  {
   PORTB=0b00000101;//back
   _delay_ms(600);
   PORTB=0b00001001;//u turn
   _delay_ms(10000);
  }
   
 }
} 
  
  
  
 
	