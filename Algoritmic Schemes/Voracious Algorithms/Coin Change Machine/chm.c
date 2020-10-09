#include <string.h>
#include <stdlib.h>

#include "chm.h"

/* Gives a solution to the problem of changing coins in a machine
 *   using Voracious Algorithmic Scheme
 *
 * It gives a solution by substracting from the total amount using
 *  the coin with highest value that is equal or smaller than the
 *  total amount. This process is repeated until the total amount
 *  remains 0 so there is a solution, or until the total amount is
 *  still greater than 0 but there is no coin with a smaller value 
 *  than the total amount, so in this case there is no solution 
 *  to the problem 
 */
int *coinsChange(int amount, int *coins,int numCoins){
	int total = amount;
	int nC = numCoins-1;
	
	int *solution = malloc(numCoins * sizeof(int));
	if(solution == NULL) return NULL;
	
	memset(solution, 0, nC); //Initialize solution to 0
	
	while(total > 0){
		while( nC>=0 && coins[nC]>total ) 
			nC--;
		
		if(nC < 0){
			return NULL;
		}else{
			solution[nC] = total / coins[nC];
			total -= coins[nC]*solution[nC];
		}
	}
	return solution;	
}

// Another version of the coin change machine
int *coinsChangeV2(int amount, int *coins, int numCoins){
	int accumChange = 0;
	int nC = numCoins -1;
	
	int *solution = malloc(numCoins * sizeof(int));
	if(solution == NULL) return NULL;
	
	memset(solution, 0, nC); //Initialize solution to 0

	while(accumChange != amount){
		while(nC>=0 && coins[nC] > (amount - accumChange))
			nC--;
			
		if(nC < 0){
			return NULL;
		}else{
			solution[nC] = (amount - accumChange) / coins[nC];
			accumChange += coins[nC] * solution[nC];
		}
	}
	return solution;

}
