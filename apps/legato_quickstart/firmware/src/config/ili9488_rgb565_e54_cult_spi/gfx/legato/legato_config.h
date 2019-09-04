/*******************************************************************************
 Module for Microchip Legato Graphics Library

  Company:
    Microchip Technology Inc.

  File Name:
    legato_config.h

  Summary:
    Autogenerated configuration file for the Legato graphics library.

  Description:
    Autogenerated configuration file for the Legato graphics library.
*******************************************************************************/

#ifndef LE_CONFIG_H
#define LE_CONFIG_H

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

/* export macros for shared libraries */
#ifdef _WIN32
#ifdef LIBRARY
#define LIB_EXPORT __declspec( dllexport )
#else
#define LIB_EXPORT __declspec( dllimport )
#endif
#else
#define LIB_EXPORT
#endif


#define LE_GLOBAL_COLOR_MODE               LE_COLOR_MODE_RGB_565
#define LE_TOUCH_ORIENTATION               90

#define LE_ASSERT_ENABLE                   0

#define LE_PREEMPTION_LEVEL                0
#define LE_STREAMING_ENABLED               0

#if LE_STREAMING_ENABLED == 1
#define LE_ASSET_DECODER_CACHE_SIZE        128
#define LE_ASSET_DECODER_USE_PIXEL_CACHE   0
#define LE_ASSET_DECODER_USE_PALETTE_CACHE 0
#define LE_ASSET_DECODER_USE_MASK_CACHE    0
#define LE_ASSET_DECODER_USE_BLEND_CACHE   0
#define LE_RASTERFONT_GLYPH_CACHE_SIZE     256
#endif

// default Font Support
#define LE_INCLUDE_DEFAULT_1BPP_FONT       0
#define LE_INCLUDE_DEFAULT_8BPP_FONT       0

// widget inclusion
#define LE_ARC_WIDGET_ENABLED              1
#define LE_BARGRAPH_WIDGET_ENABLED         1
#define LE_BUTTON_WIDGET_ENABLED           1
#define LE_CHECKBOX_WIDGET_ENABLED         1
#define LE_CIRCLE_WIDGET_ENABLED           1
#define LE_CIRCULARGAUGE_WIDGET_ENABLED    1
#define LE_CIRCULARSLIDER_WIDGET_ENABLED   1
#define LE_DRAWSURFACE_WIDGET_ENABLED      1
#define LE_GRADIENT_WIDGET_ENABLED         1
#define LE_GROUPBOX_WIDGET_ENABLED         1
#define LE_IMAGE_WIDGET_ENABLED            1
#define LE_IMAGEROTATE_WIDGET_ENABLED      0
#define LE_IMAGESCALE_WIDGET_ENABLED       0
#define LE_IMAGESEQUENCE_WIDGET_ENABLED    1
#define LE_KEYPAD_WIDGET_ENABLED           1
#define LE_LABEL_WIDGET_ENABLED            1
#define LE_LINE_WIDGET_ENABLED             1
#define LE_LINEGRAPH_WIDGET_ENABLED        1
#define LE_LIST_WIDGET_ENABLED             1
#define LE_LISTWHEEL_WIDGET_ENABLED        1
#define LE_PIECHART_WIDGET_ENABLED         1
#define LE_PROGRESSBAR_WIDGET_ENABLED      1
#define LE_RADIALMENU_WIDGET_ENABLED       0
#define LE_RADIOBUTTON_WIDGET_ENABLED      1
#define LE_RECTANGLE_WIDGET_ENABLED        1
#define LE_SCROLLBAR_WIDGET_ENABLED        1
#define LE_SLIDER_WIDGET_ENABLED           1
#define LE_TEXTFIELD_WIDGET_ENABLED        1
#define LE_TOUCHTEST_WIDGET_ENABLED        1
#define LE_WINDOW_WIDGET_ENABLED           1

// memory configuration
#define LE_USE_DEBUG_ALLOCATOR             0
#define LE_MALLOC_ZEROIZE                  0

#if LE_USE_DEBUG_ALLOCATOR == 1
#define LE_USE_ALLOCATION_TRACKING         0
#endif

// variable heap configuration
#define LE_VARIABLEHEAP_DEBUGLEVEL         0
#define LE_VARIABLEHEAP_SIZE               2048
#define LE_VARIABLEHEAP_MINALLOCSIZE       32
#define LE_VARIABLEHEAP_ALIGNMENT          4
#define LE_VARIABLEHEAP_BESTFIT            1

// fixed heap configuration
#define LE_FIXEDHEAP_ENABLE                1
#define LE_FIXEDHEAP_DEBUG                 0
#define LE_FIXEDHEAP_SIZE_16               300
#define LE_FIXEDHEAP_SIZE_32               96
#define LE_FIXEDHEAP_SIZE_64               96
#define LE_FIXEDHEAP_SIZE_128              32
#define LE_FIXEDHEAP_SIZE_196              48
#define LE_FIXEDHEAP_SIZE_256              24

// renderer configuration
//#define LE_VSYNC_STALL

#define LE_LAYER_COUNT                     1

#if LE_LAYER_COUNT <= 0
#error LE_LAYER_COUNT must be greater than or equal to 1
#endif

#define LE_WIDGET_MAX_EVENT_FILTERS        2

// renderer config
#define LE_ALPHA_BLENDING_ENABLED          1
#define LE_SCRATCH_BUFFER_SIZE_KB          16
#define LE_USE_ARC_SCAN_FILL               1
#define LE_ARC_SMOOTH_EDGE                 LE_FALSE


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_CONFIG_H
