#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Bold
 * Height:       19
 * Baseline:     14
 * Style:        Antialias
 * Glyph Count:  23
 * Range Count:  13
 * Glyph Ranges: 0x20
                 0x41-0x42
                 0x47-0x48
                 0x4C-0x4D
                 0x50
                 0x53
                 0x61
                 0x63
                 0x65
                 0x68-0x69
                 0x6D-0x70
                 0x72-0x75
                 0x79
 *********************************/
/*********************************
 * font glyph kerning table description
 *
 * unsigned int - number of glyphs
 * for each glyph:
 *     unsigned short - codepoint         * the glyph's codepoint
 *     short          - width             * the glyph's width in pixels
 *     short          - height            * the glyph's height in pixels
 *     short          - advance           * the glyph's advance value in pixels
 *     short          - bearingX          * the glyph's bearing value in pixels on the X axis
 *     short          - bearingY          * the glyph's bearing value in pixels on the Y axis
 *     unsigned short - flags             * status flags for this glyph
 *     unsigned short - data row width    * the size of a row of glyph data in bytes
 *     unsigned int   - data table offset * the offset into the corresponding font data table
 ********************************/
const uint8_t NotoSans_Bold_glyphs[464] =
{
    0x17,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x00,0x0C,0x00,0x0D,0x00,0x0C,0x00,
    0x00,0x00,0x0D,0x00,0x00,0x00,0x0C,0x00,0x00,0x00,0x00,0x00,0x42,0x00,0x0A,0x00,
    0x0D,0x00,0x0C,0x00,0x01,0x00,0x0D,0x00,0x00,0x00,0x0A,0x00,0x9C,0x00,0x00,0x00,
    0x47,0x00,0x0B,0x00,0x0D,0x00,0x0D,0x00,0x01,0x00,0x0D,0x00,0x00,0x00,0x0B,0x00,
    0x1E,0x01,0x00,0x00,0x48,0x00,0x0B,0x00,0x0D,0x00,0x0D,0x00,0x01,0x00,0x0D,0x00,
    0x00,0x00,0x0B,0x00,0xAD,0x01,0x00,0x00,0x4C,0x00,0x08,0x00,0x0D,0x00,0x09,0x00,
    0x01,0x00,0x0D,0x00,0x00,0x00,0x08,0x00,0x3C,0x02,0x00,0x00,0x4D,0x00,0x0E,0x00,
    0x0D,0x00,0x10,0x00,0x01,0x00,0x0D,0x00,0x00,0x00,0x0E,0x00,0xA4,0x02,0x00,0x00,
    0x50,0x00,0x09,0x00,0x0D,0x00,0x0B,0x00,0x01,0x00,0x0D,0x00,0x00,0x00,0x09,0x00,
    0x5A,0x03,0x00,0x00,0x53,0x00,0x0A,0x00,0x0D,0x00,0x0A,0x00,0x00,0x00,0x0D,0x00,
    0x00,0x00,0x0A,0x00,0xCF,0x03,0x00,0x00,0x61,0x00,0x09,0x00,0x0A,0x00,0x0A,0x00,
    0x00,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,0x51,0x04,0x00,0x00,0x63,0x00,0x09,0x00,
    0x0A,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,0xAB,0x04,0x00,0x00,
    0x65,0x00,0x0A,0x00,0x0A,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,
    0x05,0x05,0x00,0x00,0x68,0x00,0x09,0x00,0x0E,0x00,0x0B,0x00,0x01,0x00,0x0E,0x00,
    0x00,0x00,0x09,0x00,0x69,0x05,0x00,0x00,0x69,0x00,0x03,0x00,0x0E,0x00,0x05,0x00,
    0x01,0x00,0x0E,0x00,0x00,0x00,0x03,0x00,0xE7,0x05,0x00,0x00,0x6D,0x00,0x0F,0x00,
    0x0A,0x00,0x11,0x00,0x01,0x00,0x0A,0x00,0x00,0x00,0x0F,0x00,0x11,0x06,0x00,0x00,
    0x6E,0x00,0x09,0x00,0x0A,0x00,0x0B,0x00,0x01,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,
    0xA7,0x06,0x00,0x00,0x6F,0x00,0x0A,0x00,0x0A,0x00,0x0B,0x00,0x00,0x00,0x0A,0x00,
    0x00,0x00,0x0A,0x00,0x01,0x07,0x00,0x00,0x70,0x00,0x0A,0x00,0x0E,0x00,0x0B,0x00,
    0x01,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,0x65,0x07,0x00,0x00,0x72,0x00,0x07,0x00,
    0x0A,0x00,0x07,0x00,0x01,0x00,0x0A,0x00,0x00,0x00,0x07,0x00,0xF1,0x07,0x00,0x00,
    0x73,0x00,0x08,0x00,0x0A,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x08,0x00,
    0x37,0x08,0x00,0x00,0x74,0x00,0x07,0x00,0x0C,0x00,0x07,0x00,0x00,0x00,0x0C,0x00,
    0x00,0x00,0x07,0x00,0x87,0x08,0x00,0x00,0x75,0x00,0x09,0x00,0x0A,0x00,0x0B,0x00,
    0x01,0x00,0x0A,0x00,0x00,0x00,0x09,0x00,0xDB,0x08,0x00,0x00,0x79,0x00,0x0A,0x00,
    0x0E,0x00,0x09,0x00,0x00,0x00,0x0A,0x00,0x00,0x00,0x0A,0x00,0x35,0x09,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSans_Bold_data[2497] =
{
    0x00,0x00,0x00,0x00,0x2D,0xFF,0xAD,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x90,0xFC,0xFA,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0xEC,0x9B,0xFD,0x71,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x56,0xFF,0x3F,0xC1,0xD3,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xB9,0xE6,0x02,0x68,0xFF,0x36,0x00,0x00,0x00,0x00,0x00,0x1D,0xFD,
    0x8D,0x00,0x13,0xFA,0x99,0x00,0x00,0x00,0x00,0x00,0x7E,0xFF,0x31,0x00,0x00,0xB3,
    0xF1,0x0A,0x00,0x00,0x00,0x01,0xDF,0xE0,0x24,0x24,0x24,0x75,0xFF,0x5E,0x00,0x00,
    0x00,0x44,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x00,0x00,0xA6,0xFC,0x5D,
    0x54,0x54,0x54,0x54,0xBA,0xFE,0x23,0x00,0x11,0xF7,0xAE,0x00,0x00,0x00,0x00,0x00,
    0x3E,0xFF,0x85,0x00,0x6C,0xFF,0x43,0x00,0x00,0x00,0x00,0x00,0x00,0xD1,0xE4,0x03,
    0xCF,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x66,0xFF,0x4A,0x40,0xFF,0xFF,0xFF,
    0xFD,0xF0,0xCA,0x79,0x0A,0x00,0x40,0xFF,0x91,0x54,0x57,0x6C,0xB3,0xFF,0xBF,0x00,
    0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0xA8,0xFF,0x2D,0x40,0xFF,0x5C,0x00,0x00,0x00,
    0x00,0x6B,0xFF,0x43,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x8F,0xFC,0x1C,0x40,0xFF,
    0x68,0x14,0x14,0x21,0x63,0xF7,0x85,0x00,0x40,0xFF,0xFF,0xFF,0xFF,0xFF,0xFA,0x76,
    0x02,0x00,0x40,0xFF,0x85,0x40,0x40,0x4A,0x77,0xEA,0xD3,0x16,0x40,0xFF,0x5C,0x00,
    0x00,0x00,0x00,0x42,0xFF,0x8E,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x0C,0xFF,0xB5,
    0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x52,0xFF,0x94,0x40,0xFF,0x91,0x54,0x54,0x5B,
    0x89,0xF2,0xEE,0x24,0x40,0xFF,0xFF,0xFF,0xFF,0xF7,0xD9,0x96,0x1F,0x00,0x00,0x00,
    0x00,0x4E,0xAD,0xDE,0xF7,0xEE,0xD5,0x9C,0x34,0x00,0x10,0xB4,0xFF,0xC1,0x74,0x5B,
    0x71,0x9A,0xE8,0x3D,0x00,0xB2,0xFD,0x5D,0x00,0x00,0x00,0x00,0x00,0x02,0x00,0x48,
    0xFF,0x89,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA3,0xFF,0x19,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xCD,0xE0,0x00,0x00,0x00,0x00,0x0D,0x14,0x14,0x14,0x0F,
    0xE1,0xD0,0x00,0x00,0x00,0x00,0xAC,0xFF,0xFF,0xFF,0xC4,0xD0,0xE1,0x00,0x00,0x00,
    0x00,0x2B,0x40,0x40,0xE2,0xC4,0xAB,0xFE,0x16,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,
    0xC4,0x5B,0xFF,0x7A,0x00,0x00,0x00,0x00,0x00,0x00,0xD8,0xC4,0x06,0xD1,0xF6,0x49,
    0x00,0x00,0x00,0x00,0x00,0xD8,0xC4,0x00,0x26,0xDB,0xFE,0xB8,0x72,0x59,0x5D,0x83,
    0xF1,0xC4,0x00,0x00,0x0F,0x76,0xCB,0xEC,0xFD,0xF5,0xDE,0xAD,0x5D,0x40,0xFF,0x5C,
    0x00,0x00,0x00,0x00,0x00,0x0C,0xFF,0x94,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,
    0x0C,0xFF,0x94,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x0C,0xFF,0x94,0x40,0xFF,
    0x5C,0x00,0x00,0x00,0x00,0x00,0x0C,0xFF,0x94,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,
    0x00,0x0C,0xFF,0x94,0x40,0xFF,0x68,0x14,0x14,0x14,0x14,0x14,0x1F,0xFF,0x94,0x40,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x94,0x40,0xFF,0x85,0x40,0x40,0x40,
    0x40,0x40,0x49,0xFF,0x94,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x0C,0xFF,0x94,
    0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x0C,0xFF,0x94,0x40,0xFF,0x5C,0x00,0x00,
    0x00,0x00,0x00,0x0C,0xFF,0x94,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x0C,0xFF,
    0x94,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x0C,0xFF,0x94,0x40,0xFF,0x5C,0x00,
    0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,
    0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,
    0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,
    0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,
    0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,
    0x00,0x00,0x00,0x00,0x40,0xFF,0xA6,0x74,0x74,0x74,0x74,0x72,0x40,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFC,0x40,0xFF,0xFF,0x53,0x00,0x00,0x00,0x00,0x00,0x00,0x0A,0xF1,
    0xFF,0x94,0x40,0xFF,0xF7,0xB1,0x00,0x00,0x00,0x00,0x00,0x00,0x5D,0xFE,0xF9,0x94,
    0x40,0xFF,0xAF,0xFA,0x15,0x00,0x00,0x00,0x00,0x00,0xBE,0xBD,0xF1,0x94,0x40,0xFF,
    0x5A,0xFF,0x6F,0x00,0x00,0x00,0x00,0x20,0xFE,0x5B,0xFD,0x94,0x40,0xFF,0x39,0xC5,
    0xCE,0x00,0x00,0x00,0x00,0x7F,0xF1,0x0B,0xFF,0x94,0x40,0xFF,0x3B,0x65,0xFF,0x2C,
    0x00,0x00,0x01,0xDE,0x99,0x04,0xFF,0x94,0x40,0xFF,0x3C,0x0E,0xF6,0x8B,0x00,0x00,
    0x41,0xFF,0x38,0x04,0xFF,0x94,0x40,0xFF,0x3C,0x00,0xA5,0xE6,0x03,0x00,0xA1,0xD6,
    0x00,0x04,0xFF,0x94,0x40,0xFF,0x3C,0x00,0x45,0xFF,0x49,0x0D,0xF5,0x75,0x00,0x04,
    0xFF,0x94,0x40,0xFF,0x3C,0x00,0x02,0xE2,0xA8,0x63,0xFB,0x18,0x00,0x04,0xFF,0x94,
    0x40,0xFF,0x3C,0x00,0x00,0x85,0xF7,0xCF,0xB2,0x00,0x00,0x04,0xFF,0x94,0x40,0xFF,
    0x3C,0x00,0x00,0x25,0xFF,0xFF,0x51,0x00,0x00,0x04,0xFF,0x94,0x40,0xFF,0x3C,0x00,
    0x00,0x00,0xC4,0xEB,0x05,0x00,0x00,0x04,0xFF,0x94,0x40,0xFF,0xFF,0xFF,0xFA,0xE4,
    0xA8,0x30,0x00,0x40,0xFF,0x91,0x54,0x63,0x8D,0xF0,0xF8,0x37,0x40,0xFF,0x5C,0x00,
    0x00,0x00,0x2D,0xFA,0xB9,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0xCB,0xED,0x40,0xFF,
    0x5C,0x00,0x00,0x00,0x00,0xC8,0xE8,0x40,0xFF,0x5C,0x00,0x00,0x00,0x1B,0xF5,0xAF,
    0x40,0xFF,0x68,0x15,0x29,0x5B,0xD5,0xF9,0x31,0x40,0xFF,0xFF,0xFF,0xFF,0xFF,0xC6,
    0x37,0x00,0x40,0xFF,0x85,0x3F,0x31,0x15,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,0x00,
    0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x40,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x4A,0xBE,0xF0,0xF7,0xDE,0xB1,0x4D,0x00,0x00,0x57,0xFE,0xC5,0x68,0x62,0x87,
    0xD6,0x6F,0x00,0x00,0xCD,0xE1,0x06,0x00,0x00,0x00,0x00,0x04,0x00,0x00,0xDF,0xC4,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xAE,0xFB,0x44,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x29,0xEB,0xFD,0xAB,0x42,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0x9D,0xF8,
    0xFF,0xD6,0x4B,0x00,0x00,0x00,0x00,0x00,0x00,0x15,0x77,0xEA,0xFF,0x64,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x17,0xE3,0xE3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x9E,0xFE,0x02,0x01,0x00,0x00,0x00,0x00,0x00,0x07,0xD5,0xDA,0x00,0x14,0xDD,0x95,
    0x72,0x5B,0x71,0xCE,0xFD,0x52,0x00,0x08,0x9D,0xD6,0xEE,0xF9,0xDF,0xAA,0x33,0x00,
    0x00,0x00,0x03,0x63,0xBF,0xE7,0xF4,0xD0,0x59,0x00,0x00,0x00,0xC9,0x9E,0x6B,0x62,
    0xC6,0xFE,0x3B,0x00,0x00,0x00,0x00,0x00,0x00,0x12,0xFE,0x86,0x00,0x00,0x00,0x00,
    0x07,0x12,0x14,0xEC,0xA2,0x00,0x0D,0x8C,0xE0,0xFF,0xFF,0xFF,0xFF,0xA4,0x00,0xBA,
    0xFF,0x99,0x54,0x42,0x40,0xF1,0xA4,0x1B,0xFF,0xA4,0x00,0x00,0x00,0x05,0xFA,0xA4,
    0x18,0xFF,0x8B,0x00,0x00,0x00,0x5B,0xFF,0xA4,0x00,0xD2,0xF2,0x77,0x5F,0x98,0xDF,
    0xDC,0xA4,0x00,0x24,0xB4,0xF1,0xF1,0xB3,0x23,0x9C,0xA4,0x00,0x00,0x13,0x93,0xE0,
    0xF8,0xE3,0xA3,0x00,0x00,0x12,0xDF,0xF4,0x86,0x5F,0x83,0x91,0x00,0x00,0x8C,0xFF,
    0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0xDA,0xD1,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xF7,0xAE,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xAD,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xDE,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x92,0xFF,0x3B,0x00,0x00,
    0x00,0x00,0x00,0x00,0x16,0xE6,0xF2,0x82,0x5C,0x75,0xA3,0x00,0x00,0x00,0x1B,0x9F,
    0xE6,0xFA,0xE6,0x97,0x00,0x00,0x00,0x15,0x9A,0xE6,0xF6,0xCD,0x57,0x00,0x00,0x00,
    0x0D,0xDA,0xE8,0x77,0x62,0xB2,0xFF,0x62,0x00,0x00,0x82,0xFA,0x2A,0x00,0x00,0x00,
    0xC4,0xE6,0x02,0x00,0xD5,0xC9,0x14,0x14,0x14,0x14,0x87,0xFF,0x27,0x00,0xF7,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x3A,0x00,0xF9,0xC2,0x40,0x40,0x40,0x40,0x40,0x40,
    0x0F,0x00,0xDA,0xD4,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0xFF,0x4D,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0xD8,0xFA,0x93,0x5F,0x69,0x92,0xB2,0x00,0x00,
    0x00,0x0F,0x8D,0xDD,0xFA,0xF5,0xCC,0x69,0x00,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0xFF,0x1C,0x00,0x00,
    0x00,0x00,0x00,0x00,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0xFF,0x2B,
    0x9F,0xEC,0xF2,0xC9,0x4B,0x00,0x78,0xFF,0xD5,0xA1,0x5D,0x6B,0xDA,0xFE,0x39,0x78,
    0xFF,0xA0,0x00,0x00,0x00,0x28,0xFF,0x8E,0x78,0xFF,0x44,0x00,0x00,0x00,0x00,0xF0,
    0xA8,0x78,0xFF,0x25,0x00,0x00,0x00,0x00,0xE8,0xAC,0x78,0xFF,0x1C,0x00,0x00,0x00,
    0x00,0xE8,0xAC,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0xE8,0xAC,0x78,0xFF,0x1C,0x00,
    0x00,0x00,0x00,0xE8,0xAC,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0xE8,0xAC,0x78,0xFF,
    0x1C,0x00,0x00,0x00,0x00,0xE8,0xAC,0x65,0xE4,0x20,0x6C,0xEF,0x23,0x00,0x01,0x00,
    0x00,0x00,0x00,0x78,0xFF,0x1C,0x78,0xFF,0x1C,0x78,0xFF,0x1C,0x78,0xFF,0x1C,0x78,
    0xFF,0x1C,0x78,0xFF,0x1C,0x78,0xFF,0x1C,0x78,0xFF,0x1C,0x78,0xFF,0x1C,0x78,0xFF,
    0x1C,0x78,0xE3,0x19,0xA8,0xF1,0xF2,0xB5,0x21,0x18,0xA2,0xED,0xF0,0xBD,0x2F,0x00,
    0x78,0xFE,0xD4,0x9F,0x61,0x85,0xF8,0xD1,0xD2,0xAE,0x64,0x77,0xEF,0xEA,0x0A,0x78,
    0xFF,0x99,0x00,0x00,0x00,0x8C,0xFF,0xAF,0x00,0x00,0x00,0x68,0xFF,0x45,0x78,0xFF,
    0x41,0x00,0x00,0x00,0x5A,0xFF,0x5A,0x00,0x00,0x00,0x36,0xFF,0x5C,0x78,0xFF,0x25,
    0x00,0x00,0x00,0x54,0xFF,0x40,0x00,0x00,0x00,0x30,0xFF,0x60,0x78,0xFF,0x1C,0x00,
    0x00,0x00,0x54,0xFF,0x3C,0x00,0x00,0x00,0x30,0xFF,0x60,0x78,0xFF,0x1C,0x00,0x00,
    0x00,0x54,0xFF,0x3C,0x00,0x00,0x00,0x30,0xFF,0x60,0x78,0xFF,0x1C,0x00,0x00,0x00,
    0x54,0xFF,0x3C,0x00,0x00,0x00,0x30,0xFF,0x60,0x78,0xFF,0x1C,0x00,0x00,0x00,0x54,
    0xFF,0x3C,0x00,0x00,0x00,0x30,0xFF,0x60,0x78,0xFF,0x1C,0x00,0x00,0x00,0x54,0xFF,
    0x3C,0x00,0x00,0x00,0x30,0xFF,0x60,0x78,0xE3,0x16,0x9F,0xEB,0xF3,0xCA,0x4C,0x00,
    0x78,0xFE,0xD3,0xAE,0x67,0x6B,0xDA,0xFE,0x38,0x78,0xFF,0xA4,0x00,0x00,0x00,0x28,
    0xFF,0x8E,0x78,0xFF,0x44,0x00,0x00,0x00,0x00,0xF0,0xA8,0x78,0xFF,0x25,0x00,0x00,
    0x00,0x00,0xE8,0xAC,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0xE8,0xAC,0x78,0xFF,0x1C,
    0x00,0x00,0x00,0x00,0xE8,0xAC,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0xE8,0xAC,0x78,
    0xFF,0x1C,0x00,0x00,0x00,0x00,0xE8,0xAC,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0xE8,
    0xAC,0x00,0x00,0x17,0x98,0xE5,0xF9,0xDC,0x81,0x07,0x00,0x00,0x13,0xDE,0xF2,0x83,
    0x60,0x8E,0xFA,0xC2,0x04,0x00,0x8D,0xFF,0x3A,0x00,0x00,0x00,0x59,0xFF,0x68,0x00,
    0xDB,0xD0,0x00,0x00,0x00,0x00,0x02,0xE9,0xBE,0x00,0xFB,0xAC,0x00,0x00,0x00,0x00,
    0x00,0xC6,0xDF,0x00,0xF7,0xAE,0x00,0x00,0x00,0x00,0x00,0xC7,0xE2,0x00,0xD4,0xD5,
    0x00,0x00,0x00,0x00,0x03,0xEB,0xC1,0x00,0x7E,0xFF,0x43,0x00,0x00,0x00,0x5F,0xFF,
    0x70,0x00,0x0A,0xD2,0xF4,0x86,0x60,0x8F,0xFB,0xCA,0x07,0x00,0x00,0x0E,0x90,0xE2,
    0xFA,0xDF,0x8A,0x0C,0x00,0x78,0xE5,0x11,0xA0,0xED,0xF6,0xBF,0x36,0x00,0x00,0x78,
    0xFE,0xCC,0xA3,0x63,0x78,0xE8,0xF6,0x2D,0x00,0x78,0xFF,0x97,0x00,0x00,0x00,0x2A,
    0xFD,0xAD,0x00,0x78,0xFF,0x3E,0x00,0x00,0x00,0x00,0xC0,0xF0,0x00,0x78,0xFF,0x22,
    0x00,0x00,0x00,0x00,0x9C,0xFF,0x0C,0x78,0xFF,0x28,0x00,0x00,0x00,0x00,0x99,0xFF,
    0x0B,0x78,0xFF,0x46,0x00,0x00,0x00,0x00,0xC2,0xEE,0x00,0x78,0xFF,0xA2,0x00,0x00,
    0x00,0x2B,0xFD,0xA9,0x00,0x78,0xFF,0xE2,0xAA,0x65,0x71,0xE4,0xF5,0x2B,0x00,0x78,
    0xFF,0x2F,0xAD,0xF0,0xF6,0xBE,0x34,0x00,0x00,0x78,0xFF,0x1B,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0xFF,0x1C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x78,0xDF,0x05,0x8B,0xEB,0xF7,0x15,0x78,0xF6,0xA6,0xCB,0x65,0x64,0x00,0x78,
    0xFF,0xC6,0x06,0x00,0x00,0x00,0x78,0xFF,0x4C,0x00,0x00,0x00,0x00,0x78,0xFF,0x21,
    0x00,0x00,0x00,0x00,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0x78,0xFF,0x1C,0x00,0x00,
    0x00,0x00,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,
    0x78,0xFF,0x1C,0x00,0x00,0x00,0x00,0x00,0x14,0x94,0xE1,0xF8,0xE3,0xB4,0x3E,0x00,
    0xC2,0xE9,0x75,0x5C,0x7B,0xC2,0x42,0x09,0xFE,0x82,0x00,0x00,0x00,0x00,0x00,0x00,
    0xDA,0xE2,0x44,0x00,0x00,0x00,0x00,0x00,0x26,0xC7,0xFF,0xD7,0x71,0x0C,0x00,0x00,
    0x00,0x00,0x3D,0xA4,0xFB,0xE4,0x2D,0x00,0x00,0x00,0x00,0x00,0x2B,0xF2,0xB1,0x01,
    0x01,0x00,0x00,0x00,0x00,0xCD,0xC5,0x10,0xDF,0x8C,0x65,0x5F,0xA2,0xFF,0x73,0x06,
    0x95,0xE1,0xFB,0xF0,0xCA,0x63,0x00,0x00,0x00,0xDD,0x3C,0x00,0x00,0x00,0x00,0x34,
    0xFF,0x3C,0x00,0x00,0x00,0x78,0xF4,0xFF,0xFF,0xFF,0xFF,0x08,0x3C,0x8F,0xFF,0x7C,
    0x54,0x54,0x02,0x00,0x58,0xFF,0x3C,0x00,0x00,0x00,0x00,0x58,0xFF,0x3C,0x00,0x00,
    0x00,0x00,0x58,0xFF,0x3C,0x00,0x00,0x00,0x00,0x58,0xFF,0x3C,0x00,0x00,0x00,0x00,
    0x58,0xFF,0x3C,0x00,0x00,0x00,0x00,0x4C,0xFF,0x54,0x00,0x00,0x00,0x00,0x17,0xFA,
    0xDB,0x62,0x66,0x0E,0x00,0x00,0x52,0xDA,0xFA,0xDF,0x14,0x94,0xFF,0x08,0x00,0x00,
    0x00,0x00,0xFC,0x98,0x94,0xFF,0x08,0x00,0x00,0x00,0x00,0xFC,0x98,0x94,0xFF,0x08,
    0x00,0x00,0x00,0x00,0xFC,0x98,0x94,0xFF,0x08,0x00,0x00,0x00,0x00,0xFC,0x98,0x94,
    0xFF,0x08,0x00,0x00,0x00,0x00,0xFC,0x98,0x94,0xFF,0x08,0x00,0x00,0x00,0x07,0xFF,
    0x98,0x91,0xFF,0x0F,0x00,0x00,0x00,0x25,0xFF,0x98,0x79,0xFF,0x44,0x00,0x00,0x00,
    0x86,0xFF,0x98,0x28,0xFB,0xE5,0x71,0x63,0x9E,0xE6,0xF4,0x98,0x00,0x43,0xC4,0xF0,
    0xF2,0xB4,0x29,0xC8,0x98,0xC9,0xE2,0x02,0x00,0x00,0x00,0x00,0xB6,0xF3,0x0B,0x62,
    0xFF,0x45,0x00,0x00,0x00,0x15,0xFB,0x9D,0x00,0x0A,0xF0,0xA7,0x00,0x00,0x00,0x6C,
    0xFF,0x3C,0x00,0x00,0x94,0xF7,0x10,0x00,0x00,0xC7,0xDA,0x00,0x00,0x00,0x2D,0xFF,
    0x6A,0x00,0x23,0xFF,0x7A,0x00,0x00,0x00,0x00,0xC7,0xCA,0x00,0x7C,0xFD,0x1C,0x00,
    0x00,0x00,0x00,0x60,0xFF,0x24,0xD3,0xB8,0x00,0x00,0x00,0x00,0x00,0x09,0xEF,0x94,
    0xFF,0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x92,0xFB,0xEE,0x07,0x00,0x00,0x00,0x00,
    0x00,0x00,0x35,0xFF,0x95,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x69,0xFF,0x34,0x00,
    0x00,0x00,0x00,0x00,0x00,0x08,0xDB,0xC7,0x00,0x00,0x00,0x00,0x00,0x4C,0x5F,0xC1,
    0xFB,0x3C,0x00,0x00,0x00,0x00,0x00,0xBF,0xF9,0xD3,0x4E,0x00,0x00,0x00,0x00,0x00,
    0x00,
};

leRasterFont NotoSans_Bold =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)NotoSans_Bold_data, // data address pointer
            2497, // data size
        },
        LE_RASTER_FONT,
    },
    19,
    14,
    LE_FONT_BPP_8, // bits per pixel
    NotoSans_Bold_glyphs, // glyph table
};
