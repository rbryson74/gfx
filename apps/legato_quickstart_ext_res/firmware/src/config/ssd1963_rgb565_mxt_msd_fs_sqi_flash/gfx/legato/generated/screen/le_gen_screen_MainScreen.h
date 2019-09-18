#ifndef LE_GEN_SCREEN_MAINSCREEN_H
#define LE_GEN_SCREEN_MAINSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget1;
extern leLabelWidget* TitleLabel;
extern leButtonWidget* SloganButton;
extern leLabelWidget* LabelWidget1;
extern leLabelWidget* LabelWidget2;
extern leLabelWidget* LabelWidget3;
extern leButtonWidget* LogoButton;
extern leLabelWidget* ImageTypeLabelWidget;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_MainScreen(); // called when Legato is initialized
leResult screenShow_MainScreen(); // called when screen is shown
void screenHide_MainScreen(); // called when screen is hidden
void screenDestroy_MainScreen(); // called when Legato is destroyed
void screenUpdate_MainScreen(); // called when Legato is updating

leWidget* screenGetRoot_MainScreen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_MAINSCREEN_H
