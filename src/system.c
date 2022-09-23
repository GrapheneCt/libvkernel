#include "vnz/common.h"

unsigned long long vnzSystemGetTimeWide()
{
	volatile unsigned long long *timer = 0xE20B6000;
	return *timer;
}

unsigned int vnzSystemGetTimeLow()
{
	volatile unsigned int *timer = 0xE20B6000;
	return *timer;
}

void vnzSystemDelay(unsigned long long usec)
{
	volatile unsigned long long *timer = 0xE20B6000;
	unsigned long long start = *timer;
	unsigned long long elapsed;

	do
	{
		elapsed = *timer - start;
	} while (elapsed < usec);
}

int vnzSystemGetCoreNum()
{
	register int idreg __asm("id");
	return (idreg >> 0x10) - 48;
}
