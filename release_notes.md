---
title: Release notes
nav_order: 99
---

![Microchip logo](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_logo.png)
![Harmony logo small](https://raw.githubusercontent.com/wiki/Microchip-MPLAB-Harmony/Microchip-MPLAB-Harmony.github.io/images/microchip_mplab_harmony_logo_small.png)

# Microchip MPLAB® Harmony 3 Release Notes

## Graphics Release v3.7.0
### New Features

* **Development kit and demo application support** - The following table provides number of applications available for different development kits

| Development Kits     | Applications |
| ---  | --- |
| [SAM A5D2 Xplained Ultra](https://www.microchip.com/developmenttools/ProductDetails/atsama5d2c-xult)      | [legato_quickstart](./docs/legato/html/LegatoQuickstart.html)  |
| [SAM9X60-EK Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/DT100126)           | [legato_quickstart](./docs/legato/html/LegatoQuickstart.html)  |
| [PIC32MZ DA Curiosity](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME70-XPLD)    | [legato_quickstart](./docs/legato/html/LegatoQuickstart.html), [legato_dashboard](./docs/legato/html/LegatoDashboard.html), [legato_climate_control](./docs/legato/html/LegatoClimateControl.html) |
| [Curiosity PIC32MZ EF 2.0](https://www.microchip.com/Developmenttools/ProductDetails/DM320209)            | [legato_quickstart](./docs/legato/html/LegatoQuickstart.html),  [legato_quickstart_external_resource](./docs/legato/html/LegatoQuickstartExtRes.html), [legato_flash](./docs/legato/html/LegatoFlash.html) |
| [SAM E70 Xplained Ultra](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME70-XPLD)  | [legato_flash](./docs/legato/html/LegatoFlash.html) |


* MH3-23406     Fix hard coded I2C instance in MaxTouch Driver.
* MH3-24597     Image plus widget fails to render image if it is on the application's first screen 
* MH3-28630     SPI Index is not configurable in drv_gfx_disp_intf_spi4 
* MH3-28928 	Harmony3 Graphics Configurator VSYNC/ HSYNC polarity inversed 
* MH3-29965 	Add option for 320x480 screen resolution in Legato Composer new project wizard 
* MH3-30003 	Hard fault issue in using List Widget in Harmony 3 Graphic 
* MH3-30022 	Incorrect error message in MAXTOUCH driver code 
* MH3-30029 	SAM 9x60: Unable to display JPG or PNG images 
* MH3-30055 	Add Timer trigger for DMA-based Parallel 8080 driver for E5x/D5x 
* MH3-30056 	Add asynchronous write mode for the External Controller Driver generator 
* MH3-30077 	Build errors when ALPHA_BLENDING is not enabled 
* MH3-30078 	MHC Error when adding GLCD driver component 
* MH3-30372 	LCDC Component - Pixel Clock setting is not accurate 
* MH3-31147 	External Graphics Controller generate issue caused by gfx_driver.h changes 
* MH3-31167 	Aria Documentation missing files for library/utils/inc and library/utils/src folder 
* MH3-31168 	MPLAB® Harmony 3 Graphics Apps Repository in readme.md is pointing to a bitbucket link 
* MH3-31231 	GFX Canvas: Canvas framework code development 
* MH3-31232 	GFX Canvas: add Legato framework APIs 
* MH3-31234 	GFX Canvas: add per layer management to Composer and Legato library 
* MH3-31235 	GFX Canvas: add MHC component 
* MH3-31303 	RTOS Settings are not enabled in External Controller driver 
* MH3-31323 	GFX Template for MZ DA Curiosity board 
* MH3-31343 	PIC32MZ DA Legato: GPU is not used for blits even when "Use GPU for blit" is enabled in GLCD component 
* MH3-31344 	PIC32MZ DA Legato: Screen is not rendered when using GPU for scratch buffer blits 
* MH3-31346 	PIC32MZ DA Legato: libnano scratch buffer size is incosistent in code 
* MH3-31349 	GFX Core LE has 2 Pixel Clock options shown 
* MH3-31351 	GFX Core LE display timing does not change when using PDATM5000 display 
* MH3-31365 	External Graphics Controller RTOS support 
* MH3-31408 	Generated GFX init routines in initialization.c include the copyright header 
* MH3-31464 	PIC32MZ DA Legato: Default variable heap 4k is not enough for WVGA resolution. 
* MH3-31484 	Harmony 3: Display settings in Display Manager 
* MH3-31494 	External Graphics Contoller not supported with gfx_driver interface 
* MH3-36068 	GFX ReleaseDoc - Add Next-Gen API and User Guide 
* MH3-36215 	Fix multi-layer support in Legato GLCD driver 
* MH3-36219 	Legato Image Rotate Widget Compile Error 
* MH3-36220 	Previous fix to clipping in Aria renderer causes missing dirty rectangles 
* MH3-36221 	SAM E54 CCL DMA-based Graphics: Manage DMA transfer status in interrupt handler 
* MH3-36274 	Legato List Widget random behavior due to dirty memory 
* MH3-36410 	Aria Dynamic string UTF16 support 
* MH3-36435 	Package.xml versions no matching standard format 
* MH3-36436 	Add MPU support to Legato 
* MH3-36566 	Aria GAC Code Generation Stalled with MHC v3.4.0 
* MH3-36684 	Aria GAC Code generation stalled with MHC v3.5.0 
* MH3-36687 	Legato Image Rotate Widget: ARGB image asset no transparency in actual display 
* MH3-36804 	maxTouch driver always tries to open I2C Driver instance 0 (DRV_I2C_INDEX_0) 
* MH3-36849 	long loading time for MHC / MHGC 
* MH3-36968 	Rewrite java-based Legato Composer using C++ 
* MH3-37121 	H3 GFX - Display Manager - Typo in back Porch 
* MH3-38001 	Implement Standard driver interfaces for graphics controller and graphics processors 
* MH3-38035 	MHC regeneration hangs when Legato generated code is modified 
* MH3-38131 	PIC32MK1024MCF064: laWidget_GetMargin vs laWidget_GetMargins 
* MH3-38177 	Add Global Alpha and Palette Features to GPU drivers 
* MH3-38257 	Legato/Aria List widget wrong behavior with setItemVisible(0) function 

### Known Issues

* Code is compliant to MISRA C 2012 Mandatory guidelines, with the exception of Rule 9.1 (Code 530). In gfx.c, the variable args is falsely detected in violation of Code 530: "Symbol not initialized" at line 358. In fact, va_start at line 358 is exactly where args is initialized.
* When regenerating demo applications, keep all code between comments \/\/CUSTOM CODE and \/\/END OF CUSTOM CODE. Custom code is added to perform specific functionality.
* Applications running on SAM E70 in combination with LCC will observe visual rendering artifacts on display during SD card R/W access. There is no loss in SD Card data.
* FreeRTOS osal has an incorrect include path that causes build failures in non-Windows environments.
* SAM E54/D51 must be debugged using MPLABX v5.25
* legato_flash SAM E54 configuration support for USB is non-functional. SDCARD is functional.
* Pin 7 of the EXT1 connector on the PIC32MZ EF should drive the backlight. However, on rev1.0 of the board, it's not connected to any pin on the MCU. As a workaround, it needs to be connected to a v3.3 pin.
    
For a list of post release issues that affect this release, refer to MPLAB Harmony [GFX Issues and Errata](https://github.com/Microchip-MPLAB-Harmony/gfx/wiki/Issues-and-Errata).

### Development Tools

* [MPLAB® X IDE v5.40 or above](https://www.microchip.com/mplab/mplab-x-ide)
* [MPLAB® XC32 C/C++ Compiler v2.41](https://www.microchip.com/mplab/compilers)
* MPLAB® X IDE plug-ins:
    * MPLAB® Harmony Configurator (MHC) v3.4.2 and above.

### Dependent Components

* [BSP v3.7.0](https://github.com/Microchip-MPLAB-Harmony/bsp/releases/tag/v3.7.0)
* [Core v3.7.2 ](https://github.com/Microchip-MPLAB-Harmony/core/releases/tag/v3.7.2)
* [dev_packs v3.7.0 ](https://github.com/Microchip-MPLAB-Harmony/dev_packs/releases/tag/v3.7.0)
* [Harmony 3 USB v3.6.0](https://github.com/Microchip-MPLAB-Harmony/usb/releases/tag/v3.6.0)
* [Harmony 3 CMSIS-FreeRTOS v10.2.0](https://github.com/ARM-software/CMSIS-FreeRTOS)
* [IAR Embedded WorkBench ARM v8.40.1](https://www.iar.com/iar-embedded-workbench/#!?architecture=Arm)




