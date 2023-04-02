#include <STC12C5A60S2.H>
#include "digital.h"

sbit S1=P3^4;
int cnt;

void main()
{
	while(1)
	{
		if(S1==0)
		{
			delay(20);
			if(S1==0)
				cnt++;
			while(!S1)
				displayNum(cnt,10);
		}
		displayNum(cnt,10);
	}
	
}