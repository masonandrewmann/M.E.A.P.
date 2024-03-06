#include "samples/piano.h"
#include "samples/C_maj.h"
#include "samples/tpt.h"
#include "samples/glock.h"
#include "samples/gtr.h"
#include "samples/sine.h"
#include "samples/harp.h"
#include "samples/clari.h"
#include "samples/C_aug.h"
#include "samples/C_dim.h"
#include "samples/C_min.h"


// #include "samples/cass_piano.h"
// #include "samples/piano_4C.h"
#include "samples/toy_piano.h"
#include "samples/marimba.h"
// #include "samples/marimba_rev.h"
#include "samples/steel_drum.h"


// #include "samples/organ.h"
// #include "samples/rez_organ.h"
// #include "samples/buzzyOrgan.h"
// #include "samples/org_5th.h"

#include "samples/uke.h"
#include "samples/harp2.h"
#include "samples/tine.h"
#include "samples/lead_gtr.h"

#include "samples/upright_bass.h"
// #include "samples/mono_bass.h"

// #include "samples/shimmer.h"
#include "samples/fantasy.h"
// #include "samples/korg_bow.h"
// #include "samples/lead_synth.h"
// #include "samples/buzzy.h"

// #include "samples/flute.h"
#include "samples/strings.h"
#include "samples/vox.h"

#include "samples/e_piano.h"
// #include "samples/belldrone.h"

#define NUM_SAMPLES 23

const int8_t *samples_list[NUM_SAMPLES] = { 
piano_DATA, // 0 -   piano
clari_DATA, // 1 -   clarinet
tpt_DATA,   // 2 -   trumpet
glock_DATA, // 3 -   glockenspiel
gtr_DATA,   // 4 -   guitar
sine_DATA,  // 5 -   sine
harp_DATA,  // 6 -   harp
C_maj_DATA, // 7 -   Guitar chords
C_min_DATA, // 8 -   DEAD ZONE
C_dim_DATA, // 9 -   DEADZONE
C_aug_DATA, // 10 -  DEAD ZONE
toy_piano_DATA, // 11 - Toy Piano
marimba_DATA, // 12 - Marimba
steel_drum_DATA, // 13 - Steel Drum
uke_DATA, // 14 - Ukulele
harp2_DATA, // 15 - High Harp
tine_DATA, // 16 - Plucked Melodica Tine
lead_gtr_DATA, // 17 - Lead Guitar
upright_bass_DATA, // 18 - Upright Bass
fantasy_DATA, // 19 - Fantasy
strings_DATA, // 20 - Strings
vox_DATA, // 21 - Vox
e_piano_DATA, // 22 - E Piano
};


int samples_lengths[NUM_SAMPLES] = {
piano_NUM_CELLS, // 0 -   piano
clari_NUM_CELLS, // 1 -   clarinet
tpt_NUM_CELLS,   // 2 -   trumpet
glock_NUM_CELLS, // 3 -   glockenspiel
gtr_NUM_CELLS,   // 4 -   guitar
sine_NUM_CELLS,  // 5 -   sine
harp_NUM_CELLS,  // 6 -   harp
C_maj_NUM_CELLS, // 7 -   Guitar chords
C_min_NUM_CELLS, // 8 -   DEAD ZONE
C_dim_NUM_CELLS, // 9 -   DEADZONE
C_aug_NUM_CELLS, // 10 -  DEAD ZONE
toy_piano_NUM_CELLS, // 11 - Toy Piano
marimba_NUM_CELLS, // 12 - Marimba
steel_drum_NUM_CELLS, // 13 - Steel Drum
uke_NUM_CELLS, // 14 - Ukulele
harp2_NUM_CELLS, // 15 - High Harp
tine_NUM_CELLS, // 16 - Plucked Melodica Tine
lead_gtr_NUM_CELLS, // 17 - Lead Guitar
upright_bass_NUM_CELLS, // 18 - Upright Bass
fantasy_NUM_CELLS, // 19 - Fantasy
strings_NUM_CELLS, // 20 - Strings
vox_NUM_CELLS, // 21 - Vox
e_piano_NUM_CELLS, // 22 - E Piano
};