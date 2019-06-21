def testStringValidity(string):
	if string is None:
		return False

	if len(string) == 0:
		return False

	return True

def craftAssetName(string):
	if testStringValidity(string) == False:
		return "NULL"

	return "&" + string

def craftStringAssetName(string):
	if testStringValidity(string) == False:
		return "NULL"

	return "&tableString_" + string

def getRelativePosition(pos):
	if pos == "LeftOf":
		return "LE_RELATIVE_POSITION_LEFTOF"
	elif pos == "Above":
		return "LE_RELATIVE_POSITION_ABOVE"
	elif pos == "RightOf":
		return "LE_RELATIVE_POSITION_RIGHTOF"
	elif pos == "Below":
		return "LE_RELATIVE_POSITION_BELOW"
	else:
		return "LE_RELATIVE_POSITION_BEHIND"

def getDirection(dir):
	if dir == "Right":
		return "LE_DIRECTION_RIGHT"
	elif dir == "Up":
		return "LE_DIRECTION_UP"
	elif dir == "Left":
		return "LE_DIRECTION_LEFT"
	else:
		return "LE_DIRECTION_DOWN"


def getHorzRelativePosition(pos):
	if pos == "LeftOf":
		return "LE_RELATIVE_POSITION_LEFTOF"
	else:
		return "LE_RELATIVE_POSITION_RIGHTOF"

def getOrientation(dir):
	if dir == "Vertical":
		return "LE_ORIENTATION_VERTICAL"
	else:
		return "LE_ORIENTATION_HORIZONTAL"


def getHAlign(dir):
	if dir == "Left":
		return "LE_HALIGN_LEFT"
	elif dir == "Center":
		return "LE_HALIGN_CENTER"
	else:
		return "LE_HALIGN_RIGHT"


def getVAlign(dir):
	if dir == "Top":
		return "LE_VALIGN_TOP"
	elif dir == "Middle":
		return "LE_VALIGN_MIDDLE"
	else:
		return "LE_VALIGN_BOTTOM"


def writeSetInt(file, name, func, val, defaultVal):
	if val == defaultVal:
		return

	file.write("    %s->fn->set%s(%s, %d);" % (name, func, name, val))


def writeSetInt2Arg(file, name, func, val, defaultVal, arg):
	if val == defaultVal:
		return

	file.write("    %s->fn->set%s(%s, %s, %d);" % (name, func, name, arg, val))


def writeSetBool2Arg(file, name, func, val, defaultVal, arg):
	if val == defaultVal:
		return

	if val == True:
		val = "LE_TRUE"
	else:
		val = "LE_FALSE"

	file.write("    %s->fn->set%s(%s, %s, %s);" % (name, func, name, arg, val))


def writeSetLiteralString(file, name, func, val, defaultVal):
	if val == defaultVal:
		return

	file.write("    %s->fn->set%s(%s, %s);" % (name, func, name, val))

def writeSetAssetName(file, name, func, val):
	if testStringValidity(val) == False:
		return

	val = craftAssetName(val)

	if val == "&NULL":
		return

	file.write("    %s->fn->set%s(%s, %s);" % (name, func, name, val))

def writeSetStringAssetName(file, name, func, val):
	if testStringValidity(val) == False:
		return

	val = craftStringAssetName(val)

	if val == "&tableString_NULL":
		return

	file.write("    %s->fn->set%s(%s, (leString*)%s);" % (name, func, name, val))

def writeSetBoolean(file, name, func, val, defaultVal):
	if val == defaultVal:
		return

	if val == True:
		file.write("    %s->fn->set%s(%s, LE_TRUE);" % (name, func, name))
	else:
		file.write("    %s->fn->set%s(%s, LE_FALSE);" % (name, func, name))


def writeEvent(file, name, wgt, evtName, func, cb):
	if wgt.getEventByName(evtName).enabled == False:
		return

	file.write("    %s->fn->set%s(%s, %s_%s);" % (name, func, name, name, cb))


def generateBaseWidget(file, screen, base):
	name = base.getName()
	
	file.write("    %s->fn->setPosition(%s, %d, %d);" % (name, name, base.getX(False), base.getY(False)))

	width = getDefaultWidth(base.getType())
	height = getDefaultHeight(base.getType())

	if width != base.getWidth() or height != base.getHeight():
		file.write("    %s->fn->setSize(%s, %d, %d);" % (name, name, base.getWidth(), base.getHeight()))
	
	if base.getAlphaEnable() == True:
		file.write("    %s->fn->setAlphaEnabled(%s, LE_TRUE);" % (name, name))
		
	alphaAmount = base.getAlphaLevel()
	
	if alphaAmount != 255:
		file.write("    %s->fn->setAlphaAmount(%s, %d);" % (name, name, alphaAmount))
	
	if base.getEnabled() == False:
		file.write("    %s->fn->setEnabled(%s, LE_FALSE);" % (name, name))
	
	if base.getVisible() == False:
		file.write("    %s->fn->setVisible(%s, LE_FALSE);" % (name, name))
		
	scheme = base.getSchemeName()
	
	if testStringValidity(scheme):
		file.write("    %s->fn->setScheme(%s, &%s);" % (name, name, scheme))

	backgroundType = base.getBackgroundType().toString()

	if getDefaultBackground(base.getType()) != backgroundType:
		backgroundType = "LE_WIDGET_BACKGROUND_" + base.getBackgroundType().toString()
		backgroundType = backgroundType.upper()
	
		writeSetLiteralString(file, name, "BackgroundType", backgroundType, "LE_WIDGET_BACKGROUND_FILL")

	borderType = base.getBorderType().toString()

	if getDefaultBorder(base.getType()) != borderType:
		borderType = "LE_WIDGET_BORDER_" + base.getBorderType().toString()
		borderType = borderType.upper()

		writeSetLiteralString(file, name, "BorderType", borderType, "LE_WIDGET_BORDER_BEVEL")

	halign = base.getHAlignment().toString()

	if getDefaultHAlign(base.getType()) != halign:
		halign = getHAlign(halign)

		writeSetLiteralString(file, name, "HAlignment", halign, "LE_HALIGN_CENTER")

	valign = base.getVAlignment().toString()

	if getDefaultVAlign(base.getType()) != valign:
		valign = getVAlign(valign)

		writeSetLiteralString(file, name, "VAlignment", valign, "LE_HALIGN_MIDDLE")

	left = getDefaultLeftMargin(base.getType())
	top = getDefaultTopMargin(base.getType())
	right = getDefaultRightMargin(base.getType())
	bottom = getDefaultBottomMargin(base.getType())

	if left != base.getLeftMargin() or \
		top != base.getTopMargin() or \
		right != base.getRightMargin() or \
		bottom != base.getBottomMargin():
		file.write("    %s->fn->setMargins(%s, %d, %d, %d, %d);" % (name, name, base.getLeftMargin(), base.getTopMargin(), base.getRightMargin(), base.getBottomMargin()))


