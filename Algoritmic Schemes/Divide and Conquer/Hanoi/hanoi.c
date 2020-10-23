#include "hanoi.h"

/* Hanoi Towers problem solved with recursion (dyc algorithm)
 *   O(2^n)
 *  Minimun number of movements to solve it: 2^(number of disks) - 1
 */

//Simple gui hanoi version
void simpleHanoi(int disks, int origen, int destination, int aux){
	if(disks > 0){
		simpleHanoi(disks-1, origen, aux, destination);
		
		printf("\nMoves disk %d from tower %c to tower %c",disks,origen,destination);
		printf("\n(%d,%d,%d,%d)\n",disks,origen,destination,aux);
		
		simpleHanoi(disks-1, aux, destination, origen);
	}
}

//Better gui hanoi version
void hanoi(char **towers, int disks, int currentDisks, int origen, int destination, int aux){
	if(currentDisks > 0){
		hanoi(towers,disks, currentDisks-1, origen, aux, destination);
		
		moveTowers(towers, disks, origen, destination);		
		showTowers(towers, disks);
		
		hanoi(towers,disks, currentDisks-1, aux, destination, origen);
	}
}



/* Funtions to display hanoi
 *  in a graphical way.
 */
void initTowers(char **towers, int disks){
	int i,j;
	
	for(i=0, j=disks; i<disks; i++,j--){
		towers[0][i] = (char)(j+48);
	}

	for(i=0; i<disks; i++){
		towers[1][i] = towers[2][i] = (char)32;
	}
}

void showTowers(char **towers, int disks){
	int i;
	printf("\n");
	for(i=disks-1; i>=0; i--){
		printf("  | %c |    | %c |    | %c |\n",towers[0][i],towers[1][i],towers[2][i]);
	}
	printf("  +---+    +---+    +---+\n\n");
}

void moveTowers(char **towers, int disks, int o, int d){
	int i;
	char diskValue;

	//Origin
	i=disks-1;
	while(towers[o-1][i] == (char) 32) 
		i--;
	diskValue = towers[o-1][i];
	towers[o-1][i] = (char) 32;

	//Destination
	i=0;
	while(towers[d-1][i] != (char)32) 
		i++;
		
	towers[d-1][i] = diskValue;
}
