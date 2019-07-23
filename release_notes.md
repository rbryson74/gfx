# Microchip MPLAB® Harmony 3 Graphics Release Notes
## Graphics Release v3.3.0
### NEW FEATURES


- **Graphics Contents** - This graphics release consist of apps, displays, drivers, hardware abstractions, input, middleware, and templates. The following table lists the contents in this graphics release.

| Category | Component | Description | Release Type |
| --- | --- | ---- |---- |
| apps | aria_quickstart | Getting started in Graphics | N/A|
| displays | ATMXT-XPRO-480x320 | MaxTouch Xplained Pro 480x320| Production |
|      | ATOLED1_XPRO-128x32 | AT OLED Xplained Pro 128x32| Beta |
|      | MXT-CPRO-320x480 | MaxTouch Curiosity Xplained Pro 320x480| Beta |
|      | PDA TM4301B 480x272| PDA 4.3" 480x272 | Production |
|      | PDA TM50000 800x480| PDA 5" 800x480 | Beta |
|  drivers    | glcd | Graphics 3 Layer Display Driver | Beta |
|      | ili9488| Display Driver for the ili9488 Controller |Beta |
|      | interface | Display Driver interface driver | Production |
|      | LCC | Display Driver for the LCC software Controller| Production |
|      | LCDC | Display Driver for the LCDC Controller| Beta |
|      | ssd1306 | Display Driver for the ssd1306 Controller  | Beta |
|      | ssd1309 | Display Driver for the ssd1309 Controller  | Beta |
|      | ssd1963 | Display Driver for the ssd1963 Controller | Beta |
|      | 2dgpu| Graphics Processor Driver for the 2DGPU peripheral |Beta |
|      | gfx2d| Graphics Processor Driver for the GFX2D peripheral |Beta |
|  interface    | parallel_ebi | Inteface to the parallel EBI registers | Beta |
|      | parallel_portgroup | Inteface to the parallel portgroup registers | Beta |
|      | parallel_smc | Interface to the parallel smc registers | Beta |
|      | parallel_smc | Interface to the spi registers | Beta |
|  hal    | hal | Aria Hardware Abstration Layer | Production |
|  input    | maxtouch | Microchip maXTouch Touch Input Driver | Production |
|  middleware    | aria | Harmony Graphics Middleware Solution | Production |
|      | legato | Harmony Graphics Middleware Solution | Beta |
| templates   | aria_gfx_oled1_xpro | MHC for oled xpro| Beta |
|             | aria_gfx_pda_tm4301b| MHC config for pda 4" display | Production |
|             | aria_gfx_pda_tm5000| MHC config for pda 5" display | Beta |
|             | aria_gfx_xplained_pro| MHC config for xpro | Production |
|             | common| MHC config for common board |Production |

- **Driver support** - The following table provides the list of updates for graphics and input drivers.

| Driver | Description |
| --- | --- |
| GFX2D | Added driver support for GFX2D GPU|
| LCC | Added support for PIC32MZ EF in LCC driver|
| 2DGPU | Added performance enhancements|
| SSD1309| Added driver support SSD1309 display controller|
| GLCD| Added parallel 8080 interface driver for PIC32MZ EF|
| maxTouch| Added blocking (sync) option for maXTouch driver|
| | Added switch X, Y configuration option to maXTouch driver|
| Interface| Added parallel 8080 interface driver for PIC32MZ EF|
| ILI9488| Added support for rectangular fill |
| SSD1963 | Added DirectBlit support  |

- **Configuration support** - The following table provides the list of updates for configurations.

