/*******************************************************************************
  MPLAB Harmony Nano2D Generated HAL Wrapper

  File Name:
    libnano2D_hal.c

  Summary:
    Build-time generated implementation for the Nano2D Generated HAL Wrapper.

  Description:
    Build-time generated implementation for the Nano2D Generated HAL Wrapper.

    Created with MPLAB Harmony Version 2.03
*******************************************************************************/
// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2017 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
// DOM-IGNORE-END

//#include "gfx/hal/inc/gfx_common.h"
//#include "gfx/hal/inc/gfx_processor_interface.h"
#include "gfx/driver/processor/2dgpu/libnano2D.h"

#include <xc.h>
#include <sys/attribs.h>
#include <sys/kmem.h>

const char* driverName = "Nano 2D";

#define CMD_BUFFER_SIZE  8192
uint32_t __attribute__((coherent, aligned(32))) commandBuffer[CMD_BUFFER_SIZE];

// GPU command buffer seems to work better when placed in DDR
#define CMD_BUFFER_DDR_ADDRESS 0xA9E00000

n2d_module_parameters_t gpu_params;
n2d_buffer_format_t gpu_format = N2D_RGB565;
n2d_buffer_format_t gpu_blend = N2D_BLEND_SRC_OVER;
n2d_orientation_t gpu_orientation = N2D_0;

gfxResult GFX_2DGPU_Line(const gfxPoint* p1,
                           const gfxPoint* p2,
                           const gfxRect* clipRect,
                           const gfxColor color,
                           gfxPixelBuffer * dest)
{
    n2d_buffer_t buffer;
    n2d_point_t np1, np2;

        // trivial cases that are better handled by the CPU
    if(p1->x == p2->x || p1->y == p2->y)
        return GFX_FAILURE;

    buffer.width = dest->size.width;
    buffer.height = dest->size.height;
    buffer.stride = dest->size.width * 2;//GFX_ColorInfo[state->colorMode].size;
    buffer.format = gpu_format;
    buffer.orientation = gpu_orientation;
    buffer.handle = NULL;
    buffer.memory = dest->pixels;
    buffer.gpu = KVA_TO_PA(dest->pixels);

    np1.x = p1->x;
    np1.y = p1->y;

    np2.x = p2->x;
    np2.y = p2->y;

    // compensate for missing last pixel
    if(np1.x == np2.x) // vertical line
    {
        if(np1.y < np2.y)
            np2.y++;
        else
            np1.y--;
    }

    if(np1.y == np2.y) // horizontal line
    {
        if(np1.x < np2.x)
            np2.x++;
        else
            np1.x--;
    }

    n2d_line(&buffer,
             np1,
             np2,
             (n2d_rectangle_t*)clipRect,
             gfxColorConvert(dest->mode, GFX_COLOR_MODE_ARGB_8888, color),
             N2D_BLEND_NONE);

    return GFX_SUCCESS;
}

gfxResult DRV_2DGPU_Fill(const gfxRect* rect,
                           const gfxRect* clipRect,
                           const gfxColor color,
                           gfxPixelBuffer * dest)
{
    n2d_buffer_t buffer;

    buffer.width = dest->size.width;
    buffer.height = dest->size.height;
    buffer.stride = dest->size.width * 2;//GFX_ColorInfo[state->colorMode].size;
    buffer.format = gpu_format;
    buffer.orientation = gpu_orientation;
    buffer.handle = NULL;
    buffer.memory = dest->pixels;
    buffer.gpu = KVA_TO_PA(dest->pixels);

    n2d_fill(&buffer,
             (n2d_rectangle_t*)clipRect,
             gfxColorConvert(dest->mode, GFX_COLOR_MODE_ARGB_8888, color),
             N2D_BLEND_NONE);

    return GFX_SUCCESS;
}

