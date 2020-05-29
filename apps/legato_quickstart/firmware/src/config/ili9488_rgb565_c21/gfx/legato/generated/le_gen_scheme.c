#include "gfx/legato/generated/le_gen_scheme.h"

leScheme NewScheme;

void legato_initialize_schemes(void)
{
    leScheme_Initialize(&NewScheme, LE_COLOR_MODE_RGB_565);
    NewScheme.base = 0xFFFF;
    NewScheme.highlight = 0xC67A;
    NewScheme.highlightLight = 0xFFFF;
    NewScheme.shadow = 0x8410;
    NewScheme.shadowDark = 0x4208;
    NewScheme.foreground = 0x0000;
    NewScheme.foregroundInactive = 0xD71C;
    NewScheme.foregroundDisabled = 0x8410;
    NewScheme.background = 0xFFFF;
    NewScheme.backgroundInactive = 0xD71C;
    NewScheme.backgroundDisabled = 0xC67A;
    NewScheme.text = 0x0000;
    NewScheme.textHighlight = 0x001F;
    NewScheme.textHighlightText = 0xFFFF;
    NewScheme.textInactive = 0xD71C;
    NewScheme.textDisabled = 0x8C92;

}
