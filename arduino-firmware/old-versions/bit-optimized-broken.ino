#include <Tone.h>

const int notes[] = {                                                         // Notes pool - int frequency values (declared in Tone.h)
  NOTE_B0, NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2,
  NOTE_B2, NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4,
  NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5, NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6,
  NOTE_B6, NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7, NOTE_C8, NOTE_CS8, NOTE_D8, NOTE_DS8
};

/* ---- ACTUAL MELODY ----------------------------------------------------------------------------------------------------------------------------------------------------------------- */
const uint8_t hexMap_DX[] = {
128,0,128,0,128,0,128,0,128,0,128,0,128,0,128,0,0,255,136,130,170,152,136,138,170,144,10,138,138,138,138,138,138,138,154,138,138,138,138,136,138,136,10,138,138,138,138,138,138,138,154,138,138,138,138,138,136,136,144,8,144,8,144,8,136,136,144,8,144,8,144,136,136,136,136,154,170,136,136,138,170,136,136,154,170,136,136,138,170,152,136,154,170,136,136,138,170
};

const uint8_t hexMap_SX[] = {
128,128,130,8,128,136,162,0,128,128,130,8,136,136,130,0,0,255,170,186,170,250,170,186,170,144,171,170,186,170,186,186,186,171,186,171,186,170,186,170,170,170,171,170,186,171,186,186,186,171,186,171,186,170,186,186,170,170,146,154,146,154,146,154,136,136,146,154,146,154,146,154,170,170,170,186,170,250,170,186,170,250,170,186,170,250,170,186,170,186,170,186,170,250,170,186,170
};

const uint8_t PROGMEM hexNotes_DX[] = {
0b01010000,0b10010101,0b00111010,0b10000101,0b00001001,0b01010011,0b10100101,0b01001010,0b10001101,0b00000001,0b11100100,0b00000111,0b10001110,0b00010111,0b01010000,0b10110001,0b01101001,0b11100110,0b01101100,0b11010001,0b10011110,0b00100000,0b10111101,0b01000011,0b00010111,0b00001110,0b01010000,0b10011110,0b01011110,0b10111101,0b01100010,0b11110101,0b11101100,0b01010110,0b00100011,0b01010000,0b10100001,0b00011010,0b11110100,0b01100111,0b10010011,0b10100011,0b00111100,0b11010001,0b00101010,0b00000110,0b01101000,0b11001111,0b00110001,0b01000010,0b01100101,0b00101010,0b00010011,0b00101100,0b01011000,0b10100101,0b01000010,0b01011101,0b00011001,0b11100110,0b10001000,0b00001011,0b10001101,0b01000000,0b01100101,0b10011010,0b01110100,0b01001010,0b10010101,0b00101100,0b01001000,0b11000001,0b10000010,0b01000101,0b10001000,0b11010100,0b00101000,0b01000110,0b10111101,0b00011001,0b11100100,0b11101000,0b11001111,0b00110100,0b01001010,0b10000001,0b10011010,0b00110011,0b11001100,0b01010000,0b10011001,0b01001010,0b10000100,0b11001011,0b00010110,0b00101001,0b01010000,0b10010111,0b01000110,0b01111001,0b10100010,0b00000010,0b11100011,0b01010000,0b00011001,0b01100110,0b10011101,0b00010011,0b00110100,0b11101000,0b10011001,0b10110000,0b01100010,0b11001101,0b10001011,0b00010100,0b10101001,0b11010011,0b10100011,0b01010000,0b10100001,0b00111011,0b00100110,0b10001101,0b10011100,0b00110001,0b01100010,0b10010101,0b00111010,0b01110100,0b10101100,0b11010100,0b00110011,0b01001010,0b01010001,0b10000011,0b00010110,0b01101010,0b00010110,0b00101101,0b01011000,0b10000101,0b01101011,0b00110110,0b01101001,0b11001111,0b00010000,0b01010000,0b11000101,0b11000011,0b10010100,0b00100111,0b10000101,0b10011110,0b01001110,0b01111000,0b10000010,0b10000101,0b00001011,0b00010110,0b10101100,0b01000110,0b10110101,0b10011011,0b00110100,0b11100111,0b10001000,0b00101000,0b01100010,0b11100001,0b11001010,0b00010011,0b11001011,0b11010111,0b10101100,0b01011110,0b10111101,0b10001010,0b01010101,0b00001011,0b00010110,0b10101100,0b01000110,0b10110101,0b10011011,0b00110100,0b11100111,0b10001000,0b00101000,0b01100010,0b11100001,0b11001010,0b00010011,0b11001011,0b11010111,0b10101100,0b01011110,0b10111101,0b10001
};

