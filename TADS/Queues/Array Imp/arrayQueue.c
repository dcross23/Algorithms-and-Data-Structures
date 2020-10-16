#include <stdio.h>
#include <stdlib.h>

#include "arrayQueue.h"

void incrementIndex(int *index){
	if(index != NULL){
		if(*index == MAX_QUEUE_SIZE-1)
			*index = 0;
		else
			(*index)++;	
	}
}



int createEmptyQueue(ArrayQueue *queue){
	if(queue == NULL) return -1;
	
	queue->size = 0;
	queue->front = 0;
	queue->rear = MAX_QUEUE_SIZE-1;
	return 0;
}

int isEmpty(ArrayQueue *queue){
	if(queue == NULL) return -1;

	return (queue->size == 0);
}

int queueAdd(queueElement newElement, ArrayQueue *queue){
	if(queue == NULL) return -1;
	
	if(queue->size == MAX_QUEUE_SIZE){
		return 0;
		
	}else{
		incrementIndex(&(queue->rear));
		queue->elements[queue->rear] = newElement;
		(queue->size)++;
		return 1;
	}
}


int queueRemove(ArrayQueue *queue, queueElement *element){
	if(queue == NULL || element == NULL) return -1;
	
	if(isEmpty(queue) == 1){
		return 0;

	}else{
		*element = queue->elements[queue->front];
		incrementIndex(&(queue->front));
		(queue->size)--;
		return 1;	
	}
}


void printQueue(ArrayQueue *queue){
	if(queue != NULL){
		printf("\nQUEUE\n");
		if(isEmpty(queue) == 1){
			printf("The queue is empty\n");
		}else{
			int i = queue->front;
			printf("| %2d | <- front\n", queue->elements[queue->front]);
			incrementIndex(&i);
			
			while(i != queue->rear){
				printf("| %2d |\n", queue->elements[i]);
				incrementIndex(&i);
			}	
			
			printf("| %2d | <- rear\n", queue->elements[queue->rear]);
		}
	}
}

