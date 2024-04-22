/*
 Demonstrates filtering of white noise

 Pot 0 controls cutoff
 Pot 1 controls resonance

 Pressing Pad 1 will change filter response to lowpass
 Pressing Pad 2 will change filter response to highpass
 Pressing Pad 3 will change filter response to bandpass
 Pressing Pad 4 will change filter response to notch

  Mason Mann, CC0
 */

#include <Meap.h>                        // MEAP library, includes all dependent libraries, including all Mozzi modules
#include <tables/sin8192_int8.h>         // loads sine wavetable
#include <tables/whitenoise8192_int8.h>  // loads white noise wavetable

#define CONTROL_RATE 64   // Hz, powers of 2 are most reliable
#define AUDIO_RATE 32768  // Hz, powers of 2 are most reliable

Meap meap;  // creates MEAP object to handle inputs and other MEAP library functions

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);  // defines MIDI in/out ports


Oscil<WHITENOISE8192_NUM_CELLS, AUDIO_RATE> white_noise(WHITENOISE8192_DATA);

MultiResonantFilter<uint8_t> filter;  // Multifilter applied to an 8-bit signal.
enum types { lowpass,
             bandpass,
             highpass,
             notch };
int filter_type = 0;

void setup() {
  Serial.begin(115200);                      // begins Serial communication with computer
  Serial1.begin(31250, SERIAL_8N1, 43, 44);  // sets up MIDI: baud rate, serial mode, rx pin, tx pin
  startMozzi(CONTROL_RATE);                  // starts Mozzi engine with control rate defined above
  meap.begin();

  white_noise.setFreq(1);
}


void loop() {
  audioHook();
}


void updateControl() {
  meap.readPots();   // Reads on-board MEAP potentionmeters, results are accessed using meap.pot_vals[0] and meap.pot_vals[1]
  meap.readTouch();  // reads MEAP capacitive touch breakout
  meap.readDip();    // reads on-board MEAP dip switches
  int cutoff = map(meap.pot_vals[0], 0, 4095, 0, 255);
  int resonance = map(meap.pot_vals[1], 0, 4095, 0, 255);
  filter.setCutoffFreqAndResonance(cutoff, resonance);
}


AudioOutput_t updateAudio() {
  int sig;
  filter.next(white_noise.next());
  switch (filter_type)  // recover the output from the current selected filter type.
  {
    case lowpass:
      sig = filter.low();  // lowpassed sample
      break;
    case highpass:
      sig = filter.high();  // highpassed sample
      break;
    case bandpass:
      sig = filter.band();  // bandpassed sample
      break;
    case notch:
      sig = filter.notch();  // notched sample
      break;
  }
  return StereoOutput::fromAlmostNBit(11, sig, sig);
}


/** User defined function called whenever a DIP switch is toggled up or down
  @param number is the number of the switch that was toggled up or down: 0-7
  @param up is true if the switch was toggled up, and false if the switch was toggled down
	*/
void Meap::updateDip(int number, bool up) {
  if (up) {  // Any DIP up

  } else {  //Any DIP down
  }
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

/** User defined function called whenever a touch pad is pressed or released
  @param number is the number of the pad that was pressed or released: 0-7
  @param pressed is true if the pad was pressed and false if the pad was released
	*/
void Meap::updateTouch(int number, bool pressed) {
  if (pressed) {  // Any pad pressed

  } else {  // Any pad released
  }
  switch (number) {
    case 0:
      if (pressed) {  // Pad 1 pressed
        filter_type = lowpass;
      } else {  // Pad 1 released
      }
      break;
    case 1:
      if (pressed) {  // Pad 2 pressed
        filter_type = highpass;
      } else {  // Pad 2 released
      }
      break;
    case 2:
      if (pressed) {  // Pad 3 pressed
        filter_type = bandpass;
      } else {  // Pad 3 released
      }
      break;
    case 3:
      if (pressed) {  // Pad 4 pressed
        filter_type = notch;
      } else {  // Pad 4 released
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