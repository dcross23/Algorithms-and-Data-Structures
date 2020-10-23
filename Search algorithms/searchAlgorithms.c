#include "searchAlgorithms.h"

/* Sequential search that looks each element from the first one
 *  until it founds the value or until the vector finishes
 *  
 * Returns index where the value is located in the array.
 */
int linearSearch(int value, int *array, int arraySize){
	int i;
	for(i=0; i<arraySize; i++){
		if(array[i] == value)
			return i;		
	}

	return -1;
}

/* NEEDS THE ARRAY TO BE SHORTED!!!
 * Divides the array in 2 parts getting the middle element and
 *  compares it to the value that is being searched. If the 
 *  value is smaller than the middle element, it repeats the 
 *  process but with the left half where the numbers are smaller 
 *  than the middle element until there the element in the 
 *  subarray is equal to the value (in case value is bigger, 
 *  it does the same but with right half).
 */
int binarySearch(int value, int *array, int arraySize){
	int i=0;
	int j = arraySize-1;
	int k;
	while(i<j){
		k = (i+j)/2;
		if(value < array[k]){
			j = k-1;
		
		}else if(value > array[k]){
			i = k+1;
		
		}else if(value == array[k]){
			i = k;
			j = k;
		}			
	}

	if(value == array[i]) return i;
	else		      return -1;
}


/* 
 * Recursive implementation of the binary search
 */
int binaryRecursiveSearch(int value, int *array, int firstElement, int lastElement){
	if(firstElement > lastElement)
		return -1;
	
	else{
		int i = firstElement;
		int j = lastElement;
		int k=(i+j)/2;
		if(value < array[k]){
			j = k-1;
		
		}else if(value > array[k]){
			i = k+1;
		
		}else if(value == array[k]){
			return k;
		}

		return binaryRecursiveSearch(value,array,i,j);	
	}
}
