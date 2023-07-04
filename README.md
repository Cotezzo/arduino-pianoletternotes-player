# arduino-pianoletternotes-player

## Import and parse a song
First of all, choose a song from [pianoletternotes](https://pianoletternotes.blogspot.com/). Copy the whole "music sheet" into the javascript script (`js/index.js`) and run it with `node ./js/index.js`:

```
// Put here the sheet - the letter notes
const trad = "
RH:5|------------------------c-|
RH:4|---c--e--a--b--e--c--b----|
LH:3|a-----------G-----------g-|

RH:5|-------c------------------|
RH:4|-e--c-----F--d-----F--e--c|
RH:3|----------------a---------|
LH:3|----------F-----------f---|
";
```

The script will produce a piece of .ino code for our firmware that stores the melody we imported in a set of N constant arrays, where N is the number of contemporary tracks (piezos) your circuit supports. The output can be found in `js/output/final`.

The script is "optimized" to use as few tracks as possible (if more notes have to be played at the same time, and the number exceeds the number of tracks, only the sharpest are kept).


## Generate Arduino firmware and play
Once the song is ready to be used, the output can be copy-pasted into the `arduino-firmware/arduino-firmware.ino` file, before compiling it and writing it onto the board.

```
// Map: Values that tell the program when to play and when to pause, reading a bit when a note/pause finishes
// Notes: Compressed ordered list of every note (no pauses)
// Notes are 7-bits numbers representing actual note indexes (notes[]) compressed in 8-bit values but read sequentially with bit shifting
const byte PROGMEM hexMap_0[] = { 0x92,0x49,0x24 };
const byte PROGMEM hexMap_1[] = { 0x00,0x08,0x00 };

const byte PROGMEM hexNotes_0[] = { 0x44,0x95,0x4a,0xe6,0x0a,0x52,0xb0,0x62,0xa5,0x2b,0x15,0x69,0xd1,0x2b,0x52,0x95,0x12,0x55,0x29,0x51,0x27,0x4a,0x94,0xb1 };
const byte PROGMEM hexNotes_1[] = { 0x42,0x80,0xf9,0xe4,0x0a,0x54,0xa1,0x40,0x7c,0xf2,0x05,0x2a,0x58,0xb3,0x74,0xd5,0x9b,0x16,0x6e,0x19,0xb3,0x56,0xcd,0x9b };

const byte * const PROGMEM song[] = { hexMap_0, hexNotes_0, hexMap_1, hexNotes_1 };

const byte noteDuration = 120;                                                  // Duration of every note / pause
```

Increasing the `noteDuration` value (note duration in milliseconds) results in a slower melody, and vice-versa.

Load the firmware onto the Arduino, plug it in the circuit and you're good to go!
