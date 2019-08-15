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

leImage* resizedImage;

void APP_Initialize()
{
    leRect rect, destRect;
    rect.x = 16;
    rect.y = 0;
    rect.width = 16;
    rect.height = 32;

    destRect.x = 0;
    destRect.y = 0;
    destRect.width = 64;
    destRect.height = 64;

    resizedImage = leImage_Allocate(32, 32, LE_COLOR_MODE_RGB_565);

    /*leImage_ResizeDraw(&mchpLogo_mask,
                       &rect,
                       LE_IMAGEFILTER_BILINEAR,
                       64,
                       64,
                       0,
                       0);*/

    /*leImage_Copy(&mchpLogo_mask,
                 &rect,
                 0,
                 0,
                 resizedImage);*/

    leImage_Render(&mchpLogo_mask,
                   &rect,
                   0,
                   0,
                   LE_FALSE,
                   LE_FALSE,
                   resizedImage);

    ImageWidget1->fn->setImage(ImageWidget1, resizedImage);
//#endif
}

void APP_Tasks()
{

}
