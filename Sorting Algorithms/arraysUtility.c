#include "arraysUtility.h"

int *createArray(int size){
	if(size <=0) 
		return NULL;


	int *array;
	if(NULL == (array=malloc(size * sizeof(int)))){
		#ifdef DEBUG
			fprintf(stderr,"Error: Can not reserve memory for array\n");
		#endif
		return NULL;	
	}

	srand(time(NULL));
	for(int i=0; i<size; i++){
		array[i] = rand() % size;
	}
	return array;
}

int *createSortedArray(int size){
	if(size <=0) 
		return NULL;


	int *array;
	if(NULL == (array=malloc(size * sizeof(int)))){
		#ifdef DEBUG
			fprintf(stderr,"Error: Can not reserve memory for array\n");
		#endif
		return NULL;	
	}

	for(int i=0; i<size; i++){
		array[i] = i;
	}
	return array;

}

void printArray(int *array, int arraySize){
	int i;
	for(i=0; i<arraySize; i++){
		if(i == 0)
			printf("%d",array[i]);
		else
			printf(",%d",array[i]);
	}
}


void swap(int *array, int i, int j){
	typeof(array[0]) temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

