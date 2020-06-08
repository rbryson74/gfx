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
    legato_widget_circular_gauge.h

  Summary:


  Description:
    This module implements circular gauge drawing widget functions.
*******************************************************************************/
/** \file legato_widget_circular_gauge.h
 * @brief Circular guage widget functions and definitions.
 *
 * @details This module implements circular gauge drawing widget functions.
 */

#ifndef LEGATO_WIDGET_CIRCULAR_GAUGE_H
#define LEGATO_WIDGET_CIRCULAR_GAUGE_H

#include "gfx/legato/common/legato_common.h"

#if LE_CIRCULARGAUGE_WIDGET_ENABLED == 1

#include "gfx/legato/core/legato_scheme.h"
#include "gfx/legato/datastructure/legato_array.h"
#include "gfx/legato/string/legato_dynamicstring.h"
#include "gfx/legato/widget/legato_widget.h"


// *****************************************************************************
// *****************************************************************************
// Section: Data Types and Constants
// *****************************************************************************
// *****************************************************************************

typedef struct leCircularGaugeWidget leCircularGaugeWidget;


// *****************************************************************************
/* Structure:
    leCircularGaugeWidgetDir

  Summary:
    Direction of the gauge

  Description:
    Direction of the gauge

  Remarks:
    None.
*/
/**
  * @brief This enum represents direction of the guage.
  * @details A direction of a guage is used to define possible label positions.
  */
typedef enum leCircularGaugeWidgetLabelPosition
{
    CIRCULAR_GAUGE_LABEL_OUTSIDE,
    CIRCULAR_GAUGE_LABEL_INSIDE,
} leCircularGaugeWidgetLabelPosition;

// *****************************************************************************
/* Structure:
    leCircularGaugeWidgetArcType

  Summary:
    Type of arc

  Description:
    Type of arc

  Remarks:
    None.
*/
/**
  * @brief This enum represents gauge widget arc type.
  * @details A widget arc is used to define possible arc types.
  */
typedef enum leCircularGaugeWidgetArcType
{
    ANGLE_ARC,
    VALUE_ARC,
} leCircularGaugeWidgetArcType;

// *****************************************************************************
/* Function Pointer:
    leCircularGaugeWidget_ValueChangedEvent

  Summary:
    Value changed event function callback type
*/
/**
 * @brief This function represents a value changed event callback.
 * @details Value change event callback is used indicate a value change.
 */
typedef void (*leCircularGaugeWidget_ValueChangedEvent)(leCircularGaugeWidget*,
                                                        int32_t value);


/* internal use only */
/**
  * @cond INTERNAL
  *
  */