gfxResult DRV_2DGPU_Blit(const gfxPixelBuffer* source,
                           const gfxRect* srcRect,
                           const gfxPoint* drawPoint,
                           const gfxPixelBuffer* dest,
                           const gfxRect* destRect)
{
    n2d_buffer_t src_buffer, dest_buffer;
//    gfxRect dest_rect;
    n2d_blend_t blend = N2D_BLEND_NONE;

    // the source address must reside in KSEG1 (cache coherent) memory
    // and the source buffer must be raw pixels as the the GPU doesn't
    // understand palettized blits
    // if this fails then fall back to software mode
    if(IS_KVA1(source->pixels) == GFX_FALSE ||
       GFX_COLOR_MODE_IS_INDEX(source->mode) == GFX_TRUE ||
       GFX_COLOR_MODE_IS_INDEX(dest->mode) == GFX_TRUE ||
       gpu_format == -1 ||
       gpu_format == -1)
        return GFX_SUCCESS;

    // craft source buffer descriptor
    src_buffer.width = source->size.width;
    src_buffer.height = source->size.height;
    src_buffer.stride = source->size.width * 2;//GFX_ColorInfo[source->mode].size;
    src_buffer.format = gpu_format;
    src_buffer.orientation = gpu_orientation;
    src_buffer.handle = NULL;
    src_buffer.memory = source->pixels;
    src_buffer.gpu = KVA_TO_PA(source->pixels);

    // craft dest buffer descriptor
    dest_buffer.width = dest->size.width;
    dest_buffer.height = dest->size.height;
    dest_buffer.stride = dest->size.width * 2;//GFX_ColorInfo[state->colorMode].size;
    dest_buffer.format = gpu_format;
    dest_buffer.orientation = gpu_orientation;
    dest_buffer.handle = NULL;
    dest_buffer.memory = dest->pixels;
    dest_buffer.gpu = KVA_TO_PA(dest->pixels);

//    dest_rect.x = drawPoint->x;
//    dest_rect.y = drawPoint->y;
//    dest_rect.width = srcRect->width;
//    dest_rect.height = srcRect->height;

//    if(state->maskEnable == GFX_TRUE)
//    {
//        n2d_color_t color = (n2d_color_t)gfxColorConvert(state->colorMode, GFX_COLOR_MODE_ARGB_8888, state->maskValue);
//
//        n2d_draw_state(N2D_TRANSPARENCY_SOURCE,
//                       color,
//                       0xA,
//                       0xC);
//    }

//    if ((state->alphaEnable == GFX_TRUE) &&
//        ((state->blendMode & GFX_BLEND_CHANNEL) == 0))
//    {
//        n2d_set_global_alpha(N2D_GLOBAL_ALPHA_ON, N2D_GLOBAL_ALPHA_OFF, state->globalAlphaValue, 0xff);
//        blend = N2D_BLEND_SRC_OVER;
//    }

    n2d_blit(&dest_buffer,
             (n2d_rectangle_t*)&destRect,
             &src_buffer,
             (n2d_rectangle_t*)srcRect,
             blend);

//    if(state->maskEnable == GFX_TRUE)
//    {
//        n2d_draw_state(N2D_TRANSPARENCY_NONE, 0, 0xC, 0xC);
//    }
//
//    if ((state->alphaEnable == GFX_TRUE) &&
//        ((state->blendMode & GFX_BLEND_CHANNEL) == 0))
//    {
//        n2d_set_global_alpha(N2D_GLOBAL_ALPHA_OFF, N2D_GLOBAL_ALPHA_OFF, 0xff, 0xff);
//        blend = N2D_BLEND_NONE;
//    }

    return GFX_SUCCESS;
}

gfxResult GFX_2DGPU_BlitStretch(const gfxPixelBuffer* source,
                           const gfxRect* srcRect,
                           const gfxPixelBuffer* dest,
                           const gfxRect* destRect)
{
    n2d_buffer_t src_buffer, dest_buffer;
    n2d_blend_t blend = N2D_BLEND_NONE;

    // the source address must reside in KSEG1 (cache coherent) memory
    // and the source buffer must be raw pixels as the the GPU doesn't
    // understand palettized blits
    // if this fails then fall back to software mode
    if(IS_KVA1(source->pixels) == GFX_FALSE ||
       GFX_COLOR_MODE_IS_INDEX(source->mode) == GFX_TRUE ||
       GFX_COLOR_MODE_IS_INDEX(dest->mode) == GFX_TRUE ||
       gpu_format == -1 ||
       gpu_format == -1)
        return GFX_SUCCESS;

    // craft source buffer descriptor
    src_buffer.width = source->size.width;
    src_buffer.height = source->size.height;
    src_buffer.stride = source->size.width * 2;//GFX_ColorInfo[source->mode].size;
    src_buffer.format = gpu_format;
    src_buffer.orientation = gpu_orientation;
    src_buffer.handle = NULL;
    src_buffer.memory = source->pixels;
    src_buffer.gpu = KVA_TO_PA(source->pixels);

    // craft dest buffer descriptor
    dest_buffer.width = dest->size.width;
    dest_buffer.height = dest->size.height;
    dest_buffer.stride = dest->size.width * 2;//GFX_ColorInfo[state->colorMode].size;
    dest_buffer.format = gpu_format;
    dest_buffer.orientation = gpu_orientation;
    dest_buffer.handle = NULL;
    dest_buffer.memory = dest->pixels;
    dest_buffer.gpu = KVA_TO_PA(dest->pixels);

//    if(state->maskEnable == GFX_TRUE)
//    {
//        n2d_color_t color = (n2d_color_t)gfxColorConvert(state->colorMode, GFX_COLOR_MODE_ARGB_8888, state->maskValue);
//
//        n2d_draw_state(N2D_TRANSPARENCY_SOURCE,
//                       color,
//                       0xA,
//                       0xC);
//    }
//
//    if ((state->alphaEnable == GFX_TRUE) &&
//        ((state->blendMode & GFX_BLEND_CHANNEL) == 0))
//    {
//        n2d_set_global_alpha(N2D_GLOBAL_ALPHA_ON, N2D_GLOBAL_ALPHA_OFF, state->globalAlphaValue, 0xff);
//        blend = N2D_BLEND_SRC_OVER;
//    }

    n2d_blit(&dest_buffer,
             (n2d_rectangle_t*)destRect,
             &src_buffer,
             (n2d_rectangle_t*)srcRect,
             blend);

//    if(state->maskEnable == GFX_TRUE)
//    {
//        n2d_draw_state(N2D_TRANSPARENCY_NONE, 0, 0xC, 0xC);
//    }
//
//    if ((state->alphaEnable == GFX_TRUE) &&
//        ((state->blendMode & GFX_BLEND_CHANNEL) == 0))
//    {
//        n2d_set_global_alpha(N2D_GLOBAL_ALPHA_OFF, N2D_GLOBAL_ALPHA_OFF, 0xff, 0xff);
//        blend = N2D_BLEND_NONE;
//    }

    return GFX_SUCCESS;
}

