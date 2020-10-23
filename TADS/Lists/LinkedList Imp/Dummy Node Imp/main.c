#include <stdio.h>
#include <stdlib.h>

#include "LLDList.h"


int main(int argc, char **argv){
	LLDList *list;
	
	if(NULL == (list = malloc(sizeof(LLDList)))) return -1;
	

	createEmptyList(list);
	printList(list);
	
	listAdd(5,end(list),list);
	listAdd(8,end(list),list);
	listAdd(3,end(list),list);
	
	listAdd(4,first(list),list);
	printList(list);
	
	listAdd(7, prev(prev(end(list),list),list), list);
	printList(list);
	
	listRemove(first(list),list);
	printList(list);
	
	listElement element = 7;
	int position;
	find(element, list, &position);
	printf("\n\nElement %d finded at position %d\n",element, position);
	
	listPosition posToGet = prev(end(list), list);
	printf("\nElement %d goted\n",get(posToGet, list));
	
	
	clear(list);
	printList(list);
	
	destroy(list);
	
	puts("\n");
	return 0;
}




