#ifndef UART_H
#define UART_H
#include "public.h"
#include "stdio.h"

void UART_SendByte(uchar byte);
void UART_SendString(uchar* str);
void UartInit(void);		//9600bps@11.0592MHz
#endif