#include <STC12C5A60S2.H>
sbit led1=P1^0;
sbit led2=P1^1;
unsigned int cnt0,cnt1;


void Timer0_Init(void)		//22微秒@11.0592MHz
{
	AUXR |= 0x80;			//定时器时钟1T模式
	TMOD &= 0xF0;			//设置定时器模式
	TMOD |= 0x03;			//设置定时器模式
	TL0 = 0x0D;				//设置定时初始值
	TH0 = 0x86;				//11us
	TF0 = 0;				//清除TF0标志
	TR0 = 1;				//定时器0开始计时
	ET0 = 1;				//使能定时器0中断
}

void main()
{
	EA=1;					//开启中断
	ET1=1;					//开启定时器1中断
	TR1=1;					//开启定时器1
	/*需要注意的是，此处定时器0工作模式为3，TH的8位定时器占用了定时器 1的TR与TF*/
	Timer0_Init();
	while(1)
	{
		if(TF0==1)
		{
			TF0=0;
			TL0 = 0x0D;
			cnt0++;
		}
		if(TF1==1)
		{
			TF1=0;
			TH0 = 0x86;
			cnt1++;
		}
		if(cnt0==45454)
		{
			led1=~led1;
			cnt0=0;
		}
		if(cnt1==22727)
		{
			led2=~led2;
			cnt1=0;
		}
	}
}