def generateArcWidget(file, screen, arc, parentName):
	name = arc.getName()

	file.write("    %s = leArcWidget_New();" % (name))

	generateBaseWidget(file, screen, arc)

	writeSetInt(file, name, "Radius", arc.getRadius(), 50)
	writeSetInt(file, name, "StartAngle", arc.getStartAngle(), 0)
	writeSetInt(file, name, "CenterAngle", arc.getCenterAngle(), 135)
	writeSetInt(file, name, "Thickness", arc.getThickness(), 20)
	writeSetBoolean(file, name, "RoundEdge", arc.getUseRoundedEdge(), False)

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateBarGraphWidget(file, screen, bar, parentName):
	name = bar.getName()

	file.write("    %s = leBarGraphWidget_New();" % (name))

	generateBaseWidget(file, screen, bar)

	writeSetBoolean(file, name, "Stacked", bar.getStacked(), False)
	writeSetBoolean(file, name, "FillGraphArea", bar.getFillGraphArea(), True)
	writeSetInt(file, name, "TickLength", bar.getTickLength(), 5)

	if bar.getMinValue() != 0:
		file.write("    %s->fn->setMinValue(%s, BAR_GRAPH_AXIS_0, %d);" % (name, name, bar.getMinValue()))

	if bar.getMaxValue() != 100:
		file.write("    %s->fn->setMaxValue(%s, BAR_GRAPH_AXIS_0, %d);" % (name, name, bar.getMaxValue()))

	if bar.getTickInterval() != 10:
		file.write("    %s->fn->setValueAxisTicksInterval(%s, BAR_GRAPH_AXIS_0, %d);" % (name, name, bar.getTickInterval()))

	if bar.getSubtickInterval() != 5:
		file.write("    %s->fn->setValueAxisSubticksInterval(%s, BAR_GRAPH_AXIS_0, %d);" % (name, name, bar.getSubtickInterval()))

	if bar.getValueAxisTicksVisible() == False:
		file.write("    %s->fn->setValueAxisTicksVisible(%s, BAR_GRAPH_AXIS_0, LE_FALSE);" % (name, name))

	if bar.getValueGridlinesVisible() == False:
		file.write("    %s->fn->setGridLinesVisible(%s, BAR_GRAPH_AXIS_0, LE_FALSE);" % (name, name))

	position = bar.getValueAxisTicksPosition().toString()

	if position != "Center":
		if position == "Inside":
			position = "BAR_GRAPH_TICK_IN"
		elif position == "Outside":
			position = "BAR_GRAPH_TICK_OUT"
		else:
			position = "BAR_GRAPH_TICK_CENTER"

		file.write("    %s->fn->setValueAxisTicksPosition(%s, BAR_GRAPH_AXIS_0, %s);" % (name, name, position))

	if bar.getValueAxisLabelsVisible() == False:
		file.write("    %s->fn->setValueAxisLabelsVisible(%s, BAR_GRAPH_AXIS_0, LE_FALSE);" % (name, name))

	if bar.getValueAxisSubticksVisible() == False:
		file.write("    %s->fn->setValueAxisSubticksVisible(%s, BAR_GRAPH_AXIS_0, LE_FALSE);" % (name, name))

	position = bar.getValueAxisSubticksPosition().toString()

	if position != "Center":
		if position == "Inside":
			position = "BAR_GRAPH_TICK_IN"
		elif position == "Outside":
			position = "BAR_GRAPH_TICK_OUT"
		else:
			position = "BAR_GRAPH_TICK_CENTER"

		file.write("    %s->fn->setValueAxisSubticksPosition(%s, BAR_GRAPH_AXIS_0, %s);" % (name, name, position))

	writeSetStringAssetName(file, name, "TicksLabelString", bar.getLabelStringName())
	writeSetBoolean(file, name, "CategoryAxisTicksVisible", bar.getCategoryAxisTicksVisible(), True)
	writeSetBoolean(file, name, "CategoryAxisLabelsVisible", bar.getCategoryAxisLabelsVisible(), True)

	position = bar.getCategoryAxisTicksPosition().toString()

	if position != "Center":
		if position == "Inside":
			position = "BAR_GRAPH_TICK_IN"
		elif position == "Outside":
			position = "BAR_GRAPH_TICK_OUT"
		else:
			position = "BAR_GRAPH_TICK_CENTER"

		file.write("    %s->fn->setCategoryAxisTicksPosition(%s, %s);" % (name, name, position))

	categoryList = bar.getCategories()

	for i in range(0, len(categoryList)):
		file.write("    %s->fn->addCategory(%s, NULL);" % (name, name))

		stringName = craftStringAssetName(categoryList[i].string)

		if stringName != "NULL":
			file.write("    %s->fn->setCategoryString(%s, %d, (leString*)%s);" % (name, name, i, stringName))

	seriesList = bar.getDataSeries()

	if len(seriesList) > 0:
		for idx, series in enumerate(seriesList):
			file.write("    %s->fn->addSeries(%s, NULL);" % (name, name))

			if testStringValidity(series.scheme):
				file.write("    %s->fn->setSeriesScheme(%s, %d, &%s);" % (name, name, idx, series.scheme))

			for dataVal in series.data:
				file.write("    %s->fn->addDataToSeries(%s, %d, %s, NULL);" % (name, name, idx, dataVal))

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateButtonWidget(file, screen, button, parentName):
	name = button.getName()

	file.write("    %s = leButtonWidget_New();" % (name))

	generateBaseWidget(file, screen, button)

	writeSetBoolean(file, name, "Toggleable", button.getToggleable(), False)
	writeSetBoolean(file, name, "Pressed", button.getPressed(), False)
	writeSetStringAssetName(file, name, "String", button.getStringName())
	writeSetAssetName(file, name, "PressedImage", button.getPressedImageName())
	writeSetAssetName(file, name, "ReleasedImage", button.getReleasedImageName())
	writeSetLiteralString(file, name, "ImagePosition", getRelativePosition(button.getImagePosition().toString()), "LE_RELATIVE_POSITION_LEFTOF")
	writeSetInt(file, name, "ImageMargin", button.getImageMargin(), 10)
	writeSetInt(file, name, "PressedOffset", button.getPressedOffset(), 1)
	writeEvent(file, name, button, "PressedEvent", "PressedEventCallback", "OnPressed")
	writeEvent(file, name, button, "ReleasedEvent", "ReleasedEventCallback", "OnReleased")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateCheckBoxWidget(file, screen, cbox, parentName):
	name = cbox.getName()

	file.write("    %s = leCheckBoxWidget_New();" % (name))

	generateBaseWidget(file, screen, cbox)

	writeSetStringAssetName(file, name, "String", cbox.getStringName())
	writeSetBoolean(file, name, "Checked", cbox.getChecked(), False)
	writeSetAssetName(file, name, "CheckedImage", cbox.getCheckedImageName())
	writeSetAssetName(file, name, "UncheckedImage", cbox.getUncheckedImageName())
	writeSetLiteralString(file, name, "ImagePosition", getRelativePosition(cbox.getImagePosition().toString()), "LE_RELATIVE_POSITION_LEFTOF")
	writeSetInt(file, name, "ImageMargin", cbox.getImageMargin(), 10)
	writeEvent(file, name, cbox, "CheckedEvent", "CheckedEventCallback", "OnChecked")
	writeEvent(file, name, cbox, "UncheckedEvent", "UncheckedEventCallback", "OnUnchecked")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateCircleWidget(file, screen, circle, parentName):
	name = circle.getName()

	file.write("    %s = leCircleWidget_New();" % (name))

	generateBaseWidget(file, screen, circle)

	writeSetInt(file, name, "OriginX", circle.getOriginX(), 50)
	writeSetInt(file, name, "OriginY", circle.getOriginY(), 50)
	writeSetInt(file, name, "Radius", circle.getRadius(), 50)
	writeSetInt(file, name, "Thickness", circle.getThickness(), 1)
	writeSetBoolean(file, name, "Filled", circle.getFilled(), False)

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateCircularGaugeWidget(file, screen, gauge, parentName):
	name = gauge.getName()

	file.write("    %s = leCircularGaugeWidget_New();" % (name))

	generateBaseWidget(file, screen, gauge)

	writeSetInt(file, name, "Radius", gauge.getRadius(), 50)
	writeSetInt(file, name, "StartAngle", gauge.getStartAngle(), 225)
	writeSetInt(file, name, "CenterAngle", gauge.getCenterAngle(), -270)
	writeSetInt(file, name, "StartValue", gauge.getStartValue(), 0)
	writeSetInt(file, name, "EndValue", gauge.getEndValue(), 100)
	writeSetInt(file, name, "Value", gauge.getValue(), 50)
	writeSetAssetName(file, name, "TickLabelFont", gauge.getTickLabelFontName())
	writeSetBoolean(file, name, "TickLabelsVisible", gauge.getTickLabelsVisible(), True)
	writeSetInt(file, name, "TickLength", gauge.getTickLength(), 5)
	writeSetInt(file, name, "TickValue", gauge.getTickValue(), 5)
	writeSetBoolean(file, name, "TicksVisible", gauge.getTicksVisible(), True)
	writeSetBoolean(file, name, "HandVisible", gauge.getHandVisible(), True)
	writeSetInt(file, name, "HandRadius", gauge.getHandRadius(), 40)
	writeSetBoolean(file, name, "CenterCircleVisible", gauge.getCenterCircleVisible(), True)
	writeSetInt(file, name, "CenterCircleRadius", gauge.getCenterCircleRadius(), 5)
	writeSetInt(file, name, "CenterCircleThickness", gauge.getCenterCircleThickness(), 2)


	#TODO gauge direction not in java?
	#TODO add value/angular arc
	#TODO setFont

	#TODO below here is untested

	minorTicks = gauge.getMinorTicks()

	if len(minorTicks) > 0:
		for tick in minorTicks:
			scheme = "NULL"

			if tick.scheme is not None and len(tick.scheme) > 0:
				scheme = "&" + tick.scheme

			file.write("    %s->fn->addMinorTicks(%s, %d, %d, %d, %d, %d, %s);" % (name, name, tick.startValue, tick.endValue, tick.radius, tick.length, tick.interval, scheme))

	minorTickLabels = gauge.getMinorTickLabels()

	if len(minorTickLabels) > 0:
		for lbl in minorTickLabels:
			scheme = "NULL"

			if lbl.scheme is not None and len(lbl.scheme) > 0:
				scheme = "&" + tick.scheme

			pos = ""

			if lbl.position is "Outside":
				pos = "CIRCULAR_GAUGE_LABEL_OUTSIDE"
			else:
				pos = "CIRCULAR_GAUGE_LABEL_INSIDE"

			file.write("    %s->fn->addMinorTickLabels(%s, %d, %d, %d, %s, %d, %s);" % (name, name, lbl.startValue, lbl.endValue, lbl.radius, pos, lbl.interval, scheme))

	writeEvent(file, name, gauge, "ValueChangedEvent", "ValueChangedEventCallback", "OnValueChanged")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateCircularSliderWidget(file, screen, slider, parentName):
	name = slider.getName()

	file.write("    %s = leCircularSliderWidget_New();" % (name))

	generateBaseWidget(file, screen, slider)

	writeSetInt(file, name, "Radius", slider.getRadius(), 50)

	dir = slider.getDirection().toString()

	if dir == "CounterClockwise":
		dir = "CIRCULAR_SLIDER_DIR_COUNTER_CLOCKWISE"
	else:
		dir = "CIRCULAR_SLIDER_DIR_CLOCKWISE"

	writeSetLiteralString(file, name, "Direction", dir, "CIRCULAR_SLIDER_DIR_COUNTER_CLOCKWISE")
	writeSetInt(file, name, "StartAngle", slider.getStartAngle(), 0)
	writeSetInt(file, name, "StartValue", slider.getStartValue(), 0)
	writeSetInt(file, name, "EndValue", slider.getEndValue(), 100)
	writeSetInt(file, name, "Value", slider.getValue(), 50)
	#writeSetBoolean(file, name "RoundEd")

	#TODO rounded edges missing from Legato?

	# outside circle border arc
	writeSetBool2Arg(file, name, "ArcVisible", slider.getOutsideBorderArc().isVisible(), True, "OUTSIDE_CIRCLE_BORDER")
	writeSetInt2Arg(file, name, "ArcThickness", slider.getOutsideBorderArc().getThickness(), 5, "OUTSIDE_CIRCLE_BORDER")

	# inside circle border arc
	rad = slider.getActiveArc().getRadius() - slider.getActiveArc().getThickness()

	writeSetBool2Arg(file, name, "ArcVisible", slider.getInsideBorderArc().isVisible(), True, "INSIDE_CIRCLE_BORDER")
	writeSetInt2Arg(file, name, "ArcThickness", slider.getInsideBorderArc().getThickness(), 5, "INSIDE_CIRCLE_BORDER")

	# inactive arc
	writeSetBool2Arg(file, name, "ArcVisible", slider.getInactiveArc().isVisible(), True, "INACTIVE_AREA")

	# active arc
	writeSetBool2Arg(file, name, "ArcVisible", slider.getActiveArc().isVisible(), True, "ACTIVE_AREA")
	writeSetInt2Arg(file, name, "ArcThickness", slider.getActiveArc().getThickness(), 30, "ACTIVE_AREA")

	# circle button arc
	scheme = slider.getCircularButtonArc().getSchemeName()

	if scheme != "NULL":
		scheme = craftAssetName(scheme)

	writeSetBool2Arg(file, name, "ArcVisible", slider.getCircularButtonArc().isVisible(), True, "CIRCLE_BUTTON")
	writeSetInt2Arg(file, name, "ArcRadius", slider.getCircularButtonArc().getRadius(), 15, "CIRCLE_BUTTON")
	writeSetInt2Arg(file, name, "ArcThickness", slider.getCircularButtonArc().getThickness(), 3, "CIRCLE_BUTTON")

	if scheme != "NULL":
		file.write("    %s->fn->setArcScheme(%s, CIRCLE_BUTTON, %s);" % (name, name, scheme))

	writeEvent(file, name, slider, "ValueChangedEvent", "ValueChangedEventCallback", "OnValueChanged")
	writeEvent(file, name, slider, "PressedEvent", "PressedEventCallback", "OnPressed")
	writeEvent(file, name, slider, "ReleasedEvent", "ReleasedEventCallback", "OnReleased")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateDrawSurfaceWidget(file, screen, surf, parentName):
	name = surf.getName()

	file.write("    %s = leDrawSurfaceWidget_New();" % (name))

	generateBaseWidget(file, screen, surf)

	writeEvent(file, name, surf, "DrawNotificationEvent", "DrawCallback", "OnPaint")
	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateGradientWidget(file, screen, grad, parentName):
	name = grad.getName()

	file.write("    %s = leGradientWidget_New();" % (name))

	generateBaseWidget(file, screen, grad)

	writeSetLiteralString(file, name, "Direction", getDirection(grad.getDirection().toString()), "LE_DIRECTION_RIGHT")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateGroupBoxWidget(file, screen, box, parentName):
	name = box.getName()

	file.write("    %s = leGroupBoxWidget_New();" % (name))

	generateBaseWidget(file, screen, box)

	writeSetStringAssetName(file, name, "String", box.getStringName())

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateImageWidget(file, screen, image, parentName):
	name = image.getName()
	
	file.write("    %s = leImageWidget_New();" % (name))

	generateBaseWidget(file, screen, image)

	writeSetAssetName(file, name, "Image", image.getImageName())

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateImagePlusWidget(file, screen, image, parentName):
	name = image.getName()

	file.write("    %s = leImagePlusWidget_New();" % (name))

	generateBaseWidget(file, screen, image)

	writeSetAssetName(file, name, "Image", image.getImageName())
	writeSetInt(file, name, "TransformX", image.getTransX(), 0)
	writeSetInt(file, name, "TransformY", image.getTransY(), 0)
	writeSetInt(file, name, "TransformWidth", image.getTransWidth(), 0)
	writeSetInt(file, name, "TransformHeight", image.getTransHeight(), 0)
	writeSetBoolean(file, name, "StretchEnabled", image.getResize(), False)
	writeSetBoolean(file, name, "PreserveAspectEnabled", image.getPreserveAspect(), False)

	filter = image.getFilter()

	if filter == "Nearest Neighbor":
		filter = "LE_IMAGEFILTER_NEARESTNEIGHBOR"
	else:
		filter = "LE_IMAGEFILTER_BILINEAR"

	writeSetLiteralString(file, name, "ResizeFilter", filter, "LE_IMAGEFILTER_NEARESTNEIGHBOR")

	writeSetBoolean(file, name, "Interactive", image.getInteractive(), False)

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateImageSequenceWidget(file, screen, seq, parentName):
	name = seq.getName()

	file.write("    %s = leImageSequenceWidget_New();" % (name))

	generateBaseWidget(file, screen, seq)

	entries = seq.getEntries()

	if len(entries) > 0:
		writeSetInt(file, name, "ImageCount", len(entries), 0)

		for idx, entry in enumerate(entries):
			if entry.img != "":
				imgName = craftAssetName(entry.img)

				file.write("    %s->fn->setImage(%s, %d, %s);" % (name, name, idx, imgName))

			if entry.delay != 1000:
				file.write("    %s->fn->setImageDelay(%s, %d, %s);" % (name, name, idx, entry.delay))

			if entry.halign.toString() != "Center":
				file.write("    %s->fn->setImageHAlignment(%s, %d, %s);" % (name, name, idx, getHAlign(entry.halign.toString())))

			if entry.valign.toString() != "Middle":
				file.write("    %s->fn->setImageVAlignment(%s, %d, %s);" % (name, name, idx, getVAlign(entry.valign.toString())))

	if seq.getStartingImage() != 0:
		file.write("    %s->fn->showImage(%s, %d);" % (name, name, seq.getStartingImage()))

	if seq.getPlayingByDefault() == True:
		file.write("    %s->fn->play(%s);" % (name, name))

	writeSetBoolean(file, name, "Repeat", seq.getRepeat(), False)

	writeEvent(file, name, seq, "ImageChangedEvent", "ImageChangedEventCallback", "OnImageChanged")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateKeyPadCell(file, pad, cell, row, col):
	name = pad.getName()

	enabled = cell.enabled
	string = craftStringAssetName(cell.string)
	action = "LE_KEYPAD_CELL_ACTION_" + cell.action.toString().upper()
	value = craftStringAssetName(cell.value)
	pressIcon = craftAssetName(cell.pressIcon)
	releaseIcon = craftAssetName(cell.releaseIcon)
	pos = getRelativePosition(cell.pos.toString())
	margin = cell.imageMargin
	showBackground = cell.background

	shouldGen = False

	if enabled != True \
		and string != "NULL" \
		and value != "NULL" \
		and action != "LE_KEYPAD_CELL_ACTION_NONE" \
		and pressIcon != "NULL" \
		and releaseIcon != "NULL" \
		and pos != "LE_RELATIVE_POSITION_BEHIND" \
		and margin != 10 \
		and showBackground != True:
		return

	if enabled != True \
		or string != "NULL" \
		or pressIcon != "NULL" \
		or releaseIcon != "NULL" \
		or pos != "LE_RELATIVE_POSITION_BEHIND" \
		or margin != 10 \
		or showBackground != True:
		shouldGen = True

	varName = "%s_cell_%d_%d" % (name, row, col)

	if action != "LE_KEYPAD_CELL_ACTION_NONE":
		file.write("    %s->fn->setKeyAction(%s, %d, %d, %s);" % (name, name, row, col, action))

	if value != "NULL":
		file.write("    %s->fn->setKeyValue(%s, %d, %d, %s);" % (name, name, row, col, value))

	if shouldGen == True:
		file.write("    leButtonWidget* %s = %s->fn->getCellButton(%s, %d, %d);" % (varName, name, name, row, col))

		writeSetBoolean(file, varName, "Visible", enabled, True)

		if string != "NULL":
			file.write("    %s->fn->setString(%s, (leString*)%s);" % (varName, varName, string))

		writeSetLiteralString(file, varName, "PressedImage", pressIcon, "NULL")
		writeSetLiteralString(file, varName, "ReleasedImage", releaseIcon, "NULL")
		writeSetLiteralString(file, varName, "ImagePosition", pos, "LE_RELATIVE_POSITION_BEHIND")
		writeSetInt(file, varName, "ImageMargin", margin, 10)

		if showBackground == False:
			file.write("    %s->fn->setBackgroundType(%s, LE_WIDGET_BACKGROUND_NONE);" % (varName, varName))


