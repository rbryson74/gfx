#include "gfx/legato/generated/screen/le_gen_screen_Screen0.h"

// screen member widget declarations
leWidget* root0;

leWidget* Screen0_default_Layer0_FillPanel;

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

    // layer 0
    root0 = leWidget_New();
    root0->fn->setSize(root0, 800, 480);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);
    root0->flags |= LE_WIDGET_IGNOREEVENTS;
    root0->flags |= LE_WIDGET_IGNOREPICK;

    Screen0_default_Layer0_FillPanel = leWidget_New();
    Screen0_default_Layer0_FillPanel->fn->setPosition(Screen0_default_Layer0_FillPanel, 0, 0);
    Screen0_default_Layer0_FillPanel->fn->setSize(Screen0_default_Layer0_FillPanel, 800, 480);
    Screen0_default_Layer0_FillPanel->fn->setScheme(Screen0_default_Layer0_FillPanel, &RedScheme);
    root0->fn->addChild(root0, (leWidget*)Screen0_default_Layer0_FillPanel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGBA_8888);

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

    Screen0_default_Layer0_FillPanel = NULL;


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

