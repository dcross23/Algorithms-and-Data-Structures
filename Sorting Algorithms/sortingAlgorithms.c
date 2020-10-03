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
 *  until they are all in their correct position)
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



/* Inprovement of "insertionSort". 
 * Divides the array in subarrays using gaps (array with 
 *  the length of the subarrays) and the sorting that 
 *  subarrays using insertion sort.
 */
void shellSort(int *array, int arraySize, int *gaps, int numGaps){
	int gap, i, j; 
	typeof(gaps[0]) h;
	typeof(array[0]) temp;

	for(gap=numGaps-1; gap>=0; gap--){
		h = gaps[gap];
		for(i=h; i<=arraySize-1; i++){
			temp = array[i];
			j= i-h;
			while(j>=0 && array[j] > temp){
				swap(array, j+h, j);
				j -= h;
			}
			array[j+h] = temp;
		}			
	}
}




/* Recursive algorithm that uses a pivot and putting all the
 *  elements that are smaller than the pivot in the left of 
 *  the pivot and all the elements that are bigger in the right,
 *  and then sort this 2 subarrays using recursivity.
 */
void quickSort(int *array, int base, int top){
	if(base < top){
		int pivot = selectPivot(array,base,top);
		quickSort(array, base, pivot-1);
		quickSort(array, pivot+1, top);
	}
}

//Selects the first element as the pivot
int selectPivot(int *array, int base, int top){
	int pivot = base;
	int pivotValue = array[base];
	int i;
	
	for(i=base+1; i<=top; i++){
		if(array[i] < pivotValue){
			pivot++;
			swap(array, pivot, i);
		}
	}
	swap(array, base, pivot);
	return pivot;
}