//// function that returns the information for this driver
//gfxResult procNANO2DInfoGet(GFX_ProcessorInfo* info)
//{
//	if(info == NULL)
//        return GFX_FAILURE;
//
//	// populate info struct
//    strcpy(info->name, driverName);
//    info->color_formats = GFX_COLOR_MASK_ARGB_8888;
//
//    return GFX_SUCCESS;
//}

// function that initialized the driver context
void DRV_2DGPU_Initialize(void)
{
    /* initialize gpu hardware and peripheral software */
    memset((void*)commandBuffer, 0, CMD_BUFFER_SIZE);

    gpu_params.contiguousBase = (n2d_uint32_t)commandBuffer;
    gpu_params.registerMemBase2D = 0xBF8EB000;
    gpu_params.baseAddress = 0;

    n2d_init_hardware(&gpu_params);

    /* open and initialize gpu software  */
    if (N2D_IS_ERROR(n2d_open()))
        return ;

//	// GPU Pipeline
//	context->hal.drawPipeline[GFX_PIPELINE_GPU].drawLine[GFX_DRAW_LINE][GFX_ANTIALIAS_OFF] = &drawLine;
//	context->hal.drawPipeline[GFX_PIPELINE_GPU].drawLine[GFX_DRAW_FILL][GFX_ANTIALIAS_OFF] = &drawLine;
//
//	context->hal.drawPipeline[GFX_PIPELINE_GPU].drawRect[GFX_DRAW_FILL][GFX_ANTIALIAS_OFF] = &fillRect;
//
//	context->hal.drawPipeline[GFX_PIPELINE_GPU].drawBlit = &drawBlit;
//
//    // according to nano2d documentation the stretch blit is a fast resize, override nearest neighbor version
//    context->hal.drawPipeline[GFX_PIPELINE_GPU].drawStretchBlit[GFX_RESIZE_NEARESTNEIGHBOR] = &drawStretchBlit;
//
//	// GCU/GPU Pipeline
//	context->hal.drawPipeline[GFX_PIPELINE_GCUGPU].drawLine[GFX_DRAW_LINE][GFX_ANTIALIAS_OFF] = &drawLine;
//	context->hal.drawPipeline[GFX_PIPELINE_GCUGPU].drawLine[GFX_DRAW_FILL][GFX_ANTIALIAS_OFF] = &drawLine;
//
//	context->hal.drawPipeline[GFX_PIPELINE_GCUGPU].drawRect[GFX_DRAW_FILL][GFX_ANTIALIAS_OFF] = &fillRect;
//
//	context->hal.drawPipeline[GFX_PIPELINE_GCUGPU].drawBlit = &drawBlit;
//
//    // according to nano2d documentation the stretch blit is a fast resize, override nearest neighbor version
//    context->hal.drawPipeline[GFX_PIPELINE_GCUGPU].drawStretchBlit[GFX_RESIZE_NEARESTNEIGHBOR] = &drawStretchBlit;

}
