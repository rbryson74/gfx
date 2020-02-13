#include "gfx/legato/generated/le_gen_scheme.h"

leScheme defaultScheme;
leScheme ProgressScheme;
leScheme whiteScheme;

void legato_initialize_schemes(void)
{
    leScheme_Initialize(&defaultScheme, LE_COLOR_MODE_RGB_565);
    defaultScheme.base = 0xC67A;
    defaultScheme.highlight = 0xC67A;
    defaultScheme.highlightLight = 0xFFFF;
    defaultScheme.shadow = 0x8410;
    defaultScheme.shadowDark = 0x4208;
    defaultScheme.foreground = 0x0000;
    defaultScheme.foregroundInactive = 0xD71C;
    defaultScheme.foregroundDisabled = 0x8410;
    defaultScheme.background = 0xFFFF;
    defaultScheme.backgroundInactive = 0xD71C;
    defaultScheme.backgroundDisabled = 0xC67A;
    defaultScheme.text = 0x0000;
    defaultScheme.textHighlight = 0x001F;
    defaultScheme.textHighlightText = 0xFFFF;
    defaultScheme.textInactive = 0xD71C;
    defaultScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&ProgressScheme, LE_COLOR_MODE_RGB_565);
    ProgressScheme.base = 0xC67A;
    ProgressScheme.highlight = 0xC67A;
    ProgressScheme.highlightLight = 0xBDF7;
    ProgressScheme.shadow = 0x8410;
    ProgressScheme.shadowDark = 0x4208;
    ProgressScheme.foreground = 0x0000;
    ProgressScheme.foregroundInactive = 0xD71C;
    ProgressScheme.foregroundDisabled = 0x8410;
    ProgressScheme.background = 0xFFFF;
    ProgressScheme.backgroundInactive = 0xD71C;
    ProgressScheme.backgroundDisabled = 0xC67A;
    ProgressScheme.text = 0x0000;
    ProgressScheme.textHighlight = 0x001F;
    ProgressScheme.textHighlightText = 0xFFFF;
    ProgressScheme.textInactive = 0xD71C;
    ProgressScheme.textDisabled = 0x8C92;

    leScheme_Initialize(&whiteScheme, LE_COLOR_MODE_RGB_565);
    whiteScheme.base = 0xFFFF;
    whiteScheme.highlight = 0xC67A;
    whiteScheme.highlightLight = 0xFFFF;
    whiteScheme.shadow = 0x8410;
    whiteScheme.shadowDark = 0x4208;
    whiteScheme.foreground = 0x0000;
    whiteScheme.foregroundInactive = 0xD71C;
    whiteScheme.foregroundDisabled = 0x8410;
    whiteScheme.background = 0xFFFF;
    whiteScheme.backgroundInactive = 0xD71C;
    whiteScheme.backgroundDisabled = 0xC67A;
    whiteScheme.text = 0x0000;
    whiteScheme.textHighlight = 0x001F;
    whiteScheme.textHighlightText = 0xFFFF;
    whiteScheme.textInactive = 0xD71C;
    whiteScheme.textDisabled = 0x8C92;

}
