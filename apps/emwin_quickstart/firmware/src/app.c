/*******************************************************************************
  MPLAB Harmony Application Source File

  Company:
    Microchip Technology Inc.

  File Name:
    app.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It
    implements the logic of the application's state machine and it may call
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "app.h"
#include "configuration.h"
#include "definitions.h"
#include "gfx/emwin/emwin_config.h"
#include "emwin_gui/DLG.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.

    Application strings and buffers are be defined outside this structure.
*/

APP_DATA appData;

// EMWIN USER START (Mandatory add screens here)

EMWIN_GUI_SCREEN_CREATE emWinScreenCreate[ EMWIN_GUI_NUM_SCREENS ]
                                         = { CreateHomePage,
                                             CreateNumberChurning,
                                             CreateTextAlignment };

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************
void APP_ScreenInitialize ( void )
{   
    GUI_SetBkColor(GUI_BLACK);
    GUI_Clear();
}
// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP_Initialize ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Initialize ( void )
{
    int32_t screenCount = 0;
    
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;

// EMWIN USER START (Mandatory)
    
    
    
    /* Register Screen Initialization */
    emWin_GuiScreenInitializeRegister( APP_ScreenInitialize );
            
    /* Register Screens */
    for( screenCount = 0; screenCount < EMWIN_GUI_NUM_SCREENS; screenCount++ )
    {
        emWin_GuiScreenRegister( screenCount, emWinScreenCreate[screenCount]);
    }
    
    /* set the start screen */
    emWin_GuiStartScreenSet( EMWIN_APP_SCREEN_HOME_PAGE );
    
// EMWIN USER END
    
}


/******************************************************************************
  Function:
    void APP_Tasks ( void )

  Remarks:
    See prototype in app.h.
 */

void APP_Tasks ( void )
{

    /* Check the application's current state. */
    switch ( appData.state )
    {
        /* Application's initial state. */
        case APP_STATE_INIT:
        {
            bool appInitialized = true;


            if (appInitialized)
            {

                appData.state = APP_STATE_SERVICE_TASKS;
            }
            break;
        }

        case APP_STATE_SERVICE_TASKS:
        {
            break;
        }

        /* TODO: implement your application state machine.*/


        /* The default state should never be executed. */
        default:
        {
            /* TODO: Handle error in application's state machine. */
            break;
        }
    }
}

/*******************************************************************************
 End of File
 */