const uint8_t PROGMEM hexNotes_SX[] = {
0b01100010,0b11010001,0b10110011,0b01000110,0b11001101,0b10011101,0b10111001,0b01110000,0b11011001,0b11000011,0b10000111,0b01101111,0b01011011,0b00110100,0b01110110,0b11101101,0b11000011,0b10110111,0b01101111,0b01011110,0b10111011,0b01110000,0b11011001,0b11000011,0b01100110,0b10001011,0b11011000,0b10100000,0b01101000,0b10000001,0b10110001,0b11100110,0b10001000,0b01011011,0b00110110,0b01101100,0b11101101,0b11001011,0b10000110,0b11001000,0b11011100,0b00101100,0b01000110,0b11100001,0b00000011,0b10110100,0b00001111,0b01001111,0b00110110,0b01001010,0b11010001,0b11011011,0b10110111,0b00001110,0b11011101,0b10111101,0b00100000,0b10001101,0b10100010,0b11110101,0b11101011,0b00010001,0b10101100,0b01101000,0b11010000,0b11110011,0b01100100,0b11101011,0b11010111,0b10011110,0b01001110,0b10111101,0b11000010,0b00000111,0b00101010,0b00011100,0b00110110,0b00111100,0b11010001,0b00111011,0b01100111,0b00000110,0b01011100,0b10100101,0b01110000,0b11000100,0b11001010,0b01010110,0b00101100,0b11011010,0b00100001,0b01101000,0b10100001,0b10011011,0b00110011,0b11001001,0b11011010,0b00110110,0b01110010,0b01011101,0b11000010,0b00110110,0b11001101,0b00001100,0b10100101,0b01110000,0b11100001,0b00010011,0b01100101,0b01001101,0b01011011,0b00100010,0b01100010,0b10001001,0b10001010,0b00000100,0b11101100,0b11011001,0b10100000,0b01001110,0b10000000,0b10000010,0b00110110,0b10001011,0b11010111,0b10101100,0b01000110,0b10110001,0b10100011,0b01000011,0b11001101,0b10010011,0b10101111,0b01011110,0b01111001,0b00111011,0b11010111,0b01101110,0b00010000,0b00111001,0b01010000,0b11100001,0b10110001,0b11100110,0b10001001,0b11011011,0b00111000,0b00110010,0b11100101,0b00101011,0b10000110,0b00100110,0b01010010,0b10110001,0b01100110,0b11010001,0b00001011,0b01000101,0b00001100,0b11011001,0b10011110,0b01001110,0b11010001,0b10110011,0b10010010,0b11101110,0b00010001,0b10110110,0b01101000,0b01100101,0b00101011,0b10000111,0b00001000,0b10011011,0b00101010,0b01101010,0b11011001,0b00010011,0b10000101,0b01001110,0b01011100,0b00100000,0b01100110,0b10000001,0b10100010,0b00000110,0b11001000,0b00011010,0b00110100,0b01100110,0b11010001,0b10100010,0b10000110,0b01101101,0b10011011,0b00110100,0b01100110,0b11000101,0b00111011,0b00110110,0b10001101,0b00011001,0b10110110,0b01100110,0b10101001,0b10001011,0b01100111,0b00001110,0b01011101,0b10110100,0b01101000,0b11001101,0b10100011,0b01000101,0b00001100,0b11011011,0b00110110,0b01101000,0b11001101,0b10100010,0b10000110,0b11001110,0b00011100,0b10111000,0b01101100,0b11010001,0b01000011,0b01100111,0b00001000,0b00011100,0b00100000,0b01110100,0b10000001,0b11100010,0b00000110,0b00101000,0b00011010,0b00100000,0b01101100,0b01111001,0b10100010,0b01010110,0b11001101,0b10011011,0b00111011,0b01110010,0b11100001,0b10110010,0b00110111,0b00001011,0b00010001,0b10111000,0b01000000,0b11101101,0b00000011,0b11010011,0b11001101,0b10010010,0b10110100,0b01100110,0b11001101,0b10001011,0b00110110,0b11001101,0b00010001,0b10110100,0b01011000,0b10001101,0b10001010,0b00000110,0b10001000,0b00011011,0b00011110,0b01101000,0b10011101,0b10110011,0b01100110,0b11001110,0b11011100,0b10111000,0b01101100,0b10001101,0b11000010,0b11000100,0b01101110,0b00010000,0b00111011,0b01000000,0b11110100,0b11110011,0b01100100,0b10101101,0b00011101,0b10111011,0b01110000,0b11101101,0b11011010,0b00000111,0b10101010,0b00010000,0b00110001,0b01000000,0b11010001,0b00000011,0b01100011,0b11001101,0b00010011,0b10110110,0b01101100,0b11011001,0b11011011,0b10010111,0b00001101,0b10010001,0b10111000,0b01011000,0b10001101,0b11000010,0b00000111,0b01101000,0b00011110,0b10011110,0b01101100,0b10010101,0b10100011,0b10110111,0b01101110,0b00011101,0b10111011,0b0111101
};
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */

