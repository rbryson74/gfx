def generateStringTableFile():
	global stringTableMatrix
	
	file = File("generated/le_gen_stringtable.c")
	
	file.write('#include "gfx/legato/generated/le_gen_assets.h"')
	file.writeNewLine()
	
	file.write("/*****************************************************************************")
	file.write(" * Legato String Table")
	file.write(" * Encoding        %s" % (StringTable.getEncoding()))
	file.write(" * Language Count: %d" % (stringTableMatrix.languageIDList.size()))
	file.write(" * String Count:   %d" % (stringTableMatrix.stringIDList.size()))
	file.write("*****************************************************************************/")
	file.writeNewLine()
	
	file.write("/*****************************************************************************")
	file.write(" * string table data")
	file.write(" * ")
	file.write(" * this table contains the raw character data for each string")
	file.write(" * ")
	file.write(" * unsigned short - number of strings in the table")
	file.write(" * for each string:")
	file.write(" *   unsigned short - the length of the string")
	file.write(" *   'length' number of codepoints - the characters of the string (depends on encoding)")
	file.write(" ****************************************************************************/")
	file.writeNewLine()
	
	stringContentData = stringTableMatrix.generateStringContentData()
	stringContentDataLength = len(stringContentData)
	
	file.write("const uint8_t stringTable_data[%d] =" % (stringContentDataLength))
	file.write("{")
	
	writeBinaryData(file, stringContentData, stringContentDataLength)
	
	file.write("};")
	file.writeNewLine()
	
	file.write("/*****************************************************************************")
	file.write(" * string index table data")
	file.write(" * ")
	file.write(" * this table quickly maps a string ID to an offset into the string")
	file.write(" * data table")
	file.write(" * ")
	file.write(" * unsigned short - number of indices in the table")
	file.write(" * unsigned byte - number of languages in the table")
	file.write(" * unsigned byte - size of each index, either 1 byte or 2")
	file.write(" * array of index sub arrays - each sub array contains an index for each")
	file.write(" *                             defined language")
	file.write(" * array size is: (language count * index size) * index count")
	file.write(" ****************************************************************************/")
	file.writeNewLine()
	
	stringIndexData = stringTableMatrix.generateStringIndexData()
	stringIndexDataLength = len(stringIndexData)
	
	file.write("const uint8_t stringIndexTable_data[%d] =" % (stringIndexDataLength))
	file.write("{")
	
	writeBinaryData(file, stringIndexData, stringIndexDataLength)
	
	file.write("};")
	file.writeNewLine()
	
	fontList = FontManager.getFontList()
	
	file.write("/* font asset pointer list */")
	file.write("leFont* fontList[%d] =" % (fontList.size()))
	file.write("{")
	
	for font in fontList:
		fontData = font.generateFontData()

		if fontData.glyphs.size() == 0:
			continue

		file.write("    &%s," % (font.getName()))
	
	file.write("};")
	
	fontIndexData = stringTableMatrix.generateFontIndexData()
	fontIndexDataLength = len(fontIndexData)
	
	file.write("/*****************************************************************************")
	file.write(" * font index table")
	file.write(" * ")
	file.write(" * this table maps a string ID to a font asset")
	file.write(" * ")
	file.write(" * unsigned short - number of indices in the table")
	file.write(" * unsigned byte - size of each index, either 1 byte or 2")
	file.write(" * array of index sub arrays - each sub array contains an index for each")
	file.write(" *                             defined language")
	file.write(" * array size is: (language count * index size) * index count")
	file.write(" ****************************************************************************/")
	file.writeNewLine()
	
	file.write("const uint8_t fontIndexTable_data[%d] =" % (fontIndexDataLength))
	file.write("{")
	
	writeBinaryData(file, fontIndexData, fontIndexDataLength)
	
	file.write("};")
	file.writeNewLine()
	
	file.write("const leStringTable stringTable =")
	file.write("{")
	file.write("    {")
	file.write("        LE_ASSET_TYPE_STRINGTABLE, // asset type")
	file.write("        LE_ASSET_LOCATION_ID_INTERNAL, // data location id")
	file.write("        (void*)stringTable_data, // data address pointer")
	file.write("        %d, // data size" % (stringContentDataLength))
	file.write("    },")
	file.write("    %d," % (stringTableMatrix.languageIDList.size()))
	file.write("    %d," % (stringTableMatrix.stringIDList.size()))
	file.write("    (void*)stringIndexTable_data, // font lookup table")
	file.write("    fontList, // font lookup table")
	file.write("    (void*)fontIndexTable_data, // font index table")
	file.write("    LE_STRING_ENCODING_%s // encoding standard" % (StringTable.getEncoding()))
	file.write("};")
	file.close()
	
	global fileDict
	fileDict[file.name] = file