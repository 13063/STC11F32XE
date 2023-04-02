#include <STC12C5A60S2.H>
#include "digital.h"

sbit S1=P3^4;
int count,cnt;

void Timer0_Init(void)		//20微秒@11.0592MHz
{
	AUXR |= 0x80;			//定时器时钟1T模式
	TMOD &= 0xF0;			//设置定时器模式
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xF9;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	ET0 = 1;				//使能定时器0中断
}

void main()
{
	Timer0_Init();
	EA=1;
	while(1)
	{
		if(S1==0)
		{
			TR0 = 1;				//定时器0开始计时
		}
		displayNum(cnt,10);
	}
	
}

void Timer0_Isr(void) interrupt 1
{
	TL0 = 0x18;				//设置定时初始值
	TH0 = 0xF9;				//设置定时初始值
	TR0=0;
	if(count%1000==0)		//由于定时器是20us，这里将其扩大至20ms
	{
		if(S1==0)
		{
			cnt++;
			count=0;
			while(!S1)		//松手检测
				displayNum(cnt,10);
		}
	}		
}
