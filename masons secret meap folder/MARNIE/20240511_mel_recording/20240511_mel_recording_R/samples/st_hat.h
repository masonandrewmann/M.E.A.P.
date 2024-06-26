#ifndef st_hat_H_
#define st_hat_H_
 
#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "mozzi_pgmspace.h"
 
#define st_hat_NUM_CELLS 366
#define st_hat_SAMPLERATE 32768
 
CONSTTABLE_STORAGE(int8_t) st_hat_DATA [] = {-47, -75, -83, -83, -49, -17, -29,
-72, -68, -35, -8, 7, 33, 54, 8, -72, -90, -63, 10, 93, 73, 6, -8, 3, 2, 1, 19,
42, 54, 53, -1, -63, -31, 44, 83, 95, 39, -31, -45, -31, 1, 41, 71, 81, 19, -60,
-78, -54, 8, 65, 83, 68, -13, -86, -59, 5, 63, 82, 7, -54, -18, 28, 36, 23, -12,
-34, -13, 20, 55, 62, 13, -34, -57, -46, 14, 64, 71, 48, -10, -55, -63, -38, 27,
69, 65, 35, -24, -53, -26, -2, -2, 19, 77, 61, -57, -96, -16, 42, 52, 44, 16,
-8, -23, -13, 31, 70, 87, 75, 39, 36, 76, 67, 4, -5, 37, 62, 79, 72, 31, -11,
-43, -50, -34, -26, -26, -12, 4, -32, -101, -116, -89, -50, -8, -24, -69, -71,
-50, -19, 15, -5, -44, -30, 7, 0, -30, -57, -72, -34, 21, 46, 45, 10, -33, -49,
-48, -23, 12, 34, 46, 45, 31, -9, -43, -27, -1, 19, 35, 29, 11, -6, -15, -20,
-20, 3, 21, 12, -1, -18, -27, -8, 12, 29, 27, -22, -58, -37, -2, 26, 38, 23, 7,
-3, -16, -45, -50, 6, 49, 46, 18, -34, -52, 0, 24, -13, -26, 12, 35, 23, -3,
-48, -51, 4, 32, 8, -7, 10, 13, -1, -18, -44, -39, 7, 34, 35, 18, -5, -22, -40,
-31, 3, 23, 31, 19, -21, -40, -28, 8, 48, 39, -12, -28, -15, -2, 16, 1, -39,
-25, 30, 47, 34, 1, -39, -41, -18, 1, 16, 33, 39, 10, -34, -40, -26, 4, 37, 19,
-15, -1, 26, 7, -24, -32, -22, 2, 24, 25, 18, 15, 5, -22, -43, -27, 3, 31, 45,
10, -33, -32, -16, 0, 17, 22, 13, -16, -35, -13, 13, 14, 8, 12, 20, -3, -21,
-22, -19, 12, 14, -4, 7, 14, -16, -17, 8, 4, -4, -5, 3, 7, 3, -2, -2, -5, -3, 3,
4, 2, -3, -1, 2, 0, -1, 0, 2, 2, 1, 1, 2, -2, -3, 2, 3, 4, 2, 0, 1, -1, -2, 0,
2, 4, 4, 0, -1, 2, 0, -2, 0, 1, 4, 4, 3, 4, 3, 0, 0, 0, 1, };

#endif /* st_hat_H_ */
