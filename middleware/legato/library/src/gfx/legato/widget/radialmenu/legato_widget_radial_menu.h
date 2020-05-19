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
    legato_widget_radial_menu.h

  Summary:
    

  Description:
    This module implements radial menu widget functions.
*******************************************************************************/

/** \file legato_widget_radial_menu.h
 * @brief Radial menu functions and definitions.
 *
 * @details This module implements radial menu widget functions.
 */

#ifndef LEGATO_RADIALMENU_H
#define LEGATO_RADIALMENU_H

#include "gfx/legato/common/legato_common.h"

#if LE_RADIALMENU_WIDGET_ENABLED == 1

#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/widget/image/legato_widget_image.h"
#include "gfx/legato/datastructure/legato_list.h"
#include "gfx/legato/string/legato_string.h"

typedef struct leRadialMenuWidget leRadialMenuWidget;

typedef void (*leRadialMenuWidget_ItemSelectedEvent)(leRadialMenuWidget*, leWidget*, int32_t);
typedef void (*leRadialMenuWidget_ItemProminenceChangedEvent)(leRadialMenuWidget*, leWidget*, int32_t);

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************
/**
 * @brief Used to define a radial menu widget state.
 * @details .
 */
typedef enum leRadialMenuWidgetState
{
    LE_RADIAL_MENU_INIT,
	LE_RADIAL_MENU_INPUT_READY,
	LE_RADIAL_MENU_HANDLE_USER_MOVE_REQUEST,
    LE_RADIAL_MENU_RESET_TO_INPUT_POS            
} leRadialMenuWidgetState;

/**
 * @brief Used to define a radial menu interpolation mode.
 * @details .
 */
typedef enum leRadialMenuWidgetInterpolationMode
{
	LE_RADIAL_MENU_INTERPOLATE_OFF,
	LE_RADIAL_MENU_INTERPOLATE_GRADUAL,
	LE_RADIAL_MENU_INTERPOLATE_PROMINENT
} leRadialMenuWidgetInterpolationMode;

/**
 * @brief Used to define a radial menu ellipse type.
 * @details .
 */
typedef enum leRadialMenuEllipseType
{
	LE_RADIAL_MENU_ELLIPSE_TYPE_DEFAULT,
	LE_RADIAL_MENU_ELLIPSE_TYPE_ORBITAL,
	LE_RADIAL_MENU_ELLIPSE_TYPE_ROLLODEX
} leRadialMenuEllipseType;

/* internal use only */
/**
  * @cond INTERNAL
  *
  */typedef struct leRadialMenuWidget leRadialMenuWidget;

#define LE_RADIALMENUWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    leBool    (*isProminent)(const THIS_TYPE* _this, const leWidget* widget); \
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
    leResult  (*setProminent)(THIS_TYPE* _this, const leWidget* widget); \
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
    int32_t   (*getProminentIndex)(const THIS_TYPE* _this); \
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
    leResult  (*setProminentIndex)(THIS_TYPE* _this, int32_t index); \
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
    leResult  (*setNumberOfItemsShown)(THIS_TYPE* _this, uint32_t cnt); \
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
    leResult  (*setHighlightProminent)(THIS_TYPE* _this, leBool hl); \
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
    int32_t   (*getTheta)(const THIS_TYPE* _this); \
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
    leResult  (*setTheta)(THIS_TYPE* _this, int32_t tht); \
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
    leResult  (*setEllipseType)(THIS_TYPE* _this, leRadialMenuEllipseType type); \
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
    leResult  (*addWidget)(THIS_TYPE* _this, leWidget* wgt); \
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
    leResult  (*removeWidget)(THIS_TYPE* _this, leWidget* wgt); \
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
    leWidget* (*getWidgetAtIndex)(const THIS_TYPE* _this, int32_t idx); \
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
    leResult  (*setWidgetAtIndex)(THIS_TYPE* _this, int32_t idx, leWidget* wgt); \
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
    leResult  (*removeAllWidgets)(THIS_TYPE* _this); \
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
    leResult  (*setScaleMode)(THIS_TYPE* _this, leRadialMenuWidgetInterpolationMode mode); \
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
    leResult  (*setScaleRange)(THIS_TYPE* _this, int32_t min, int32_t max); \
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
    leResult  (*setBlendMode)(THIS_TYPE* _this, leRadialMenuWidgetInterpolationMode mode); \
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
    leResult  (*setBlendRange)(THIS_TYPE* _this, int32_t min, int32_t max); \
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
    leResult  (*setTouchArea)(THIS_TYPE* _this, int32_t x, int32_t y, int32_t width, int32_t height); \
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
    leResult  (*setDrawEllipse)(THIS_TYPE* _this, leBool b); \
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
    leRadialMenuWidget_ItemSelectedEvent (*getItemSelectedEventCallback)(const THIS_TYPE* _this); \
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
    leResult  (*setItemSelectedEventCallback)(THIS_TYPE* _this, leRadialMenuWidget_ItemSelectedEvent cb); \
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
    leRadialMenuWidget_ItemProminenceChangedEvent (*getItemProminenceChangedEventCallback)(const THIS_TYPE* _this); \
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
    leResult  (*setItemProminenceChangedEventCallback)(THIS_TYPE* _this, leRadialMenuWidget_ItemProminenceChangedEvent cb); \
    
