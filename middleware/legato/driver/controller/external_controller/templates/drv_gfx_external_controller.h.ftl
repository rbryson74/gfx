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

/*******************************************************************************
  MPLAB Harmony Generated Driver Header File

  File Name:
    drv_gfx_custom_external.h

  Summary:
    Build-time generated header file for ${ControllerName} driver.
	
  Description:
    Build-time generated header file for top-level ${ControllerName} driver.
 * 
    Created with MPLAB Harmony Version 3.00
*******************************************************************************/

/** \file drv_gfx_external_controller_ftl.h
 * @brief External Controller driver functions and definitions.
 *
 * @details This header file contains the function prototypes and definitions
 * of the data types and constants that make up the interface to the External
 * Controller Graphics Controller.
 *
 * This driver files are configured via MHC and generated specific to the configuration
 * and hardware architecture set in MHC.
 * @see LE External Controller component
 */

#ifndef DRV_GFX_${ControllerName}_H
#define DRV_GFX_${ControllerName}_H

#include "gfx/driver/gfx_driver.h"

#ifdef __cplusplus
    extern "C" {
#endif
 
/**
 * @brief Initialize driver.
 * @details Initializes the External Controller driver. This routine is typically called
 * by a graphics library or by the application during application initialization.
 * @code
 * gfxResult res = DRV_<em>controller</em>_Initialize();
 * @endcode
 * @return GFX_SUCCESS if driver ready to render, otherwise GFX_FAILURE.
 */
int DRV_${ControllerName}_Initialize(void);

/**
 * @brief Execute update task.
 * @details Performs a driver task update.
 * @code
 * DRV_<em>controller</em>_Update();
 * @endcode
 * @return void.
 */
void DRV_${ControllerName}_Update(void);

<#if PassiveDriver == false>
/**
 * @brief Get color mode.
 * @details Returns the current color mode.
 * @code
 * gfxDisplayDriver*  drv;
 * gfxColorMode mode = drv->getColorMode();
 * @endcode
 * @return RGB color mode.
 */
gfxColorMode DRV_${ControllerName}_GetColorMode(void);

/**
 * @brief Get buffer count.
 * @details Returns the number of configured buffers. In a single buffer system
 * count will be 1. In a double buffered system, the count would be at least 2.
 * @code
 * gfxDisplayDriver*  drv;
 * uint32_t cnt = drv->getBufferCount();
 * @endcode
 * @return number of configured buffers.
 */
uint32_t DRV_${ControllerName}_GetBufferCount(void);

/**
 * @brief Get display width.
 * @details Returns the max number of horizontal pixels. This is the horizonal portion
 * of the screen resolution.
 * @see DRV_LCC_GetDisplayHeight()
 * @code
 * gfxDisplayDriver*  drv;
 * uint32_t width = drv->getDisplayWidth();
 * @endcode
 * @return horizontal display width.
 */
uint32_t DRV_${ControllerName}_GetDisplayWidth(void);

/**
 * @brief Get display height.
 * @details Returns the max number vertical pixels. This is the vertical portion
 * of the screen resolution.
 * @see DRV_LCC_GetDisplayWidth()
 * @code
 * gfxDisplayDriver*  drv;
 * uint32_t width = drv->getDisplayHeight();
 * @endcode
 * @return vertical display height.
 */
uint32_t DRV_${ControllerName}_GetDisplayHeight(void);

/**
 * @brief Get layer count.
 * @details Returns the number of display layers configured.
 * @code
 * gfxDisplayDriver*  drv;
 * uint32_t cnt = drv->getLayerCount();
 * @endcode
 * @return number of display layers.
 */
uint32_t DRV_${ControllerName}_GetLayerCount();

/**
 * @brief Get active layer.
 * @details Returns the index of the active layer.
 * @code
 * gfxDisplayDriver*  drv;
 * uint32_t layer = drv->getActiveLayer();
 * @endcode
 * @return layer index.
 */
uint32_t DRV_${ControllerName}_GetActiveLayer();

/**
 * @brief Set active layer.
 * @details Sets active the layer at <span style="color: #820a32"><em>idx</em></span> position.
 * @code
 * gfxDisplayDriver* drv;
 * uint32_t idx;
 * gfxResult res = drv->setActiveLayer(idx);
 * @endcode
 * @return GFX_SUCCESS if layer at idx is active, otherwise GFX_FAILURE.
 */
gfxResult DRV_${ControllerName}_SetActiveLayer(uint32_t idx);

/**
 * @brief Gets the state for a hardware layer.
 * @details Gets the state of layer <span style="color: #820a32"><em>idx</em></span> .
 * @code
 * gfxDisplayDriver* drv;
 * uint32_t idx;
 * gfxLayerState state = drv->getLayerState(idx);
 * @endcode
 * @return The state of the layer.
 */
gfxLayerState DRV_${ControllerName}_GetLayerState(uint32_t idx);

/**
 * @brief Blit buffer.
 * @details Copies <span style="color: #820a32"><em>buf</em></span>
 * to the framebuffer at location <span style="color: #820a32"><em>x</em></span> and
 * <span style="color: #820a32"><em>y</em></span>.
 * @code
 * gfxDisplayDriver* drv;
 * gfxResult res = drv->blitBuffer();
 * @endcode
 * @return GFX_SUCCESS if blit was performed, otherwise GFX_FAILURE.
 */
gfxResult DRV_${ControllerName}_BlitBuffer(int32_t x, int32_t y, gfxPixelBuffer* buf);

/**
 * @brief Swap buffer.
 * @details Swaps the rendering buffer with the display buffer. The display buffer now
 * becomes the rendering buffer. Swapping support double buffering technology.
 * @code
 * gfxDisplayDriver* drv;
 * drv->swap();
 * @endcode
 * @return void.
 */
void DRV_${ControllerName}_Swap(void);

/**
 * @brief Get VSYNC count.
 * @details Returns the vertical pulse count. This can be used
 * as an interrupt to indicate the end of a frame or start of a new frame.
 * This value can also be used to do frame rate calculations.
 * @code
 * gfxDisplayDriver* drv;
 * drv->getVSYNCCount();
 * @endcode
 * @return VSYNC count.
 */
uint32_t DRV_${ControllerName}_GetSwapCount(void);

/**
 * @brief Set global palette.
 * @details Sets the global palette for the driver.  Used for blitting color map buffers.
 * @code
 * gfxDisplayDriver* drv;
 * gfxResult res = drv->setPalette(addr, colorMode, colorCount);
 * @endcode
 * @return GFX_SUCCESS if the palette was successfully set, otherwise GFX_FAILURE.
 */
gfxResult DRV_${ControllerName}_SetPalette(gfxBuffer* palette,
                                           gfxColorMode mode,
                                           uint32_t colorCount);

/**
 * @brief Defines the External Controller interface functions.
 * @details Establishes the driver abstract interface functions between the driver
 * and client. The client is either a graphics library middleware or application which
 * interfaces with the driver through these functions.
 */
static const gfxDisplayDriver gfxDriverInterface =
{
    DRV_${ControllerName}_GetColorMode,         /**< implements getColorMode */
    DRV_${ControllerName}_GetBufferCount,       /**< implements getBufferCount */
    DRV_${ControllerName}_GetDisplayWidth,      /**< implements getDisplayWidth */
    DRV_${ControllerName}_GetDisplayHeight,     /**< implements getDisplayHeight */
    DRV_${ControllerName}_Update,               /**< implements update */
    DRV_${ControllerName}_GetLayerCount,        /**< implements layerCount */
    DRV_${ControllerName}_GetActiveLayer,       /**< implements activeLayer */
    DRV_${ControllerName}_SetActiveLayer,       /**< implements setActive */
    DRV_${ControllerName}_GetLayerState,        /**< implements getLayerState */
    DRV_${ControllerName}_BlitBuffer,           /**< implements blitbuffer */
    DRV_${ControllerName}_Swap,                 /**< implements swap. */
    DRV_${ControllerName}_GetSwapCount,         /**< implements getVSYNCCount */
    NULL,                                       /**< nop getframebuffer */
    DRV_${ControllerName}_SetPalette,           /**< implements setPalette */
    NULL                                        /**< nop ctrlConfig */
};
</#if>

#ifdef __cplusplus
    }
#endif
    
#endif // DRV_GFX_${ControllerName}_H
