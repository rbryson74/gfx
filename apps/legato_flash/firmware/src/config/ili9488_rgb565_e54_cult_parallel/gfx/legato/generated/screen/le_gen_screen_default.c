#include "gfx/legato/generated/screen/le_gen_screen_default.h"

// screen member widget declarations
leWidget* root0;

leWidget* default_BackgroundPanel;
leImageWidget* default_WatermarkImage;
leImageWidget* default_LogoImage;
leLabelWidget* default_TitleLabel;
leWidget* default_SelectMediumPanel;
leWidget* default_InfoPanel;
leWidget* default_FlashingPanel;
leLabelWidget* default_SelectMediumLabel;
leButtonWidget* default_SDCardButton;
leButtonWidget* default_USBButton;
leWidget* default_ErrorMsgPanel;
leLabelWidget* default_NoMediumLabel2;
leLabelWidget* default_NoMediumLabel1;
leLabelWidget* default_InfoLabel1;
leLabelWidget* default_InfoLabel2;
leButtonWidget* default_InfoOKButton;
leProgressBarWidget* default_FlashingProgressBar;
leLabelWidget* default_FlashingLabel;
leLabelWidget* default_RecordsTotalLabel;
leLabelWidget* default_OfLabel;
leLabelWidget* default_CurrentRecordLabel;

// string list for this screen
static leTableString string_Title;
static leTableString string_SelectSource;
static leTableString string_SDCard;
static leTableString string_USB;
static leTableString string_NoValidMedium2;
static leTableString string_NoValidMedium;
static leTableString string_FileNotFound1;
static leTableString string_FileNotFound2;
static leTableString string_Ok;
static leTableString string_Flashing;
static leTableString string_stringNumberFiller;
static leTableString string_Of;

static leBool initialized = LE_FALSE;
static leBool showing = LE_FALSE;

leResult screenInit_default()
{
    if(initialized == LE_TRUE)
        return LE_FAILURE;

    initialized = LE_TRUE;

    return LE_SUCCESS;
}

