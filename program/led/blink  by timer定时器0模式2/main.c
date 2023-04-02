#include <STC12C5A60S2.H>
sbit led1=P1^0;

unsigned int cnt;

void Timer0_Init(void)		//22微秒@11.0592MHz
{
	AUXR |= 0x80;			//定时器时钟1T模式
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x02;			//设置定时器模式
	TL0 = 0x0D;				//设置定时初始值
	TH0 = 0x0D;				//设置定时重载值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
}


void main()
{
	Timer0_Init();
	while(1)
	{
		if(TF0==1)
		{
			cnt++;
			TF0=0;
		}
		if(cnt==45454)
		{
			led1=~led1;
			cnt=0;
		}
		
	}
}
