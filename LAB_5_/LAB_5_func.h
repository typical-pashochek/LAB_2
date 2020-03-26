#ifndef lab_5
#define lab_5
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void TextIntoMass(char*** mass, FILE** Text, int* rowsCount);
void Ordering(char*** mass, int* n);
void FreeMass(char*** mass, int n);
#endif