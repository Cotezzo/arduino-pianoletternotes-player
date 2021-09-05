const fs = require("fs");

const trad = `
RH:5|--d---------------d-------|
RH:4|dd--a--G-g-f-dfgcc--a--G-g|

RH:5|--------d---------------d-|
RH:4|-f-dfg----a--G-g-f-dfg----|
RH:3|------bb--------------AA--|

RH:5|--------------d-----------|
RH:4|a--G-g-f-dfgdd--a--G-g-f-d|
LH:3|------------d-d-dd-d-d-ddd|

RH:5|----d---------------d-----|
RH:4|fgcc--a--G-g-f-dfg----a--G|
RH:3|------------------bb------|
LH:3|d-c-c-cc-c-c-cccc---------|
LH:2|------------------b-b-bb-b|

RH:5|----------d-------------dd|
RH:4|-g-f-dfg----a--G-g-f-dfgdd|
RH:3|--------AA----------------|
LH:3|---------------c-c-cccc---|
LH:2|-b-bbbb-A-A-AA----------d-|

RH:6|d---------------d---------|
RH:5|d-a--G-g-f-dfgccd-a--G-g-f|
RH:4|--a--G-g-f-dfgcc--a--G-g-f|
LH:3|d---d---d---d---c---c---c-|
LH:2|--dd-d-d-ddd--c---cc-c-c-c|

RH:6|------d---------------d---|
RH:5|-dfg--d-a--G-g-f-dfg--d-a-|
RH:4|-dfgbb--a--G-g-f-dfgAA--a-|
RH:3|----bb--------------AA----|
LH:3|--c-----------------------|
LH:2|cc----b---b---b---b---A---|
LH:1|----b---bb-b-b-bbb--A---AA|

RH:6|------------d-------------|
RH:5|-G-g-f-dfgddd-a--G-g-f-dfg|
RH:4|-G-g-f-dfgdd--a--G-g-f-dfg|
LH:3|----c---c---d---d---d---d-|
LH:2|Ac-c-ccc--d---dd-d-d-ddd--|

RH:6|--d---------------d-------|
RH:5|ccd-a--G-g-f-dfg--d-a--G-g|
RH:4|cc--a--G-g-f-dfgbb--a--G-g|
RH:3|----------------bb--------|
LH:3|--c---c---c---c-----------|
LH:2|c---cc-c-c-ccc----b---b---|
LH:1|----------------b---bb-b-b|

RH:6|--------d-----------------|
RH:5|-f-dfg--d-a--G-g-f-dfgf-ff|
RH:4|-f-dfgAA--a--G-g-f-dfg----|
RH:3|------AA------------------|
LH:3|----------------c---c---d-|
LH:2|b---b---A---Ac-c-ccc--d---|
LH:1|-bbb--A---AA--------------|

RH:5|---------------------gg---|
RH:5|-f-f-d-d----f-ff-g-G-Gfdfg|
LH:3|--d---d---d---c---c---c---|
LH:2|dd-d-d-ddd--c---cc-c-c-ccc|

RH:6|-------------c----d-d-d-dc|
RH:5|--f-ff-g-G-a---a-------a--|
LH:3|c-------------------------|
LH:2|----b---b---b---b---A---Ac|
LH:1|--b---bb-b-b-bbb--A---AA--|

RH:6|----g---------------------|
RH:5|--------f-aa-f-a-d-d----f-|
RH:5|--------a-ff-a-f-g-g----a-|
LH:3|--c---c---d---d---d---d---|
LH:2|-c-ccc--dd--dd-d-g-fddfgcc|
LH:2|------------a--G-d-d------|

RH:6|---------d----d-------c---|
RH:5|af-f-g-a---dc---a-f-------|
RH:5|fa-a-d-f-e-ag-bgdegdfd-dgd|
RH:4|--------------------b---b-|
LH:3|d---d---d---d---d---d---d-|
LH:2|--ac-c-c-ccdfg----a--G-g-f|
LH:2|--c--G-g-f----------------|
LH:1|--------------bb--bb-b-b-b|

RH:6|-----------c--------------|
RH:5|---------d----------------|
RH:5|f-e---cd-f-e--------------|
RH:4|bgbgA--A------------------|
LH:3|--d---d---d---d---d-------|
LH:2|-dfg----a--c-g-fcdfg--A---|
LH:2|-----------G-c-c----------|
LH:1|b---AA--AA----------A---AA|

RH:5|--d-fefgf-Gdf-e-----------|
RH:5|--fddgGeddgfd-g--------G-a|
RH:4|---A-----A----------------|
LH:3|------------c---c---c---c-|
LH:2|A---A---A-c---cc-c-c-ccc--|
LH:1|-A-A-AAA------------------|

RH:6|c-------------c-C---------|
RH:5|--aGgfdef-g-a-----G-Ggfg--|
LH:3|--d---d---d---d---C---C---|
LH:2|d---dd-d-d-ddd--C---CC-D-D|

RH:5|------------d-c-----------|
RH:5|------------f-e---d---e---|
RH:4|------f-e-f-------a---g---|
RH:4|------d-g-a---------------|
LH:3|D---D-------------------c-|
LH:2|-DDD----A---A---A---A-c---|
LH:1|------A---AA-A-A-AAA------|

RH:5|----g-------a-------------|
RH:5|f---c---e---d-------aGgFfe|
RH:4|a-------a-----------------|
LH:3|--c---c---c---d---d---d---|
LH:2|cc-c-c-ccc--d---dd-d-d-ddd|

RH:5|DdC-------D---------------|
RH:4|--G-------A---------------|
LH:3|d---C---C---D---D---------|
LH:2|--C---CC-D-D-DDD----A---A-|
LH:1|------------------A---AA-A|

RH:6|------------------------c-|
RH:5|d-fefgf-gdd-g-------------|
RH:5|fddgGeddGff-e--------G-a--|
RH:4|-A-----A------------------|
LH:3|----------c---c---c---c---|
LH:2|--A---A-c---cc-c-c-ccc--d-|
LH:1|-A-AAA--------------------|

RH:6|------------c-C-----------|
RH:5|aGgfdef-g-a-----G-Ggfg----|
LH:3|d---d---d---d---C---C---D-|
LH:2|--dd-d-d-ddd--C---CC-D-D-D|

RH:5|----------f-e-------------|
RH:5|----------d-c---d---e---f-|
RH:4|----f-e-a-------a---g---a-|
RH:4|----d-g-f-----------------|
LH:3|--D-------------------c---|
LH:2|DD----A---A---A---A-c---cc|
LH:1|----A---AA-A-A-AAA--------|

RH:5|--g-------a---------------|
RH:5|--c---e---d-------aGgFfeDd|
RH:4|------a-------------------|
LH:3|c---c---c---d---d---d---d-|
LH:2|-c-c-ccc--d---dd-d-d-ddd--|

RH:5|C-------D-----------------|
RH:4|G-------A-----------------|
RH:3|----------------A---------|
LH:3|--C---C---D---D-----------|
LH:2|C---CC-D-D-DDD------------|
LH:1|----------------A-A-AA-A-A|

RH:4|--f---e-------d-------f---|
LH:2|------c-c-cc-c-c-cccc-----|
LH:1|-AAAA-----------------b-b-|

LH:1|bb-b-b-bbbb-b-b-bb-b-b-bbb|

RH:4|--------------f---e-------|
RH:3|--A-----------------------|
LH:2|------------------c-c-cc-c|
LH:1|b-A-A-AA-A-A-AAAA---------|

RH:4|d-------d-------dc--------|
RH:4|-----------------C--------|
RH:3|------------------baGFfed-|
RH:3|-------------------A-g-D--|
LH:2|-c-cccc-d-d-dd-d-d-dddd-d-|

RH:4|----------------d---------|
RH:3|--------------dd--a--G-g-f|
RH:3|--------------A-----------|
LH:2|d-dd-d-d-dddd-------------|
LH:1|--------------A-A-AA-A-A-A|

RH:4|f---e-d-----d-------f-d---|
RH:3|-dfgcc--a--G-g-f-dfg----a-|
RH:2|--------------------bb----|
LH:2|----c-c-cc-c-c-cccc-------|
LH:1|AAA-----------------b-b-bb|

RH:4|------------fdg-fcdc-----c|
RH:4|------------d-------------|
RH:3|-G-g-f-dfg-g--a--G-g-f-gfg|
RH:3|---------------------a-da-|
RH:2|----------b---------------|
LH:1|-b-b-bbbb-b-b-bb-b-b-bbbb-|

RH:4|--d---------f---e-d-----d-|
RH:3|Ad--a--G-g-f-dfgcc--a--G-g|
RH:3|d-------------------------|
LH:2|----------------c-c-cc-c-c|
LH:1|A-A-AA-A-A-AAAA-----------|

RH:4|------d-f-e--c-e-d---c--d-|
RH:4|--------d---------------f-|
RH:3|-f-dfgdd--a--G-g-f-dfgdd--|
RH:3|-------------------ga-----|
LH:2|-cccc-d-d-dd-d-d-dddd-d-d-|

RH:4|e--c-e-d---c--------------|
RH:3|a--G-g-f-gfgA-A--f-A-f----|
RH:3|---------da-f-f--A-f-A----|
RH:2|----------------A------AAA|
LH:2|dd-d-d-dddd---A---A---A---|
LH:1|------------A---AA-A-A-AAA|

RH:4|--c-c--c-c-c----c-d-d--d-C|
RH:3|A-g-g-cg-g-g-cccg-a-a-da-G|
RH:3|f-------------------------|
LH:3|----c---c---c---c---d---d-|
LH:2|A-c---cc-c-c-ccc--d---dd-C|

RH:4|-C----C-c-c--c------------|
RH:3|-G-CCCG-g-g-cg-b-b----F-A-|
RH:3|---------------F-F----b-f-|
RH:2|-------------------bbb----|
LH:3|--C---C---c---c-----------|
LH:2|-C-CCC--c---cc----b---b---|
LH:1|---------------b-b-bbb--A-|

RH:4|--------------c-c--c-c-c--|
RH:3|A--f-f-A----f-g-g-cg-g-g-c|
RH:3|f--A-A-f----A-------------|
RH:2|--A------AAA--------------|
LH:3|----------------c---c---c-|
LH:2|A---A---A---A-c---cc-c-c-c|
LH:1|--AA-A-A-AAA--------------|

RH:4|--c-d-d--d-d-d----d-d-d--d|
RH:3|ccg-a-a-da-a-a-ddda-a-a-da|
LH:3|--c---d---d---d---d---d---|
LH:2|cc--d---dd-d-d-ddd--d---dd|

RH:4|-d-d----d-----------------|
RH:3|-a-a-ddda-f-f--f-f-A----A-|
RH:3|----------A-A--A-A-f----f-|
RH:2|--------------A------AAA--|
LH:3|d---d---d-----------------|
LH:2|-d-d-ddd----A---A---A---A-|
LH:1|----------A---AA-A-A-AAA--|

RH:4|c-c--c-c-c----c-d-d--d-C-C|
RH:3|g-g-cg-g-g-cccg-a-a-da-G-G|
LH:3|--c---c---c---c---d---d---|
LH:2|c---cc-c-c-ccc--d---dd-C-C|

RH:4|----C-c-c--c--------------|
RH:3|-CCCG-g-g-cg-b-b----F-A-A-|
RH:3|-------------F-F----b-f-f-|
RH:2|-----------------bbb------|
LH:3|C---C---c---c-------------|
LH:2|-CCC--c---cc----b---b---A-|
LH:1|-------------b-b-bbb--A---|

RH:4|------------c-c--c-c-c----|
RH:3|-f-f-A----f-g-g-cg-g-g-ccc|
RH:3|-A-A-f----A---------------|
RH:2|A------AAA----------------|
LH:3|--------------c---c---c---|
LH:2|--A---A---A-c---cc-c-c-ccc|
LH:1|AA-A-A-AAA----------------|

RH:4|c-d-d--d-d-d----d-d-d--d-d|
RH:3|g-dd--a--G-g-f-dfgdd--a--G|
LH:3|c---d---d---d---d---d---d-|
LH:2|--d---dd-d-d-ddd--d---dd-d|

RH:5|----------d---------------|
RH:4|-d----d-----a--G-g-f-dfgcc|
RH:3|-g-f-dfgAA----------------|
LH:3|--d---d-------------------|
LH:2|-d-ddd--------------------|

RH:5|d---------------d---------|
RH:4|--a--G-g-f-dfgdd--a--G-g-f|

RH:5|------d---------------d---|
RH:4|-dfgdd--a--G-g-f-dfg----a-|
RH:3|--------------------AA----|

RH:5|------------d-------------|
RH:4|-G-g-f-dfgcc--a--G-g-f-dfg|

RH:5|--d---------------d-------|
RH:4|dd--a--G-g-f-dfgcc--a--G-g|

RH:5|--------d---------------d-|
RH:4|-f-dfg----a--G-g-f-dfg----|
RH:3|------bb--------------AA--|

RH:4|a--G-g-f-dfg--------------|
`;


