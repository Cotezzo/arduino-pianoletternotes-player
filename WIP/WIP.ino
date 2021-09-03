#include <Tone.h>                                                             // Used to output to multiple pins at the same time (max 3 for Arduino Uno)

const int notes[] = {                                                         // Notes pool - int frequency values (declared in Tone.h)
  NOTE_B0, NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2,
  NOTE_B2, NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4,
  NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5, NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6,
  NOTE_B6, NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7, NOTE_C8, NOTE_CS8, NOTE_D8, NOTE_DS8
};

/* ---- ACTUAL MELODY ----------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Sample song - format doesn't really matter, you can use decimal, binary, ecc... I prefer hex for readability since I'm working with bits
// Map: Values that tell the program when to play and when to pause, reading a bit when a note/pause finishes
// Notes: Compressed list of every note, regardless of the pauses
// Notes are 7-bits numbers representing actual note indexes (notes[]) compressed in 8-bit values but read sequentially with bit shifting

const byte PROGMEM hexMap_0[] = { 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x88,0x88,0x88,0x88,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0x88,0x88,0x88,0x88,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0x8a,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xa8,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x80,0x0f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xff,0xff,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xae,0xba,0xaa,0xaa,0xaa,0xba,0xaa,0xaf,0xff,0xff,0xff,0xbb,0xeb,0xae,0xff,0xfa,0xaa,0xff,0xff,0xfa,0xaa,0xff,0xff,0xff,0xff,0xfa,0xbf,0xff,0xff,0xff,0x8a,0x22,0xff,0xff,0x8a,0x22,0xff,0xff,0x88,0x92,0x49,0x2a,0xff,0xff,0xeb,0xae,0xbf,0xff,0xff,0xff,0xa8,0x94,0xff,0xff,0xfb,0xef,0xbf,0xff,0xff,0xff,0xff,0x8e,0xff,0xff,0xff,0x8f,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xff,0xff,0x80,0x00 };
const byte PROGMEM hexMap_1[] = { 0xa2,0x2a,0xa2,0x2a,0xa2,0x2a,0xa2,0x2a,0xa2,0x2a,0xa2,0x2a,0xa2,0x2a,0xa2,0x2a,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x88,0x88,0x88,0x88,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x00,0xaa,0xaa,0x80,0x00,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x8a,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x80,0x80,0x80,0x88,0x80,0x80,0x80,0xa8,0x80,0x80,0x80,0x88,0x80,0x80,0x80,0x88,0xa2,0x22,0x22,0x22,0xa2,0x22,0x22,0x22,0xa2,0x22,0x22,0x22,0xa2,0x22,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x8a,0xaa,0x8a,0xaa,0x8a,0xaa,0xaa,0xaa,0x80,0x00,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x8a,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x8a,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x80,0x00,0x00,0x00,0x80,0x00,0x00,0x00,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x24,0x92,0xaa,0xa2,0x28,0x92,0x82,0x0a,0xaa,0xaa,0xaa,0x91,0x49,0x24,0xaa,0xaa,0x2a,0xaa,0xaa,0xaa,0x2a,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x8a,0x22,0x80,0x00,0x8a,0x22,0x80,0x00,0x88,0x92,0x49,0x2a,0xaa,0xaa,0x49,0x24,0x88,0x92,0xaa,0xaa,0xa8,0x94,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x8a,0xaa,0xaa,0xaa,0x80,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x00,0x80,0x00,0x80,0x00,0x80,0x80,0x80,0x00,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x8a,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x8a,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0xaa,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x88,0x80,0x00 };

const byte PROGMEM hexNotes_0[] = { 0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8b,0x95,0xac,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xab,0x58,0xc1,0x9b,0x77,0x0e,0x9b,0xb8,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8b,0x95,0xac,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x40,0x91,0x3a,0xb5,0x8a,0xd3,0xa4,0x4e,0x9d,0x3b,0x16,0x6d,0xdd,0x3d,0x7e,0xe1,0x9b,0xf7,0x0c,0xdf,0xb8,0x66,0xf5,0xc3,0x37,0xae,0x1e,0xb8,0x78,0xcd,0x83,0xc6,0x6c,0x1e,0x33,0x60,0xdd,0x9b,0x06,0xec,0x1b,0xb0,0x74,0xd5,0x83,0xa6,0xac,0x1d,0x35,0x60,0xe1,0xab,0x07,0x0c,0x1c,0x30,0x6e,0xd5,0x83,0x76,0xac,0x1c,0x30,0x74,0xd5,0xe3,0x57,0xad,0x5f,0xb5,0x82,0xf5,0xc4,0x17,0xae,0x20,0xb8,0x86,0xe2,0x1b,0x88,0x8e,0x22,0x38,0x8c,0xea,0x33,0xa8,0x8e,0xa2,0x3a,0x86,0xea,0x1b,0xa8,0x2e,0xa0,0xba,0x82,0xe2,0x0b,0x87,0xee,0x1f,0xb8,0x7c,0xe1,0xf3,0x88,0x2e,0x20,0xb8,0x7e,0xe1,0xab,0xf7,0x0d,0x5f,0xb8,0x6a,0xf1,0xc3,0x57,0x8d,0x5e,0x35,0x7a,0xe1,0xeb,0x87,0xee,0x1f,0xb8,0x82,0xe2,0x0b,0x88,0x8e,0x22,0x38,0x87,0x12,0x1c,0x17,0x10,0x5c,0x3f,0x70,0xfd,0xc3,0xd7,0x0f,0x5c,0x3c,0x6e,0xf1,0xbc,0x06,0xf0,0x1b,0xc3,0x6f,0x0d,0xbc,0x87,0x92,0x1e,0x46,0x79,0x19,0xe4,0x47,0x91,0x1e,0x43,0x79,0x0d,0xe4,0x47,0x91,0x1e,0x48,0x82,0xf6,0x44,0x17,0xb2,0x20,0xbd,0x91,0x05,0xec,0x47,0x50,0x5d,0x48,0x82,0xf6,0x44,0x17,0x50,0x5d,0x48,0x82,0xf6,0x4c,0x17,0xb2,0x5e,0xc8,0x86,0xfe,0x44,0x37,0xf2,0x21,0xbf,0x8d,0x0d,0xfc,0x37,0xf1,0x9f,0xcb,0x97,0x26,0x4c,0x89,0x11,0xa3,0x27,0x56,0xb9,0x8b,0x36,0xee,0x9e,0xb3,0x40,0xcd,0x03,0x54,0x0c,0xd0,0x31,0x36,0xc0,0xda,0xe3,0x8a,0xce,0x30,0x3a,0xd4,0xeb,0x83,0xae,0x0e,0xba,0x30,0xe0,0xc3,0x73,0x0c,0xcc,0x35,0x32,0xdc,0xcb,0x83,0x2d,0x4c,0xb3,0x40,0xe9,0x03,0x84,0x0c,0xd0,0x31,0x32,0xcc,0xcb,0x54,0x4e,0x11,0x3c,0x36,0xe8,0xdb,0x83,0x6e,0x8d,0xb3,0x40,0xcd,0x03,0x54,0x0c,0xd0,0x31,0x36,0xc0,0xda,0xe3,0x8a,0xce,0x30,0x3a,0xd4,0xeb,0x83,0xae,0x0e,0xba,0x30,0xe0,0xc3,0x73,0x0c,0xcc,0x35,0x32,0xdc,0xcb,0x83,0x2d,0x4c,0xb3,0x40,0xe9,0x03,0x84,0x0c,0xd0,0x31,0x66,0xd5,0xbb,0x86,0x2d,0x5c,0x3a,0x66,0xdd,0xd3,0xf7,0xaf,0x1d,0x3f,0x70,0xcd,0xfb,0x86,0x6f,0xdc,0x33,0x7a,0xe1,0x9b,0xd7,0x0f,0x5c,0x3c,0x66,0xc1,0xe3,0x36,0x0f,0x19,0xb0,0x6e,0xcd,0x83,0x76,0x0d,0xd8,0x3a,0x6a,0xc1,0xd3,0x56,0x0e,0x9a,0xb0,0x70,0xd5,0x83,0x86,0x0e,0x18,0x37,0x6a,0xc1,0xbb,0x56,0x0e,0x18,0x3a,0x6a,0xf1,0xab,0xd6,0xaf,0xda,0xc1,0x7a,0xe2,0x0b,0xd7,0x10,0x5c,0x43,0x71,0x0d,0xc4,0x47,0x11,0x1c,0x46,0x75,0x19,0xd4,0x47,0x51,0x1d,0x43,0x75,0x0d,0xd4,0x17,0x50,0x5d,0x41,0x71,0x05,0xc3,0xf7,0x0f,0xdc,0x3e,0x70,0xf9,0xc4,0x17,0x10,0x5c,0x3f,0x70,0xd5,0xfb,0x86,0xaf,0xdc,0x35,0x78,0xe1,0xab,0xc6,0xaf,0x1a,0xbd,0x70,0xf5,0xc3,0xf7,0x0f,0xdc,0x41,0x71,0x05,0xc4,0x47,0x11,0x1c,0x43,0x88,0x6e,0x1c,0x17,0x10,0x5c,0x3f,0x70,0xfd,0xc3,0xd7,0x0f,0x5c,0x3c,0x6e,0xf1,0xbc,0x06,0xf0,0x1b,0xc3,0x6f,0x0d,0xbc,0x87,0x92,0x1e,0x46,0x79,0x19,0xe4,0x47,0x91,0x1e,0x43,0x79,0x0d,0xe4,0x47,0x91,0x1e,0x48,0x82,0xf6,0x44,0x17,0xb2,0x20,0xbd,0x91,0x05,0xec,0x47,0x50,0x5d,0x48,0x82,0xf6,0x44,0x17,0x50,0x5d,0x48,0x82,0xf6,0x4c,0x17,0xb2,0x5e,0xc8,0x86,0xfe,0x44,0x37,0xf2,0x21,0xbf,0x8d,0x0d,0xfc,0x37,0xf1,0x9f,0xcb,0x97,0x26,0x4c,0x89,0x11,0xa3,0x44,0x52,0xad,0x62,0xb5,0x8a,0x57,0x2c,0x5c,0xc5,0x83,0x16,0x0a,0xd6,0x2b,0x52,0xad,0x62,0xb5,0x8c,0x15,0xae,0x66,0xdd,0xc3,0x76,0x6c,0x14,0xa4,0x52,0xad,0x62,0xb5,0x8a,0x57,0x2c,0x5c,0xc5,0x83,0x16,0x0a,0xd6,0x2b,0x52,0xad,0x62,0xe6,0x0c,0x59,0xae,0x56,0xb9,0x61,0xf5,0x6a,0x4e,0xa9,0x56,0xb1,0x5a,0xc5,0x2b,0x96,0x2e,0x62,0xc1,0x8b,0x05,0x6b,0x15,0xa9,0x56,0xb1,0x5a,0xc6,0x0a,0xd7,0x33,0x6e,0xe1,0xbb,0x36,0x0a,0xd3,0x2b,0x5a,0xb9,0x6a,0xe5,0x6c,0x17,0x30,0x66,0xc9,0x9b,0x25,0xab,0x96,0xab,0x5a,0xb9,0x83,0x26,0x6d,0x4e,0x91,0x3a,0x44,0xe9,0x13,0xab,0x4e,0x91,0x3a,0x44,0xe9,0x13,0xac,0x0e,0x91,0x3a,0x44,0xe9,0x13,0xac,0xce,0x91,0x3a,0x44,0xe9,0x13,0xad,0x4e,0xb5,0x6a,0xd5,0xab,0x56,0xae,0x4e,0xb9,0x72,0xe5,0xcb,0x97,0x2f,0x0e,0xbc,0x78,0xf1,0xe3,0xc7,0x8f,0xdf,0xbf,0x7f,0x02,0x04,0x08,0x10,0x5a,0xb9,0x79,0x06,0x0b,0xa6,0xb0,0x5d,0x35,0x82,0xe9,0xab,0xf7,0x4d,0x5f,0xba,0x7e,0xe9,0xf3,0x56,0x4f,0x9a,0xb2,0x7c,0xd5,0x93,0x96,0xac,0x9c,0xb2,0x72,0xc9,0xe3,0x76,0x4f,0x1b,0xb2,0x78,0xdd,0x93,0xa6,0xec,0x9d,0x32,0x74,0xc9,0xcb,0x76,0x4e,0x5b,0xb2,0x74,0xc9,0xe3,0x77,0xcd,0xdf,0xb7,0x82,0xde,0x1b,0xf7,0x50,0xdf,0xba,0x86,0xea,0x2b,0xa8,0xae,0xa3,0x3a,0x8c,0xea,0x43,0xc9,0x0f,0x23,0x3c,0x8c,0xf2,0x2b,0xc8,0xaf,0x21,0xbc,0x86,0xf2,0x1b,0xa8,0x6e,0xa0,0xba,0x82,0xea,0x03,0xa8,0x0e,0xa1,0xba,0x86,0xea,0x0b,0xa6,0xf0,0x5d,0x37,0x82,0xe9,0xbb,0xe7,0x4d,0xdf,0x37,0x7c,0xdd,0xfb,0xa7,0xee,0xa0,0xba,0x82,0xea,0x1b,0xa8,0x6e,0xa3,0x3a,0x8c,0xea,0x2c,0x63,0xb1,0x61,0xba,0x86,0xea,0x0b,0xa8,0x2e,0x9f,0xba,0x7e,0xe9,0xf3,0x97,0xce,0x61,0x39,0x84,0xe6,0x2b,0x98,0xae,0x65,0x3e,0x94,0xfa,0x43,0xe9,0x0f,0xa3,0x3e,0x8c,0xfa,0x2b,0xe8,0xaf,0xa3,0x3e,0x8c,0xfa,0x54,0x37,0xf2,0xa1,0xbf,0x95,0x0d,0xfc,0xa8,0x6f,0xe3,0x3c,0x86,0xf2,0x54,0x37,0xf2,0xa1,0xbc,0x86,0xf2,0x54,0x37,0xf2,0xe1,0xbf,0x96,0xfe,0x54,0x58,0x32,0xa2,0xc1,0x95,0x16,0x0c,0x88,0xb0,0x62,0xc1,0x91,0x06,0x6c,0xd9,0x72,0xe5,0x4a,0x91,0x22,0x0b,0xa6,0xb0,0x5d,0x35,0x82,0xe9,0xab,0xf7,0x4d,0x5f,0xba,0x7e,0xe9,0xf3,0x56,0x4f,0x9a,0xb2,0x7c,0xd5,0x93,0x96,0xac,0x9c,0xb2,0x72,0xc9,0xe3,0x76,0x4f,0x1b,0xb2,0x78,0xdd,0x93,0xa6,0xec,0x9d,0x32,0x74,0xc9,0xcb,0x76,0x4e,0x5b,0xb2,0x74,0xc9,0xe3,0x77,0xcd,0xdf,0xb7,0x82,0xde,0x1b,0xf7,0x50,0xdf,0xba,0x86,0xea,0x2b,0xa8,0xae,0xa3,0x3a,0x8c,0xea,0x43,0xc9,0x0f,0x23,0x3c,0x8c,0xf2,0x2b,0xc8,0xaf,0x21,0xbc,0x86,0xf2,0x1b,0xa8,0x6e,0xa0,0xba,0x82,0xea,0x03,0xa8,0x0e,0xa1,0xba,0x86,0xea,0x0b,0xa6,0xf0,0x5d,0x37,0x82,0xe9,0xbb,0xe7,0x4d,0xdf,0x37,0x7c,0xdd,0xfb,0xa7,0xee,0xa0,0xba,0x82,0xea,0x1b,0xa8,0x6e,0xa3,0x3a,0x8c,0xea,0x2c,0x63,0xb1,0x61,0xba,0x86,0xea,0x0b,0xa8,0x2e,0x9f,0xba,0x7e,0xe9,0xf3,0x97,0xce,0x61,0x39,0x84,0xe6,0x2b,0x98,0xae,0x65,0x3e,0x94,0xfa,0x43,0xe9,0x0f,0xa3,0x3e,0x8c,0xfa,0x2b,0xe8,0xaf,0xa3,0x3e,0x8c,0xfa,0x54,0x37,0xf2,0xa1,0xbf,0x95,0x0d,0xfc,0xa8,0x6f,0xe3,0x3c,0x86,0xf2,0x54,0x37,0xf2,0xa1,0xbc,0x86,0xf2,0x54,0x37,0xf2,0xe1,0xbf,0x96,0xfe,0x54,0x58,0x32,0xa2,0xc1,0x95,0x16,0x0c,0x88,0xb0,0x62,0xc1,0x91,0x06,0x6c,0xd9,0x72,0xe5,0x4a,0x91,0x21,0x49,0x55,0xa7,0x58,0x15,0x66,0x75,0xa9,0x57,0x27,0x5e,0x15,0x7e,0x75,0xc9,0x57,0x87,0x60,0x95,0x86,0x76,0x29,0xf3,0xa6,0xde,0x1b,0x34,0x62,0x09,0xa3,0x05,0xa2,0x96,0x2a,0x46,0x32,0x22,0xc8,0x8b,0x22,0x2c,0x88,0xb2,0x22,0xc8,0x8b,0x22,0x2c,0x89,0xd2,0x22,0xc8,0x8b,0x22,0x2c,0x88,0xb2,0x22,0xc8,0x8b,0x22,0x2c,0x89,0x73,0x26,0xae,0x5d,0x39,0x6a,0xc9,0x73,0x26,0xae,0x5d,0x39,0x6a,0xc9,0x73,0x26,0xae,0x5d,0x39,0x6a,0xc9,0x73,0x26,0xae,0x5d,0x39,0x6a,0xc9,0x4a,0xd6,0x0c,0xda,0xb3,0x60,0xb5,0x4a,0xd6,0x0c,0xda,0xb3,0x60,0xb5,0x4a,0xd6,0x0c,0xda,0xb3,0x60,0xb5,0x4a,0xd6,0x0c,0xda,0xb3,0x60,0xb5,0x72,0xd5,0xcc,0x19,0x30,0x64,0xcd,0xab,0x36,0xad,0xdc,0xba,0x7e,0x3d,0xf0,0xf7,0xe6,0xdf,0x1b,0x78,0x3d,0xf3,0x97,0x2e,0x5c,0xb9,0x72,0x45,0xd1,0x17,0x8e,0x8e,0xb9,0x3a,0xd4,0x8b,0x06,0xa6,0x87,0x35,0x1c,0x69,0xab,0x77,0x2e,0x9e,0x3a,0x72,0xe9,0xe3,0xa7,0x2e,0x9e,0x3e,0x7f,0x06,0x2c,0x18,0xb1,0xa4,0x43,0x7c,0xea,0x34,0x37,0xce,0xa0,0x9f,0x86,0x4c,0xfc,0x11,0xd0,0x4d,0x41,0x34,0xf0,0x73,0x91,0xcb,0x4d,0x2b,0x4e,0xad,0x6a,0xe5,0x6b,0x98,0x32,0x5c,0xc9,0x9b,0x56,0xe3,0xd5,0xae,0x64,0xcd,0x73,0x36,0xee,0x9b,0xb3,0x5c,0xb5,0x4a,0xd5,0xcc,0x16,0xb0,0x64,0xcd,0x83,0x36,0xad,0xdc,0x91,0x5a,0xc1,0x9b,0x56,0x0d,0x5c,0xc1,0x78,0xe5,0xab,0xf7,0x8e,0x59,0xbc,0x72,0xfd,0xe3,0x96,0x6f,0x1c,0xbf,0x78,0xe5,0x9b,0xc7,0x2f,0xdc,0xbf,0x78,0xe5,0x9b,0xf7,0x8e,0x59,0xbe,0x7e,0xf9,0xb3,0x25,0xaa,0x96,0xb2,0x6c,0xb5,0x93,0x67,0x2c,0x9b,0x39,0x7c,0xc9,0xb3,0x97,0xce,0x5f,0x36,0x72,0xfa,0x14,0x59,0x51,0x61,0x3e,0x74,0xc9,0xd3,0xc7,0xca,0xd7,0x32,0x6e,0xe9,0xf4,0x38,0xd2,0xa3,0x43,0x7c,0xe9,0xbb,0x26,0xee,0x59,0x39,0x78,0xf9,0x52,0xd6,0x4d,0x9c,0xbe,0x85,0x16,0x54,0x58,0x4f,0x9c,0xb6,0x64,0xd9,0xab,0x97,0x8f,0xa0,0x41,0x87,0x16,0x34,0x58,0xd2,0x23,0x43,0x7d,0x1a,0x1b,0xe7,0x50,0xdf,0x3a,0x6e,0xf9,0xd3,0x76,0x44,0x21,0x9c,0x7c,0x71,0xf1,0x07,0x44,0x1b,0x9c,0x6a,0xb9,0x83,0x25,0xcc,0x99,0xb5,0x64,0xcd,0xa3,0x57,0x4f,0x9f,0xc1,0x7e,0xf9,0xfc,0x17,0xef,0x9f,0xc1,0x7e,0xf9,0xfc,0x18,0xd1,0x63,0x26,0x7c,0xf9,0xf3,0xe7,0xd3,0x63,0x41,0x7d,0x2e,0x34,0x17,0xd2,0xa3,0x41,0x7d,0x2e,0x34,0x17,0xcf,0xe1,0xc6,0x91,0x19,0xfc,0x38,0xd2,0x23,0x33,0x6e,0xe9,0xe3,0xa6,0x6d,0xdd,0x3c,0x7e,0xe9,0xfb,0xa6,0xec,0xd7,0x2d,0x5c,0xc0,0xea,0x13,0xa9,0xd0,0xa4,0x4e,0xa5,0x22,0x75,0x2b,0x53,0xa9,0x5a,0xc1,0xab,0x06,0xae,0x5e,0x35,0x72,0xf2,0x0b,0xc6,0xac,0x0f,0x22,0x4a,0xa1,0x12,0x55,0x0a,0x92,0xa8,0x54,0xb9,0x42,0xa5,0xcc,0x5b,0x31,0x6c,0xe9,0xeb,0x67,0x4f,0x5e,0xb6,0x74,0xf6,0x14,0x27,0x6d,0xa1,0x3b,0x6d,0x09,0xdb,0x68,0x0e,0xdb,0x40,0x77,0x01,0xdb,0xf6,0xcc,0xdf,0xb6,0x66,0xfd,0xb3,0x37,0x4d,0x99,0xba,0x66,0xe9,0x9b,0xd7,0x0c,0xde,0xb8,0x66,0xf5,0xc3,0x37,0x6e,0x19,0xbb,0x66,0xed,0x9b,0xa7,0x0c,0xdd,0x38,0x66,0xed,0x9b,0xd7,0x0f,0xdc,0x40,0x71,0x09,0xc4,0x48,0x0e,0xe2,0x40,0x77,0x11,0xdc,0x67,0x71,0x9d,0xc7,0x77,0x1d,0xdc,0x97,0xb2,0x5e,0xc7,0x7b,0x1d,0xec,0x67,0xb1,0x9e,0xc4,0x7b,0x11,0xec,0x47,0x71,0x1d,0xc2,0x77,0x09,0xdc,0x17,0x70,0x5d,0xc4,0x77,0x11,0xdc,0x27,0x6e,0x21,0x3b,0x71,0x09,0xdb,0x87,0xee,0xdc,0x3f,0x70,0xfd,0xc4,0x07,0x70,0x1d,0xc2,0x77,0x09,0xdc,0x47,0x71,0x1d,0xc7,0x77,0x1d,0xdc,0x68,0xf1,0xa2,0x3b,0x88,0xee,0x13,0xb8,0x4e,0xe0,0x3b,0x80,0xed,0xfb,0xa7,0xee,0xa1,0xba,0x86,0xea,0x33,0xa8,0xce,0xa5,0xbf,0x96,0xfe,0x4b,0xf9,0x2f,0xe3,0xbf,0x8e,0xfe,0x33,0xf8,0xcf,0xe3,0xbf,0x8e,0xfe,0x5c,0x48,0x12,0xe2,0x40,0x97,0x12,0x04,0xb8,0x90,0x23,0xbd,0x88,0xf6,0x5c,0x48,0x12,0xe2,0x3d,0x88,0xf6,0x5c,0x48,0x13,0x22,0x40,0x99,0x02,0x5c,0x68,0x52,0xe3,0x42,0x97,0x1a,0x14,0x98,0xd0,0xa3,0x42,0x93,0x0a,0x74,0xe9,0x93,0x25,0xcb,0x93,0x26,0x1b,0xc6,0xf0,0xde,0x37,0x86,0xf1,0xbc,0x17,0x8d,0xe0,0xbc,0x82,0xf2,0x03,0x76,0x90,0x1b,0xb4,0x80,0xdd,0xa3,0xb6,0xed,0x1d,0xb4,0x76,0xd1,0xf3,0x96,0x8f,0x9c,0xb4,0x7c,0xe5,0xa3,0xc7,0x2d,0x1e,0x34,0x78,0xd1,0xdb,0x96,0x8e,0xdc,0xb4,0x78,0xd1,0xf3,0x98,0x0e,0x60,0xb9,0x86,0xe6,0x2c,0x17,0x91,0x60,0xbc,0x8a,0xf2,0x3b,0xc8,0xef,0x24,0x3c,0x90,0xf2,0x53,0xe9,0x4f,0xa4,0x3e,0x90,0xfa,0x3b,0xe8,0xef,0xa2,0xbe,0x8a,0xfa,0x2b,0xc8,0xaf,0x21,0xbc,0x86,0xf2,0x13,0xc8,0x4f,0x22,0xbc,0x8a,0xf2,0x1b,0xc7,0x30,0xde,0x39,0x86,0xf1,0xcc,0x07,0x8e,0x60,0x39,0x80,0xe6,0x0b,0xc8,0x2f,0x21,0xbc,0x86,0xf2,0x2b,0xc8,0xaf,0x24,0x3c,0x90,0xf2,0x3c,0x83,0xf1,0xe2,0xbc,0x8a,0xf2,0x1b,0xc8,0x6f,0x20,0xbc,0x82,0xf2,0x03,0xb8,0x0e,0xe2,0x3b,0x88,0xee,0x3b,0xb8,0xee,0xe6,0x40,0x99,0x02,0x54,0x09,0x50,0x24,0x40,0x91,0x02,0x3c,0x08,0xf0,0x24,0x40,0x91,0x02,0x64,0x58,0x33,0x22,0xc1,0x99,0x16,0x0c,0xc8,0xb0,0x64,0x3e,0x8a,0xfa,0x64,0x58,0x33,0x22,0xbe,0x8a,0xfa,0x64,0x58,0x33,0x62,0xc1,0x9b,0x06,0x64,0x78,0x73,0x23,0xc3,0x99,0x1e,0x1c,0xa8,0xf0,0xe3,0xc3,0x95,0x0e,0x7c,0xf9,0xb3,0x66,0x4c,0x95,0x2a,0x2b,0xe7,0x31,0x5f,0x39,0x8a,0xf9,0xcc,0x37,0xce,0x61,0xbe,0x86,0xfa,0x13,0x96,0xd0,0x9c,0xb6,0x84,0xe5,0xb3,0xd7,0x2d,0x9e,0xb6,0x7a,0xda,0x03,0xb6,0xd0,0x1d,0xb6,0x80,0xed,0xb3,0xe7,0x6d,0x9f,0x36,0x7c,0xd9,0xeb,0xb6,0xcf,0x5d,0xb6,0x7c,0xda,0x03,0xb8,0x4e,0xe1,0xbb,0x8a,0xee,0x3c,0x37,0xd1,0xe1,0xbe,0x8e,0xfa,0x4b,0xe9,0x2f,0xa5,0x3e,0x94,0xfa,0x64,0x09,0x90,0x25,0x40,0x95,0x02,0x4c,0x09,0x30,0x23,0xc0,0x8f,0x02,0x3b,0xe8,0xef,0xa2,0xbe,0x8a,0xfa,0x23,0xe8,0x8f,0xa3,0xbe,0x8e,0xfa,0x2b,0xe7,0x71,0x5f,0x3b,0x8a,0xf9,0xdc,0x27,0xce,0xe1,0x3b,0x84,0xee,0x1b,0xe8,0x6f,0xa2,0xbe,0x8a,0xfa,0x3b,0xe8,0xef,0xa5,0x3e,0x94,0xfa,0x4c,0xa4,0x32,0x63,0xbe,0x8e,0xfa,0x2b,0xe8,0xaf,0xa1,0xbe,0x86,0xfa,0x13,0xd8,0x4f,0x63,0x3d,0x8c,0xf6,0x4b,0xd9,0x2f,0x67,0x42,0x9d,0x0a,0x64,0x29,0x90,0xa5,0x42,0x95,0x0a,0x4c,0x29,0x30,0xa5,0x42,0x95,0x0a,0x74,0x78,0x73,0xa3,0xc3,0x9d,0x1e,0x1c,0xe8,0xf0,0xe5,0x40,0x8f,0x02,0x74,0x78,0x73,0xa3,0xc0,0x8f,0x02,0x74,0x78,0x73,0xe3,0xc3,0x9f,0x0e,0x74,0x98,0xb3,0xa4,0xc5,0x9d,0x26,0x2c,0xc9,0x31,0x64,0xc5,0x99,0x16,0x8d,0x19,0xf3,0xe7,0x4e,0x99,0x31,0x69,0x96,0x28,0x5a,0x19,0x6e,0x85,0xc9,0x97,0xa8,0x60,0x19,0x86,0x85,0xe9,0x98,0x08,0x62,0x99,0x8e,0x86,0x4a,0x34,0x27,0xe0,0x1f,0x3c,0x72,0x29,0xe3,0x86,0xa4,0x9a,0x32,0x56,0x0a };
const byte PROGMEM hexNotes_1[] = { 0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x28,0x80,0xa2,0x02,0x88,0x0a,0x20,0x36,0xad,0x72,0x74,0xe9,0x57,0x31,0x58,0x9d,0x4a,0x44,0xa9,0xd2,0xa4,0x52,0x95,0x3a,0x54,0x8a,0x51,0x25,0x4c,0x9d,0xfb,0xf7,0xaf,0x5e,0x3c,0x74,0xe8,0xda,0x75,0x6b,0x98,0xb0,0x60,0xc5,0x82,0xe5,0x8a,0xd4,0x2c,0x60,0xd5,0xab,0x76,0xac,0xd8,0x31,0x66,0xd5,0x8b,0x06,0xec,0xd8,0x2e,0x60,0xc9,0xab,0x86,0xec,0xdb,0xb0,0x60,0xc5,0x82,0xe5,0x8a,0xd4,0x2c,0x60,0xd5,0xab,0x76,0xac,0xd8,0x31,0x66,0xd5,0x8b,0x06,0xec,0xd8,0x19,0x3a,0x81,0x29,0x93,0xa8,0x12,0x9b,0x3e,0x89,0x3a,0x74,0xe9,0xd3,0x94,0x40,0x51,0x01,0x44,0x05,0x10,0x0f,0x36,0x3c,0xd8,0xf3,0x63,0xcd,0x91,0x3a,0x44,0xe9,0x13,0xa4,0x4e,0x8c,0x30,0x30,0xc0,0xc3,0x03,0x0c,0x0d,0x32,0x34,0xc8,0xd3,0x23,0x4c,0x8f,0x36,0x3c,0xd8,0xd3,0x23,0x4c,0x8c,0x30,0x30,0xc0,0xc3,0x03,0x0c,0x11,0x3a,0x44,0xe9,0x13,0xa4,0x4e,0x8d,0x32,0x34,0xc8,0xd3,0x23,0x4c,0x8f,0x1e,0x6c,0x69,0x91,0xa6,0x46,0x18,0x18,0x60,0x61,0x81,0x86,0x08,0x9d,0x22,0x74,0x89,0xd2,0x27,0x46,0x99,0x1a,0x64,0x69,0x91,0xa6,0x45,0x16,0x14,0x58,0x51,0x61,0x45,0x87,0x9b,0x1e,0x6c,0x79,0xb1,0xe6,0xdf,0xbf,0x7a,0xf5,0xe3,0xc7,0x4e,0x9c,0x19,0x36,0x80,0xf9,0xd3,0x26,0xd0,0x1f,0x36,0x74,0xc9,0xb4,0x07,0xce,0x99,0x36,0x80,0xd9,0xd4,0x87,0x4c,0x99,0x36,0x6d,0x01,0xf3,0xa7,0x4e,0x99,0x32,0x6c,0xd9,0xf3,0x67,0xcf,0x9f,0x36,0x6c,0xe9,0xd4,0x48,0x4f,0x9f,0x3e,0x6c,0xda,0x92,0x24,0x48,0xa9,0x52,0xa5,0x4a,0x95,0x2a,0x56,0xad,0x5a,0xb5,0x6a,0xd5,0xac,0x18,0x30,0x60,0xc1,0x83,0x06,0x6c,0xd9,0xb3,0x68,0xd1,0xa3,0x46,0xa5,0x91,0x16,0x44,0x59,0x11,0x64,0x44,0x4e,0x91,0x3a,0x44,0xe9,0x13,0xa4,0xcf,0x93,0x3e,0x4c,0xf9,0x33,0xe3,0x8d,0x0e,0x34,0x38,0xd0,0xe3,0x43,0xcd,0x8f,0x36,0x3c,0xd8,0xf3,0x64,0x4e,0x91,0x3a,0x3c,0xd8,0xf3,0x63,0x8d,0x0e,0x34,0x38,0xd0,0xe3,0x44,0xcf,0x93,0x3e,0x4c,0xf9,0x33,0xe3,0xcd,0x8f,0x36,0x3c,0xd8,0xf3,0x64,0x48,0x9d,0x1e,0x6c,0x79,0xb1,0xc6,0x87,0x1a,0x1c,0x68,0x71,0xa2,0x67,0xc9,0x9f,0x26,0x7c,0x99,0xf1,0xe6,0xc7,0x9b,0x1e,0x6c,0x79,0xb1,0x86,0x06,0x18,0x18,0x60,0x61,0x82,0x27,0x48,0x9d,0x22,0x74,0x89,0xd8,0x30,0x5f,0xbf,0x7c,0xf9,0xe3,0xc2,0xc8,0x8b,0x22,0x2c,0x88,0xb2,0x22,0x27,0x48,0x9d,0x22,0x74,0x89,0xd2,0x67,0xc9,0x9f,0x26,0x7c,0x99,0xf1,0xc6,0x87,0x1a,0x1c,0x68,0x71,0xa1,0xe6,0xc7,0x9b,0x1e,0x6c,0x79,0xb2,0x27,0x48,0x9d,0x1e,0x6c,0x79,0xb1,0xc6,0x87,0x1a,0x1c,0x68,0x71,0xa2,0x67,0xc9,0x9f,0x26,0x7c,0x99,0xf1,0xe6,0xc7,0x9b,0x1e,0x6c,0x79,0xb2,0x24,0x4e,0x8f,0x36,0x3c,0xd8,0xe3,0x43,0x8d,0x0e,0x34,0x38,0xd1,0x33,0xe4,0xcf,0x93,0x3e,0x4c,0xf8,0xf3,0x63,0xcd,0x8f,0x36,0x3c,0xd8,0xc3,0x03,0x0c,0x0c,0x30,0x30,0xc1,0x13,0xa4,0x4e,0x91,0x3a,0x44,0xec,0x18,0x2f,0xdf,0xbe,0x7c,0xf1,0xe1,0x13,0x04,0x4c,0x29,0x5a,0xc1,0x9a,0xd6,0x0d,0x5b,0xb9,0x60,0xd5,0xcb,0xa5,0xc5,0x91,0x16,0x44,0x59,0x11,0x64,0x45,0x91,0x16,0x44,0x59,0x11,0x64,0x44,0x4e,0x91,0x3a,0x44,0xe9,0x13,0xa4,0x4e,0x91,0x3a,0x44,0xe9,0x13,0xa3,0xcd,0x8f,0x36,0x3c,0xd8,0xf7,0x90,0x5d,0x3a,0x72,0xe9,0xab,0x56,0xad,0x5a,0xb5,0x6e,0xe5,0xbb,0x56,0x4b,0x58,0x30,0x1c,0x68,0x71,0xa1,0xc6,0x87,0x1a,0x1c,0x68,0x99,0xf2,0x67,0xe2,0xc6,0x8b,0x15,0xe3,0x96,0xaa,0x47,0x9b,0x1e,0x6c,0x79,0xb6,0x4c,0xcd,0x8f,0x36,0x3c,0xd8,0xf3,0x64,0x4e,0x91,0x3a,0x44,0xeb,0x36,0xa7,0x48,0x9d,0x22,0x74,0x89,0xd2,0xc8,0x8b,0x22,0x2c,0x88,0xb2,0x22,0xc8,0x8b,0x22,0x2c,0x8a,0x0b,0xc7,0x28,0x4a,0xa1,0x2a,0x84,0xaa,0x12,0xa8,0x4a,0xa1,0x2a,0x84,0xaa,0x16,0xeb,0x9b,0xb9,0x74,0x7d,0xb2,0xd6,0xce,0x5c,0x9e,0x60,0xd5,0xcb,0x97,0x2e,0x5c,0xb9,0x72,0x44,0xe9,0x03,0x84,0x0e,0x10,0x38,0x40,0xe4,0x68,0x6e,0x9b,0xb2,0x64,0x91,0x22,0x44,0x86,0x12,0x18,0x48,0x61,0x21,0x84,0x88,0x64,0x46,0x8b,0x1a,0x29,0xa4,0xc6,0x93,0x1a,0x4c,0x69,0x31,0xb4,0xe6,0xd3,0x9b,0x4e,0x6d,0x38,0xf3,0x63,0xcd,0x8f,0x36,0x3c,0xd9,0x14,0x84,0x4e,0x91,0x3a,0x44,0xe9,0x13,0xa4,0x4e,0xbc,0x30,0x44,0x91,0xe2,0x47,0x89,0x1e,0x24,0x78,0x91,0xe2,0x47,0xa1,0x2f,0x54,0xb1,0x3a,0x85,0x4a,0x13,0xac,0x50,0xa9,0x42,0x75,0x89,0x54,0x29,0x55,0x0a,0x14,0x08,0x0f,0xdf,0xbd,0x7a,0x61,0x21,0x84,0x86,0x12,0x18,0x48,0x4c,0xf9,0x33,0xe4,0xcf,0x93,0x3e,0x55,0x09,0x54,0x25,0x50,0x95,0x42,0x40,0xe1,0x03,0x84,0x0e,0x10,0x38,0x44,0xe9,0x13,0xa4,0x4e,0x91,0x3a,0x4c,0xf9,0x33,0xe4,0x4e,0x91,0x3a,0x40,0xe1,0x03,0x84,0x0e,0x10,0x38,0x55,0x09,0x54,0x25,0x50,0x95,0x42,0x44,0xe9,0x13,0xa4,0x4e,0x91,0x3a,0x4c,0x99,0xf2,0x27,0x48,0x9d,0x20,0x70,0x81,0xc2,0x07,0x08,0x1c,0x2a,0x84,0xaa,0x12,0xa8,0x4a,0xa1,0x22,0x74,0x89,0xd2,0x27,0x48,0x9d,0x1c,0x68,0x71,0xa1,0xc6,0x87,0x1a,0x26,0x7c,0x99,0xf2,0x67,0xc9,0x9f,0x87,0x0e,0x0c,0x18,0x10,0x1f,0x3e,0x34,0x98,0xd2,0x63,0x49,0x8d,0x26,0x2a,0x84,0xaa,0x12,0xa8,0x4a,0xa1,0x2e,0x8c,0xba,0x32,0xe8,0xcb,0xa3,0x24,0x78,0x91,0xe2,0x47,0x89,0x1e,0x26,0x7c,0x99,0xf2,0x67,0xc9,0x9f,0x2a,0x84,0xaa,0x12,0x67,0xc9,0x9f,0x24,0x78,0x91,0xe2,0x47,0x89,0x1e,0x2e,0x8c,0xba,0x32,0xe8,0xcb,0xa3,0x26,0x7c,0x99,0xf2,0x67,0xc9,0x9f,0x2a,0x55,0x09,0x33,0xe4,0xcf,0x92,0x3c,0x48,0xf1,0x23,0xc4,0x8f,0x17,0x46,0x5d,0x19,0x74,0x65,0xd1,0x93,0x3e,0x4c,0xf9,0x33,0xe4,0xcf,0x90,0x38,0x40,0xe1,0x03,0x84,0x0e,0x15,0x42,0x55,0x09,0x54,0x25,0x50,0xc5,0x8b,0x0e,0x1c,0x28,0x50,0x20,0x15,0x38,0x54,0xe2,0xd6,0x2d,0x1b,0xb1,0x68,0xe5,0xdb,0xd6,0x8e,0x5e,0xbe };

const byte * const PROGMEM song[] = { hexMap_0, hexNotes_0, hexMap_1, hexNotes_1 };

const byte noteDuration = 65;                                                // Duration of every note / pause
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */

