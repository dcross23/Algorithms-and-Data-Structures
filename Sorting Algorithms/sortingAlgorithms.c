#include "sortingAlgorithms.h"
#include "arraysUtility.h"

/* Sorts the array bubbling each element to his correct
 *  position.      O(n²)
 */
void bubbleSort(int *array, int arraySize){
	int i,j;

	for(i=0; i<=arraySize-2; i++){
		for(j=arraySize-2; j>=i; j--){
			if(array[j] > array[j+1]){
				swap(array,j,j+1);
			}
		}
	}

}


/* Select the lowest element and put it in his correct
 *  position.        O(n²)
 */
void selectionSort(int *array, int arraySize){
	int i,j;
	int posSelection;
	typeof(array[0]) valueSelection;

	for(i=0; i<=arraySize-2; i++){
		posSelection = i;

		for(j=i+1; j<=arraySize-1; j++){
			if(array[j] < array[posSelection]){
				posSelection = j;
			}
		}

		swap(array, posSelection, i);
	}
}

/* Inserts the first element of the array in his correct
 *  position (elements are cycling to the first position 
    until they are all in their correct position)
 *   O(n²) worst/middle case
 *   O(n)  best case
 */
void insertionSort(int *array, int arraySize){
	int i,j;
	typeof(array[0]) temp;
	
	for(i=1; i<=arraySize-1; i++){
		temp = array[i];
		j = i-1;
		while(j>=0 && array[j]>temp){
			swap(array, j, j+1);
			j--;
		}
		array[j + 1] = temp;
	}
}
