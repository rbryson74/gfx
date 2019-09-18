#ifndef LE_GEN_SCREEN_LOADINGSCREEN_H
#define LE_GEN_SCREEN_LOADINGSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leWidget* PanelWidget0;
extern leButtonWidget* ButtonWidget_Wait;
extern leLabelWidget* LabelWidget_Wait;
extern leButtonWidget* ButtonWidget_MainScreen;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_LoadingScreen(); // called when Legato is initialized
leResult screenShow_LoadingScreen(); // called when screen is shown
void screenHide_LoadingScreen(); // called when screen is hidden
void screenDestroy_LoadingScreen(); // called when Legato is destroyed
void screenUpdate_LoadingScreen(); // called when Legato is updating

leWidget* screenGetRoot_LoadingScreen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_LOADINGSCREEN_H
