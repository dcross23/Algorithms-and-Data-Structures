#ifndef __KRUSKAL_HEAP_H__
#define __KRUSKAL_HEAP_H__

#define MAX_SIZE_K 100

#define KEYS_ORDER >


typedef int HeapKeyK;   
typedef struct edgeTwoVertex{
	int u, v; 
} HeapInfoK;	

typedef struct{
	HeapKeyK key;
	HeapInfoK info;
} HeapElementK;

typedef struct{ 
	HeapElementK elements[MAX_SIZE_K];
	int size;
} HeapK;


// HeapK methods 
int initHeapK(HeapK *h);
int isHeapKEmpty(HeapK *h);
int addK(HeapElementK x, HeapK *h);
int removeTopK(HeapK *h, HeapElementK *minElement);
int decrementKeyK(int pos, HeapKeyK amount, HeapK *h);
int incrementKeyK(int pos, HeapKeyK amount, HeapK *h);
int isHeapK(HeapK *h);

int heapifyK(HeapK *h);

// Filtering functions
void descFilteringK(HeapK *h, int posToFilter);
void ascFilteringK(HeapK *h, int posToFilter);

#endif