const int songSize = (sizeof(hexMap_SX) / sizeof(hexMap_SX[0])) * 8;        // 1 bit => 1 note
const byte noteDuration = 70;

// AUDIO DEVICES SETUP
Tone AUDIO_DX;
Tone AUDIO_SX;

void setup() {                                                              // Run once
  AUDIO_DX.begin(2);
  AUDIO_SX.begin(3);
}

void loop() {                                                               // Run playMelody() repeateadly
  // Init / Reset variables
  int hexNotesIndex_DX = -1;                                                // First mask_1 is 0x00, so with index = 0 you would skip a note
  byte mask_1_DX = 0xff;                                                    // Setup masks before the bitwise NOT and SHIFT
  byte mask_2_DX = 0xff;
  byte shift_DX = 7;

  int hexNotesIndex_SX = -1;
  byte mask_1_SX = 0xff;
  byte mask_2_SX = 0xff;
  byte shift_SX = 7;

  int i = 0;
  while (i < songSize) {
    if(AUDIO_SX.isPlaying()) continue;                                      // If there's already a note playing, loop and try again
    
    // AUDIO is not playing, hence a note play or pause will happen now
    const byte hexMapIndex = i / 8;                                         // Index of the 8-bit chunk to check
    const byte hexMapBitIndex = 7 - (i % 8);                                // Index of the bit (0 - 7) to check
    const byte isNote_DX = bitRead(hexMap_DX[hexMapIndex], hexMapBitIndex); // Read bit value - 0=pause - 1=note
    const byte isNote_SX = bitRead(hexMap_SX[hexMapIndex], hexMapBitIndex); // Example: i = 5, number 0, 6th bit
    i++;                                                                    // Next not playing audio loop, read next hexMap bit and next hexNote chunk / pause

    if (!isNote_DX && !isNote_SX) delay(noteDuration);                      // Check if there is something to play - if there's not, pause note
    else {                                                                  // If there is, check individually each side
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
        // const byte intNoteIndex_DX = ((pgm_read_byte(&hexNotes_DX[hexNotesIndex_DX]) & mask_1_DX) << shift_DX ) | ((pgm_read_byte(&hexNotes_DX[hexNotesIndex_DX + 1]) & mask_2_DX) >> (8 - shift_DX));
        const byte intNoteIndex_DX = ((buffer[0] & mask_1_DX) << shift_DX ) | ((buffer[1] & mask_2_DX) >> (8 - shift_DX));
        shift_DX--;                                                         // Decrement shift  (will reset to 7 when 0 aka when mask==_2  0x00)
        hexNotesIndex_DX++;                                                 // Increment notes index (next play, grab next note... remember if(mask_2_DX == 0x00) => hexNotesInedx_DX--)

        AUDIO_DX.play(notes[intNoteIndex_DX], noteDuration);                // Finally - Actual note play :D
      }
      
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
    } // end play note
  } // end while
} // end loop
