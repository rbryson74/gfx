"""def splitText(text, lineLength, tabCount):
	lastSpace = 0
	cnt = 0
	
	if(len(text) <= lineLength):
		return text

	for(i in range(len(text)))
		if(cnt > lineLength)
			
	
		if(text[i] == ' '):
			last"""

def writeBinaryData(file, data, length):
	itr = 0
	
	for i in range(length):
		if itr % 16 == 0:
			file.writeNoNewline("    ")
		
		val = (data[i] & 0xFF)
		strVal = "0x%02X" % val
		
		file.writeNoNewline(strVal)
		
		if itr < 15 and i < length - 1:
			file.writeNoNewline(",")
			itr += 1
		else:
			file.write(",")
			itr = 0
			
def writeFileDescription(file, name, summary, desc):
	text = headerDesc.replace("${FILENAME}", name)
	text = headerDesc.replace("${FILESUMMARY}", summary)
	text = headerDesc.replace("${FILEDESC}", desc)
	
	file.write(text)