#include <STC12C5A60S2.H>
sbit led1=P1^0;

unsigned int cnt;

void Timer0_Init(void)		//100微秒@11.0592MHz
{
	AUXR |= 0x80;			//定时器时钟1T模式
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x01;			//设置定时器模式
	TL0 = 0xAE;				//设置定时初始值
	TH0 = 0xFB;				//设置定时初始值
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
}

void main()
{
	EA=1;					//开启中断
	ET0=1;					//开启定时器中断
	Timer0_Init();
	while(1)
	{
		if(cnt==10000)
		{
			led1=~led1;
			cnt=0;
		}	
	}
}


void Timer0_Isr(void) interrupt 1
{
	TL0 = 0xAE;				//设置定时初始值
	TH0 = 0xFB;				//设置定时初始值
	cnt++;

}
