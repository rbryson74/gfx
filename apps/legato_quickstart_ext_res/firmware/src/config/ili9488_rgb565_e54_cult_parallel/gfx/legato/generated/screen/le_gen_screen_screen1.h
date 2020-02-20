#ifndef LE_GEN_SCREEN_SCREEN1_H
#define LE_GEN_SCREEN_SCREEN1_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* Layer0_FillPanel;
extern leLabelWidget* TitleLabel;
extern leButtonWidget* SloganButton;
extern leButtonWidget* LogoButton;
extern leLabelWidget* ImageTypeLabelWidget;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_screen1(); // called when Legato is initialized
leResult screenShow_screen1(); // called when screen is shown
void screenHide_screen1(); // called when screen is hidden
void screenDestroy_screen1(); // called when Legato is destroyed
void screenUpdate_screen1(); // called when Legato is updating

leWidget* screenGetRoot_screen1(uint32_t lyrIdx); // gets a root widget for this screen

// event handlers
void SloganButton_OnReleased(leButtonWidget* btn)
;

void LogoButton_OnReleased(leButtonWidget* btn)
;


//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SCREEN1_H
