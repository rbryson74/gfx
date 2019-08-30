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

def instantiateComponent(component):
	projectPath = "config/" + Variables.get("__CONFIGURATION_NAME") + "/gfx/emwin"
	
	component.setHelpFile("../../doc/html/help_harmony_gfx_html_alias.h")
	
	execfile(Module.getPath() + "/config/emwin_config.py")
	execfile(Module.getPath() + "/config/emwin_files.py")

	EMWIN_SYS_DEFINITIONS_H = component.createFileSymbol("EMWIN_SYS_DEFINITIONS_H", None)
	EMWIN_SYS_DEFINITIONS_H.setType("STRING")
	EMWIN_SYS_DEFINITIONS_H.setOutputName("core.LIST_SYSTEM_DEFINITIONS_H_INCLUDES")
	EMWIN_SYS_DEFINITIONS_H.setSourcePath("templates/system/emwin_definitions.h.ftl")
	EMWIN_SYS_DEFINITIONS_H.setMarkup(True)
	
	EMWIN_SYS_INIT_C = component.createFileSymbol("EMWIN_SYS_INIT_C", None)
	EMWIN_SYS_INIT_C.setType("STRING")
	EMWIN_SYS_INIT_C.setOutputName("core.LIST_SYSTEM_INIT_C_INITIALIZE_MIDDLEWARE")
	EMWIN_SYS_INIT_C.setSourcePath("templates/system/emwin_init.c.ftl")
	EMWIN_SYS_INIT_C.setMarkup(True)

	EMWIN_SYS_TASK_C = component.createFileSymbol("EMWIN_SYS_TASK_C", None)
	EMWIN_SYS_TASK_C.setType("STRING")
	EMWIN_SYS_TASK_C.setOutputName("core.LIST_SYSTEM_TASKS_C_CALL_LIB_TASKS")
	EMWIN_SYS_TASK_C.setSourcePath("templates/system/emwin_tasks.c.ftl")
	EMWIN_SYS_TASK_C.setMarkup(True)

	#LIBARIA_SYS_RTOS_TASK_C = component.createFileSymbol("LIBARIA_SYS_RTOS_TASK_C", None)
	#LIBARIA_SYS_RTOS_TASK_C.setType("STRING")
	#LIBARIA_SYS_RTOS_TASK_C.setOutputName("core.LIST_SYSTEM_RTOS_TASKS_C_DEFINITIONS")
	#LIBARIA_SYS_RTOS_TASK_C.setSourcePath("templates/system/emwin_rtos_tasks.c.ftl")
	#LIBARIA_SYS_RTOS_TASK_C.setMarkup(True)
	#LIBARIA_SYS_RTOS_TASK_C.setEnabled((Database.getSymbolValue("HarmonyCore", "SELECT_RTOS") != "BareMetal"))
	#LIBARIA_SYS_RTOS_TASK_C.setDependencies(enableAriaRTOSTask, ["HarmonyCore.SELECT_RTOS"])

	EMWIN_ControllerMenu = component.createMenuSymbol("EMWIN_DisplayControllerMenu", None)
	EMWIN_ControllerMenu.setLabel("Display Controller Setting")

        EMWIN_ControllerType = component.createComboSymbol("EMWIN_ControllerType", EMWIN_ControllerMenu, ["LCC", "GLCD", "S1D13517"])
	EMWIN_ControllerType.setLabel("Display Controller")
	EMWIN_ControllerType.setDescription("Display controller used for emWin")
	EMWIN_ControllerType.setDefaultValue("LCC")

	EMWIN_ColorMenu = component.createMenuSymbol("EMWIN_ColorFormatMenu", None)
	EMWIN_ColorMenu.setLabel("Color Format Setting")

        EMWIN_ColorFormat = component.createComboSymbol("EMWIN_ColorFormat", EMWIN_ColorMenu, ["EMWIN_COLOR_MODE_RGB_332", "EMWIN_COLOR_MODE_RGB_565", "EMWIN_COLOR_MODE_RGB_888", "EMWIN_COLOR_MODE_ARGB_888"])
	EMWIN_ColorFormat.setLabel("Color Format")
	EMWIN_ColorFormat.setDescription("Color format used for emWin")
	EMWIN_ColorFormat.setDefaultValue("EMWIN_COLOR_MODE_RGB_565")


def onAttachmentConnected(source, target):
	if source["id"] == "gfx_driver":
		driverName = target["component"].getSymbolValue("DriverInitName")
		source["component"].setSymbolValue("driverInitName", driverName)
		
	#if source["id"] == "gfx_hal":
	#	target["component"].setSymbolValue("GlobalPaletteModeHint", source["component"].getSymbolValue("useGlobalPalette"), 1)
	#	target["component"].setSymbolValue("DisableGlobalPaletteModeHint", True, 1)

def onAttachmentDisconnected(source, target):
	if source["id"] == "gfx_driver":
		source["component"].clearSymbolValue("driverInitName")

	#if source["id"] == "gfx_hal":
	#	target["component"].clearSymbolValue("GlobalPaletteModeHint")
	#	target["component"].clearSymbolValue("DisableGlobalPaletteModeHint")
	
	
"""def showAriaRTOSMenu(symbol, event):
	symbol.setVisible(event["value"] != "BareMetal")
	symbol.getComponent().getSymbolByID("useRTOSExtensions").setValue(event["value"] != "BareMetal", 1)
	
def enableAriaRTOSExtensions(symbol, event):
	enableAriaExtensionsFiles(symbol.getComponent(), event["value"] == True)

def enableAriaRTOSSymbol(symbol, event):
	if (event["value"] == "True"):
		symbol.setEnabled(True)
	else:
		symbol.setEnabled(False)

	
def enableAriaRTOSTask(symbol, event):
    if (event["value"] != "BareMetal"):
        symbol.setEnabled(True)
    else:
        symbol.setEnabled(False)"""
