\page PortingApplications Porting Applications
[TOC]

## Porting Aria Applications to Legato 

Microchip Harmony Graphics Suite Legato graphics library is a result of an on going effort to make graphics applications and development more easy to use and high performance.. 

When porting Aria-related code to Legato library, application developers should be aware that the graphics development infrastructure has undergone considerable changes in Legato. 

The table below details items to consider and the impact they have when porting an application using the Aria graphics library to the Legato graphics library. 

### Project Graph Component Changes
There are a few changes in MHC that affect the Aria applications. These are:

|----------|----------|
Aria | Legato | Discussion 
-----|--------|-----------
Aria Graphics Library component | Legato Graphics Library component  | The Aria component should be removed from the project graph. Select Legato instead. 
Aria Display Driver components | LE Display Driver components | The Aria display driver component should be removed. Select an LE display driver component instead. 
GFX Core Hardware Abstraction Layer component | GFX Core LE component for display management purposes | The HAL is no longer needed. The GFX Core LE is enabled on selection of a LE display driver.


### Middleware Folder Changes

There are a few folder changes which affect Aria applications. These are: 

|----------|----------|
Aria | Legato | Discussion 
-----|--------|-----------
middleware/aria | middleware/legato | The aria folder is not used for Legato applications. All related support files will exist in the legato folder. This includes library and drivers and templates. 

### Generated GFX File Changes

There are a few changes which effect the content of generated files. These are:

|----------|----------|
| Aria | Legato | Discussion |
|-----|--------|-----------|
|Application specific files are scattered under the config folder in various locations.  | Application specific files are located in the config/<your config>/gfx/legato/generate  | All Legato applications will generate fonts, images, screen and app support files to a single folder named "generate". |
| The UI design is hidden in the harmony.prj file | The UI design is stored in a single zip file named: <your_config>_design.zip.
| This file is selected when invoking Graphics Designer  |


###  Generated Harmony File Changes

There are a few changes to the content of generated files that should be noted. These are: 


### Driver Interface Changes

There are a few changes which effect Aria driver interface. These are: 


### Widgets and Screen Changes

Widgets and screens have a new declaration and calling mechanism. More facilities for speciality in Legato: These ar


### Memory Use Changes


Memory use was found to be problematic in Aria during heavy heap usage and debugging. Legato addresses heap allocation and dynamic memory as follows:

