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
	//insertionSort(array,arraySize);

	//int inc[5] = {1,2,3,4,5};
	//shellSort(array,arraySize,inc,5);

	quickSort(array,0,arraySize-1);


	printf("\n\nSortered array\n");
	printArray(array,arraySize);
			
	puts("\n");
	return 0;
}

