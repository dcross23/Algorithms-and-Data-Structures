#include <stdio.h>
#include <stdlib.h>

#include "linkedListQueue.h"


int main(int argc, char **argv){
	LLQueue *queue;
	
	if(NULL == (queue = malloc(sizeof(LLQueue)))) return -1;
	
	createEmptyQueue(queue);
	
	printQueue(queue);
	
	printf("\n\nAdding 5,3,8");
	queueAdd(5,queue);	
	queueAdd(3,queue);
	queueAdd(8,queue);
	
	printQueue(queue);
	
	printf("\n\nAdding 2,1");
	queueAdd(2,queue);
	queueAdd(1,queue);
	
	printQueue(queue);
	
	int l;
	printf("\n\nRemoving element...");
	queueRemove(queue, &l);
	
	printQueue(queue);	
	
	printf("\n\nRemoving element...");
	queueRemove(queue, &l);
	
	printQueue(queue);
	
	printf("\n\nAdding 4,6");
	queueAdd(4,queue);
	queueAdd(6,queue);
	
	printQueue(queue);
	
	puts("\n");
	return 0;
}




