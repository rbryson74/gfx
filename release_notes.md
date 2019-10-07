# Microchip MPLAB® Harmony 3 Graphics Release Notes
## Graphics Release v3.4.0
### NEW FEATURES


- **Graphics Contents** - This graphics release consist of Graphics Libraries and apps, displays, drivers, hardware abstractions, input, middleware, and templates. The following table lists the contents in this graphics release.

| Category | Component | Description | Release Type |
| --- | --- | ---- |---- |
| aria | apps | aria_flash | Aria UI library interface to external flash assests | N/A |
|      |      | aria_quickstart | Aria UI library quickstart example | N/A|
|      |      | aria_quickstart_ext_res | Aria UI library external resource example | N/A|
|      |      | blank_quickstart | Blank UI-less library quickstart example | N/A|
|      |      | emwin_quickstart | Segger emWin UI library quickstart example | N/A|
|      |      | legato_quickstart | Legato UI library quickstart example | N/A |
|      |      | legato_quickstart_ext_res | Legato UI library external resource example | N/A|
|      |drivers| controller | external_controller | User generate-able external display driver | Beta |
|      |      |  | glcd | Graphics 3 Layer Display Driver | Production |
|      |      |  | ili9488| Display Driver for the ili9488 Controller |Beta |
|      |      |  | LCC | Display Driver for the LCC software Controller| Production |
|      |      |  | LCDC | Display Driver for the LCDC Controller| Beta |
|      |      |  | ssd1306 | Display Driver for the ssd1306 Controller  | Beta |
|      |      |  | ssd1309 | Display Driver for the ssd1309 Controller  | Beta |
|      |      |  | ssd1963 | Display Driver for the ssd1963 Controller | Beta |
|      |      | display interface | parallel_ebi | Interface to the parallel EBI registers | Beta |
|      |      |  | parallel_portgroup | Inteface to the parallel portgroup registers | Beta |
|      |      |  | parallel_smc | Interface to the parallel smc registers | Beta |
|      |      |  | spi | Interface to the spi registers | Beta |
|      |      | processor | 2dgpu| Graphics Processor Driver for the 2DGPU peripheral |Production |
|      |      |  | gfx2d | Graphics Processor Driver for the GFX2D peripheral |Production |
|      | hal | hal | Aria Hardware Abstration Layer | Production |
|      | input | generic | Generic Touch Input Driver | Beta |
|      |       | maxtouch | Microchip maXTouch Touch Input Driver | Production |
|      | library    | aria | Graphics Library | Production |
|      | templates   | aria_gfx_oled1_xpro | MHC for oled xpro| Beta |
|      |             | aria_gfx_pda_tm4301b| MHC config for pda 4" display | Production |
|      |             | aria_gfx_pda_tm5000| MHC config for pda 5" display | Beta |
|      |             | aria_gfx_xplained_pro| MHC config for xpro | Production |
|      |             | common| MHC config for common board |Production |
| legato | apps | legato_quickstart | Legato UI library quickstart example | N/A |
|      |      | legato_quickstart_ext_res | Legato UI library external resource example | N/A|
|      |drivers| controller | external_controller | User generate-able external display driver | Beta |
|      |      |  | ili9488| Display Driver for the ili9488 Controller |Beta |
|      |      |  | LCC | Display Driver for the LCC software Controller| Production |
|      |      |  | ssd1963 | Display Driver for the ssd1963 Controller | Beta |
|      |      | display interface | parallel_ebi | Interface to the parallel EBI registers | Beta |
|      |      |  | parallel_portgroup | Inteface to the parallel portgroup registers | Beta |
|      |      |  | parallel_smc | Interface to the parallel smc registers | Beta |
|      |      |  | spi | Interface to the spi registers | Beta |
|      | input | generic | Generic Touch Input Driver | Beta |
|      |       | maxtouch | Microchip maXTouch Touch Input Driver | Production |
|      |  library    | legato | Graphics Library | Production |
|      | templates   | legato_gfx_mxt_cpro | MHC for maXTouch cpro| Beta |
|      |             | aria_gfx_pda_tm4301b| MHC config for pda 4" display | Production |
|      |             | aria_gfx_pda_tm5000| MHC config for pda 5" display | Beta |
|      |             | common| MHC config for common board |Production |
| emWin | apps | emwin_quickstart | Legato UI library quickstart example | N/A |
|      |drivers| controller | external_controller | User generate-able external display driver | Beta |
|      |      |  | glcd | Graphics 3 Layer Display Driver | Production |
|      |      |  | LCC | Display Driver for the LCC software Controller| Production |
|      |      | display interface | parallel_ebi | Interface to the parallel EBI registers | Beta |
|      | input | generic | Generic Touch Input Driver | Beta |
|      |       | maxtouch | Microchip maXTouch Touch Input Driver | Production |
|      |  library    | emWin | Segger emWin Graphics Library | Production |
|      | templates   | aria_gfx_pda_tm4301b| MHC config for pda 4.3" display | Production |


- **Driver support** - The following table provides the list of updates for graphics and input drivers.

| Driver | Description |
| --- | --- |
| Generic | Added generic touch controller driver generator |
| Portgroup | Performance improvement |
| maxTouch| Enhanced power on reset timing|
| SSD1963 | Added support for Legato  |

- **Configuration support** - The following table provides the list of updates for configurations.

