#include<avr/io.h>
#include<util/delay.h>

#define F_CPU 1000000ul
#define BaudRate 4800
#define myubrr ((F_CPU/(BaudRate*16ul))-1)

void uart_init()
{
 UBRRH=(myubrr>>8);
 UBRRL=myubrr;
 UCSRB|=1<<RXEN;
}

unsigned int uart_recieve()
{
 while((UCSRA&(1<<RXC))==0);
 return UDR;
}

void main()
{
 unsigned char value;
 DDRB=0b11111111;
 uart_init();
 _delay_ms(50);
 
 while(1)
 {
  value=uart_recieve();
  
  if(value=='F')
   PORTB=0b00001010;
  else if(value=='B')
        PORTB=0b00000101;
        else if(value=='R')
              PORTB=0b00000110;
             else if(value=='L')
                   PORTB=0b00001001;
                   else if(value=='V')
				         PORTB=0b00100000;
						 _delay_ms(80);
						 else
                          PORTB=0b00000000;
 }
} 