# Microchip MPLAB® Harmony 3 Graphics Release Notes
## Graphics Release v3.5.0

- **Graphics Contents** - This graphics release consists of graphics libraries, applications, utilities, drivers, hardware abstractions, input, middleware, templates, and documentation. The following table lists the contents:

### Aria graphics library
| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
| apps |  aria_flash  | Aria UI library flash writer | Beta |
|      |  aria_quickstart|Aria UI library quickstart example | Production|
|      |  aria_quickstart_ext_res    | Aria UI library external resource example | Beta|
|drivers|  external_controller | User generate-able external display driver | Beta |
|      |  glcd | Graphics 3 Layer Display Driver | Production |
|      |  ili9488| Display Driver for the ili9488 Controller |Production |
|      |  LCC | Display Driver for the LCC software Controller| Production |
|      |  LCDC | Display Driver for the LCDC Controller| Production |
|      |  ssd1306 | Display Driver for the ssd1306 Controller  | Production |
|      |  ssd1309 | Display Driver for the ssd1309 Controller  | Beta |
|      |  ssd1963 | Display Driver for the ssd1963 Controller | Production |
|      |  parallel_ebi | Display interface using parallel EBI registers | Production |
|      | parallel_portgroup | Display interface using parallel portgroup registers | Production |
|      | parallel_smc | Display interface using parallel smc registers | Production |
|      | spi | Display interface using spi registers | Production |
|      | 2dgpu| Graphics Processor Driver for the 2DGPU peripheral |Beta |
|      | gfx2d | Graphics Processor Driver for the GFX2D peripheral |Production |
| hal     | hal | Aria Hardware Abstraction Layer | Production |
| library    | aria | Graphics Library | Production |
| designer | Aria MHGC  | Harmony Graphics Composer for Aria| Production|

### Legato graphics library
| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
|  apps | legato_quickstart | Legato UI library quickstart example | Production |
|      |  legato_quickstart_ext_res | Legato UI library external resource example | Beta|
| drivers|  external_controller | User generate-able external display driver | Beta |
|      |   ili9488| Display Driver for the ili9488 Controller |Beta |
|      |   LCC | Display Driver for the LCC software Controller| Beta |
|      |   ssd1963 | Display Driver for the ssd1963 Controller | Beta |
|      |   parallel_ebi | Interface to the parallel EBI registers | Beta |
|      |   parallel_portgroup | Inteface to the parallel portgroup registers | Beta |
|      |   parallel_smc | Interface to the parallel smc registers | Beta |
|      |   spi | Interface to the spi registers | Beta |
| library    | legato | Graphics Library | Production |
| designer | Legato MHGC |Harmony Graphics Composer for for Legato| Beta|

### SEGGER emWin graphics library
| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
| apps | emwin_quickstart | Legato UI library quickstart example |Beta |
| drivers|  glcd | Graphics 3 Layer Display Driver | Production |
|      |      LCC | Display Driver for the LCC software Controller| Production |
|      | parallel_ebi | Interface to the parallel EBI registers | Beta |
| library    | emWin | SEGGER emWin Graphics Library | Production |
|      | templates   | aria_gfx_pda_tm4301b| MHC config for pda 4.3" display | Production |
| designer | emWin | SEGGER emWin v5.50 - Graphical UI for embedded applications| Beta|

### Blank graphics library
| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
| apps | blank_quickstart | Blank UI-less library quickstart example | Beta|
| drivers| glcd | Graphics 3 Layer Display Driver | Production |
|      |  LCC | Display Driver for the LCC software Controller| Production |
|      |   parallel_ebi | Interface to the parallel EBI registers | Beta |
| library    | blank | Pixel operations | Beta |


### Misc items
| Category | Item | Description | Release Type |
| --- | --- | ---- |---- |
|input | generic | Generic Touch Input Driver | Production |
|      | maxtouch | Microchip maXTouch Touch Input Driver | Production |
| doc | Help | Application Help Documentation| Production |
| docs| Help | Application Help Documentation HTML| Production |
| templates   |  middleware | Board configuration scripts| Production |

### Changes for v3.5

- **Driver support** - The following table provides the list of updates for graphics and input drivers.

| Driver | Description |
| --- | --- |
| Generic | Added generic touch controller driver generator |
| Portgroup | Enhanced improvement with respect to performance |
| maxTouch| Enhanced power on reset timing|
| SSD1963 | Added support for Legato  |

- **Application support** - The following table provides the list of updates for application configurations.

| Application |  Description |
| --- | --- |
|aria_flash| Added flash write application |
|aria_quickstart external| Added external media based image and font |

- **Middleware/HAL support** - The following table provides the list of updates for middleware and HAL content.

| Middleware/HAL | Description |
| --- | --- |
| SEGGER emWin| Added graphics library |


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

| Applications | [SAM D21N Xplained Pro Evaluation Kit](https://www.microchip.com/DevelopmentTools/ProductDetails/ATSAMD21-XPRO) |[SAM C21N Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAMC21-XPRO) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME54-XPRO) | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME70-XPLD) | [SAM A5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsama5d2c-xult) | [Multimedia Expansion Board II](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320005-5) |SAM 9x60 Evaluation Kit |[PIC32MZ EF Curiosity Kit](https://www.microchip.com/Developmenttools/ProductDetails/DM320209) |
| --- | --- |--- | --- | --- | --- | --- | --- |--- |
| aria_flash                   |   |   |   | x | x | x |   | x |
| aria_quickstart              | x | x | x | x | x | x | x | x |
| aria_quickstart_ext_res      |   |   |   | x |   | x |   | x |
| blank_quickstart             |   |   |   |   |   | x |   |  |
| emwin_quickstart             |   |   |   |   |   | x |   |  |
| legato_quickstart            |   |   | x | x |   | x | x | x |

### KNOWN ISSUES

Current known issues are as follows:

* Code is compliant to MISRA C 2012 Mandatory guidelines, with the exception of Rule 9.1 (Code 530).
In gfx.c the variable args is falsely detected in violation of Code 530: &quot;Symbol not initialized&quot; at line 358.  In fact, va_start at line 358 is exactly where args is initialized.
* Interactive help using the Show User Manual Entry in the Right-click menu for configuration options provided by this module is not yet available from within the MPLAB Harmony Configurator (MHC).  Please see the *Configuring the Library* section in the help documentation in the doc folder for this Harmony 3 module instead.  Help is available in both CHM and PDF formats.
* Configurations using xplained pro display do not support touch events. For example, aria_quickstart_e70_xult_xpro_spi.
* The Heap Estimator can be inaccurate with estimating PNG images that have high pixel fidelity.
* Project regeneration from command line can remove Aria generated screens and widgets.
* MHGC GAC does not generated a 2DGPU comaptible palette table. A translation step is required to create word values from little endian byte array.
* When regenerating demo applications, keep all code between comments //CUSTOM CODE and //END OF CUSTOM CODE. Custom code is added to perform specific functionality.
* PKOB4 debugging requires MPLAB v5.20.

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
| [IAR Embedded WorkBench ARM](https://www.iar.com/iar-embedded-workbench/#!?architecture=Arm)   | v8.40.1 |
