/* twitter bitmap file for GLCD library */
/* Bitmap created from twitter.png      */
/* Date: 30 Aug 2014      */
/* Image Pixels = 960    */
/* Image Bytes  = 120     */

#include <inttypes.h>
#include <avr/pgmspace.h>

#ifndef twitter_H
#define twitter_H

static uint8_t twitter[] PROGMEM = {
  40, // width
  24, // height

  /* page 0 (lines 0-7) */
  0x0,0x0,0x7c,0xfc,0xfc,0xf8,0xf0,0xf0,0xe0,0xe0,0xc0,0xc0,0xc0,0x80,0x80,0x80,
  0x80,0x80,0x80,0x80,0xf8,0xfc,0xfe,0xfe,0xfe,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,
  0xfe,0xfc,0xfc,0xfc,0x3e,0x1a,0x8,0x0,
  /* page 1 (lines 8-15) */
  0x0,0x0,0x6,0xe,0x1f,0xbf,0xbf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
  0xff,0x3f,0x1f,0x3,0x0,0x0,0x0,0x0,
  /* page 2 (lines 16-23) */
  0x0,0x0,0x20,0x60,0x60,0x60,0x61,0xe3,0xf3,0xf3,0xf7,0xff,0xff,0xff,0xff,0xff,
  0xff,0xff,0x7f,0x7f,0x7f,0x7f,0x3f,0x3f,0x3f,0x1f,0x1f,0xf,0x7,0x7,0x3,0x1,
  0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
};
#endif
