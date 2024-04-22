/*
  Example that tests the basic harware setup of a M.E.A.P. board.
  
  Plays a constant sine wave at 440Hz and prints to the console 
  whenever a DIP switch or capacitive touch input is pressed.

  Mason Mann, CC0
 */

#include <MozziGuts.h>
#include <Oscil.h>
#include <mozzi_midi.h>
#include <Meap.h>
#include <tables/saw8192_int8.h>  // loads saw wavetable
#include <tables/triangle_warm8192_int8.h>  // loads sine wavetable
#include <LinkedList.h>
#include 

#define CONTROL_RATE 128  // Hz, powers of 2 are most reliable
#define POLYPHONY 4

int button_pins[6] = { 15, 16, 12, 13, 18, 35 };
int button_vals[6] = { 0, 0, 0, 0, 0, 0 };
int last_button_vals[6] = { 0, 0, 0, 0, 0, 0 };

Meap meap;

// Oscil<8192, AUDIO_RATE> my_sine(SIN8192_DATA);

Oscil<8192, AUDIO_RATE> saw_bank1[POLYPHONY];
Oscil<8192, AUDIO_RATE> saw_bank2[POLYPHONY];

Oscil<8192, CONTROL_RATE> pitch_lfo(TRIANGLE_WARM8192_DATA);
Oscil<8192, CONTROL_RATE> phaser_lfo(TRIANGLE_WARM8192_DATA);

AudioDelay<512, int> delay_line;
int delay_samples;

ADSR<AUDIO_RATE, AUDIO_RATE> envelopes[POLYPHONY];
int gains[POLYPHONY];
bool voice_free[POLYPHONY];

MultiResonantFilter<uint8_t> filter; /**< Filter for left channel */
int cutoff = 255;
int resonance = 127;

uint32_t detune = 0;

int ensemble_mix = 0;


/**
* Keeps track of a single note turned on by a midi message
*/
class MidiNoteVoice {
public:
  int note_num;    /**< MIDI note number */
  int voice_num;   /**< Num of sample voice sounding this note */
  float frequency; /**< Frequency of note, used for portamento */
};

LinkedList<MidiNoteVoice *> voiceQueue = LinkedList<MidiNoteVoice *>();

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI); /**< MEAP hardware serial port*/

void setup() {
  Serial.begin(115200);                      // begins Serial communication with computer
  Serial1.begin(31250, SERIAL_8N1, 43, 44);  // sets up MIDI: baud rate, serial mode, rx pin, tx pin
  startMozzi(CONTROL_RATE);                  // starts Mozzi engine with control rate defined above
  meap.begin();

  // set up the oscillators
  for (int i = 0; i < POLYPHONY; i++) {
    saw_bank1[i].setFreq(440);
    saw_bank1[i].setTable(SAW8192_DATA);
    saw_bank2[i].setFreq(440);
    saw_bank2[i].setTable(SAW8192_DATA);
    envelopes[i].setAttackTime(10);
    envelopes[i].setSustainTime(4294967295);  // max value of unsigned 32 bit int,, notes can sustain for arbitrary time limit
    envelopes[i].setReleaseTime(500);
    envelopes[i].setADLevels(255, 255);
    gains[i] = 0;
    voice_free[i] = true;
  }
  phaser_lfo.setFreq(0.63f);
  pitch_lfo.setFreq(0.63f);

  for (int i = 0; i < 6; i++) {
    pinMode(button_pins[i], INPUT_PULLUP);
  }
}


void loop() {
  audioHook();
  if (MIDI.read())  // Is there a MIDI message incoming ?
  {
    midiEventHandler();
  }
}


