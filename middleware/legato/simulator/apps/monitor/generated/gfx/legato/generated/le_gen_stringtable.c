#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        ASCII
 * Language Count: 1
 * String Count:   11
*****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of indices in the table
 * unsigned byte - size of each index
 * unsigned byte - number of languages in the table
 * 
 * index array (size = number of indices * number of languages
 * 
 * for each index in the array:
 *   unsigned byte - the font ID for the index
 *   unsigned (index size) - a value of length 'index size' that contains
 *                           the offset of the string codepoint data in
 *                           the table
 * 
 * string data is found by jumping to the index offset from the start
 * of the table
 * 
 * string data entry:
 * unsigned short : length of the string in bytes:
 * 'length' number of codepoints - the string data (encoding dependent
 ****************************************************************************/

const uint8_t stringTable_data[107] =
{
    0x0B,0x00,0x01,0x01,0x02,0x1A,0x00,0x2A,0x03,0x2F,0x01,0x33,0x04,0x3A,0x04,0x3E,
    0x00,0x4A,0x05,0x4F,0x05,0x52,0x02,0x5F,0x02,0x65,0x0E,0x00,0x4D,0x61,0x72,0x63,
    0x68,0x20,0x32,0x36,0x2C,0x20,0x32,0x30,0x31,0x39,0x03,0x00,0x44,0x49,0x41,0x02,
    0x00,0x38,0x34,0x05,0x00,0x50,0x55,0x4C,0x53,0x45,0x02,0x00,0x37,0x30,0x0A,0x00,
    0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x03,0x00,0x53,0x59,0x53,0x01,
    0x00,0x38,0x0B,0x00,0x30,0x31,0x32,0x33,0x34,0x35,0x36,0x37,0x38,0x39,0x20,0x04,
    0x00,0x6D,0x6D,0x48,0x67,0x04,0x00,0x2F,0x6D,0x69,0x6E,
};

/* font asset pointer list */
leFont* fontList[6] =
{
    (leFont*)&Arial48,
    (leFont*)&Arial30,
    (leFont*)&Arial14,
    (leFont*)&Calibri98,
    (leFont*)&Calibri,
    (leFont*)&CourierNew,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        107, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_ASCII // encoding standard
};
