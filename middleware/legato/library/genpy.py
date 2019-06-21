import os

file = open("output.txt", "w")

def cleanupPath(path):
	path = path.replace('\\', '/')
	
	while path.find('//') > 0:
		path = path.replace('//', '/')
	
	return path
	
for root, directories, filenames in os.walk("src/"):
	#for directory in directories:
	#	print os.path.join(root, directory) 
	
	for filename in filenames:
		if filename.endswith("c") == False and filename.endswith("h") == False:
			continue
			
		if "rtos" in filename.lower() == True:
			continue
			
		type = filename[-1:]
		symbolName = filename[:-2].upper() + "_" + type.upper()
		sourcePath = root + '/' + filename
		sourcePath = cleanupPath(sourcePath)
		destPath = "gfx/legato/" + root + '/'
		destPath = destPath.replace("src", "")
		destPath = cleanupPath(destPath)
		fileType = "HEADER"
		
		if type == "c":
			fileType = "SOURCE"
		
		file.write('%s = component.createFileSymbol("%s", None)\n' % (symbolName, symbolName))
		file.write('%s.setSourcePath("%s")\n' % (symbolName, sourcePath))
		file.write('%s.setDestPath("%s")\n' % (symbolName, destPath))
		filePath = root.replace("src", "")
		filePath = cleanupPath(filePath)
		file.write('%s.setProjectPath(projectPath + "/%s")\n' % (symbolName, filePath))
		file.write('%s.setOutputName("%s")\n' % (symbolName, filename))
		file.write('%s.setType("%s")\n' % (symbolName, fileType))
		file.write("\n")
		
		#print os.path.join(root,filename) 
		
file.close()