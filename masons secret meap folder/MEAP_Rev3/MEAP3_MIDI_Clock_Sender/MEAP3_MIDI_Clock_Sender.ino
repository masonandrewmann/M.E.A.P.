/*
  Example that tests the basic harware setup of a M.E.A.P. board.
  
  Plays a constant sine wave at 440Hz and prints to the console 
  whenever a DIP switch or capacitive touch input is pressed.

  Mason Mann, CC0
 */

#include <MozziGuts.h>
#include <Oscil.h>
#include <mozzi_rand.h>
#include <mozzi_midi.h>
#include <Mux.h>
#include <MIDI.h>
#include <SPI.h>
#include <tables/sin8192_int8.h> // loads sine wavetable

#define CONTROL_RATE 64 // Hz, powers of 2 are most reliable

#define DEBUG 1 // 1 to enable serial prints, 0 to disable

#if DEBUG == 1
#define debug(x) Serial.print(x)
#define debugln(x) Serial.println(x)
#else
#define debug(x)
#define debugln(x)
#endif

using namespace admux;

// variables for DIP switches
Mux mux(Pin(14, INPUT, PinType::Digital), Pinset(38, 45, 46));
int dipPins[] = {5, 6, 7, 4, 3, 0, 2, 1};
int dipVals[] = {0, 0, 0, 0, 0, 0, 0, 0};
int prevDipVals[] = {0, 0, 0, 0, 0, 0, 0, 0};

// variables for capacitive touch pads
int touchPins[] = {2, 4, 6, 8, 1, 3, 5, 7};
int touchAvgs[] = {100, 100, 100, 100, 100, 100, 100, 100};
int touchVals[] = {0, 0, 0, 0, 0, 0, 0, 0};
int prevTouchVals[] = {0, 0, 0, 0, 0, 0, 0, 0};
int touchThreshold = 1000;

// variables for potentiometers
int potVals[] = {0, 0};

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

Oscil<SIN8192_NUM_CELLS, AUDIO_RATE> mySine(SIN8192_DATA);

// MIDI clock timer
uint32_t midi_timer = 0;
uint32_t midi_micros = 100000;
bool start_flag = false;
bool stop_flag = false;

void setup(){
  Serial.begin(115200); // begins Serial communication with computer
  Serial1.begin(31250, SERIAL_8N1, 43, 44); // sets up MIDI: baud rate, serial mode, rx pin, tx pin
  startMozzi(CONTROL_RATE); // starts Mozzi engine with control rate defined above
  touchSetCycles(1, 1); // sets up touch pads
  mySine.setFreq(440); // set frequency of sine oscillator
  midi_micros = midiPulseMicros(240);
  debugln(midi_micros);
}


void loop(){
  audioHook();
  uint32_t t = micros();
  if (t > midi_timer){
    // debugln("t");
    midi_timer = t + midi_micros;

    MIDI.sendRealTime((midi::MidiType)248);
    if(start_flag){
      start_flag = false;
      MIDI.sendStart();
    }
    if(stop_flag){
      stop_flag = false;
      MIDI.sendStop();
    }
    // debugln(midi_micros);
  }
}


void updateControl(){
  readDip(); // reads DIP switches
  readTouch(); // reads capacitive touch pads
  readPots(); // reads potentiometers

  // debug(potVals[0]);
  // debug(" ");
  // debugln(potVals[1]);
}


AudioOutput_t updateAudio(){
  return StereoOutput::from8Bit(0, 0);
}

