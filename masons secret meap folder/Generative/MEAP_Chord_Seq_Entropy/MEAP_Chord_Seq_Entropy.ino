/*
  Example that generates baroque-style chord progressions in the key of C major

  Pot #1 Control attack time of envelope
  Pot #2 Controls entropy amount

  Mason Mann, CC0
 */

#include <MozziGuts.h>
#include <Oscil.h>
#include <mozzi_rand.h>
#include <mozzi_midi.h>
#include <Mux.h>
#include <tables/triangle_warm8192_int8.h>
#include <EventDelay.h>
#include <Ead.h>

#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable

using namespace admux;

// variables for DIP switches
Mux mux(Pin(34, INPUT, PinType::Digital), Pinset(16, 17, 12));
int dipPins[] = {5, 6, 7, 4, 3, 0, 2, 1};
int dipVals[] = {0, 0, 0, 0, 0, 0, 0, 0};
int prevDipVals[] = {0, 0, 0, 0, 0, 0, 0, 0};

// variables for capacitive touch pads
int touchPins[] = {2, 13, 27, 32, 4, 15, 14, 33};
int touchAvgs[] = {100, 100, 100, 100, 100, 100, 100, 100};
int touchVals[] = {0, 0, 0, 0, 0, 0, 0, 0};
int prevTouchVals[] = {0, 0, 0, 0, 0, 0, 0, 0};
int touchThreshold = 20;

// variables for potentiometers
int potVals[] = {0, 0};

Oscil<TRIANGLE_WARM8192_NUM_CELLS, AUDIO_RATE> osc1(TRIANGLE_WARM8192_DATA);
Oscil<TRIANGLE_WARM8192_NUM_CELLS, AUDIO_RATE> osc2(TRIANGLE_WARM8192_DATA);
Oscil<TRIANGLE_WARM8192_NUM_CELLS, AUDIO_RATE> osc3(TRIANGLE_WARM8192_DATA);
Oscil<TRIANGLE_WARM8192_NUM_CELLS, AUDIO_RATE> osc4(TRIANGLE_WARM8192_DATA);

Ead env1(CONTROL_RATE); // resolution will be CONTROL_RATE
Ead env2(CONTROL_RATE); // resolution will be CONTROL_RATE
Ead env3(CONTROL_RATE); // resolution will be CONTROL_RATE
Ead env4(CONTROL_RATE); // resolution will be CONTROL_RATE

// envelope values
int gain1 = 0;
int gain2 = 0;
int gain3 = 0;
int gain4 = 0;

int majScale[] = {0, 2, 4, 5, 7, 9, 11}; // template for building major scale on top of 12TET
int scaleRoot = 60; // root of major scale

int triad[] = {0, 2, 4}; // template for triad on top of major scale
int chordRoot = 2; // root of triad

EventDelay noteDelay;
int noteLength = 400; // number of milliseconds between notes of arpeggio
int arpCounter = 0; // current note of arpeggio (0->3)

int treeLevel = 4; // what level of chord tree are we on

int entropy = 0; // amount of entropy from 0 to 100

uint16_t myRandom = 0; // variable for raw random number
int myMappedNum = 0; // variable for mapped random number

void setup(){
  Serial.begin(115200);
  pinMode(34, INPUT);
  startMozzi(CONTROL_RATE);

  //set oscillators to pitches of first chord (iii chord on c major scale)
  osc1.setFreq(mtof(scaleRoot + majScale[(triad[0] + chordRoot)%7]));
  osc2.setFreq(mtof(scaleRoot + majScale[(triad[1] + chordRoot)%7]));
  osc3.setFreq(mtof(scaleRoot + majScale[(triad[2] + chordRoot)%7]));
  osc4.setFreq(2 * mtof(scaleRoot + majScale[(triad[0] + chordRoot)%7]));

  setAtkDec(10, 1000); // sets all envelopes at once, function defined at bottom of code

  noteDelay.start(noteLength); //start first note timer

  randomSeed(10); // initializes random number generator
  xorshiftSeed((long)random(1000));
}


void loop(){
  audioHook();
}


