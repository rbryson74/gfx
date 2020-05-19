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
    legato_widget_rectangle.h

  Summary:
    

  Description:
    This module implements rectangle drawing widget functions.
*******************************************************************************/
/** \file legato_widget_rectangle.h
 * @brief Rectangle widget functions and definitions.
 *
 * @details This module implements rectangle widget functions.
 */

#ifndef LEGATO_RECTANGLE_H
#define LEGATO_RECTANGLE_H

#include "gfx/legato/common/legato_common.h"

#if LE_RECTANGLE_WIDGET_ENABLED == 1

#include "gfx/legato/widget/legato_widget.h"

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

typedef struct leRectangleWidget leRectangleWidget;

#define LE_RECTANGLEWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    /**
     * @brief Get title bar height.
     * @details Returns the title bar height from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leResult res =  = wgt->fn->getCursorDelay(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    int32_t   (*getThickness)(const THIS_TYPE* _this); \
    /**
     * @brief Set title height.
     * @details Sets the title height for <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * uint32_t ht;
     * leResult res = wgt->fn->setTitleHeight(wgt, ht);
     * @endcode
     * @param param1 wgt is the widget to modify
     * @return returns uint32_t.
     */
    leResult  (*setThickness)(THIS_TYPE* _this, int32_t thk); \
    
typedef struct leRectangleWidgetVTable
{
	LE_RECTANGLEWIDGET_VTABLE(leRectangleWidget)
} leRectangleWidgetVTable; 

// *****************************************************************************
/**
 * @brief This struct represents a rectangle widget.
 * @details A rectangle widget draws a basic rectangle of a given
 * thickness using the widget's bounding box as the dimensions.
 */
typedef struct leRectangleWidget
{
    leWidget widget; // widget base class

    const leRectangleWidgetVTable* fn;

    int32_t thickness; // rectangle border thickness
} leRectangleWidget;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

/**
 * @brief Create widget.
 * @details Creates a new leRectangleWidget and allocates memory for the widget through the
 * current active context.  Application is responsible for managing the widget
 * pointer until the widget is added to a widget tree.
 * @remark use leWidget_Delete() to free this pointer.
 * @code
 * leRectangleWidget* wgt = leRectangleWidget_New();
 * @endcode
 * @return a widget object pointer.
 */
LIB_EXPORT leRectangleWidget* leRectangleWidget_New();

/**
 * @brief Initialize widget.
 * @details Initializes the leRectangleWidget <span class="param">wgt</span>.
 * @code
 * leRectangleWidget* wgt;
 * leRectangleWidget_Constructor(wgt);
 * @endcode
 * @param wgt is the widget to initialize
 * @return void.
 */
void leRectangleWidget_Constructor(leRectangleWidget* wgt);

// *****************************************************************************
/* Virtual Member Function:
    int32_t getThickness(const leRectangleWidget* _this)

  Summary:
     Gets the rectangle border thickness

  Description:
     Gets the rectangle border thickness

  Parameters:
    const leRectangleWidget* _this - The rectangle widget to operate on

  Remarks:
    Usage - _this->fn->getThickness(_this);

  Returns:
    int32_t - the thickness value
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setThickness(leRectangleWidget* _this,
                          int32_t thk)

  Summary:
     Sets the rectangle border thickness

  Description:
     Sets the rectangle border thickness

  Parameters:
    leRectangleWidget* _this - The rectangle widget to operate on
    int32_t thk -

  Remarks:
    Usage - _this->fn->setThickness(_this, thk);

  Returns:
    leResult - the result of the operation
*/



#endif // LE_RECTANGLE_WIDGET_ENABLED
#endif /* LEGATO_RECTANGLE_H */
