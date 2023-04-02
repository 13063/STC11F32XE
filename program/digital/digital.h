#include <STC12C5A60S2.H>
#include "intrins.h"
#ifndef DIGITAL_H
#define DIGITAL_H

sbit selCon=P2^7;
sbit datCon=P2^6;

void display(unsigned char pos,unsigned char num);		//最左边对应位1，最右边对应位6
void displayNum(long int num,unsigned char mode);		//mode代表进制

#endif