typedef struct leRadialMenuWidgetVTable
{
	LE_RADIALMENUWIDGET_VTABLE(leRadialMenuWidget)
} leRadialMenuWidgetVTable; 

    /**
      * @endcond
      *
      */

/**
 * @brief Used to define a radial menu item node.
 * @details .
 */
typedef struct leRadialMenuItemNode
{
	leWidget* widget; // point to the widget of the item
	int32_t t; // the angle in degress between 0 - 360, representing the relative position of the item on the track
	
	//leWidgetInputHandler inputHandler; 
    
	//leWidget_TouchDownEvent_FnPtr origTouchDown; //the widget item's original touch down event, 
                                                 //allows the radial menu to work as a hub to route to the appropriate widget
	//leWidget_TouchUpEvent_FnPtr origTouchUp; //the widget item's original touch up event
                                                 //allows the radial menu to work as a hub to route to the appropriate widget
	//leWidget_TouchMovedEvent_FnPtr origTouchMoved; //the widget item's original touch move event

    leRect origSize;  //the original size of the widget, it is a reference point for scaling
    uint32_t origAlphaAmount; //the original alpha value of the widget, it is a reference point for scaling
    
} leRadialMenuItemNode;

// *****************************************************************************
/**
 * @brief This struct represents a radial menu widget.
 * @details A radial menu is a master widget that manages the movement, in an
 * elliptical track, of a list of widgets.  It also manages the draw order and
 * scaling of each widget item.
 * It is essentially a group of widgets which provides a mutually exclusive
 * selection capability so that only one item may be selected at any one time.
 */
