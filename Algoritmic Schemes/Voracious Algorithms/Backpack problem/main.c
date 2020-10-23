#include <stdio.h>
#include <stdlib.h>

#include "backPack.h"


int main(int argc, char **argv){
		
	//Depending on the order, result will be better/worse
	// This order will be the selection funtion of the algorithm
	int n = 5;
	int values[5] = {55,75,95,76,55};
	int weights[5]   = {50,40,45,35,25}; 
	
	int backPackCapacity = 110;
	double *myBackPack,backPackValue=0; //Solución	
		
	myBackPack = backPack(backPackCapacity, weights, values, n);
	
	if(myBackPack == NULL){
		printf("\nThere is no solution\n");
		return -1;
	}
	
	int i;
	for (i=0; i<n; i++) {
	 	printf("Weight \033[0;35m%d\033[0m -> Quantity \033[0;35m%.3lf\n\033[0m",weights[i],myBackPack[i]);
		backPackValue += myBackPack[i] * values[i];
	}
	printf ("\n\033[1;36mBackpack total value: %.2f\n\033[0m",backPackValue); 	
			
	puts("");
	return 0;
}




