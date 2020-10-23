#include <stdio.h>
#include <stdlib.h>

#include "arraysListsUtilities.h"
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

	//quickSort(array,0,arraySize-1);
	//mergeSort(array,0,arraySize-1);

	printf("\n\nSortered array\n");
	printArray(array,arraySize);
			
	puts("\n");

	
	//Comment the code before and uncomment this for radix sort
	/*
		int numNodes;
		int numGroups = 10; //decimal, 10 numbers, 0-9
		
		printf("List size?:");
		scanf("%d%*c",&numNodes);

		int numFigures=0;
		int aux = numNodes-1; 
		//This loop will calculate the number of figures the biggest number has. 
		//  createList method just create nodes with info from 0 to numNodes-1
		//  so is easy to know the max number of figures the numbers have.
		while(aux != 0){
			numFigures++;
			aux = aux/10;
		}

		Node* list=NULL;
		createList(&list, numNodes);

		printf("\nRandom list\n");	
		printList(list);	

		radixSortLSD(&list,numGroups,numFigures);

		printf("\n\nSorted list with RadixSort\n");
	   	printList(list);

		puts("\n\n");
	*/
	return 0;
}

