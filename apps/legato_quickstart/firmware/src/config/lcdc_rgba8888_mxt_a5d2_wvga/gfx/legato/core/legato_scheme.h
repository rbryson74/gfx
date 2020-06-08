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
 Module for Microchip Graphics Library - Legato User Interface Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_scheme.h

  Summary:
    A scheme is a collection of colors that can be referenced by one or more
    widgets.  Widgets may use schemes in different ways.  While the color
    names strive to be intuitive they aren't always used in the manner in
    which they describe.
*******************************************************************************/

/** \file legato_scheme.h
 * @brief Schemes support various properties that make it possible to customize the
 * color of widgets.
 *
 * @details A scheme is a collection of colors that can be referenced by
 * one or more widgets.  Widgets may use schemes in different ways.  While
 * the color names strive to be intuitive they aren't always used in the manner
 * in which they describe.
 */

#ifndef LEGATO_SCHEME_H
#define LEGATO_SCHEME_H

#include "gfx/legato/common/legato_common.h"

#include "gfx/legato/common/legato_color.h"

#ifdef __cplusplus
    extern "C" {
#endif
      
// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************
/**
 * @brief This struct represents style scheme components for objects.
 * @details  A scheme is a collection of colors that can be referenced by
 * widgets or other objects. While the color names strive to be intuitive
 * they aren't always used in the manner in which they describe.
 */
typedef struct leScheme
{
    leColor base;
    leColor highlight;
    leColor highlightLight;
    leColor shadow;
    leColor shadowDark;
    leColor foreground;
    leColor foregroundInactive;
    leColor foregroundDisabled;
    leColor background;
    leColor backgroundInactive;
    leColor backgroundDisabled;
    leColor text;
    leColor textHighlight;
    leColor textHighlightText;
    leColor textInactive;
    leColor textDisabled;
} leScheme;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

/* Function:
     void leScheme_Initialize(leScheme* scheme, leColorMode mode)
 
   Summary:
     Initialize the scheme to the default values as per the specified color mode. 

   Description:
     Initialize the scheme to the default values as per the specified color mode.

   Parameters:
     leScheme* scheme - the scheme to modify
     leColorMode - the color mode to use
    
   Returns:
     void    

*/
/**
 * @brief Initialize scheme.
 * @details Initializes <span class="param">scheme</span> to the
 * default values of <span class="param">mode</span>.
 * @code
 * leScheme* scheme;
 * leColorMode mode
 * leScheme_Initialize(scheme, mode);
 * @endcode
 * @param scheme is the scheme to initialize.
 * @param mode is color mode.
 * @return void.
 */
LIB_EXPORT void leScheme_Initialize(leScheme* scheme, leColorMode mode);

#ifdef __cplusplus
    }
#endif
    
#endif // LEGATO_SCHEME_H 
