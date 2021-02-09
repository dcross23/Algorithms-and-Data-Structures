#include "sortingAlgorithms.h"
#include <math.h>

/**
 * Sorts the array bubbling each element to his correct
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


/**
 * Select the lowest element and put it in his correct
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

/**
 * Inserts the first element of the array in his correct
 *  position (elements are cycling to the first position 
 *  until they are all in their correct position)
 *   O(n²) worst/average cases
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



/**
 * Inprovement of "insertionSort". 
 * Divides the array in subarrays using gaps (array with 
 *  the length of the subarrays) and the sorting that 
 *  subarrays using insertion sort.
 * The complexity of this alg depends on the gaps.
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




/**
 * Recursive algorithm that uses a pivot and putting all the
 *  elements that are smaller than the pivot in the left of 
 *  the pivot and all the elements that are bigger in the right,
 *  and then sort this 2 subarrays using recursivity.
 *    O(n²)      worst case
 *    O(nlg(n))  best/average cases
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



/**
 * Recursive algorithm that separates an array into 2 subarrays 
 *  that will be merged later in ascending order.
 *    O(nlg(n)) all cases
 */
void mergeSort(int *array, int base, int top){
	if(base < top){
		int middle = (base+top)/2;
		mergeSort(array, base, middle);
		mergeSort(array, middle+1, top);
		merge(array, base, middle, middle+1, top);
	}
}

//Merges the subarrays in ascending order
void merge(int *array, int baseA, int topA, int baseB, int topB){
	int i;	
	int dimA = topA - baseA +1;
	int dimB = topB - baseB +1;

	//Temp arrays
	int A[dimA], B[dimB];
	for(i=0; i<dimA; i++){
		A[i] = array[baseA + i];
	}
	for(i=0; i<dimB; i++){
		B[i] = array[baseB + i];
	}
		
	//Indexes for each temp array and main array
	int indA=0;
	int indB=0;
	int ind = baseA;
	
	//If there are still elements in A and B, compare the next one 
	// that has not been added to the main array and the smaller 
	// one is added to array.
	//Repeat this until array A or B is finished.
	while(indA<dimA && indB<dimB){
		if(A[indA] <= B[indB]){
			array[ind] = A[indA++];
		
		}else{
			array[ind] = B[indB++];
		}
		ind++;
	}	
	
	//If there are still elements on A (because B finished) add them
	while (indA < dimA){
		array[ind++] = A[indA++];
	}

	//If there are still elements on B (because A finished) add them
	while (indB < dimB){
		array[ind++] = B[indB++];
	}
}



/**
 * Algorithm based on sorting using distribution of groups. Each number is sorted
 *  acording to its digits starting form the less significant digit (LSD)
 *  First the numbers are distributed and sorted according to the most right or less 
 *  significant digit. Then, this is repeated for each digit until there are no more
 *  digits. This is when the list will be sorted.
 *     O(n) all cases
 */
void radixSortLSD(Node **list,int numGroups,int numFigures){
	Node *groups[numGroups], *lasts[numGroups];
	int k, posFigure;

	for(posFigure=1; posFigure<=numFigures; posFigure++){
		for(k=0; k<numGroups; k++){
			groups[k] = lasts[k] = NULL;
		}
		distribute(posFigure, list, groups, lasts);
		concat(list, groups, lasts, numGroups);
	}
}

//Distributes the list into groups according to the next extracted figure
// Ej: if figure extracted is the 2nd one and its number 3, that node will
//     be added to the group 3
void distribute(int posFigure, Node **list, Node** groups, Node **lasts){
	Node *aux = *list;
	int c;

	while(aux != NULL){
		c = extractFigure(aux->info, posFigure);
		if(groups[c] == NULL){
			groups[c] = aux;
			lasts[c] = aux;	
		}else{
			lasts[c]->next = aux;
			lasts[c] = aux;		
		}
		aux = aux->next;
		lasts[c]->next = NULL;
	}
	*list = NULL;
}

//Concatenates all groups (0-9) in ascending order. This causes the numbers
// to be ordered according with and specific figure. 
void concat(Node **list, Node **groups, Node **lasts, int numGroups){
	int k,prev;
	
	*list = NULL;
	for(k=0; k<numGroups; k++){
		if(groups[k] != NULL){
			if(*list==NULL){
				*list = groups[k];			
			}else{
				lasts[prev]->next = groups[k];		
			}		
			prev = k;
		}
	}
	lasts[prev]->next = NULL;
}

// Extracts figure in a specific position from a number
int extractFigure (int num, int posFigure){
	int d, c, figure;
	
	d = pow(10, posFigure-1);
	c = num / d;
	figure = c % 10;

	return figure;
}




/**
 * Algorith based on Heap (priority queues) properties. In a heap, the 
 *  top element has the highest/lowest priority (or key), so using this property, 
 *  we can create a Heap using the elements of the array as the keys in the heap, 
 *  and then extracting always the top element and inserting them in order in the
 *  array.
 *         O(nlog(n))
 */
void heapSort(int *array, int arraySize){
	if(array != NULL && arraySize >0){
		int hSize = arraySize, i;
		Heap h;
		heapElement top;
		
		h.size = hSize;
		
		for(i=1; i<=hSize; i++){
			h.elements[i].key = array[i-1];
		}
		heapify(&h);
		
		for(i=1; i<=hSize; i++){
			removeTop(&h, &top);
			array[i-1] = top.key;
		}		
	}
}





