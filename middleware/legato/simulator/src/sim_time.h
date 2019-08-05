#ifndef SIM_TIME_H
#define SIM_TIME_H

#include "gfx/legato/legato.h"

void     sim_TimeInit();
void     sim_TimeUpdate();
uint32_t sim_TimeTotal();
void     sim_TimeSleep(uint32_t ms);
double   sim_TimeDelta();

#endif // SIM_TIME_H