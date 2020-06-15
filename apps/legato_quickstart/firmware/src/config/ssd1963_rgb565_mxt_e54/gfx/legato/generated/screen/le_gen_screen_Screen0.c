#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
leWidget* root0;

leWidget* Screen0_PanelWidget0;
leImageWidget* Screen0_LogoWidget;
leLabelWidget* Screen0_TitleLabel;
leButtonWidget* Screen0_SloganButton;

// string list for this screen
static leTableString string_TitleString;
static leTableString string_Slogan;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_Screen0()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_Screen0()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&string_TitleString, stringID_TitleString);
    leTableString_Constructor(&string_Slogan, stringID_Slogan);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    Screen0_PanelWidget0 = leWidget_New();
    Screen0_PanelWidget0->fn->setPosition(Screen0_PanelWidget0, 0, 0);
    Screen0_PanelWidget0->fn->setSize(Screen0_PanelWidget0, 480, 272);
    Screen0_PanelWidget0->fn->setScheme(Screen0_PanelWidget0, &DefaultScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_PanelWidget0);

    Screen0_LogoWidget = leImageWidget_New();
    Screen0_LogoWidget->fn->setPosition(Screen0_LogoWidget, 161, 51);
    Screen0_LogoWidget->fn->setSize(Screen0_LogoWidget, 150, 150);
    Screen0_LogoWidget->fn->setBackgroundType(Screen0_LogoWidget, LE_WIDGET_BACKGROUND_NONE);
    Screen0_LogoWidget->fn->setBorderType(Screen0_LogoWidget, LE_WIDGET_BORDER_NONE);
    Screen0_LogoWidget->fn->setImage(Screen0_LogoWidget, (leImage*)&MHGC_150x150);
    root0->fn->addChild(root0, (leWidget*)Screen0_LogoWidget);

    Screen0_TitleLabel = leLabelWidget_New();
    Screen0_TitleLabel->fn->setPosition(Screen0_TitleLabel, 71, 18);
    Screen0_TitleLabel->fn->setSize(Screen0_TitleLabel, 343, 25);
    Screen0_TitleLabel->fn->setBackgroundType(Screen0_TitleLabel, LE_WIDGET_BACKGROUND_NONE);
    Screen0_TitleLabel->fn->setHAlignment(Screen0_TitleLabel, LE_HALIGN_CENTER);
    Screen0_TitleLabel->fn->setString(Screen0_TitleLabel, (leString*)&string_TitleString);
    root0->fn->addChild(root0, (leWidget*)Screen0_TitleLabel);

    Screen0_SloganButton = leButtonWidget_New();
    Screen0_SloganButton->fn->setPosition(Screen0_SloganButton, 119, 211);
    Screen0_SloganButton->fn->setSize(Screen0_SloganButton, 238, 37);
    Screen0_SloganButton->fn->setString(Screen0_SloganButton, (leString*)&string_Slogan);
    root0->fn->addChild(root0, (leWidget*)Screen0_SloganButton);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_Screen0()
{
}

void screenHide_Screen0()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    Screen0_PanelWidget0 = NULL;
    Screen0_LogoWidget = NULL;
    Screen0_TitleLabel = NULL;
    Screen0_SloganButton = NULL;

    string_TitleString.fn->destructor(&string_TitleString);
    string_Slogan.fn->destructor(&string_Slogan);


    showing = LE_FALSE;
}

void screenDestroy_Screen0()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_Screen0(uint32_t lyrIdx)
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

