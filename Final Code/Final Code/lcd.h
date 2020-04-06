#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define MrLCDsCrib PORTA
#define DataDir_MrLCDsCrib DDRA
#define MrLCDsControl PORTD
#define DataDir_MrLCDsControl DDRD
#define E 5
#define RW 4
#define RS 3


void isBusy(void);
void Blinklight(void);
void Send_A_Command(unsigned char command);
void Send_A_Character(unsigned char character);
void Send_A_String(char *StringOfCharacters);
void location(uint8_t x, uint8_t y);

char index[2] ={0,64};
char pos[2];
int acc = 0, ref = 0, neu = 0;
	

void isBusy()
{
	DataDir_MrLCDsCrib = 0;
	MrLCDsControl |= 1<<RW;
	MrLCDsControl &= ~1<<RS;

	while (MrLCDsCrib >= 0x80)
	{
		Blinklight();
	}

	DataDir_MrLCDsCrib = 0xFF; 
	
	Send_A_Command(0x01); //Clear Screen 0x01 = 00000001
	_delay_ms(2);
	Send_A_Command(0x38);
	_delay_us(50);
	Send_A_Command(0b00001110);
	_delay_us(50);
}

void Blinklight()
{
	MrLCDsControl |= 1<<E;
	asm volatile ("nop");
	asm volatile ("nop");
	MrLCDsControl &= ~1<<E;
}

void Send_A_Command(unsigned char command)
{
	MrLCDsCrib = command;
	MrLCDsControl &= ~ ((1<<RW)|(1<<RS));
	Blinklight();
	MrLCDsCrib = 0;
}

void Send_A_Character(unsigned char character)
{
	MrLCDsCrib = character;
	MrLCDsControl &= ~ (1<<RW);
	MrLCDsControl |= 1<<RS;
	Blinklight();
	MrLCDsCrib = 0;
}

void Send_A_String(char *StringOfCharacters)
{
	while(*StringOfCharacters > 0)
	{
		Send_A_Character(*StringOfCharacters++);
	}
}

void location(uint8_t x, uint8_t y)
{
	Send_A_Command(0x80 + index[y-1] + (x-1));
}

void LCD_Clear()
{
	Send_A_Command (0x01);		/* clear display */
	Send_A_Command (0x80);		/* cursor at home position */
}

void LCD_ShowData()
{
	location(2,1);
	Send_A_String("YES");
	_delay_ms(15);
	
	location(7,1);
	Send_A_String("NO");
	_delay_ms(15);
	
	location(12,1);
	Send_A_String("NONE");
	_delay_ms(15);
	
	itoa(acc,pos,10);    /*Convert integer numbers to strings to print it on the LCD*/
	location(3,2);
	Send_A_String(pos);
	_delay_ms(15);
	
	itoa(ref,pos,10);
	location(8,2);
	Send_A_String(pos);
	_delay_ms(15);
	
	itoa(neu,pos,10);
	location(13,2);
	Send_A_String(pos);
	_delay_ms(15);
}