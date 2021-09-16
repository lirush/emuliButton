#include "clks\clks.h"
#include "systick.h"

void delay_us(uint32_t usec) 
{
	uint32_t usec_mul=usec*12;
	__asm("MOV R0, usec_mul\n\t"
				"loop:SUBS R0, #1\n\t"
				"BNE loop\n\t"
	);
}

void delay_ms(uint32_t msec) 
{
	while(msec--)
	{
		delay_us(1000);
	}
}

uint8_t wait_us(uint32_t us)
{
	delay_us(us);
	return 1;

}

uint8_t wait_ms(uint32_t ms)
{
	delay_ms(ms);
	return 1;
}