| applications | Description |
| --- | --- |
|aria_flash| Added support for MZ EF + MEB II +WQVGA |
|| Added support for SAM E70 + WQVGA |
|| Added support for MZ EF Curiosity 2.0 |
|| Added support for MZ DA Int DDR + MEB2 |
|aria_quickstart| Added support on D21 Nano GFX board   |
|| Added support for A5D2 XULT + WVGA display (XC32)  |
| aria_quickstart external| Added support on MZ EF MEB2   |
|| Added support for SAM E70 XULT + WQVGA  |
|| Added support for MZ EF Curiosity 2.0 LCC + WQVGA   |
|| Added support for SAM E70 XULT + SSD1963 +WQVGA    |
|| Added support for SAM E70 XULT + LCC +WQVGA  |
|| Added support for MZ EF Curiosity 2.0 + LCC +WQVGA |
|| Added support for MZ EF SK + MEB-II + LCC +WQVGA |
|| Added support for MZ DAR/S IntDDR SK + MEB-II + WQVGA |
|| Added support for MZ DAS/R IntDDR SK + MEB-II + WQVGA |
|legato_quickstart| Added support for PIC32MZ EF + WQVGA w/ LCC|
|| Added support for SAM E70 + WQVGA LCC |
|| Added support for SAM E54 CULT + CPRO with SPI interface|
|| Added support for SAM E54 CULT + SSD1963  |
|| Added support for SAM E70 XULT + SSD1963  |
|| Added support for PIC32MZ EF CULT + SSD1963 + 4.3" PDA display |
|legato_quickstart external| Added support for SAM E70 XULT + SSD1963 +WQVGA|
|blank_quickstart| Added support for PIC32MZ EF + WQVGA w/ LCC|
|| Added support for PIC32MZ DA + WQVGA w/ LCC   |


- **Middleware/HAL support** - The following table provides the list of updates for middleware and HAL content.

| Middleware/HAL | Description |
| --- | --- |
| emWin| Added graphics library |


- **Graphics Application Templates** - The following table provides the list of updates for graphics templates use within MHC.

|Library| Template | Description |
| --- | --- |---|
|aria | xplained_pro|Added support aria_gfx_oled1_xpro|
|legato|legato_gfx_pda_tm4301b|Added support for BSP_PIC32MZ_EF_Curiosity  |
|||Added support for PIC32MZ_EF_Starter_Kit |
|||Added support for SAM_E54_Curiosity_Ultra |
|||Added support for SAM_E70_Xplained_Ultra |

- **Board Support Packages (BSP)s** - The following table provides the list of updates for board support packages for use within MHC.

| BSP | Description |
| --- | --- |
| none | |

- **Development Interfaces** - The following table provides the list of updates for interface tools.

| Interface Tool | Description |
| --- | --- |
| none | |

- **Development kit support** - The following table lists  applications available for different development kits.

| Applications | [SAM C21N Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAMC21-XPRO) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME54-XPRO) | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME70-XPLD) | [SAM A5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsama5d2c-xult) | [Multimedia Expansion Board II](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320005-5) |SAM 9x60 Evaluation Kit |PIC32MZ EF Curiosity Kit |
| --- | --- | --- | --- | --- | --- | --- |--- |
| aria_flash                   |   |   | x |   | x |   | x |
| aria_quickstart              | x | x | x | x | x | x | x |
| aria_quickstart_ext_res      |   |   | x |   | x |   | x |
| blank_quickstart             |   |   |   |   | x |   |  |
| emwin_quickstart             |   |   |   |   | x |   |  |
| legato_quickstart            |   | x | x |   | x | x | x |
| legato_quickstart_ext_res    |   |   | x |   |   |   |  |

### KNOWN ISSUES

The current known issues are as follows:

* Code is compliant to MISRA C 2012 Mandatory guidelines, with the exception of Rule 9.1 (Code 530).
In gfx.c, the variable args is falsely detected in violation of Code 530: &quot;Symbol not initialized&quot; at line 358.  In fact, va_start at line 358 is exactly where args is initialized.

* Interactive help using the Show User Manual Entry in the Right-click menu for configuration options provided by this module is not yet available from within the MPLAB Harmony Configurator (MHC).  Please see the *Configuring the Library* section in the help documentation in the doc folder for this Harmony 3 module instead.  Help is available in both CHM and PDF formats.

* The target configuration aria_quickstart_e70_xult_xpro_spi does not support touch.

* The Heap Estimator can be inaccurate with estimating PNG images that have high pixel fidelity.

* Project regeneration from command line can remove Aria generated screens and widgets.

* MHGC GAC does not generated a 2DGPU comaptible palette table. A translation step is required to create word values from little endian byte array.

* Applications for PIC32MZ DA using external DDR are only supported on Rev A1 silicon.

### DEVELOPMENT TOOLS

| Tool | Version |
| --- | --- |
| [MPLAB® X IDE](https://www.microchip.com/mplab/mplab-x-ide) | v5.25 |
| [MPLAB® XC32 C/C++ Compiler](https://www.microchip.com/mplab/compilers)      | v2.30 |
| MPLAB® X IDE plug-ins          |  |
| MPLAB® Harmony Configurator (MHC) plug-in   | v3.3.1 |
| [Harmony 3 BSP](https://github.com/Microchip-MPLAB-Harmony/bsp)   | v3.5.0 |
| [Harmony 3 CSP](https://github.com/Microchip-MPLAB-Harmony/csp)  | v3.5.0 |
| [Harmony 3 Core](https://github.com/Microchip-MPLAB-Harmony/core)  | v3.5.0 |
| [Harmony 3 Graphics ](https://github.com/Microchip-MPLAB-Harmony/gfx)   | v3.5.0 |
| [Harmony 3 Dev_Packs](https://github.com/Microchip-MPLAB-Harmony/dev_packs)   | v3.5.0 |
| [Harmony 3 USB](https://github.com/Microchip-MPLAB-Harmony/usb)   | v3.4.0 |
| [Harmony 3 CMSIS-FreeRTOS](https://github.com/ARM-software/CMSIS-FreeRTOS)   | v10.2.0 |
