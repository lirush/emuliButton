#ifndef __SYSTICK_H_
#define __SYSTICK_H_

#include <MDR32Fx.h>

extern uint32_t Ticks;

// System timer control
void SysTickStart(uint32_t ticks);
void SysTickStartNoIE(uint32_t ticks);
void SysTickStop(void);


#endif // __SYSTICK_H_
