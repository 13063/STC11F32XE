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
	ET0 = 1;				//ʹ�ܶ�ʱ��0�ж�
}

void main()
{
	EA=1;					//�����ж�
	ET0=1;					//������ʱ���ж�
	Timer0_Init();
	while(1)
	{
		if(cnt==45454)
		{
			led1=~led1;
			cnt=0;
		}
	}
}


void Timer0_Isr(void) interrupt 1
{
	cnt++;
}
