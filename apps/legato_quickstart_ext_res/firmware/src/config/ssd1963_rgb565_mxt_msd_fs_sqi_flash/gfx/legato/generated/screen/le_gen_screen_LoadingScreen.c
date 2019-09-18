#include "gfx/legato/generated/screen/le_gen_screen_LoadingScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget0;
leButtonWidget* ButtonWidget_Wait;
leLabelWidget* LabelWidget_Wait;
leButtonWidget* ButtonWidget_MainScreen;

// string list for this screen
static leTableString tableString_WaitForUSB;
static leTableString tableString_WaitForUSBAlt;
static leTableString tableString_PressToMainScreen;

// event handlers
static void ButtonWidget_Wait_OnReleased(leButtonWidget* btn)
;

static void ButtonWidget_MainScreen_OnReleased(leButtonWidget* btn)
;


static leBool showing = LE_FALSE;

leResult screenInit_LoadingScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_LoadingScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_WaitForUSB, string_WaitForUSB);
    leTableString_Constructor(&tableString_WaitForUSBAlt, string_WaitForUSBAlt);
    leTableString_Constructor(&tableString_PressToMainScreen, string_PressToMainScreen);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget0 = leWidget_New();
    PanelWidget0->fn->setPosition(PanelWidget0, 0, 0);
    PanelWidget0->fn->setSize(PanelWidget0, 480, 272);
    PanelWidget0->fn->setScheme(PanelWidget0, &WhiteScheme);
    root0->fn->addChild(root0, PanelWidget0);

    ButtonWidget_Wait = leButtonWidget_New();
    ButtonWidget_Wait->fn->setPosition(ButtonWidget_Wait, 0, 0);
    ButtonWidget_Wait->fn->setSize(ButtonWidget_Wait, 480, 272);
    ButtonWidget_Wait->fn->setBackgroundType(ButtonWidget_Wait, LE_WIDGET_BACKGROUND_NONE);
    ButtonWidget_Wait->fn->setBorderType(ButtonWidget_Wait, LE_WIDGET_BORDER_NONE);
    ButtonWidget_Wait->fn->setString(ButtonWidget_Wait, (leString*)&tableString_WaitForUSB);
    ButtonWidget_Wait->fn->setReleasedEventCallback(ButtonWidget_Wait, ButtonWidget_Wait_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget_Wait);

    LabelWidget_Wait = leLabelWidget_New();
    LabelWidget_Wait->fn->setPosition(LabelWidget_Wait, 9, 7);
    LabelWidget_Wait->fn->setSize(LabelWidget_Wait, 463, 92);
    LabelWidget_Wait->fn->setBackgroundType(LabelWidget_Wait, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget_Wait->fn->setHAlignment(LabelWidget_Wait, LE_HALIGN_CENTER);
    LabelWidget_Wait->fn->setString(LabelWidget_Wait, (leString*)&tableString_WaitForUSBAlt);
    ButtonWidget_Wait->fn->addChild(ButtonWidget_Wait, (leWidget*)LabelWidget_Wait);

    ButtonWidget_MainScreen = leButtonWidget_New();
    ButtonWidget_MainScreen->fn->setPosition(ButtonWidget_MainScreen, 51, 182);
    ButtonWidget_MainScreen->fn->setSize(ButtonWidget_MainScreen, 380, 54);
    ButtonWidget_MainScreen->fn->setString(ButtonWidget_MainScreen, (leString*)&tableString_PressToMainScreen);
    ButtonWidget_MainScreen->fn->setReleasedEventCallback(ButtonWidget_MainScreen, ButtonWidget_MainScreen_OnReleased);
    root0->fn->addChild(root0, (leWidget*)ButtonWidget_MainScreen);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_LoadingScreen()
{
}

void screenHide_LoadingScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget0 = NULL;
    ButtonWidget_Wait = NULL;
    LabelWidget_Wait = NULL;
    ButtonWidget_MainScreen = NULL;

    tableString_WaitForUSB.fn->destructor(&tableString_WaitForUSB);
    tableString_WaitForUSBAlt.fn->destructor(&tableString_WaitForUSBAlt);
    tableString_PressToMainScreen.fn->destructor(&tableString_PressToMainScreen);
    showing = LE_FALSE;
}

void screenDestroy_LoadingScreen()
{

}

leWidget* screenGetRoot_LoadingScreen(uint32_t lyrIdx)
{
    if(lyrIdx >= LE_LAYER_COUNT)
        return NULL;

    switch(lyrIdx)
    {
        case 0:
        {
            return root0;
        }
        default:
        {
            return NULL;
        }
    }
}

// event handlers
void ButtonWidget_Wait_OnReleased(leButtonWidget* btn)
{
}


void ButtonWidget_MainScreen_OnReleased(leButtonWidget* btn)
{
    // Show Screen (MainScreen) - ShowScreen - MainScreen
    legato_showScreen(screenID_MainScreen);

}