| Middleware/HAL | Description |
| --- | --- |
| quickstart| Added support on E54 curiosity with PDA TM4301b display using SSD1953 GFX adapter board |
| | Added support on PIC32MZ EF SK + MEBII + WQVGA Display |
| | Added support on PIC32MZ EF Curiosity 2.0 + WQVGA Display |
| | Added support on SAM E54 Curiosity Ultra + maXTouch XPro w/ ILI9488 via 8-bit 8080-mode |
| | Added support on SAM E70 Xplained Ultra + maXTouch XPro w/ ILI9488 via 16-bit 8080-mode |
| | Added support on PIC32MZ EF Curiosity 2 + WQVGA Display and SSD1963 GFX Card |
| | Added support on PIC32MZ EF Curiosity 2 + maXTouch XPlained Pro 2 (new) w/ ILI9488 controller |
| | Added support on PIC32MZ EF Curiosity 2 + maXTouch XPlained Pro w/ ILI9488 controller (SPI)|
| | Added support on SAM9x60 Evaluation Kit with PDA Display |
| | Added support on PIC32MZ DA SK with PDA TM5000 Display on MEBII |
|legato_quickstart| Added support on E54 CULT + Xplained Pro 2 Parallel 8-bit mode|

- **Middleware/HAL support** - The following table provides the list of updates for middleware and HAL content.

| Middleware/HAL | Description |
| --- | --- |
| aria| |
| legato| Added graphics library |


- **Graphics Application Templates** - The following table provides the list of updates for graphics templates use within MHC.

|Library| Template | Description |
| --- | --- |---|
|aria| pda_tm4301b| Added template support for E54 Curiousity Ultra + PDA TM4301B display|
|||Added PWM Backlight configuration to SAM E70 XULT + WQVGA GFX Template|
|||Added template for PIC32MZ EF SK + MEBII + WQVGA display|
|||Added template for PIC32MZ EF Curiosity 2.0 + WQVGA display|
|||Added template for PIC32MZ EF Curiosity 2 + WQVGA display + SSD1963 GFX card|
|||Added template for SAM9x60 Evaluation Kit + PDA display |
| | pda_tm5000|Added template for SAM9x60 Evaluation Kit + PDA display|
|||Added template for SAM9x60 Evaluation Kit + PDA display |
| | xplained_pro|Added template for SAM E54 Curiosity Ultra + maXTouch Xpro display via 8-bit parallel mode|
|||Added template for PIC32MZ EF Curiosity 2.0 + maXTouch XPLD display|
|||Added template for PIC32MZ EF Curiosity 2.0 + maXTouch XPRO 2 display (SPI) |
|legato|legato_gfx_mxt_cpro| Added  template for SAM E54 CULT + ILI9488 Parallel 8-bit mode |

- **Board Support Packages (BSP)s** - The following table provides the list of updates for board support packages for use within MHC.

| BSP | Description |
| --- | --- |
| none | |

- **Development Interfaces** - The following table provides the list of updates for interface tools.

| Interface Tool | Description |
| --- | --- |
| none | |

- **Development kit support** - The following table lists  applications available for different development kits.

| Applications | [SAM C21N Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAMC21-XPRO) | [SAM E54 Xplained Pro Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME54-XPRO) | [SAM E70 Xplained Ultra Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/PartNO/ATSAME70-XPLD) | [SAM A5D2 Xplained Ultra Evaluation Kit](https://www.microchip.com/developmenttools/ProductDetails/atsama5d2c-xult) | [Multimedia Expansion Board II](https://www.microchip.com/DevelopmentTools/ProductDetails/PartNO/DM320005-5) |
| --- | --- | --- | --- | --- | --- |
| aria_quickstart           | x | x | x | x | x |
| legato_quickstart         |   | x |   |   |   |

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
| [MPLAB X IDE](https://www.microchip.com/mplab/mplab-x-ide) | v5.20 |
| [MPLAB XC32 C/C++ Compiler](https://www.microchip.com/mplab/compilers)      | v2.20 |
| MPLAB X IDE plug-ins          |  |
| MPLAB Harmony Configurator (MHC) plug-in   | v3.3.0 |
| Harmony 3 BSP (https://github.com/Microchip-MPLAB-Harmony/bsp)   | v3.3.0 |
| Harmony 3 CSP (https://github.com/Microchip-MPLAB-Harmony/csp)  | v3.3.0 |
| Harmony 3 Core (https://github.com/Microchip-MPLAB-Harmony/core)  | v3.3.0|
| Harmony 3 Graphics (https://github.com/Microchip-MPLAB-Harmony/gfx)   | v3.3.0 |
| Harmony 3 Dev_Packs (https://github.com/Microchip-MPLAB-Harmony/dev_packs)   | v3.3.0 |