typedef struct leRadialMenuWidget
{
    leWidget widget; // widget base class
    
    const leRadialMenuWidgetVTable* fn;

	leRadialMenuWidgetState state;

    int32_t prominentIndex;
    int32_t lastProminentIndex;
	int32_t userRequestedAngleDiff; // the angle for the radial menu to rotate as requested by user
	int32_t targetAngleDiff; // the angle for the radial menu to rotate for prominent item to be in front
    int32_t userRequestedDirection; // tracks the direction that the user requested for rotation
    
    leBool drawEllipse; // indicates if the radial menu is selected
    leBool highlightProminent; // highlight the prominent widget

	leImageWidget* highlighter; // this widget manages the selector art asset
    
	int32_t a;  // the half-length of the 0-180 axis of the ellipse
	int32_t b;  // the half-length of the 90-270 axis of the ellipse
	int32_t theta; // the angle of rotation of the entire ellipse
	
    leBool touchPressed; // keep track of users touch input
    
    leBool ellipseChanged; // keeps track if the elliptical track has changed
    
	leRadialMenuWidgetInterpolationMode scaleMode;  // the enable item size scaling within the widget

	int32_t maxSizePercent;  // the maximum size scale between 1 - 200%
	int32_t minSizePercent;  // the minimum size scale between 1 - 200%

	leRect touchArea; // the area specified within the widget that touch events are detected

	leRadialMenuWidgetInterpolationMode blendMode; // the enable item alpha scaling within the widget

	int32_t maxAlphaAmount;  // the maximum alpha between 0 - 255
	int32_t minAlphaAmount;  // the minimum alpha between 0 - 255

    uint32_t itemsShown; // keeps count of how many items to visible, this number should be less than or equal to total number of widget items
    leList widgetList; // this is the list of widgets
    leList shownList; // this is the partial list of widgets shown
    leList hiddenList; // this is the partial list of widgets hidden

    leRadialMenuItemNode* widestWidgetItem; // keeps track of which widget is the widgets for major axis calculation
    leRadialMenuItemNode* tallestWidgetItem; // keeps track of which widget is the widgets for minor axis calculation
    
    leRadialMenuWidget_ItemSelectedEvent itemSelectedEvent; // an item is selected event callback
	leRadialMenuWidget_ItemProminenceChangedEvent itemProminenceChangedEvent; // whenever a new item is in prominence event callback

    leRadialMenuEllipseType ellipseType;
} leRadialMenuWidget;


// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

/**
 * @brief Create widget.
 * @details Creates a new leRadialMenuWidget and allocates memory for the widget through the
 * current active context.  Application is responsible for managing the widget
 * pointer until the widget is added to a widget tree.
 * @remark use leWidget_Delete() to free this pointer.
 * @code
 * leRadialMenuWidget* wgt = leRadialMenuWidget_New();
 * @endcode
 * @return a widget object pointer.
 */
LIB_EXPORT leRadialMenuWidget* leRadialMenuWidget_New();

/**
 * @brief Initialize widget.
 * @details Initializes the leRadialMenuWidget <span class="param">wgt</span>.
 * @code
 * leRadialMenuWidget* wgt;
 * leRadialMenuWidget_Constructor(wgt);
 * @endcode
 * @param wgt is the widget to initialize
 * @return void.
 */
LIB_EXPORT void leRadialMenuWidget_Constructor(leRadialMenuWidget* wgt);

