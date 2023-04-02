#include <STC12C5A60S2.H>
sbit led1=P1^0;

unsigned int cnt;

void Timer0_Init(void)		//100΢��@11.0592MHz
{
	AUXR |= 0x80;			//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x01;			//���ö�ʱ��ģʽ
	TL0 = 0xAE;				//���ö�ʱ��ʼֵ
	TH0 = 0xFB;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
}

void main()
{
	EA=1;					//�����ж�
	ET0=1;					//������ʱ���ж�
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
	TL0 = 0xAE;				//���ö�ʱ��ʼֵ
	TH0 = 0xFB;				//���ö�ʱ��ʼֵ
	cnt++;

}
