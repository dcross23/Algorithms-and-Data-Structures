#include <stdio.h>
#include <stdlib.h>

#include "LLDisjointSet.h"

void printPartition(LLDsPartition p);

int main(){ 
	LLDsPartition p;
	int i;

	create(p);
	printf("\x1b[36;1mInitial situation:\x1b[0m\n");
	printPartition(p);

	// Sets we want in the partition (1rst number is the representant):
	// {7,0,13,15},{2,3,8,12},{11,1,4,6,14},{9,5,10}

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

	printf("\nElement 5 belongs to set (with representant):\x1b[36;1m %d \x1b[0m\n\n",search(5,p));
	
	return 0;
}

    
void printPartition(LLDsPartition p){
	int i;
	LLDsSetNode *aux;
	for(i=0; i<MAX_SETS; i++){
		aux = p[i].first;
		if(aux != NULL){
			 printf("\x1b[35;1m %2d\x1b[0m -> ",aux->element);
			 aux = aux->next;
		
			 while (aux!=NULL)
			 { 
				printf("%2d -> ",aux->element);
			  	aux=aux->next;
			 }
			 
			 printf(" -\n");
		}
	}
	printf("\n");
}
