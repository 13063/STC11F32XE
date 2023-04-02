#include <STC12C5A60S2.H>
#include "public.h"
#include "uart.h"
sbit led1=P1^0;

uchar rx_buffer[100];
uchar tx_buffer[100];




void main()
{
	UartInit();
	EA=1;
	ES=1;
	while(1)
	{
		UART_SendString("hello world\r\n");
		delay(200);
	}
}

void Uart_Isr() interrupt 4 
{
	if (RI==1)
	{
		led1=~led1;
		RI=0;
	}
}