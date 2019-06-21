def generateScreenEvent(screen, event, actions):
    text = ""

    if event.name == "ShowEvent":
        text += "void %s_OnShow(void)" % screen.getName()

    if event.name == "HideEvent":
        text += "void %s_OnHide(void)" % screen.getName()

    if event.name == "UpdateEvent":
        text += "void %s_OnUpdate(void)" % screen.getName()

    text += generateActions(actions, None)

    return text


def generateButtonEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "PressedEvent":
        text += "void %s_OnPressed(%s)" % (widget.getName(), getWidgetVariableName(widget))

    if event.name == "ReleasedEvent":
        text += "void %s_OnReleased(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateCheckBoxEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "CheckedEvent":
        text += "void %s_OnChecked(%s)" % (widget.getName(), getWidgetVariableName(widget))

    if event.name == "UncheckedEvent":
        text += "void %s_OnUnchecked(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateCircularGaugeEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "ValueChangedEvent":
        text += "void %s_OnValueChanged(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text

def generateCircularSliderEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "ValueChangedEvent":
        text += "void %s_OnValueChanged(%s)" % (widget.getName(), getWidgetVariableName(widget))

    if event.name == "PressedEvent":
        text += "void %s_OnPressed(%s)" % (widget.getName(), getWidgetVariableName(widget))

    if event.name == "ReleasedEvent":
        text += "void %s_OnReleased(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateDrawSurfaceEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "DrawNotificationEvent":
        text += "leBool %s_OnPaint(%s, leRect* rect)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, "return LE_SUCCESS;")

    return text


def generateImageSequenceEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "ImageChangedEvent":
        text += "void %s_OnImageChanged(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateKeyPadEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "KeyClickEvent":
        text += "void %s_OnKeyClick(%s, leButtonWidget* btn, uint32_t row, uint32_t col)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateListEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "SelectionChangedEvent":
        text += "void %s_OnSelectionChanged(%s, uint32_t idx, leBool selected)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateListWheelEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "SelectedItemChangedEvent":
        text += "void %s_OnSelectionChanged(%s, int32_t idx)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generatePieChartEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "PressedEvent":
        text += "void %s_OnPressed(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateProgressBarEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "ValueChangedEvent":
        text += "void %s_OnValueChanged(%s, uint32_t val)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateRadialMenuEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "ItemSelectedEvent":
        text += "void %s_OnItemSelected(%s)" % (widget.getName(), getWidgetVariableName(widget))

    if event.name == "ItemProminenceChangedEvent":
        text += "void %s_OnItemProminenceChanged(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateRadioButtonEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "SelectedEvent":
        text += "void %s_OnSelected(%s)" % (widget.getName(), getWidgetVariableName(widget))

    if event.name == "DeselectedEvent":
        text += "void %s_OnDeselected(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateScrollBarEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "ValueChangedEvent":
        text += "void %s_OnValueChanged(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateSliderEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "ValueChangedEvent":
        text += "void %s_OnValueChanged(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateTextFieldEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "TextChangedEvent":
        text += "void %s_OnTextChanged(%s)" % (widget.getName(), getWidgetVariableName(widget))

    if event.name == "FocusChangedEvent":
        text += "void %s_OnFocusChanged(%s)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


def generateTouchTestEvent(screen, widget, event, genActions):
    text = ""

    if event.name == "PointAddedEvent":
        text += "void %s_OnPointAdded(%s, lePoint* pnt)" % (widget.getName(), getWidgetVariableName(widget))

    text += generateActions(genActions, None)

    return text


eventGenerateFunctions = {
    "ButtonWidget": generateButtonEvent,
    "CheckBoxWidget": generateCheckBoxEvent,
    "CircularGaugeWidget": generateCircularGaugeEvent,
    "CircularSliderWidget": generateCircularSliderEvent,
    "DrawSurfaceWidget": generateDrawSurfaceEvent,
    "ImageSequenceWidget": generateImageSequenceEvent,
    "KeyPadWidget": generateKeyPadEvent,
    "ListWidget": generateListEvent,
    "ListWheelWidget": generateListWheelEvent,
    "PieChartWidget": generatePieChartEvent,
    "ProgressBarWidget": generateProgressBarEvent,
    "RadialMenuWidget": generateRadialMenuEvent,
    "RadioButtonWidget": generateRadioButtonEvent,
    "ScrollBarWidget": generateScrollBarEvent,
    "SliderWidget": generateSliderEvent,
    "TextFieldWidget": generateTextFieldEvent,
    "TouchTestWidget": generateTouchTestEvent,
}

def generateActions(actions, returnText):
    text = ""

    if actions == True:
        text += "\n{\n"

        #actionList = event.getActionList()

        #for action in actionList:
        #    text += generateAction(event.name, widget.getName())

        if returnText != None:
            text += "    %s\n" % returnText

        text += "}"
    else:
        text += ";"

    return text

def generateEvent(screen, widget, event, actions):
    text = ""

    if widget == None:
        text = generateScreenEvent(screen, event, actions)
    else:
        text = eventGenerateFunctions[widget.getType()](screen, widget, event, actions)

    return text


def getWidgetVariableName(widget):
    if widget.getType() == "ButtonWidget":
        return "leButtonWidget* btn"
    elif widget.getType() == "CheckBoxWidget":
        return "leCheckBoxWidget* box"
    elif widget.getType() == "CircularGaugeWidget":
        return "leCircularGaugeWidget* cir"
    elif widget.getType() == "CircularSliderWidget":
        return "leCircularSliderWidget* cir"
    elif widget.getType() == "DrawSurfaceWidget":
        return "leDrawSurfaceWidget* sfc"
    elif widget.getType() == "ImageSequenceWidget":
        return "leImageSequenceWidget* seq"
    elif widget.getType() == "KeyPadWidget":
        return "leKeyPadWidget* pad"
    elif widget.getType() == "ListWidget":
        return "leListWidget* lst"
    elif widget.getType() == "ListWheelWidget":
        return "leListWheelWidget* lst"
    elif widget.getType() == "PieChartWidget":
        return "lePieChartWidget* pie"
    elif widget.getType() == "ProgressBarWidget":
        return "leProgressBarWidget* bar"
    elif widget.getType() == "RadialMenuWidget":
        return "leRadialMenuWidget* rad"
    elif widget.getType() == "RadioButtonWidget":
        return "leRadioButtonWidget* btn"
    elif widget.getType() == "ScrollBarWidget":
        return "leScrollBarWidget* bar"
    elif widget.getType() == "SliderWidget":
        return "leSliderWidget* sld"
    elif widget.getType() == "TextFieldWidget":
        return "leTextFieldWidget* txt"
    elif widget.getType() == "TouchTestWidget":
        return "leTouchTestWidget* tch"