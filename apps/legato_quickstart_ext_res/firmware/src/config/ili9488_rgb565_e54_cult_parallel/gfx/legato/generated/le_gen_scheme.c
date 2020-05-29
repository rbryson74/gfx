#include "gfx/legato/generated/le_gen_scheme.h"

leScheme AriaImport_LayerScheme;

void legato_initialize_schemes(void)
{
    leScheme_Initialize(&AriaImport_LayerScheme, LE_COLOR_MODE_RGB_565);
    AriaImport_LayerScheme.base = 0xFFFF;
    AriaImport_LayerScheme.highlight = 0xC67A;
    AriaImport_LayerScheme.highlightLight = 0xFFFF;
    AriaImport_LayerScheme.shadow = 0x8410;
    AriaImport_LayerScheme.shadowDark = 0x4208;
    AriaImport_LayerScheme.foreground = 0x0000;
    AriaImport_LayerScheme.foregroundInactive = 0xD71C;
    AriaImport_LayerScheme.foregroundDisabled = 0x8410;
    AriaImport_LayerScheme.background = 0xFFFF;
    AriaImport_LayerScheme.backgroundInactive = 0xD71C;
    AriaImport_LayerScheme.backgroundDisabled = 0xC67A;
    AriaImport_LayerScheme.text = 0x0000;
    AriaImport_LayerScheme.textHighlight = 0x001F;
    AriaImport_LayerScheme.textHighlightText = 0xFFFF;
    AriaImport_LayerScheme.textInactive = 0xD71C;
    AriaImport_LayerScheme.textDisabled = 0x8C92;

}
