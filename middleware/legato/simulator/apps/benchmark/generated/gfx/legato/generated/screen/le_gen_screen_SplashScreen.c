#include "gfx/legato/generated/screen/le_gen_screen_SplashScreen.h"

// widget list for layer 0
static leWidget* root0;

leWidget* SplashBackground;
leImageWidget* SplashPIC32Logo;
leImageWidget* SplashHarmonyLogo;
leImageWidget* SplashBar;
leImageWidget* SplashMicrochipLogo;
leListWheelWidget* ListWheelWidget0;

// string list for this screen
static leTableString tableString_String0;
static leTableString tableString_String1;
static leTableString tableString_String10;
static leTableString tableString_String11;
static leTableString tableString_GPUOff;
static leTableString tableString_GPUOn;
static leTableString tableString_Next;
static leTableString tableString_Previous;

static leBool showing = LE_FALSE;

leResult screenInit_SplashScreen()
{
    return LE_SUCCESS;
}

leResult screenShow_SplashScreen()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&tableString_String0, string_String0);
    leTableString_Constructor(&tableString_String1, string_String1);
    leTableString_Constructor(&tableString_String10, string_String10);
    leTableString_Constructor(&tableString_String11, string_String11);
    leTableString_Constructor(&tableString_GPUOff, string_GPUOff);
    leTableString_Constructor(&tableString_GPUOn, string_GPUOn);
    leTableString_Constructor(&tableString_Next, string_Next);
    leTableString_Constructor(&tableString_Previous, string_Previous);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 272);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    SplashBackground = leWidget_New();
    SplashBackground->fn->setPosition(SplashBackground, 0, 0);
    SplashBackground->fn->setSize(SplashBackground, 480, 272);
    SplashBackground->fn->setScheme(SplashBackground, &WhiteFillScheme);
    root0->fn->addChild(root0, SplashBackground);

    SplashPIC32Logo = leImageWidget_New();
    SplashPIC32Logo->fn->setPosition(SplashPIC32Logo, 120, 40);
    SplashPIC32Logo->fn->setSize(SplashPIC32Logo, 240, 139);
    SplashPIC32Logo->fn->setBackgroundType(SplashPIC32Logo, LE_WIDGET_BACKGROUND_NONE);
    SplashPIC32Logo->fn->setImage(SplashPIC32Logo, &PIC32Logo);
    root0->fn->addChild(root0, (leWidget*)SplashPIC32Logo);

    SplashHarmonyLogo = leImageWidget_New();
    SplashHarmonyLogo->fn->setPosition(SplashHarmonyLogo, 120, 40);
    SplashHarmonyLogo->fn->setSize(SplashHarmonyLogo, 240, 139);
    SplashHarmonyLogo->fn->setVisible(SplashHarmonyLogo, LE_FALSE);
    SplashHarmonyLogo->fn->setScheme(SplashHarmonyLogo, &WhiteBackgroundScheme);
    SplashHarmonyLogo->fn->setImage(SplashHarmonyLogo, &HarmonyLogo);
    root0->fn->addChild(root0, (leWidget*)SplashHarmonyLogo);

    SplashBar = leImageWidget_New();
    SplashBar->fn->setPosition(SplashBar, 480, 207);
    SplashBar->fn->setSize(SplashBar, 480, 65);
    SplashBar->fn->setBackgroundType(SplashBar, LE_WIDGET_BACKGROUND_NONE);
    SplashBar->fn->setImage(SplashBar, &Bar);
    root0->fn->addChild(root0, (leWidget*)SplashBar);

    SplashMicrochipLogo = leImageWidget_New();
    SplashMicrochipLogo->fn->setPosition(SplashMicrochipLogo, 17, 223);
    SplashMicrochipLogo->fn->setSize(SplashMicrochipLogo, 144, 39);
    SplashMicrochipLogo->fn->setVisible(SplashMicrochipLogo, LE_FALSE);
    SplashMicrochipLogo->fn->setBackgroundType(SplashMicrochipLogo, LE_WIDGET_BACKGROUND_NONE);
    SplashMicrochipLogo->fn->setImage(SplashMicrochipLogo, &MicrochipLogo);
    root0->fn->addChild(root0, (leWidget*)SplashMicrochipLogo);

    ListWheelWidget0 = leListWheelWidget_New();
    ListWheelWidget0->fn->setPosition(ListWheelWidget0, 41, 18);
    ListWheelWidget0->fn->setSize(ListWheelWidget0, 134, 180);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->setItemString(ListWheelWidget0, 0, (leString*)&tableString_String0);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->setItemString(ListWheelWidget0, 1, (leString*)&tableString_String1);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->setItemString(ListWheelWidget0, 2, (leString*)&tableString_String10);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->setItemString(ListWheelWidget0, 3, (leString*)&tableString_String11);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->setItemString(ListWheelWidget0, 4, (leString*)&tableString_GPUOff);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->setItemString(ListWheelWidget0, 5, (leString*)&tableString_GPUOn);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->setItemString(ListWheelWidget0, 6, (leString*)&tableString_Next);
    ListWheelWidget0->fn->appendItem(ListWheelWidget0);
    ListWheelWidget0->fn->setItemString(ListWheelWidget0, 7, (leString*)&tableString_Previous);
    root0->fn->addChild(root0, (leWidget*)ListWheelWidget0);

    leAddRootWidget(root0, 0);

    showing = LE_TRUE;

    SplashScreen_OnShow();

    return LE_SUCCESS;
}

void screenUpdate_SplashScreen()
{
    SplashScreen_OnUpdate();
}

void screenHide_SplashScreen()
{
    leRemoveRootWidget(root0, 0);

    leWidget_Delete(root0);

    root0 = NULL;

    SplashBackground = NULL;
    SplashPIC32Logo = NULL;
    SplashHarmonyLogo = NULL;
    SplashBar = NULL;
    SplashMicrochipLogo = NULL;
    ListWheelWidget0 = NULL;

    tableString_String0.fn->destructor(&tableString_String0);
    tableString_String1.fn->destructor(&tableString_String1);
    tableString_String10.fn->destructor(&tableString_String10);
    tableString_String11.fn->destructor(&tableString_String11);
    tableString_GPUOff.fn->destructor(&tableString_GPUOff);
    tableString_GPUOn.fn->destructor(&tableString_GPUOn);
    tableString_Next.fn->destructor(&tableString_Next);
    tableString_Previous.fn->destructor(&tableString_Previous);
    showing = LE_FALSE;

    SplashScreen_OnHide();
}

void screenDestroy_SplashScreen()
{

}

leWidget* screenGetRoot_SplashScreen(uint32_t lyrIdx)
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

