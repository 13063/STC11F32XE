#include "uart.h"


void UART_SendByte(uchar byte)
{
	SBUF=byte;
	while(TI==0);
	TI=0;
}

void UART_SendString(uchar* str)
{
	while(*str)
	{
		UART_SendByte(*str++);
	}
}

//void UartInit(void)		//9600bps@11.0592MHz
//{
//	PCON &= 0x7F;		//�����ʲ�����
//	SCON = 0x50;		//8λ����,�ɱ䲨����
//	AUXR |= 0x04;		//��ʱ��ʱ��1Tģʽ
//	BRT = 0xDC;			//���ö�ʱ����ֵ
//	AUXR |= 0x01;		//����1ʹ�ö��������ʷ�����Ϊ�����ʷ�����
//	AUXR |= 0x10;		//�������������ʷ�����
//}
void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//�����ʲ�����
	SCON = 0x50;		//8λ����,�ɱ䲨����
	AUXR |= 0x40;		//��ʱ��ʱ��1Tģʽ
	AUXR &= 0xFE;		//����1ѡ��ʱ��1Ϊ�����ʷ�����
	TMOD &= 0x0F;		//���ö�ʱ��ģʽ
	TMOD |= 0x20;		//���ö�ʱ��ģʽ
	TL1 = 0xDC;			//���ö�ʱ��ʼֵ
	TH1 = 0xDC;			//���ö�ʱ����ֵ
	ET1 = 0;			//��ֹ��ʱ���ж�
	TR1 = 1;			//��ʱ��1��ʼ��ʱ
}

char putchar(char c){
	UART_SendByte(c);
	return c; 
}
