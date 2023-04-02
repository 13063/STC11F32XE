#include <STC12C5A60S2.H>
#include "digital.h"

sbit S1=P3^4;
int count,cnt;

void Timer0_Init(void)		//20΢��@11.0592MHz
{
	AUXR |= 0x80;			//��ʱ��ʱ��1Tģʽ
	TMOD &= 0xF0;			//���ö�ʱ��ģʽ
	TL0 = 0x18;				//���ö�ʱ��ʼֵ
	TH0 = 0xF9;				//���ö�ʱ��ʼֵ
	TF0 = 0;				//���TF0��־
	ET0 = 1;				//ʹ�ܶ�ʱ��0�ж�
}

void main()
{
	Timer0_Init();
	EA=1;
	while(1)
	{
		if(S1==0)
		{
			TR0 = 1;				//��ʱ��0��ʼ��ʱ
		}
		displayNum(cnt,10);
	}
	
}

void Timer0_Isr(void) interrupt 1
{
	TL0 = 0x18;				//���ö�ʱ��ʼֵ
	TH0 = 0xF9;				//���ö�ʱ��ʼֵ
	TR0=0;
	if(count%1000==0)		//���ڶ�ʱ����20us�����ｫ��������20ms
	{
		if(S1==0)
		{
			cnt++;
			count=0;
			while(!S1)		//���ּ��
				displayNum(cnt,10);
		}
	}		
}
