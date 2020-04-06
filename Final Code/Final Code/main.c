#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include "lcd.h"

#define F_CPU 16000000

int main(void)
{
	DDRA=0XFF;
	DDRB=0X00;
	DDRD=0b00111000;
	PORTD |=(1 << 0);
	PORTD |=(1 << 1);
	PORTD |=(1 << 2);
	PORTB |=(1 << 0);
	PORTB |=(1 << 1);
	PORTB |=(1 << 2);
	PORTB |=(1 << 3);
	PORTB |=(1 << 4);
	PORTB |=(1 << 5);
    int acc = 0, ref = 0, neu = 0, i =0, j =0, k =0;
	
	/* LCD initialization*/
	isBusy();
	
	/*The Printed Text OR Numbers on the LCD Screen*/
	LCD_ShowData();
	
    while (1) 
    { 
		
		/*if (!(PINB&(1<<PB0)) || !(PINB&(1<<PB1)) || !(PINB&(1<<PB2)))
		{
			if(i==0)
			{ 
				if(!(PINB&(1<<PB0)))
				{
					while(!(PINB&(1<<PB0))){};
					acc++;
					itoa(acc,pos,10);
					location(3,2);
					Send_A_String(pos);
					_delay_ms(15);
					i++;
				}
				
				
				if(!(PINB&(1<<PB1)))
				{
					while(!(PINB&(1<<PB1))){};
					ref++;
					itoa(ref,pos,10);
					location(8,2);
					Send_A_String(pos);
					_delay_ms(15);
					i++;
				}
				
				if(!(PINB&(1<<PB2)))
				{ 
					while(!(PINB&(1<<PB2))){};
					neu++;
					itoa(neu,pos,10);
					location(13,2);
					Send_A_String(pos);
					_delay_ms(15);
					i++;
				}
				
			}
		}
			
			if (!(PINB&(1<<PB3)) || !(PINB&(1<<PB4)) || !(PINB&(1<<PB5)))
			{
				if(j==0)
				{
					if(!(PINB&(1<<PB3)))
					{
						while(!(PINB&(1<<PB3))){};
						acc++;
						itoa(acc,pos,10);
						location(3,2);
						Send_A_String(pos);
						_delay_ms(15);
						j++;
					}
					
					
					if(!(PINB&(1<<PB4)))
					{
						while(!(PINB&(1<<PB4))){};
						ref++;
						itoa(ref,pos,10);
						location(8,2);
						Send_A_String(pos);
						_delay_ms(15);
						j++;
					}
					
					if(!(PINB&(1<<PB5)))
					{
						while(!(PINB&(1<<PB5))){};
						neu++;
						itoa(neu,pos,10);
						location(13,2);
						Send_A_String(pos);
						_delay_ms(15);
						j++;
					}
					
				}
			}
			
			if (!(PIND&(1<<PD0)) || !(PIND&(1<<PD1)) || !(PIND&(1<<PD2)))
			{
				if(k==0)
				{
					if(!(PIND&(1<<PD0)))
					{
						while(!(PIND&(1<<PD0))){};
						acc++;
						itoa(acc,pos,10);
						location(3,2);
						Send_A_String(pos);
						_delay_ms(15);
						k++;
					}
					
					
					if(!(PIND&(1<<PD1)))
					{
						while(!(PIND&(1<<PD1))){};
						ref++;
						itoa(ref,pos,10);
						location(8,2);
						Send_A_String(pos);
						_delay_ms(15);
						k++;
					}
					
					if(!(PIND&(1<<PD2)))
					{
						while(!(PIND&(1<<PD2))){};
						neu++;
						itoa(neu,pos,10);
						location(13,2);
						Send_A_String(pos);
						_delay_ms(15);
						k++;
					}
					
				}
			}
		}
}*/
		if(!(PINB&(1<<PB0)) || !(PINB&(1<<PB3)) || !(PIND&(1<<PD0))) 
		{ 
			while(!(PINB &(1<<PINB0)) || !(PINB &(1<<PINB3)) || !(PIND &(1<<PIND0)))  {};   
			acc++;
			itoa(acc,pos,10);
			location(3,2);
			Send_A_String(pos);
			_delay_ms(15);
		}
		
		if(!(PINB&(1<<PB1)) || !(PINB&(1<<PB4)) || !(PIND&(1<<PD1)))
		{
				
			while(!(PINB &(1<<PINB1)) || !(PINB &(1<<PINB4)) || !(PIND &(1<<PIND1))){ };
			ref++;
			itoa(ref,pos,10);
			location(8,2);
			Send_A_String(pos);
			_delay_ms(15);
		}
				
		if(!(PINB&(1<<PB2)) || !(PINB&(1<<PB5)) || !(PIND&(1<<PD2)))
		{
			while(!(PINB &(1<<PINB2)) || !(PINB &(1<<PINB5)) || !(PIND &(1<<PIND2))){};
			neu++;
			itoa(neu,pos,10);
			location(13,2);
			Send_A_String(pos);
			_delay_ms(15);
		}
			
    }
}
