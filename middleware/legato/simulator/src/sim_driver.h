#ifndef GFX_DRIVER_H
#define GFX_DRIVER_H

#include "gfx/legato/legato.h"

#define DRIVER_BUFFER_COUNT    SIM_DRIVER_BUFFER_COUNT
#define DRIVER_DISPLAY_WIDTH   SIM_DISPLAY_WIDTH
#define DRIVER_DISPLAY_HEIGHT  SIM_DISPLAY_HEIGHT
#define DRIVER_COLOR_MODE      SIM_COLOR_MODE

int32_t simDriver_Initialize(void);

leColorMode simDriver_GetColorMode(void);

uint32_t simDriver_GetBufferCount(void);

uint32_t simDriver_GetBufferWidth(void);

uint32_t simDriver_GetBufferHeight(void);

leResult simDriver_SetActiveLayer(uint32_t idx);

leResult simDriver_BlitBuffer(int32_t x,
                              int32_t y,
                              lePixelBuffer* buf);

void simDriver_Swap(void);

uint32_t simDriver_GetVSYNCCount(void);

void simDriver_Update(void);

#endif // GFX_DRIVER_H