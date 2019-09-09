/*******************************************************************************
  MPLAB Harmony Graphics Asset Header File

  File Name:
    gfx_assets.h

  Summary:
    Header file containing a list of asset specifications for use with the
	MPLAB Harmony Graphics Stack.

  Description:
    Header file containing a list of asset specifications for use with the
	MPLAB Harmony Graphics Stack.

    Created with MPLAB Harmony Version 3.0
*******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2018 released Microchip Technology Inc.  All rights reserved.

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

#ifndef GFX_ASSETS_H
#define GFX_ASSETS_H

#include "gfx/utils/gfx_utils.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END 

/*** Generated Asset Descriptors ***/
/*****************************************************************************
 * MPLAB Harmony Graphics Asset Location IDs
 *****************************************************************************/
#define GFXU_ASSET_LOCATION_ID_INTERNAL    0
#define GFXU_ASSET_LOCATION_ID_Fonts    1
#define GFXU_ASSET_LOCATION_ID_Images    2
 
/*****************************************************************************
 * MPLAB Harmony Graphics Image Assets
 *****************************************************************************/
/*********************************
 * GFX Image Asset
 * Name:   MHGS_logo_small_jpeg
 * Size:   141x132 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MHGS_logo_small_jpeg;
	
/*********************************
 * GFX Image Asset
 * Name:   MHGS_logo_small_png
 * Size:   141x132 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MHGS_logo_small_png;
	
/*********************************
 * GFX Image Asset
 * Name:   MHGS_logo_small_raw
 * Size:   141x132 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MHGS_logo_small_raw;
	
/*********************************
 * GFX Image Asset
 * Name:   MHGS_logo_small_rle
 * Size:   141x132 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MHGS_logo_small_rle;
	
/*********************************
 * GFX Image Asset
 * Name:   MHGS_logo_small_raw_direct_blit
 * Size:   141x132 pixels
 * Mode:   GS_8
 * Format: RAW
 ***********************************/
extern GFXU_ImageAsset MHGS_logo_small_raw_direct_blit;
	
/*****************************************************************************
 * MPLAB Harmony Graphics Font Assets
 *****************************************************************************/
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS_Internal
 * Height:       23
 * Style:        Plain
 * Glyph Count:  31
 * Range Count:  23
 * Glyph Ranges: 0x20
			     0x42
			     0x46
			     0x50
			     0x53
			     0x55
			     0x61
			     0x64-0x66
			     0x68-0x69
			     0x6C-0x6F
			     0x72-0x74
			     0x77
			     0x79
			     0x4EF6
			     0x52A0
			     0x548C
			     0x5F85
			     0x6587
			     0x7B49
			     0x7CFB
			     0x7D71
			     0x8ACB
			     0x8F09
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS_Internal;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS
 * Height:       23
 * Style:        Plain
 * Glyph Count:  40
 * Range Count:  15
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
			     0x61-0x69
			     0x6C-0x70
			     0x72-0x79
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS;
	
/*********************************
 * GFX Font Asset
 * Name:         ArialUnicodeMS_Large
 * Height:       28
 * Style:        Plain
 * Glyph Count:  21011
 * Range Count:  18
 * Glyph Ranges: 0x20
			     0x2B
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
			     0x4E00-0x9FFF
 ***********************************/
extern GFXU_FontAsset ArialUnicodeMS_Large;
	
/*****************************************************************************
 * MPLAB Harmony Graphics String Table
 *****************************************************************************/
/*********************************
 * GFX String Table
 * Name:         stringTable
 * Encoding:     UTF16
 * Languages:    English, Chinese
 * String Count: 13
 ***********************************/
// language IDs
#define language_English    0
#define language_Chinese    1

// string IDs
#define string_DrawDirectBlit    0
#define string_DrawJpeg    1
#define string_DrawPNG    2
#define string_DrawRLE    3
#define string_DrawRaw    4
#define string_ImageIsDirectBlit    5
#define string_ImageIsJPEG    6
#define string_ImageIsPNG    7
#define string_ImageIsRLE    8
#define string_ImageIsRaw    9
#define string_TitleString    10
#define string_WaitForUSB    11
#define string_WaitForUSBAlt    12
 
extern GFXU_StringTableAsset stringTable;

/*****************************************************************************
 * MPLAB Harmony Graphics Global Palette
 *****************************************************************************/

extern uint16_t globalColorPalette[256];
//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif /* GFX_ASSETS_H */

