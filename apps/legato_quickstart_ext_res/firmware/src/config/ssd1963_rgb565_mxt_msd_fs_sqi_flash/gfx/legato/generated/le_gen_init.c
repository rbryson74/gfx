#include "gfx/legato/generated/le_gen_init.h"

static uint32_t currentScreen;

void legato_initialize(void)
{
    legato_initialize_schemes();

    leSetStringTable(&stringTable);

    currentScreen = -1;

    legato_showScreen(screenID_LoadingScreen);
}

uint32_t legato_getCurrentScreen(void)
{
    return currentScreen;
}

void legato_hideCurrentScreen()
{
    switch(currentScreen)
    {
        case screenID_LoadingScreen:
        {
            screenHide_LoadingScreen();
            currentScreen = 0;
            break;
        }
        case screenID_MainScreen:
        {
            screenHide_MainScreen();
            currentScreen = 0;
            break;
        }
    }
}

void legato_showScreen(uint32_t id)
{
    legato_hideCurrentScreen(currentScreen);

    switch(id)
    {
        case screenID_LoadingScreen:
        {
            screenShow_LoadingScreen();
            currentScreen = id;
            break;
        }
        case screenID_MainScreen:
        {
            screenShow_MainScreen();
            currentScreen = id;
            break;
        }
    }
}

void legato_updateCurrentScreen(void)
{
    switch(currentScreen)
    {
    }
}

