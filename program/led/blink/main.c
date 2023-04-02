#include <STC12C5A60S2.H>
sbit led1=P1^0;

void Delay300ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 13;
	j = 156;
	k = 83;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	while(1)
	{
		led1=~led1;
		Delay300ms();
		
	}
}