void updateControl() {
  meap.readPots();
  meap.readTouch();
  meap.readDip();
  meap.readAuxMux();
  updateButtons();

  int attack_time = meap.aux_mux_vals[5] >> 2;
  int release_time = meap.aux_mux_vals[7] >> 2;

  for (int i = 0; i < POLYPHONY; i++) {
    envelopes[i].setAttackTime(attack_time);
    envelopes[i].setReleaseTime(release_time);
  }

  cutoff = meap.aux_mux_vals[4] >> 4;  // have 12want 8
  filter.setCutoffFreq(cutoff);

  resonance = meap.aux_mux_vals[6] >> 4;
  filter.setResonance(resonance);

  detune = meap.pot_vals[1] >> 5;  // gets us to 8bit

  int queue_size = voiceQueue.size();
  if (queue_size > 0) {
    MidiNoteVoice *myNote;
    for (int i = 0; i < queue_size; i++) {
      myNote = voiceQueue.get(i);
      int my_voice_num = myNote->voice_num;
      float my_freq = myNote->frequency;
      float my_detune_freq = my_freq + (my_freq / 50) * detune / 127.0;
      saw_bank2[my_voice_num].setFreq(my_detune_freq);
    }
  }
  float phaser_freq = (float)meap.pot_vals[0] / 512.f;
  phaser_lfo.setFreq(phaser_freq);

  delay_samples = (128 + phaser_lfo.next());

  ensemble_mix = meap.aux_mux_vals[3] >> 4; // 256
}


AudioOutput_t updateAudio() {
  int sample = 0;

  for (int i = 0; i < POLYPHONY; i++) {
    envelopes[i].update();
    gains[i] = envelopes[i].next();
    sample += (saw_bank1[i].next() + saw_bank2[i].next()) * gains[i];
  }

  filter.next(sample);
  sample = filter.low();

  int downsample = 11;
  int sample_to8bit = sample >> downsample;
  int phaser_sample = delay_line.next(sample_to8bit, delay_samples) << downsample;
  phaser_sample = (phaser_sample * ensemble_mix) >> 8;
  sample = sample + phaser_sample;
  return StereoOutput::fromAlmostNBit(20, sample, sample);
}

void Meap::updateTouch(int number, bool pressed) {
  switch (number) {
    case 0:
      if (pressed) {  // Pad 1 pressed
        envelopes[0].noteOn();
        saw_bank1[0].setFreq(440);
        saw_bank2[0].setFreq(442);
      } else {  // Pad 1 released
        envelopes[0].noteOff();
      }
      break;
    case 1:
      if (pressed) {  // Pad 2 pressed
        envelopes[1].noteOn();
        saw_bank1[1].setFreq(494);
        saw_bank2[1].setFreq(496);
      } else {  // Pad 2 released
        envelopes[1].noteOff();
      }
      break;
    case 2:
      if (pressed) {  // Pad 3 pressed
      } else {        // Pad 3 released
      }
      break;
    case 3:
      if (pressed) {  // Pad 4 pressed
      } else {        // Pad 4 released
      }
      break;
    case 4:
      if (pressed) {  // Pad 5 pressed
      } else {        // Pad 5 released
      }
      break;
    case 5:
      if (pressed) {  // Pad 6 pressed
      } else {        // Pad 6 released
      }
      break;
    case 6:
      if (pressed) {  // Pad 7 pressed
      } else {        // Pad 7 released
      }
      break;
    case 7:
      if (pressed) {  // Pad 8 pressed
      } else {        // Pad 8 released
      }
      break;
  }
}

void Meap::updateDip(int number, bool up) {
  switch (number) {
    case 0:
      if (up) {  // DIP 1 up
      } else {   // DIP 1 down
      }
      break;
    case 1:
      if (up) {  // DIP 2 up
      } else {   // DIP 2 down
      }
      break;
    case 2:
      if (up) {  // DIP 3 up
      } else {   // DIP 3 down
      }
      break;
    case 3:
      if (up) {  // DIP 4 up
      } else {   // DIP 4 down
      }
      break;
    case 4:
      if (up) {  // DIP 5 up
      } else {   // DIP 5 down
      }
      break;
    case 5:
      if (up) {  // DIP 6 up
      } else {   // DIP 6 down
      }
      break;
    case 6:
      if (up) {  // DIP 7 up
      } else {   // DIP 7 down
      }
      break;
    case 7:
      if (up) {  // DIP 8 up
      } else {   // DIP 8 down
      }
      break;
  }
}

