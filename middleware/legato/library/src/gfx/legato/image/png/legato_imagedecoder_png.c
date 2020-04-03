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


#include "gfx/legato/image/png/legato_imagedecoder_png.h"

#include "gfx/legato/common/legato_math.h"
#include "gfx/legato/core/legato_state.h"
#include "gfx/legato/core/legato_stream.h"
#include "gfx/legato/image/legato_palette.h"
#include "gfx/legato/memory/legato_memory.h"
#include "gfx/legato/renderer/legato_renderer.h"

#include "gfx/legato/image/png/lodepng.h"

static leImageDecoder decoder;

static struct leImage decodedImage;

static leBool _supportsImage(const leImage* img)
{
    if(img->header.location != LE_STREAM_LOCATION_ID_INTERNAL)
        return LE_FALSE;

    return img->format == LE_IMAGE_FORMAT_PNG;
}

static leResult _draw(const leImage* img,
                      const leRect* srcRect,
                      int32_t x,
                      int32_t y,
                      uint32_t a)
{
    leRect imgRect, sourceClipRect;

#if LE_STREAMING_ENABLED == 1
    leStream stream;
#endif

    uint8_t* encodedData = NULL;
    uint8_t* decodedData;
    uint32_t width;
    uint32_t height;

    imgRect.x = 0;
    imgRect.y = 0;
    imgRect.width = img->buffer.size.width;
    imgRect.height = img->buffer.size.height;

    /* make sure the source rect is within the source bounds */
    if(leRectIntersects(&imgRect, srcRect) == LE_FALSE)
        return LE_FAILURE;

    leRectClip(&imgRect, srcRect, &sourceClipRect);

    if(sourceClipRect.width <= 0 || sourceClipRect.height <= 0)
        return LE_FAILURE;

#if LE_STREAMING_ENABLED == 1
    if(img->header.location != LE_STREAM_LOCATION_ID_INTERNAL)
    {
        encodedData = leMalloc(img->header.size);

        if(encodedData == NULL)
            return LE_FAILURE;

        leStream_Init(&stream,
                      &img->header,
                      0,
                      NULL,
                      NULL);

        if(leStream_Open(&stream) == LE_FAILURE)
            return LE_FAILURE;

        stream.flags |= SF_BLOCKING;

        leStream_Read(&stream,
                      (uint32_t)img->header.address,
                      img->header.size,
                      encodedData,
                      NULL);
    }
    else
#else
    {
        encodedData = img->header.address;
    }
#endif

    lodepng_decode_memory(&decodedData,
                          &width,
                          &height,
                          encodedData,
                          img->header.size,
                          img->buffer.mode == LE_COLOR_MODE_RGBA_8888 ? LCT_RGBA : LCT_RGB,
                          8);

#if LE_STREAMING_ENABLED == 1
    if(img->header.location != LE_STREAM_LOCATION_ID_INTERNAL)
    {
        leFree(encodedData);
    }
#endif

    leImage_Create(&decodedImage,
                   width,
                   height,
                   img->buffer.mode,
                   decodedData,
                   LE_STREAM_LOCATION_ID_INTERNAL);

    leImage_Draw(&decodedImage,
                 srcRect,
                 x,
                 y,
                 a);

    LE_FREE(decodedData);

    return LE_SUCCESS;
}

static leResult _render(const leImage* src,
                        const leRect* srcRect,
                        int32_t x,
                        int32_t y,
                        leBool ignoreMask,
                        leBool ignoreAlpha,
                        leImage* dst)
{
    leRect imgRect, sourceClipRect;

    uint8_t* encodedData;
    uint8_t* decodedData;
    uint32_t width;
    uint32_t height;

#if LE_STREAMING_ENABLED == 1
    leStream stream;
#endif

    imgRect.x = 0;
    imgRect.y = 0;
    imgRect.width = src->buffer.size.width;
    imgRect.height = src->buffer.size.height;

    /* make sure the source rect is within the source bounds */
    if(leRectIntersects(&imgRect, srcRect) == LE_FALSE)
        return LE_FAILURE;

    leRectClip(&imgRect, srcRect, &sourceClipRect);

    if(sourceClipRect.width <= 0 || sourceClipRect.height <= 0)
        return LE_FAILURE;

#if LE_STREAMING_ENABLED == 1
    if(src->header.location != LE_STREAM_LOCATION_ID_INTERNAL)
    {
        encodedData = leMalloc(src->header.size);

        if(encodedData == NULL)
            return LE_FAILURE;

        leStream_Init(&stream,
                      &src->header,
                      0,
                      NULL,
                      NULL);

        if(leStream_Open(&stream) == LE_FAILURE)
            return LE_FAILURE;

        stream.flags |= SF_BLOCKING;

        leStream_Read(&stream,
                      (uint32_t)src->header.address,
                      src->header.size,
                      encodedData,
                      NULL);
    }
    else
#else
    {
        encodedData = src->header.address;
    }
#endif

    lodepng_decode_memory(&decodedData,
                          &width,
                          &height,
                          encodedData,
                          src->header.size,
                          src->buffer.mode == LE_COLOR_MODE_RGBA_8888 ? LCT_RGBA : LCT_RGB,
                          8);

#if LE_STREAMING_ENABLED == 1
    if(src->header.location != LE_STREAM_LOCATION_ID_INTERNAL)
    {
        leFree(encodedData);
    }
#endif

    lePixelBufferCopy(&dst->buffer, x, y, &src->buffer, srcRect);

    LE_FREE(decodedData);

    return LE_SUCCESS;
}

static void _decoderCleanup()
{
}

static leResult _decoderExec()
{
    return LE_SUCCESS;
}

static leBool _decoderIsDone()
{
    return LE_TRUE;
}

leImageDecoder* _lePNGImageDecoder_Init(void)
{
    decoder.supportsImage = _supportsImage;
    decoder.draw = _draw;
    decoder.copy = NULL;
    decoder.render = _render;
    decoder.resize = NULL;
    decoder.resizeDraw = NULL;
    decoder.rotate = NULL;
    decoder.rotateDraw = NULL;
    decoder.exec = _decoderExec;
    decoder.isDone = _decoderIsDone;
    decoder.free = _decoderCleanup;

    return &decoder;
}