// ----------------------------------------------------------------------------------------------------------------------------------------------------------
const noteValues = [
    "B0", "C1", "CS1", "D1", "DS1", "E1", "F1", "FS1", "G1", "GS1", "A1", "AS1", "B1", "C2", "CS2", "D2", "DS2", "E2", "F2", "FS2", "G2", "GS2", "A2", "AS2",
    "B2", "C3", "CS3", "D3", "DS3", "E3", "F3", "FS3", "G3", "GS3", "A3", "AS3", "B3", "C4", "CS4", "D4", "DS4", "E4", "F4", "FS4", "G4", "GS4", "A4", "AS4",
    "B4", "C5", "CS5", "D5", "DS5", "E5", "F5", "FS5", "G5", "GS5", "A5", "AS5", "B5", "C6", "CS6", "D6", "DS6", "E6", "F6", "FS6", "G6", "GS6", "A6", "AS6",
    "B6", "C7", "CS7", "D7", "DS7", "E7", "F7", "FS7", "G7", "GS7", "A7", "AS7", "B7", "C8", "CS8", "D8", "DS8"
];

const normalizeLetter = (char) => {
    const upChar = char.toUpperCase();
    return (char == upChar) ? (char + "S") : upChar;
}

const lines = trad.replace(/(LH:)|(RH:)/g, "").split("\n\n").map(el => el.replace(/\n/g, ""));