// *****************************************************************************
/* Virtual Member Function:
    leBool isProminent(const leRadialMenuWidget* _this,
                       const leWidget* widget)

  Summary:
     Evaluates a widget to see if it is the prominent widget

  Description:
     Evaluates a widget to see if it is the prominent widget

  Parameters:
    const leRadialMenuWidget* _this - The radial menu bar widget to operate on
    const leWidget* widget -

  Remarks:
    Usage - _this->fn->isProminent(_this, widget);

  Returns:
    leBool - the prominent indicator
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setProminent(leRadialMenuWidget* _this,
                          const leWidget* widget)

  Summary:
     Sets a widget as prominent

  Description:
     Sets a widget as prominent

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    const leWidget* widget - the widget to test

  Remarks:
    Usage - _this->fn->setProminent(_this, widget);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    int32_t getProminentIndex(const leRadialMenuWidget* _this)

  Summary:
     Gets the prominent item index

  Description:
     Gets the prominent item index

  Parameters:
    const leRadialMenuWidget* _this - The radial menu bar widget to operate on

  Remarks:
    Usage - _this->fn->getProminentIndex(_this);

  Returns:
    int32_t - the prominent index
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setProminentIndex(leRadialMenuWidget* _this,
                               int32_t index)

  Summary:
     Sets the prominent item index

  Description:
     Sets the prominent item index

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    int32_t index - the desired prominent index

  Remarks:
    Usage - _this->fn->setProminentIndex(_this, index);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setNumberOfItemsShown(leRadialMenuWidget* _this,
                                   uint32_t cnt)

  Summary:
     Sets the number of items shown

  Description:
     Sets the number of items shown

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    uint32_t cnt - the item count

  Remarks:
    Usage - _this->fn->setNumberOfItemsShown(_this, cnt);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setHighlightProminent(leRadialMenuWidget* _this,
                                   leBool hl)

  Summary:
     Sets the highlight prominent setting value

  Description:
     Sets the highlight prominent setting value

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    leBool hl - the setting value

  Remarks:
    Usage - _this->fn->setHighlightProminent(_this, hl);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    int32_t getTheta(const leRadialMenuWidget* _this)

  Summary:
     Gets the menu ellipse rotation coefficient

  Description:
     Gets the menu ellipse rotation coefficient

  Parameters:
    const leRadialMenuWidget* _this - The radial menu bar widget to operate on

  Remarks:
    Usage - _this->fn->getTheta(_this);

  Returns:
    int32_t - the theta value
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setTheta(leRadialMenuWidget* _this,
                      int32_t tht)

  Summary:
     Sets the menu ellipse rotation coefficient

  Description:
     Sets the menu ellipse rotation coefficient

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    int32_t tht - the theta value

  Remarks:
    Usage - _this->fn->setTheta(_this, tht);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setEllipseType(leRadialMenuWidget* _this,
                            leRadialMenuEllipseType type)

  Summary:
     Sets the menu ellipse type

  Description:
     Sets the menu ellipse type

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    leRadialMenuEllipseType type - the type

  Remarks:
    Usage - _this->fn->setEllipseType(_this, type);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult addWidget(leRadialMenuWidget* _this,
                       leWidget* wgt)

  Summary:
     Adds a widget to the ellipse

  Description:
     Adds a widget to the ellipse

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    leWidget* wgt - the widget to add

  Remarks:
    Usage - _this->fn->addWidget(_this, wgt);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult removeWidget(leRadialMenuWidget* _this,
                          leWidget* wgt)

  Summary:
     Removes a widget from the ellipse

  Description:
     Removes a widget from the ellipse

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    leWidget* wgt - the widget to remove

  Remarks:
    Usage - _this->fn->removeWidget(_this, wgt);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leWidget* getWidgetAtIndex(const leRadialMenuWidget* _this,
                               int32_t idx)

  Summary:
     Gets a widget at a given index

  Description:
     Gets a widget at a given index

  Parameters:
    const leRadialMenuWidget* _this - The radial menu bar widget to operate on
    int32_t idx - the index

  Remarks:
    Usage - _this->fn->getWidgetAtIndex(_this, idx);

  Returns:
    leWidget* - the widget
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setWidgetAtIndex(leRadialMenuWidget* _this,
                              int32_t idx,
                              leWidget* wgt)

  Summary:
     Sets a widget at a given index

  Description:
     Sets a widget at a given index

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    int32_t idx - the index
    leWidget* wgt - the widget to set

  Remarks:
    Usage - _this->fn->setWidgetAtIndex(_this, idx, wgt);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult removeAllWidgets(leRadialMenuWidget* _this)

  Summary:
     Removes all widgets from the menu

  Description:
     Removes all widgets from the menu

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on

  Remarks:
    Usage - _this->fn->removeAllWidgets(_this);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setScaleMode(leRadialMenuWidget* _this,
                          leRadialMenuWidgetInterpolationMode mode)

  Summary:
     Sets the menu item scaling mode

  Description:
     Sets the menu item scaling mode

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    leRadialMenuWidgetInterpolationMode mode -

  Remarks:
    Usage - _this->fn->setScaleMode(_this, mode);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setScaleRange(leRadialMenuWidget* _this,
                           int32_t min,
                           int32_t max)

  Summary:
     Sets the scale range for menu items

  Description:
     Sets the scale range for menu items

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    int32_t min - the minimum value
    int32_t max - the maximum value

  Remarks:
    Usage - _this->fn->setScaleRange(_this, min, max);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setBlendMode(leRadialMenuWidget* _this,
                          leRadialMenuWidgetInterpolationMode mode)

  Summary:
     Sets the menu item blending mode

  Description:
     Sets the menu item blending mode

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    leRadialMenuWidgetInterpolationMode mode -

  Remarks:
    Usage - _this->fn->setBlendMode(_this, mode);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setBlendRange(leRadialMenuWidget* _this,
                           int32_t min,
                           int32_t max)

  Summary:
     Sets the blending range

  Description:
     Sets the blending range

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    int32_t min - the minimum value
    int32_t max - the maximum value

  Remarks:
    Usage - _this->fn->setBlendRange(_this, min, max);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setTouchArea(leRadialMenuWidget* _this,
                          int32_t x,
                          int32_t y,
                          int32_t width,
                          int32_t height)

  Summary:
     Sets the menu touch area

  Description:
     Sets the menu touch area

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    int32_t x - the X value
    int32_t y - the Y value
    int32_t width - the width value
    int32_t height - the height value

  Remarks:
    Usage - _this->fn->setTouchArea(_this, x, y, width, height);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setDrawEllipse(leRadialMenuWidget* _this,
                            leBool b)

  Summary:
     Sets the draw ellipse setting value

  Description:
     Sets the draw ellipse setting value

  Parameters:
    leRadialMenuWidget* _this - The radial menu bar widget to operate on
    leBool b - the setting value

  Remarks:
    Usage - _this->fn->setDrawEllipse(_this, b);

  Returns:
    leResult - the result of the operation
*/

