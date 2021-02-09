#ifndef __TREE_MODIFIED_QUEUE_H__
#define __TREE_MODIFIED_QUEUE_H__

#include "binaryTree.h"

//Queue element
typedef BinaryTree queueElement;

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


#endif
