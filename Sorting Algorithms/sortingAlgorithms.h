#ifndef __SORTING_ALGORITHMS__
#define __SORTING_ALGORITHMS__

void bubbleSort(int *array, int arraySize);
void selectionSort(int *array, int arraySize);
void insertionSort(int *array, int arraySize);
//TODO: insertionSort with binary search instead of linear search
void shellSort(int *array, int arraySize, int *gaps, int numGaps);

void quickSort(int *array, int base, int top);
int selectPivot(int *array, int base, int top);

#endif
