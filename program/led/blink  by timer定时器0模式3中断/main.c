#include <STC12C5A60S2.H>
sbit led1=P1^0;
sbit led2=P1^1;
unsigned int cnt0,cnt1;


void Timer0_Init(void)		//22΢��@11.0592MHz
{
	AUXR |= 0x80;			//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TMOD |= 0x03;			//���ö�ʱ��ģʽ
	TL0 = 0x0D;				//���ö�ʱ��ʼֵ
	TH0 = 0x86;				//11us
	TF0 = 0;				//���TF0��־
	TR0 = 1;				//��ʱ��0��ʼ��ʱ
	ET0 = 1;				//ʹ�ܶ�ʱ��0�ж�
}

void main()
{
	EA=1;					//�����ж�
	ET1=1;					//������ʱ��1�ж�
	TR1=1;					//������ʱ��1
	/*��Ҫע����ǣ��˴���ʱ��0����ģʽΪ3��TH��8λ��ʱ��ռ���˶�ʱ�� 1��TR��TF*/
	Timer0_Init();
	while(1)
	{
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
void Timer0_Isr(void) interrupt 1
{
	TL0 = 0x0D;
	cnt0++;
}
void Timer1_Isr(void) interrupt 3
{
	TH0 = 0x86;
	cnt1++;
}