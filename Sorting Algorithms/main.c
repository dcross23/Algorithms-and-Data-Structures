#include <stdio.h>
#include <stdlib.h>

#include "arraysUtility.h"
#include "sortingAlgorithms.h"

int main(int argc, char **argv){
	
	int arraySize;

	printf("Array size?:");
	scanf("%d%*c",&arraySize);

	int *array = createArray(arraySize); 

	if(array == NULL) 
		return -1;

	printf("\nRandom array\n");
	printArray(array,arraySize);

	//bubbleSort(array,arraySize);
	//selectionSort(array,arraySize);
	insertionSort(array,arraySize);

	printf("\n\nSortered array\n");
	printArray(array,arraySize);
			
	puts("\n");
	return 0;
}

