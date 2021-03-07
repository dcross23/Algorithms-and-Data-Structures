#include "kruskalHeap.h"
#include <stdlib.h>

/**
 * Filtering functions:
 * Filters an element to his correct position in case one or more of his 
 *  childs have a lower/greater key (depending on the keys order).
 */
void descFilteringK(HeapK *h, int posToFilter){
	#if 1 KEYS_ORDER 2
		#define KEYS_ORDER_OPPOSITE >
	#else
		#define KEYS_ORDER_OPPOSITE <
	#endif

	if(h != NULL){
		HeapElementK aux = h->elements[posToFilter];
		int endFiltering = 0;
		HeapKeyK child;

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

void ascFilteringK(HeapK *h, int posToFilter){
	if(h != NULL){
		HeapElementK aux = h->elements[posToFilter];
		while(posToFilter>1 && h->elements[posToFilter/2].key  KEYS_ORDER  aux.key){
			h->elements[posToFilter] = h->elements[posToFilter/2];
			posToFilter = posToFilter/2;
		}	
		h->elements[posToFilter] = aux;		
	}
}



/**
 * Clears and init a HeapK. Returns -1 in case there is an error,
 *  return 0 if there are no errors.
 */
int initHeapK(HeapK *h){
	if(h == NULL) return -1;
	h->size=0;
	return 0;
}



/**
 * Returns 1(true) if HeapK is empty, 0(false) if not.
 * Returns -1 in case there is an error.
 */
int isHeapKEmpty(HeapK *h){
	if (h == NULL) return -1;
	else return (h->size == 0);
}


/**
 * Inserts element x in HeapK h to his correct position 
 * Returns -1 in case there is an error,
 *  return 0 if there are no errors.
 */
int addK(HeapElementK x, HeapK *h){
	if(h == NULL || h->size>=MAX_SIZE_K) 
		return -1;
	else{
		h->size++;
		h->elements[h->size] = x;
		ascFilteringK(h,h->size);		
		return 0;
	}
}



/**
 * Removes the top element (element with higher priority(key)) and 
 *  reorganises the HeapK to mantain correct order.
 * This element can be minimun or maximun element of the HeapK,
 *  depending on the keys order definition.
 * Returns -1 in case there is an error, return 0 if there are no errors.
 */
int removeTopK(HeapK *h, HeapElementK *topElement){
	if(h==NULL || isHeapKEmpty(h))
		return -1;
	else{
		*topElement = h->elements[1];
		h->elements[1] = h->elements[h->size];
		h->size--;
		descFilteringK(h,1);
		return 0;
	}
}

/**
 * Decrements priority (key) of the element at position "pos" by an
 *  amount "amount" and reorganises the HeapK to mantain correct order.
 * Returns -1 in case there is an error, return 0 if there are no errors.
 */
int decrementKeyK(int pos, HeapKeyK amount, HeapK *h){
	if(h==NULL || amount<=0 || pos<1 || pos>h->size) 
		return -1;

	h->elements[pos].key -= amount;
	
	#if 1 KEYS_ORDER 2
		descFilteringK(h,pos);
	#else
		ascFilteringK(h,pos);
	#endif
	return 0;
}


/**
 * Increments priority (key) of the element at position "pos" by an
 *  amount "amount" and reorganises the HeapK to mantain correct order.
 * Returns -1 in case there is an error, return 0 if there are no errors.
 */
int incrementKeyK(int pos, HeapKeyK amount, HeapK *h){
	if(h==NULL || amount<=0 || pos<1 || pos>h->size) 
		return -1;

	h->elements[pos].key += amount;
	
	#if 1 KEYS_ORDER 2
		ascFilteringK(h,pos);
	#else
		descFilteringK(h,pos);
	#endif
	return 0;
}

/*
 * Returns 1 if the HeapK satisfies the conditions to be a HeapK.
 *  (This conditions depend on keys order definition). If the HeapK
 *  doesnt satisfy the conditions, returns 0.
 * Returns -1 in case there is an error.
 */
int isHeapK(HeapK *h){
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
 * Creates a HeapK from any array inserted previously in "h" elements array
 */
int heapifyK(HeapK *h){
	if(h == NULL) return -1;
	
	int i;
	int n = h->size;
	for(i=n/2; i>=1; i--)
		descFilteringK(h,i);
	return 0;
}


