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

#if LE_ASSET_STREAMING_ENABLED == 1
leResult leApplication_MediaOpenRequest(leAssetStreamReader* rdr)
{
    return LE_SUCCESS;
}

leResult leApplication_MediaReadRequest(leAssetStreamReader* rdr,
                                        void* address,
                                        uint32_t size,
                                        uint8_t* buffer)
{
    uint32_t addr;

    if(rdr->asset == (leAssetHeader*)&mchpLogo_mask)
    {
        //addr = (uint32_t)address - (uint32_t)mchpLogo_mask.header.dataAddress;
        //addr += (uint32_t)address;

        memcpy(buffer, (uint8_t*)address, size);

        rdr->dataReady(rdr);
    }
    /*else if(rdr->asset == (leAssetHeader*)&leGenPalette0)
    {
        memcpy(buffer, (uint8_t*)address, size);

        rdr->dataReady(rdr);
    }*/

    return LE_SUCCESS;
}

void leApplication_MediaCloseRequest(leAssetStreamReader* rdr)
{

}
#endif