const byte numberOfLayers = sizeof(song)/4;                                   // Calculate number of layers
const int songSize = sizeof(hexMap_0)*8;                                      // Calculate song size (how many notes need to be played)
Tone player[numberOfLayers];                                                  // Tone instance

void setup() {                                                                // Run once
  Serial.begin(9600);
  for(byte i=0;i<numberOfLayers;i++){
    player[i].begin(i+2);                                                     // Loop through input pins starting from 2
  }
  // player[0].begin(11);
  // player[1].begin(12);                                                     // Or choose your output pins   
}

void loop() {                                                                 // Play repeateadly
  // Init / Reset variables
  int hexNotesIndex[numberOfLayers];
  byte mask_1[numberOfLayers];
  byte mask_2[numberOfLayers];
  byte shift[numberOfLayers];

  for(byte i=0;i<numberOfLayers;i++){
    hexNotesIndex[i] = -1;
    mask_1[i] = 0xff;
    mask_2[i] = 0xff;
    shift[i] = 7;
  }

  int i = 0;
  while (i < songSize) {  
    if(player[0].isPlaying()) continue;                                       // If there's already a note playing, loop and try again
    // const byte hexMapIndex = i / 8;                                           // Index of the 8-bit chunk to check
    // const byte hexMapBitIndex = 7 - (i % 8);                                        // Index of the bit (0 - 7) to check
    // byte isNote[numberOfLayers];
    // for(byte j=0;j<numberOfLayers;j++) isNote[j] = bitRead(pgm_read_byte(&song[j*2][hexMapIndex]), hexMapBitIndex); // Read bit value - 0=pause - 1=note
                                                                      // Next not playing audio loop, read next hexMap bit and next hexNote chunk / pause
    // Loop check
    boolean pause = true;
    for (byte j=0;j<numberOfLayers;j++){
      
      Serial.println(j);
      const byte isNote = bitRead(pgm_read_byte(&song[j*2][i / 8]), 7 - (i % 8));
      if(isNote == 0) continue;                                                // If there is a pause, check the next layer
      if (mask_2[j] == 0x00) {                                                // Reset variables every 8 cycles and apply corrections
        mask_2[j] = ~mask_2[j];                                               // Indirectly set mask_1 to 0x00, mask_2 to 0xfe
        hexNotesIndex[j]--;                                                   // Correct index (or you would skip a note every 8 loops)
        shift[j] = 7;                                                         // Reset bit shifting
      }

      mask_1[j] = ~mask_2[j];                                                 // Bitwise NOT on mask  _2
      mask_2[j] = mask_2[j] << 1;                                             // Bitwise SHIFT - only maskis_2  needed to generate the next mask generation

      const byte chunk_1 = pgm_read_byte(&song[j == 0 ? 1 : 1][hexNotesIndex[j]]);     // note chunk #1 (may be empty)
      const byte chunk_2 = pgm_read_byte(&song[j == 0 ? 1 : 1][hexNotesIndex[j] + 1]); // note chunk #2 (may be empty)

      // Use bit masks and shifts to get 7-bits numbers sequentially from PROGMEM hexNotes
      const byte intNoteIndex = ((chunk_1 & mask_1[j]) << shift[j] ) | ((chunk_2 & mask_2[j]) >> (8 - shift[j]));
      shift[j]--;                                                             // Decrement shift  (will reset to 7 when 0 aka when mask==_2  0x00)
      hexNotesIndex[j]++;                                                     // Increment notes index (next play, grab next note... remember if(mask_2_SX == 0x00) => hexNotesInedx_SX--)

      player[j].play(notes[intNoteIndex], noteDuration);                      // Finally - Actual note play :D
      pause = false;                                                         // If at least one note plays, don't pause
    }
    if(pause) delay(noteDuration);                                            // If no notes play, pause
    i++;
  } // end while
} // end loop
