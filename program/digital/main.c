#include <STC12C5A60S2.H>
#include "digital.h"

void main()
{
	while(1)
	{
		display(1,7);
		display(2,5);
		display(3,9);
		displayNum(56,10);
	}
}