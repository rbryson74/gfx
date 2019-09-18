/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    generated/le_gen_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
    MPLAB Harmony Graphics Stack.

  Description:
    Header file containing a list of asset specifications for use with the
    MPLAB Harmony Graphics Stack.
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
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

#ifndef LE_GEN_ASSETS_H
#define LE_GEN_ASSETS_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

#include "gfx/legato/legato.h"

/*****************************************************************************
* MPLAB Harmony Graphics Asset Location IDs
*****************************************************************************/
/*********************************
 * Legato Asset Memory Location
 * Name:   Fonts1
 * Size:   1000000
 * Format: INTERNAL
 * Path:   None
 * Offset: 0
 ***********************************/
#define LA_ASSET_LOCATION_ID_Fonts1    2

/*********************************
 * Legato Asset Memory Location
 * Name:   Images
 * Size:   1000000
 * Format: INTERNAL
 * Path:   None
 * Offset: 0
 ***********************************/
#define LA_ASSET_LOCATION_ID_Images    3

/*********************************
 * Legato Asset Memory Location
 * Name:   Fonts2
 * Size:   1000000
 * Format: INTERNAL
 * Path:   None
 * Offset: 0
 ***********************************/
#define LA_ASSET_LOCATION_ID_Fonts2    4

/*****************************************************************************
* MPLAB Harmony Graphics Image Assets
*****************************************************************************/
/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_jpeg
 * Size:   141x132 pixels
 * Format: Raw
 * Mode: RGB_888
 ***********************************/
extern leImage MHGS_logo_small_jpeg;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_raw
 * Size:   141x132 pixels
 * Format: Raw
 * Mode: RGB_888
 ***********************************/
extern leImage MHGS_logo_small_raw;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_raw_direct_blit
 * Size:   141x132 pixels
 * Format: Raw
 * Mode: RGB_565
 ***********************************/
extern leImage MHGS_logo_small_raw_direct_blit;

/*********************************
 * Legato Image Asset
 * Name:   MHGS_logo_small_raw_rle
 * Size:   141x132 pixels
 * Format: RLE
 * Mode: RGB_888
 ***********************************/
extern leImage MHGS_logo_small_raw_rle;

/*****************************************************************************
* MPLAB Harmony Graphics Font Assets
*****************************************************************************/
/*********************************
 * Legato Font Asset
 * Name:         NotoSansCJKsc_Regular
 * Height:       19
 * Baseline:     14
 * Style:        Antialias
 * Glyph Count:  38
 * Range Count:  17
 * Glyph Ranges: 0x20
                 0x2B
                 0x41-0x42
                 0x44-0x45
                 0x47
                 0x49-0x4A
                 0x4C
                 0x4E
                 0x50-0x53
                 0x55
                 0x57
                 0x5C
                 0x61
                 0x63-0x69
                 0x6C-0x70
                 0x72-0x76
                 0x78-0x79
***********************************/
extern leRasterFont NotoSansCJKsc_Regular;

/*********************************
 * Legato Font Asset
 * Name:         NotoSansCJKsc_Regular_Large1
 * Height:       23
 * Baseline:     19
 * Style:        Antialias
 * Glyph Count:  10515
 * Range Count:  19
 * Glyph Ranges: 0x20
                 0x2B
                 0x3F
                 0x41-0x42
                 0x44-0x45
                 0x47
                 0x4A
                 0x4C
                 0x4E
                 0x50
                 0x52
                 0x57
                 0x63
                 0x65
                 0x69
                 0x6C
                 0x72
                 0x74
                 0x4E00-0x76FE
***********************************/
extern leRasterFont NotoSansCJKsc_Regular_Large1;

/*********************************
 * Legato Font Asset
 * Name:         NotoSansCJKsc_Regular_Internal
 * Height:       19
 * Baseline:     14
 * Style:        Antialias
 * Glyph Count:  40
 * Range Count:  20
 * Glyph Ranges: 0x20
                 0x27
                 0x2C
                 0x2E
                 0x31-0x32
                 0x3F
                 0x41-0x43
                 0x45-0x46
                 0x49
                 0x4C
                 0x50
                 0x53-0x55
                 0x5C
                 0x61-0x67
                 0x69
                 0x6C-0x70
                 0x72-0x74
                 0x76
                 0x78-0x79
                 0x201C-0x201D
***********************************/
extern leRasterFont NotoSansCJKsc_Regular_Internal;

/*********************************
 * Legato Font Asset
 * Name:         NotoSansCJKsc_Regular_Large2
 * Height:       23
 * Baseline:     19
 * Style:        Antialias
 * Glyph Count:  10497
 * Range Count:  1
 * Glyph Ranges: 0x76FF-0x9FFF
***********************************/
extern leRasterFont NotoSansCJKsc_Regular_Large2;

/*********************************
 * Legato Font Asset
 * Name:         NotoSansCJKsc_Regular_Bold
 * Height:       18
 * Baseline:     13
 * Style:        Antialias
 * Glyph Count:  26
 * Range Count:  15
 * Glyph Ranges: 0x20
                 0x41
                 0x45
                 0x47
                 0x4A
                 0x4C
                 0x4E
                 0x50
                 0x52
                 0x57
                 0x61-0x65
                 0x69
                 0x6C-0x70
                 0x72-0x75
                 0x77
***********************************/
extern leRasterFont NotoSansCJKsc_Regular_Bold;

/*****************************************************************************
 * Legato String Table
 * Encoding        UTF16
 * Language Count: 2
 * String Count:   16
*****************************************************************************/

// language IDs
#define language_English    0
#define language_Chinese    1

// string IDs
#define string_DrawDirectBlit    0
#define string_DrawJpeg    1
#define string_DrawPNG    2
#define string_DrawRLE    3
#define string_DrawRaw    4
#define string_ImageFromExternal    5
#define string_ImageIsDirectBlit    6
#define string_ImageIsJPEG    7
#define string_ImageIsPNG    8
#define string_ImageIsRLE    9
#define string_ImageIsRaw    10
#define string_PressButton    11
#define string_PressToMainScreen    12
#define string_TitleString    13
#define string_WaitForUSB    14
#define string_WaitForUSBAlt    15

extern const leStringTable stringTable;
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* LE_GEN_ASSETS_H */
