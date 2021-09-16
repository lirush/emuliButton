#include "systick.h"

volatile uint32_t TimingDelay_ms;
uint32_t Ticks=0;

void SysTickStart(uint32_t ticks)
{
  SysTick->LOAD = ticks;
  SysTick->CTRL = SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk | SysTick_CTRL_TICKINT_Msk;
}

void SysTickStartNoIE(uint32_t ticks)
{
  SysTick->LOAD = ticks;
  SysTick->CTRL = SysTick_CTRL_ENABLE_Msk | SysTick_CTRL_CLKSOURCE_Msk;	
}

void SysTickStop(void)
{
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}

void SysTick_Handler(void)
{
  if (TimingDelay_ms > 0x00)
  {
    TimingDelay_ms--;
  }
	Ticks++;
}
