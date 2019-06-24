#include "sim_time.h"

#include <stdio.h>
#include <string.h>

#include "gfx/legato/generated/le_gen_init.h"

static uint32_t ticks;

void SYS_Initialize()
{
    legato_initialize();

    ticks = sim_TimeTotal();
}

void SYS_Tasks()
{
    uint32_t currentTicks = sim_TimeTotal() - ticks;

    if(currentTicks > 0)
    {
        ticks = sim_TimeTotal();

        leUpdate(currentTicks);

        legato_updateCurrentScreen();
    }
}

void APP_Initialize()
{

}

void APP_Tasks()
{

}
