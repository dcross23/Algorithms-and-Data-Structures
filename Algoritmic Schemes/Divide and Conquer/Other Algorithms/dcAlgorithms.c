#include "dcAlgorithms.h"

/* Divide & Conquer algorith very similar to binary search, but
 *   in this case it divides the array in 3 parts instead of 
 *   2 parts.
 *                     O(lg₃(n)) 
 */ 
int ternarySearch(int value, int *array, int firstElement, int lastElement){
	if(firstElement > lastElement){
		return -1;
	}else{
		int i = firstElement;
		int j = lastElement;
			
		//Array [0,1,2, 3,4,5, 6,7,8]
		//             [k]    [l]
		int k = i + (j - i) / 3;  
		int l = j - (j - i) / 3;;
		
		if(value < array[k]){
			//First part of the array (1/3 of the array)
			j = k-1;
		
		}else if(value > array[k]){
			if(value < array[l]){
				//Second part of the array (2/3 of the array)
				i = k+1;
				j = l-1;
				
			}else if(value > array[l]){
				//Third part of the array (3/3 of the array)
				i = l+1;
			
			}else{
				return l;
			}
			
		}else{
			return k;
		}
	
		return ternarySearch(value, array, i, j);
	}
}




/* Returns the base powered up to exp
 *    O(lg(n))
 */
int powerOf(int base, int exp){
	//printf("\nBase:%d\nExp:%d",base,exp);
	if(exp == 1){
		return base;
	
	}else{
		int res = powerOf(base, exp/2) * powerOf(base, exp/2);
		if(exp % 2 != 0){
			res *= base;
		}
		return res;	
	}
}



















