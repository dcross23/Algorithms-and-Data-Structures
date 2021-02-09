#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "heap.h"

void printHeap(Heap *h);

int main(void){
	srand(time(NULL));
	int i;

	Heap h;
	heapElement element;
	int n=6;

	initHeap(&h);

	//Add an element	
	element.key=4;
	element.info=1;
	printf("\n\x1b[36;1mAdding an element with key = %d\x1b[0m\n", element.key);
	add(element,&h);
	printHeap(&h);

	//Add some more elements
	printf("\n\n\x1b[36;1mAdding random elements\x1b[0m\n");
	while (h.size < n){
	 	element.key= rand() % 10;
		add(element,&h);
	}
	printHeap(&h);
	
	//Add one more to see how it is filtered
	element.key=9;
	element.info=0;
	printf("\n\n\x1b[36;1mAdding an element with key = %d\x1b[0m\n", element.key);
	add(element,&h);
	printHeap(&h);


	//Removing top element
	heapElement topElement;
	removeTop(&h, &topElement);
	printf("\n\n\x1b[36;1mRemoving min priority(key) element: %d\x1b[0m\n", topElement.key);
	printHeap(&h);


	//Try to decrement a key (to half of the value)		
	#if 1 KEYS_ORDER 2
		int pos = 2;
	#else
		int pos = 5;
	#endif
			
	int amount = h.elements[pos].key/2 + 1;
	printf("\n\n\x1b[36;1mDecrementing key at pos %d, amount: %d (%d -> %d)\x1b[0m\n", pos, amount, h.elements[pos].key, h.elements[pos].key-amount);
	decrementKey(pos, amount, &h);
	printHeap(&h);

	
	#if 1 KEYS_ORDER 2
		pos = 5;
	#else
		pos = 2;
	#endif
	amount = h.elements[pos].key * 3;
	printf("\n\n\x1b[36;1mIncrementing key at pos %d, amount: %d (%d -> %d)\x1b[0m\n", pos, amount, h.elements[pos].key, h.elements[pos].key+amount);
	incrementKey(pos, amount ,&h);
	printHeap(&h);
	
	printf("\n\n\x1b[36;1mIs a correct heap?:\x1b[0m");
	if(isHeap(&h))  printf("\x1b[35;1m YES\x1b[0m\n\n");
	else		printf("\x1b[35;1m NO\x1b[0m\n\n");



	for(i=0; i<=50; i++){
		printf("-");
	}


	//Creating a heap from array		
	Heap h2;
	h2.size = 6;
	
	printf("\n\n\x1b[36;1mRandom array of %d elements: \x1b[35;1m", h2.size);
	for (i=1; i<=h2.size; i++){
		h2.elements[i].key = rand() % 10;
		h2.elements[i].info = 0;
		printf("%d ",h2.elements[i].key);

	}

	printf("\n\n\x1b[36;1mIs a correct heap?:\x1b[0m");
	if(isHeap(&h2))  printf("\x1b[35;1m YES\x1b[0m\n");
	else		printf("\x1b[35;1m NO\x1b[0m\n");

	printf("\n\x1b[36;1mCreating heap(h2) from random array....");
	heapify(&h2);
	printf(" Heap created\x1b[0m\n");
	printHeap(&h2);
	
	printf("\n\x1b[36;1mIs now h2 a correct heap?:\x1b[0m");
	if(isHeap(&h2))  printf("\x1b[35;1m YES\x1b[0m\n");
	else		printf("\x1b[35;1m NO\x1b[0m\n");

	return 0;
}




void printHeap(Heap *h){
	int i;
	for(i=0; i<=h->size*3 + 15; i++){
		printf("=");
	}
	
	printf("\n\tHEAP\n");
	
	for(i=0; i<=h->size*3 + 15; i++){
		printf("=");
	}
	
	printf("\n%9s | ","position");
	for(i=0; i<=h->size; i++){
		printf("%2d ",i);
	}
	
	printf("\n");
	for(i=0; i<=h->size*3 + 15; i++){
		printf("-");
	}
	
	printf("\n%9s | %2c ","elements", '_');	
	for (i=1;i<=h->size;i++)
		printf("%2d ",h->elements[i].key);
	printf("\n");

	for(i=0; i<=h->size*3 + 15; i++){
		printf("=");
	}
	
	printf("\n");
}


