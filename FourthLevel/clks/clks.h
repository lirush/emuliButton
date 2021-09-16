#ifndef _CLKS_H
#define _CLKS_H

#include <stdint.h>

void delay_us(uint32_t usec);

void delay_ms(uint32_t msec);

__inline__ uint8_t wait_us(uint32_t us) __attribute__((always_inline));

__inline__ uint8_t wait_ms(uint32_t ms) __attribute__((always_inline));

#endif
