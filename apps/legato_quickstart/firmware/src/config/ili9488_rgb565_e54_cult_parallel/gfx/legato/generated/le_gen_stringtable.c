#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   2
*****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of strings in the table
 * for each string:
 *   unsigned short - the length of the string
 *   'length' number of codepoints - the characters of the string (depends on encoding)
 ****************************************************************************/

const uint8_t stringTable_data[60] =
{
    0x02,0x00,0x1F,0x00,0x4D,0x50,0x4C,0x41,0x42,0x20,0x48,0x61,0x72,0x6D,0x6F,0x6E,
    0x79,0x20,0x47,0x72,0x61,0x70,0x68,0x69,0x63,0x73,0x20,0x43,0x6F,0x6D,0x70,0x6F,
    0x73,0x65,0x72,0x17,0x00,0x4D,0x6F,0x64,0x69,0x66,0x79,0x2E,0x20,0x52,0x65,0x67,
    0x65,0x6E,0x65,0x72,0x61,0x74,0x65,0x2E,0x20,0x52,0x75,0x6E,
};

/*****************************************************************************
 * string index table data
 * 
 * this table quickly maps a string ID to an offset into the string
 * data table
 * 
 * unsigned short - number of indices in the table
 * unsigned byte - number of languages in the table
 * unsigned byte - size of each index, either 1 byte or 2
 * array of index sub arrays - each sub array contains an index for each
 *                             defined language
 * array size is: (language count * index size) * index count
 ****************************************************************************/

const uint8_t stringIndexTable_data[6] =
{
    0x02,0x00,0x01,0x01,0x02,0x23,
};

/* font asset pointer list */
leFont* fontList[1] =
{
    &NotoSans_Medium,
};
/*****************************************************************************
 * font index table
 * 
 * this table maps a string ID to a font asset
 * 
 * unsigned short - number of indices in the table
 * unsigned byte - size of each index, either 1 byte or 2
 * array of index sub arrays - each sub array contains an index for each
 *                             defined language
 * array size is: (language count * index size) * index count
 ****************************************************************************/

const uint8_t fontIndexTable_data[5] =
{
    0x01,0x00,0x01,0x00,0x00,
};

const leStringTable stringTable =
{
    {
        LE_ASSET_TYPE_STRINGTABLE, // asset type
        LE_ASSET_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        60, // data size
    },
    1,
    2,
    (void*)stringIndexTable_data, // font lookup table
    fontList, // font lookup table
    (void*)fontIndexTable_data, // font index table
    LE_STRING_ENCODING_ASCII // encoding standard
};
