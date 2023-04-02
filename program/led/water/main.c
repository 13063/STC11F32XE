#include <STC12C5A60S2.H>

void Delay500ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 22;
	j = 3;
	k = 227;
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
	char i;
	while(1)
	{
		P1=0x01;
		for(i=0;i<8;i++)
		{
			P1=P1<<1;
			if(P1==0x00)
			P1=0x01;
			Delay500ms();
		}		
	}	
}
