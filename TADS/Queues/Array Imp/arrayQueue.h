#ifndef __ARRAY_QUEUE_H__
#define __ARRAY_QUEUE_H__

#define MAX_QUEUE_SIZE 5

//Queue element
typedef int queueElement;

//Queue structure with array implementation
typedef struct arrayQueue{
	queueElement elements[MAX_QUEUE_SIZE];
	int front, rear, size;
} ArrayQueue;


//Queue methods
void incrementIndex(int *index);

int createEmptyQueue(ArrayQueue *queue);
int isEmpty(ArrayQueue *queue);

int queueAdd(queueElement newElement, ArrayQueue *queue);
int queueRemove(ArrayQueue *queue, queueElement *element);

void printQueue(ArrayQueue *queue);

#endif
