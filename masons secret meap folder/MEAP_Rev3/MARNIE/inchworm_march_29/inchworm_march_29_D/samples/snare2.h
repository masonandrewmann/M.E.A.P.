#ifndef snare2_H_
#define snare2_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"
 
#define snare2_NUM_CELLS 5267
#define snare2_SAMPLERATE 32768
 
CONSTTABLE_STORAGE(int8_t) snare2_DATA [] = {-1, 0, -1, 6, 25, 48, 68, 87, 104,
120, 127, 124, 118, 110, 103, 95, 86, 78, 70, 61, 53, 44, 36, 28, 19, 12, 4, -4,
-11, -18, -25, -31, -37, -43, -48, -54, -58, -63, -66, -70, -73, -76, -78, -80,
-82, -84, -85, -85, -86, -86, -86, -85, -85, -84, -82, -81, -79, -78, -76, -73,
-71, -69, -66, -63, -60, -58, -55, -52, -48, -45, -42, -39, -36, -33, -30, -27,
-24, -20, -18, -15, -12, -9, -6, -4, -1, 1, 4, 6, 8, 10, 12, 14, 16, 17, 19, 20,
21, 23, 24, 25, 26, 26, 27, 28, 28, 29, 29, 29, 30, 30, 30, 30, 30, 30, 29, 29,
29, 28, 28, 27, 27, 26, 26, 25, 25, 24, 23, 22, 22, 21, 20, 20, 19, 18, 17, 17,
16, 15, 14, 14, 13, 12, 11, 11, 10, 10, 9, 8, 8, 7, 7, 6, 6, 5, 5, 4, 4, 4, 3,
3, 3, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
-1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, 0, 1, -1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -2, -1, -1, -2, -1,
-1, -1, -2, -1, -2, -2, -2, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1, -2, -2, -2, -2,
-2, -1, -1, -2, 1, 0, -2, 1, -1, -1, -1, -2, -2, -1, 0, -1, 0, 0, 0, -1, -1, -2,
-2, -2, -2, -2, -2, -2, -1, -1, -2, -1, -3, -2, -3, -2, -2, 2, 0, -1, 2, -2, 1,
-1, -1, 0, 0, 0, -1, -1, -2, -2, -2, -2, -2, -2, -1, -2, -1, -1, -1, -2, -2, -2,
-2, -2, -1, 1, -1, 1, 0, -2, 0, 2, 0, -1, 1, -2, 1, 2, -1, 0, -1, -2, -1, -2,
-2, 0, 0, -1, -1, -2, -1, -1, -2, -1, 1, -2, -1, -1, -3, -2, -1, -1, -2, 0, -1,
-2, -2, -1, -2, -2, -3, -3, 0, 1, -2, -1, 0, -1, -1, 0, 0, -1, -1, -2, -3, -2,
-1, -2, -2, -1, -1, -2, -2, -2, 0, 1, -1, 1, 0, -1, -1, 0, -2, -1, -1, -2, -3,
0, 4, -2, 3, 0, 1, 1, -2, 2, -1, -2, -2, -2, -3, -3, -3, -1, -1, 1, 5, 4, 2, 1,
1, -1, 0, -1, -2, -1, -2, -2, -4, -3, -2, -1, -3, 0, 3, -2, 0, 2, 8, 5, 7, 4, 1,
5, -2, 1, 0, -4, 2, 6, 2, 3, 2, -2, 2, -4, -2, 0, -2, -1, 1, 0, -3, -1, -5, -3,
-3, -1, -2, 2, 0, -1, -1, -5, -3, -3, -2, -4, -4, -2, 2, -4, 1, 0, -1, 0, -5,
-3, -3, -2, -1, 2, -3, 0, -2, -4, -2, -3, -3, -4, -4, -4, -1, -3, -1, 1, -1, -3,
-3, -3, -3, -2, -4, -3, 1, 3, -1, 0, 0, -3, -2, 0, 2, -1, -1, -2, -3, 0, 1, 1,
-2, -1, -1, -1, -2, 0, 1, 1, 1, -2, -1, -1, 0, -2, -4, -3, -3, -4, -3, 3, -1,
-1, 1, -1, 1, -2, -1, 1, 2, -3, -1, -2, -4, -1, -2, 1, -2, -1, -1, -4, -1, 1,
-1, -2, -2, -3, -3, -3, 2, 2, 1, 0, -1, -2, -2, 2, 7, 7, 3, 5, 4, 4, 3, -2, 2,
-2, -2, -1, -4, -3, 2, 10, 0, 6, 4, -2, 7, 2, 6, 2, -1, 3, -3, -1, 2, -1, 0, 0,
-1, -2, -3, -3, -5, -6, -6, -6, -5, -3, 0, 0, -3, -1, -4, -4, 3, -1, -1, -1, -4,
-3, -3, -5, 1, 6, 1, 4, 2, -1, 3, -3, 2, 0, -2, 0, -4, -3, -3, -3, -4, -5, -4,
1, -3, -2, 5, 3, 0, 3, -3, 0, 2, -3, 0, -3, -1, -2, -2, -2, -3, -3, -1, -3, -4,
-3, 0, 3, 0, 3, -3, -1, -1, -4, -2, -1, -1, -3, 1, 0, -3, -2, -3, -3, -1, -1,
-3, -3, 2, -1, -2, 2, 1, -1, -1, -1, -1, -2, -3, -3, -2, -3, -2, -1, 0, 2, -2,
-1, 1, 0, -2, 3, 4, -1, 3, 0, -1, 1, -3, -1, -2, 1, 0, -2, 0, -4, -2, -2, 3, 0,
1, 2, -2, 0, 1, 1, -2, -1, -2, -1, 3, 1, -2, 3, -1, -1, 0, -2, -3, -1, -1, -2,
-3, 0, 0, -1, 0, 0, 0, -1, 0, 0, 1, -1, -1, -2, 1, 1, -2, 0, 0, 0, -2, -2, -3,
-2, -2, -2, 1, -1, -1, 0, 0, 0, 3, 0, 0, 2, -2, -1, 0, 1, -1, 0, -1, -1, 0, -2,
-2, -1, 1, -2, -2, -1, 0, -2, -2, 3, 0, -1, 0, 5, 1, 1, 2, 2, 5, 0, 3, 1, 1, 0,
-2, -2, -2, 0, 0, -2, -1, 0, 0, 1, 0, 1, -2, -2, -1, -3, -2, 1, 3, -2, 2, 2, -1,
0, -1, 0, -1, -2, -1, 1, -1, 2, 0, -1, 1, 0, -1, -2, -1, -3, -3, -1, 3, 0, 1, 0,
-2, -1, -3, -1, 0, 0, -2, -1, 2, 1, -1, 0, 1, 1, 1, 0, -2, -1, -2, -1, -2, -2,
-2, -1, 1, 1, 4, 0, 0, -1, -1, -2, -1, 1, -2, 0, 4, 3, 1, 3, -3, 1, 2, -2, 0,
-2, -2, -2, -3, -2, -2, -2, 1, -2, 0, 0, -1, 2, 1, -1, -1, -1, -2, -1, -1, 0,
-1, 0, -2, -2, -1, 0, -2, -2, 0, -1, -2, -2, 2, -1, -1, 1, 9, 5, 3, 8, 0, 6, 2,
1, 5, -2, 3, 1, -1, 2, -3, -1, 0, -1, -1, -1, -1, -2, -3, -3, -3, -2, -4, -3,
-1, 0, 0, -1, 1, -2, -2, -2, 2, -2, 0, 0, -3, 1, 6, 0, 2, 5, -1, 3, -1, 0, 0, 0,
2, -2, -1, 1, 0, -2, -1, -3, -3, -3, -2, -1, 0, 1, -1, -2, -1, -2, -2, -3, -3,
-3, -3, -3, -2, 1, -1, -1, -1, -3, -1, 1, 3, -1, 2, 0, -1, 1, -2, -2, 1, 0, -2,
-1, -1, -2, -2, -3, 0, 2, -2, 0, -1, -1, 0, -2, -1, 1, -2, -2, 3, 2, -1, 3, 0,
-1, 1, -2, -1, -2, -2, -2, -3, 0, 1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -2, -2,
-2, -2, -2, 0, 2, 1, 0, 0, -1, -2, -2, -2, 0, -1, 0, 0, 1, 0, -1, -1, 2, 4, 0,
3, 0, 3, 2, -1, 2, -1, 0, 0, -2, -2, -2, -1, -1, -1, -1, 0, -1, 1, -1, -1, -1,
-1, -1, -2, -2, -1, 0, -1, 1, -1, -2, -2, -2, -2, -1, 0, -2, -1, 1, 1, -2, 3, 4,
1, 2, 1, 0, 1, -2, -1, 3, 1, 1, 1, -2, 0, -2, -2, -1, 0, 0, -1, 1, -1, -2, -1,
3, 0, -1, 1, -3, 1, 4, 3, 2, 2, -1, 1, -2, -2, 0, -1, -1, 0, 0, -2, -1, -2, -3,
-2, 2, 0, 0, 1, -2, 1, -1, -1, -1, -2, -3, -2, 0, -1, -2, -1, -3, -1, 0, 0, 0,
-1, -1, -1, 1, -1, -1, -1, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, 0, 1, 0,
2, 1, -1, -1, -1, -1, 0, 0, -2, -1, 1, 3, -1, 2, 0, -1, 0, -2, 0, -1, 0, -2, -1,
-2, -1, -2, 0, 3, 1, 2, 1, 1, 1, -1, -1, -1, -2, -1, -2, -2, -2, 0, -1, -2, -1,
1, 0, -2, 0, 2, 0, -1, 3, 0, 0, 0, 1, 0, 1, 0, -1, 0, -1, -1, -2, -2, -2, -2,
-1, 1, -1, 0, -2, -2, -1, 0, 1, 1, 3, -1, 1, 0, -1, -1, -1, -1, -2, -1, 0, -1,
-2, 0, -1, -1, -1, -1, -1, -2, -2, -2, -1, 1, 2, 0, 0, 0, -1, 0, -1, -1, 0, -1,
-1, -2, -1, -1, -2, -1, 0, 0, 0, 0, 0, -1, -2, -1, -1, -1, -1, -1, -2, 1, 1, -1,
1, 0, 0, 0, -1, -1, -1, 0, -1, 0, -1, -2, -1, -1, -1, -2, 2, 1, 1, 1, 0, 2, -1,
0, 0, -1, -1, -2, -1, -2, -1, 1, 4, 2, 1, 3, -1, 1, 3, 2, 2, 1, -1, 1, 0, -1,
-2, -1, -1, 0, 1, -2, 0, 1, 3, 0, 1, 0, 0, 1, -2, 0, -1, -2, 0, 0, -2, -1, -1,
-1, -1, -1, -2, -1, 1, -1, -2, -1, -2, -1, -1, -2, -1, -2, -2, -2, -2, -2, -2,
-2, -2, -1, -1, -2, -2, 0, 1, 1, 1, 0, 0, -1, -1, -1, -2, -1, -1, -1, -2, -1,
-1, -1, -2, -1, 0, -1, 0, 4, 4, 0, 4, 0, 1, 2, -1, 2, 2, 4, 2, 3, 1, 0, 1, -1,
0, -1, -2, 0, -1, -1, -2, -2, -2, -1, -2, -2, 0, 1, 0, 1, 0, -1, -1, -1, -2, -2,
-2, -2, -3, 1, 1, -1, 2, -1, 0, -1, -2, -1, 0, 1, -1, 0, 0, 1, -1, -1, -1, -2,
-1, -2, -2, -2, -2, -1, -2, -2, -2, -2, -1, -1, 0, -2, -2, -1, -2, -2, -2, -1,
-1, -1, 0, 1, -1, -1, 0, -1, 0, -1, -1, -1, 0, -1, -1, -1, -1, 0, 3, 1, 0, 2,
-1, 1, 0, -1, 1, -2, 0, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -2, -2,
-2, -2, 0, 2, -1, 0, 0, -2, 0, -1, 0, 0, -1, -1, -2, -2, -1, 1, 0, 1, 3, 2, 1,
2, 0, 0, 0, -2, 0, 0, 0, 0, -1, -2, -1, -1, -2, -2, -2, -2, 1, 2, 0, 2, 0, 1, 1,
-1, 1, 0, -1, -1, -2, -1, -1, -1, -1, -2, -1, -1, -2, -1, 0, 0, -1, 0, -1, -1,
-1, -2, -2, -2, -2, -2, -2, 0, 0, -2, 0, -1, -1, -1, 1, 1, -1, 1, -1, 0, 0, 0,
0, -1, -1, -1, 0, -1, -1, -1, -2, -2, 0, -1, -1, -1, 0, -1, -1, -1, 2, 2, 0, 3,
-1, 1, 2, 0, 2, 0, 0, 0, -1, 0, -1, -1, 0, -1, -1, 0, -1, -1, 0, -1, -2, -1, 0,
-1, -1, 0, 0, -1, 0, -1, -1, -1, -2, -2, -1, 0, -1, 0, 2, 0, 0, 1, -1, 1, -1,
-1, 0, -1, 0, 0, -1, -1, -1, -2, -1, -1, -1, -1, 1, 0, -1, 0, -1, 0, -1, -1, -1,
-1, -1, -1, -1, -1, -1, 2, 1, 0, 2, -1, 0, 0, 1, 1, 0, 0, -1, -1, 0, 0, -1, 0,
-1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0,
0, 0, -1, -1, 1, -1, -1, 0, -1, 0, -1, 0, -1, -1, -1, 0, -1, 0, 0, 0, 0, -1, 0,
-1, -1, -1, -1, 0, 1, 0, 0, 0, -1, 0, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, 1, 0, 0, 0, -1, -1, -1, 0, -1, -1, -1, 1, -1, 0, 0, -1, 0, 0, 1, -1, -1,
-1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 1, 0, 0, -1, -1, -1, 0,
-1, 0, 1, 0, 0, 0, -1, 0, -1, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1,
-1, -1, 0, 0, -1, 0, -1, -1, -1, 0, -1, -1, 0, -1, -1, -1, -1, 0, -1, -1, 0, 0,
0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, 2, 2, 0, 2, 0, 0, 1, -1, 1, -1, 0, 0,
-1, 0, 1, 1, -1, 1, 0, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -2, -1, -2, 0,
2, 0, 2, 0, 0, 1, -1, 0, 2, 0, 0, 1, 0, 0, 0, -1, -1, -1, -1, -1, -2, -1, 0, -1,
-1, 0, -2, -1, 1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1,
-1, -1, -2, -1, 0, -1, -1, 0, -2, -1, -1, -1, -1, -2, -2, -1, -1, -1, -1, -1,
-1, -1, -1, -1, 0, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0,
0, -1, -1, -1, -1, 0, -1, -1, -1, 1, 0, -1, 1, 0, 1, 0, 0, 0, -1, -1, -1, 0, -1,
-1, -1, 0, 0, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, 0, 1, 0, 0, 0, -1, -1, -1, -1, 1, 0, -1, 0, -1, -1, -1,
-1, -1, 0, 0, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, 0, 1, 1, 2, 0, 1, 1, 0, 0, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, 0, 0, 0, 0, -1, -1, -1, -1, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 1, 1, 0, 0, 0, -1, -1, -1, -1,
-1, -1, 0, 1, 0, 0, 0, 0, 0, -1, -1, 0, -1, -1, -1, -1, -1, 0, 0, -1, 1, 0, -1,
0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, -1, -1,
-1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, 0, 0,
0, 0, -1, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, 1, 1, 0, 1, 0, 1, 1, -1,
0, 0, 0, 0, -1, -1, -1, 1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,
0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 1, -1, 0, -1, 0, 0, -1, 0, -1, -1,
-1, -1, -1, -1, -1, 0, 1, 1, 1, 0, 1, 0, 0, 0, -1, 0, -1, 0, 0, -1, -1, -1, -1,
-1, 0, -1, -1, 1, 1, 0, 1, 1, 0, 1, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, 0, 0, 1, 0, 0, 0, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1,
-1, 0, 0, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1,
-1, 0, 0, -1, -1, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, 0, -1, -1, 0, -1, -1, -1,
-1, -1, -1, -1, -1, -1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, -1, 0, -1, 0, -1, -1,
-1, -1, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, 0, 1, 0, 0, 0, -1, 0,
0, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, 0, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, 0, 0, 0, -1, -1, -1, -1,
-1, 0, 0, 1, 0, 1, 0, -1, 1, -1, 0, 0, -1, 0, 1, -1, 0, 0, -1, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1,
-1, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, 0, 0, -1,
-1, -1, -1, 0, -1, -1, 0, 0, -1, 0, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1,
0, -1, -1, 1, 1, -1, 1, -1, 0, 0, -1, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, 0, -1, -1, -1, -1, -1, 0, -1, 0, 0, -1, -1, 0, -1, -1, -1, -1, -1,
0, 1, 1, 1, 1, 1, 0, 0, 0, -1, -1, -1, -1, -1, 1, 0, -1, 0, -1, 0, -1, -1, 0, 0,
0, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0,
-1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, 0, -1, -1,
-1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, -1,
-1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0,
-1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1,
0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, -1, -1, -1, 0,
0, -1, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, 1, 0, 0, 1, -1, 0, 0, 0, 0,
-1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, 0, -1, -1, 0, 0, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -1, 1, 0, 0, 1, -1, 1, 0, 0, 1, -1, 0, 0, -1, 0, -1, 0, 0, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, -1, 0, 1, 0, 0, 0, -1, 0, -1, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, 0, -1, 0, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, -1, -1, 0, 0, 0, 0, 0, -1, 0, -1, -1, 0, -1, -1, -1, -1, -1, 0, -1,
-1, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1,
-1, -1, -1, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 1, 0, 0, 0, -1, 0, 0,
0, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, 0, 0, -1, -1, -1, 0, -1, -1,
-1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, -1, -1, 0,
0, 0, 0, -1, -1, 0, -1, 0, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0,
0, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1,
0, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, 0, -1, -1, -1, -1, 0, -1, -1, -1, -1, 0, 0, 0, -1, 0, 0, 0, 0, -1,
0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, 0, -1, 0, -1, -1, -1, -1, -1,
-1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1,
-1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, 0, 1, 0, 0, 1,
0, 1, 0, 0, 1, -1, 0, 0, -1, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 1, 0, 0, 0, 0, 0, 0,
0, 0, -1, 0, -1, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, -1,
0, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, -1,
-1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, -1,
-1, -1, -1, 0, 0, -1, 0, -1, 0, -1, -1, 0, 0, -1, 0, -1, -1, 0, -1, -1, -1, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0,
0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1,
-1, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1,
0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1, -1, 0,
0, 0, 0, -1, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -1, 0, 0, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0,
-1, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0,
0, 0, -1, 0, 0, 0, 0, 0, -1, -1, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1,
-1, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, -1, 0, -1, -1, -1, 0, -1, -1, -1, -1,
-1, 0, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0,
-1, -1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, 0,
-1, 0, 0, 0, 0, 0, -1, -1, -1, -1, 0, -1, -1, 0, 0, -1, 0, -1, 0, 0, -1, 0, -1,
-1, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1,
-1, -1, -1, -1, 0, 0, -1, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, -1, 0, 0, 0, -1, -1, -1, -1, -1,
-1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, -1, 0, -1, -1, 0,
-1, -1, 0, 0, -1, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, 0, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1,
-1, 0, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, 0, -1, 0, -1,
0, -1, -1, -1, 0, 0, 0, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0,
-1, -1, -1, -1, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1, 0, 0, 0, 0, -1, -1, 0, 0, 0,
0, -1, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 0, 0, 0,
0, 0, -1, 0, 0, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1, -1, -1,
-1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -1, -1, 0, 0, 0, 0, -1, 0, -1, 0, 0, -1, 0, -1, 0, -1, -1, -1,
-1, -1, -1, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, -1, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, -1, 0, -1,
-1, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, 0, -1,
-1, -1, -1, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, 0, -1,
-1, 0, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, -1, -1, -1, -1,
-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, 0, -1, -1, -1, -1, -1, -1,
0, 0, -1, 0, -1, -1, 0, 0, -1, 0, -1, -1, -1, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1,
0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, 0, 0, 0, 0, -1, 0, -1, -1,
-1, -1, -1, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1,
-1, -1, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, 0, -1,
-1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0,
0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1, 0, 0, 0,
-1, 0, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1, 0, -1, -1, -1, -1, -1, 0, 0, -1, 0,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, -1, 0, 0,
-1, 0, -1, -1, -1, 0, 0, 0, 0, -1, 0, 0, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1, 0, 0, 0,
0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, 0, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, -1, -1, 0, 0, 0, -1, -1,
-1, 0, -1, 0, 0, -1, -1, 0, 0, -1, -1, -1, -1, 0, -1, -1, 0, 0, 0, 0, 0, -1, 0,
-1, -1, 0, -1, -1, 0, 0, -1, 0, -1, -1, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -1, 0, 0, -1, 0, 0, 0, 0, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, -1, 0, -1,
-1, 0, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, -1, 0, 0, 0, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, 0, 0, 0, -1, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1, -1, 0, 0, -1,
-1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, -1, -1, 0, -1, 0, -1, -1, -1, -1, -1,
-1, 0, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, 0, 0, -1, 0, 0, 0, -1, -1, -1,
-1, -1, -1, -1, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, -1, 0, -1, -1, 0, 0, -1, 0, 0,
-1, -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, 0, 0, 0, 0,
0, 0, -1, -1, -1, -1, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, 0, 0, -1, -1, 0, 0,
0, -1, 0, 0, 0, 0, -1, -1, -1, 0, -1, -1, -1, 0, 0, -1, 0, -1, 0, -1, 0, 0, 0,
0, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1,
0, 0, -1, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0,
-1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0, -1, 0, 0, -1, 0, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0,
0, 0, 0, 0, 0, 0, -1, 0, -1, -1, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0,
-1, 0, -1, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, 0, -1, -1, -1, -1, -1, -1, -1,
-1, -1, -1, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0,
0, 0, 0, -1, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, -1, 0, 0, 0, -1, 0, 0,
-1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0, -1, 0, -1, -1,
-1, -1, -1, 0, 0, -1, 0, 0, 0, 0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
-1, -1, 0, -1, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1, 0, -1, -1, 0, -1, 0, -1,
-1, 0, 0, -1, 0, 0, -1, -1, -1, -1, -1, 0, -1, -1, 0, 0, 0, 0, -1, -1, -1, -1,
-1, -1, 0, -1, 0, 0, 0, -1, 0, -1, -1, 0, -1, -1, 0, 0, -1, 0, 0, 0, 0, -1, 0,
0, 0, 0, -1, -1, -1, -1, -1, -1, -1, -1, };

#endif /* snare2_H_ */
