#include <stdio.h>
#include <stdlib.h>

#include "arraysListsUtilities.h"
#include "dcAlgorithms.h"

int callTernarySearch(void);

int main(int argc, char **argv){
	
	//Code for ternary search
	//return callTernarySearch();

	//Code for powerOf
	/*
	int num;
	int exp;
	
	printf("Num?:");
	scanf("%d%*c",&num);
	
	printf("Exp?:");
	scanf("%d%*c",&exp);
	
	if(num <0 || exp<=0) return -1;
	
	int res = powerOf(num,exp);
	printf("\n%d power to %d is %d\n",num, exp, res);
	return  0;
	*/

}



int callTernarySearch(void){
	int *array;
	int arraySize;
	int valueToFind;
	
	printf("Array size?:");
	scanf("%d%*c",&arraySize);
	
	array = createSortedArray(arraySize);
	
	if(array == NULL) return -1;

	printArray(array,arraySize);
	printf("\n");
	
	printf("\nValue?:");
	scanf("%d%*c",&valueToFind);

	int pos = ternarySearch(valueToFind,array,0,arraySize-1);

	if(pos == -1)
		printf("\nCan not find value %d in the array\n",valueToFind);
	else
		printf("\nValue %d finded at pos %d\n",valueToFind, pos);		
			
	return 0;

}



