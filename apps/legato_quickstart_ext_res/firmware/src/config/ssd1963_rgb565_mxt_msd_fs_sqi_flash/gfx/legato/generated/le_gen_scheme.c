#include "gfx/legato/generated/le_gen_scheme.h"

leScheme WhiteScheme;

void legato_initialize_schemes(void)
{
    leScheme_Initialize(&WhiteScheme, LE_COLOR_MODE_RGB_565);
    WhiteScheme.base = 0xFFFF;
    WhiteScheme.highlight = 0xC67A;
    WhiteScheme.highlightLight = 0xFFFF;
    WhiteScheme.shadow = 0x8410;
    WhiteScheme.shadowDark = 0x4208;
    WhiteScheme.foreground = 0xFFFF;
    WhiteScheme.foregroundInactive = 0xD71C;
    WhiteScheme.foregroundDisabled = 0x8410;
    WhiteScheme.background = 0xFFFF;
    WhiteScheme.backgroundInactive = 0xD71C;
    WhiteScheme.backgroundDisabled = 0xC67A;
    WhiteScheme.text = 0x0000;
    WhiteScheme.textHighlight = 0x001F;
    WhiteScheme.textHighlightText = 0xFFFF;
    WhiteScheme.textInactive = 0xD71C;
    WhiteScheme.textDisabled = 0x8C92;

}
