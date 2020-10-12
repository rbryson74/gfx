# coding: utf-8
##############################################################################
# Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
#
# Subject to your compliance with these terms, you may use Microchip software
# and any derivatives exclusively with Microchip products. It is your
# responsibility to comply with third party license terms applicable to your
# use of third party software (including open source software) that may
# accompany Microchip software.
#
# THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
# EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
# WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
# PARTICULAR PURPOSE.
#
# IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
# INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
# WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
# BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
# FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
# ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
# THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
##############################################################################

driverInitName = component.createStringSymbol("driverInitName", None)
driverInitName.setVisible(False)
driverInitName.setReadOnly(True)

managedComment = component.createCommentSymbol("managedComment", None)
managedComment.setLabel('All settings are managed through the Graphics Composer Tool.')
managedComment.setVisible(True)

managedComment2 = component.createCommentSymbol("managedComment2", None)
managedComment2.setLabel('This tool can be launched through the Tools->Graphics Composer option.')
managedComment2.setVisible(True)

useAutoGeneratedCode = component.createBooleanSymbol("useAutoGeneratedCode", None)
useAutoGeneratedCode.setVisible(False)

"""useComposerDesign = component.createBooleanSymbol("useComposerDesign", None)
useComposerDesign.setLabel("Use Graphics Composer Design")
useComposerDesign.setDefaultValue(True)
useComposerDesign.setDescription("Indicates that the code generator should include the generated graphics composer design files.")

managedComment = component.createCommentSymbol("managedComment", None)
managedComment.setLabel('These settings are currently hidden.  They can be adjusted through the graphics composer tool or by deselecting the "Use Graphics Composer Design" option.')
managedComment.setVisible(False)



widgetMenu = component.createMenuSymbol("widgetMenu", None)
widgetMenu.setLabel("Widget Configuration")
widgetMenu.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableArcWidget = component.createBooleanSymbol("enableArcWidget", widgetMenu)
enableArcWidget.setLabel("Enable Arc Widget?")
enableArcWidget.setDefaultValue(False)
enableArcWidget.setDescription("Enables the Arc widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableArcWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableBarGraphWidget = component.createBooleanSymbol("enableBarGraphWidget", widgetMenu)
enableBarGraphWidget.setLabel("Enable Bar Graph Widget?")
enableBarGraphWidget.setDefaultValue(False)
enableBarGraphWidget.setDescription("Enables the Bar Graph widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableBarGraphWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableButtonWidget = component.createBooleanSymbol("enableButtonWidget", widgetMenu)
enableButtonWidget.setLabel("Enable Button Widget?")
enableButtonWidget.setDefaultValue(False)
enableButtonWidget.setDescription("Enables the Button widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableButtonWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableCheckBoxWidget = component.createBooleanSymbol("enableCheckBoxWidget", widgetMenu)
enableCheckBoxWidget.setLabel("Enable Check Box Widget?")
enableCheckBoxWidget.setDefaultValue(False)
enableCheckBoxWidget.setDescription("Enables the Check Box widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableCheckBoxWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableCircleWidget = component.createBooleanSymbol("enableCircleWidget", widgetMenu)
enableCircleWidget.setLabel("Enable Circle Widget?")
enableCircleWidget.setDefaultValue(False)
enableCircleWidget.setDescription("Enables the Circle widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableCircleWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableCircularGaugeWidget = component.createBooleanSymbol("enableCircularGaugeWidget", widgetMenu)
enableCircularGaugeWidget.setLabel("Enable Circular Gauge Widget?")
enableCircularGaugeWidget.setDefaultValue(False)
enableCircularGaugeWidget.setDescription("Enables the Circular Gauge widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableCircularGaugeWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableCircularSliderWidget = component.createBooleanSymbol("enableCircularSliderWidget", widgetMenu)
enableCircularSliderWidget.setLabel("Enable Circular Slider Widget?")
enableCircularSliderWidget.setDefaultValue(False)
enableCircularSliderWidget.setDescription("Enables the Circular Slider widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableCircularSliderWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableDrawSurfaceWidget = component.createBooleanSymbol("enableDrawSurfaceWidget", widgetMenu)
enableDrawSurfaceWidget.setLabel("Enable Draw Surface Widget?")
enableDrawSurfaceWidget.setDefaultValue(False)
enableDrawSurfaceWidget.setDescription("Enables the Draw Surface widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableDrawSurfaceWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableGradientWidget = component.createBooleanSymbol("enableGradientWidget", widgetMenu)
enableGradientWidget.setLabel("Enable Gradient Widget?")
enableGradientWidget.setDefaultValue(False)
enableGradientWidget.setDescription("Enables the Gradient widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableGradientWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableGroupBoxWidget = component.createBooleanSymbol("enableGroupBoxWidget", widgetMenu)
enableGroupBoxWidget.setLabel("Enable Group Box Widget?")
enableGroupBoxWidget.setDefaultValue(False)
enableGroupBoxWidget.setDescription("Enables the Group Box widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableGroupBoxWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableImageWidget = component.createBooleanSymbol("enableImageWidget", widgetMenu)
enableImageWidget.setLabel("Enable Image Widget?")
enableImageWidget.setDefaultValue(False)
enableImageWidget.setDescription("Enables the Image widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableImageWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableImagePlusWidget = component.createBooleanSymbol("enableImagePlusWidget", widgetMenu)
enableImagePlusWidget.setLabel("Enable Image Plus Widget?")
enableImagePlusWidget.setDefaultValue(False)
enableImagePlusWidget.setDescription("Enables the Image Plus widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableImagePlusWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableImageSequenceWidget = component.createBooleanSymbol("enableImageSequenceWidget", widgetMenu)
enableImageSequenceWidget.setLabel("Enable Image Sequence Widget?")
enableImageSequenceWidget.setDefaultValue(False)
enableImageSequenceWidget.setDescription("Enables the Image Sequence widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableImageSequenceWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableKeyPadWidget = component.createBooleanSymbol("enableKeyPadWidget", widgetMenu)
enableKeyPadWidget.setLabel("Enable Key Pad Widget?")
enableKeyPadWidget.setDefaultValue(False)
enableKeyPadWidget.setDescription("Enables the Key Pad widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableKeyPadWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableLabelWidget = component.createBooleanSymbol("enableLabelWidget", widgetMenu)
enableLabelWidget.setLabel("Enable Label Widget?")
enableLabelWidget.setDefaultValue(False)
enableLabelWidget.setDescription("Enables the Label widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableLabelWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableLineWidget = component.createBooleanSymbol("enableLineWidget", widgetMenu)
enableLineWidget.setLabel("Enable Line Widget?")
enableLineWidget.setDefaultValue(False)
enableLineWidget.setDescription("Enables the Line widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableLineWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableLineGraphWidget = component.createBooleanSymbol("enableLineGraphWidget", widgetMenu)
enableLineGraphWidget.setLabel("Enable Line Graph Widget?")
enableLineGraphWidget.setDefaultValue(False)
enableLineGraphWidget.setDescription("Enables the Line Graph widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableLineGraphWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableListWidget = component.createBooleanSymbol("enableListWidget", widgetMenu)
enableListWidget.setLabel("Enable List Widget?")
enableListWidget.setDefaultValue(False)
enableListWidget.setDescription("Enables the List widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableListWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableListWheelWidget = component.createBooleanSymbol("enableListWheelWidget", widgetMenu)
enableListWheelWidget.setLabel("Enable List Wheel Widget?")
enableListWheelWidget.setDefaultValue(False)
enableListWheelWidget.setDescription("Enables the List Wheel widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableListWheelWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enablePieChartWidget = component.createBooleanSymbol("enablePieChartWidget", widgetMenu)
enablePieChartWidget.setLabel("Enable Pie Chart Widget?")
enablePieChartWidget.setDefaultValue(False)
enablePieChartWidget.setDescription("Enables the Pie Chart widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enablePieChartWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableProgressBarWidget = component.createBooleanSymbol("enableProgressBarWidget", widgetMenu)
enableProgressBarWidget.setLabel("Enable Progress Bar Widget?")
enableProgressBarWidget.setDefaultValue(False)
enableProgressBarWidget.setDescription("Enables the Progress Bar widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableProgressBarWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableRadialMenuWidget = component.createBooleanSymbol("enableRadialMenuWidget", widgetMenu)
enableRadialMenuWidget.setLabel("Enable Radial Menu Widget?")
enableRadialMenuWidget.setDefaultValue(False)
enableRadialMenuWidget.setDescription("Enables the Radial Menu widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableRadialMenuWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableRadioButtonWidget = component.createBooleanSymbol("enableRadioButtonWidget", widgetMenu)
enableRadioButtonWidget.setLabel("Enable Radio Button Widget?")
enableRadioButtonWidget.setDefaultValue(False)
enableRadioButtonWidget.setDescription("Enables the Radio Button widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableRadioButtonWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableRectangleWidget = component.createBooleanSymbol("enableRectangleWidget", widgetMenu)
enableRectangleWidget.setLabel("Enable Rectangle Widget?")
enableRectangleWidget.setDefaultValue(False)
enableRectangleWidget.setDescription("Enables the Rectangle widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableRectangleWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableScrollBarWidget = component.createBooleanSymbol("enableScrollBarWidget", widgetMenu)
enableScrollBarWidget.setLabel("Enable Scroll Bar Widget?")
enableScrollBarWidget.setDefaultValue(False)
enableScrollBarWidget.setDescription("Enables the Scroll Bar widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableScrollBarWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableSliderWidget = component.createBooleanSymbol("enableSliderWidget", widgetMenu)
enableSliderWidget.setLabel("Enable Slider Widget?")
enableSliderWidget.setDefaultValue(False)
enableSliderWidget.setDescription("Enables the Slider widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableSliderWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableTextFieldWidget = component.createBooleanSymbol("enableTextFieldWidget", widgetMenu)
enableTextFieldWidget.setLabel("Enable Text Field Widget?")
enableTextFieldWidget.setDefaultValue(False)
enableTextFieldWidget.setDescription("Enables the Text Field widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableTextFieldWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableTouchTestWidget = component.createBooleanSymbol("enableTouchTestWidget", widgetMenu)
enableTouchTestWidget.setLabel("Enable Touch Test Widget?")
enableTouchTestWidget.setDefaultValue(False)
enableTouchTestWidget.setDescription("Enables the Touch Test widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableTouchTestWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

enableWindowWidget = component.createBooleanSymbol("enableWindowWidget", widgetMenu)
enableWindowWidget.setLabel("Enable Window Widget?")
enableWindowWidget.setDefaultValue(False)
enableWindowWidget.setDescription("Enables the Window widget.  Disabling this will remove the code for this widget and it will not be available for use.")
enableWindowWidget.setHelp("IDH_HTML_MHGC_UG_Widget_Tool_Box_Panel")

codeGenerationMenu = component.createMenuSymbol("codeGenerationMenu", None)
codeGenerationMenu.setLabel("Code Generator Options")

genMediaIntf = component.createBooleanSymbol("genMediaIntf", codeGenerationMenu)
genMediaIntf.setLabel("Generate External Media Interface")
genMediaIntf.setDefaultValue(False)
genMediaIntf.setDescription("Indicates that the code generator should create the binding code to allow the library to request external media data.")

enableInput = component.createBooleanSymbol("enableInput", codeGenerationMenu)
enableInput.setLabel("Enable Input Event Interface?")
enableInput.setDefaultValue(False)
enableInput.setDescription("Indicates that the library should interface with the Input System Service for input events.")
#enableInput.setDependencies(onEnableInputChanged, ["enableInput"])

settingsMenu = component.createMenuSymbol("generalSettings", None)
settingsMenu.setLabel("General Settings")

layerCount = component.createIntegerSymbol("layerCount", settingsMenu)
layerCount.setLabel("Root Layer Count")
layerCount.setDefaultValue(1)
layerCount.setMin(1)
layerCount.setMax(5)
layerCount.setDescription("Configures the number of root widget layers that the graphics library should create.  The display driver should match this amount.  If the library is configured to use more than the driver can support then rendering anomalies may occur.")

preemptionLevel = component.createComboSymbol("preemptionLevel", settingsMenu, ["0", "1", "2"])
preemptionLevel.setLabel("Preemption Level")
preemptionLevel.setDefaultValue("0")
preemptionLevel.setDescription("Configures the library's self-imposed preemption level.  0 is fully blocking.  2 is fully self-preempting.")

externalStreamingEnabled = component.createBooleanSymbol("externalStreamingEnabled", settingsMenu)
externalStreamingEnabled.setLabel("Enable External Media Streaming")
externalStreamingEnabled.setDefaultValue(False)
externalStreamingEnabled.setDescription("Enables the use of external media streaming interfaces.  Allows font and image data to be streamed from external memory storage locations.")

include1BPPFont = component.createBooleanSymbol("include1BPPFont", settingsMenu)
include1BPPFont.setLabel("Include Default 1BPP Font")
include1BPPFont.setDefaultValue(False)
include1BPPFont.setDescription("Includes a built-in 12 point 1bpp ASCII font in the library.  Consumes memory but doesn't require external assets.  See associated Liberation font license for details.")

include8BPPFont = component.createBooleanSymbol("include8BPPFont", settingsMenu)
include8BPPFont.setLabel("Include Default 8BPP Font")
include8BPPFont.setDefaultValue(False)
include8BPPFont.setDescription("Includes a built-in 12 point 8bpp antialiased ASCII font in the library.  Consumes memory but doesn't require external assets.  See associated Liberation font license for details.")

rendererMenu = component.createMenuSymbol("rendererMenu", None)
rendererMenu.setLabel("Renderer Options")

scratchBufferSize = component.createIntegerSymbol("scratchBufferSize", rendererMenu)
scratchBufferSize.setLabel("Scratch Buffer Size")
scratchBufferSize.setMin(1)
scratchBufferSize.setDefaultValue(16)
scratchBufferSize.setDescription("Sets the size of the scratch buffer in kilobytes.  Larger buffers may increase performance at the cost of memory.  Smaller may produce visual artifacts during rendering.")

useAlphaBlending = component.createBooleanSymbol("useAlphaBlending", rendererMenu)
useAlphaBlending.setLabel("Enable Alpha Blending")
useAlphaBlending.setDefaultValue(False)
useAlphaBlending.setDescription("Enables alpha blending on a per-widget basis.  Disable for increased performace.")

debugMenu = component.createMenuSymbol("debugMenu", None)
debugMenu.setLabel("Debug Options")

assertsEnabled = component.createBooleanSymbol("assertsEnabled", debugMenu)
assertsEnabled.setLabel("Enable Asserts")
assertsEnabled.setDefaultValue(False)
assertsEnabled.setDescription("Indicates that any configured assets should be automatically generated and added to the application.")

zeroizeMemory = component.createBooleanSymbol("zeroizeMemory", debugMenu)
zeroizeMemory.setLabel("Zeroize Memory Allocations")
zeroizeMemory.setDefaultValue(False)
zeroizeMemory.setDescription("Automatically zeroizes memory allocations.  Useful for debugging purposes but adds overhead.")

useDebugAllocator = component.createBooleanSymbol("useDebugAllocator", debugMenu)
useDebugAllocator.setLabel("Use Debug Memory Allocator")
useDebugAllocator.setDefaultValue(False)
useDebugAllocator.setDescription("Enables debug memory allocator interface.  Allows for advanced memory verification and tracking capabilities at the cost of memory consumption.")

useAllocationTracking = component.createBooleanSymbol("useAllocationTracking", debugMenu)
useAllocationTracking.setLabel("Use Debug Memory Tracking")
useAllocationTracking.setDefaultValue(False)
useAllocationTracking.setDescription("Enables memory allocation tracking.  Every memory allocation will be stamped with file, line, and function information.  Useful for tracking memory leaks or other issues.")

memoryMenu = component.createMenuSymbol("memoryMenu", None)
memoryMenu.setLabel("Memory Manager Configuration")

variableHeapMenu = component.createMenuSymbol("variableHeapMenu", memoryMenu)
variableHeapMenu.setLabel("Variable Heap")

variableHeapSize = component.createIntegerSymbol("variableHeapSize", variableHeapMenu)
variableHeapSize.setLabel("Size")
variableHeapSize.setMin(0)
variableHeapSize.setDefaultValue(2048)
variableHeapSize.setDescription("Sets the size of the variable heap in bytes.")

variableHeapMinAllocSize = component.createIntegerSymbol("variableHeapMinAllocSize", variableHeapMenu)
variableHeapMinAllocSize.setLabel("Minimum Allocation Size")
variableHeapMinAllocSize.setMin(4)
variableHeapMinAllocSize.setDefaultValue(32)
variableHeapMinAllocSize.setDescription("Sets the minimum allocation size of the variable heap.  This is the smallest allocation size the heap will allow.")

variableHeapUseBestFit = component.createComboSymbol("variableHeapUseBestFit", variableHeapMenu, ["Best Fit", "First Fit"])
variableHeapUseBestFit.setLabel("Allocation Method")
variableHeapUseBestFit.setDefaultValue("Best Fit")
variableHeapUseBestFit.setDescription("Sets the allocation method for the variable heap.  Best fit is more efficient in space.  First fit is more efficient in time.")

variableHeapDebugLevel = component.createComboSymbol("variableHeapDebugLevel", variableHeapMenu, ["0", "1", "2"])
variableHeapDebugLevel.setLabel("Debug Level")
variableHeapDebugLevel.setDefaultValue("0")
variableHeapDebugLevel.setDescription("Configures the debug level for the heap.  0 is no debugging.  2 is full debugging.  Debugging verifies checksums and debug memory fill values and tracks allocation statistics at the cost of time and memory space.")

fixedHeapEnable = component.createBooleanSymbol("fixedHeapEnable", memoryMenu)
fixedHeapEnable.setLabel("Enable Fixed Heap")
fixedHeapEnable.setDefaultValue(True)

fixedHeapSize16 = component.createIntegerSymbol("fixedHeapSize16", fixedHeapEnable)
fixedHeapSize16.setLabel("16 byte entries")
fixedHeapSize16.setMin(1)
fixedHeapSize16.setDefaultValue(300)
fixedHeapSize16.setDescription("Sets the number of 16 byte fixed heap entries.")

fixedHeapSize32 = component.createIntegerSymbol("fixedHeapSize32", fixedHeapEnable)
fixedHeapSize32.setLabel("32 byte entries")
fixedHeapSize32.setMin(1)
fixedHeapSize32.setDefaultValue(96)
fixedHeapSize32.setDescription("Sets the number of 32 byte fixed heap entries.")

fixedHeapSize64 = component.createIntegerSymbol("fixedHeapSize64", fixedHeapEnable)
fixedHeapSize64.setLabel("64 byte entries")
fixedHeapSize64.setMin(1)
fixedHeapSize64.setDefaultValue(96)
fixedHeapSize64.setDescription("Sets the number of 64 byte fixed heap entries.")

fixedHeapSize128 = component.createIntegerSymbol("fixedHeapSize128", fixedHeapEnable)
fixedHeapSize128.setLabel("128 byte entries")
fixedHeapSize128.setMin(1)
fixedHeapSize128.setDefaultValue(32)
fixedHeapSize128.setDescription("Sets the number of 32 byte fixed heap entries.")

fixedHeapSize196 = component.createIntegerSymbol("fixedHeapSize196", fixedHeapEnable)
fixedHeapSize196.setLabel("196 byte entries")
fixedHeapSize196.setMin(1)
fixedHeapSize196.setDefaultValue(48)
fixedHeapSize196.setDescription("Sets the number of 196 byte fixed heap entries.")

fixedHeapSize256 = component.createIntegerSymbol("fixedHeapSize256", fixedHeapEnable)
fixedHeapSize256.setLabel("256 byte entries")
fixedHeapSize256.setMin(1)
fixedHeapSize256.setDefaultValue(24)
fixedHeapSize256.setDescription("Sets the number of 256 byte fixed heap entries.")

fixedHeapDebugEnable = component.createBooleanSymbol("fixedHeapDebugEnable", fixedHeapEnable)
fixedHeapDebugEnable.setLabel("Debug Enable")
fixedHeapDebugEnable.setDefaultValue(False)
fixedHeapDebugEnable.setDescription("Configures the debug mode for the fixed heaps.  Debugging verifies checksums and debug memory fill values and tracks allocation statistics at the cost of time and memory space.")
"""