#define LE_CIRCULARGAUGEWIDGET_VTABLE(THIS_TYPE) \
    LE_WIDGET_VTABLE(THIS_TYPE) \
    \
    uint32_t                 (*getRadius)(const THIS_TYPE* _this); \
    leResult                 (*setRadius)(THIS_TYPE* _this, uint32_t rad); \
    int32_t                  (*getStartAngle)(const THIS_TYPE* _this); \
    leResult                 (*setStartAngle)(THIS_TYPE* _this, int32_t ang); \
    int32_t                  (*getCenterAngle)(const THIS_TYPE* _this); \
    leResult                 (*setCenterAngle)(THIS_TYPE* _this, int32_t ang); \
    leResult                 (*addValueArc)(THIS_TYPE* _this, int32_t startVal, int32_t endVal, uint32_t rad, uint32_t thk, leScheme* schm); \
    leResult                 (*addAngularArc)(THIS_TYPE* _this, int32_t startAng, int32_t endAng, uint32_t rad, uint32_t thk, leScheme* schm); \
    leResult                 (*deleteArcs)(THIS_TYPE* _this); \
    leResult                 (*addMinorTicks)(THIS_TYPE* _this, int32_t startVal, int32_t endVal, uint32_t rad, uint32_t len, uint32_t interval, leScheme* schm); \
    leResult                 (*deleteMinorTicks)(THIS_TYPE* _this); \
    leResult                 (*addMinorTickLabels)(THIS_TYPE* _this, int32_t startVal, int32_t endVal, uint32_t rad, leCircularGaugeWidgetLabelPosition pos, uint32_t interval, leScheme* schm); \
    leResult                 (*deleteMinorTickLabels)(THIS_TYPE* _this); \
    int32_t                  (*getValue)(const THIS_TYPE* _this); \
    leResult                 (*setValue)(THIS_TYPE* _this, int32_t val); \
    int32_t                  (*getStartValue)(const THIS_TYPE* _this); \
    leResult                 (*setStartValue)(THIS_TYPE* _this, int32_t val); \
    int32_t                  (*getEndValue)(const THIS_TYPE* _this); \
    leResult                 (*setEndValue)(THIS_TYPE* _this, int32_t val); \
    leBool                   (*getTicksVisible)(const THIS_TYPE* _this); \
    leResult                 (*setTicksVisible)(THIS_TYPE* _this, leBool vis); \
    int32_t                  (*getTickValue)(const THIS_TYPE* _this); \
    leResult                 (*setTickValue)(THIS_TYPE* _this, int32_t val); \
    uint32_t                 (*getTickLength)(const THIS_TYPE* _this); \
    leResult                 (*setTickLength)(THIS_TYPE* _this, uint32_t len); \
    leBool                   (*getTickLabelsVisible)(const THIS_TYPE* _this); \
    leResult                 (*setTickLabelsVisible)(THIS_TYPE* _this, leBool vis); \
    leBool                   (*getHandVisible)(const THIS_TYPE* _this); \
    leResult                 (*setHandVisible)(THIS_TYPE* _this, leBool vis); \
    uint32_t                 (*getHandRadius)(const THIS_TYPE* _this); \
    leResult                 (*setHandRadius)(THIS_TYPE* _this, uint32_t rad); \
    leBool                   (*getCenterCircleVisible)(const THIS_TYPE* _this); \
    leResult                 (*setCenterCircleVisible)(THIS_TYPE* _this, leBool vis); \
    uint32_t                 (*getCenterCircleRadius)(const THIS_TYPE* _this); \
    leResult                 (*setCenterCircleRadius)(THIS_TYPE* _this, uint32_t rad); \
    uint32_t                 (*getCenterCircleThickness)(const THIS_TYPE* _this); \
    leResult                 (*setCenterCircleThickness)(THIS_TYPE* _this, uint32_t thk); \
    leResult                 (*setTickLabelFont)(THIS_TYPE* _this, const leFont* font); \
    leResult                 (*setValueChangedEventCallback)(THIS_TYPE* _this, leCircularGaugeWidget_ValueChangedEvent cb); \

typedef struct leCircularGaugeWidgetVTable
{
	LE_CIRCULARGAUGEWIDGET_VTABLE(leCircularGaugeWidget)
} leCircularGaugeWidgetVTable; 

/**
  * @endcond
  *
  */

// *****************************************************************************
/* Structure:
    leCircularGaugeWidget

  Summary:
    Implementation of a circular gauge widget.

  Description:
    A circular gauge widget draws a circular gauge of the specified properties
    inside the widget bounds.  All coordinates are expressed in local widget space.

  Remarks:
    None.
*/
/**
 * @brief This struct represents a circular gauge.
 * @details A circular gauge widget draws a circular gauge of the specified
 * properties inside the widget bounds.  All coordinates are expressed in local
 * widget space.
 */
typedef struct leCircularGaugeWidget
{
    leWidget widget; // base widget header

    const leCircularGaugeWidgetVTable* fn;

    //Widget properties
    int32_t value;
    int32_t startValue;
    int32_t endValue;
    uint32_t radius; // the radius of the circular gauge
    uint32_t startAngle; //the start angle of the outer arc
    int32_t centerAngle; //the center angle of the outer arc
    leRotationDirection dir; //the turn direction of the gauge

    //Tick properties
    leBool ticksVisible; // are ticks visible
    uint32_t tickLength; //length of ticks (towards center)
    int32_t tickValue; // tick value (delta)

    //Tick label properties
    leBool tickLabelsVisible; // are tick labels visible
    const leFont* ticksLabelFont; // ticks label font

    //hand properties
    leBool handVisible;
    uint32_t handRadius;
    leBool centerCircleVisible;
    uint32_t centerCircleRadius;
    uint32_t centerCircleThickness;

    //Advanced config arrays
    leArray arcsArray; //ArcsArray list
    leArray ticksArray; //ArcsArray list
    leArray labelsArray; //ArcsArray list


    leCircularGaugeWidget_ValueChangedEvent cb; //value changed event callback

} leCircularGaugeWidget;

