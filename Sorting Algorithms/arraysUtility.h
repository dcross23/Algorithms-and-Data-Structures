#ifndef __ARRAYS_UTILITY__
#define __ARRAYS_UTILITY__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *createArray(int size);
int *createSortedArray(int size);
void printArray(int *array, int arraySize);

void swap(int *array, int i, int j);


#endif
