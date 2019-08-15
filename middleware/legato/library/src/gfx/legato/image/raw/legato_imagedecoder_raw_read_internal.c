/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
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

#include "gfx/legato/image/raw/legato_imagedecoder_raw.h"

#include "gfx/legato/common/legato_error.h"
#include "gfx/legato/image/legato_image_utils.h"
#include "gfx/legato/renderer/legato_renderer.h"

void _leRawImageDecoder_InjectStage(leRawDecodeState* state,
                                    leRawDecodeStage* stage);

static struct InternalReadStage
{
    leRawDecodeStage base;
    void (*decode)(void);
    uint32_t lastBlock;
    uint32_t lastOffset;

    uint32_t dataSize;
    uint32_t imgBPP;
} internalReadStage;

static void colorDecode()
{
    leRawSourceReadOperation* op = &internalReadStage.base.state->readOperation[internalReadStage.base.state->readIndex];

    // get a pixel from the sourced image
    op->data = lePixelBufferGet_Unsafe(&internalReadStage.base.state->source->buffer,
                                       op->x,
                                       op->y);
}

static void indexDecode()
{
    leRawSourceReadOperation* op = &internalReadStage.base.state->readOperation[internalReadStage.base.state->readIndex];

    op->data = lePixelBufferGetIndex_Unsafe(&internalReadStage.base.state->source->buffer,
                                            op->bufferIndex);
}

static void rleDecode()
{
    leRawSourceReadOperation* op = &internalReadStage.base.state->readOperation[internalReadStage.base.state->readIndex];

    op->data = leGetRLEDataAtIndex(internalReadStage.base.state->source->buffer.pixels,
                                   internalReadStage.base.state->source->buffer.pixel_count,
                                   op->bufferIndex,
                                   &internalReadStage.lastBlock,
                                   &internalReadStage.lastOffset);
}

static void indexRLEDecode()
{
    uint32_t srcClr;

    leRawSourceReadOperation* op = &internalReadStage.base.state->readOperation[internalReadStage.base.state->readIndex];

    // get the offset into the index table
    srcClr = leGetOffsetFromIndexAndBPP(op->bufferIndex,
                                        internalReadStage.imgBPP);

    // perform RLE lookup
    srcClr = leGetRLEDataAtIndex(internalReadStage.base.state->source->buffer.pixels,
                                 internalReadStage.base.state->source->buffer.pixel_count,
                                 srcClr,
                                 &internalReadStage.lastBlock,
                                 &internalReadStage.lastOffset);

    // get the value from the RLE block
    srcClr = leGetDiscreteValueAtIndex(op->bufferIndex,
                                       srcClr,
                                       internalReadStage.base.state->source->buffer.mode);

    op->data = srcClr;
}

static leResult stage_decode(struct InternalReadStage* stage)
{
    stage->base.state->readIndex = 0;

    for(stage->base.state->readIndex = 0;
        stage->base.state->readIndex < stage->base.state->readCount;
        stage->base.state->readIndex++)
    {
        internalReadStage.decode();
    }

    return LE_SUCCESS;
}

leResult _leRawImageDecoder_ReadStage_Internal(leRawDecodeState* state)
{
    memset(&internalReadStage, 0, sizeof(internalReadStage));

    internalReadStage.dataSize = leColorInfoTable[state->source->buffer.mode].size;
    internalReadStage.imgBPP = leColorInfoTable[state->source->buffer.mode].bppOrdinal;

    internalReadStage.base.state = state;

    if(LE_COLOR_MODE_IS_INDEX(state->source->buffer.mode) == LE_TRUE)
    {
        if(state->source->format == LE_IMAGE_FORMAT_RAW)
        {
            internalReadStage.decode = indexDecode;
        }
        else
        {
            internalReadStage.decode = indexRLEDecode;
        }
    }
    else
    {
        if(state->source->format == LE_IMAGE_FORMAT_RAW)
        {
            internalReadStage.decode = colorDecode;
        }
        else
        {
            internalReadStage.decode = rleDecode;
        }
    }

    internalReadStage.base.exec = (void *) stage_decode;

    _leRawImageDecoder_InjectStage(state, (void*)&internalReadStage);

    return LE_SUCCESS;
}