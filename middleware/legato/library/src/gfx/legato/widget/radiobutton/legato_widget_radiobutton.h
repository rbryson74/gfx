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
    legato_widget_radiobutton.h

  Summary:
    

  Description:
    This module implements radio button widget functions.
*******************************************************************************/

/** \file legato_widget_radiobutton.h
 * @brief Radiobutton functions and definitions.
 *
 * @details This module implements scroll bar widget functions.
 */

#ifndef LEGATO_RADIOBUTTON_H
#define LEGATO_RADIOBUTTON_H

#include "gfx/legato/common/legato_common.h"

#if LE_RADIOBUTTON_WIDGET_ENABLED == 1

#include "gfx/legato/image/legato_image.h"
#include "gfx/legato/widget/legato_widget.h"
#include "gfx/legato/widget/radiobutton/legato_radiobutton_group.h"
#include "gfx/legato/string/legato_string.h"

typedef struct leRadioButtonWidget leRadioButtonWidget;
typedef struct leRadioButtonGroup leRadioButtonGroup;

// *****************************************************************************
/* Function Pointer:
    leRadioButtonWidget_SelectedEvent

  Summary:
    Radio button selected function callback type
*/
/**
 * @brief Used to define a select event callback function.
 * @details .
 */
typedef void (*leRadioButtonWidget_SelectedEvent)(leRadioButtonWidget*);

// *****************************************************************************
/* Function Pointer:
    leRadioButtonWidget_DeselectedEvent

  Summary:
    Radio button deselected function callback type
*/
/**
 * @brief Used to define a deselect event callback function.
 * @details .
 */
typedef void (*leRadioButtonWidget_DeselectedEvent)(leRadioButtonWidget*);

// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

/* internal use only */
/**
  * @cond INTERNAL
  *
  */typedef struct leRadioButtonWidget leRadioButtonWidget;

#define LE_RADIOBUTTONWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    leRadioButtonGroup* (*getGroup)(const THIS_TYPE* _this); \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    leBool              (*getSelected)(const THIS_TYPE* _this); \
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
    leResult            (*setSelected)(THIS_TYPE* _this); \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    void                (*select)(THIS_TYPE* _this); \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    void                (*deselect)(THIS_TYPE* _this); \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    leString*           (*getString)(const THIS_TYPE* _this); \
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
    leResult            (*setString)(THIS_TYPE* _this, const leString* str); \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    leImage*            (*getSelectedImage)(const THIS_TYPE* _this); \
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
    leResult            (*setSelectedImage)(THIS_TYPE* _this, const leImage* img); \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    leImage*            (*getUnselectedImage)(const THIS_TYPE* _this); \
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
    leResult            (*setUnselectedImage)(THIS_TYPE* _this, const leImage* img); \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    leRelativePosition  (*getImagePosition)(const THIS_TYPE* _this); \
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
    leResult            (*setImagePosition)(THIS_TYPE* _this, leRelativePosition pos); \
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
    uint32_t            (*getImageMargin)(const THIS_TYPE* _this); \
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
    leResult            (*setImageMargin)(THIS_TYPE* _this, uint32_t mg); \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    leRadioButtonWidget_SelectedEvent (*getSelectedEventCallback)(const THIS_TYPE* _this); \
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
    leResult            (*setSelectedEventCallback)(THIS_TYPE* _this, leRadioButtonWidget_SelectedEvent cb); \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    leRadioButtonWidget_DeselectedEvent (*getDeselectedEventCallback)(const THIS_TYPE* _this); \
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
    leResult            (*setDeselectedEventCallback)(THIS_TYPE* _this, leRadioButtonWidget_DeselectedEvent cb); \
    /**
     * @brief Get title string.
     * @details Returns the title string from  <span style="color: #820a32"><em>wgt</em></span>.
     * @remark This is a Virtual Member Function
     * @code
     * leWindowWidget* wgt;
     * leString * title = wgt->fn->getTitleHeight(wgt);
     * @endcode
     * @param param1 wgt is the widget to query
     * @return returns uint32_t.
     */
    uint32_t            (*getCircleButtonSize)(const THIS_TYPE* _this); \
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
    leResult            (*setCircleButtonSize)(THIS_TYPE* _this, uint32_t sz); \
    
typedef struct leRadioButtonWidgetVTable
{
	LE_RADIOBUTTONWIDGET_VTABLE(leRadioButtonWidget)
} leRadioButtonWidgetVTable; 

    /**
      * @endcond
      *
      */

// *****************************************************************************
/* Enumeration:
    leRadioButtonWidget

  Summary:
    Implementation of a radio button widget struct

  Description:
    A radio button is similar to a checkbox widget in that it has an on and
    off state.  It is further capable of being added to a radio button group.
    This group provides a mutually exclusive selection capability so that
    only one radio button may be selected at any one time.

  Remarks:
    None.
*/
/**
 * @brief This struct represents a radio button widget.
 * @details A radio button is similar to a checkbox widget in that it has an on
 * and off state.  It is further capable of being added to a radio button group. This
 * group provides a mutually exclusive selection capability so that only one
 * radio button may be selected at any one time.
 */
