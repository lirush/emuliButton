#ifndef EIBUTTON_H
#define EIBUTTON_H

#include "MDR32Fx.h"

#ifdef	REGULAR_SPEED
#		define MIN_RESET	(480)
#		define MAX_RESET	(520)
#else
#		define MIN_RESET	(390)
#		define MAX_RESET	(520)
#endif


void xSetPoint(double point);

#endif
