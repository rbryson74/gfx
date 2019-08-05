#ifndef LE_GEN_SCREEN_SLIDESHOWDEMOSCREEN_H
#define LE_GEN_SCREEN_SLIDESHOWDEMOSCREEN_H

#include "gfx/legato/generated/le_gen_init.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility
extern "C" {
#endif
// DOM-IGNORE-END

// widget list for this screen
// layer 0
extern leGradientWidget* GradientWidget6;
extern leImageSequenceWidget* ImageSequenceWidget1;
extern leButtonWidget* SlideshowHelpButton;
extern leButtonWidget* SlideShowHomeButton;
extern leLabelWidget* LabelWidget10;
extern leButtonWidget* SlideShowPrevButton;
extern leButtonWidget* SlideshowNextButton;
extern leButtonWidget* ButtonWidget21;
extern leButtonWidget* ButtonWidget22;
extern leImageWidget* SSStatusImageWidget;


// screen lifecycle functions
// DO NOT CALL THESE DIRECTLY
leResult screenInit_SlideShowDemoScreen(); // called when Legato is initialized
leResult screenShow_SlideShowDemoScreen(); // called when screen is shown
void screenHide_SlideShowDemoScreen(); // called when screen is hidden
void screenDestroy_SlideShowDemoScreen(); // called when Legato is destroyed
void screenUpdate_SlideShowDemoScreen(); // called when Legato is updating

leWidget* screenGetRoot_SlideShowDemoScreen(uint32_t lyrIdx); // gets a root widget for this screen

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif // LE_GEN_SCREEN_SLIDESHOWDEMOSCREEN_H
