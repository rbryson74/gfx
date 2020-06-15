#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Bold
 * Height:       21
 * Baseline:     15
 * Style:        Antialias
 * Glyph Count:  28
 * Range Count:  13
 * Glyph Ranges: 0x20
                 0x41-0x44
                 0x46
                 0x4C-0x4D
                 0x4F
                 0x53
                 0x55
                 0x61
                 0x63-0x65
                 0x67-0x69
                 0x6B-0x70
                 0x72-0x74
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
const uint8_t NotoSans_Bold_data[564] =
{
    0x1C,0x00,0x00,0x00,0x20,0x00,0x00,0x00,0x00,0x00,0x05,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x41,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,
    0x00,0x00,0x0E,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x42,0x00,0x0C,0x00,
    0x0E,0x00,0x0D,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x0C,0x00,0xC4,0x00,0x00,0x00,
    0x43,0x00,0x0C,0x00,0x0E,0x00,0x0D,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x0C,0x00,
    0x6C,0x01,0x00,0x00,0x44,0x00,0x0D,0x00,0x0E,0x00,0x0F,0x00,0x01,0x00,0x0E,0x00,
    0x00,0x00,0x0D,0x00,0x14,0x02,0x00,0x00,0x46,0x00,0x09,0x00,0x0E,0x00,0x0B,0x00,
    0x01,0x00,0x0E,0x00,0x00,0x00,0x09,0x00,0xCC,0x02,0x00,0x00,0x4C,0x00,0x0A,0x00,
    0x0E,0x00,0x0B,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x0A,0x00,0x4C,0x03,0x00,0x00,
    0x4D,0x00,0x11,0x00,0x0E,0x00,0x13,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x11,0x00,
    0xD8,0x03,0x00,0x00,0x4F,0x00,0x0E,0x00,0x0E,0x00,0x10,0x00,0x01,0x00,0x0E,0x00,
    0x00,0x00,0x0E,0x00,0xC8,0x04,0x00,0x00,0x53,0x00,0x0B,0x00,0x0E,0x00,0x0B,0x00,
    0x00,0x00,0x0E,0x00,0x00,0x00,0x0B,0x00,0x8C,0x05,0x00,0x00,0x55,0x00,0x0D,0x00,
    0x0E,0x00,0x0F,0x00,0x01,0x00,0x0E,0x00,0x00,0x00,0x0D,0x00,0x28,0x06,0x00,0x00,
    0x61,0x00,0x0B,0x00,0x0B,0x00,0x0C,0x00,0x00,0x00,0x0B,0x00,0x00,0x00,0x0B,0x00,
    0xE0,0x06,0x00,0x00,0x63,0x00,0x0A,0x00,0x0B,0x00,0x0A,0x00,0x00,0x00,0x0B,0x00,
    0x00,0x00,0x0A,0x00,0x5C,0x07,0x00,0x00,0x64,0x00,0x0C,0x00,0x0F,0x00,0x0D,0x00,
    0x00,0x00,0x0F,0x00,0x00,0x00,0x0C,0x00,0xCC,0x07,0x00,0x00,0x65,0x00,0x0B,0x00,
    0x0B,0x00,0x0C,0x00,0x00,0x00,0x0B,0x00,0x00,0x00,0x0B,0x00,0x80,0x08,0x00,0x00,
    0x67,0x00,0x0C,0x00,0x10,0x00,0x0D,0x00,0x00,0x00,0x0B,0x00,0x00,0x00,0x0C,0x00,
    0xFC,0x08,0x00,0x00,0x68,0x00,0x0B,0x00,0x0F,0x00,0x0D,0x00,0x01,0x00,0x0F,0x00,
    0x00,0x00,0x0B,0x00,0xBC,0x09,0x00,0x00,0x69,0x00,0x04,0x00,0x0F,0x00,0x06,0x00,
    0x01,0x00,0x0F,0x00,0x00,0x00,0x04,0x00,0x64,0x0A,0x00,0x00,0x6B,0x00,0x0C,0x00,
    0x0F,0x00,0x0C,0x00,0x01,0x00,0x0F,0x00,0x00,0x00,0x0C,0x00,0xA0,0x0A,0x00,0x00,
    0x6C,0x00,0x04,0x00,0x0F,0x00,0x06,0x00,0x01,0x00,0x0F,0x00,0x00,0x00,0x04,0x00,
    0x54,0x0B,0x00,0x00,0x6D,0x00,0x12,0x00,0x0B,0x00,0x14,0x00,0x01,0x00,0x0B,0x00,
    0x00,0x00,0x12,0x00,0x90,0x0B,0x00,0x00,0x6E,0x00,0x0B,0x00,0x0B,0x00,0x0D,0x00,
    0x01,0x00,0x0B,0x00,0x00,0x00,0x0B,0x00,0x58,0x0C,0x00,0x00,0x6F,0x00,0x0C,0x00,
    0x0B,0x00,0x0C,0x00,0x00,0x00,0x0B,0x00,0x00,0x00,0x0C,0x00,0xD4,0x0C,0x00,0x00,
    0x70,0x00,0x0B,0x00,0x10,0x00,0x0D,0x00,0x01,0x00,0x0B,0x00,0x00,0x00,0x0B,0x00,
    0x58,0x0D,0x00,0x00,0x72,0x00,0x08,0x00,0x0B,0x00,0x09,0x00,0x01,0x00,0x0B,0x00,
    0x00,0x00,0x08,0x00,0x08,0x0E,0x00,0x00,0x73,0x00,0x0A,0x00,0x0B,0x00,0x0A,0x00,
    0x00,0x00,0x0B,0x00,0x00,0x00,0x0A,0x00,0x60,0x0E,0x00,0x00,0x74,0x00,0x09,0x00,
    0x0E,0x00,0x09,0x00,0x00,0x00,0x0E,0x00,0x00,0x00,0x09,0x00,0xD0,0x0E,0x00,0x00,
    0x79,0x00,0x0C,0x00,0x10,0x00,0x0B,0x00,0x00,0x00,0x0B,0x00,0x00,0x00,0x0C,0x00,
    0x50,0x0F,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSans_Bold_glyphs[4112] =
{
    0x00,0x00,0x00,0x00,0x23,0xFF,0xFF,0xFF,0xE6,0x03,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x7F,0xFF,0xFF,0xFF,0xFF,0x46,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xDA,0xFF,0xD4,0xF6,0xFF,0xA3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x37,0xFF,0xFF,
    0x7F,0xB4,0xFF,0xF4,0x0B,0x00,0x00,0x00,0x00,0x00,0x00,0x94,0xFF,0xFF,0x31,0x62,
    0xFF,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x04,0xEB,0xFF,0xDE,0x00,0x12,0xFB,0xFF,
    0xB8,0x00,0x00,0x00,0x00,0x00,0x4C,0xFF,0xFF,0x8B,0x00,0x00,0xB8,0xFF,0xFC,0x18,
    0x00,0x00,0x00,0x00,0xA8,0xFF,0xFF,0x39,0x00,0x00,0x63,0xFF,0xFF,0x72,0x00,0x00,
    0x00,0x0E,0xF6,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xCE,0x00,0x00,0x00,0x61,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x2A,0x00,0x00,0xBD,0xFF,0xFF,
    0x9F,0x84,0x84,0x84,0x84,0xB9,0xFF,0xFF,0x87,0x00,0x1C,0xFD,0xFF,0xF7,0x0A,0x00,
    0x00,0x00,0x00,0x34,0xFF,0xFF,0xE2,0x01,0x76,0xFF,0xFF,0xB5,0x00,0x00,0x00,0x00,
    0x00,0x01,0xE6,0xFF,0xFF,0x40,0xD2,0xFF,0xFF,0x69,0x00,0x00,0x00,0x00,0x00,0x00,
    0x9A,0xFF,0xFF,0x9D,0x34,0xFF,0xFF,0xFF,0xFF,0xFC,0xF1,0xD3,0x99,0x33,0x00,0x00,
    0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x57,0x00,0x34,0xFF,0xFF,0xE2,
    0x64,0x67,0x82,0xE2,0xFF,0xFF,0xD8,0x00,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x32,
    0xFF,0xFF,0xFB,0x00,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x34,0xFF,0xFF,0xE2,0x00,
    0x34,0xFF,0xFF,0xE2,0x64,0x65,0x7D,0xDD,0xFF,0xFF,0x79,0x00,0x34,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xF8,0x6E,0x00,0x00,0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xF1,0x67,0x00,0x34,0xFF,0xFF,0xD0,0x00,0x01,0x14,0x70,0xFF,0xFF,0xFC,0x1E,
    0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0xD3,0xFF,0xFF,0x55,0x34,0xFF,0xFF,0xD0,
    0x00,0x00,0x00,0x0B,0xEC,0xFF,0xFF,0x52,0x34,0xFF,0xFF,0xE2,0x64,0x64,0x77,0xCE,
    0xFF,0xFF,0xF8,0x16,0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x68,0x00,
    0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFA,0xE3,0xA7,0x38,0x00,0x00,0x00,0x00,0x00,0x35,
    0x9E,0xD7,0xF4,0xF5,0xD3,0x8F,0x3A,0x00,0x00,0x02,0x85,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xD2,0x00,0x00,0x78,0xFF,0xFF,0xFE,0xAA,0x6D,0x76,0xB9,0xFE,0x6B,0x00,
    0x1C,0xF9,0xFF,0xFF,0x5D,0x00,0x00,0x00,0x00,0x27,0x0D,0x00,0x74,0xFF,0xFF,0xCB,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB0,0xFF,0xFF,0x77,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xCB,0xFF,0xFF,0x57,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xCD,0xFF,0xFF,0x54,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xB7,0xFF,0xFF,0x70,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x86,0xFF,0xFF,0xB8,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x36,0xFF,0xFF,0xFE,0x3F,0x00,0x00,0x00,0x00,0x00,0x07,0x00,
    0x00,0xAB,0xFF,0xFF,0xF9,0x9E,0x6B,0x75,0x94,0xD6,0x7F,0x00,0x00,0x11,0xBF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,0x05,0x5E,0xBC,0xE3,0xF9,0xEC,
    0xD3,0x95,0x2F,0x00,0x34,0xFF,0xFF,0xFF,0xFF,0xF9,0xE2,0xBE,0x6E,0x12,0x00,0x00,
    0x00,0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE9,0x4F,0x00,0x00,0x34,0xFF,
    0xFF,0xE2,0x64,0x67,0x82,0xD3,0xFF,0xFF,0xFB,0x40,0x00,0x34,0xFF,0xFF,0xD0,0x00,
    0x00,0x00,0x02,0x99,0xFF,0xFF,0xDF,0x02,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,
    0x07,0xE9,0xFF,0xFF,0x47,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0xA4,0xFF,
    0xFF,0x7C,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x87,0xFF,0xFF,0x99,0x34,
    0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x89,0xFF,0xFF,0x97,0x34,0xFF,0xFF,0xD0,
    0x00,0x00,0x00,0x00,0x00,0xAA,0xFF,0xFF,0x7D,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,
    0x00,0x0E,0xF1,0xFF,0xFF,0x3F,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x07,0xAD,0xFF,
    0xFF,0xD5,0x02,0x34,0xFF,0xFF,0xE2,0x64,0x6A,0x8C,0xE1,0xFF,0xFF,0xF7,0x3B,0x00,
    0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE3,0x40,0x00,0x00,0x34,0xFF,0xFF,
    0xFF,0xFF,0xF6,0xE2,0xB0,0x63,0x09,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFC,0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x34,0xFF,
    0xFF,0xDD,0x64,0x64,0x64,0x64,0x62,0x34,0xFF,0xFF,0xC8,0x00,0x00,0x00,0x00,0x00,
    0x34,0xFF,0xFF,0xC8,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xC8,0x00,0x00,0x00,
    0x00,0x00,0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xA0,0x34,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xA0,0x34,0xFF,0xFF,0xDD,0x64,0x64,0x64,0x64,0x3E,0x34,0xFF,0xFF,
    0xC8,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xC8,0x00,0x00,0x00,0x00,0x00,0x34,
    0xFF,0xFF,0xC8,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xC8,0x00,0x00,0x00,0x00,
    0x00,0x34,0xFF,0xFF,0xC8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,
    0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xD0,0x00,0x00,
    0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,
    0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,
    0x00,0x00,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xD0,
    0x00,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,
    0x34,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x00,0x34,0xFF,0xFF,0xE7,0x7C,0x7C,
    0x7C,0x7C,0x7C,0x4D,0x34,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xA0,0x34,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xA0,0x34,0xFF,0xFF,0xFF,0xFD,0x16,0x00,0x00,
    0x00,0x00,0x00,0x3B,0xFF,0xFF,0xFF,0xFF,0x10,0x34,0xFF,0xFF,0xFF,0xFF,0x64,0x00,
    0x00,0x00,0x00,0x00,0x90,0xFF,0xFF,0xFF,0xFF,0x10,0x34,0xFF,0xFF,0xF9,0xFF,0xB5,
    0x00,0x00,0x00,0x00,0x01,0xE4,0xFF,0xFF,0xFF,0xFF,0x10,0x34,0xFF,0xFF,0xBB,0xFF,
    0xF8,0x0D,0x00,0x00,0x00,0x3B,0xFF,0xFF,0xCE,0xFF,0xFF,0x10,0x34,0xFF,0xFF,0x7A,
    0xFD,0xFF,0x56,0x00,0x00,0x00,0x91,0xFF,0xD2,0xAE,0xFF,0xFF,0x10,0x34,0xFF,0xFF,
    0x71,0xC4,0xFF,0xA7,0x00,0x00,0x01,0xE4,0xFF,0x7C,0xB8,0xFF,0xFF,0x10,0x34,0xFF,
    0xFF,0x79,0x75,0xFF,0xF1,0x06,0x00,0x3C,0xFF,0xFF,0x26,0xBF,0xFF,0xFF,0x10,0x34,
    0xFF,0xFF,0x7F,0x27,0xFF,0xFF,0x48,0x00,0x91,0xFF,0xD0,0x00,0xC3,0xFF,0xFF,0x10,
    0x34,0xFF,0xFF,0x80,0x00,0xD8,0xFF,0x98,0x01,0xE5,0xFF,0x79,0x00,0xC4,0xFF,0xFF,
    0x10,0x34,0xFF,0xFF,0x80,0x00,0x8A,0xFF,0xE7,0x3E,0xFF,0xFF,0x23,0x00,0xC4,0xFF,
    0xFF,0x10,0x34,0xFF,0xFF,0x80,0x00,0x3B,0xFF,0xFF,0xC9,0xFF,0xCD,0x00,0x00,0xC4,
    0xFF,0xFF,0x10,0x34,0xFF,0xFF,0x80,0x00,0x02,0xEA,0xFF,0xFF,0xFF,0x77,0x00,0x00,
    0xC4,0xFF,0xFF,0x10,0x34,0xFF,0xFF,0x80,0x00,0x00,0x9E,0xFF,0xFF,0xFF,0x21,0x00,
    0x00,0xC4,0xFF,0xFF,0x10,0x34,0xFF,0xFF,0x80,0x00,0x00,0x4F,0xFF,0xFF,0xCB,0x00,
    0x00,0x00,0xC4,0xFF,0xFF,0x10,0x00,0x00,0x00,0x00,0x00,0x43,0xA5,0xD8,0xF3,0xF2,
    0xD7,0x9F,0x3B,0x00,0x00,0x00,0x00,0x08,0xA1,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x90,0x04,0x00,0x00,0x94,0xFF,0xFF,0xFD,0xAA,0x6F,0x70,0xAE,0xFF,0xFF,0xFF,
    0x7E,0x00,0x2A,0xFE,0xFF,0xFF,0x5A,0x00,0x00,0x00,0x00,0x69,0xFF,0xFF,0xFA,0x19,
    0x80,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x03,0xE0,0xFF,0xFF,0x6A,0xB5,0xFF,
    0xFF,0x83,0x00,0x00,0x00,0x00,0x00,0x00,0x97,0xFF,0xFF,0xA0,0xCC,0xFF,0xFF,0x66,
    0x00,0x00,0x00,0x00,0x00,0x00,0x7A,0xFF,0xFF,0xB8,0xCC,0xFF,0xFF,0x66,0x00,0x00,
    0x00,0x00,0x00,0x00,0x7A,0xFF,0xFF,0xB7,0xB3,0xFF,0xFF,0x83,0x00,0x00,0x00,0x00,
    0x00,0x00,0x97,0xFF,0xFF,0x9F,0x7C,0xFF,0xFF,0xD0,0x00,0x00,0x00,0x00,0x00,0x03,
    0xE0,0xFF,0xFF,0x69,0x27,0xFD,0xFF,0xFF,0x59,0x00,0x00,0x00,0x00,0x69,0xFF,0xFF,
    0xF9,0x18,0x00,0x90,0xFF,0xFF,0xFD,0xA8,0x6D,0x6F,0xAE,0xFE,0xFF,0xFF,0x7C,0x00,
    0x00,0x07,0x9F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x8E,0x03,0x00,0x00,0x00,
    0x00,0x44,0xA5,0xDA,0xF4,0xF2,0xD7,0x9D,0x39,0x00,0x00,0x00,0x00,0x00,0x1A,0x93,
    0xDB,0xF8,0xEE,0xD0,0x98,0x43,0x02,0x00,0x26,0xEB,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xE7,0x05,0x00,0xAB,0xFF,0xFF,0xCE,0x6F,0x7E,0xAC,0xF6,0x81,0x00,0x00,0xE2,0xFF,
    0xFF,0x20,0x00,0x00,0x00,0x0D,0x0E,0x00,0x00,0xD9,0xFF,0xFF,0x5F,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x82,0xFF,0xFF,0xFF,0xAA,0x2D,0x00,0x00,0x00,0x00,0x00,0x05,
    0xBA,0xFF,0xFF,0xFF,0xFE,0xAD,0x20,0x00,0x00,0x00,0x00,0x02,0x6E,0xE8,0xFF,0xFF,
    0xFF,0xF0,0x3B,0x00,0x00,0x00,0x00,0x00,0x09,0x6C,0xED,0xFF,0xFF,0xE0,0x02,0x00,
    0x00,0x00,0x00,0x00,0x00,0x19,0xEA,0xFF,0xFF,0x29,0x09,0x49,0x04,0x00,0x00,0x00,
    0x00,0xD4,0xFF,0xFF,0x2B,0x14,0xFF,0xE8,0x9F,0x72,0x6C,0xAE,0xFF,0xFF,0xE5,0x03,
    0x14,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x48,0x00,0x04,0x63,0xB2,0xDE,0xF5,
    0xF9,0xDD,0x9C,0x29,0x00,0x00,0x00,0x00,0x4C,0xFF,0xFF,0xB8,0x00,0x00,0x00,0x00,
    0x00,0x98,0xFF,0xFF,0x6C,0x4C,0xFF,0xFF,0xB8,0x00,0x00,0x00,0x00,0x00,0x98,0xFF,
    0xFF,0x6C,0x4C,0xFF,0xFF,0xB8,0x00,0x00,0x00,0x00,0x00,0x98,0xFF,0xFF,0x6C,0x4C,
    0xFF,0xFF,0xB8,0x00,0x00,0x00,0x00,0x00,0x98,0xFF,0xFF,0x6C,0x4C,0xFF,0xFF,0xB8,
    0x00,0x00,0x00,0x00,0x00,0x98,0xFF,0xFF,0x6C,0x4C,0xFF,0xFF,0xB8,0x00,0x00,0x00,
    0x00,0x00,0x98,0xFF,0xFF,0x6C,0x4C,0xFF,0xFF,0xB8,0x00,0x00,0x00,0x00,0x00,0x98,
    0xFF,0xFF,0x6C,0x4C,0xFF,0xFF,0xB8,0x00,0x00,0x00,0x00,0x00,0x98,0xFF,0xFF,0x6C,
    0x4B,0xFF,0xFF,0xBA,0x00,0x00,0x00,0x00,0x00,0x9D,0xFF,0xFF,0x6B,0x3F,0xFF,0xFF,
    0xD3,0x00,0x00,0x00,0x00,0x00,0xBD,0xFF,0xFF,0x5A,0x13,0xFD,0xFF,0xFF,0x3E,0x00,
    0x00,0x00,0x31,0xFC,0xFF,0xFF,0x29,0x00,0xA7,0xFF,0xFF,0xFC,0xAE,0x8C,0xA7,0xF7,
    0xFF,0xFF,0xB9,0x00,0x00,0x12,0xD0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xD4,0x18,
    0x00,0x00,0x00,0x08,0x70,0xC4,0xEF,0xFB,0xE9,0xC3,0x6F,0x07,0x00,0x00,0x00,0x00,
    0x00,0x00,0x2E,0x93,0xD7,0xF6,0xF9,0xDB,0x8F,0x14,0x00,0x00,0x06,0xE5,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xD9,0x0A,0x00,0x00,0x6D,0xD6,0x92,0x71,0x7B,0xE9,0xFF,0xFF,
    0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6F,0xFF,0xFF,0x8C,0x00,0x00,0x3D,0x98,
    0xC4,0xD4,0xD8,0xE7,0xFF,0xFF,0x94,0x00,0x75,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0x94,0x09,0xF6,0xFF,0xFF,0x7B,0x17,0x02,0x61,0xFF,0xFF,0x94,0x20,0xFF,0xFF,
    0xF4,0x00,0x00,0x00,0x9A,0xFF,0xFF,0x94,0x06,0xFC,0xFF,0xFF,0xA1,0x6F,0xA8,0xFF,
    0xFF,0xFF,0x94,0x00,0xA3,0xFF,0xFF,0xFF,0xFF,0xFF,0x9D,0xF4,0xFF,0x94,0x00,0x0D,
    0x90,0xE3,0xF8,0xD9,0x73,0x02,0xAA,0xFF,0x94,0x00,0x00,0x00,0x00,0x00,0x01,0x60,
    0xC0,0xEC,0xFB,0xE5,0xA7,0x3A,0x00,0x02,0xB0,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x5F,
    0x00,0x6E,0xFF,0xFF,0xF8,0x8F,0x71,0xA0,0xE4,0x0B,0x00,0xD1,0xFF,0xFF,0x63,0x00,
    0x00,0x00,0x02,0x00,0x02,0xFC,0xFF,0xFF,0x0D,0x00,0x00,0x00,0x00,0x00,0x13,0xFF,
    0xFF,0xF6,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0xFF,0xFF,0xFF,0x0B,0x00,0x00,0x00,
    0x00,0x00,0x00,0xE0,0xFF,0xFF,0x61,0x00,0x00,0x00,0x04,0x10,0x00,0x8B,0xFF,0xFF,
    0xF8,0x8E,0x6F,0x90,0xE0,0x50,0x00,0x10,0xD6,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x50,
    0x00,0x00,0x0E,0x84,0xD6,0xF7,0xFA,0xE0,0x8C,0x14,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xE0,0xFF,0xFF,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xE0,0xFF,0xFF,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xE0,0xFF,0xFF,0x18,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xDD,0xFF,0xFF,0x18,0x00,0x00,0x1E,0xA8,
    0xEF,0xF4,0xBE,0x34,0xCE,0xFF,0xFF,0x18,0x00,0x14,0xE3,0xFF,0xFF,0xFF,0xFF,0xF5,
    0xDB,0xFF,0xFF,0x18,0x00,0x8F,0xFF,0xFF,0xF5,0x84,0x7A,0xD9,0xFF,0xFF,0xFF,0x18,
    0x00,0xE0,0xFF,0xFF,0x5E,0x00,0x00,0x19,0xFA,0xFF,0xFF,0x18,0x09,0xFF,0xFF,0xFF,
    0x09,0x00,0x00,0x00,0xC9,0xFF,0xFF,0x18,0x14,0xFF,0xFF,0xF2,0x00,0x00,0x00,0x00,
    0xB3,0xFF,0xFF,0x18,0x09,0xFF,0xFF,0xFE,0x07,0x00,0x00,0x00,0xC5,0xFF,0xFF,0x18,
    0x00,0xE2,0xFF,0xFF,0x57,0x00,0x00,0x13,0xF6,0xFF,0xFF,0x18,0x00,0x93,0xFF,0xFF,
    0xF3,0x84,0x76,0xD4,0xFF,0xFF,0xFF,0x18,0x00,0x17,0xE7,0xFF,0xFF,0xFF,0xFF,0xE9,
    0xCC,0xFF,0xFF,0x18,0x00,0x00,0x22,0xAD,0xF2,0xF2,0xB5,0x26,0x5E,0xFF,0xFF,0x18,
    0x00,0x00,0x01,0x66,0xC7,0xF0,0xF7,0xD2,0x77,0x06,0x00,0x00,0x01,0xAE,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xBE,0x05,0x00,0x68,0xFF,0xFF,0xDE,0x79,0x72,0xCC,0xFF,0xFF,
    0x71,0x00,0xCC,0xFF,0xFF,0x27,0x00,0x00,0x0C,0xF2,0xFF,0xC7,0x02,0xFB,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xEA,0x11,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xF4,0x03,0xFC,0xFF,0xFC,0x65,0x64,0x64,0x64,0x64,0x64,0x5F,0x00,0xCF,0xFF,
    0xFF,0x49,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x65,0xFF,0xFF,0xF6,0x97,0x6C,0x77,
    0x94,0xD8,0x57,0x00,0x00,0x9E,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x58,0x00,0x00,
    0x00,0x51,0xB4,0xE8,0xFB,0xF3,0xCE,0x7C,0x14,0x00,0x00,0x00,0x00,0x00,0x1F,0xA9,
    0xEF,0xF4,0xBD,0x34,0x7F,0xFF,0xFF,0x18,0x00,0x13,0xE3,0xFF,0xFF,0xFF,0xFF,0xF5,
    0xCF,0xFF,0xFF,0x18,0x00,0x8C,0xFF,0xFF,0xF2,0x83,0x78,0xD9,0xFF,0xFF,0xFF,0x18,
    0x00,0xDE,0xFF,0xFF,0x57,0x00,0x00,0x19,0xF9,0xFF,0xFF,0x18,0x08,0xFF,0xFF,0xFF,
    0x09,0x00,0x00,0x00,0xC8,0xFF,0xFF,0x18,0x14,0xFF,0xFF,0xF6,0x00,0x00,0x00,0x00,
    0xB3,0xFF,0xFF,0x18,0x09,0xFF,0xFF,0xFF,0x09,0x00,0x00,0x00,0xC2,0xFF,0xFF,0x18,
    0x00,0xE2,0xFF,0xFF,0x57,0x00,0x00,0x0E,0xF0,0xFF,0xFF,0x18,0x00,0x93,0xFF,0xFF,
    0xF3,0x83,0x74,0xCE,0xFF,0xFF,0xFF,0x18,0x00,0x1A,0xEA,0xFF,0xFF,0xFF,0xFF,0xE5,
    0xE5,0xFF,0xFF,0x18,0x00,0x00,0x27,0xB2,0xF2,0xF2,0xB3,0x25,0xDE,0xFF,0xFF,0x18,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xFF,0xFF,0x10,0x00,0x17,0x07,0x00,
    0x00,0x00,0x00,0x37,0xFF,0xFF,0xEE,0x01,0x00,0x70,0xF2,0xAB,0x86,0x6D,0x82,0xEB,
    0xFF,0xFF,0x9B,0x00,0x00,0x70,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xD9,0x15,0x00,
    0x00,0x2B,0x96,0xD6,0xED,0xFB,0xF3,0xCD,0x7D,0x0D,0x00,0x00,0x70,0xFF,0xFF,0x8C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,
    0x87,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x7C,0x57,0xCE,0xF7,0xE2,
    0xA3,0x20,0x00,0x70,0xFF,0xFF,0xC5,0xFF,0xFF,0xFF,0xFF,0xFF,0xE9,0x15,0x70,0xFF,
    0xFF,0xFF,0xD5,0x79,0x89,0xF9,0xFF,0xFF,0x73,0x70,0xFF,0xFF,0xF2,0x11,0x00,0x00,
    0x8F,0xFF,0xFF,0x9B,0x70,0xFF,0xFF,0xAF,0x00,0x00,0x00,0x5F,0xFF,0xFF,0xA4,0x70,
    0xFF,0xFF,0x94,0x00,0x00,0x00,0x58,0xFF,0xFF,0xA4,0x70,0xFF,0xFF,0x8C,0x00,0x00,
    0x00,0x58,0xFF,0xFF,0xA4,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x58,0xFF,0xFF,0xA4,
    0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x58,0xFF,0xFF,0xA4,0x70,0xFF,0xFF,0x8C,0x00,
    0x00,0x00,0x58,0xFF,0xFF,0xA4,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x58,0xFF,0xFF,
    0xA4,0x00,0x00,0x00,0x49,0xE0,0xE7,0x60,0x78,0xFF,0xFF,0x97,0x05,0x4E,0x54,0x0A,
    0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,
    0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,
    0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,
    0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x8C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x70,0xFF,0xFF,0x8C,0x00,0x00,0x02,0xAA,0xFF,0xFF,0xAC,0x02,0x70,0xFF,0xFF,0x8C,
    0x00,0x00,0x97,0xFF,0xFF,0xBE,0x07,0x00,0x70,0xFF,0xFF,0x8A,0x00,0x82,0xFF,0xFF,
    0xCE,0x0E,0x00,0x00,0x70,0xFF,0xFF,0x7F,0x68,0xFF,0xFF,0xDB,0x16,0x00,0x00,0x00,
    0x70,0xFF,0xFF,0xA4,0xFB,0xFF,0xF3,0x22,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0x56,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0xFF,0xD0,0xFC,0xFF,0xF1,
    0x22,0x00,0x00,0x00,0x70,0xFF,0xFF,0xB9,0x06,0x84,0xFF,0xFF,0xCA,0x06,0x00,0x00,
    0x70,0xFF,0xFF,0x8C,0x00,0x04,0xCB,0xFF,0xFF,0x8E,0x00,0x00,0x70,0xFF,0xFF,0x8C,
    0x00,0x00,0x26,0xF5,0xFF,0xFF,0x4C,0x00,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x66,
    0xFF,0xFF,0xEC,0x1C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,
    0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,
    0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,
    0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,0x70,0xFF,0xFF,0x8C,
    0x70,0xFF,0xEF,0x00,0x4C,0xCC,0xF7,0xE2,0x85,0x05,0x01,0x70,0xDB,0xF6,0xD6,0x78,
    0x06,0x00,0x70,0xFF,0xFF,0x68,0xFE,0xFF,0xFF,0xFF,0xFF,0x97,0x82,0xFF,0xFF,0xFF,
    0xFF,0xFF,0x92,0x00,0x70,0xFF,0xFF,0xFF,0xCC,0x74,0xA7,0xFF,0xFF,0xFF,0xFF,0xB1,
    0x71,0xC3,0xFF,0xFF,0xF4,0x03,0x70,0xFF,0xFF,0xEF,0x0D,0x00,0x00,0xD8,0xFF,0xFF,
    0xC0,0x00,0x00,0x12,0xFA,0xFF,0xFF,0x1C,0x70,0xFF,0xFF,0xAD,0x00,0x00,0x00,0xAB,
    0xFF,0xFF,0x73,0x00,0x00,0x00,0xDF,0xFF,0xFF,0x24,0x70,0xFF,0xFF,0x94,0x00,0x00,
    0x00,0xA4,0xFF,0xFF,0x5C,0x00,0x00,0x00,0xD8,0xFF,0xFF,0x24,0x70,0xFF,0xFF,0x8C,
    0x00,0x00,0x00,0xA4,0xFF,0xFF,0x58,0x00,0x00,0x00,0xD8,0xFF,0xFF,0x24,0x70,0xFF,
    0xFF,0x8C,0x00,0x00,0x00,0xA4,0xFF,0xFF,0x58,0x00,0x00,0x00,0xD8,0xFF,0xFF,0x24,
    0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0xA4,0xFF,0xFF,0x58,0x00,0x00,0x00,0xD8,0xFF,
    0xFF,0x24,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0xA4,0xFF,0xFF,0x58,0x00,0x00,0x00,
    0xD8,0xFF,0xFF,0x24,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0xA4,0xFF,0xFF,0x58,0x00,
    0x00,0x00,0xD8,0xFF,0xFF,0x24,0x00,0x00,0x70,0xFF,0xF3,0x04,0x67,0xCF,0xF7,0xE4,
    0xA6,0x21,0x00,0x70,0xFF,0xFF,0xB1,0xFF,0xFF,0xFF,0xFF,0xFF,0xEB,0x16,0x70,0xFF,
    0xFF,0xFF,0xD4,0x79,0x87,0xF8,0xFF,0xFF,0x74,0x70,0xFF,0xFF,0xF2,0x11,0x00,0x00,
    0x8C,0xFF,0xFF,0x9B,0x70,0xFF,0xFF,0xAF,0x00,0x00,0x00,0x5E,0xFF,0xFF,0xA4,0x70,
    0xFF,0xFF,0x94,0x00,0x00,0x00,0x58,0xFF,0xFF,0xA4,0x70,0xFF,0xFF,0x8C,0x00,0x00,
    0x00,0x58,0xFF,0xFF,0xA4,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x58,0xFF,0xFF,0xA4,
    0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x58,0xFF,0xFF,0xA4,0x70,0xFF,0xFF,0x8C,0x00,
    0x00,0x00,0x58,0xFF,0xFF,0xA4,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x58,0xFF,0xFF,
    0xA4,0x00,0x00,0x00,0x00,0x00,0x02,0x66,0xC5,0xF1,0xF6,0xD7,0x86,0x10,0x00,0x00,
    0x00,0x03,0xB1,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0x1D,0x00,0x00,0x6F,0xFF,0xFF,
    0xF4,0x88,0x75,0xCE,0xFF,0xFF,0xBE,0x00,0x00,0xD3,0xFF,0xFF,0x58,0x00,0x00,0x0B,
    0xED,0xFF,0xFF,0x2B,0x06,0xFE,0xFF,0xFF,0x09,0x00,0x00,0x00,0xA9,0xFF,0xFF,0x60,
    0x12,0xFF,0xFF,0xF6,0x00,0x00,0x00,0x00,0x96,0xFF,0xFF,0x76,0x02,0xFB,0xFF,0xFF,
    0x0A,0x00,0x00,0x00,0xAA,0xFF,0xFF,0x67,0x00,0xC8,0xFF,0xFF,0x58,0x00,0x00,0x0B,
    0xED,0xFF,0xFF,0x33,0x00,0x5D,0xFF,0xFF,0xF4,0x87,0x74,0xCE,0xFF,0xFF,0xCB,0x00,
    0x00,0x00,0x9B,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE6,0x27,0x00,0x00,0x00,0x00,0x57,
    0xBE,0xED,0xF8,0xDB,0x8F,0x17,0x00,0x00,0x70,0xFF,0xFF,0x1D,0x54,0xD1,0xF8,0xE2,
    0x84,0x06,0x00,0x70,0xFF,0xFF,0xB3,0xFF,0xFF,0xFF,0xFF,0xFF,0xAA,0x00,0x70,0xFF,
    0xFF,0xFF,0xBC,0x71,0xA1,0xFF,0xFF,0xFF,0x3E,0x70,0xFF,0xFF,0xDB,0x02,0x00,0x00,
    0xAA,0xFF,0xFF,0x8D,0x70,0xFF,0xFF,0x9D,0x00,0x00,0x00,0x60,0xFF,0xFF,0xB4,0x70,
    0xFF,0xFF,0x8F,0x00,0x00,0x00,0x4E,0xFF,0xFF,0xC0,0x70,0xFF,0xFF,0xA3,0x00,0x00,
    0x00,0x62,0xFF,0xFF,0xB3,0x70,0xFF,0xFF,0xE5,0x06,0x00,0x00,0xAE,0xFF,0xFF,0x8A,
    0x70,0xFF,0xFF,0xFF,0xC4,0x72,0xA1,0xFF,0xFF,0xFF,0x38,0x70,0xFF,0xFF,0xDA,0xFF,
    0xFF,0xFF,0xFF,0xFF,0x9F,0x00,0x70,0xFF,0xFF,0x76,0x67,0xDC,0xF9,0xDF,0x7C,0x03,
    0x00,0x70,0xFF,0xFF,0x8A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x8C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,
    0x8C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0xFF,0xEE,0x02,0x4E,0xCB,0xF9,0x99,
    0x70,0xFF,0xFF,0x93,0xFF,0xFF,0xFF,0x86,0x70,0xFF,0xFF,0xFF,0xEF,0x8E,0x69,0x36,
    0x70,0xFF,0xFF,0xF2,0x23,0x00,0x00,0x00,0x70,0xFF,0xFF,0xA5,0x00,0x00,0x00,0x00,
    0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,
    0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,
    0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,0x70,0xFF,0xFF,0x8C,0x00,0x00,0x00,0x00,
    0x00,0x07,0x71,0xCB,0xED,0xF6,0xDA,0xAB,0x4D,0x00,0x00,0xAF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xD7,0x00,0x0D,0xFF,0xFF,0xFA,0x7E,0x72,0x9E,0xED,0x70,0x00,0x08,0xFC,
    0xFF,0xF6,0x2D,0x00,0x00,0x07,0x08,0x00,0x00,0x9B,0xFF,0xFF,0xFD,0xB5,0x4D,0x02,
    0x00,0x00,0x00,0x02,0x72,0xE9,0xFF,0xFF,0xFF,0xD1,0x2C,0x00,0x00,0x00,0x00,0x07,
    0x5C,0xD2,0xFF,0xFF,0xE0,0x04,0x04,0x0F,0x00,0x00,0x00,0x04,0xDE,0xFF,0xFF,0x26,
    0x14,0xFA,0xB9,0x88,0x6B,0x85,0xFA,0xFF,0xFE,0x15,0x14,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xA1,0x00,0x06,0x81,0xCF,0xF4,0xFD,0xF2,0xC8,0x6E,0x04,0x00,0x00,0x00,
    0x00,0x00,0x11,0x80,0x6E,0x00,0x00,0x00,0x00,0x00,0x00,0x64,0xFF,0xDC,0x00,0x00,
    0x00,0x00,0x00,0x00,0xBC,0xFF,0xDC,0x00,0x00,0x00,0x00,0x0F,0x9C,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xEC,0x00,0x8A,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xEC,0x00,0x36,0x77,0xFF,
    0xFF,0xEA,0x64,0x64,0x5C,0x00,0x00,0x20,0xFF,0xFF,0xDC,0x00,0x00,0x00,0x00,0x00,
    0x20,0xFF,0xFF,0xDC,0x00,0x00,0x00,0x00,0x00,0x20,0xFF,0xFF,0xDC,0x00,0x00,0x00,
    0x00,0x00,0x20,0xFF,0xFF,0xDC,0x00,0x00,0x00,0x00,0x00,0x1C,0xFF,0xFF,0xE2,0x00,
    0x00,0x00,0x00,0x00,0x08,0xFC,0xFF,0xFF,0x8D,0x63,0x89,0x07,0x00,0x00,0xAF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0x0C,0x00,0x00,0x12,0xA0,0xEB,0xFA,0xE6,0xAE,0x06,0x00,0x00,
    0xCE,0xFF,0xFF,0x6D,0x00,0x00,0x00,0x07,0xF2,0xFF,0xFF,0x30,0x6A,0xFF,0xFF,0xC0,
    0x00,0x00,0x00,0x4C,0xFF,0xFF,0xD2,0x00,0x0F,0xF6,0xFF,0xFD,0x16,0x00,0x00,0x9F,
    0xFF,0xFF,0x74,0x00,0x00,0xA2,0xFF,0xFF,0x66,0x00,0x04,0xED,0xFF,0xFC,0x19,0x00,
    0x00,0x3E,0xFF,0xFF,0xBA,0x00,0x44,0xFF,0xFF,0xB8,0x00,0x00,0x00,0x00,0xD9,0xFF,
    0xFB,0x12,0x96,0xFF,0xFF,0x5A,0x00,0x00,0x00,0x00,0x76,0xFF,0xFF,0x5D,0xE5,0xFF,
    0xF2,0x09,0x00,0x00,0x00,0x00,0x17,0xFA,0xFF,0xBC,0xFF,0xFF,0x9E,0x00,0x00,0x00,
    0x00,0x00,0x00,0xAE,0xFF,0xFA,0xFF,0xFF,0x40,0x00,0x00,0x00,0x00,0x00,0x00,0x4A,
    0xFF,0xFF,0xFF,0xE0,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xE2,0xFF,0xFF,0x84,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCD,0xFF,0xFF,0x26,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x46,0xFF,0xFF,0xC4,0x00,0x00,0x00,0x00,0x00,0x23,0x61,0x7E,0xF0,
    0xFF,0xFF,0x46,0x00,0x00,0x00,0x00,0x00,0x50,0xFF,0xFF,0xFF,0xFF,0x8E,0x00,0x00,
    0x00,0x00,0x00,0x00,0x47,0xF8,0xF4,0xCA,0x5C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

leRasterFont NotoSans_Bold =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)NotoSans_Bold_glyphs, // glyph table variable pointer
            4112, // data size
        },
        LE_RASTER_FONT,
    },
    21,
    15,
    LE_FONT_BPP_8, // bits per pixel
    NotoSans_Bold_data, // kerning table
};
