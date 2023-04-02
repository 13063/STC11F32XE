#include <digital.h>
#define SCAN_TIME 1

extern unsigned char code table[]={
	0x3F,  //"0"
    0x06,  //"1"
    0x5B,  //"2"
    0x4F,  //"3"
    0x66,  //"4"
    0x6D,  //"5"
    0x7D,  //"6"
    0x07,  //"7"
    0x7F,  //"8"
    0x6F,  //"9"
    0x77,  //"A"
    0x7C,  //"B"
    0x39,  //"C"
    0x5E,  //"D"
    0x79,  //"E"
    0x71,  //"F"
    0x76,  //"H"
    0x38,  //"L"
    0x37,  //"n"
    0x3E,  //"u"
    0x73,  //"P"
    0x5C,  //"o"
    0x40,  //"-"
    0x00  //熄灭
};
void delay(unsigned int t)		//@11.0592MHz
{
	while(t--)
	{
		unsigned char i, j;

		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} 	while (--i);
	}	
}

void display(unsigned char pos,unsigned char num)
{
	switch (6-pos)
	{
		case 0:
		{
			P0=0x1f;
			selCon=1;
			selCon=0;
			break;
		}
		case 1:
		{
			P0=0x2f;
			selCon=1;
			selCon=0;
			break;
		}
		case 2:
		{
			P0=0x37;
			selCon=1;
			selCon=0;
			break;
		}
		case 3:
		{
			P0=0x3b;
			selCon=1;
			selCon=0;
			break;
		}
		case 4:
		{
			P0=0x3d;
			selCon=1;
			selCon=0;
			break;
		}
		case 5:
		{
			P0=0x3e;
			selCon=1;
			selCon=0;
			break;
		}
	}
	P0=table[num];
	datCon=1;
	datCon=0;
	
	delay(SCAN_TIME);
}
void displayNum(long int number,unsigned char mode)		//mode代表进制
{
	if(number>=0)
	{
		unsigned long int f=1;
		unsigned long int i=1;
		unsigned char len=0;

		if(number==0)
			len=1;
		while((number/f)!=0)
		{
			f=f*mode;
			len++;
		}
		for(f=1;f<=6;f++)
		{
			if(f<=len)
			{
				display(7-f,(number/i)%mode);
				i=i*mode;
			}
			else
				display(7-f,23);
		}
	}
	else
	{
		unsigned long int f=1;
		unsigned long int i=1;
		unsigned char len=0;
		while(((0-number)/f)!=0)
		{
			f=f*mode;
			len++;
		}
		for(f=1;f<=6;f++)
		{
			if(f<=len)
			{
				display(7-f,((0-number)/i)%mode);
				i=i*mode;
			}
			else
				display(8-f,23);	
		}
		display(6-len,22);
	}
}