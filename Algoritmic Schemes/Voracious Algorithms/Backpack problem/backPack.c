#include <string.h>
#include <stdlib.h>

#include "backPack.h"

/* Voracious algorithm to solve the backpack problem.
 * The problem is to maximize the value of the backpack 
 *  with a given weigth.
 * This max value will depend on the selection function that in
 *  this case, depends on weight and value of the objects: depending
 *  on the order of the arrays that contain the weights/values, the 
 *  result will be different.
 *
 * There are 2 possible algorithms: one with object division and one 
 *  without. 
 * The one with object division allows to insert a fraction of the 
 *  object in the backpack, this is, objects can be fractioned and add
 *  only a part of it.
 * The other one without object division only allows to add a full object
 *  to the backpack.
 *
 * The differences remain on the solution: with object division will always 
 *  give an optimal value but dont represent the reallity; the other one
 *  without object division represents reallity but will not always give 
 *  an optimal value
 */
double *backPack(int capacity, int *weights, int *values, int n){
	double *solution = malloc(n *  sizeof(double));

	if(solution == NULL){
		return NULL;
	}	
	memset(solution, 0, n-1); //Initialize solution to 0
	
	
	int currentWeight = 0;
	int j = n-1;
	
	while( (j>=0) && (currentWeight<capacity) ){
		if(currentWeight + weights[j] <= capacity){
			solution[j] = 1.0;			
		
		}
	 	#ifdef OBJECT_DIVISION
			else{
				solution[j] = ((double)(capacity - currentWeight) / (double)weights[j]);	
			}	
		#endif 
		
		currentWeight += solution[j] * weights[j];
		j--;
	}
	return solution;
}
