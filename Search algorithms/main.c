#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "arraysUtility.h"
#include "searchAlgorithms.h"

int main(int argc, char **argv){
	
	int valueToFind;
	int arraySize;

	printf("Array size?:");
	scanf("%d%*c",&arraySize);

	//int *array = createArray(arraySize);       //Not binary search
	int *array = createSortedArray(arraySize); //Any search

	if(array == NULL) 
		return -1;

	printArray(array,arraySize);
	printf("\n");
	
	printf("\nValue?:");
	scanf("%d%*c",&valueToFind);

	//int pos = linearSearch(valueToFind,array,arraySize);
	//int pos = binarySearch(valueToFind,array,arraySize);
	int pos = binaryRecursiveSearch(valueToFind,array,0,arraySize-1);

	if(pos == -1)
		printf("\nCan not find value %d in the array\n",valueToFind);
	else
		printf("\nValue %d finded at pos %d\n",valueToFind, pos);		
			
	return 0;
}

