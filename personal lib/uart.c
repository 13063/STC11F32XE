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
//	PCON &= 0x7F;		//波特率不倍速
//	SCON = 0x50;		//8位数据,可变波特率
//	AUXR |= 0x04;		//定时器时钟1T模式
//	BRT = 0xDC;			//设置定时重载值
//	AUXR |= 0x01;		//串口1使用独立波特率发射器为波特率发生器
//	AUXR |= 0x10;		//启动独立波特率发射器
//}
void UartInit(void)		//9600bps@11.0592MHz
{
	PCON &= 0x7F;		//波特率不倍速
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器时钟1T模式
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设置定时器模式
	TMOD |= 0x20;		//设置定时器模式
	TL1 = 0xDC;			//设置定时初始值
	TH1 = 0xDC;			//设置定时重载值
	ET1 = 0;			//禁止定时器中断
	TR1 = 1;			//定时器1开始计时
}

char putchar(char c){
	UART_SendByte(c);
	return c; 
}
