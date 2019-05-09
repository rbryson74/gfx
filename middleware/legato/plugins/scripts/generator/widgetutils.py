def getWidgetStringList(widgetList):
	stringList = []
	
	for widget in widgetList:
		if widget.getType() == "BarGraphWidget":
			if widget.getLabelStringName() is not None and widget.getLabelStringName() not in stringList:
				stringList.append(widget.getLabelStringName())

			categoryList = widget.getCategories()

			for i in range(0, len(categoryList)):
				if categoryList[i].string not in stringList:
					stringList.append(categoryList[i].string)

		if widget.getType() == "ButtonWidget":
			if widget.getStringName() is not None and widget.getStringName() not in stringList:
				stringList.append(widget.getStringName())

		if widget.getType() == "CheckBoxWidget":
			if widget.getStringName() is not None and widget.getStringName() not in stringList:
				stringList.append(widget.getStringName())

		if widget.getType() == "CircularGuageWidget":
			if widget.getTickLabelString() is not None and widget.getTickLabelString() not in stringList:
				stringList.append(widget.getTickLabelString())

		if widget.getType() == "GroupBoxWidget":
			if widget.getStringName() is not None and widget.getStringName() not in stringList:
				stringList.append(widget.getStringName())

		if widget.getType() == "LabelWidget":
			if widget.getStringName() is not None and widget.getStringName() not in stringList:
				stringList.append(widget.getStringName())

		if widget.getType() == "KeyPadWidget":
			rows = widget.getCells()

			for row in rows:
				for cell in row:
					if cell.string is not None and cell.string != "" and cell.string not in stringList:
						stringList.append(cell.string)

					if cell.value is not None and cell.value != "" and cell.value not in stringList:
						stringList.append(cell.value)

		if widget.getType() == "LineGraphWidget":
			categoryList = widget.getCategories()

			for i in range(0, len(categoryList)):
				if categoryList[i].string is not None and categoryList[i].string != "" and categoryList[i].string not in stringList:
					stringList.append(categoryList[i].string)

		if widget.getType() == "ListWidget":
			for item in widget.getItems():
				if item.text is not None and item.text not in stringList:
					stringList.append(item.text)

		if widget.getType() == "ListWheelWidget":
			for item in widget.getItems():
				if item.text is not None and item.text not in stringList:
					stringList.append(item.text)

		if widget.getType() == "RadioButtonWidget":
			if widget.getStringName() is not None and widget.getStringName() not in stringList:
				stringList.append(widget.getStringName())

		if widget.getType() == "TextFieldWidget":
			if widget.getStringName() is not None and widget.getStringName() not in stringList:
				stringList.append(widget.getStringName())

				#TODO hint text string

		if widget.getType() == "WindowWidget":
			if widget.getTitleName() is not None and widget.getTitleName() not in stringList:
				stringList.append(widget.getTitleName())

	return stringList

class WidgetDefault:
	def __init__(self):
		self.width = 100
		self.height = 100
		self.border = "Bevel"
		self.background = "Fill"
		self.halign = "Center"
		self.valign = "Middle"
		self.left = 4
		self.top = 4
		self.right = 4
		self.bottom = 4

commonDefaults = {}

#TODO check on this whole 101 thing

widget = WidgetDefault()
widget.width = 101
widget.height = 101
widget.border = "None"
widget.background = "None"
commonDefaults["ArcWidget"] = widget

widget = WidgetDefault()
widget.width = 101
widget.height = 101
widget.border = "None"
widget.background = "None"
commonDefaults["BarGraphWidget"] = widget

widget = WidgetDefault()
widget.height = 25
commonDefaults["ButtonWidget"] = widget

widget = WidgetDefault()
widget.height = 25
widget.border = "None"
commonDefaults["CheckBoxWidget"] = widget

widget = WidgetDefault()
widget.width = 101
widget.height = 101
widget.border = "None"
widget.background = "None"
commonDefaults["CircleWidget"] = widget

widget = WidgetDefault()
widget.width = 101
widget.height = 101
widget.border = "None"
widget.background = "None"
commonDefaults["CircularGaugeWidget"] = widget

widget = WidgetDefault()
widget.width = 101
widget.height = 101
widget.border = "None"
widget.background = "None"
commonDefaults["CircularSliderWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
commonDefaults["DrawSurfaceWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
commonDefaults["GradientWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
commonDefaults["GroupBoxWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
commonDefaults["ImageWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
commonDefaults["ImagePlusWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
commonDefaults["ImageSequenceWidget"] = widget

widget = WidgetDefault()
widget.width = 200
widget.height = 200
widget.background = "None"
commonDefaults["KeyPadWidget"] = widget

widget = WidgetDefault()
widget.height = 25
widget.border = "None"
widget.halign = "Left"
commonDefaults["LabelWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
widget.background = "None"
commonDefaults["LineWidget"] = widget

widget = WidgetDefault()
widget.width = 101
widget.height = 101
widget.border = "None"
widget.background = "None"
commonDefaults["LineGraphWidget"] = widget

widget = WidgetDefault()
commonDefaults["ListWidget"] = widget

widget = WidgetDefault()
commonDefaults["ListWheelWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
commonDefaults["PanelWidget"] = widget

widget = WidgetDefault()
widget.width = 101
widget.height = 101
widget.border = "None"
widget.background = "None"
commonDefaults["PieChartWidget"] = widget

widget = WidgetDefault()
widget.height = 25
commonDefaults["ProgressBarWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
widget.background = "None"
commonDefaults["RadialMenuWidget"] = widget

widget = WidgetDefault()
widget.height = 25
widget.border = "None"
widget.halign = "Left"
commonDefaults["RadioButtonWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
widget.background = "None"
commonDefaults["RectangleWidget"] = widget

widget = WidgetDefault()
widget.width = 20
commonDefaults["ScrollBarWidget"] = widget

widget = WidgetDefault()
widget.width = 20
commonDefaults["SliderWidget"] = widget

widget = WidgetDefault()
widget.height = 25
commonDefaults["TextFieldWidget"] = widget

widget = WidgetDefault()
widget.border = "None"
commonDefaults["TouchTestWidget"] = widget

widget = WidgetDefault()
commonDefaults["WindowWidget"] = widget


def getDefaultWidth(type):
	return commonDefaults[type].width


def getDefaultHeight(type):
	return commonDefaults[type].height


def getDefaultBorder(type):
	return commonDefaults[type].border


def getDefaultBackground(type):
	return commonDefaults[type].background


def getDefaultHAlign(type):
	return commonDefaults[type].halign


def getDefaultVAlign(type):
	return commonDefaults[type].valign


def getDefaultLeftMargin(type):
	return commonDefaults[type].left


def getDefaultTopMargin(type):
	return commonDefaults[type].top


def getDefaultRightMargin(type):
	return commonDefaults[type].right


def getDefaultBottomMargin(type):
	return commonDefaults[type].bottom
