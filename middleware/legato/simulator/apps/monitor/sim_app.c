#include "sim_time.h"

#include "gfx/legato/legato.h"
#include "gfx/legato/generated/le_gen_init.h"
#include "gfx/legato/renderer/legato_renderer.h"

#include <stdio.h>
#include <string.h>

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

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
