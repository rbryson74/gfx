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

############ GLCD + TOUCH I2C CONFIG ######################################################
skActivateList = ["gfx_driver_glcd", "i2c1", "drv_i2c", "drv_i2c0", "core_timer", "sys_time", "ddr"]
skAutoConnectList = [["gfx_hal", "gfx_display_driver", "gfx_driver_glcd", "gfx_driver_glcd"],
					["drv_i2c_0", "drv_i2c_I2C_dependency", "i2c1", "I2C1_I2C"],
					["gfx_maxtouch_controller", "i2c", "drv_i2c_0", "drv_i2c"],
					["sys_time", "sys_time_TMR_dependency", "core_timer", "CORE_TIMER_TMR"]]
skPinConfig = [{"pin": 16, "name": "CAMERA_ENABLE", "type": "GPIO", "direction": "Out", "latch": "", "abcd": "B"}, #RE4, B3
				{"pin": 22, "name": "BSP_MAXTOUCH_CHG", "type": "GPIO", "direction": "In", "latch": "", "abcd": "B"}, #RB1, B9
				{"pin": 146, "name": "TM4301B_BACKLIGHT", "type": "GPIO", "direction": "Out", "latch": "High", "abcd": ""}, #RE3, M3
				{"pin": 154, "name": "SCL1", "type": "SCL1", "direction": "", "latch": "", "abcd": ""}, #RA14, M11
				{"pin": 167, "name": "SDA1", "type": "SDA1", "direction": "", "latch": "", "abcd": ""}] #RA15, N11
##################################################################################

def eventHandler(event):
	if (event == "configure"):
		try:
			Database.setSymbolValue("gfx_driver_glcd", "PixelClockDivider", 6, 1)
			Database.setSymbolValue("gfx_hal", "ColorModeHint", "GFX_COLOR_MODE_RGBA_8888", 1)
			### Temporary fuse settings
			Database.setSymbolValue("core", "CONFIG_POSCMOD", "EC", 1)
			Database.setSymbolValue("core", "CONFIG_ICESEL", "ICS_PGx2", 1)
			Database.setSymbolValue("core", "CONFIG_POSCAGC", "OFF", 1)
		except:
			return

bspDisplayInterfaceList = ["GLCD"]

pic32mz_das_sk_meb2 = bspSupportObj(skPinConfig, skActivateList, None, skAutoConnectList, eventHandler)

addBSPSupport("BSP_PIC32MZ_DA_Starter_Kit", "GLCD", pic32mz_das_sk_meb2)
addDisplayIntfSupport("BSP_PIC32MZ_DA_Starter_Kit", bspDisplayInterfaceList)

#override default pin config fxn w/ PIC32M version
pinConfigureFxn = configurePinsPIC32M