\page Designer Designer
[TOC]  

MPLAB Harmony Graphics Suite has its own integrated GUI design tool named MPLAB Harmony Graphics Composer (MHGC). It is used to design and build graphical user interfaces (GUIs) from widgets contain in the graphics library. With its what-you-see-what-you-get (WYSWYG) editor, a complete layout can be created and managed.

MPLAB Harmony Graphics Suite contains the Aria and Legato composer designer tools for the Aria and Legato graphics library. With their what-you-see-what-you-get (WYSWYG) editor, a complete layout can be created and managed. 

The designer contains a number of integrated tools which support the collaboration work flow between designers and developers to help create quick to market solutions. The designer is tightly coupled with the graphics library to facilitate rapid prototyping and optimization of the application's user interface. 

 * Widget Layouts
 * Asset and Image management
 * Language Localization
 * Strings and Fonts
 * Event Management
 * Palette Management
 * Heap Estimation

Legato composer is currently in a beta version. It is functionality compatible with Aria composer and approaching feature compatibility. 

## Legato composer

Legato composer is the designer tool for designing and building graphical user interfaces (GUIs) using Legato widgets. You can compose and customize your screens in a what-you-see-is-what-you-get (WYSIWYG) manner, and generate code associated with various LCD display dimensions and resolutions. 

If you are new to Legato composer, you can take a look at the screen shots below. Legato composer is currently a beta version. It is functionality compatible with Aria composer and approaching feature compatibility. For a step by step tutorial see [Quickstart Composer](https://github.com/Microchip-MPLAB-Harmony/gfx/wiki).

The MHGC designer for Legato is launched from the MPLAB Harmony Configurator (MHC) Tools menu as shown below: 
 
![](../images/composer_display_conf.png)

Start a new design using the New Project Wizard

Use the Project Wizard to set **display configuration** **width** and **height**,the default is 480x272. A variety of popular display resolution **presets* are available. View **Total pixel count** used by the display configuration.

![](../images/composer_display_conf.png)

Use the Project Wizard to set the desired **color mode*. The default is RGB_565. View **Estimated size** of a single frame buffer in bytes used as a result of the color mode.

![](../images/composer_display_color_mode.png)

Use the **Tree View** pane to create **Layers** view and select widgets and define parent, child, and sibling relationships.

![](../images/composer_tree_view.png)

Use the **Screens** pane to create **screens**. Screens are elements within a layer. They have **generate** and **visible** properties.

![](../images/composer_screens.png)

Use the **Schemes** pane to create **schemes**. Schemes contain all the colors used in displaying a widget. Schemes are defined independently of widgets. Schemes are assigned to widget using properties editer. 

![](../images/composer_schemes.png)

Use the **Widget Tool Box** pane to create **widgets**. Widgets are the essential items in a user interface. Widgets allow users to view and interact with data of an applications. Widgets are used display data, report status, and receive input. Widget are able to contain other widgets.

![](../images/composer_widget_tool_box.png)


Use the **Properties** pane to adjust widget **properites**. Widget properties adjust the widget content or behavior directly before and during application execution. The property editor is used to set default values, enable features, set schemes, and establish user events.

![](../images/composer_properties_editor.png)
