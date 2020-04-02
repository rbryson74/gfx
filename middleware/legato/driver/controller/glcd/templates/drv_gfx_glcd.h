// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2020 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/
// DOM-IGNORE-END

/*******************************************************************************
  GFX GLCD Driver Interface Declarations for Static Single Instance Driver

  Company:
    Microchip Technology Inc.

  File Name:
    drv_gfx_glcd_static.h

  Summary:
    GFX GLCD driver interface declarations for the static single instance driver.

  Description:
    The GLCD device driver provides a simple interface to manage the GLCD
    module on Microchip microcontrollers. This file defines the interface
    Declarations for the GLCD driver.

  Remarks:
    Static interfaces incorporate the driver instance number within the names
    of the routines, eliminating the need for an object ID or object handle.

    Static single-open interfaces also eliminate the need for the open handle.
*******************************************************************************/


#ifndef _DRV_GFX_GLCD_H
#define _DRV_GFX_GLCD_H


// *****************************************************************************
// *****************************************************************************
// Section: File includes
// *****************************************************************************
// *****************************************************************************
/* Note:  A file that maps the interface definitions above to appropriate static
          implementations (depending on build mode) is included at the bottom of
          this file.
*/

#include "gfx/driver/controller/glcd/plib_glcd.h"
#include "gfx/driver/gfx_driver.h"

#ifdef __cplusplus
    extern "C" {
#endif
        
// *****************************************************************************
// *****************************************************************************
// Section: Functions
// *****************************************************************************
// *****************************************************************************
void DRV_GLCD_Initialize(void);

gfxColorMode DRV_GLCD_GetColorMode(void);
uint32_t DRV_GLCD_GetBufferCount(void);
uint32_t DRV_GLCD_GetDisplayWidth(void);
uint32_t DRV_GLCD_GetDisplayHeight(void);
void DRV_GLCD_Update(void);
uint32_t DRV_GLCD_GetLayerCount();
uint32_t DRV_GLCD_GetActiveLayer();
gfxResult DRV_GLCD_SetActiveLayer(uint32_t idx);
gfxResult DRV_GLCD_BlitBuffer(int32_t x, int32_t y, gfxPixelBuffer* buf, gfxBlend blend);
void DRV_GLCD_Swap(void);
uint32_t DRV_GLCD_GetVSYNCCount(void);
gfxPixelBuffer * DRV_GLCD_GetFrameBuffer(int32_t idx);
void DRV_GLCD_SetUseGPU(gfxBool onOff);
gfxResult DRV_GLCD_CtrlrConfig(ctlrCfg request, void * arg);

static const gfxDisplayDriver glcdDisplayDriver =
{
    DRV_GLCD_GetColorMode,
    DRV_GLCD_GetBufferCount,
    DRV_GLCD_GetDisplayWidth,
    DRV_GLCD_GetDisplayHeight,
    DRV_GLCD_Update,
    DRV_GLCD_GetLayerCount,
    DRV_GLCD_GetActiveLayer,
    DRV_GLCD_SetActiveLayer,
    DRV_GLCD_BlitBuffer,
    DRV_GLCD_Swap,
    DRV_GLCD_GetVSYNCCount,
    DRV_GLCD_GetFrameBuffer,
    DRV_GLCD_CtrlrConfig
};

#ifdef __cplusplus
    }
#endif
    
#endif // #ifndef _DRV_GFX_GLCD_H
/*******************************************************************************
 End of File
*/
