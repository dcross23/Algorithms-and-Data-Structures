#include <stdio.h>
#include <stdlib.h>

#include "linkedListStack.h"

int createEmptyStack(LLStack *stack){
	if(stack == NULL) return -1;
	
	*stack == NULL;
	return 0;
}

int isEmpty(LLStack *stack){
	if(stack == NULL) 
		return -1;
		
	return (*stack == NULL);	
}


int push(stackElement newElement, LLStack *stack){
	if(stack == NULL) return -1;
	
	StackNode *new;
	if(NULL == (new = malloc(sizeof(StackNode)))) return -2;
	
	new->element = newElement;
	new->next = *stack;
	*stack = new;	
	return 0;
}
	
int pop(LLStack *stack, stackElement *returnedElement){
	if(stack == NULL || returnedElement == NULL) return -1;
	
	if(isEmpty(stack) == 1) 
		return 0;
	else{
		StackNode *poped = *stack;
		*returnedElement = poped->element;
		
		*stack = poped->next;
		free(poped);
		return 1;
	}
}

int getTopElement(LLStack *stack, stackElement *returnedElement){
	if(stack == NULL || returnedElement == NULL) return -1;
	
	if(isEmpty(stack) == 1) 
		return 0;
	else{
		*returnedElement = (*stack)->element;
		return 1;
	}
}

void printStack(LLStack *stack){
	if(stack != NULL){
		printf("\nSTACK\n");
		if(isEmpty(stack) == 1){
			printf("The stack is empty\n");
		}else{
			StackNode *aux = *stack;			
			printf("| %2d | <- top\n", aux->element);
			aux = aux->next;

			while(aux != NULL){
				printf("| %2d |\n", aux->element);
				aux = aux->next;
			}
			
			printf("+----+");
		}
	}
}


