#include <stdio.h>
#include <stdlib.h>

#include "arrayStack.h"

int createEmptyStack(ArrayStack *stack){
	if(stack == NULL) 
		return -1;
	
	stack->top = -1;
	return 0;
}

int isEmpty(ArrayStack *stack){
	if(stack == NULL) 
		return -1;
		
	if(stack->top == -1) return 1;
	else		     return 0;
}


int push(stackElement newElement, ArrayStack *stack){
	if(stack == NULL) return -1;
	
	if(stack->top == MAX_STACK_SIZE-1){
		return 0; //There is no more space
	
	}else{
		stack->top++;
		stack->elements[stack->top] = newElement;	
		return 1;		
	}
}


int pop(ArrayStack *stack, stackElement *returnedElement){
	if(stack == NULL || returnedElement == NULL) return -1;
	
	if(isEmpty(stack) == 1) return 0;
	else{
		*returnedElement = stack->elements[stack->top];
		stack->top--;
		return 1;
	}
}

int getTopElement(ArrayStack *stack, stackElement *returnedElement){
	if(stack == NULL || returnedElement == NULL) return -1;
	
	if(isEmpty(stack) == 1) return 0;
	else{
		*returnedElement = stack->elements[stack->top];
		return 1;
	}
}

void printStack(ArrayStack *stack){
	if(stack != NULL){
		printf("\nSTACK\n");
		if(isEmpty(stack) == 1){
			printf("The stack is empty\n");
		}else{
			int i;
			printf("| %2d | <- top\n", stack->elements[stack->top]);
			for(i=stack->top-1; i>=0; i--){
				printf("| %2d |\n", stack->elements[i]);
			}	
			
			printf("+----+");
		}
	}
}


