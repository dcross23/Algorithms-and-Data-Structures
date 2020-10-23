#ifndef __LINKED_LIST_QUEUE_H__
#define __LINKED_LIST_QUEUE_H__

//Queue element
typedef int queueElement;

//Queue structure with linked list implementation
typedef struct queueNode {
	queueElement element;
	struct queueNode * next;
} QueueNode;


typedef struct {
        QueueNode *front, *rear;
} LLQueue;


//Stack methods
int createEmptyQueue(LLQueue *queue);
int isEmpty(LLQueue *queue);

int queueAdd(queueElement newElement, LLQueue *queue);
int queueRemove(LLQueue *queue, queueElement *element);

void printQueue(LLQueue *queue);

#endif