void updateButtons() {

  for (int i = 0; i < 6; i++) {
    // Read the buttons
    button_vals[i] = digitalRead(button_pins[i]);
    // Check if state has changed
    if (button_vals[i] != last_button_vals[i]) {
      switch (i) {
        case 0:
          if (button_vals[i]) {  // button 0 pressed
          } else {               // button 0 released
          }
          break;
        case 1:
          if (button_vals[i]) {  // button 1 pressed
          } else {               // button 1 released
          }
          break;
        case 2:
          if (button_vals[i]) {  // button 2 pressed
          } else {               // button 2 released
          }
          break;
        case 3:
          if (button_vals[i]) {  // button 3 pressed
          } else {               // button 3 released
          }
          break;
        case 4:
          if (button_vals[i]) {  // button 4 pressed
          } else {               // button 4 released
          }
          break;
        case 5:
          if (button_vals[i]) {  // button 5 pressed
          } else {               // button 5 released
          }
          break;
      }
    }
    last_button_vals[i] = button_vals[i];
  }
}


/**
* @brief To be called whenever a midi event is recieved.
*/
void midiEventHandler() {
  int channel = -1;
  int data1 = -1;
  int data2 = -1;
  switch (MIDI.getType())  // Get the type of the message we caught
  {
    case midi::NoteOn:  // ---------- MIDI NOTE ON RECEIVED ----------
      channel = MIDI.getChannel();
      data1 = MIDI.getData1();  // note
      data2 = MIDI.getData2();  // velocity
      noteOnHandler(data1, data2, channel);
      break;
    case midi::NoteOff:  // ---------- MIDI NOTE OFF RECEIVED ----------
      channel = MIDI.getChannel();
      data1 = MIDI.getData1();  // note
      noteOffHandler(data1, channel);
      break;
  }
}

/**
* @brief Handles turning on sample notes.
*
* @param note is the MIDI note number to turn on
* @param velocity is the velocity of the MIDI note to turn on (NOT CURRENTLY USED)
* @param channel is the velocity of the MIDI note to turn on (NOT CURRENTLY USED)
*/
void noteOnHandler(int note, int velocity, int channel) {
  int voice_num = -1;
  // find a free voice
  for (int i = 0; i < POLYPHONY; i++) {
    if (voice_free[i]) {
      voice_free[i] = false;
      voice_num = i;
      break;
    }
  }

  if (voice_num == -1) {  // if no voices free, override the most distantly pressed note
    MidiNoteVoice *myNote;
    myNote = voiceQueue[0];
    voice_num = myNote->voice_num;
  }

  float voice_freq = mtof(note);
  saw_bank1[voice_num].setFreq(voice_freq);
  saw_bank2[voice_num].setFreq(voice_freq + 2);
  envelopes[voice_num].noteOn();
  // keep track of note in active notes queue
  MidiNoteVoice *myNote = new MidiNoteVoice();  // create object to keep track of note num, voice num and freq
  myNote->note_num = note;
  myNote->voice_num = voice_num;
  myNote->frequency = voice_freq;
  voiceQueue.add(myNote);
}

/**
* @brief Handles turning off sample notes.
*
* @param note is the MIDI note number to turn off
* @param channel is the MIDI channel of the note to turn off
*/
void noteOffHandler(int note, int channel) {
  int queue_size = voiceQueue.size();
  if (queue_size > 0) {
    MidiNoteVoice *myNote;
    // loop through voice queue searching for note
    for (int i = 0; i < queue_size; i++) {
      myNote = voiceQueue.get(i);
      if (note == myNote->note_num) {
        envelopes[myNote->voice_num].noteOff();  // turn off note
        voice_free[myNote->voice_num] = true;    // free up voice
        delete (voiceQueue.get(i));
        voiceQueue.remove(i);
        return;
      }
    }
  }
}