leResult screenShow_default()
{
    if(showing == LE_TRUE)
        return LE_FAILURE;

    // initialize static strings
    leTableString_Constructor(&string_Title, stringID_Title);
    leTableString_Constructor(&string_SelectSource, stringID_SelectSource);
    leTableString_Constructor(&string_SDCard, stringID_SDCard);
    leTableString_Constructor(&string_USB, stringID_USB);
    leTableString_Constructor(&string_NoValidMedium2, stringID_NoValidMedium2);
    leTableString_Constructor(&string_NoValidMedium, stringID_NoValidMedium);
    leTableString_Constructor(&string_FileNotFound1, stringID_FileNotFound1);
    leTableString_Constructor(&string_FileNotFound2, stringID_FileNotFound2);
    leTableString_Constructor(&string_Ok, stringID_Ok);
    leTableString_Constructor(&string_Flashing, stringID_Flashing);
    leTableString_Constructor(&string_stringNumberFiller, stringID_stringNumberFiller);
    leTableString_Constructor(&string_Of, stringID_Of);

    // layer 0
    root0 = leWidget_New();
    root0->fn->setPosition(root0, 0, 0);
    root0->fn->setSize(root0, 480, 320);
    root0->fn->setBackgroundType(root0, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->setMargins(root0, 0, 0, 0, 0);

    default_BackgroundPanel = leWidget_New();
    default_BackgroundPanel->fn->setPosition(default_BackgroundPanel, 0, 0);
    default_BackgroundPanel->fn->setSize(default_BackgroundPanel, 480, 320);
    default_BackgroundPanel->fn->setScheme(default_BackgroundPanel, &whiteScheme);
    root0->fn->addChild(root0, (leWidget*)default_BackgroundPanel);

    default_WatermarkImage = leImageWidget_New();
    default_WatermarkImage->fn->setPosition(default_WatermarkImage, 170, 106);
    default_WatermarkImage->fn->setSize(default_WatermarkImage, 141, 132);
    default_WatermarkImage->fn->setBackgroundType(default_WatermarkImage, LE_WIDGET_BACKGROUND_NONE);
    default_WatermarkImage->fn->setBorderType(default_WatermarkImage, LE_WIDGET_BORDER_NONE);
    default_WatermarkImage->fn->setImage(default_WatermarkImage, (leImage*)&MHGS_logo_small);
    root0->fn->addChild(root0, (leWidget*)default_WatermarkImage);

    default_LogoImage = leImageWidget_New();
    default_LogoImage->fn->setPosition(default_LogoImage, 11, 11);
    default_LogoImage->fn->setSize(default_LogoImage, 32, 32);
    default_LogoImage->fn->setBackgroundType(default_LogoImage, LE_WIDGET_BACKGROUND_NONE);
    default_LogoImage->fn->setBorderType(default_LogoImage, LE_WIDGET_BORDER_NONE);
    default_LogoImage->fn->setImage(default_LogoImage, (leImage*)&mchpLogo);
    root0->fn->addChild(root0, (leWidget*)default_LogoImage);

    default_TitleLabel = leLabelWidget_New();
    default_TitleLabel->fn->setPosition(default_TitleLabel, 64, 14);
    default_TitleLabel->fn->setSize(default_TitleLabel, 377, 32);
    default_TitleLabel->fn->setScheme(default_TitleLabel, &defaultScheme);
    default_TitleLabel->fn->setBackgroundType(default_TitleLabel, LE_WIDGET_BACKGROUND_NONE);
    default_TitleLabel->fn->setString(default_TitleLabel, (leString*)&string_Title);
    root0->fn->addChild(root0, (leWidget*)default_TitleLabel);

    default_SelectMediumPanel = leWidget_New();
    default_SelectMediumPanel->fn->setPosition(default_SelectMediumPanel, 0, 60);
    default_SelectMediumPanel->fn->setSize(default_SelectMediumPanel, 480, 260);
    default_SelectMediumPanel->fn->setBackgroundType(default_SelectMediumPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)default_SelectMediumPanel);

    default_SelectMediumLabel = leLabelWidget_New();
    default_SelectMediumLabel->fn->setPosition(default_SelectMediumLabel, 78, 6);
    default_SelectMediumLabel->fn->setSize(default_SelectMediumLabel, 333, 25);
    default_SelectMediumLabel->fn->setScheme(default_SelectMediumLabel, &defaultScheme);
    default_SelectMediumLabel->fn->setBackgroundType(default_SelectMediumLabel, LE_WIDGET_BACKGROUND_NONE);
    default_SelectMediumLabel->fn->setString(default_SelectMediumLabel, (leString*)&string_SelectSource);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_SelectMediumLabel);

    default_SDCardButton = leButtonWidget_New();
    default_SDCardButton->fn->setPosition(default_SDCardButton, 58, 65);
    default_SDCardButton->fn->setSize(default_SDCardButton, 100, 100);
    default_SDCardButton->fn->setVisible(default_SDCardButton, LE_FALSE);
    default_SDCardButton->fn->setScheme(default_SDCardButton, &defaultScheme);
    default_SDCardButton->fn->setString(default_SDCardButton, (leString*)&string_SDCard);
    default_SDCardButton->fn->setPressedImage(default_SDCardButton, (leImage*)&sdcard_sm);
    default_SDCardButton->fn->setReleasedImage(default_SDCardButton, (leImage*)&sdcard_sm);
    default_SDCardButton->fn->setImagePosition(default_SDCardButton, LE_RELATIVE_POSITION_ABOVE);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_SDCardButton);

    default_USBButton = leButtonWidget_New();
    default_USBButton->fn->setPosition(default_USBButton, 316, 65);
    default_USBButton->fn->setSize(default_USBButton, 100, 100);
    default_USBButton->fn->setVisible(default_USBButton, LE_FALSE);
    default_USBButton->fn->setScheme(default_USBButton, &defaultScheme);
    default_USBButton->fn->setString(default_USBButton, (leString*)&string_USB);
    default_USBButton->fn->setPressedImage(default_USBButton, (leImage*)&usb_icon_sm);
    default_USBButton->fn->setReleasedImage(default_USBButton, (leImage*)&usb_icon_sm);
    default_USBButton->fn->setImagePosition(default_USBButton, LE_RELATIVE_POSITION_ABOVE);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_USBButton);

    default_ErrorMsgPanel = leWidget_New();
    default_ErrorMsgPanel->fn->setPosition(default_ErrorMsgPanel, 67, 189);
    default_ErrorMsgPanel->fn->setSize(default_ErrorMsgPanel, 327, 57);
    default_ErrorMsgPanel->fn->setBackgroundType(default_ErrorMsgPanel, LE_WIDGET_BACKGROUND_NONE);
    default_SelectMediumPanel->fn->addChild(default_SelectMediumPanel, (leWidget*)default_ErrorMsgPanel);

    default_NoMediumLabel2 = leLabelWidget_New();
    default_NoMediumLabel2->fn->setPosition(default_NoMediumLabel2, -6, 27);
    default_NoMediumLabel2->fn->setSize(default_NoMediumLabel2, 358, 25);
    default_NoMediumLabel2->fn->setScheme(default_NoMediumLabel2, &defaultScheme);
    default_NoMediumLabel2->fn->setBackgroundType(default_NoMediumLabel2, LE_WIDGET_BACKGROUND_NONE);
    default_NoMediumLabel2->fn->setHAlignment(default_NoMediumLabel2, LE_HALIGN_CENTER);
    default_NoMediumLabel2->fn->setString(default_NoMediumLabel2, (leString*)&string_NoValidMedium2);
    default_ErrorMsgPanel->fn->addChild(default_ErrorMsgPanel, (leWidget*)default_NoMediumLabel2);

    default_NoMediumLabel1 = leLabelWidget_New();
    default_NoMediumLabel1->fn->setPosition(default_NoMediumLabel1, 33, 2);
    default_NoMediumLabel1->fn->setSize(default_NoMediumLabel1, 277, 25);
    default_NoMediumLabel1->fn->setScheme(default_NoMediumLabel1, &defaultScheme);
    default_NoMediumLabel1->fn->setBackgroundType(default_NoMediumLabel1, LE_WIDGET_BACKGROUND_NONE);
    default_NoMediumLabel1->fn->setHAlignment(default_NoMediumLabel1, LE_HALIGN_CENTER);
    default_NoMediumLabel1->fn->setString(default_NoMediumLabel1, (leString*)&string_NoValidMedium);
    default_ErrorMsgPanel->fn->addChild(default_ErrorMsgPanel, (leWidget*)default_NoMediumLabel1);

    default_InfoPanel = leWidget_New();
    default_InfoPanel->fn->setPosition(default_InfoPanel, 0, 60);
    default_InfoPanel->fn->setSize(default_InfoPanel, 480, 260);
    default_InfoPanel->fn->setVisible(default_InfoPanel, LE_FALSE);
    default_InfoPanel->fn->setBackgroundType(default_InfoPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)default_InfoPanel);

    default_InfoLabel1 = leLabelWidget_New();
    default_InfoLabel1->fn->setPosition(default_InfoLabel1, 14, 4);
    default_InfoLabel1->fn->setSize(default_InfoLabel1, 448, 33);
    default_InfoLabel1->fn->setScheme(default_InfoLabel1, &defaultScheme);
    default_InfoLabel1->fn->setBackgroundType(default_InfoLabel1, LE_WIDGET_BACKGROUND_NONE);
    default_InfoLabel1->fn->setHAlignment(default_InfoLabel1, LE_HALIGN_CENTER);
    default_InfoLabel1->fn->setString(default_InfoLabel1, (leString*)&string_FileNotFound1);
    default_InfoPanel->fn->addChild(default_InfoPanel, (leWidget*)default_InfoLabel1);

    default_InfoLabel2 = leLabelWidget_New();
    default_InfoLabel2->fn->setPosition(default_InfoLabel2, 72, 29);
    default_InfoLabel2->fn->setSize(default_InfoLabel2, 336, 29);
    default_InfoLabel2->fn->setScheme(default_InfoLabel2, &defaultScheme);
    default_InfoLabel2->fn->setBackgroundType(default_InfoLabel2, LE_WIDGET_BACKGROUND_NONE);
    default_InfoLabel2->fn->setHAlignment(default_InfoLabel2, LE_HALIGN_CENTER);
    default_InfoLabel2->fn->setString(default_InfoLabel2, (leString*)&string_FileNotFound2);
    default_InfoPanel->fn->addChild(default_InfoPanel, (leWidget*)default_InfoLabel2);

    default_InfoOKButton = leButtonWidget_New();
    default_InfoOKButton->fn->setPosition(default_InfoOKButton, 177, 189);
    default_InfoOKButton->fn->setSize(default_InfoOKButton, 120, 44);
    default_InfoOKButton->fn->setScheme(default_InfoOKButton, &defaultScheme);
    default_InfoOKButton->fn->setString(default_InfoOKButton, (leString*)&string_Ok);
    default_InfoPanel->fn->addChild(default_InfoPanel, (leWidget*)default_InfoOKButton);

    default_FlashingPanel = leWidget_New();
    default_FlashingPanel->fn->setPosition(default_FlashingPanel, 39, 243);
    default_FlashingPanel->fn->setSize(default_FlashingPanel, 398, 60);
    default_FlashingPanel->fn->setVisible(default_FlashingPanel, LE_FALSE);
    default_FlashingPanel->fn->setBackgroundType(default_FlashingPanel, LE_WIDGET_BACKGROUND_NONE);
    root0->fn->addChild(root0, (leWidget*)default_FlashingPanel);

    default_FlashingProgressBar = leProgressBarWidget_New();
    default_FlashingProgressBar->fn->setPosition(default_FlashingProgressBar, 5, 30);
    default_FlashingProgressBar->fn->setSize(default_FlashingProgressBar, 385, 25);
    default_FlashingProgressBar->fn->setScheme(default_FlashingProgressBar, &ProgressScheme);
    default_FlashingPanel->fn->addChild(default_FlashingPanel, (leWidget*)default_FlashingProgressBar);

    default_FlashingLabel = leLabelWidget_New();
    default_FlashingLabel->fn->setPosition(default_FlashingLabel, 0, 0);
    default_FlashingLabel->fn->setSize(default_FlashingLabel, 310, 25);
    default_FlashingLabel->fn->setScheme(default_FlashingLabel, &defaultScheme);
    default_FlashingLabel->fn->setBackgroundType(default_FlashingLabel, LE_WIDGET_BACKGROUND_NONE);
    default_FlashingLabel->fn->setString(default_FlashingLabel, (leString*)&string_Flashing);
    default_FlashingPanel->fn->addChild(default_FlashingPanel, (leWidget*)default_FlashingLabel);

    default_RecordsTotalLabel = leLabelWidget_New();
    default_RecordsTotalLabel->fn->setPosition(default_RecordsTotalLabel, 327, 0);
    default_RecordsTotalLabel->fn->setSize(default_RecordsTotalLabel, 66, 25);
    default_RecordsTotalLabel->fn->setVisible(default_RecordsTotalLabel, LE_FALSE);
    default_RecordsTotalLabel->fn->setScheme(default_RecordsTotalLabel, &defaultScheme);
    default_RecordsTotalLabel->fn->setBackgroundType(default_RecordsTotalLabel, LE_WIDGET_BACKGROUND_NONE);
    default_RecordsTotalLabel->fn->setHAlignment(default_RecordsTotalLabel, LE_HALIGN_RIGHT);
    default_RecordsTotalLabel->fn->setString(default_RecordsTotalLabel, (leString*)&string_stringNumberFiller);
    default_FlashingPanel->fn->addChild(default_FlashingPanel, (leWidget*)default_RecordsTotalLabel);

    default_OfLabel = leLabelWidget_New();
    default_OfLabel->fn->setPosition(default_OfLabel, 301, 0);
    default_OfLabel->fn->setSize(default_OfLabel, 23, 25);
    default_OfLabel->fn->setVisible(default_OfLabel, LE_FALSE);
    default_OfLabel->fn->setScheme(default_OfLabel, &defaultScheme);
    default_OfLabel->fn->setBackgroundType(default_OfLabel, LE_WIDGET_BACKGROUND_NONE);
    default_OfLabel->fn->setString(default_OfLabel, (leString*)&string_Of);
    default_FlashingPanel->fn->addChild(default_FlashingPanel, (leWidget*)default_OfLabel);

    default_CurrentRecordLabel = leLabelWidget_New();
    default_CurrentRecordLabel->fn->setPosition(default_CurrentRecordLabel, 221, 0);
    default_CurrentRecordLabel->fn->setSize(default_CurrentRecordLabel, 80, 25);
    default_CurrentRecordLabel->fn->setVisible(default_CurrentRecordLabel, LE_FALSE);
    default_CurrentRecordLabel->fn->setScheme(default_CurrentRecordLabel, &defaultScheme);
    default_CurrentRecordLabel->fn->setBackgroundType(default_CurrentRecordLabel, LE_WIDGET_BACKGROUND_NONE);
    default_CurrentRecordLabel->fn->setHAlignment(default_CurrentRecordLabel, LE_HALIGN_RIGHT);
    default_CurrentRecordLabel->fn->setString(default_CurrentRecordLabel, (leString*)&string_stringNumberFiller);
    default_FlashingPanel->fn->addChild(default_FlashingPanel, (leWidget*)default_CurrentRecordLabel);

    leAddRootWidget(root0, 0);
    leSetLayerColorMode(0, LE_COLOR_MODE_RGB_565);

    default_OnShow(); // raise event

    showing = LE_TRUE;

    return LE_SUCCESS;
}

