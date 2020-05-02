\page blank_qs_e54_cu_cpro_spi_X blank_qs_e54_cu_cpro_spi.X
[TOC]

## Defining the Architecture

![](https://microchip-mplab-harmony.github.io/gfx/legato_qs_e54_cu_cpro_spi_arch.png)

The application uses the Legato Graphics Driver Abstraction APIs to render text on a label widget, an image and a user-interactive button to the screen. Touching the button on the screen will show the button being pressed. 

The block diagrams below show the various software and hardware blocks used in this application:

### Demonstration Features 

* 3rd-Party graphics driver abstraction 
* ILI9488 display controller driver 
* 4-line SPI display interface driver 
* Time system service, timer-counter peripheral library and driver 
* 16-bit RGB565 color depth support (65535 unique colors) 
* Port, I2C peripheral library 

## Creating the Project Graph

![](https://microchip-mplab-harmony.github.io/gfx/blank_quickstart_e54_cult_cpro_spi.X_pg.png)

 The Project Graph diagram below shows the Harmony components that are included in this application. Lines between components are drawn to satisfy components that depend on a capability that another component provides.

Adding the “SAM E54 Curiosity Ultra BSP” and “Legato Graphics w/ MXT Curiosity Pro Display” Graphics Template component into the project graph will automatically add the components needed for a graphics project and resolve their dependencies. It will also configure the pins needed to drive the external peripherals like the display and the touch controller. 

To configure the project for an SPI Interface, set the Display Interface setting for the “Legato Graphics w/ PDA TM4301B Display“ component to SPI 4-Line. 

![](https://microchip-mplab-harmony.github.io/gfx/legato_qs_e54_cu_cpro_spi_cfg1.png)

## Building the Application

 The parent directory for this application is gfx/apps/blank_quickstart. To build this application, use MPLABX IDE to open the gfx/apps/blank_quickstart/firmware/blank_qs_e54_cu_cpro_spi.X project file. 

The following table lists configuration properties:  

| Project Name  | BSP Used |Graphics Template Used | Description |
|---------------| ---------|---------------| ---------|
| blank_quickstart_e54_cu_cpro_spi.X | SAM E54 Curiosity Ultra BSP | Legato graphics w/ maXTouch Curiosity Pro Display  | SAM E54 Curiosity Ultra w/ maXTouch maXTouch Curiosity Pro display via 8-bit parallel interface |

> **_NOTE:_**  This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

## Configuring the Hardware

The final setup should be:

![](https://microchip-mplab-harmony.github.io/gfx/legato_qs_e54_cu_cpro_spi_hd1.png)

Set the IM switches on the MXT Curiosity Pro Display to IM[2:0] = 111b. 

![](https://microchip-mplab-harmony.github.io/gfx/legato_qs_e54_cu_cpro_spi_hd2.png)

## Running the Demonstration

When power-on is successful, the demonstration will display a similar menu to that shown in the following figure (different configurations may have slight variation in the screen aspect ratio): 

![](https://microchip-mplab-harmony.github.io/gfx/APPS%20GFX%20e70_run.png)
