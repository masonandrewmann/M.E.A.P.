/*
  Example plays through sequence on loop. Sequence is 
  defined using variables mySeqNotes and mySeqLens

  Mason Mann, CC0
 */

#include <MozziGuts.h>
#include <Oscil.h>
#include <mozzi_rand.h>
#include <mozzi_midi.h>
#include <Mux.h>
#include <tables/sin8192_int8.h>
#include <EventDelay.h>
#include <Ead.h>

#define CONTROL_RATE 128 // Hz, powers of 2 are most reliable

using namespace admux;

// variables for playing sequence
int mySeqNotes[] = {88, 86, 78, 80, 85, 83, 74, 76, 83, 81, 73, 76, 81}; // notes referred to by MIDI note number
int mySeqLens[] = {250, 250, 500, 500, 250, 250, 500, 500, 250, 250, 500, 500, 1500}; // length of notes in milliseconds
int seqInd = 0;
int seqLen = 13;

int gain;

//oscillator definitions
Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> mySine(SIN8192_DATA);
Ead myEnv(CONTROL_RATE); // resolution will be CONTROL_RATE


EventDelay noteDelay;

// variables for potentiometers
int potVals[] = {0, 0};

void setup(){
  startMozzi(CONTROL_RATE);
  mySine.setFreq(mtof(mySeqNotes[0]));
  noteDelay.start(mySeqLens[0]); // 2 second countdown
  myEnv.setAttack(10);
  myEnv.setDecay(500);
}


void loop(){
  audioHook();
}


void updateControl(){
    readPots(); // reads potentiometers


  if(noteDelay.ready()){
    seqInd = (seqInd + 1) % seqLen; // move to next step of sequence
    mySine.setFreq(mtof(mySeqNotes[seqInd])); // set oscillator frequency to current pitch
    noteDelay.start(mySeqLens[seqInd]); // set ending time of current note
    myEnv.start();
  }
  
  int atkTime = map(potVals[0], 0, 4095, 10, 1000);
  int decTime = map(potVals[1], 0, 4095, 10, 1000);
  myEnv.setAttack(atkTime);
  myEnv.setDecay(decTime);
  gain = myEnv.next();
}


AudioOutput_t updateAudio(){
  return MonoOutput::fromAlmostNBit(16,mySine.next()*gain);
}

void readPots(){
  mozziAnalogRead(0);
  potVals[0] = mozziAnalogRead(39);
  
  mozziAnalogRead(1);
  potVals[1] = mozziAnalogRead(36);
}