// *****************************************************************************
/* Structure:
    leCircularGaugeArc

  Summary:
    Internal structure for the arcs in the circular gauge widget

  Description:
    Describs the arc instances in the circular gauge widget

  Remarks:
    None.
*/
/**
  * @brief This struct represents circular gauge widget.
  * @details A circular gauge widget is used to describe the
  * arc instances in the circular gauge widget.
  */
typedef struct leCircularGaugeArc
{
    leCircularGaugeWidgetArcType type;
    int32_t startAngle;
    int32_t endAngle;
    int32_t startValue;
    int32_t endValue;
    uint32_t radius;
    uint32_t thickness;
    leScheme* scheme;
} leCircularGaugeArc;

// *****************************************************************************
/* Structure:
    leCircularGaugeTick

  Summary:
    Tick object for the circular gauge

  Description:
    Contains properties of the ticks in the gauge

  Remarks:
    None.
*/
/**
  * @brief This struct represents circular gauge tick.
  * @details A circular gauge tick is used to
  * contain properties of the ticks in the gauge.
  */
typedef struct leCircularGaugeTick
{
    int32_t startValue;
    int32_t endValue;
    uint32_t interval;
    uint32_t radius;
    uint32_t length;
    leScheme* scheme;
} leCircularGaugeTick;

// *****************************************************************************
/* Structure:
    typedef struct leCircularGaugeLabel


  Summary:
    Label object for the circular gauge

  Description:
    Contains properties of the labels in the gauge

  Remarks:
    None.
*/
/**
  * @brief This struct represents circular gauge label.
  * @details A circular gauge tick is used to
  * contain properties of the labels in the gauge.
  */
typedef struct leCircularGaugeLabel
{
    int32_t startValue;
    int32_t endValue;
    uint32_t interval;
    uint32_t radius;
    leCircularGaugeWidgetLabelPosition position;
    leScheme* scheme;
} leCircularGaugeLabel;

// *****************************************************************************
// *****************************************************************************
// Section: Routines
// *****************************************************************************
// *****************************************************************************

/**
 * @brief Create widget.
 * @details Creates a new leCircularGaugeWidget and allocates memory for the widget through the
 * current active context.  Application is responsible for managing the widget
 * pointer until the widget is added to a widget tree.
 * @remark use leWidget_Delete() to free this pointer.
 * @code
 * leCircularGaugeWidget* wgt = leCircularGaugeWidget_New();
 * @endcode
 * @return a widget object pointer.
 */
LIB_EXPORT leCircularGaugeWidget* leCircularGaugeWidget_New();


/**
 * @brief Initialize widget.
 * @details Initializes the leCircularGaugeWidget <span class="param">wgt</span>.
 * @code
 * leCircularGaugeWidget* wgt;
 * leCircularGaugeWidget_Constructor(wgt);
 * @endcode
 * @param wgt is the widget to initialize
 * @return void.
 */
LIB_EXPORT void leCircularGaugeWidget_Constructor(leCircularGaugeWidget* gauge);


#ifdef _DOXYGEN_
#define THIS_TYPE struct leWidget

// *****************************************************************************
/**
 * @brief Get radius.
 * @details Gets the radius using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t angle = _this->fn->getRadius(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the radius.
 */
virtual uint32_t getRadius(const leCircularGaugeWidget* _this);