void updateControl(){
  readPots(); // reads potentiometers


  
  entropy = map(potVals[1], 0, 4095, 0, 100); // pot #2 controls amount of entropy, which chooses order of notes in arpeggio

  if(noteDelay.ready()){ // if it is time to play the next note
    myRandom = xorshift96();
    int myEntropy = map(myRandom, 0, 65535, 0, 100); // decide if we should have a random attack time
    myRandom = xorshift96();
    int myDecay = map(myRandom, 0, 65535, 10, 2000); // decide if we should have a random attack time
    if (myEntropy < entropy){
      setAtkDec(map(myEntropy, 0, 100, 10, 2000), myDecay); // pot #1 controls attack time of envelope
    } else{
      setAtkDec(map(potVals[0], 0, 4095, 10, 2000), 2000); // pot #1 controls attack time of envelope
    }

    // --------------------WHAT STATE SHOULD WE MOVE TO NEXT?--------------------------------------
    if(arpCounter == 4){ // if we have finished our arpeggio, prepare to move to next chord
      arpCounter = 0;
      if(treeLevel != 0){
        treeLevel = treeLevel - 1; // move one level down the tree
      } else{
        myRandom = xorshift96();
        treeLevel = map(myRandom, 0, 65535, 0, 4); // if already at bottom of tree jump to a random level
      }

      // --------------------WHAT HAPPENS IN EACH STATE?-------------------------------------------
      switch(treeLevel){ // choose chord based on tree level
        case 4: // leaves : iii
          chordRoot = 2; // iii chord (E minor)
          break;
        case 3: // twigs: I or vi
              myRandom = xorshift96();
              myMappedNum = map(myRandom, 0, 65535, 0, 3);
              if (myMappedNum == 0){ // 25% chance of I, 75% chance of vi
                chordRoot = 0; // I chord (C major)
              } else{
                chordRoot = 5; // vi chord (A minor)
              }
          break;
        case 2: // branches: IV or ii
              myRandom = xorshift96();
              myMappedNum = map(myRandom, 0, 65535, 0, 2);
              if (myMappedNum == 0){ // 33% chance of ii, 66% chance off IV
                chordRoot = 1; // ii chord (D minor)
              } else{
                chordRoot = 3; // IV chord (F major)
              }
          break;
        case 1: // boughs: V or vii˚
              myRandom = xorshift96();
              myMappedNum = map(myRandom, 0, 65535, 0, 3);
              if (myMappedNum == 0){ // 25% chance of vii˚, 75% chance of V
                chordRoot = 6; // vii˚ chord (B diminished)
              } else{
                chordRoot = 4; // V chord (G major)
              }
          break;
        case 0: // trunk: I or vi
              myRandom = xorshift96();
              myMappedNum = map(myRandom, 0, 65535, 0, 3);
              if (myMappedNum == 0){ // 25% chance of vi, 75% chance of I
                chordRoot = 5; // vi chord (A minor)
              } else{
                chordRoot = 0; // I chord (C major)
              }
          break;
      }
      osc1.setFreq(mtof(scaleRoot + majScale[(triad[0] + chordRoot)%7])); // root of chord (modded to octave)
      osc2.setFreq(mtof(scaleRoot + majScale[(triad[1] + chordRoot)%7])); // third of chord (modded to octave)
      osc3.setFreq(mtof(scaleRoot + majScale[(triad[2] + chordRoot)%7])); // fifth of chord (modded to octave)
      osc4.setFreq(2 * mtof(scaleRoot + majScale[(triad[0] + chordRoot)%7])); // octave above root
    } else {
    noteDelay.start(noteLength); // set length of note

    // --------------------Handling Arpeggio--------------------
    myRandom = xorshift96();
    myMappedNum = map(myRandom, 0, 65535, 0, 100); // generate random number between 0 and 100
    int myNoteNum = arpCounter; // set note to be triggered equal to note next note in arpeggio
    if (myMappedNum < entropy){ // compare random number to entropy
      myNoteNum = myMappedNum % 4; // if random number is less than entropy value, select a random note from chord to play
    } 
      switch(myNoteNum){
        case 0:
          env1.start();
          break;
        case 1:
          env2.start();
          break;
        case 2:
          env3.start();
          break;
        case 3:
          env4.start();
      }
    arpCounter++; // move on to next note of arpeggio
  }
}

  // --------------------Grab next envelope values--------------------
  gain1 = env1.next();
  gain2 = env2.next();
  gain3 = env3.next();
  gain4 = env4.next();
}


int updateAudio(){
  // adds all four oscillators together and multiplies them by envelope
  // 18 bit because... each gain*osc takes up 16 bits and 4 16 bit number added together fit in 18 bits
  return MonoOutput::fromAlmostNBit(18, gain1 * osc1.next() + gain2 * osc2.next() + gain3 * osc3.next() + gain4 * osc4.next());
}

void readPots(){
  mozziAnalogRead(0);
  potVals[0] = mozziAnalogRead(39);
  
  mozziAnalogRead(1);
  potVals[1] = mozziAnalogRead(36);
}

//Function for setting all four envelopes at once
void setAtkDec(int atk, int dec){
  env1.setAttack(atk);
  env1.setDecay(dec);
  env2.setAttack(atk);
  env2.setDecay(dec);
  env3.setAttack(atk);
  env3.setDecay(dec);
  env4.setAttack(atk);
  env4.setDecay(dec);
}
