#include <string.h>
#include <stdlib.h>

#include "primeFact.h"

/* Voracious algorithm that returns a solution for a number factorization
 *  using an array of primes (its imposible to use all infinite primes)
 * It also returns the number of primes that are used to factorize the 
 *  number. That is, if it uses numbers 2,3,5,7 (all 2 times) to factorize 
 *  the number, it will return 4 (one for 2, one for 3, one for 5, one for 7)
 */
int primeFactorization(int number, int *primes, int numPrimes, int *solution){
	if(solution == NULL || primes == NULL || numPrimes<=0) return -1;
	
	int j;
	for(j=0; j<numPrimes; j++){
		solution[j]=0;
	}
	
	int total = number;
	j=0;
	
	while(total != 1){
		while(j<numPrimes && total%primes[j]!=0){
			j++;
		}	
		
		if(j >= numPrimes)
			return 0;
			
		else{
			solution[j]++;
			total /= primes[j];
			
		}
	}
	
	int numPrimesFinded = 0;
	for(j=0; j<numPrimes; j++){
		if(solution[j] != 0){
			numPrimesFinded++;
		}	
	}
	
	return numPrimesFinded;

}
