#include "gfx/legato/generated/le_gen_scheme.h"

leScheme BlueScheme;
leScheme defaultScheme;
leScheme GreenScheme;
leScheme LayerScheme;
leScheme RedScheme;

void legato_initialize_schemes(void)
{
    leScheme_Initialize(&BlueScheme, LE_COLOR_MODE_RGBA_8888);
    BlueScheme.base = 0x0000FFFF;
    BlueScheme.highlight = 0xC8D0D4FF;
    BlueScheme.highlightLight = 0xFFFFFFFF;
    BlueScheme.shadow = 0x808080FF;
    BlueScheme.shadowDark = 0x404040FF;
    BlueScheme.foreground = 0x0000FFFF;
    BlueScheme.foregroundInactive = 0xD6E3E7FF;
    BlueScheme.foregroundDisabled = 0x808080FF;
    BlueScheme.background = 0xFFFFFFFF;
    BlueScheme.backgroundInactive = 0xD6E3E7FF;
    BlueScheme.backgroundDisabled = 0xC8D0D4FF;
    BlueScheme.text = 0x0000FFFF;
    BlueScheme.textHighlight = 0xFFFF00FF;
    BlueScheme.textHighlightText = 0xFFFFFFFF;
    BlueScheme.textInactive = 0xD6E3E7FF;
    BlueScheme.textDisabled = 0x8C9294FF;

    leScheme_Initialize(&defaultScheme, LE_COLOR_MODE_RGBA_8888);
    defaultScheme.base = 0xC8D0D4FF;
    defaultScheme.highlight = 0xC8D0D4FF;
    defaultScheme.highlightLight = 0xFFFFFFFF;
    defaultScheme.shadow = 0x808080FF;
    defaultScheme.shadowDark = 0x404040FF;
    defaultScheme.foreground = 0x000000FF;
    defaultScheme.foregroundInactive = 0xD6E3E7FF;
    defaultScheme.foregroundDisabled = 0x808080FF;
    defaultScheme.background = 0xFFFFFFFF;
    defaultScheme.backgroundInactive = 0xD6E3E7FF;
    defaultScheme.backgroundDisabled = 0xC8D0D4FF;
    defaultScheme.text = 0x000000FF;
    defaultScheme.textHighlight = 0x0000FFFF;
    defaultScheme.textHighlightText = 0xFFFFFFFF;
    defaultScheme.textInactive = 0xD6E3E7FF;
    defaultScheme.textDisabled = 0x8C9294FF;

    leScheme_Initialize(&GreenScheme, LE_COLOR_MODE_RGBA_8888);
    GreenScheme.base = 0x00FF00FF;
    GreenScheme.highlight = 0xC8D0D4FF;
    GreenScheme.highlightLight = 0xFFFFFFFF;
    GreenScheme.shadow = 0x808080FF;
    GreenScheme.shadowDark = 0x404040FF;
    GreenScheme.foreground = 0x00FF00FF;
    GreenScheme.foregroundInactive = 0xD6E3E7FF;
    GreenScheme.foregroundDisabled = 0x808080FF;
    GreenScheme.background = 0xFFFFFFFF;
    GreenScheme.backgroundInactive = 0xD6E3E7FF;
    GreenScheme.backgroundDisabled = 0xC8D0D4FF;
    GreenScheme.text = 0x00FF00FF;
    GreenScheme.textHighlight = 0x0000FFFF;
    GreenScheme.textHighlightText = 0xFFFFFFFF;
    GreenScheme.textInactive = 0xD6E3E7FF;
    GreenScheme.textDisabled = 0x8C9294FF;

    leScheme_Initialize(&LayerScheme, LE_COLOR_MODE_RGBA_8888);
    LayerScheme.base = 0xFFFFFFFF;
    LayerScheme.highlight = 0xC8D0D4FF;
    LayerScheme.highlightLight = 0xFFFFFFFF;
    LayerScheme.shadow = 0x808080FF;
    LayerScheme.shadowDark = 0x404040FF;
    LayerScheme.foreground = 0x000000FF;
    LayerScheme.foregroundInactive = 0xD6E3E7FF;
    LayerScheme.foregroundDisabled = 0x808080FF;
    LayerScheme.background = 0xFFFFFFFF;
    LayerScheme.backgroundInactive = 0xD6E3E7FF;
    LayerScheme.backgroundDisabled = 0xC8D0D4FF;
    LayerScheme.text = 0x000000FF;
    LayerScheme.textHighlight = 0x0000FFFF;
    LayerScheme.textHighlightText = 0xFFFFFFFF;
    LayerScheme.textInactive = 0xD6E3E7FF;
    LayerScheme.textDisabled = 0x8C9294FF;

    leScheme_Initialize(&RedScheme, LE_COLOR_MODE_RGBA_8888);
    RedScheme.base = 0xFF0000FF;
    RedScheme.highlight = 0xC8D0D4FF;
    RedScheme.highlightLight = 0xFFFFFFFF;
    RedScheme.shadow = 0x808080FF;
    RedScheme.shadowDark = 0x404040FF;
    RedScheme.foreground = 0xFF0000FF;
    RedScheme.foregroundInactive = 0xD6E3E7FF;
    RedScheme.foregroundDisabled = 0x808080FF;
    RedScheme.background = 0xFFFFFFFF;
    RedScheme.backgroundInactive = 0xD6E3E7FF;
    RedScheme.backgroundDisabled = 0xC8D0D4FF;
    RedScheme.text = 0xFF0000FF;
    RedScheme.textHighlight = 0x0000FFFF;
    RedScheme.textHighlightText = 0xFFFFFFFF;
    RedScheme.textInactive = 0xD6E3E7FF;
    RedScheme.textDisabled = 0x8C9294FF;

}
