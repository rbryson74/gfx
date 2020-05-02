\page blank_qs_e70_xu_tm4301b_X blank_qs_e70_xu_tm4301b.X
[TOC]

## Defining the Architecture

![](https://microchip-mplab-harmony.github.io/gfx/APPS%20GFX%20aria_quickstart%20block%20diagram.png)

In this configuration, a 16-bit RGB565 frame buffer is stored in the internal SRAM. These configurations use the Low Cost Controller-less (LCC) display driver to manage the DMA that transfers the framebuffer contents to the display. 

User touch input on the display panel is received thru the PCAP capacitive touch controller, which sends a notification to the Touch Input Driver. The Touch Input Driver reads the touch information over I2C and sends the touch event to the Graphics Library thru the Input System Service. 

### Demonstration Features 

* 3rd-Party graphics driver abstraction 
* DMA System Service
* Low-Cost Controllerless (LCC) graphics driver
* 16-bit RGB565 color depth support (65535 unique colors)
* RAW image stored in internal flash 

## Creating the Project Graph

![](https://microchip-mplab-harmony.github.io/gfx/blank_qs_e70_xu_tm4301b.X_pj.png)

The Project Graph diagram shows the Harmony components that are included in this application. Lines between components are drawn to satisfy components that depend on a capability that another component provides. 

Adding the “SAM E70 XPlained Ultra BSP” and “Legato Graphics w/ PDA TM4301B Display” Graphics Template component into the project graph will automatically add the components needed for a graphics project and resolve their dependencies. It will also configure the pins needed to drive the external peripherals like the display and the touch controller. . 

![](https://microchip-mplab-harmony.github.io/gfx/legato_qs_e54_cu_cpro_spi_cfg1.png)

## Building the Application

The parent directory for this application is gfx/apps/blank_quickstart. To build this application, use MPLABX IDE to open the gfx/apps/blank_quickstart/firmware/blank_qs_e70_xu_tm4301b.X project file. . 

The following table lists configuration properties:  

| Project Name  | BSP Used |Graphics Template Used | Description |
|---------------| ---------|---------------| ---------|
| blank_qs_e70_xu_tm4301b.X | sam_E70_xplained_ultra | PDA TM4301b display | SAM E70 Xplained Ultra board with PDA TM4301B 480x272 (WQVGA) display |

> **_NOTE:_**  This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

## Configuring the Hardware

The final setup should be:

![](https://microchip-mplab-harmony.github.io/gfx/APPS%20GFX%20aria_benchmark%20Final%20Setup.png)

Configuring the 4.3” WQVGA Display requires disconnecting the ribbon cable that connects the display to the interposer board.  

![](https://microchip-mplab-harmony.github.io/gfx/APPS%20GFX%20aria_benchmark%20Bottom%20of%20WQVGA%20Display.png)

First, release the ribbon cable from the interposer board. Next, release the black clamp on the E70’s J2 connector and turn the display over. Finally, insert the ribbon cable into J2 and close the clamp.

![](https://microchip-mplab-harmony.github.io/gfx/APPS%20GFX%20aria_benchmark%20Connecting%20Ribbon%20Cable.png)

The board and display are powered by a Micro B – USB A cable from PC to the “Debug USB” port on the E70 board. The ICD4 Debugger and ICD4/PICKit4 Adapter Board are connected as shown above. 

## Running the Demonstration

When power-on is successful, the demonstration will display a similar menu to that shown in the following figure (different configurations may have slight variation in the screen aspect ratio): 

![](https://microchip-mplab-harmony.github.io/gfx/blank_quickstart_565.png)
