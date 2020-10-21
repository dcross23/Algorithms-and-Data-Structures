#include <stdio.h>
#include <stdlib.h>

#include "arrayList.h"


int main(int argc, char **argv){
	ArrayList *list;
	
	if(NULL == (list = malloc(sizeof(ArrayList)))) return -1;
	

	createEmptyList(list);
	printList(list);
	
	listAdd(5,end(list),list);
	listAdd(8,end(list),list);
	listAdd(3,end(list),list);
	
	listAdd(4,first(list),list);
	printList(list);
	
	
	listAdd(7,end(list)-2,list);
	printList(list);
	
	listRemove(first(list),list);
	printList(list);
	
	listElement element = 7;
	printf("\n\nElement %d finded at position %d\n",element, find(element,list));
	
	listPosition posToGet = end(list) - 1;
	printf("\nElement %d goted from position %d\n",get(posToGet, list), posToGet);
	
	
	clear(list);
	printList(list);
	
	puts("\n");
	return 0;
}