const f = [];
for(const line of lines){
    const t = line.split(/\|/);

    const arr = [];
    for(let i = 0; i < (t.length-1)/2; i++){
        arr.push([]);
        const str = t[i*2+1]
        for(let j = 0; j < 26; j++)
            arr[i].push(str.charAt(j) == "-" ? 0 : (noteValues.indexOf(normalizeLetter(str.charAt(j)) + t[i*2])));
    }
    f.push(arr);
}

const layers = [];
const mapLayers = [];
const notesLayers = [];

const nOfLayers = 2;
for(let i = 0; i<nOfLayers; i++){
    layers.push([]);
    mapLayers.push([]);
    notesLayers.push([]);
}

for(const line of f){
    // line: chunk between 2 \n

    const s = [];
    var n = 1;

    for(let i = 0; i < 26; i++)
        for(let j = 0; j < line.length; j++)
            for(let l = 0; l < n; l++){
                if(!s[l]) s[l] = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ];
                
                if(!s[l][i]){
                    s[l][i] = line[j][i];
                    break;
                }
                
                if(l+1 == n) n++;
            }

    for(let i = 0; i < nOfLayers; i++)
        layers[i].push(...s[i] ?? [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]);
}

const hexify = (bitMap) =>
    JSON.stringify(
        bitMap
        .match(/.{1,8}/g)
        .map(el => {
            const a = parseInt(el, 2).toString(16);
            return "0x" + ("0".repeat(2-a.length)) + a;
        })
    )
    .replace(/"/g, "").replace("[", "{\n")
    .replace("]", "\n};")
    .replace(/-/g, "0");

// Layers has all the notes, now begins memory optimization with a bit map
const temp = [];
for(let n = 0; n < nOfLayers; n++){

    var bitNotes = "";
    var bitMap = "";

    for(let i = 0; i<layers[n].length; i++){
        const note = layers[n][i];

        bitMap += note ? "1" : "0";

        if(note){
            const a = note.toString(2);
            bitNotes += "0".repeat(7-a.length) + a;
        }

    }
    
    if(!bitNotes || !bitMap) continue;
    const a = hexify(bitMap);
    const b = hexify(bitNotes);
    temp.push(a, b);
    fs.writeFileSync(`./maps/hexMap_${n ? "DX" : "SX"}`, a);
    fs.writeFileSync(`./notes/hexNotes_${n ? "DX" : "SX"}`, b);
}

fs.writeFileSync(`./finito`, `
#include <Tone.h>

const int notes[] = {                                                         // Notes pool - int frequency values (declared in Tone.h)
  NOTE_B0, NOTE_C1, NOTE_CS1, NOTE_D1, NOTE_DS1, NOTE_E1, NOTE_F1, NOTE_FS1, NOTE_G1, NOTE_GS1, NOTE_A1, NOTE_AS1, NOTE_B1, NOTE_C2, NOTE_CS2, NOTE_D2, NOTE_DS2, NOTE_E2, NOTE_F2, NOTE_FS2, NOTE_G2, NOTE_GS2, NOTE_A2, NOTE_AS2,
  NOTE_B2, NOTE_C3, NOTE_CS3, NOTE_D3, NOTE_DS3, NOTE_E3, NOTE_F3, NOTE_FS3, NOTE_G3, NOTE_GS3, NOTE_A3, NOTE_AS3, NOTE_B3, NOTE_C4, NOTE_CS4, NOTE_D4, NOTE_DS4, NOTE_E4, NOTE_F4, NOTE_FS4, NOTE_G4, NOTE_GS4, NOTE_A4, NOTE_AS4,
  NOTE_B4, NOTE_C5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_E5, NOTE_F5, NOTE_FS5, NOTE_G5, NOTE_GS5, NOTE_A5, NOTE_AS5, NOTE_B5, NOTE_C6, NOTE_CS6, NOTE_D6, NOTE_DS6, NOTE_E6, NOTE_F6, NOTE_FS6, NOTE_G6, NOTE_GS6, NOTE_A6, NOTE_AS6,
  NOTE_B6, NOTE_C7, NOTE_CS7, NOTE_D7, NOTE_DS7, NOTE_E7, NOTE_F7, NOTE_FS7, NOTE_G7, NOTE_GS7, NOTE_A7, NOTE_AS7, NOTE_B7, NOTE_C8, NOTE_CS8, NOTE_D8, NOTE_DS8
};

/* ---- ACTUAL MELODY ----------------------------------------------------------------------------------------------------------------------------------------------------------------- */
const uint8_t hexMap_SX[] = ${temp[0]}

const uint8_t hexMap_DX[] = ${temp[2]}

const uint8_t PROGMEM hexNotes_SX[] = ${temp[1]}

const uint8_t PROGMEM hexNotes_DX[] = ${temp[3]}

const byte noteDuration = 115;
/* ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ */

const int songSize = (sizeof(hexMap_SX) / sizeof(hexMap_SX[0])) * 8;        // 1 bit => 1 note

// AUDIO DEVICES SETUP
Tone AUDIO_SX;
Tone AUDIO_DX;

void setup() {                                                              // Run once
  AUDIO_SX.begin(3);                                                        // Put the dominant AUDIO first
  AUDIO_DX.begin(2);
}

void loop() {                                                               // Run playMelody() repeateadly
  // Init / Reset variables
  int hexNotesIndex_SX = -1;
  byte mask_1_SX = 0xff;
  byte mask_2_SX = 0xff;
  byte shift_SX = 7;
  
  int hexNotesIndex_DX = -1;                                                // First mask_1 is 0x00, so with index = 0 you would skip a note
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
    
    // For saving hexMaps in PROGMEM
    // const byte isNote_SX = bitRead(pgm_read_byte(&hexMap_SX[hexMapIndex]), hexMapBitIndex);
    // const byte isNote_DX = bitRead(pgm_read_byte(&hexMap_DX[hexMapIndex]), hexMapBitIndex);

    if (!isNote_DX && !isNote_SX) delay(noteDuration);                      // Check if there is something to play - if there's not, pause note
    else {                                                                  // If there is, check individually each side
      // Make a for instead of double code? Maybe with a third piezo...
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
        // const byte intNoteIndex_DX = ((pgm_read_byte(&hexNotes_DX[hexNotesIndex_DX]) & mask_1_DX) << shift_DX ) | ((pgm_read_byte(&hexNotes_DX[hexNotesIndex_DX + 1]) & mask_2_DX) >> (8 - shift_DX));
        const byte intNoteIndex_DX = ((buffer[0] & mask_1_DX) << shift_DX ) | ((buffer[1] & mask_2_DX) >> (8 - shift_DX));
        shift_DX--;                                                         // Decrement shift  (will reset to 7 when 0 aka when mask==_2  0x00)
        hexNotesIndex_DX++;                                                 // Increment notes index (next play, grab next note... remember if(mask_2_DX == 0x00) => hexNotesInedx_DX--)

        AUDIO_DX.play(notes[intNoteIndex_DX], noteDuration);                // Finally - Actual note play :D
      }
    } // end play note
  } // end while
} // end loop
`);