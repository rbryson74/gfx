#include "sim_legato.h"
#include "sim_driver.h"
#include "sim_extmem.h"
#include "sim_memory.h"
#include "sim_time.h"
#include "sim_touch.h"

#include "gfx/legato/legato.h"

struct leDisplayDriver driver;

int32_t sim_shouldRun = 1;

void run_Legato()
{
    driver.getColorMode = simDriver_GetColorMode;
    driver.getBufferCount = simDriver_GetBufferCount;
    driver.getDisplayWidth = simDriver_GetBufferWidth;
    driver.getDisplayHeight = simDriver_GetBufferHeight;
    driver.blitBuffer = simDriver_BlitBuffer;
    driver.update = simDriver_Update;
    driver.setActiveLayer = simDriver_SetActiveLayer;
    driver.swap = simDriver_Swap;
    driver.getVSYNCCount = simDriver_GetVSYNCCount;
    
    if(simDriver_Initialize() != 0)
    {
        return;
    }
    
	// initialize hardware layer
	if(leInitialize(&driver) == LE_FAILURE)
	{
		return;
	}

	SYS_Initialize();

    APP_Initialize();

	//Touch_CallbackSet(&touchEventCallback);
	    
	while(sim_shouldRun)
    {
        sim_TimeUpdate();
        
#if LE_STREAMING_ENABLED == 1
        sim_ExtMemUpdate();
#endif

        simDriver_Update();

        //ticks += sim_TimeTicks();
            
        //if(ticks >= 1)
        //{
            //printf("ticks: %u\n", ticks);

            SYS_Tasks();


            
            APP_Tasks();
        //}
    }
}