typedef struct leRadioButtonWidget
{
    leWidget widget; // widget base class

    const leRadioButtonWidgetVTable* fn;

    leBool selected; // indicates if the radio button is selected

    const leString* string; // radio button text

    const leImage* selectedImage; // button custom selected image
    const leImage* unselectedImage; // buton custom unselected image
    
    leRelativePosition imagePosition; // image icon relative position
    
    uint32_t imageMargin; // image margin
    uint32_t circleButtonSize; // size of radio circle button in pixels

    leRadioButtonWidget_SelectedEvent selectedEvent; // button selected event callback
    leRadioButtonWidget_DeselectedEvent deselectedEvent; // button deselected event callback

    leRadioButtonGroup* group; // radio button group
} leRadioButtonWidget;


// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    leRadioButtonWidget* leRadioButtonWidget_New()

  Summary:
    Allocates memory for a new widget of this type.  The application is
    responsible for the managment of this memory until the widget is added to
    a widget tree.

  Description:
    

  Parameters:
    
  Returns:
    leRadioButtonWidget*
    
  Remarks:
    Use leWidget_Delete() to free this pointer.
*/
/**
 * @brief Create widget.
 * @details Creates a new leRadioButtonWidget and allocates memory for the widget through the
 * current active context.  Application is responsible for managing the widget
 * pointer until the widget is added to a widget tree.
 * @remark use leWidget_Delete() to free this pointer.
 * @code
 * leRadioButtonWidget* wgt = leRadioButtonWidget_New();
 * @endcode
 * @return a widget object pointer.
 */
LIB_EXPORT leRadioButtonWidget* leRadioButtonWidget_New();

/**
 * @brief Initialize widget.
 * @details Initializes the leRadioButtonWidget <span class="param">wgt</span>.
 * @code
 * leRadioButtonWidget* wgt;
 * leRadioButtonWidget_Constructor(wgt);
 * @endcode
 * @param wgt is the widget to initialize
 * @return void.
 */
LIB_EXPORT void leRadioButtonWidget_Constructor(leRadioButtonWidget* wgt);

// *****************************************************************************
/* Virtual Member Function:
    leRadioButtonGroup* getGroup(const leRadioButtonWidget* _this)

  Summary:
     Gets the button's group pointer

  Description:
     Gets the button's group pointer

  Parameters:
    const leRadioButtonWidget* _this - The radio button widget to operate on

  Remarks:
    Usage - _this->fn->getGroup(_this);

  Returns:
    leRadioButtonGroup* - the radio button group
*/

// *****************************************************************************
/* Virtual Member Function:
    leBool getSelected(const leRadioButtonWidget* _this)

  Summary:
     Gets the button's selection state

  Description:
     Gets the button's selection state

  Parameters:
    const leRadioButtonWidget* _this - The radio button widget to operate on

  Remarks:
    Usage - _this->fn->getSelected(_this);

  Returns:
    leBool - the selected state
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setSelected(leRadioButtonWidget* _this)

  Summary:
     Selects the button

  Description:
     Selects the button

  Parameters:
    leRadioButtonWidget* _this - The radio button widget to operate on

  Remarks:
    Usage - _this->fn->setSelected(_this);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    void select(leRadioButtonWidget* _this)

  Summary:
     internal use only
*/

// *****************************************************************************
/* Virtual Member Function:
    void deselect(leRadioButtonWidget* _this)

  Summary:
     internal use only
*/