def generateKeyPadWidget(file, screen, pad, parentName):
	name = pad.getName()

	file.write("    %s = leKeyPadWidget_New(%d, %d);" % (name, pad.getRowCount(), pad.getColCount()))

	generateBaseWidget(file, screen, pad)

	trigMode = pad.getTriggerMode().toString()

	if trigMode == "KeyRelease":
		trigMode = "LE_KEYPAD_TRIGGER_KEYRELEASED"
	else:
		trigMode = "LE_KEYPAD_TRIGGER_KEYPRESSED"

	if trigMode != "LE_KEYPAD_TRIGGER_KEYRELEASED":
		writeSetLiteralString(file, name, "KeyPadActionTrigger", trigMode, "LE_KEYPAD_TRIGGER_KEYRELEASED")

	cells = pad.getCells()

	for row_idx, row in enumerate(cells):
		for col_idx, cell in enumerate(row):
			generateKeyPadCell(file, pad, cell, row_idx, col_idx)

	writeEvent(file, name, pad, "KeyClickEvent", "KeyClickEventCallback", "OnKeyClick")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateLabelWidget(file, screen, label, parentName):
	name = label.getName()
	
	file.write("    %s = leLabelWidget_New();" % (name))

	generateBaseWidget(file, screen, label)

	writeSetStringAssetName(file, name, "String", label.getStringName())

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateLineWidget(file, screen, line, parentName):
	name = line.getName()
	
	file.write("    %s = leLineWidget_New();" % (name))

	generateBaseWidget(file, screen, line)

	file.write("    %s->fn->setStartPoint(%s, %d, %d);" % (name, name, line.getP1X(), line.getP1Y()))
	file.write("    %s->fn->setEndPoint(%s, %d, %d);" % (name, name, line.getP2X(), line.getP2Y()))

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateLineGraphWidget(file, screen, gph, parentName):
	name = gph.getName()

	file.write("    %s = leLineGraphWidget_New();" % (name))

	generateBaseWidget(file, screen, gph)

	writeSetBoolean(file, name, "Stacked", gph.getStacked(), False)
	writeSetBoolean(file, name, "FillGraphArea", gph.getFillGraphArea(), True)
	writeSetBoolean(file, name, "FillSeriesArea", gph.getFillValueArea(), True)
	writeSetInt(file, name, "TickLength", gph.getTickLength(), 5)

	if gph.getMinValue() != 0:
		file.write("    %s->fn->setMinValue(%s, LINE_GRAPH_AXIS_0, %d);" % (name, name, gph.getMinValue()))

	if gph.getMaxValue() != 100:
		file.write("    %s->fn->setMaxValue(%s, LINE_GRAPH_AXIS_0, %d);" % (name, name, gph.getMaxValue()))

	if gph.getTickInterval() != 10:
		file.write("    %s->fn->setValueAxisTickInterval(%s, LINE_GRAPH_AXIS_0, %d);" % (name, name, gph.getTickInterval()))

	if gph.getSubtickInterval() != 5:
		file.write("    %s->fn->setValueAxisSubtickInterval(%s, LINE_GRAPH_AXIS_0, %d);" % (name, name, gph.getSubtickInterval()))

	if gph.getValueAxisTicksVisible() == False:
		file.write("    %s->fn->setValueAxisTicksVisible(%s, LINE_GRAPH_AXIS_0, LE_FALSE);" % (name, name))

	if gph.getValueGridlinesVisible() == False:
		file.write("    %s->fn->setGridLinesVisible(%s, LINE_GRAPH_AXIS_0, LE_FALSE);" % (name, name))

	position = gph.getValueAxisTicksPosition().toString()

	if position != "Center":
		if position == "Inside":
			position = "LINE_GRAPH_TICK_IN"
		elif position == "Outside":
			position = "LINE_GRAPH_TICK_OUT"

		file.write("    %s->fn->setValueAxisTicksPosition(%s, LINE_GRAPH_AXIS_0, %s);" % (name, name, position))

	if gph.getValueAxisLabelsVisible() == False:
		file.write("    %s->fn->setValueAxisLabelsVisible(%s, LINE_GRAPH_AXIS_0, LE_FALSE);" % (name, name))

	if gph.getValueAxisSubticksVisible() == False:
		file.write("    %s->fn->setValueAxisSubticksVisible(%s, LINE_GRAPH_AXIS_0, LE_FALSE);" % (name, name))

	position = gph.getValueAxisSubticksPosition().toString()

	if position != "Center":
		if position == "Inside":
			position = "BAR_GRAPH_TICK_IN"
		elif position == "Outside":
			position = "BAR_GRAPH_TICK_OUT"

		file.write("    %s->fn->setValueAxisSubticksPosition(%s, LINE_GRAPH_AXIS_0, %s);" % (name, name, position))

	writeSetAssetName(file, name, "TicksLabelFont", gph.getLabelFontName())
	writeSetBoolean(file, name, "CategoryAxisTicksVisible", gph.getCategoryAxisTicksVisible(), True)
	writeSetBoolean(file, name, "CategoryAxisLabelsVisible", gph.getCategoryAxisLabelsVisible(), True)

	position = gph.getCategoryAxisTicksPosition().toString()

	if position != "Center":
		if position == "Inside":
			position = "BAR_GRAPH_TICK_IN"
		elif position == "Outside":
			position = "BAR_GRAPH_TICK_OUT"

		file.write("    %s->fn->setCategoryAxisTicksPosition(%s, %s);" % (name, name, position))

	categoryList = gph.getCategories()

	for i in range(0, len(categoryList)):
		file.write("    %s->fn->addCategory(%s);" % (name, name))

		stringName = craftStringAssetName(categoryList[i].string)

		if stringName != "NULL":
			file.write("    %s->fn->setCategoryString(%s, %d, (leString*)%s);" % (name, name, i, stringName))

	seriesList = gph.getDataSeries()

	if len(seriesList) > 0:
		for idx, series in enumerate(seriesList):
			file.write("    %s->fn->addSeries(%s);" % (name, name))

			if testStringValidity(series.scheme):
				file.write("    %s->fn->setSeriesScheme(%s, %d, &%s);" % (name, name, idx, series.scheme))

			for dataVal in series.data:
				file.write("    %s->fn->addDataToSeries(%s, %d, %s);" % (name, name, idx, dataVal))

			pointType = series.pointType

			if pointType == "None":
				pointType = "LINE_GRAPH_DATA_POINT_NONE"
			elif pointType == "Circle":
				pointType = "LINE_GRAPH_DATA_POINT_CIRCLE"
			elif pointType == "Square":
				pointType = "LINE_GRAPH_DATA_POINT_SQUARE"

			if series.drawLines == False:
				file.write("    %s->fn->setSeriesLinesVisible(%s, %d, LE_FALSE);" % (name, name, idx))

			if series.fillPoints == False:
				file.write("    %s->fn->setSeriesFillPoints(%s, %d, LE_FALSE);" % (name, name, idx))

			if series.pointType != "LINE_GRAPH_DATA_POINT_NONE":
				file.write("    %s->fn->setSeriesPointType(%s, %d, %s);" % (name, name, idx, pointType))

			if series.pointSize != 10:
				file.write("    %s->fn->setSeriesPointSize(%s, %d, %d);" % (name, name, idx, series.pointSize))

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateListWidget(file, screen, list, parentName):
	name = list.getName()

	file.write("    %s = leListWidget_New();" % (name))

	generateBaseWidget(file, screen, list)

	mode = list.getSelectionMode().toString()

	if mode != "Single":
		mode = "LE_LIST_WIDGET_SELECTION_MODE_" + mode.upper()

		writeSetLiteralString(file, name, "SelectionMode", mode, "LE_LIST_WIDGET_SELECTION_MODE_SINGLE")

	writeSetBoolean(file, name, "AllowEmptySelection", list.getAllowEmpty(), True)

	pos = getHorzRelativePosition(list.getIconPosition().toString())

	writeSetLiteralString(file, name, "IconPosition", pos, "LE_RELATIVE_POSITION_LEFTOF")
	writeSetInt(file, name, "IconMargin", list.getIconMargin(), 10)

	items = list.getItems()

	if len(items) > 0:
		for idx, item in enumerate(items):
			file.write("    %s->fn->appendItem(%s);" % (name, name))

			text = craftStringAssetName(item.text)

			if text != "NULL":
				file.write("    %s->fn->setItemString(%s, %d, (leString*)%s);" % (name, name, idx, text))

			icon = craftAssetName(item.icon)

			if icon != "NULL":
				file.write("    %s->fn->setItemIcon(%s, %d, %s);" % (name, name, idx, icon))

	writeEvent(file, name, list, "SelectionChangedEvent", "SelectedItemChangedEventCallback", "OnSelectionChanged")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateListWheelWidget(file, screen, list, parentName):
	name = list.getName()

	file.write("    %s = leListWheelWidget_New();" % (name))

	generateBaseWidget(file, screen, list)

	items = list.getItems()

	if len(items) > 0:
		for idx, item in enumerate(items):
			file.write("    %s->fn->appendItem(%s);" % (name, name))

			text = craftStringAssetName(item.text)

			if text != "NULL":
				file.write("    %s->fn->setItemString(%s, %d, (leString*)%s);" % (name, name, idx, text))

			icon = craftAssetName(item.icon)

			if icon != "NULL":
				file.write("    %s->fn->setItemIcon(%s, %d, %s);" % (name, name, idx, icon))

	writeSetInt(file, name, "VisibleItemCount", list.getVisibleItems(), 5)

	selectedIdx = list.getSelectedIndex()

	if selectedIdx != -1:
		writeSetInt(file, name, "SelectedItem", list.getSelectedIndex(), 0)

	pos = getHorzRelativePosition(list.getIconPosition().toString())
	writeSetLiteralString(file, name, "IconPosition", pos, "LE_RELATIVE_POSITION_LEFTOF")

	writeSetInt(file, name, "IconMargin", list.getIconMargin(), 10)
	writeSetBoolean(file, name, "Shaded", list.getShowIndicators(), True)

	effect = list.getEffects().toString()

	if effect != "None":
		if effect == "Fixed":
			effect = "LE_LISTWHEEL_ZOOM_EFFECT_FIXED_SCALE"
		elif effect == "Vertical":
			effect = "LE_LISTWHEEL_ZOOM_EFFECT_VSCALE"
		else:
			effect = "LE_LISTWHEEL_ZOOM_EFFECT_FULL_SCALE"

		writeSetLiteralString(file, name, "ZoomEffects", effect, "LE_LISTWHEEL_ZOOM_EFFECT_NONE")

	writeSetBoolean(file, name, "AutoHideWheel", list.getAutoHideWheel(), False)
	writeSetBoolean(file, name, "Shaded", list.getShaded(), True)
	writeSetBoolean(file, name, "ShowIndicators", list.getShowIndicators(), True)
	writeSetInt(file, name, "IndicatorArea", list.getIndicatorArea(), 20)

	fillMode = list.getIndicatorFill().toString()

	if fillMode == "None":
		fillMode = "LE_LISTWHEEL_INDICATOR_FILL_NONE"
	elif fillMode == "Solid":
		fillMode = "LE_LISTWHEEL_INDICATOR_FILL_SOLID"
	else:
		fillMode = "LE_LISTWHEEL_INDICATOR_FILL_GRADIENT"

	writeSetLiteralString(file, name, "IndicatorFill", fillMode, "LE_LISTWHEEL_INDICATOR_FILL_SOLID")
	writeSetInt(file, name, "FlickInitSpeed", list.getFlickInitSpeed(), 20)
	writeSetInt(file, name, "MaxMomentum", list.getMaxMomentum(), 100)
	writeSetInt(file, name, "RotationUpdateRate", list.getRotationUpdateRate(), 40)
	writeSetInt(file, name, "MomentumFalloffRate", list.getMomentumFalloff(), 1)

	writeEvent(file, name, list, "SelectedItemChangedEvent", "SelectedItemChangedEventCallback", "OnSelectionChanged")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generatePanelWidget(file, screen, panel, parentName):
	name = panel.getName()
	
	file.write("    %s = leWidget_New();" % (name))

	generateBaseWidget(file, screen, panel)

	file.write("    %s->fn->addChild(%s, %s);" % (parentName, parentName, name))
	file.writeNewLine()


