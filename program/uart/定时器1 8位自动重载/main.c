#include <STC12C5A60S2.H>
#include "public.h"
#include "uart.h"


#define BUFFER_LEN 200

sbit led1=P1^0;

uchar rx_buffer[BUFFER_LEN];
uchar tx_buffer[BUFFER_LEN];


void main()
{
	uchar i;
	UartInit();
	EA=1;
	ES=1;
	for(i=0;i<BUFFER_LEN-1;i++)
		rx_buffer[i]='P';
	rx_buffer[BUFFER_LEN-1]='\0';
	while(1)
	{
//		UART_SendString(rx_buffer);
//		UART_SendString("\r\n");
		printf(rx_buffer);
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