#include <stdio.h>
#include <stdlib.h>

#include "hanoi.h"


int main(int argc, char **argv){
	
	int disks, i, j;

	#ifdef DRAW_TOWERS 
		char *towers[3];
		
		for(i=0; i<3; i++){
			if(NULL == (towers[i] = malloc(disks * sizeof(char)))){
				for(j=i-1; j>=0; j--){
					free(towers[i]);
				}
				return -1;
			}
		}
	#endif
	
	
	do{
		printf("\nNumber of disks?(min 1):");
		scanf("%d%*c",&disks);
		if(disks <=0) 
			printf("\n\tInvalid number of disks");
		
	}while(disks <= 0);	
	
	
	
	#ifdef DRAW_TOWERS 
		initTowers(towers, disks);
		showTowers(towers, disks);
		hanoi(towers,disks, disks,1,3,2);
	#else
		printf("\n(%d,%d,%d,%d)\n",disks,1,2,3);
		simpleHanoi(disks,1,3,2);
	#endif	
	

	printf("\n\nMinimun number of movements: %ld\n\n",(long)(pow(2,disks) - 1));

	return 0;
}




