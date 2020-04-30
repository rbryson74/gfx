---
title: Harmony 3 Graphics Package
nav_order: 1
---
# ![Microchip Technology](docs/images/mhgs.png) MPLAB® Harmony 3 Graphics Support Package

MPLAB® Harmony 3 is an extension of the MPLAB® ecosystem for creating
embedded firmware solutions for Microchip 32-bit SAM and PIC microcontroller
and microprocessor devices.  Refer to the following links for more information:
 - [Microchip 32-bit MCUs](https://www.microchip.com/design-centers/32-bit)
 - [Microchip 32-bit MPUs](https://www.microchip.com/design-centers/32-bit-mpus)
 - [Microchip MPLAB® X IDE](https://www.microchip.com/mplab/mplab-x-ide)
 - [Microchip MPLAB® Harmony](https://www.microchip.com/mplab/mplab-harmony)
 - [Microchip MPLAB® Harmony Pages](https://microchip-mplab-harmony.github.io/)

This repository contains the MPLAB® Harmony Graphics Suite.  The
suite supports a free fast to market, graphics software development environment for Microchip MPLAB® 32-bit SAM and PIC microprocessor devices.  Refer to
the following graphics links for release notes, home page, training materials, framework and application help.
Find multiple graphics application examples in the [gfx_apps](https://github.com/Microchip-MPLAB-Harmony/gfx_apps/tree/master/apps) repository.
 - [Release Notes](./release_notes.md)
 - [MPLAB® Harmony License](mplab_harmony_license.md)
 - [MPLAB® Harmony 3 Graphics Wiki](https://github.com/Microchip-MPLAB-Harmony/gfx/wiki)
 - [MPLAB® Harmony 3 Graphics Videos](https://www.youtube.com/playlist?list=PL9B4edd-p2ag5xsIIHhja-caKYY7AKPxe)
 - [MPLAB® Harmony 3 Graphics Suite Documentation](https://automaate.github.io/gen2_wiki_sandbox/docs/html/index.html)
 - [MPLAB® Harmony 3 Graphics Apps Repository](api.md)

# Features

The key features of the MPLAB® Harmony Graphics Suite are the following:

- Hardware optimized for use with Microchip 32-bit SAM and PIC devices
- Compatible component for use with Microchip Harmony 3 Configurator (MHC)
- Written in C with MISRA C (Mandatory) compliancy
- RTOS and non-RTOS support
- Configurable widget building blocks buttons, labels, lists, sliders, and images
- Rich tool set: Heap Estimator, Event Manager, Palette generator, Asset Manager, String and Font interface, DDR memory organizer
- Hardware integrated for Microchip GPU and display controller peripherals
- Support for single and double frame buffers
- Multi-language font support
- External input support for use with capacitive, resistive and other devices
- UI design editor for what-you-see-what-you-get (WYSWYG) graphics layouts
- Fluid-UI support for alpha-blending, animations, scaling
- Pixel format support for RGBA8888, RGB888, RGB565, RGB5551, RGB332, GS8
- Multi-image support for industry standard formats, compression choices, external memory accessibility
- Fully functional demonstrations and quick-starts to enable new development
- Low memory and low power configurable


# Contents Summary

| Folder     | Description                                  |
|------------|----------------------------------------------|
| apps       | Example quickstart and utility applications |
| display    | Supported displays |
| docs       | HTML Help documentation                   |
| input      | Input System and its associated drivers and services |
| middleware | Supported User Interface (UI) libraries |
| driver     | Display controller and graphics processor unit drivers |


## Legato graphics library

**Legato graphics library** - the performance improved graphics library for MPLAB Harmony Graphics Suite. Supports Microchip PIC32 and SAM microcontrollers.

| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
|  apps | legato_flash | Legato UI library quickstart flash writer example | ![app-beta](https://img.shields.io/badge/application-beta-orange?style=plastic) |
|  apps | legato_quickstart | Legato UI library quickstart example | ![app-beta](https://img.shields.io/badge/application-beta-orange?style=plastic) |
|      |  legato_quickstart_ext_res | Legato UI library external resource example | ![app-beta](https://img.shields.io/badge/application-beta-orange?style=plastic)|
| drivers|  external_controller | User generate-able external display driver | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
|      |   ili9488 | Display Driver for the ili9488 Controller |![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
|      |   LCC | Display Driver for the LCC software Controller| ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
|      |   ssd1963 | Display Driver for the ssd1963 Controller | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
|      |   parallel_ebi | Interface to the parallel EBI registers | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
|      |   parallel_portgroup | Inteface to the parallel portgroup registers | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
|      |   parallel_smc | Interface to the parallel smc registers | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
|      |   spi | Interface to the spi registers | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| library    | legato | Graphics Library | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| designer | legato MHGC |Harmony Graphics Composer for Legato| ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |


## Blank library interface

**Blank library interface** - the library interface which easily allows a third-party graphics library direct access to the display framebuffer.

| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
| apps | blank_quickstart | Blank UI-less library quickstart example | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| interface| gfx_driver | Interface abstraction between a graphics library and graphics drivers | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |

## Graphics Drivers

| Driver | Status |
| --- | :---: |
| [external_controller](middleware/legato/driver/controller/external_controller/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| [glcd](middleware/legato/driver/controller/glcd/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| [2dgpu](middleware/legato/driver/processor/2dgpu/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| [generic_touch](input/driver/touch/generic_touch/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| [maxtouch](input/driver/touch/maxtouch/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| [ptc](input/driver/touch/ptc/readme.md) | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |

## Misc items

**Misc items** - items associated with the entire graphics suite.

| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
|input | generic | Generic Touch Input Driver | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
|      | maxtouch | Microchip maXTouch Touch Input Driver | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| docs| Help | Application Help Documentation HTML| ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| templates   |  middleware | Board configuration scripts| ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |
| display | boards | Productized display board support | ![app-beta](https://img.shields.io/badge/plib-beta-orange?style=plastic) |

____

[![License](https://img.shields.io/badge/license-Harmony%20license-orange.svg)](https://github.com/Microchip-MPLAB-Harmony/gfx/blob/master/mplab_harmony_license.md)
[![Latest release](https://img.shields.io/github/release/Microchip-MPLAB-Harmony/aerospace.svg)](https://github.com/Microchip-MPLAB-Harmony/gfx/releases/latest)
[![Latest release date](https://img.shields.io/github/release-date/Microchip-MPLAB-Harmony/aerospace.svg)](https://github.com/Microchip-MPLAB-Harmony/gfx/releases/latest)
[![Commit activity](https://img.shields.io/github/commit-activity/y/Microchip-MPLAB-Harmony/aerospace.svg)](https://github.com/Microchip-MPLAB-Harmony/gfx/graphs/commit-activity)
[![Contributors](https://img.shields.io/github/contributors-anon/Microchip-MPLAB-Harmony/aerospace.svg)]()

____

[![Follow us on Youtube](https://img.shields.io/badge/Youtube-Follow%20us%20on%20Youtube-red.svg)](https://www.youtube.com/user/MicrochipTechnology)
[![Follow us on LinkedIn](https://img.shields.io/badge/LinkedIn-Follow%20us%20on%20LinkedIn-blue.svg)](https://www.linkedin.com/company/microchip-technology)
[![Follow us on Facebook](https://img.shields.io/badge/Facebook-Follow%20us%20on%20Facebook-blue.svg)](https://www.facebook.com/microchiptechnology/)
[![Follow us on Twitter](https://img.shields.io/twitter/follow/MicrochipTech.svg?style=social)](https://twitter.com/MicrochipTech)

[![](https://img.shields.io/github/stars/Microchip-MPLAB-Harmony/aerospace.svg?style=social)]()
[![](https://img.shields.io/github/watchers/Microchip-MPLAB-Harmony/aerospace.svg?style=social)]()