void screenUpdate_default()
{
}

void screenHide_default()
{

    leRemoveRootWidget(root0, 0);
    leWidget_Delete(root0);
    root0 = NULL;

    default_BackgroundPanel = NULL;
    default_WatermarkImage = NULL;
    default_LogoImage = NULL;
    default_TitleLabel = NULL;
    default_SelectMediumPanel = NULL;
    default_InfoPanel = NULL;
    default_FlashingPanel = NULL;
    default_SelectMediumLabel = NULL;
    default_SDCardButton = NULL;
    default_USBButton = NULL;
    default_ErrorMsgPanel = NULL;
    default_NoMediumLabel2 = NULL;
    default_NoMediumLabel1 = NULL;
    default_InfoLabel1 = NULL;
    default_InfoLabel2 = NULL;
    default_InfoOKButton = NULL;
    default_FlashingProgressBar = NULL;
    default_FlashingLabel = NULL;
    default_RecordsTotalLabel = NULL;
    default_OfLabel = NULL;
    default_CurrentRecordLabel = NULL;

    string_Title.fn->destructor(&string_Title);
    string_SelectSource.fn->destructor(&string_SelectSource);
    string_SDCard.fn->destructor(&string_SDCard);
    string_USB.fn->destructor(&string_USB);
    string_NoValidMedium2.fn->destructor(&string_NoValidMedium2);
    string_NoValidMedium.fn->destructor(&string_NoValidMedium);
    string_FileNotFound1.fn->destructor(&string_FileNotFound1);
    string_FileNotFound2.fn->destructor(&string_FileNotFound2);
    string_Ok.fn->destructor(&string_Ok);
    string_Flashing.fn->destructor(&string_Flashing);
    string_stringNumberFiller.fn->destructor(&string_stringNumberFiller);
    string_Of.fn->destructor(&string_Of);


    showing = LE_FALSE;
}

void screenDestroy_default()
{
    if(initialized == LE_FALSE)
        return;

    initialized = LE_FALSE;
}

leWidget* screenGetRoot_default(uint32_t lyrIdx)
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

