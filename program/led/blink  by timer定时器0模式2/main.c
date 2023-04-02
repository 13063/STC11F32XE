#include <STC12C5A60S2.H>
sbit led1=P1^0;

unsigned int cnt;

void Timer0_Init(void)		//22΢��@11.0592MHz
{
	AUXR |= 0x80;			//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x02;			//���ö�ʱ��ģʽ
	TL0 = 0x0D;				//���ö�ʱ��ʼֵ
	TH0 = 0x0D;				//���ö�ʱ����ֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
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