// *****************************************************************************
/* Virtual Member Function:
    leResult setRadius(leCircularGaugeWidget* _this,
                       uint32_t rad)

  Summary:
     Sets the radius

  Description:
     Sets the radius

  Parameters:
    leCircularGaugeWidget* _this - The gauge to operate on
    uint32_t rad - the radius value

  Remarks:
    Usage - _this->fn->setRadius(_this, rad);

  Returns:
    leResult - the result of the operation
*/
/**
 * @brief Set radius.
 * @details Sets the radius to <span class="param">ang</span>
 * using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * uint32_t rad;
 * leResult res = _this->fn->setStartAngle(_this, rad);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param rad is the start angle.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setRadius(leCircularGaugeWidget* _this,
                           uint32_t rad);

// *****************************************************************************
/**
 * @brief Get start angle.
 * @details Gets the start angle using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t angle = _this->fn->getStartAngle(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the start angle.
 */
virtual int32_t getStartAngle(const leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Set start angle.
 * @details Sets the start angle to <span class="param">ang</span>
 * using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t ang;
 * leResult res = _this->fn->setStartAngle(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param ang is the start angle.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setStartAngle(leCircularGaugeWidget* _this,
                               int32_t ang);

// *****************************************************************************
/**
 * @brief Get center angle.
 * @details Gets the center angle using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t angle = _this->fn->getCenterAngle(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the center angle.
 */
virtual int32_t getCenterAngle(const leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Set center angle.
 * @details Sets the center angle to
 * <span class="param">ang</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t ang;
 * leResult res = _this->fn->setStartAngle(_this, ang);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param ang is the center angle.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setCenterAngle(leCircularGaugeWidget* _this,
                                int32_t ang);


// *****************************************************************************
/* Virtual Member Function:
    leResult addValueArc(leCircularGaugeWidget* _this,
                         int32_t startVal,
                         int32_t endVal,
                         uint32_t rad,
                         uint32_t thk,
                         leScheme* schm)

  Summary:
     Adds a value arc to the gauge

  Description:
     Adds a value arc to the gauge

  Parameters:
    leCircularGaugeWidget* _this - The gauge to operate on
    int32_t startVal - the start value
    int32_t endVal - the end value
    uint32_t rad - the radius value
    uint32_t thk - the thickness value
    leScheme* schm - the scheme pointer

  Remarks:
    Usage - _this->fn->addValueArc(_this, startVal, endVal, rad, thk, schm);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult addAngularArc(leCircularGaugeWidget* _this,
                           int32_t startAng,
                           int32_t endAng,
                           uint32_t rad,
                           uint32_t thk,
                           leScheme* schm)

  Summary:
     Adds an angular arc to the gauge

  Description:
     Adds an angular arc to the gauge

  Parameters:
    leCircularGaugeWidget* _this - The gauge to operate on
    int32_t startAng - the start angle value
    int32_t endAng - the end angle value
    uint32_t rad - the radius value
    uint32_t thk - the thickness value
    leScheme* schm - the scheme pointer

  Remarks:
    Usage - _this->fn->addAngularArc(_this, startAng, endAng, rad, thk, schm);

  Returns:
    leResult - the result of the operation
*/

// *****************************************************************************
/* Virtual Member Function:
    leResult deleteArcs(leCircularGaugeWidget* _this)

  Summary:
     Deletes all arcs from the gauge

  Description:
     Deletes all arcs from the gauge

  Parameters:
    leCircularGaugeWidget* _this - The gauge to operate on

  Remarks:
    Usage - _this->fn->deleteArcs(_this);

  Returns:
    leResult - the result of the operation
*/
/**
 * @brief Delete arcs from the gauge.
 * @details Deletes all arcs from the gauge using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t ang;
 * leResult res = _this->fn->setCenterAngle(_this, ang);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param ang is the center angle.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setCenterAngle(leCircularGaugeWidget* _this,
                                int32_t ang);

// *****************************************************************************
/* Virtual Member Function:
    leResult addMinorTicks(leCircularGaugeWidget* _this,
                           int32_t startVal,
                           int32_t endVal,
                           uint32_t rad,
                           uint32_t len,
                           uint32_t interval,
                           leScheme* schm)

  Summary:
     Adds a series of minor ticks

  Description:
     Adds a series of minor ticks

  Parameters:
    leCircularGaugeWidget* _this - The gauge to operate on
    int32_t startVal - the start value
    int32_t endVal - the end value
    uint32_t rad - the radius value
    uint32_t len - the length value
    uint32_t interval - the value
    leScheme* schm - the scheme pointer

  Remarks:
    Usage - _this->fn->addMinorTicks(_this, startVal, endVal, rad, len, interval, schm);

  Returns:
    leResult - the result of the operation
*/
* @brief Adds series of minor ticks.
* @details Adds a series of minor ticks by
* <span class="param">val</span> using <span class="param">_this</span>.
* @code
* const leCircularGaugeWidget* _this;
* int32_t val;
* int32_t startVal;
* int32_t endVal;
* uint32_t rad;
* leCircularGaugeWidgetLabelPosition pos;
* uint32_t interval;
* leScheme* schm;
* leResult res = _this->fn->addMinorTicks(_this, startVal, endVal, rad, pos, interval, schm);
* @endcode
* @param _this is the widget pointer to query.
* @param val is the label to add.
* @param startVal the start value
* @param endVal the end value.
* @param rad the radius value.
* @param len  position.
* @param interval the value.
* @param schm the scheme pointer.
* @returns LE_SUCCESS if set, otherwise LE_FAILURE.
*/
virtual leResult addMinorTicks(leCircularGaugeWidget* _this,
                               int32_t startVal,
                               int32_t endVal,
                               uint32_t rad,
                               uint32_t len,
                               uint32_t interval,
                               leScheme* schm);

// *****************************************************************************
/* Virtual Member Function:
    leResult deleteMinorTicks(leCircularGaugeWidget* _this)

  Summary:
     Deletes all minor ticks

  Description:
     Deletes all minor ticks

  Parameters:
    leCircularGaugeWidget* _this - The gauge to operate on

  Remarks:
    Usage - _this->fn->deleteMinorTicks(_this);

  Returns:
    leResult - the result of the operation
*/
/**
 * @brief Delete all minor ticks.
 * @details Deletes all minor ticks using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leResult res = _this->fn->deleteMinorTicks(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult deleteMinorTicks(leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Adds minor tick labels.
 * @details Adds minor tick labels by
 * <span class="param">val</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t val;
 * int32_t startVal;
 * int32_t endVal;
 * uint32_t rad;
 * leCircularGaugeWidgetLabelPosition pos;
 * uint32_t interval;
 * leScheme* schm;
 * leResult res = _this->fn->addMinorTickLabels(_this, startVal, endVal, rad, pos, interval, schm);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param val is the label to add.
 * @param startVal the start value
 * @param endVal the end value.
 * @param rad the radius value.
 * @param pos  position.
 * @param interval the value.
 * @param schm the scheme pointer.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult addMinorTickLabels(leCircularGaugeWidget* _this,
                                    int32_t startVal,
                                    int32_t endVal,
                                    uint32_t rad,
                                    leCircularGaugeWidgetLabelPosition pos,
                                    uint32_t interval,
                                    leScheme* schm);


// *****************************************************************************
/**
 * @brief Delete all minor tick labels.
 * @details Deletes all minor tick labels by
 * <span class="param">val</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t val;
 * leResult res = _this->fn->deleteMinorTickLabels(_this, val);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param val is the label to value .
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult deleteMinorTickLabels(leCircularGaugeWidget* _this,
                          int32_t val);

// *****************************************************************************
/**
 * @brief Get gauge value.
 * @details Gets the gauge value using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t gauge = _this->fn->getValue(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the gauge value.
 */
virtual int32_t getValue(const leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Set gauge value.
 * @details Sets the gauge value to
 * <span class="param">val</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t val;
 * leResult res = _this->fn->setValue(_this, val);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param val is the gauge value.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setValue(leCircularGaugeWidget* _this,
                          int32_t val);


// *****************************************************************************
/**
 * @brief Get start value.
 * @details Gets the start value using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t start = _this->fn->getStartValue(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the start value.
 */
virtual int32_t getStartValue(const leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Set start value.
 * @details Sets the start value to
 * <span class="param">val</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t val;
 * leResult res = _this->fn->setStartValue(_this, val);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param val is the gauge value.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setStartValue(leCircularGaugeWidget* _this,
                               int32_t val);

// *****************************************************************************
/**
 * @brief Get end value.
 * @details Gets the end value using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t end = _this->fn->getEndValue(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the end value.
 */
virtual int32_t getEndValue(const leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Set end value.
 * @details Sets the end value to
 * <span class="param">val</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t val;
 * leResult res = _this->fn->setEndValue(_this, val);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param val is the end value.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setEndValue(leCircularGaugeWidget* _this,
                               int32_t val);


// *****************************************************************************
/**
 * @brief Get ticks visible setting.
 * @details Gets the ticks visible setting using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leBool visible = _this->fn->getTicksVisible(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the ticks visible setting.
 */
virtual leBool getTicksVisible(const leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Set ticks visible setting.
 * @details Sets the ticks visible setting to
 * <span class="param">val</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leBool vis;
 * leResult res = _this->fn->setTicksVisible(_this, vis);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param vis is the ticks visible settinge.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setTicksVisible(leCircularGaugeWidget* _this,
                                 leBool vis);


// *****************************************************************************
/**
 * @brief Get current tick value.
 * @details Gets the current tick value using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t tick = _this->fn->getTickValue(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the tick value.
 */
virtual int32_t getTickValue(const leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Set tick value.
 * @details Sets the tick value to
 * <span class="param">val</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t val;
 * leResult res = _this->fn->setTicksVisible(_this, val);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param val is the tick value.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setTickValue(leCircularGaugeWidget* _this,
                              int32_t val);



// *****************************************************************************
/**
 * @brief Get current tick length.
 * @details Gets the current tick length using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * uint32_t len = _this->fn->getTickLength(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the tick length.
 */
virtual uint32_t getTickLength(const leCircularGaugeWidget* _this);

// *****************************************************************************
/**
 * @brief Set tick length.
 * @details Sets the tick length to
 * <span class="param">val</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * int32_t val;
 * leResult res = _this->fn->setTicksVisible(_this, val);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param val is the tick length.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setTickValue(leCircularGaugeWidget* _this,
                              int32_t val);


// *****************************************************************************
/**
 * @brief Get tick labels visibility setting.
 * @details Gets the tick labels visibility setting using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leBool visible = _this->fn->getHandVisible(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the tick labels visibility setting.
 */
virtual leBool getHandVisible(const leCircularGaugeWidget* _this);

// *****************************************************************************
/**
 * @brief Set visibility setting for the tick labels.
 * @details Sets the visibility setting for the tick labels to
 * <span class="param">vis</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leBool vis;
 * leResult res = _this->fn->setTicksVisible(_this, vis);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param vis is the visibility setting for the tick labels.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setTickLabelsVisible(leCircularGaugeWidget* _this,
                                      leBool vis);

// *****************************************************************************
/**
 * @brief Get hand visibility setting.
 * @details Gets the visibility setting using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leBool visible = _this->fn->getHandRadius(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the visibility setting.
 */
virtual leBool getHandVisible(const leCircularGaugeWidget* _this);

// *****************************************************************************
/**
 * @brief Set hand visibility setting for the tick labels.
 * @details Sets the hand visibility setting to
 * <span class="param">vis</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leBool vis;
 * leResult res = _this->fn->setHandVisible(_this, vis);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param vis is the visibility setting for the tick labels.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setHandVisible(leCircularGaugeWidget* _this,
                                      leBool vis);

// *****************************************************************************
/**
 * @brief Get hand radius setting.
 * @details Gets the hand radius using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leBool visible = _this->fn->getHandRadius(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the hand radius.
 */
virtual uint32_t getHandRadius(const leCircularGaugeWidget* _this);

// *****************************************************************************
/**
 * @brief Set hand radius for the tick labels.
 * @details Sets the hand radius to
 * <span class="param">rad</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * uint32_t rad;
 * leResult res = _this->fn->setHandRadius(_this, rad);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param rad is the hand radius.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setHandRadius(leCircularGaugeWidget* _this,
                              uint32_t rad);


// *****************************************************************************
/**
 * @brief Get center circle visibility setting.
 * @details Gets the center circle visibility setting using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leBool visible = _this->fn->getCenterCircleVisible(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the center circle visibility setting.
 */
virtual leBool getCenterCircleVisible(const leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Set center circle visibility setting.
 * @details Sets the center circle visibility setting to
 * <span class="param">vis</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leBool vis;
 * leResult res = _this->fn->setCenterCircleVisible(_this, vis);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param vis is the center circle visibility setting.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setCenterCircleVisible(leCircularGaugeWidget* _this,
                                        leBool vis);

// *****************************************************************************
/**
 * @brief Get center circle radius.
 * @details Gets the center circle radius using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * uint32_t radius = _this->fn->getCenterCircleRadius(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the radius value.
 */
virtual uint32_t getCenterCircleRadius(const leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Set center circle radius.
 * @details Sets the center circle radius to
 * <span class="param">rad</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * uint32_t rad;
 * leResult res = _this->fn->setCenterCircleRadius(_this, rad);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param rad center circle radius.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setCenterCircleRadius(leCircularGaugeWidget* _this,
                                       uint32_t rad);


// *****************************************************************************
/**
 * @brief Get center circle thickness.
 * @details Gets the center circle thickness using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * uint32_t thickness = _this->fn->getCenterCircleThickness(_this);
 * @endcode
 * @param _this is the widget pointer to query.
 * @returns the thickness value.
 */
virtual uint32_t getCenterCircleThickness(const leCircularGaugeWidget* _this);


// *****************************************************************************
/**
 * @brief Set center circle thickness.
 * @details Sets the center circle thickness to
 * <span class="param">rad</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * uint32_t rad;
 * leResult res = _this->fn->setCenterCircleThickness(_this, rad);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param rad center circle thickness.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setCenterCircleThickness(leCircularGaugeWidget* _this,
                                       uint32_t rad);


// *****************************************************************************
/* Virtual Member Function:
    leResult setTickLabelFont(leCircularGaugeWidget* _this,
                              const leFont* font)

  Summary:
     Sets the tick label font

  Description:
     Sets the tick label font

  Parameters:
    leCircularGaugeWidget* _this - The gauge to operate on
    const leFont* font - the font pointer

  Remarks:
    Usage - _this->fn->setTickLabelFont(_this, font);

  Returns:
    leResult - the result of the operation
*/
/**
 * @brief Set tick label font.
 * @details Sets the tick label font to
 * <span class="param">font</span> using <span class="param">_this</span>.
 * @code
 * const leCircularGaugeWidget* _this;
 * leFont* font;
 * leResult res = _this->fn->setCenterCircleThickness(_this, font);
 * @endcode
 * @param _this is the widget pointer to query.
 * @param font the font pointer.
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setTickLabelFont(leCircularGaugeWidget* _this,
                                  const leFont* font);

/**
 * @brief Set value changed callback.
 * @details Sets the value changed callback to <span class="param">cb</span>
 * using <span class="param">_this</span>.
 * @code
 * leCircularGaugeWidget* _this;
 * leCircularGaugeWidget_ValueChangedEvent cb;
 * leResult res = _this->fn->setValueChangedEventCallback(_this, cb);
 * @endcode
 * @param _this is the widget to modify
 * @param cb is the callback func
 * @returns LE_SUCCESS if set, otherwise LE_FAILURE.
 */
virtual leResult setValueChangedEventCallback(leCircularGaugeWidget* _this,
                                              leCircularGaugeWidget_ValueChangedEvent cb);

#undef THIS_TYPE
#endif

#endif // LE_CIRCULARGAUGE_WIDGET_ENABLED
#endif /* LEGATO_WIDGET_CIRCULAR_GAUGE_H */