def generatePieChartWidget(file, screen, pie, parentName):
	name = pie.getName()

	file.write("    %s = lePieChartWidget_New();" % (name))

	generateBaseWidget(file, screen, pie)

	writeSetInt(file, name, "StartAngle", pie.getStartAngle(), 0)
	writeSetInt(file, name, "CenterAngle", pie.getCenterAngle(), 180)
	writeSetBoolean(file, name, "LabelsVisible", pie.getLabelsVisible(), True)
	writeSetInt(file, name, "LabelsOffset", pie.getLabelsOffset(), 40)
	writeSetAssetName(file, name, "LabelFont", craftAssetName(pie.getLabelFontName()))

	data = pie.getData()

	if len(data) > 0:
		for idx, dataItem in enumerate(data):
			file.write("    %s->fn->addEntry(%s);" % (name, name))

			if dataItem.value != 0:
				file.write("    %s->fn->setEntryValue(%s, %d, %d);" % (name, name, idx, dataItem.value))

			if dataItem.radius != 0:
				file.write("    %s->fn->setEntryRadius(%s, %d, %d);" % (name, name, idx, dataItem.radius))

			if dataItem.offset != 0:
				file.write("    %s->fn->setEntryOffset(%s, %d, %d);" % (name, name, idx, dataItem.offset))

			scheme = craftAssetName(dataItem.scheme)

			if scheme != "NULL":
				file.write("    %s->fn->setEntryScheme(%s, %d, %s);" % (name, name, idx, scheme))

	writeEvent(file, name, pie, "PressedEvent", "PressedEventCallback", "OnPressed")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateProgressBarWidget(file, screen, bar, parentName):
	name = bar.getName()

	file.write("    %s = leProgressBarWidget_New();" % (name))

	generateBaseWidget(file, screen, bar)

	writeSetLiteralString(file, name, "Direction", getDirection(bar.getDirection().toString()), "LE_DIRECTION_RIGHT")
	writeSetInt(file, name, "Value", bar.getValue(), 0)

	writeEvent(file, name, bar, "ValueChangedEvent", "ValueChangedCallback", "OnValueChanged")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateRadialMenuWidget(file, screen, menu, parentName):
	name = menu.getName()

	file.write("    %s = leRadialMenuWidget_New();" % (name))

	generateBaseWidget(file, screen, menu)

	writeSetInt(file, name, "NumberOfItemsShown", menu.getItemsShown(), 5)
	writeSetBoolean(file, name, "HighlightProminent", menu.getHighlightProminent(), False)
	writeSetInt(file, name, "Theta", menu.getTheta(), 0)

	ellipseType = menu.getEllipseType().toString()

	if ellipseType == "Default":
		ellipseType = "LE_RADIAL_MENU_ELLIPSE_TYPE_DEFAULT"
	elif ellipseType == "Orbital":
		ellipseType = "LE_RADIAL_MENU_ELLIPSE_TYPE_OBITAL"
	else:
		ellipseType = "LE_RADIAL_MENU_ELLIPSE_TYPE_ROLLODEX"

	writeSetLiteralString(file, name, "EllipseType", ellipseType, "LE_RADIAL_MENU_ELLIPSE_TYPE_DEFAULT")
	writeSetBoolean(file, name, "DrawEllipse", menu.getEllipseVisible(), True)

	scaleMode = menu.getSizeScale().toString()

	if scaleMode == "Off":
		scaleMode = "LE_RADIAL_MENU_INTERPOLATE_OFF"
	elif scaleMode == "Gradual":
		scaleMode = "LE_RADIAL_MENU_INTERPOLATE_GRADUAL"
	else:
		scaleMode = "LE_RADIAL_MENU_INTERPOLATE_PROMINENT"

	writeSetLiteralString(file, name, "ScaleMode", scaleMode, "LE_RADIAL_MENU_INTERPOLATE_GRADUAL")

	blendMode = menu.getAlphaScale().toString()

	if blendMode == "Off":
		blendMode = "LE_RADIAL_MENU_INTERPOLATE_OFF"
	elif blendMode == "Gradual":
		blendMode = "LE_RADIAL_MENU_INTERPOLATE_GRADUAL"
	else:
		blendMode = "LE_RADIAL_MENU_INTERPOLATE_PROMINENT"

	writeSetLiteralString(file, name, "BlendMode", blendMode, "LE_RADIAL_MENU_INTERPOLATE_GRADUAL")

	min = menu.getMinSizePercent()
	max = menu.getMaxSizePercent()

	if min != 30 or max != 100:
		file.write("    %s->fn->setScaleRange(%s, %d, %d);" % (name, name, min, max))

	min = menu.getMinAlphaAmount()
	max = menu.getMaxAlphaAmount()

	if min != 128 or max != 255:
		file.write("    %s->fn->setBlendRange(%s, %d, %d);" % (name, name, min, max))

	touchX = menu.getTouchX()
	touchY = menu.getTouchY()
	touchWidth = menu.getTouchWidth()
	touchHeight = menu.getTouchHeight()

	if touchX != 0 or touchY != 75 or touchWidth != 100 or touchHeight != 50:
		file.write("    %s->fn->setTouchArea(%s, %d, %d, %d, %d);" % (name, name, touchX, touchY, touchWidth, touchHeight))

	items = menu.getItemList()

	if len(items) > 0:
		for idx, item in enumerate(items):
			varName = "%s_image_%d" % (name, idx)
			file.write("")
			file.write("    %s = leImagePlusWidget_New();" % (varName))
			file.write("    %s->fn->setImage(%s, %s);" % (varName, varName, craftAssetName(item.image)))
			file.write("    %s->fn->addWidget(%s, (leWidget*)%s);" % (name, name, varName))
			file.write("")

			#TODO any other imageplus widget attributes?
			#TODO add global static variables for each item
			#TODO cleanup global static entries

	writeEvent(file, name, menu, "ItemSelectedEvent", "ItemSelectedEventCallback", "OnItemSelected")
	writeEvent(file, name, menu, "ItemProminenceChangedEvent", "ItemProminenceChangedEvent", "OnItemProminenceChanged")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateRadioButtonWidget(file, screen, btn, parentName):
	name = btn.getName()

	file.write("    %s = leRadioButtonWidget_New();" % (name))

	generateBaseWidget(file, screen, btn)

	#TODO add to group

	writeSetStringAssetName(file, name, "String", btn.getStringName())
	writeSetBoolean(file, name, "Selected", btn.getSelected(), True)
	writeSetAssetName(file, name, "SelectedImage", btn.getSelectedImageName())
	writeSetAssetName(file, name, "UnselectedImage", btn.getUnselectedImageName())
	writeSetLiteralString(file, name, "ImagePosition", getRelativePosition(btn.getImagePosition().toString()), "LE_RELATIVE_POSITION_LEFTOF")
	writeSetInt(file, name, "ImageMargin", btn.getImageMargin(), 10)
	writeSetInt(file, name, "CircleButtonSize", btn.getCircleButtonSize(), 12)

	writeEvent(file, name, btn, "SelectedEvent", "SelectedEventCallback", "OnSelected")
	writeEvent(file, name, btn, "DeselectedEvent", "DeselectedEventCallback", "OnDeselected")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateRectangleWidget(file, screen, rect, parentName):
	name = rect.getName()

	file.write("    %s = leRectangleWidget_New();" % (name))

	generateBaseWidget(file, screen, rect)

	writeSetInt(file, name, "Thickness", rect.getThickness(), 2)

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateScrollBarWidget(file, screen, bar, parentName):
	name = bar.getName()

	file.write("    %s = leScrollBarWidget_New();" % (name))

	generateBaseWidget(file, screen, bar)

	orientation = getOrientation(bar.getOrientation().toString())

	if orientation != "LE_ORIENTATION_VERTICAL":
		file.write("    %s->fn->setOrientation(%s, LE_ORIENTATION_HORIZONTAL, LE_TRUE);" % (name, name))

	writeSetInt(file, name, "MaximumValue", bar.getMax(), 100)
	writeSetInt(file, name, "ExtentValue", bar.getExtent(), 10)
	writeSetInt(file, name, "StepSize", bar.getStep(), 1)
	writeSetInt(file, name, "ScrollValue", bar.getValue(), 0)

	writeEvent(file, name, bar, "ValueChangedEvent", "ValueChangedEventCallback", "OnValueChanged")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateSliderWidget(file, screen, sld, parentName):
	name = sld.getName()

	file.write("    %s = leSliderWidget_New();" % (name))

	generateBaseWidget(file, screen, sld)

	orientation = getOrientation(sld.getOrientation().toString())

	if orientation != "LE_ORIENTATION_VERTICAL":
		file.write("    %s->fn->setOrientation(%s, LE_ORIENTATION_HORIZONTAL, LE_TRUE);" % (name, name))

	writeSetInt(file, name, "MinimumValue", sld.getMin(), 0)
	writeSetInt(file, name, "MaximumValue", sld.getMax(), 100)
	writeSetInt(file, name, "Value", sld.getValue(), 0)
	writeSetInt(file, name, "GripSize", sld.getGrip(), 10)

	writeEvent(file, name, sld, "ValueChangedEvent", "ValueChangedEventCallback", "OnValueChanged")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateTextFieldWidget(file, screen, text, parentName):
	name = text.getName()

	file.write("    %s = leTextFieldWidget_New();" % (name))

	generateBaseWidget(file, screen, text)

	writeSetStringAssetName(file, name, "Value", text.getStringName())
	writeSetBoolean(file, name, "CursorEnabled", text.getCursorEnabled(), True)
	writeSetInt(file, name, "CursorDelay", text.getCursorDelay(), 500)

	#TODO hint text

	writeEvent(file, name, text, "TextChangedEvent", "TextChangedEventCallback", "OnTextChanged")
	writeEvent(file, name, text, "FocusChangedEvent", "FocusChangedEventCallback", "OnFocusChanged")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateTouchTestWidget(file, screen, tch, parentName):
	name = tch.getName()

	file.write("    %s = leTouchTestWidget_New();" % (name))

	generateBaseWidget(file, screen, tch)

	writeEvent(file, name, tch, "PointAddedEvent", "PointAddedEventCallback", "OnPointAdded")

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