// *****************************************************************************
/* Virtual Member Function:
    leString* getString(const leRadioButtonWidget* _this)

  Summary:
     Gets the text string pointer

  Description:
     Gets the text string pointer

  Parameters:
    const leRadioButtonWidget* _this - The radio button widget to operate on

  Remarks:
    Usage - _this->fn->getString(_this);

  Returns:
    leString* - the string pointer
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setString(leRadioButtonWidget* _this,
                       const leString* str)

  Summary:
     Sets the text string pointer

  Description:
     Sets the text string pointer

  Parameters:
    leRadioButtonWidget* _this - The radio button widget to operate on
    const leString* str - the string pointer

  Remarks:
    Usage - _this->fn->setString(_this, str);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leImage* getSelectedImage(const leRadioButtonWidget* _this)

  Summary:
     Gets the selected image pointer

  Description:
     Gets the selected image pointer

  Parameters:
    const leRadioButtonWidget* _this - The radio button widget to operate on

  Remarks:
    Usage - _this->fn->getSelectedImage(_this);

  Returns:
    leImage* - the image pointer
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setSelectedImage(leRadioButtonWidget* _this,
                              const leImage* img)

  Summary:
     Sets the selected image pointer

  Description:
     Sets the selected image pointer

  Parameters:
    leRadioButtonWidget* _this - The radio button widget to operate on
    const leImage* img - the image pointer

  Remarks:
    Usage - _this->fn->setSelectedImage(_this, img);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leImage* getUnselectedImage(const leRadioButtonWidget* _this)

  Summary:
     Gets the unselected image pointer

  Description:
     Gets the unselected image pointer

  Parameters:
    const leRadioButtonWidget* _this - The radio button widget to operate on

  Remarks:
    Usage - _this->fn->getUnselectedImage(_this);

  Returns:
    leImage* - the image pointer
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setUnselectedImage(leRadioButtonWidget* _this,
                                const leImage* img)

  Summary:
     Sets the unselected image pointer

  Description:
     Sets the unselected image pointer

  Parameters:
    leRadioButtonWidget* _this - The radio button widget to operate on
    const leImage* img - the image pointer

  Remarks:
    Usage - _this->fn->setUnselectedImage(_this, img);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leRelativePosition getImagePosition(const leRadioButtonWidget* _this)

  Summary:
     Gets the image position

  Description:
     Gets the image position

  Parameters:
    const leRadioButtonWidget* _this - The radio button widget to operate on

  Remarks:
    Usage - _this->fn->getImagePosition(_this);

  Returns:
    leRelativePosition - the position
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setImagePosition(leRadioButtonWidget* _this,
                              leRelativePosition pos)

  Summary:
     Sets the image position

  Description:
     Sets the image position

  Parameters:
    leRadioButtonWidget* _this - The radio button widget to operate on
    leRelativePosition pos - the position value

  Remarks:
    Usage - _this->fn->setImagePosition(_this, pos);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    uint32_t getImageMargin(const leRadioButtonWidget* _this)

  Summary:
     Gets the image margin

  Description:
     Gets the image margin

  Parameters:
    const leRadioButtonWidget* _this - The radio button widget to operate on

  Remarks:
    Usage - _this->fn->getImageMargin(_this);

  Returns:
    uint32_t - the margin value
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setImageMargin(leRadioButtonWidget* _this,
                            uint32_t mg)

  Summary:
     Sets the image margin

  Description:
     Sets the image margin

  Parameters:
    leRadioButtonWidget* _this - The radio button widget to operate on
    uint32_t mg - the margin value

  Remarks:
    Usage - _this->fn->setImageMargin(_this, mg);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    uint32_t getCircleButtonSize(const leRadioButtonWidget* _this)

  Summary:
     Gets the circle button size

  Description:
     Gets the circle button size

  Parameters:
    const leRadioButtonWidget* _this - The radio button widget to operate on

  Remarks:
    Usage - _this->fn->getCircleButtonSize(_this);

  Returns:
    uint32_t - the circle button size
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult setCircleButtonSize(leRadioButtonWidget* _this,
                                 uint32_t sz)

  Summary:
     Sets the circle button size

  Description:
     Sets the circle button size

  Parameters:
    leRadioButtonWidget* _this - The radio button widget to operate on
    uint32_t sz - the size value

  Remarks:
    Usage - _this->fn->setCircleButtonSize(_this, sz);

  Returns:
    leResult - the result of the operation
*/

/**
 * @brief Get deselected event callback pointer.
 * @details Gets the deselected event callback pointer using <span class="param">_this</span>.
 * @code
 * leRadioButtonWidget* _this;
 * leRadioButtonWidget_SelectedEvent cb = _this->fn->getDeselectedEventCallback(_this);
 * @endcode
 * @param _this is the widget to modify
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leRadioButtonWidget_SelectedEvent getSelectedEventCallback
                                        (const leRadioButtonWidget* _this);

/**
 * @brief Set deselected event callback pointer.
 * @details Sets the deselected event callback pointer to <span class="param">cb</span>
 * using <span class="param">_this</span>.
 * @code
 * leRadioButtonWidget* _this;
 * leRadioButtonWidget_SelectedEvent cb;
 * leResult res = _this->fn->setSelectedEventCallback(_this, cb);
 * @endcode
 * @param _this is the widget to modify
 * @param cb is the callback func
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setSelectedEventCallback(leRadioButtonWidget* _this,
                                            leRadioButtonWidget_SelectedEvent cb);

/**
 * @brief Get deselected event callback pointer.
 * @details Gets the deselected event callback pointer using <span class="param">_this</span>.
 * @code
 * leRadioButtonWidget* _this;
 * leRadioButtonWidget_DeselectedEvent cb = _this->fn->getDeselectedEventCallback(_this);
 * @endcode
 * @param _this is the widget to modify
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leRadioButtonWidget_DeselectedEvent getDeselectedEventCallback
                                        (const leRadioButtonWidget* _this);

/**
 * @brief Set deselected event callback pointer.
 * @details Sets the deselected event callback pointer to <span class="param">cb</span>
 * using <span class="param">_this</span>.
 * @code
 * leRadioButtonWidget* _this;
 * leRadioButtonWidget_DeselectedEvent cb;
 * leResult res = _this->fn->setDeselectedEventCallback(_this, cb);
 * @endcode
 * @param _this is the widget to modify
 * @param cb is the callback func
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setDeselectedEventCallback(leRadioButtonWidget* _this,
                                            leRadioButtonWidget_DeselectedEvent cb);

#undef THIS_TYPE
#endif

#endif // LE_RADIOBUTTON_WIDGET_ENABLED
#endif /* LEGATO_RADIOBUTTON_H */
