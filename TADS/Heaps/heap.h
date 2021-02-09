#ifndef __HEAP_H__
#define __HEAP_H__

#define MAX_SIZE 100


/**
 *This macro will change the order of the keys in the heap. This is, a child
 *will have lower or greater key than his parent just changing the macro.
 *Values:
 * - KEYS_ORDER = >  --> child key will be greater than his parent key
 *    Example:           3
 *    		       /   \
 *    		      4     6
 *
 * - KEYS_ORDER = <  --> child key will be lower than his parent key
 *     Example:          7
 *    		       /   \
 *    		      6     4
 */
#define KEYS_ORDER <


typedef int heapKey;   
typedef int heapInfo;	

typedef struct{
	heapKey key;
	heapInfo info;
} heapElement;

typedef struct{ 
	heapElement elements[MAX_SIZE];
	int size;
} Heap;


// Heap methods 
int initHeap(Heap *h);
int isHeapEmpty(Heap *h);
int add(heapElement x, Heap *h);
int removeTop(Heap *h, heapElement *minElement);
int decrementKey(int pos, heapKey amount, Heap *h);
int incrementKey(int pos, heapKey amount, Heap *h);
int isHeap(Heap *h);

int heapify(Heap *h);

// Filtering functions
void descFiltering(Heap *h, int posToFilter);
void ascFiltering(Heap *h, int posToFilter);


//void heapsort(Monticulo *m);

#endif