def generateWindowWidget(file, screen, win, parentName):
	name = win.getName()

	file.write("    %s = leWindowWidget_New();" % (name))

	generateBaseWidget(file, screen, win)

	writeSetStringAssetName(file, name, "Title", win.getTitleName())
	writeSetAssetName(file, name, "Icon", win.getIconName())
	writeSetInt(file, name, "IconMargin", win.getMargin(), 10)

	file.write("    %s->fn->addChild(%s, (leWidget*)%s);" % (parentName, parentName, name))
	file.writeNewLine()


generateFunctions = {
	"ArcWidget" : generateArcWidget,
	"BarGraphWidget" : generateBarGraphWidget,
	"ButtonWidget": generateButtonWidget,
	"CheckBoxWidget": generateCheckBoxWidget,
	"CircleWidget": generateCircleWidget,
	"CircularGaugeWidget": generateCircularGaugeWidget,
	"CircularSliderWidget": generateCircularSliderWidget,
	"DrawSurfaceWidget": generateDrawSurfaceWidget,
	"GradientWidget": generateGradientWidget,
	"GroupBoxWidget": generateGroupBoxWidget,
	"ImageWidget": generateImageWidget,
	"ImagePlusWidget": generateImagePlusWidget,
	"ImageSequenceWidget": generateImageSequenceWidget,
	"KeyPadWidget": generateKeyPadWidget,
	"LabelWidget": generateLabelWidget,
	"LineWidget": generateLineWidget,
	"LineGraphWidget": generateLineGraphWidget,
	"ListWidget": generateListWidget,
	"ListWheelWidget": generateListWheelWidget,
	"PanelWidget": generatePanelWidget,
	"PieChartWidget": generatePieChartWidget,
	"ProgressBarWidget": generateProgressBarWidget,
	"RadialMenuWidget": generateRadialMenuWidget,
	"RadioButtonWidget": generateRadioButtonWidget,
	"RectangleWidget": generateRectangleWidget,
	"ScrollBarWidget": generateScrollBarWidget,
	"SliderWidget": generateSliderWidget,
	"TextFieldWidget": generateTextFieldWidget,
	"TouchTestWidget": generateTouchTestWidget,
	"WindowWidget": generateWindowWidget,
}

def generateWidget(file, screen, widget, parentName):
	generateFunctions[widget.getType()](file, screen, widget, parentName)

	childList = widget.getChildren()
	
	for child in childList:
		generateWidget(file, screen, child, widget.getName())