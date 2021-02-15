#include <stdio.h>
#include <stdlib.h>

#include "TreeDisjointSet.h"

void printPartition(TDsPartition p);

int main(){ 
	TDsPartition p;
	int i;
	
	// Sets we want in the partition (1rst number is the representant):
	// {7,0,13,15},{2,3,8,12},{11,1,4,6,14},{9,5,10}
	

	//Normal implementation 
	printf("\x1b[33;1m====================================================\x1b[0m\n");
	printf("\x1b[33;1m\t\tNORMAL IMPLEMENTATION\x1b[0m\n");
	printf("\x1b[33;1m====================================================\x1b[0m\n");
	
	create(p);
	printf("\x1b[36;1mInitial situation:\x1b[0m\n");
	printPartition(p);

	join(search(13,p), search(15,p), p);		
	join(search(7,p), search(0,p), p);		
	join(search(7,p), search(13,p), p);	

	join(search(8,p), search(12,p), p);		
	join(search(3,p), search(8,p), p);	
	join(search(2,p), search(3,p), p);		

	join(search(6,p), search(1,p), p);
	join(search(6,p), search(4,p), p);	
	join(search(11,p), search(14,p), p);	
	join(search(11,p), search(6,p), p);

	join(search(5,p), search(10,p), p);	
	join(search(9,p), search(5,p), p);		

	printf("\x1b[36;1mFinal situation:\x1b[0m\n");
	printPartition(p);

	printf("Element 5 belongs to set (with representant):\x1b[36;1m %d \x1b[0m\n\n",search(5,p));
	printf("\n\n\n");
	
	
	//Join (union) by height
	printf("\x1b[33;1m====================================================\x1b[0m\n");
	printf("\x1b[33;1m\t\tUNION BY HEIGHT\x1b[0m\n");
	printf("\x1b[33;1m====================================================\x1b[0m\n");

	create(p);
	printf("\x1b[36;1mInitial situation:\x1b[0m\n");
	printPartition(p);

	joinByHeight(search(13,p), search(15,p), p);		
	joinByHeight(search(7,p), search(0,p), p);		
	joinByHeight(search(7,p), search(13,p), p);	

	joinByHeight(search(8,p), search(12,p), p);		
	joinByHeight(search(2,p), search(3,p), p);	
	joinByHeight(search(3,p), search(8,p), p);	

	joinByHeight(search(6,p), search(1,p), p);
	joinByHeight(search(6,p), search(4,p), p);	
	joinByHeight(search(11,p), search(14,p), p);	
	joinByHeight(search(11,p), search(6,p), p);

	joinByHeight(search(9,p), search(5,p), p);	
	joinByHeight(search(5,p), search(10,p), p);	

	printf("\x1b[36;1mFinal situation:\x1b[0m\n");
	printPartition(p);

	printf("\nElement 5 belongs to set (with representant):\x1b[36;1m %d \x1b[0m\n\n",search(5,p));
	printf("\n\n\n");
	
	
	//Join (union) by size
	printf("\x1b[33;1m====================================================\x1b[0m\n");
	printf("\x1b[33;1m\t\tUNION BY SIZE\x1b[0m\n");
	printf("\x1b[33;1m====================================================\x1b[0m\n");

	create(p);
	printf("\x1b[36;1mInitial situation:\x1b[0m\n");
	printPartition(p);

	joinBySize(search(13,p), search(15,p), p);		
	joinBySize(search(7,p), search(0,p), p);		
	joinBySize(search(7,p), search(13,p), p);	

	joinBySize(search(8,p), search(12,p), p);		
	joinBySize(search(2,p), search(3,p), p);	
	joinBySize(search(3,p), search(8,p), p);	

	joinBySize(search(6,p), search(1,p), p);
	joinBySize(search(11,p), search(14,p), p);	
	joinBySize(search(11,p), search(6,p), p);
	joinBySize(search(6,p), search(4,p), p);

	joinBySize(search(9,p), search(5,p), p);	
	joinBySize(search(5,p), search(10,p), p);	

	printf("\x1b[36;1mFinal situation:\x1b[0m\n");
	printPartition(p);

	printf("\nElement 5 belongs to set (with representant):\x1b[36;1m %d \x1b[0m\n\n",search(5,p));
	printf("\n\n\n");
	
	
	//Path compression
	printf("\x1b[33;1m====================================================\x1b[0m\n");
	printf("\x1b[33;1m\t\tPATH COMPRESSION\x1b[0m\n");
	printf("\x1b[33;1m====================================================\x1b[0m\n");
	printf("\x1b[33;2m(^ mark shows the position of the element to search that probably will change)\x1b[0m\n\n");
	
	int elementToChange = 12;
	
	printf("\x1b[36;1mBefore path compression:\x1b[0m\n");
	printPartition(p);
	
	for(i=0; i<3*elementToChange+2;i++){
		printf(" ");
	}
	printf("\x1b[33;1m^\x1b[0m\n");
	
	
	printf("\nElement %d belongs to set (with representant):\x1b[36;1m %d \x1b[0m\n\n\n",elementToChange, pathCompressionSearch(elementToChange,p));
	
	printf("\x1b[36;1mAfter path compression:\x1b[0m\n");
	printPartition(p);
	
	for(i=0; i<3*elementToChange+2;i++){
		printf(" ");
	}
	printf("\x1b[33;1m^\x1b[0m\n");
	
	return 0;
}

    
void printPartition(TDsPartition p){
	int i;

	for (i =0;i<MAX_SETS;i++) 
		printf("|%2d",p[i]);
	printf("|   array elements (set representant)\n");

	for (i =0;i<MAX_SETS;i++) 
		printf("---");
	printf("-\n");

	//Representants of each set are represented in purple
	for (i =0;i<MAX_SETS;i++)
		if(0 < p[i])
			printf(" %2d",i);
		else
			printf("\x1b[35;1m %2d\x1b[0m",i);
	printf("    array indexes (set elements)\n\n");
}
