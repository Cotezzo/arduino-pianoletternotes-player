const fs = require("fs");

// Choose how many layers do you need (the number of tracks you can play simultaneously)
const nOfLayers = 2;

// Put here the sheet - the letter notes
const trad = `
RH:5|------------------------c-|
RH:4|---c--e--a--b--e--c--b----|
LH:3|a-----------G-----------g-|

RH:5|-------c------------------|
RH:4|-e--c-----F--d-----F--e--c|
RH:3|----------------a---------|
LH:3|----------F-----------f---|
`;

/* --------------------------------------------------------------------------------------------- */
//																							     //
// This code is awful and unoptimized. Don't even bother reading it, let alone trying to fix it. //
//																							     //
/* --------------------------------------------------------------------------------------------- */

const noteValues = [
    "B0", "C1", "CS1", "D1", "DS1", "E1", "F1", "FS1", "G1", "GS1", "A1", "AS1", "B1", "C2", "CS2", "D2", "DS2", "E2", "F2", "FS2", "G2", "GS2", "A2", "AS2",
    "B2", "C3", "CS3", "D3", "DS3", "E3", "F3", "FS3", "G3", "GS3", "A3", "AS3", "B3", "C4", "CS4", "D4", "DS4", "E4", "F4", "FS4", "G4", "GS4", "A4", "AS4",
    "B4", "C5", "CS5", "D5", "DS5", "E5", "F5", "FS5", "G5", "GS5", "A5", "AS5", "B5", "C6", "CS6", "D6", "DS6", "E6", "F6", "FS6", "G6", "GS6", "A6", "AS6",
    "B6", "C7", "CS7", "D7", "DS7", "E7", "F7", "FS7", "G7", "GS7", "A7", "AS7", "B7", "C8", "CS8", "D8", "DS8"
];

// Clean output dir
try{
    fs.unlinkSync("js/output/final");
}catch(e){}

const normalizeLetter = char => {
    const upChar = char.toUpperCase();
    return (char == upChar) ? (char + "S") : upChar;
}

// TODO: let LEFT - RIGHT matter

// Remove useless data - for now - and split string in blocks that play together
const lines = trad.replace(/(LH:)|(RH:)/g, "").split("\n\n").map(el => el.replace(/\n/g, ""));

// For every chunk of notes, split it in other chunks (the actual rows that are between pipes), use the number to
// determine the octave and substitute every note with right the noteValues index (the same index that Arduino uses)
const f = [];	// Save here the parsed data
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
	// Beautiful triple for indeed
}

const layers = [];
const mapLayers = [];
const notesLayers = [];

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
                if(!s[l]) s[l] = [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ];	// Default: fill with 0
                
                if(!s[l][i]){
                    s[l][i] = line[j][i];
                    break;
                }
                
                if(l+1 == n) n++;
            }

    for(let i = 0; i < nOfLayers; i++)
        layers[i].push(...s[i] ?? [ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 ]);
}

const hexify = (bitMap, b, n) =>
    JSON.stringify(
        bitMap
        .match(/.{1,8}/g)
        .map(el => {
            const a = parseInt(el, 2).toString(16);
            return "0x" + ("0".repeat(2-a.length)) + a;
        })
    )
    .replace("]", " };")
    .replace(/"/g, "").replace("[", `const byte PROGMEM hex${b ? "Map" : "Notes"}_${n}[] = { `)
    .replace(/-/g, "0");	// There's a bug, somewhere, that can spawn dashes (it actually only happened one time, so idk)... Maybe I'll try to fix it in the future

// Layers has all the notes, now begins memory optimization with a bit map so that the Arduino can store more notes
var maps = "";
var notes= "";
var arrs = "";
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
    // fs.writeFileSync(`js/maps/hexMap_${n}`, hexify(bitMap, 0, n));
    // fs.writeFileSync(`js/notes/hexNotes_${n}`, hexify(bitNotes, 1, n));
    maps += hexify(bitMap, 1, n) + "\n";
    notes += hexify(bitNotes, 0, n) + "\n";
    arrs += `hexMap_${n}, hexNotes_${n}${n+1!=nOfLayers ? ", " : " "}`;
}

const final = `${maps}\n${notes}\nconst byte * const PROGMEM song[] = { ${arrs}};`
fs.writeFileSync(`js/output/final`, final);
