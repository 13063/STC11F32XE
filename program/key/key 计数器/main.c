#include <STC12C5A60S2.H>
#include "digital.h"

sbit S1=P3^4;
int cnt;

void main()
{	
	TMOD &= 0xF0;
	TMOD |= 0x04;
	TL0=30;
	TH0=255;
	TF0=0;
	TR0=1;
	ET0=1;
	EA=1;
	while(1)
	{
		displayNum(cnt,10);
	}	
}

void Timer0_Isr(void) interrupt 1
{
	TL0=30;
	TH0=255;
	cnt++;
}