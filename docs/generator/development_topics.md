\page DevelopmentTopics Development Topics
[TOC]
\subpage ImageDecodeFormats
\subpage ThirdPartyDisplay
\subpage CustomEventDynamicWidgets
\subpage EnableRtos
\subpage PortingApplications
\subpage PhantomButtonTouch
\subpage DrawPipelineOptions
\subpage DynamicGraphics

# Development Topics

The Suite is comprised of a set of tools and technologies. The developent topics listed here are presented as user guides and best practices to help users get more out of the Suite.

## Integrated Tools

These pages give guidance on how best to use MPLAB Harmony Graphics Suite tools to create quality applications.

* [MPLAB Harmony 3 Configurator](https://microchipdeveloper.com/harmony3:mhc-overview) a graphical user interface for the MPLAB Harmony framework. It dramatically simplifies 32-bit (SAM and PIC32) core and peripheral configuration. It also allows you to enable and configure any of the specific Harmony framework libraries (e.g., device drivers, system services, USB, TCP/IP, graphics, etc.) you may need for your project
    
* [Legato graphics composer]() for designing and building graphical user interfaces (GUIs) from Legato widgets. Users compose and customize widgets in a visual editor upon setting a display configuration and color mode. You can access Legato composer from MPLAB X MHC menu after launching MHC.
    
* [Event Manager]() for managing user's interaction with GUI components.  The event manager contains facilities to handle GUI component activities for screen and widget events and defining screen macros.
    
* [Asset Manager]() for managing asset memory locations, images, fonts, string table, strings, and binary objects. It simplifies the management of internal and external assets storage. It also performs image format conversions, string localization, and font specification.


## Technologies

These pages give general guidance on how best to use MPLAB Harmony Graphics Suite technologies to create quality applications. For specific step-by-step complete application tutorials on our development board see:

| Technology | Description |
|-------------- | ---------|
| [Custom Events and Widgets](CustomEventDynamicWidgets.html) | How to add events|
| [Draw Pipeline](DrawPipelineOptions.html) | How to use draw pipeline options |
| [Dynamic Graphics](DynamicGraphics.html)| Recommendations for UI movements|
| [Enable RTOS](EnableRtos.html) | How to enable RTOS for graphics application |
| [Image Decode Performance](ImageDecodeFormats.html) | Some image performance statistics  |
| [Phantom Button Press](PhantomButtonTouch.html)| How to fix false button presses|
| [Porting Applications](PortingApplications.html) | How to port an application from a previous release|
| [Third-Party Display and Touch Module](ThirdPartyDisplay.html) | Using using a non-Microchip display module |

