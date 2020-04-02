#include<avr/io.h>
#include<util/delay.h>

void init_adc()
{
 ADCSRA|=1<<ADEN;
 ADCSRA|=1<<ADPS2;
 ADMUX|=1<<REFS0;
 }
 
 unsigned int read_adcs()
 {
  int p=0b00000011;
  ADMUX&=0b1100000000;
  ADMUX|=p;
  ADCSRA|=1<<ADSC;
  while((ADCSRA&(1<<ADIF))==0);
  ADCSRA|=1<<ADIF;
  return ADC;
 }
 
 unsigned int read_adcd()
 {
  int d=0b00000101;
  ADMUX|=d;
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
  unsigned int p1;
  
  while(1)
  {
   p=read_adcs();
   p1=read_adcd();
   a=p/40;
   T=25;
   Toff=a;
   Ton=T-Toff;
   
   if(p1<256)
   { 
      PORTB=0b00001010;
     _delay_ms(Ton);
      PORTB=0b00000000;
      _delay_ms(Toff);
	}  
	else if((p1>=256)&&(p1<512))
	     {  
            PORTB=0b00001001;
            _delay_ms(Ton);
            PORTB=0b00000000;
            _delay_ms(Toff);
		
		  }	
	     else if((p1>512)&&(p1<768))
	          {
			    
                PORTB=0b00000110;
                _delay_ms(Ton);
                PORTB=0b00000000;
                _delay_ms(Toff);
			   }
	           else
		       {
			    
                 PORTB=0b00000101;
                 _delay_ms(Ton);
                 PORTB=0b000000000;
                 _delay_ms(Toff);
			    }
	
   
  }
 } 
 
  
  