#include<avr/io.h>
#include<util/delay.h>

void main()
{
 int c;
 
DDRD=0b00000000;
DDRB=0b11111111;
PORTD=0b11111111;

while(1)
{
 c=PIND;

 if(c==0b11110000)//all on
   PORTB=0b00001010;
 
 if(c==0b11111000)//1 of
 {
  PORTB=0b00000101;
  _delay_ms(300);
  PORTB=0b00001001;
  _delay_ms(200);
  }
   
   
  if(c==0b11110100)
  {
  PORTB=0b00000101;
  _delay_ms(250);
  PORTB=0b00001001;
  _delay_ms(220);
  }
  
  if(c==0b11110010)
   {
    PORTB=0b00001010;
    _delay_ms(200);
    PORTB=0b00000110;
    _delay_ms(190);
  }
  
  if(c==0b11110001)  
  {
   PORTB=0b00001010;
   _delay_ms(260);
   PORTB=0b00001001;
   _delay_ms(290);
  }
  
  if(c==0b11111001)
  {
   PORTB=0b00001010;
   _delay_ms(160);
   PORTB=0b00001001;
   _delay_ms(215);
  }
  
  if(c==0b11111001)
   PORTB=0b00001001;
   
  if(c==0b11110011)
   PORTB=0b00001010;
   
  if(c==0b11110110)
   PORTB=0b00000110;
   
  if(c==0b11111110)
   PORTB=0b00000110;
   
  if(c==0b11110111)
   PORTB=0b00000110;
   
  if(c==0b11111011)
   PORTB=0b00001001;
   
  if(c==0b11111101)
   PORTB=0b0000101;
  }
  }

 