void readDip(){
  //Read DIP values using mux
  for (int i = 0; i < 8; i++) {
    mux.read(i); //read once and throw away result (for reliability)
    dipVals[dipPins[i]] = !mux.read(i);
  }
  //Check if any switches changed position
  for (int i = 0; i < 8; i++){
    switch(i){
      case 0:
        if (dipVals[i] != prevDipVals[i]){
          if(dipVals[i]){
            debugln("DIP 1 up");
          } else {
            debugln("DIP 1 down");
          }
        }
        break;
      case 1:
        if (dipVals[i] != prevDipVals[i]){
          if(dipVals[i]){
            debugln("DIP 2 up");
          } else {
            debugln("DIP 2 down");
          }
        }
        break;
      case 2:
        if (dipVals[i] != prevDipVals[i]){
          if(dipVals[i]){
            debugln("DIP 3 up");
          } else {
            debugln("DIP 3 down");
          }
        }
        break;
      case 3:
        if (dipVals[i] != prevDipVals[i]){
          if(dipVals[i]){
            debugln("DIP 4 up");
          } else {
            debugln("DIP 4 down");
          }
        }
        break;
      case 4:
        if (dipVals[i] != prevDipVals[i]){
          if(dipVals[i]){
            debugln("DIP 5 up");
          } else {
            debugln("DIP 5 down");
          }
        }
        break;
      case 5:
        if (dipVals[i] != prevDipVals[i]){
          if(dipVals[i]){
            debugln("DIP 6 up");
          } else {
            debugln("DIP 6 down");
          }
        }
        break;
      case 6:
        if (dipVals[i] != prevDipVals[i]){
          if(dipVals[i]){
            debugln("DIP 7 up");
          } else {
            debugln("DIP 7 down");
          }
        }
        break;
      case 7:
        if (dipVals[i] != prevDipVals[i]){
          if(dipVals[i]){
            debugln("DIP 8 up");
          } else {
            debugln("DIP 8 down");
          }
        }
        break;   
    }
    prevDipVals[i] = dipVals[i]; // update prevDipVals array
  }
}

void readTouch(){
  int pinVal = 0;
  for (int i = 0; i < 8; i++){
    pinVal = touchRead(touchPins[i]);  
    touchAvgs[i] = 0.6 * touchAvgs[i] + 0.4 * pinVal; 
    if (touchAvgs[i] > touchThreshold){
      touchVals[i] = 1; 
    } else {
      touchVals[i] = 0;
    }
    if (touchVals[i] != prevTouchVals[i]){
      switch(i){
        case 0:
          if(touchVals[i]){ // pad 0 pressed
            debugln("pad 0 pressed");
            // MIDI.sendStart();
            start_flag = true;
          } else { // pad 0 released
            debugln("pad 0 released");
          }
          break;
        case 1:
          if(touchVals[i]){ // pad 1 pressed
            debugln("pad 1 pressed");
            // MIDI.sendStop();
            stop_flag = true;
          } else { // pad 1 released
            debugln("pad 1 released");
          }
          break;
        case 2:
          if(touchVals[i]){ // pad 2 pressed
            debugln("pad 2 pressed");
            MIDI.sendContinue();
          } else { // pad 2 released
            debugln("pad 2 released");
          }
          break;
        case 3:
          if(touchVals[i]){ // pad 3 pressed
            debugln("pad 3 pressed");
            MIDI.sendRealTime((midi::MidiType)248);
          } else { // pad 3 released
            debugln("pad 3 released");
          }
          break;
        case 4:
          if(touchVals[i]){ // pad 4 pressed
            debugln("pad 4 pressed");
          } else { // pad 4 released
            debugln("pad 4 released");
          }
          break;
        case 5:
          if(touchVals[i]){ // pad 5 pressed
            debugln("pad 5 pressed");
          } else { // pad 5 released
            debugln("pad 5 released");
          }
          break;
        case 6:
          if(touchVals[i]){ // pad 6 pressed
            debugln("pad 6 pressed");
          } else { // pad 6 released
            debugln("pad 6 released");
          }
          break;
        case 7:
          if(touchVals[i]){ // pad 7 pressed
            debugln("pad 7 pressed");
          } else { // pad 7 released
            debugln("pad 7 released");
          }
          break;
      }
    }
    prevTouchVals[i] = touchVals[i];
  }
}

void readPots(){
  potVals[0] = 4095 - mozziAnalogRead(9);
  potVals[1] = 4095 - mozziAnalogRead(10);
}

long irand(long howsmall, long howbig){ // generates a random integer between howsmall and howbig (inclusive of both numbers)
  howbig++;
  if (howsmall >= howbig){
    return howsmall;
  }
  long diff = howbig - howsmall;
  return (xorshift96() % diff) + howsmall;
}

float frand() // generates a random float between 0 and 1 with 4 decimals of precision
{
  return (xorshift96()%10000 / 10000.f);
}

// returns the number of ms in one quarter note given a tempo in BPM
float tempoToPeriod(float tempo){
  return 60000.f / tempo;
}

//returns the number of ms (non rounded) in one MIDI Timing Clock pule given a tempo in bpm
float midiPulseMicros(float tempo){
  return (2500000.f / tempo); // 2500 = 60000ms/24pulses
}
