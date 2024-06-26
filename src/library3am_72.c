/*******************************************************************************
 * Size: 72 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include <lvgl.h>
#endif

#ifndef LIBRARY3AM_72
#define LIBRARY3AM_72 1
#endif

#if LIBRARY3AM_72

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0030 "0" */
    0x0, 0x0, 0x7f, 0x80, 0x0, 0x0, 0x1, 0xff,
    0xfc, 0x0, 0x0, 0x1, 0xff, 0xff, 0xc0, 0x0,
    0x0, 0xfe, 0x1, 0xfc, 0x0, 0x0, 0x7c, 0x0,
    0xf, 0x80, 0x0, 0x3c, 0x0, 0x0, 0xf0, 0x0,
    0x1e, 0x0, 0x0, 0x1e, 0x0, 0xf, 0x0, 0xfe,
    0x3, 0xc0, 0x7, 0x80, 0xff, 0xe0, 0x78, 0x1,
    0xc0, 0xff, 0xfe, 0xe, 0x0, 0xf0, 0x7e, 0xf,
    0xc1, 0xc0, 0x78, 0x1e, 0x0, 0xf8, 0x70, 0x1c,
    0xf, 0x0, 0x1e, 0xe, 0x7, 0x7, 0x80, 0x3,
    0xc3, 0x83, 0x81, 0xc0, 0x0, 0x70, 0x70, 0xe0,
    0xf0, 0x0, 0x1e, 0x1c, 0x38, 0x38, 0x0, 0x3,
    0x87, 0x1c, 0xe, 0x0, 0x0, 0xf0, 0xe7, 0x7,
    0x0, 0x0, 0x1c, 0x39, 0xc1, 0xc0, 0x0, 0x7,
    0xe, 0x70, 0x70, 0x0, 0x1, 0xc3, 0xbc, 0x1c,
    0x0, 0x0, 0x78, 0x6e, 0xe, 0x0, 0x0, 0xe,
    0x1f, 0x83, 0x80, 0x0, 0x0, 0x7, 0xe0, 0xe0,
    0x0, 0x0, 0x1, 0xf8, 0x38, 0x0, 0x0, 0x0,
    0x7e, 0xe, 0x0, 0x0, 0x0, 0x1f, 0x83, 0x80,
    0x0, 0x3, 0xff, 0xe0, 0xe0, 0x0, 0x0, 0xff,
    0xf8, 0x38, 0x0, 0x0, 0x3f, 0xfe, 0xe, 0x0,
    0x0, 0xe, 0x3, 0x83, 0x80, 0x0, 0x3, 0x80,
    0xe0, 0xe0, 0x0, 0x0, 0xe0, 0x38, 0x38, 0x0,
    0x0, 0x38, 0xf, 0x7, 0x0, 0x0, 0x1e, 0x1d,
    0xc1, 0xc0, 0x0, 0x7, 0x86, 0x70, 0x70, 0x0,
    0x1, 0xc3, 0x9c, 0x1c, 0x0, 0x0, 0x70, 0xe7,
    0x3, 0x80, 0x0, 0x3c, 0x38, 0xe0, 0xe0, 0x0,
    0xf, 0xe, 0x38, 0x3c, 0x0, 0x3, 0x87, 0xe,
    0x7, 0x0, 0x1, 0xe1, 0xc1, 0xc1, 0xe0, 0x0,
    0xf0, 0xf0, 0x70, 0x3c, 0x0, 0x7c, 0x38, 0x1e,
    0x7, 0x80, 0x3e, 0x1e, 0x3, 0x81, 0xf8, 0x3f,
    0x7, 0x0, 0x70, 0x3f, 0xff, 0x83, 0xc0, 0x1e,
    0x3, 0xff, 0xc1, 0xe0, 0x3, 0xc0, 0x3f, 0x80,
    0xf0, 0x0, 0x78, 0x0, 0x0, 0x78, 0x0, 0xf,
    0x0, 0x0, 0x3e, 0x0, 0x1, 0xf0, 0x0, 0x3e,
    0x0, 0x0, 0x3f, 0x80, 0x7f, 0x0, 0x0, 0x7,
    0xff, 0xff, 0x80, 0x0, 0x0, 0x7f, 0xff, 0x80,
    0x0, 0x0, 0x1, 0xff, 0x0, 0x0,

    /* U+0031 "1" */
    0x0, 0x0, 0x8, 0x0, 0x1, 0xc0, 0x0, 0x3e,
    0x0, 0xf, 0xf0, 0x1, 0xfe, 0x0, 0x3f, 0x80,
    0x7, 0xf0, 0x0, 0xfe, 0x0, 0x3f, 0xc0, 0x1f,
    0xf0, 0x3, 0xfe, 0x0, 0x7f, 0xc0, 0xf, 0xfe,
    0x3, 0xff, 0xf0, 0x7f, 0x9f, 0x8f, 0xe0, 0xfd,
    0xfc, 0x7, 0xff, 0x80, 0x3f, 0xf0, 0x1, 0xfe,
    0x0, 0xf, 0x80, 0x8, 0x70, 0x1, 0xc3, 0x80,
    0xe, 0x1c, 0x0, 0x70, 0xe0, 0x3, 0x87, 0x0,
    0x1c, 0x38, 0x0, 0xe1, 0xc0, 0x7, 0xe, 0x0,
    0x38, 0x70, 0x1, 0xc3, 0x80, 0xe, 0x1c, 0x0,
    0x70, 0xe0, 0x3, 0x87, 0x0, 0x1c, 0x38, 0x0,
    0xe1, 0xc0, 0x7, 0xe, 0x0, 0x38, 0x70, 0x1,
    0xc3, 0x80, 0xe, 0x1c, 0x0, 0x70, 0xe0, 0x3,
    0x87, 0x0, 0x1c, 0x38, 0x0, 0xe1, 0xc0, 0x7,
    0xe, 0x0, 0x38, 0x70, 0x1, 0xc3, 0x80, 0xe,
    0x1c, 0x0, 0x70, 0xe0, 0x3, 0x87, 0x0, 0x1c,
    0x38, 0x0, 0xe1, 0xc0, 0x7, 0xe, 0x0, 0x38,
    0x70, 0x1, 0xff, 0x80, 0xf, 0xfc, 0x0, 0x7f,
    0xe0,

    /* U+0032 "2" */
    0x0, 0xf, 0xf8, 0x0, 0x0, 0x1f, 0xff, 0xe0,
    0x0, 0xf, 0xff, 0xff, 0x0, 0x3, 0xf8, 0x7,
    0xf0, 0x1, 0xf8, 0x0, 0x1f, 0x80, 0x7c, 0x0,
    0x0, 0xf8, 0x1f, 0x0, 0x0, 0xf, 0x3, 0xc0,
    0x7f, 0x80, 0xf0, 0x7c, 0x3f, 0xfc, 0xf, 0x7,
    0xcf, 0xff, 0xc0, 0xe0, 0x3f, 0xe0, 0x7c, 0xe,
    0x3, 0xf0, 0x3, 0xc1, 0xc0, 0x3c, 0x0, 0x38,
    0x38, 0x3, 0x0, 0x7, 0x3, 0x80, 0x0, 0x0,
    0x70, 0x70, 0x0, 0x0, 0xe, 0xe, 0x0, 0x0,
    0x1, 0xc1, 0xc0, 0x0, 0x0, 0x38, 0x38, 0x0,
    0x0, 0x7, 0x7, 0x0, 0x0, 0x0, 0xe0, 0xe0,
    0x0, 0x0, 0x38, 0x1c, 0x0, 0x0, 0x7, 0x7,
    0x0, 0x0, 0x1, 0xe0, 0xe0, 0x0, 0x0, 0x78,
    0x3c, 0x0, 0x0, 0xe, 0x7, 0x0, 0x0, 0x3,
    0xc1, 0xe0, 0x0, 0x0, 0xf0, 0x38, 0x0, 0x0,
    0x3c, 0xf, 0x0, 0x0, 0xf, 0x3, 0xc0, 0x0,
    0x3, 0xc0, 0x70, 0x0, 0x0, 0xf0, 0x1e, 0x0,
    0x0, 0x3c, 0x7, 0x80, 0x0, 0xf, 0x1, 0xe0,
    0x0, 0x3, 0xc0, 0x78, 0x0, 0x0, 0xf0, 0x1e,
    0x0, 0x0, 0x3c, 0x7, 0x80, 0x0, 0xf, 0x81,
    0xe0, 0x0, 0x3, 0xe0, 0x78, 0x0, 0x0, 0x78,
    0x1e, 0x0, 0x0, 0x1e, 0x7, 0x80, 0x0, 0x7,
    0x81, 0xe0, 0x0, 0x1, 0xe0, 0x78, 0x0, 0x0,
    0x78, 0x1e, 0x0, 0x0, 0x1e, 0x7, 0x80, 0x0,
    0x7, 0x81, 0xe0, 0x0, 0x0, 0xe0, 0x78, 0xf,
    0xff, 0xd8, 0x1e, 0x3, 0xff, 0xfa, 0x7, 0xc0,
    0xff, 0xff, 0x1, 0xf0, 0x0, 0x0, 0xe0, 0x7c,
    0x0, 0x0, 0x1c, 0x1f, 0x0, 0x0, 0x3, 0x87,
    0xc0, 0x0, 0x0, 0x71, 0xff, 0xff, 0xff, 0xfe,
    0x7f, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff,
    0xf8,

    /* U+0033 "3" */
    0xf, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff,
    0xff, 0xe0, 0x3f, 0xff, 0xff, 0xff, 0xc0, 0x70,
    0x0, 0x0, 0x3, 0x80, 0xe0, 0x0, 0x0, 0x7,
    0x1, 0xc0, 0x0, 0x0, 0xe, 0x3, 0x80, 0x0,
    0x0, 0x1c, 0x7, 0xff, 0xff, 0xf0, 0x38, 0xf,
    0xff, 0xff, 0xe0, 0xf0, 0x1f, 0xff, 0xff, 0x83,
    0xc0, 0x0, 0x0, 0x1e, 0xf, 0x0, 0x0, 0x0,
    0x38, 0x1c, 0x0, 0x0, 0x0, 0xf0, 0x78, 0x0,
    0x0, 0x3, 0xc1, 0xe0, 0x0, 0x0, 0xf, 0x3,
    0x80, 0x0, 0x0, 0x1c, 0xf, 0x0, 0x0, 0x0,
    0x78, 0x3c, 0x0, 0x0, 0x1, 0xe0, 0xf0, 0x0,
    0x0, 0x7, 0x81, 0xc0, 0x0, 0x0, 0xf, 0x7,
    0x80, 0x0, 0x0, 0x3c, 0x1e, 0x0, 0x0, 0x0,
    0xf0, 0x78, 0x0, 0x0, 0x1, 0xc0, 0xf0, 0x0,
    0x0, 0x3, 0x83, 0xc1, 0x0, 0x0, 0x6, 0xf,
    0x3, 0x80, 0x0, 0x0, 0x1c, 0xf, 0x80, 0x0,
    0x0, 0x78, 0xf, 0x80, 0x0, 0x1, 0xf8, 0x7,
    0x80, 0x0, 0x7, 0xfc, 0x7, 0x0, 0x0, 0x7,
    0xfc, 0xf, 0x0, 0x0, 0x0, 0x7c, 0xe, 0x0,
    0x0, 0x0, 0x3c, 0xe, 0x0, 0x0, 0x0, 0x3c,
    0x1c, 0x0, 0x0, 0x0, 0x38, 0x3c, 0x0, 0x0,
    0x0, 0x78, 0x38, 0x0, 0x0, 0x0, 0x70, 0x70,
    0x0, 0x0, 0x0, 0xe0, 0xe0, 0x0, 0x0, 0x1,
    0xc1, 0xc0, 0x0, 0x0, 0x3, 0x83, 0x80, 0x0,
    0x0, 0x7, 0x7, 0x0, 0x0, 0x0, 0x1e, 0xe,
    0x18, 0x0, 0x0, 0x38, 0x3c, 0x7c, 0x0, 0x0,
    0xf0, 0x70, 0xff, 0x0, 0x3, 0xc0, 0xe3, 0xff,
    0xc0, 0x3f, 0x3, 0xc7, 0x1f, 0xff, 0xfc, 0x7,
    0x1e, 0xf, 0xff, 0xe0, 0x1e, 0x38, 0x1, 0xff,
    0x0, 0x78, 0xf0, 0x0, 0x0, 0x1, 0xe1, 0xf8,
    0x0, 0x0, 0xf, 0x81, 0xfe, 0x0, 0x0, 0x7e,
    0x0, 0xff, 0xc0, 0x7, 0xf8, 0x0, 0x7f, 0xff,
    0xff, 0xc0, 0x0, 0x1f, 0xff, 0xfe, 0x0, 0x0,
    0x1, 0xff, 0xe0, 0x0, 0x0,

    /* U+0034 "4" */
    0x0, 0x0, 0x1f, 0xfe, 0x0, 0x0, 0x0, 0xf,
    0xff, 0x0, 0x0, 0x0, 0xf, 0xff, 0x0, 0x0,
    0x0, 0x7, 0x7, 0x80, 0x0, 0x0, 0x7, 0x87,
    0x80, 0x0, 0x0, 0x3, 0x83, 0xc0, 0x0, 0x0,
    0x3, 0xc3, 0xc0, 0x0, 0x0, 0x1, 0xc1, 0xe0,
    0x0, 0x0, 0x1, 0xe1, 0xe0, 0x0, 0x0, 0x0,
    0xe0, 0xf0, 0x0, 0x0, 0x0, 0xe0, 0xf0, 0x0,
    0x0, 0x0, 0x70, 0x78, 0x0, 0x0, 0x0, 0x70,
    0x78, 0x0, 0x0, 0x0, 0x38, 0x3c, 0x0, 0x0,
    0x0, 0x38, 0x3c, 0x0, 0x0, 0x0, 0x3c, 0x1e,
    0x0, 0x0, 0x0, 0x1c, 0x1e, 0x0, 0x0, 0x0,
    0x1e, 0xe, 0x0, 0x0, 0x0, 0xe, 0xf, 0x0,
    0x0, 0x0, 0xf, 0x7, 0x0, 0x0, 0x0, 0x7,
    0x7, 0x80, 0x0, 0x0, 0x7, 0x83, 0x80, 0x0,
    0x0, 0x3, 0x83, 0xc0, 0x0, 0x0, 0x3, 0xc1,
    0xc0, 0x0, 0x0, 0x1, 0xc1, 0xe0, 0x0, 0x0,
    0x1, 0xe0, 0xe0, 0x7f, 0xf0, 0x0, 0xe0, 0xf0,
    0x3f, 0xf8, 0x0, 0xf0, 0x70, 0x1f, 0xfc, 0x0,
    0x70, 0x78, 0xe, 0xe, 0x0, 0x78, 0x38, 0x7,
    0x7, 0x0, 0x38, 0x3c, 0x3, 0x83, 0x80, 0x3c,
    0x1c, 0x1, 0xc1, 0xc0, 0x1c, 0x1e, 0x0, 0xe0,
    0xe0, 0x1e, 0x1e, 0x0, 0x70, 0x70, 0xe, 0xf,
    0x0, 0x38, 0x38, 0xf, 0xf, 0x7, 0xfc, 0x1f,
    0xf7, 0x7, 0x7, 0xfe, 0xf, 0xff, 0x87, 0x83,
    0xff, 0x7, 0xfc, 0x3, 0x80, 0x0, 0x0, 0xe,
    0x3, 0xc0, 0x0, 0x0, 0x7, 0x1, 0xc0, 0x0,
    0x0, 0x3, 0x81, 0xe0, 0x0, 0x0, 0x1, 0xc0,
    0xff, 0xff, 0xf8, 0x3f, 0xe0, 0xff, 0xff, 0xfc,
    0x1f, 0xf0, 0x7f, 0xff, 0xfe, 0xf, 0xf8, 0x0,
    0x0, 0x7, 0x7, 0x0, 0x0, 0x0, 0x3, 0x83,
    0x80, 0x0, 0x0, 0x1, 0xc1, 0xc0, 0x0, 0x0,
    0x0, 0xe0, 0xe0, 0x0, 0x0, 0x0, 0x70, 0x70,
    0x0, 0x0, 0x0, 0x38, 0x38, 0x0, 0x0, 0x0,
    0x1f, 0xfc, 0x0, 0x0, 0x0, 0xf, 0xfe, 0x0,
    0x0, 0x0, 0x7, 0xff, 0x0,

    /* U+0035 "5" */
    0x1, 0xff, 0xff, 0xff, 0xf0, 0x3, 0xff, 0xff,
    0xff, 0xe0, 0x7, 0xff, 0xff, 0xff, 0xc0, 0xe,
    0x0, 0x0, 0x3, 0x80, 0x1c, 0x0, 0x0, 0x7,
    0x0, 0x38, 0x0, 0x0, 0xe, 0x0, 0x70, 0x0,
    0x0, 0x1c, 0x1, 0xe1, 0xff, 0xff, 0xf8, 0x3,
    0x83, 0xff, 0xff, 0xf0, 0x7, 0x7, 0xff, 0xff,
    0xe0, 0xe, 0xe, 0x0, 0x0, 0x0, 0x1c, 0x1c,
    0x0, 0x0, 0x0, 0x38, 0x70, 0x0, 0x0, 0x0,
    0x70, 0xe0, 0x0, 0x0, 0x0, 0xe1, 0xc0, 0x0,
    0x0, 0x1, 0xc3, 0x80, 0x0, 0x0, 0x3, 0x87,
    0x0, 0x0, 0x0, 0xe, 0xe, 0x0, 0x0, 0x0,
    0x1c, 0x1c, 0x0, 0x0, 0x0, 0x38, 0x38, 0x7c,
    0x0, 0x0, 0x70, 0x70, 0xff, 0x0, 0x0, 0xe1,
    0xc1, 0xff, 0x80, 0x1, 0xc3, 0x80, 0x1f, 0xc0,
    0x3, 0x87, 0x0, 0x7, 0xc0, 0x7, 0xe, 0x0,
    0x3, 0xc0, 0xe, 0x1c, 0x0, 0x3, 0xc0, 0x18,
    0x3f, 0xf8, 0x3, 0xc0, 0x10, 0x7f, 0xfe, 0x3,
    0xc0, 0x0, 0xff, 0xfe, 0x3, 0x80, 0x1, 0xc0,
    0x3e, 0x7, 0x80, 0x6, 0x0, 0x1e, 0x7, 0x0,
    0x0, 0x0, 0x1e, 0xe, 0x0, 0x0, 0x0, 0x1c,
    0x1e, 0x0, 0x0, 0x0, 0x3c, 0x1c, 0x0, 0x0,
    0x0, 0x38, 0x38, 0x0, 0x0, 0x0, 0x70, 0x70,
    0x0, 0x0, 0x0, 0xe0, 0xe0, 0x0, 0x0, 0x1,
    0xc1, 0xc0, 0x0, 0x0, 0x3, 0x83, 0x80, 0x0,
    0x0, 0x7, 0x7, 0x4, 0x0, 0x0, 0x1c, 0xe,
    0xc, 0x0, 0x0, 0x38, 0x38, 0x3e, 0x0, 0x0,
    0xe0, 0x70, 0x7f, 0x80, 0x3, 0xc0, 0xe1, 0xff,
    0xe0, 0x3f, 0x3, 0x83, 0x9f, 0xff, 0xfc, 0xf,
    0xf, 0x7, 0xff, 0xe0, 0x1c, 0x1c, 0x1, 0xff,
    0x0, 0x78, 0x78, 0x0, 0x0, 0x3, 0xe0, 0xfc,
    0x0, 0x0, 0xf, 0x80, 0xfe, 0x0, 0x0, 0x7e,
    0x0, 0x7f, 0xe0, 0x7, 0xf0, 0x0, 0x3f, 0xff,
    0xff, 0xc0, 0x0, 0xf, 0xff, 0xfe, 0x0, 0x0,
    0x1, 0xff, 0xc0, 0x0, 0x0,

    /* U+0036 "6" */
    0x0, 0x0, 0xf, 0xff, 0x0, 0x0, 0x0, 0x3f,
    0xfc, 0x0, 0x0, 0x1, 0xff, 0xe0, 0x0, 0x0,
    0xf, 0x7, 0x0, 0x0, 0x0, 0x38, 0x3c, 0x0,
    0x0, 0x1, 0xe0, 0xe0, 0x0, 0x0, 0xf, 0x7,
    0x80, 0x0, 0x0, 0x38, 0x3c, 0x0, 0x0, 0x1,
    0xe0, 0xe0, 0x0, 0x0, 0xf, 0x7, 0x80, 0x0,
    0x0, 0x38, 0x1c, 0x0, 0x0, 0x1, 0xe0, 0xe0,
    0x0, 0x0, 0xf, 0x7, 0x80, 0x0, 0x0, 0x38,
    0x1c, 0x0, 0x0, 0x1, 0xe0, 0xf0, 0x0, 0x0,
    0xf, 0x7, 0x80, 0x0, 0x0, 0x38, 0x1c, 0x0,
    0x0, 0x1, 0xe0, 0xf0, 0x0, 0x0, 0xf, 0x7,
    0x80, 0x0, 0x0, 0x38, 0x1c, 0x10, 0x0, 0x1,
    0xe0, 0xf0, 0x70, 0x0, 0x7, 0x3, 0x83, 0xf0,
    0x0, 0x38, 0x1c, 0x3, 0xe0, 0x1, 0xe0, 0xf0,
    0x3, 0xe0, 0x7, 0x3, 0x80, 0x7, 0xc0, 0x3c,
    0x1f, 0xe0, 0xf, 0x1, 0xe0, 0xff, 0xf8, 0x1e,
    0x7, 0x3, 0xff, 0xf0, 0x3c, 0x3c, 0x0, 0x7,
    0xf0, 0x70, 0xe0, 0x0, 0x3, 0xe1, 0xe7, 0x0,
    0x0, 0x7, 0x83, 0x9c, 0x0, 0x0, 0xf, 0xe,
    0xf0, 0x70, 0x0, 0x1c, 0x3f, 0x83, 0xc0, 0x0,
    0x78, 0x7e, 0xe, 0x0, 0x0, 0xe1, 0xf8, 0x38,
    0x0, 0x3, 0x87, 0xe0, 0xe0, 0x0, 0xe, 0x1f,
    0x83, 0x80, 0x0, 0x38, 0x7e, 0xe, 0x0, 0x0,
    0xe1, 0xf8, 0x38, 0x0, 0x3, 0x87, 0xe0, 0xf0,
    0x0, 0x1e, 0x1f, 0xc1, 0xc0, 0x0, 0x70, 0xe7,
    0x7, 0x80, 0x3, 0xc3, 0x9c, 0xf, 0x0, 0x1e,
    0xe, 0x78, 0x1f, 0x1, 0xf0, 0x78, 0xe0, 0x3f,
    0xff, 0x81, 0xc3, 0xc0, 0x7f, 0xfc, 0xf, 0x7,
    0x80, 0x3f, 0xc0, 0x78, 0xf, 0x0, 0x0, 0x3,
    0xc0, 0x1e, 0x0, 0x0, 0x1e, 0x0, 0x3e, 0x0,
    0x1, 0xf0, 0x0, 0x7f, 0x0, 0x3f, 0x80, 0x0,
    0x7f, 0xff, 0xfc, 0x0, 0x0, 0x7f, 0xff, 0xc0,
    0x0, 0x0, 0x3f, 0xf0, 0x0, 0x0,

    /* U+0037 "7" */
    0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0xff, 0xfc,
    0xf, 0xff, 0xff, 0xff, 0x3, 0x80, 0x0, 0x3,
    0x80, 0xe0, 0x0, 0x0, 0xe0, 0x38, 0x0, 0x0,
    0x78, 0xe, 0x0, 0x0, 0x1c, 0x3, 0xff, 0xff,
    0xf, 0xf, 0xff, 0xff, 0x83, 0x83, 0xbf, 0xff,
    0xe0, 0xe0, 0xe0, 0x0, 0x0, 0x78, 0x70, 0x0,
    0x0, 0x1c, 0x1c, 0x0, 0x0, 0xf, 0xf, 0x0,
    0x0, 0x3, 0x83, 0x80, 0x0, 0x0, 0xe0, 0xe0,
    0x0, 0x0, 0x70, 0x70, 0x0, 0x0, 0x1c, 0x1c,
    0x0, 0x0, 0xf, 0xf, 0x0, 0x0, 0x3, 0x83,
    0x80, 0x0, 0x0, 0xe1, 0xe0, 0x0, 0x0, 0x70,
    0x70, 0x0, 0x0, 0x1c, 0x1c, 0x0, 0x0, 0xf,
    0xf, 0x0, 0x0, 0x3, 0x83, 0x80, 0x0, 0x1,
    0xe1, 0xe0, 0x0, 0x0, 0x70, 0x70, 0x0, 0x0,
    0x1c, 0x1c, 0x0, 0x0, 0xe, 0xe, 0x0, 0x0,
    0x3, 0x83, 0x80, 0x0, 0x1, 0xe1, 0xe0, 0x0,
    0x0, 0x70, 0x70, 0x0, 0x0, 0x1c, 0x1c, 0x0,
    0x0, 0xe, 0xe, 0x0, 0x0, 0x3, 0x83, 0x80,
    0x0, 0x1, 0xe1, 0xe0, 0x0, 0x0, 0x70, 0x70,
    0x0, 0x0, 0x3c, 0x1c, 0x0, 0x0, 0xe, 0xe,
    0x0, 0x0, 0x3, 0x83, 0x80, 0x0, 0x1, 0xe1,
    0xe0, 0x0, 0x0, 0x70, 0x70, 0x0, 0x0, 0x3c,
    0x3c, 0x0, 0x0, 0xe, 0xe, 0x0, 0x0, 0x3,
    0x83, 0x80, 0x0, 0x1, 0xc1, 0xc0, 0x0, 0x0,
    0x70, 0x70, 0x0, 0x0, 0x3c, 0x3c, 0x0, 0x0,
    0xe, 0xe, 0x0, 0x0, 0x3, 0x83, 0x80, 0x0,
    0x1, 0xc1, 0xc0, 0x0, 0x0, 0x70, 0x70, 0x0,
    0x0, 0x3f, 0xfc, 0x0, 0x0, 0xf, 0xfe, 0x0,
    0x0, 0x7, 0xff, 0x80, 0x0, 0x0,

    /* U+0038 "8" */
    0x0, 0x3, 0xfe, 0x0, 0x0, 0x0, 0x7f, 0xff,
    0x80, 0x0, 0x7, 0xff, 0xff, 0x80, 0x0, 0x3f,
    0x80, 0x7f, 0x0, 0x1, 0xf0, 0x0, 0x3e, 0x0,
    0xf, 0x0, 0x0, 0x3c, 0x0, 0x78, 0x0, 0x0,
    0x78, 0x3, 0xc0, 0x7f, 0x0, 0xf0, 0xe, 0x7,
    0xff, 0x1, 0xc0, 0x70, 0x7f, 0xff, 0x7, 0x81,
    0xc1, 0xe0, 0x7c, 0xe, 0x7, 0xf, 0x0, 0x78,
    0x38, 0x38, 0x38, 0x0, 0xe0, 0x70, 0xe1, 0xc0,
    0x1, 0xc1, 0xc3, 0x87, 0x0, 0x7, 0x7, 0xe,
    0x1c, 0x0, 0x1c, 0x1c, 0x38, 0x70, 0x0, 0x70,
    0x70, 0xe1, 0xc0, 0x1, 0xc1, 0xc3, 0x87, 0x0,
    0xf, 0x7, 0xe, 0x1e, 0x0, 0x38, 0x3c, 0x1c,
    0x38, 0x1, 0xe0, 0xe0, 0x70, 0xf0, 0xf, 0x0,
    0x81, 0xc1, 0xe0, 0x7e, 0x0, 0x7, 0x83, 0xc0,
    0x7e, 0x0, 0xe, 0xf, 0x80, 0x7c, 0x0, 0x1c,
    0x1f, 0x80, 0x7c, 0x0, 0x70, 0x1f, 0x0, 0xf8,
    0x1, 0xe0, 0x3f, 0x1, 0xf0, 0xe, 0x0, 0x3e,
    0x3, 0xc0, 0x70, 0x0, 0x7e, 0x7, 0x83, 0xc0,
    0x80, 0x7c, 0xf, 0xe, 0x7, 0x0, 0xf8, 0x1c,
    0x70, 0x3e, 0x1, 0xf0, 0x79, 0xc0, 0xe0, 0x1,
    0xc0, 0xe7, 0x7, 0x80, 0x7, 0x83, 0xb8, 0x1c,
    0x0, 0xe, 0x7, 0xe0, 0xe0, 0x0, 0x3c, 0x1f,
    0x83, 0x80, 0x0, 0x70, 0x7e, 0xe, 0x0, 0x1,
    0xc1, 0xf8, 0x38, 0x0, 0x7, 0x7, 0xe0, 0xe0,
    0x0, 0x1c, 0x1f, 0x83, 0x80, 0x0, 0x70, 0x7e,
    0xf, 0x0, 0x3, 0xc1, 0xfc, 0x1c, 0x0, 0xe,
    0xf, 0x70, 0x78, 0x0, 0x78, 0x39, 0xc0, 0xf8,
    0x7, 0xc0, 0xe3, 0x81, 0xff, 0xfe, 0x7, 0x8f,
    0x1, 0xff, 0xf0, 0x3c, 0x1e, 0x1, 0xfe, 0x0,
    0xe0, 0x7c, 0x0, 0x0, 0x7, 0x80, 0xf8, 0x0,
    0x0, 0x7c, 0x1, 0xf8, 0x0, 0x7, 0xe0, 0x1,
    0xfc, 0x0, 0xff, 0x0, 0x3, 0xff, 0xff, 0xf0,
    0x0, 0x3, 0xff, 0xff, 0x0, 0x0, 0x0, 0xff,
    0xe0, 0x0,

    /* U+0039 "9" */
    0x0, 0x3, 0xff, 0x0, 0x0, 0x0, 0xff, 0xff,
    0x80, 0x0, 0xf, 0xff, 0xff, 0x80, 0x0, 0x7f,
    0x0, 0x7f, 0x80, 0x3, 0xe0, 0x0, 0x1f, 0x0,
    0x1e, 0x0, 0x0, 0x1e, 0x0, 0xf0, 0x0, 0x0,
    0x3c, 0x7, 0x80, 0x3f, 0x80, 0x78, 0x3c, 0x7,
    0xff, 0xc0, 0xe0, 0xe0, 0x3f, 0xff, 0x81, 0xc7,
    0x81, 0xf0, 0x1f, 0x7, 0x1c, 0xf, 0x0, 0x1e,
    0xe, 0x70, 0x78, 0x0, 0x3c, 0x39, 0xc1, 0xc0,
    0x0, 0x70, 0xee, 0xf, 0x0, 0x1, 0xc1, 0xf8,
    0x38, 0x0, 0x3, 0x87, 0xe0, 0xe0, 0x0, 0xe,
    0x1f, 0x83, 0x80, 0x0, 0x38, 0x7e, 0xe, 0x0,
    0x0, 0xe1, 0xf8, 0x38, 0x0, 0x3, 0x87, 0xe0,
    0xe0, 0x0, 0xe, 0x1f, 0x83, 0xc0, 0x0, 0x78,
    0x7f, 0x7, 0x0, 0x1, 0xc3, 0xdc, 0x1e, 0x0,
    0x0, 0xe, 0x70, 0x3c, 0x0, 0x0, 0x39, 0xe0,
    0xf8, 0x0, 0x1, 0xc3, 0x81, 0xfc, 0x0, 0x7,
    0xf, 0x1, 0xff, 0xf8, 0x38, 0x1e, 0x3, 0xff,
    0xe1, 0xe0, 0x3c, 0x0, 0xff, 0x7, 0x0, 0x78,
    0x0, 0x38, 0x3c, 0x0, 0xf8, 0x1, 0xe1, 0xe0,
    0x1, 0xf8, 0xf, 0x7, 0x0, 0x3, 0xf8, 0x38,
    0x3c, 0x0, 0x3, 0xc1, 0xe0, 0xe0, 0x0, 0x1,
    0x7, 0x7, 0x80, 0x0, 0x0, 0x3c, 0x3c, 0x0,
    0x0, 0x1, 0xe0, 0xe0, 0x0, 0x0, 0x7, 0x7,
    0x80, 0x0, 0x0, 0x3c, 0x1c, 0x0, 0x0, 0x1,
    0xe0, 0xe0, 0x0, 0x0, 0x7, 0x7, 0x80, 0x0,
    0x0, 0x3c, 0x1c, 0x0, 0x0, 0x1, 0xe0, 0xf0,
    0x0, 0x0, 0x7, 0x7, 0x80, 0x0, 0x0, 0x3c,
    0x1c, 0x0, 0x0, 0x1, 0xe0, 0xf0, 0x0, 0x0,
    0x7, 0x83, 0x80, 0x0, 0x0, 0x3c, 0x1c, 0x0,
    0x0, 0x1, 0xe0, 0xf0, 0x0, 0x0, 0x7, 0x83,
    0x80, 0x0, 0x0, 0x3c, 0x1e, 0x0, 0x0, 0x1,
    0xff, 0xf0, 0x0, 0x0, 0x7, 0xff, 0x80, 0x0,
    0x0, 0x3f, 0xfe, 0x0, 0x0, 0x0,

    /* U+003A ":" */
    0xf, 0x3, 0xfc, 0x7f, 0xe7, 0xe, 0xe0, 0x7e,
    0x7, 0xe0, 0x7e, 0x7, 0x79, 0xe7, 0xe, 0x30,
    0xc0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0xf0, 0x3f, 0xc7, 0xfe, 0x70, 0xee,
    0x7, 0xe0, 0x7e, 0x7, 0xe0, 0x77, 0x9e, 0x70,
    0xe3, 0xc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 850, .box_w = 42, .box_h = 56, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 294, .adv_w = 568, .box_w = 21, .box_h = 55, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 439, .adv_w = 706, .box_w = 35, .box_h = 55, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 680, .adv_w = 761, .box_w = 39, .box_h = 55, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 949, .adv_w = 780, .box_w = 41, .box_h = 54, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1226, .adv_w = 753, .box_w = 39, .box_h = 55, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 1495, .adv_w = 786, .box_w = 38, .box_h = 55, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 1757, .adv_w = 643, .box_w = 34, .box_h = 54, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1987, .adv_w = 774, .box_w = 38, .box_h = 56, .ofs_x = 5, .ofs_y = -1},
    {.bitmap_index = 2253, .adv_w = 786, .box_w = 38, .box_h = 55, .ofs_x = 6, .ofs_y = 0},
    {.bitmap_index = 2515, .adv_w = 306, .box_w = 12, .box_h = 44, .ofs_x = 4, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 48, .range_length = 11, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    5, 3,
    8, 5,
    8, 7,
    8, 8,
    10, 5,
    10, 7
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    23, -29, -29, 46, -29, -29
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 6,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR >= 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR >= 8
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t library3am_72 = {
#else
lv_font_t library3am_72 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 56,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
    .fallback = NULL,
    .user_data = NULL
};



#endif /*#if LIBRARY3AM_72*/

