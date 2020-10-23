#include <stdio.h>
#include <stdlib.h>

#include "primeFact.h"

#define NUMPRIMES 20

int main(int argc, char **argv){
	
	int primes[NUMPRIMES]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71};
	int solution[NUMPRIMES], primesTried;
	int number = 600;
		
	primesTried = primeFactorization(number, primes, NUMPRIMES, solution);

	int i;
	printf("\nPRIMES USED\n");
	for(i=0; i<NUMPRIMES; i++){
		printf("%2d ",primes[i]);
	}
	
	
	printf("\n\n\033[1;31mSOLUTION FOR %d\n\033[0m",number);
	for(i=0; i<NUMPRIMES; i++){
		printf("%2d ",solution[i]);
	}
	
	if(primesTried <= 0){
		printf("\n\nNo solution finded for %d\n",number);
	
	}else{
		printf("\n\n\033[1;36m%d = ",number);
		for (i =0;i<primesTried;i++) {
			printf("%d^%d",primes[i],solution[i]);
			
			if(i != primesTried-1){
				printf(" + ");
			}	
		}
	}		
	
	puts("");
	return 0;
}




