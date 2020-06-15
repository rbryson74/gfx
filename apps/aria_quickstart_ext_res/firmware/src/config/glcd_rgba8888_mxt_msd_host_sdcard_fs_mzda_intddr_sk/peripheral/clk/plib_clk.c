/*******************************************************************************
  SYS CLK Static Functions for Clock System Service

  Company:
    Microchip Technology Inc.

  File Name:
    plib_clk.c

  Summary:
    SYS CLK static function implementations for the Clock System Service.

  Description:
    The Clock System Service provides a simple interface to manage the
    oscillators on Microchip microcontrollers. This file defines the static
    implementation for the Clock System Service.

  Remarks:
    Static functions incorporate all system clock configuration settings as
    determined by the user via the Microchip Harmony Configurator GUI.
    It provides static version of the routines, eliminating the need for an
    object ID or object handle.

    Static single-open interfaces also eliminate the need for the open handle.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2019 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Include Files
// *****************************************************************************
// *****************************************************************************

#include "device.h"
#include "plib_clk.h"

// *****************************************************************************
// *****************************************************************************
// Section: File Scope Functions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void CLK_Initialize( void )

  Summary:
    Initializes hardware and internal data structure of the System Clock.

  Description:
    This function initializes the hardware and internal data structure of System
    Clock Service.

  Remarks:
    This is configuration values for the static version of the Clock System
    Service module is determined by the user via the MHC GUI.

    The objective is to eliminate the user's need to be knowledgeable in the
    function of the 'configuration bits' to configure the system oscillators.
*/

void CLK_Initialize( void )
{
    bool int_flag = false;

    int_flag = (bool)__builtin_disable_interrupts();

    /* unlock system for clock configuration */
    SYSKEY = 0x00000000;
    SYSKEY = 0xAA996655;
    SYSKEY = 0x556699AA;

    if (int_flag)
    {
        __builtin_mtc0(12, 0,(__builtin_mfc0(12, 0) | 0x0001)); /* enable interrupts */
    }


    /* Set up Reference Clock 2 */
    /* REFO2CON register */
    /* ROSEL =  SYSCLK */
    /* DIVSWEN = 1 */
    /* RODIV = 5 */
    REFO2CON = 0x50200;

    /* Enable oscillator (ON bit) */
    REFO2CONSET = 0x00008000;

    /* Set up Reference Clock 4 */
    /* Enable oscillator (ON bit) */
    REFO4CONSET = 0x00008000;

    /* Set up Reference Clock 5 */
    /* REFO5CON register */
    /* ROSEL =  SYSCLK */
    /* DIVSWEN = 1 */
    /* RODIV = 1 */
    REFO5CON = 0x10200;

    /* Enable oscillator (ON bit) */
    REFO5CONSET = 0x00008000;

    /* CFGMPLL */
    /* MPLLVREGDIS = ENABLED */
    /* INTVREFCON = EXTERNAL_DDRV */
    /* MPLLIDIV = DIV_1 */
    /* MPLLMULT = MUL_25 */
    /* MPLLODIV2 = DIV_1 */
    /* MPLLODIV1 = DIV_3 */
    /* MPLLDIS = ENABLED */

    CFGMPLLbits.MPLLVREGDIS = 0;

    while(!(CFGMPLLbits.MPLLVREGRDY));

    CFGMPLL = 0x0B001901;

    while(!(CFGMPLLbits.MPLLRDY));
  

    /* Peripheral Module Disable Configuration */
    PMD1 = 0x101101;
    PMD2 = 0x3;
    PMD3 = 0x1ff01ff;
    PMD4 = 0x1ff;
    PMD5 = 0xfefeffff;
    PMD6 = 0xffc9e0ff;
    PMD7 = 0xefffffef;

    /* Lock system since done with clock configuration */
    int_flag = (bool)__builtin_disable_interrupts();

    SYSKEY = 0x33333333;

    if (int_flag) /* if interrupts originally were enabled, re-enable them */
    {
        __builtin_mtc0(12, 0,(__builtin_mfc0(12, 0) | 0x0001));
    }
}
