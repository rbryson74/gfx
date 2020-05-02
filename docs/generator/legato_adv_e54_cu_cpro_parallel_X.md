\page legato_adv_e54_cu_cpro_parallel_X legato_adv_e54_cu_cpro_parallel.X
[TOC]

## Defining the Architecture

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_adv_e54_cu_cpro_parallel.X_arch.png)

This configuration runs on the SAM E54 Curiosity Ultra board with a 24-bit passthrough GFX interface card and a maXTouch Curiosity Pro display. The maXTouch Curiosity Pro display has an ILI9488 display controller that is connected to the SAM E54 thru the port/GPIO peripheral using an 8-bit 8080/Parallel interface, boosted with a combination of DMA and CCL peripherals. The Legato graphics library draws the updated sections of the frame to an internal scratch buffer which is used by the ILI9488 display driver to update the ILI9488 display controller. 

User touch input on the display panel is received thru the PCAP capacitive touch controller, which sends a notification to the Touch Input Driver. The Touch Input Driver reads the touch information over I2C and sends the touch event to the Graphics Library thru the Input System Service.  

## Demonstration Features 

* Legato Graphics Library 
* Input system service and touch driver 
* Time system service, timer-counter peripheral library and driver 
* ILI9488 display 8-bit parallel mode driver (DMA-CCL boosted) 
* 16-bit RGB565 color depth (8-bit palettized double buffering) 
* Port/GPIO peripheral 
* I2C peripheral library and driver 
* Images and Fonts for user interface stored in internal flas

## Creating the Project Graph

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_adv_e54_cu_cpro_parallel.X_pj.png)

Adding the “SAM E54 Curiosity Ultra BSP” and “Legato Graphics w/ MXT Curiosity Pro Display” Graphics Template component into the project graph. 

This will automatically add the components needed for a graphics project and resolve their dependencies. It will also configure the pins needed to drive the external peripherals like the display and the touch controller. 

For the DMA-CCL boosted setup, components TC4, CCL needs to be added. 

Some of these components are fine with default settings, while other require some changes. The following is a list of all the components that required custom settings. . 

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_qs_x_r_e54_cult_cpro_parallel.X_conf1.png)

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_qs_x_r_e54_cult_cpro_parallel.X_conf1.png) 

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_qs_x_r_e54_cult_cpro_parallel.X_conf2.png)

To setup the CCL to clock the pixel data, make sure PB09 is set to CCL_OUT2 

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_qs_x_r_e54_cult_cpro_parallel.X_conf4.png)

Instead of write strobe, make sure PB17 is setup as RSDC instead 

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_qs_x_r_e54_cult_cpro_parallel.X_conf5.png)


## Building the Application

The parent directory for this application is gfx/apps/legato_adventure. To build this application, use MPLAB X IDE to open the gfx/apps/legato_adventure/firmware/legato_adv_e54_cu_cpro_parallel.X project file.  

The following table lists configuration properties: 

| Project Name  | BSP Used |Graphics Template Used | Description |
|---------------| ---------|---------------| ---------|
| legato_adv_e54_cu_cpro_parallel.X | SAM E54 Curiosity Ultra BSP | Legato Graphics w/ Xplained Pro Display | SAM E54 Curiosity Ultra w/ maXTouch Xplained Pro display via 8-bit parallel interface |

 
> **_NOTE:_**  This application may contain custom code that is marked by the comments // START OF CUSTOM CODE ... and // END OF CUSTOM CODE. When using the MPLAB Harmony Configurator to regenerate the application code, use the "ALL" merging strategy and do not remove or replace the custom code.

## Configuring the Hardware

This section describes how to configure the supported hardware. 

Configure the hardware as follows: 

* Attach the 24-bit pass through card to the GFX Connector on the SAM E54 Curiosity Ultra board. 
* Connect the ribbon cable from the maXTouch Curiosity Pro Display to the ribbon connector on the 24-bit pass through card. Make sure that the S1 switch on the 24-bit pass through card is set to 2. 
* On the backside of the maXTouch Curiosity Pro display, set the IM[2:0] switches to ‘011’ for 8-bit MCU mode. 
* Connect a USB cable from the host computer to the DEBUG USB port on the SAM E54 Curiosity Ultra board. This USB connection is used for code download and debugging. 
* Connect 5.5V power supply to the SAM E54 Curiosity Ultra board is optional 

The final hardware setup should be: 

![](https://microchip-mplab-harmony.github.io/gfx/legato_fl_e54_cult_cpro_parallel.X_conf7.png)

## Running the Demonstration

The application first boots to an animated Splash Screen. Once the Splash Screen animation completes, the application boots to a Main Screen. 

When at rest, the demo will cycle through idle sprite animations. Various areas of the screen are touch interactive

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_adv_e54_cu_cpro_parallel.X_img1.png)

If initiated to run, the lamb sprite will run to the end of the screen, and play out a sequence of smacking into a wall, hurt and dizzy animations. 

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_adv_e54_cu_cpro_parallel.X_img2.png)

Tap Jump and the lamb will play out a jump animation. 

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_adv_e54_cu_cpro_parallel.X_img3.png)

Info Screen describes the features supported by this demo 

![](https://microchip-mplab-harmony.github.io/gfx_apps/legato_adv_e54_cu_cpro_parallel.X_img4.png)
