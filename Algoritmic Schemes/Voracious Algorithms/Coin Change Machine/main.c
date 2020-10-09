#include <stdio.h>
#include <stdlib.h>

#include "chm.h"


int main(int argc, char **argv){
	int i;
	
	int numCoins = 8; //Change numCoins according to coins length
	
	//Coins in cts(€) -> 1cts to 200cts(or 2€)
	int coins[8]={1,2,5,10,20,50,100,200}; //€
	//int coins[6]={1,3,6,12,24,30}; //Old english monetary system
	
	printf("COINS AVAILABLE\n");
	for(i=0; i<numCoins; i++){
		printf("%3d ",coins[i]);
	}

	//Amount in cts in case of € monetary system
	int amount;
	
 	do{
		printf("\n\nAmount (min 1)?:");
		scanf("%d%*c",&amount);
	}while(amount < 1);	
	

	int *solution;
	
	solution = coinsChange(amount, coins, numCoins);
  	printf("\nCOIN CHANGE\n");
  	if(solution == NULL){
  		printf("\n\nCan not change the amount of %d\n",amount);
  	
  	}else{
		for (i =0;i<numCoins;i++) 
			printf("%3d ",solution[i]); 
	}
	
	
	solution = coinsChangeV2(amount, coins, numCoins);
  	printf("\n\nCOIN CHANGE V2\n");
  	if(solution == NULL){
  		printf("\n\nCan not change the amount of %d\n",amount);
  	
  	}else{
		for (i =0;i<numCoins;i++) 
			printf("%3d ",solution[i]); 
	}
		
	puts("\n");
	return 0;
}




