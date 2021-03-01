#include <stdio.h>
#include <stdlib.h>

#include "linkedListQueue.h"

int createEmptyQueue(LLQueue *queue){
	if(queue == NULL) return -1;
	
	queue->front = queue->rear = NULL;
	return 0;
}

int isQueueEmpty(LLQueue *queue){
	if(queue == NULL) return -1;

	return (queue->front == 0);
}

int queueAdd(queueElement newElement, LLQueue *queue){
	if(queue == NULL) return -1;
	
	QueueNode *new;
	if(NULL == (new = malloc(sizeof(QueueNode)))) return -2;
	
	new->element = newElement;
	new->next = NULL;

	if(isQueueEmpty(queue) == 1){
		queue->front = queue->rear = new;
	
	}else{
		queue->rear->next = new;
		queue->rear = new;
	}
	return 1;
}

int queueRemove(LLQueue *queue, queueElement *element){
	if(queue == NULL || element == NULL) return -1;
	
	if(isQueueEmpty(queue) == 1){
		return 0;

	}else{
		QueueNode *removed = queue->front;
		*element = removed->element;
		
		queue->front = removed->next;
		if(queue->front == NULL) 
			queue->rear = NULL;
			
		free(removed);
		return 1;	
	}
}


void printQueue(LLQueue *queue){
	if(queue != NULL){
		printf("\nQUEUE\n");
		if(isQueueEmpty(queue) == 1){
			printf("The queue is empty\n");
		}else{
			QueueNode *aux = queue->front;
			printf("| %2d | <- front\n", aux->element);
			aux = aux->next;
			
			while(aux != queue->rear){
				printf("| %2d |\n", aux->element);
				aux = aux->next;
			}	
			
			printf("| %2d | <- rear\n", aux->element);
		}
	}
}



