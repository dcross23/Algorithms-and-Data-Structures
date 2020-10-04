#ifndef __ARRAYS_UTILITY__
#define __ARRAYS_UTILITY__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Arrays utilities
int *createArray(int size);
int *createSortedArray(int size);
void printArray(int *array, int arraySize);

void swap(int *array, int i, int j);

//Lists utilities
typedef struct node{
	int info;
	struct node *next;
}Node;

Node* createNode(int info);
void createList(Node **list, int numNodes);
void printList(Node *list);

#endif
