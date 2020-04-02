#include<avr/io.h>
#include<util/delay.h>

void init_adc()
{
 ADCSRA|=1<<ADEN;
 ADCSRA|=1<<ADPS2;
 ADMUX|=1<<REFS0;
 }
 
 unsigned int read_adc()
 {
  int p=0b00000011;
  ADMUX|=p;
  ADCSRA|=1<<ADSC;
  while((ADCSRA&(1<<ADIF))==0);
  ADCSRA|=1<<ADIF;
  return ADC;
 }
 
 void main()
 {
  DDRB=0b11111111;
  int c;
  init_adc();
  _delay_ms(500);
  unsigned int a,p,T,Ton,Toff;
  
  while(1)
  {
   p=read_adc();
   a=p/40;
   T=25;
   Toff=a;
   Ton=T-Toff;
   
   if(p<446)
   {
	 PORTB=0b00001010;
	 _delay_ms(Ton);
	 PORTB=0b00000000;
	 _delay_ms(Toff);
	}
   else
    PORTB=0;
  }
 } 
 
  
  