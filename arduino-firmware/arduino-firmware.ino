
#include <Tone.h>                                                           // Used to output to multiple pins at the same time (max 3 for Arduino Uno)

const int notes[] = {                                                       // Notes pool - int frequency values (declared in Tone.h)
  NOTE_B0, NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2,
  NOTE_B2, NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4,
  NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5, NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6,
  NOTE_B6, NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7, NOTE_C8, NOTE_CS8, NOTE_D8, NOTE_DS8
};

/* ---- ACTUAL MELODY ----------------------------------------------------------------------------------------------------------------------------------------------------------------- */
// Sample song - format doesn't really matter, you can use decimal, binary, ecc... I prefer hex for readability since I'm working with bits
const uint8_t hexMap_SX[] = {                                               // Values that tell the program when to play and when to pause, reading a bit every not playing / pausing loop
0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xed,0x5f,0xed,0x5f,0xed,0x5f,0xed,0x5f,0xef,0x7f,0xef,0x7f,0xef,0x7f,0xef,0x7f,0xef,0x7f,0xef,0x7f,0xef,0x7f,0xef,0x7f,0xbf,0x7e,0xbf,0x7e,0xbf,0x7e,0xaf,0x7e,0xff,0x7f,0xff,0x7f,0xff,0xff,0xff,0x7f,0xaf,0xff,0xef,0x7f,0xbf,0xfe,0xaf,0x7e,0xaf,0xfe,0xaf,0xfe,0xaf,0xff,0xaf,0xfe,0xaf,0xff,0xef,0x7f,0xbf,0xfe,0xaf,0x7e,0xaf,0xfe,0xaf,0xfe,0xaf,0xff,0xaf,0xfe,0xad,0x5e,0xad,0xde,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0xde,0xad,0xff,0xad,0x5e,0xed,0x5f,0xed,0xdf,0xed,0x5f,0xff,0xdf,0xed,0x5f,0xed,0xdf,0xed,0x5f,0xed,0x5f,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xaf,0x7e,0xef,0x7f,0xef,0x7f,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0x00,0x00
};

