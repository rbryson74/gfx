#include "gfx/legato/generated/screen/le_gen_screen_MainScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* PanelWidget1;
leLabelWidget* TitleLabel;
leButtonWidget* SloganButton;
leLabelWidget* LabelWidget1;
leLabelWidget* LabelWidget2;
leLabelWidget* LabelWidget3;
leButtonWidget* LogoButton;
leLabelWidget* ImageTypeLabelWidget;

// string list for this screen
static leTableString tableString_TitleString;
static leTableString tableString_PressButton;
static leTableString tableString_DrawDirectBlit;
static leTableString tableString_ImageFromExternal;
static leTableString tableString_ImageIsDirectBlit;

// event handlers
static void SloganButton_OnReleased(leButtonWidget* btn)
;

static void LogoButton_OnReleased(leButtonWidget* btn)
;


static leBool showing = LE_FALSE;

leResult screenInit_MainScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_MainScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_TitleString, string_TitleString);
    leTableString_Constructor(&tableString_PressButton, string_PressButton);
    leTableString_Constructor(&tableString_DrawDirectBlit, string_DrawDirectBlit);
    leTableString_Constructor(&tableString_ImageFromExternal, string_ImageFromExternal);
    leTableString_Constructor(&tableString_ImageIsDirectBlit, string_ImageIsDirectBlit);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    PanelWidget1 = leWidget_New();
    PanelWidget1->fn->setPosition(PanelWidget1, 0, 0);
    PanelWidget1->fn->setSize(PanelWidget1, 480, 272);
    PanelWidget1->fn->setScheme(PanelWidget1, &WhiteScheme);
    root0->fn->addChild(root0, PanelWidget1);

    TitleLabel = leLabelWidget_New();
    TitleLabel->fn->setPosition(TitleLabel, 13, 4);
    TitleLabel->fn->setSize(TitleLabel, 455, 55);
    TitleLabel->fn->setBackgroundType(TitleLabel, LE_WIDGET_BACKGROUND_NONE);
    TitleLabel->fn->setHAlignment(TitleLabel, LE_HALIGN_CENTER);
    TitleLabel->fn->setString(TitleLabel, (leString*)&tableString_TitleString);
    root0->fn->addChild(root0, (leWidget*)TitleLabel);

    SloganButton = leButtonWidget_New();
    SloganButton->fn->setPosition(SloganButton, 14, 207);
    SloganButton->fn->setSize(SloganButton, 450, 50);
    SloganButton->fn->setReleasedEventCallback(SloganButton, SloganButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)SloganButton);

    LabelWidget1 = leLabelWidget_New();
    LabelWidget1->fn->setPosition(LabelWidget1, 5, 10);
    LabelWidget1->fn->setSize(LabelWidget1, 78, 30);
    LabelWidget1->fn->setBackgroundType(LabelWidget1, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget1->fn->setHAlignment(LabelWidget1, LE_HALIGN_RIGHT);
    LabelWidget1->fn->setString(LabelWidget1, (leString*)&tableString_PressButton);
    SloganButton->fn->addChild(SloganButton, (leWidget*)LabelWidget1);

    LabelWidget2 = leLabelWidget_New();
    LabelWidget2->fn->setPosition(LabelWidget2, 7, 10);
    LabelWidget2->fn->setSize(LabelWidget2, 398, 30);
    LabelWidget2->fn->setBackgroundType(LabelWidget2, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget2->fn->setHAlignment(LabelWidget2, LE_HALIGN_CENTER);
    LabelWidget2->fn->setString(LabelWidget2, (leString*)&tableString_DrawDirectBlit);
    SloganButton->fn->addChild(SloganButton, (leWidget*)LabelWidget2);

    LabelWidget3 = leLabelWidget_New();
    LabelWidget3->fn->setPosition(LabelWidget3, 331, 10);
    LabelWidget3->fn->setSize(LabelWidget3, 116, 30);
    LabelWidget3->fn->setBackgroundType(LabelWidget3, LE_WIDGET_BACKGROUND_NONE);
    LabelWidget3->fn->setString(LabelWidget3, (leString*)&tableString_ImageFromExternal);
    SloganButton->fn->addChild(SloganButton, (leWidget*)LabelWidget3);

    LogoButton = leButtonWidget_New();
    LogoButton->fn->setPosition(LogoButton, 96, 62);
    LogoButton->fn->setSize(LogoButton, 141, 132);
    LogoButton->fn->setBackgroundType(LogoButton, LE_WIDGET_BACKGROUND_NONE);
    LogoButton->fn->setBorderType(LogoButton, LE_WIDGET_BORDER_NONE);
    LogoButton->fn->setPressedImage(LogoButton, &MHGS_logo_small_raw_direct_blit);
    LogoButton->fn->setReleasedImage(LogoButton, &MHGS_logo_small_raw_direct_blit);
    LogoButton->fn->setPressedOffset(LogoButton, 0);
    LogoButton->fn->setReleasedEventCallback(LogoButton, LogoButton_OnReleased);
    root0->fn->addChild(root0, (leWidget*)LogoButton);

    ImageTypeLabelWidget = leLabelWidget_New();
    ImageTypeLabelWidget->fn->setPosition(ImageTypeLabelWidget, 251, 95);
    ImageTypeLabelWidget->fn->setSize(ImageTypeLabelWidget, 215, 51);
    ImageTypeLabelWidget->fn->setBackgroundType(ImageTypeLabelWidget, LE_WIDGET_BACKGROUND_NONE);
    ImageTypeLabelWidget->fn->setHAlignment(ImageTypeLabelWidget, LE_HALIGN_CENTER);
    ImageTypeLabelWidget->fn->setString(ImageTypeLabelWidget, (leString*)&tableString_ImageIsDirectBlit);
    root0->fn->addChild(root0, (leWidget*)ImageTypeLabelWidget);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_MainScreen()
{
}

void screenHide_MainScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    PanelWidget1 = NULL;
    TitleLabel = NULL;
    SloganButton = NULL;
    LabelWidget1 = NULL;
    LabelWidget2 = NULL;
    LabelWidget3 = NULL;
    LogoButton = NULL;
    ImageTypeLabelWidget = NULL;

    tableString_TitleString.fn->destructor(&tableString_TitleString);
    tableString_PressButton.fn->destructor(&tableString_PressButton);
    tableString_DrawDirectBlit.fn->destructor(&tableString_DrawDirectBlit);
    tableString_ImageFromExternal.fn->destructor(&tableString_ImageFromExternal);
    tableString_ImageIsDirectBlit.fn->destructor(&tableString_ImageIsDirectBlit);
    showing = LE_FALSE;
}

void screenDestroy_MainScreen()
{

}

leWidget* screenGetRoot_MainScreen(uint32_t lyrIdx)
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
void SloganButton_OnReleased(leButtonWidget* btn)
{
}


void LogoButton_OnReleased(leButtonWidget* btn)
{
}



