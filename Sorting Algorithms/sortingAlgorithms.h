#ifndef __SORTING_ALGORITHMS__
#define __SORTING_ALGORITHMS__

#include "OtherFiles/arraysListsUtilities.h"
#include "OtherFiles/heap.h"

void bubbleSort(int *array, int arraySize);
void selectionSort(int *array, int arraySize);
void insertionSort(int *array, int arraySize);
//TODO: insertionSort with binary search instead of linear search
void shellSort(int *array, int arraySize, int *gaps, int numGaps);

//QuickSort
void quickSort(int *array, int base, int top);
int selectPivot(int *array, int base, int top);

//MergeSort
void mergeSort(int *array, int base, int top);
void merge(int *array, int baseA, int topA, int baseB, int topB);

//RadixSort
void radixSortLSD(Node **list,int numGroups,int numFigures);
void distribute(int posFigure, Node **list, Node** groups, Node **lasts);
void concat(Node **list, Node **groups, Node **lasts, int numGroups);
int extractFigure (int num, int posFigure);

//HeapSort
void heapSort(int *array, int arraySize);

#endif
