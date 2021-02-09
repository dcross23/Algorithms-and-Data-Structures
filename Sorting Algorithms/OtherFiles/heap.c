#include "heap.h"
#include <stdlib.h>


/**
 * Filtering functions:
 * Filters an element to his correct position in case one or more of his 
 *  childs have a lower/greater key (depending on the keys order).
 */
void descFiltering(Heap *h, int posToFilter){
	#if 1 KEYS_ORDER 2
		#define KEYS_ORDER_OPPOSITE >
	#else
		#define KEYS_ORDER_OPPOSITE <
	#endif

	if(h != NULL){
		heapElement aux = h->elements[posToFilter];
		int endFiltering = 0;
		heapKey child;

		while(2*posToFilter<=h->size && !endFiltering){
			child=2*posToFilter;	
			if(child != h->size){
				if(h->elements[child+1].key  KEYS_ORDER_OPPOSITE  h->elements[child].key)
					child++;
			}
			
			if(h->elements[child].key  KEYS_ORDER_OPPOSITE  aux.key){
				h->elements[posToFilter] = h->elements[child];
				posToFilter = child;		
			}else
				endFiltering = 1;		
		}
		h->elements[posToFilter] = aux;	
	}
}

void ascFiltering(Heap *h, int posToFilter){
	if(h != NULL){
		heapElement aux = h->elements[posToFilter];
		while(posToFilter>1 && h->elements[posToFilter/2].key  KEYS_ORDER  aux.key){
			h->elements[posToFilter] = h->elements[posToFilter/2];
			posToFilter = posToFilter/2;
		}	
		h->elements[posToFilter] = aux;		
	}
}



/**
 * Clears and init a heap. Returns -1 in case there is an error,
 *  return 0 if there are no errors.
 */
int initHeap(Heap *h){
	if(h == NULL) return -1;
	h->size=0;
	return 0;
}



/**
 * Returns 1(true) if heap is empty, 0(false) if not.
 * Returns -1 in case there is an error.
 */
int isHeapEmpty(Heap *h){
	if (h == NULL) return -1;
	else return (h->size == 0);
}


/**
 * Inserts element x in heap h to his correct position 
 * Returns -1 in case there is an error,
 *  return 0 if there are no errors.
 */
int add(heapElement x, Heap *h){
	if(h == NULL || h->size>=MAX_SIZE) 
		return -1;
	else{
		h->size++;
		h->elements[h->size] = x;
		ascFiltering(h,h->size);		
		return 0;
	}
}



/**
 * Removes the top element (element with higher priority(key)) and 
 *  reorganises the heap to mantain correct order.
 * This element can be minimun or maximun element of the heap,
 *  depending on the keys order definition.
 * Returns -1 in case there is an error, return 0 if there are no errors.
 */
int removeTop(Heap *h, heapElement *topElement){
	if(h==NULL || isHeapEmpty(h))
		return -1;
	else{
		*topElement = h->elements[1];
		h->elements[1] = h->elements[h->size];
		h->size--;
		descFiltering(h,1);
		return 0;
	}
}

/**
 * Decrements priority (key) of the element at position "pos" by an
 *  amount "amount" and reorganises the heap to mantain correct order.
 * Returns -1 in case there is an error, return 0 if there are no errors.
 */
int decrementKey(int pos, heapKey amount, Heap *h){
	if(h==NULL || amount<=0 || pos<1 || pos>h->size) 
		return -1;

	h->elements[pos].key -= amount;
	
	#if 1 KEYS_ORDER 2
		descFiltering(h,pos);
	#else
		ascFiltering(h,pos);
	#endif
	return 0;
}


/**
 * Increments priority (key) of the element at position "pos" by an
 *  amount "amount" and reorganises the heap to mantain correct order.
 * Returns -1 in case there is an error, return 0 if there are no errors.
 */
int incrementKey(int pos, heapKey amount, Heap *h){
	if(h==NULL || amount<=0 || pos<1 || pos>h->size) 
		return -1;

	h->elements[pos].key += amount;
	
	#if 1 KEYS_ORDER 2
		ascFiltering(h,pos);
	#else
		descFiltering(h,pos);
	#endif
	return 0;
}

/*
 * Returns 1 if the Heap satisfies the conditions to be a Heap.
 *  (This conditions depend on keys order definition). If the heap
 *  doesnt satisfy the conditions, returns 0.
 * Returns -1 in case there is an error.
 */
int isHeap(Heap *h){
	if(h == NULL) return -1;

	int n = h->size;
	int i, child;
	
	for(i=1; i<=n/2; i++){
		child = 2*i;
		// Checks left child
		if(h->elements[i].key  KEYS_ORDER  h->elements[child].key)
			return 0;

		// Checks right child
		else if(child != n && h->elements[i].key  KEYS_ORDER  h->elements[child+1].key)
			return 0;
	}
	return 1;
}

/**
 * Creates a heap from any array inserted previously in "h" elements array
 */
int heapify(Heap *h){
	if(h == NULL) return -1;
	
	int i;
	int n = h->size;
	for(i=n/2; i>=1; i--)
		descFiltering(h,i);
	return 0;
}