/**
 * @brief Get item prominence changed event callback pointer.
 * @details Gets the item prominence changed event callback pointer using <span class="param">_this</span>.
 * @code
 * leRadialMenuWidget* _this;
 * leRadialMenuWidget_ItemSelectedEvent cb = _this->fn->getItemSelectedEventCallback(_this);
 * @endcode
 * @param _this is the widget to modify
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leRadialMenuWidget_ItemSelectedEvent getItemSelectedEventCallback(const leRadialMenuWidget* _this)

/**
 * @brief Set item prominence changed event callback pointer.
 * @details Sets the item prominence changed event callback pointer to <span class="param">cb</span>
 * using <span class="param">_this</span>.
 * @code
 * leRadialMenuWidget* _this;
 * leRadialMenuWidget_ItemSelectedEvent cb;
 * leResult res = _this->fn->setItemSelectedEventCallback(_this, cb);
 * @endcode
 * @param _this is the widget to modify
 * @param cb is the callback func
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setItemSelectedEventCallback(leRadialMenuWidget* _this,
                                              leRadialMenuWidget_ItemSelectedEvent cb);

/**
 * @brief Get item prominence changed event callback pointer.
 * @details Gets the item prominence changed event callback pointer using <span class="param">_this</span>.
 * @code
 * leRadialMenuWidget* _this;
 * leRadialMenuWidget_ItemProminenceChangedEvent cb = _this->fn->getItemProminenceChangedEventCallback(_this);
 * @endcode
 * @param _this is the widget to modify
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leRadialMenuWidget_ItemProminenceChangedEvent getItemProminenceChangedEventCallback
                                                    (const leRadialMenuWidget* _this)

/**
 * @brief Set item prominence changed event callback pointer.
 * @details Sets the item prominence changed event callback pointer to <span class="param">cb</span>
 * using <span class="param">_this</span>.
 * @code
 * leRadialMenuWidget* _this;
 * leRadialMenuWidget_ItemProminenceChangedEvent cb;
 * leResult res = _this->fn->setItemProminenceChangedEventCallback(_this, cb);
 * @endcode
 * @param _this is the widget to modify
 * @param cb is the callback func
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setItemProminenceChangedEventCallback(leRadialMenuWidget* _this,
                                                       leRadialMenuWidget_ItemProminenceChangedEvent cb)

#undef THIS_TYPE
#endif

/* internal use only */
/**
  * @cond INTERNAL
  *
  */
leWidgetUpdateState _leRadialMenuWidget_Update(leRadialMenuWidget* mn);
/**
  * @endcond
  *
  */

#endif // LE_RADIALMENU_WIDGET_ENABLED
#endif /* LEGATO_RADIALMENU_H */