const uint8_t hexMap_DX[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xa9,0x56,0xa9,0x56,0xa9,0x56,0xa9,0x56,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xe9,0x57,0xa5,0x50,0xa5,0x7c,0xa5,0x54,0xaf,0x08,0xbd,0x52,0xbd,0x56,0xef,0x7f,0xbd,0x52,0x00,0xff,0xe8,0x04,0xaf,0x2a,0xaf,0x00,0xaa,0x88,0x88,0x88,0x80,0x7e,0x80,0x80,0x00,0xff,0xe8,0x04,0xaf,0x2a,0xaf,0x00,0xaa,0x88,0x88,0x88,0x80,0x7e,0x80,0x80,0x80,0x08,0x80,0x00,0x80,0x00,0x00,0x00,0x80,0x08,0x80,0x00,0x80,0x5f,0x80,0x00,0xa9,0x5e,0xa9,0x56,0xa9,0x56,0xa9,0x57,0xa9,0x5e,0xa9,0x56,0xa9,0x57,0xa9,0x57,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x5e,0xad,0x56,0xad,0x56,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

const uint8_t PROGMEM hexNotes_SX[] = {                                     // Compressed list of every note, regardless of the pauses
0x4e,0x9d,0x9a,0xe5,0xab,0x15,0x27,0x54,0xb1,0x2a,0x56,0x6b,0x96,0xac,0x54,0x9d,0x52,0xc4,0x89,0x19,0xae,0x5a,0xb1,0x52,0x75,0x4b,0x11,0xa3,0x66,0xb9,0x6a,0xc5,0x49,0xd5,0x2c,0x4e,0x9d,0x9a,0xe3,0x6b,0x56,0x2a,0x36,0x9d,0x52,0xc4,0xa9,0x59,0xae,0x32,0xb5,0x62,0xa3,0x29,0xd5,0x2c,0x48,0x91,0x9a,0xe3,0x0b,0x56,0x2a,0x30,0x9d,0x52,0xc4,0x68,0xd9,0xae,0x2e,0xb5,0x62,0xa3,0x29,0xd5,0x2c,0x66,0xcd,0xfb,0xa1,0xe6,0xdc,0xb8,0x36,0xd8,0x7b,0x36,0xce,0x18,0xb1,0x7e,0xe8,0x69,0x97,0x2e,0x0c,0xb6,0x1a,0xcd,0xb3,0x86,0x0c,0x1f,0xba,0x18,0x61,0xcb,0x83,0x0d,0x86,0x33,0x6c,0xe1,0x7a,0xf7,0xee,0x85,0x97,0x72,0xe0,0xcb,0x61,0xac,0xdb,0x38,0x66,0xcd,0xfb,0xa1,0xe6,0xdc,0xb8,0x36,0xd8,0x7b,0x36,0xce,0x18,0xb1,0x7e,0xe8,0x69,0x97,0x2e,0x0c,0xb6,0x1a,0xcd,0xb3,0x86,0x0c,0x1f,0xba,0x18,0x61,0xcb,0x83,0x0d,0x86,0x33,0x6c,0xe1,0x7a,0xf7,0xee,0x85,0x97,0x72,0xe0,0xcb,0x61,0xac,0xdb,0x38,0x6c,0xd9,0xb0,0xf6,0xc6,0xdb,0x33,0x36,0xcc,0x78,0xf3,0x6d,0x9b,0x36,0x1a,0xe0,0xcb,0x97,0x0e,0x19,0xb6,0x70,0x65,0xb3,0x66,0xc3,0x1c,0x18,0x72,0xe8,0xc3,0xd1,0x8e,0x8c,0x3f,0x7e,0xfd,0xd3,0xf7,0xa3,0x4c,0x8d,0x88,0x34,0xcb,0x61,0xee,0x9d,0x0f,0x6c,0x6d,0xd3,0x33,0x6c,0xc7,0x8f,0x36,0x51,0xb0,0xd7,0x4d,0x8b,0x36,0x36,0xe1,0xd1,0xb7,0xe3,0x59,0xb1,0x28,0xfd,0xc3,0xa6,0xad,0x99,0xb6,0x66,0xf5,0x9b,0x86,0x6d,0x96,0x35,0x58,0xbc,0x5b,0x16,0x65,0x99,0x9b,0x7a,0x50,0xd9,0x21,0xa3,0xcd,0x94,0x16,0x5c,0x58,0xb2,0xe2,0xd9,0xb3,0x6c,0xd5,0xb3,0x86,0xcc,0xdc,0xb3,0x6c,0xd4,0x69,0x91,0xa3,0x4c,0x8d,0x1a,0xe4,0xcb,0xa7,0xae,0x9c,0xb8,0x6c,0xcd,0xab,0x61,0xee,0x07,0xba,0x1e,0xf5,0xf3,0x97,0x2e,0x1b,0x38,0x20,0x70,0x81,0x02,0x07,0x15,0x29,0x54,0x2d,0x98,0xb6,0x22,0xcb,0x8b,0x66,0x2c,0xbb,0x53,0x2d,0x86,0x99,0x1a,0xe0,0x69,0x91,0xad,0x46,0x99,0x74,0x6c,0x78,0xf3,0x63,0xdd,0x39,0x70,0xdd,0xb3,0x56,0x8c,0xd9,0x1a,0x1c,0x38,0xd1,0x06,0x84,0x0e,0x10,0x20,0x40,0xe0,0xb2,0xe2,0xc5,0x97,0x16,0xcd,0x9b,0x66,0xad,0x9c,0x36,0x66,0xe1,0x9b,0x37,0x03,0x4c,0x8d,0x1a,0x64,0x68,0xd7,0x26,0x5d,0x3d,0x74,0xe5,0xc3,0x66,0x6d,0x5b,0x0f,0x70,0x3d,0xd0,0xf7,0xaf,0x9c,0xb9,0x70,0xd9,0xc1,0x03,0x84,0x08,0x10,0x38,0xa9,0x4a,0xe1,0x6d,0x85,0xb5,0x16,0x5c,0x5b,0x31,0x65,0xda,0x99,0x6c,0x34,0xc8,0xd7,0x03,0x4c,0x8d,0x6a,0x34,0xcb,0xa3,0x63,0xc7,0x9b,0x1e,0xe9,0xcb,0x86,0xed,0x9a,0xb4,0x66,0xc8,0xd0,0xe1,0xc6,0x88,0x34,0x20,0x70,0x81,0x02,0x07,0x11,0x8b,0x16,0x2c,0x58,0xb1,0x6a,0x85,0x8b,0x52,0x34,0x68,0xd1,0xa9,0xc6,0x8d,0x1a,0x34,0x6a,0xa1,0x83,0x06,0x0c,0x18,0x30,0x60,0xc1,0x83,0x06,0x0c,0x18,0x30,0x60,0xc1,0x83,0x06,0x23,0x16,0x2c,0x58,0xb1,0x62,0xd5,0x0b,0x16,0xa4,0x68,0xd1,0xa3,0x53,0x8d,0x1a,0x34,0x68,0xd4,0xe3,0xc7,0x8f,0x1e,0x9d,0x2a,0x44,0x48,0x4f,0x9e,0x3a,0x6c,0x78,0xf1,0xe3,0xc7,0x8f,0x1e,0x3c,0x79,0xb3,0x69,0xd1,0x0b,0x42,0x80,0xf2,0xa3,0x67,0x90,0x29,0x32,0x9d,0x10,0xd4,0x29,0xd0,0x1e,0x1a,0x6c,0xf2,0x05,0x46,0x13,0xa2,0x18,0x85,0x01,0xe1,0x86,0xcf,0x20,0x30,0x81,0x52,0x75,0x83,0x15,0x25,0x4e,0x94,0xf0,0xc4,0x07,0x92,0xa3,0x36,0x9d,0x10,0xb4,0x28,0x0f,0x2a,0x36,0x79,0x02,0x93,0x29,0xd1,0x0d,0x42,0x9d,0x01,0xe1,0xa6,0xcf,0x20,0x4e,0x6d,0x52,0x91,0xe9,0x54,0xa7,0x1e,0x6c,0xf2,0x53,0x66,0xd3,0xa9,0x1e,0x95,0x4a,0x71,0xe8,0x0f,0x25,0x46,0x8c,0xb9,0xe2,0xe8,0xcf,0x17,0x2e,0x5c,0xba,0x34,0xa9,0x4c,0xa5,0x32,0x95,0x29,0x93,0x26,0x4c,0xa5,0x4e,0x9c,0xda,0x73,0x69,0x93,0x1a,0x34,0x68,0xd2,0x64,0xa9,0x4c,0xa5,0x32,0x91,0x21,0x83,0x06,0x0c,0x1f,0x46,0x8c,0xb9,0xe2,0xe7,0x91,0x97,0x2e,0x5c,0xb9,0xe4,0xa9,0x4c,0xa5,0x32,0x95,0x29,0x93,0x26,0x4c,0xa5,0x4e,0x9c,0xda,0x73,0x69,0xd3,0x9b,0x36,0x6c,0xda,0x74,0xe9,0xcd,0xa7,0x36,0x9d,0x39,0xb3,0x66,0xcd,0xa7,0x3c,0x78,0xb9,0xe2,0xe7,0x91,0x97,0x2e,0x5c,0xba,0x34,0xa9,0x4c,0xa5,0x32,0x95,0x29,0x93,0x26,0x4c,0xa5,0x4e,0x9c,0xda,0x73,0x69,0x93,0x1a,0x34,0x68,0xd2,0x64,0xa9,0x4c,0xa5,0x32,0x91,0x21,0x83,0x06,0x0c,0x1f,0x46,0x8c,0xb9,0xe2,0xe7,0x91,0x97,0x2e,0x5c,0xb9,0xe4,0xa9,0x4c,0xa5,0x32,0x95,0x29,0x93,0x26,0x4c,0xa5,0x4e,0x6d,0x3a,0x24,0xe6,0xd3,0xa7,0x36,0x78,0x79,0xb4,0xe8,0x13,0x9b,0x4e,0x89,0x39,0xb4,0xe9,0xcd,0x9e,0x1e,0x6d,0x3a,0x04,0x68,0xd9,0xae,0x5a,0xb1,0x52,0x75,0x4b,0x12,0xa5,0x66,0xb9,0x6a,0xc5,0x49,0xd5,0x2c,0x4e,0x9d,0x9a,0xe5,0xab,0x15,0x27,0x54,0xb1,0x3a,0x76,0x6b,0x96,0xac,0x54,0x9d,0x52,0xc4,0x68,0xd9,0xae,0x5a,0xb1,0x52,0x75,0x4b,0x12,0xa5,0x66,0xb9,0x6a,0xc5,0x49,0xd5,0x2c,0x4e,0x9d,0x9a,0xe5,0xab,0x15,0x27,0x54,0xb1,0x2a,0x56,0x6b,0x96,0xac,0x54,0x9d,0x52,0xc4,0x89,0x19,0xae,0x5a,0xb1,0x52,0x75,0x4b,0x11,0xa3,0x66,0xb9,0x6a,0xc5,0x49,0xd5,0x2c
};

const uint8_t PROGMEM hexNotes_DX[] = {                                     // Notes are 7-bits numbers representing actual note indexes (notes[]) compressed in 8-bit values
0x36,0x6c,0xd9,0xb3,0x66,0xcd,0x9b,0x32,0x64,0xc9,0x93,0x26,0x4c,0x99,0x30,0x60,0xc1,0x83,0x06,0x0c,0x18,0x2e,0x5c,0xb9,0x93,0x26,0x4c,0x99,0x4e,0x9d,0x9a,0xe5,0xab,0x15,0x27,0x54,0xb1,0x2a,0x56,0x6b,0x96,0xac,0x54,0x9d,0x52,0xc4,0x89,0x19,0xae,0x5a,0xb1,0x52,0x75,0x4b,0x11,0xa3,0x66,0xb9,0x6a,0xc5,0x49,0xd5,0x2c,0x4e,0x9d,0x9a,0xe5,0xab,0x15,0x27,0x54,0xb1,0x2a,0x56,0x6b,0x96,0xac,0x54,0x9d,0x52,0xc4,0x89,0x19,0xae,0x5a,0xb1,0x52,0x75,0x4b,0x11,0xa3,0x66,0xb9,0x6a,0xc5,0x49,0xd5,0x2c,0x1e,0x6c,0x78,0xf1,0xe3,0xc6,0x99,0x1a,0x35,0xcb,0x61,0xa3,0x46,0x8c,0x30,0x30,0x60,0xc1,0x83,0x05,0x97,0x16,0x2c,0xb8,0xd1,0xae,0x9b,0x36,0x2c,0xe9,0xb3,0x87,0x04,0x9d,0x36,0x74,0x35,0xd3,0x36,0xcd,0x5d,0x38,0x78,0x31,0x9b,0x81,0x8c,0x0a,0x94,0x60,0x49,0x80,0xf6,0x05,0x05,0x9b,0x5e,0x2d,0xb3,0x51,0xa3,0x49,0x36,0x5e,0xcd,0xc3,0x96,0xac,0xd7,0xb8,0x6c,0xcd,0xc0,0xd1,0xe6,0xc7,0x8f,0x36,0x3c,0xd8,0xf3,0x63,0x8d,0x0e,0x1c,0x68,0x82,0x75,0x8b,0x9b,0x35,0x5c,0xb1,0x73,0x15,0xcc,0xc7,0x9b,0x1e,0x3c,0x79,0xb5,0xab,0xdb,0x2f,0x66,0xe1,0xcb,0x56,0x6b,0xdc,0xb6,0x6c,0xd4,0x68,0xf3,0x63,0xc7,0x9b,0x1e,0x6c,0x79,0xb1,0xc6,0x87,0x0e,0x34,0x41,0x3a,0xc5,0x4c,0xd8,0xae,0x58,0xb9,0x8a,0xe6,0x63,0xcd,0x8f,0x1e,0x3c,0xda,0xd5,0xe2,0xc5,0x8d,0x18,0x2c,0x58,0xd1,0xe9,0x91,0x8f,0x40,0x3c,0xe0,0xf4,0x62,0xc5,0x8b,0x16,0x2c,0x58,0xb1,0x66,0x46,0x8d,0x1a,0x34,0x68,0xd1,0xa6,0x06,0x0c,0x18,0x30,0x60,0xc1,0x83,0x13,0xa2,0x42,0x81,0x11,0xb4,0x48,0x0d,0x8b,0x16,0x2c,0x58,0xb1,0x62,0xc5,0x99,0x1a,0x34,0x68,0xd1,0xa3,0x46,0x9b,0x4e,0x89,0x0a,0x03,0xc8,0x11,0x20,0x1e,0xa9,0x12,0x14,0x07,0x8d,0xa2,0x40,0x78,0xf0,0xb4,0x67,0x91,0x8b,0x16,0x2c,0xf2,0x04,0x03,0x50,0x20,0x40,0x34,0x68,0xd4,0x08,0x91,0x0f,0x44,0x85,0x08,0xe1,0xc3,0x90,0xa0,0x40,0x35,0x01,0xf3,0xe3,0x06,0x0c,0x48,0x78,0xf0,0xb4,0x68,0xcf,0x0b,0x16,0x2d,0x1a,0x04,0x03,0x50,0x20,0x40,0x34,0x68,0xd4,0x08,0x91,0x0f,0x44,0x89,0x10,0xf1,0xe3,0xd1,0x22,0x44,0x3d,0x12,0x24,0x43,0xc7,0x8f,0x44,0x8d,0x18,0xb4,0x68,0xcf,0x0b,0x16,0x2c,0xf2,0x04,0x03,0x50,0x20,0x40,0x34,0x68,0xd4,0x08,0x91,0x0f,0x44,0x85,0x08,0xe1,0xc3,0x90,0xa0,0x40,0x35,0x01,0xf3,0xe3,0x06,0x0c,0x48,0x78,0xf0,0xb4,0x68,0xcf,0x0b,0x16,0x2d,0x1a,0x04,0x03,0x50,0x20,0x40,0x34,0x68,0xd4,0x06,0xcd,0x8f,0x1e,0x85,0x00,0xf1,0xe7,0x8d,0x9b,0x1e,0x3d,0x0a,0x01,0xe3,0xcf,0x00
};

const byte noteDuration = 120;                                              // Duration of every note / pause
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */

const int songSize = (sizeof(hexMap_SX) / sizeof(hexMap_SX[0])) * 8;        // 1 notes chunk = 1 byte = 8 bit (size * 8)

// TODO: Implement loops / arrays instead of this horrible and repetitive code (and for N layers of notes, instead of 2)

Tone AUDIO_SX;                                                              // Tone instance
Tone AUDIO_DX;                                                              // See library Tone.h

void setup() {                                                              // Run once
  AUDIO_SX.begin(3);                                                        // Put the dominant AUDIO first (don't ask me why)
  AUDIO_DX.begin(2);                                                        // And choose your output pins
}

void loop() {                                                               // Play repeateadly
  // Init / Reset variables
  int hexNotesIndex_SX = -1;
  byte mask_1_SX = 0xff;
  byte mask_2_SX = 0xff;
  byte shift_SX = 7;
  
  int hexNotesIndex_DX = -1;                                                // First mask_1 is 0x00 - with index = 0 you would skip a note
  byte mask_1_DX = 0xff;                                                    // Setup masks before the bitwise NOT and SHIFT
  byte mask_2_DX = 0xff;
  byte shift_DX = 7;

  int i = 0;
  while (i < songSize) {
    if(AUDIO_SX.isPlaying()) continue;                                      // If there's already a note playing, loop and try again - AUDIO_SX is the dominant audio
    
    // AUDIO is not playing, hence a note play or pause will happen now
    const byte hexMapIndex = i / 8;                                         // Index of the 8-bit chunk to check
    const byte hexMapBitIndex = 7 - (i % 8);                                // Index of the bit (0 - 7) to check
    const byte isNote_SX = bitRead(hexMap_SX[hexMapIndex], hexMapBitIndex); // Read bit value - 0=pause - 1=note
    const byte isNote_DX = bitRead(hexMap_DX[hexMapIndex], hexMapBitIndex); // Example: i = 5, number 0, 6th bit
    i++;                                                                    // Next not playing audio loop, read next hexMap bit and next hexNote chunk / pause
    
    // For saving hexMaps in PROGMEM instead
    // const byte isNote_SX = bitRead(pgm_read_byte(&hexMap_SX[hexMapIndex]), hexMapBitIndex);
    // const byte isNote_DX = bitRead(pgm_read_byte(&hexMap_DX[hexMapIndex]), hexMapBitIndex);

    if (!isNote_DX && !isNote_SX) delay(noteDuration);                      // Check if there is something to play - if there's not, pause note
    else {                                                                  // If there is, check individually each side
      if (isNote_SX) {                                                      // Setup masks, corrections, get notes data from PROGMEM, parse it, get note index, play note
        if (mask_2_SX == 0x00) {                                            // Reset variables every 8 cycles and apply corrections
          mask_2_SX = ~mask_2_SX;                                           // Indirectly set mask_1 to 0x00, mask_2 to 0xfe
          hexNotesIndex_SX--;                                               // Correct index (or you would skip a note every 8 loops)
          shift_SX = 7;                                                     // Reset bit shifting
        }

        mask_1_SX = ~mask_2_SX;                                             // Bitwise NOT on mask  _2
        mask_2_SX = mask_2_SX << 1;                                         // Bitwise SHIFT - only maskis_2  needed to generate the next mask generation

        byte buffer[2];                                                     // Save necessary values from PROGMEM into buffer
        buffer[0] = pgm_read_byte(&hexNotes_SX[hexNotesIndex_SX]);          // note chunk #1 (may be empty)
        buffer[1] = pgm_read_byte(&hexNotes_SX[hexNotesIndex_SX + 1]);      // note chunk #2 (may be empty)

        // Use bit masks and shifts to get 7-bits numbers sequentially from PROGMEM hexNotes
        const byte intNoteIndex_SX = ((buffer[0] & mask_1_SX) << shift_SX ) | ((buffer[1] & mask_2_SX) >> (8 - shift_SX));
        shift_SX--;                                                         // Decrement shift  (will reset to 7 when 0 aka when mask==_2  0x00)
        hexNotesIndex_SX++;                                                 // Increment notes index (next play, grab next note... remember if(mask_2_SX == 0x00) => hexNotesInedx_SX--)

        AUDIO_SX.play(notes[intNoteIndex_SX], noteDuration);                // Finally - Actual note play :D
      }
      
      if (isNote_DX) {                                                      // Setup masks, corrections, get notes data from PROGMEM, parse it, get note index, play note
        if (mask_2_DX == 0x00) {                                            // Reset variables every 8 cycles and apply corrections
          mask_2_DX = ~mask_2_DX;                                           // Indirectly set mask_1 0x00, mask_2 to 0xfe
          hexNotesIndex_DX--;                                               // Correct index (or you would skip a note every 8 loops)
          shift_DX = 7;                                                     // Reset bit shifting
        }

        mask_1_DX = ~mask_2_DX;                                             // Bitwise NOT on mask_2
        mask_2_DX = mask_2_DX << 1;                                         // Bitwise SHIFT - only mask_2 is needed to generate the next mask generation

        byte buffer[2];                                                     // Save necessary values from PROGMEM into buffer
        buffer[0] = pgm_read_byte(&hexNotes_DX[hexNotesIndex_DX]);          // note chunk #1 (may be empty)
        buffer[1] = pgm_read_byte(&hexNotes_DX[hexNotesIndex_DX + 1]);      // note chunk #2 (may be empty)
        
        // Use bit masks and shifts to get 7-bits numbers sequentially from PROGMEM hexNotes
        const byte intNoteIndex_DX = ((buffer[0] & mask_1_DX) << shift_DX ) | ((buffer[1] & mask_2_DX) >> (8 - shift_DX));
        shift_DX--;                                                         // Decrement shift  (will reset to 7 when 0 aka when mask==_2  0x00)
        hexNotesIndex_DX++;                                                 // Increment notes index (next play, grab next note... remember if(mask_2_DX == 0x00) => hexNotesInedx_DX--)

        AUDIO_DX.play(notes[intNoteIndex_DX], noteDuration);                // Finally - Actual note play :D
      }
    } // end play note
  } // end while
} // end loop