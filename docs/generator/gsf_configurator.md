\page Configurator Configurator
[TOC]  

# Configurator

The MPLAB Harmony Graphics Suite aligns with MPLAB Harmony Configurator which increases productivity, simplicity, scalability, and consistency through a data-driven approach to establishing graphics solution. 

MHGS supports the configuration and generation of the code from the designer, graphics library, and drivers through graphics configurator. It produces custom code specific to the needs of a project. It provides a data setting environment to help bind modules, peripherals, widgets, memory, assets together into a final application for compilation.

MHGS code is generated on click of the generate button, It parses all graphics resources and source and inserts c-code into the project source tree that you can then compile link and distribute . 

MHGS produces an extensive set of Harmony components made available under "Available Components". The components are actual code blocks that can accept user level inputs to affect generate code output. This means you can create your own unique system within the Project Graph window.

What is generated? 

The configuration step supports the generation c-code for the following elements below. The generated code is automatically inserted into the project build configuration. They are: 

* Harmony Framework code
* Middleware (User Interface) code
* Driver code
* Touch Input code

Code Generation Tools: 

* MPLAB Harmony Configurator (MHC) - is the parent generator tool for MPLAB Harmony. It is responsible for establishing a consistent overall structure for any Harmony-based project.
* MPLAB Harmony Graphics Composer (MHGC) - is the GUI productivity and simplicity tool you to easily configure and visually design your graphics UI using a supported graphics library.
* Display Manager - is the primary graphics display interface scalability tool which allows you to establish custom display driver tuning for the LCC-type display drivers.
* Graphics Components - are user configurable code blocks.