#include "public.h"

void delay(uint c)   //Îó²î 0us
{
    uchar a,b;
	for (; c>0; c--)
	{
		 unsigned char i, j;

		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);   
	}	
}

