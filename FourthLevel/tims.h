#ifndef _TIMS_H
#define _TIMS_H

#include "MDR32Fx.h"

//extern uint8_t fall_signal;
//extern uint8_t raise_signal;
extern volatile uint16_t timeslots;
//extern volatile double scale_fall;
//extern volatile double scale_raise;
//extern volatile uint8_t x_bool[8];
//extern volatile double x_time[8];
//extern volatile uint8_t frame_full;
//extern volatile double frame;
//extern volatile uint8_t index_table;
//extern uint16_t frame_table[18];

void xTimer1Init(void);
void xTimer2Init(void);
//void xSetPoint(double point);

#endif
