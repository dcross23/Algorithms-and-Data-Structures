#include <stdio.h>
#include <stdlib.h>

#include "arrayStack.h"


int main(int argc, char **argv){
	ArrayStack *stack;
	
	if(NULL == (stack = malloc(sizeof(ArrayStack)))){
		return -1;
	}
	
	createEmptyStack(stack);
	
	printStack(stack);
	
	push(5,stack);
	push(3,stack);
	push(8,stack);
	
	printStack(stack);
	
	stackElement topElement;
	if(getTopElement(stack, &topElement) == 1)
		printf("\n\nThe top element is:%d\n",topElement);
	else
		printf("\n\nThe stack is empty\n");
		
	printStack(stack);	
		
	if(pop(stack, &topElement) == 1)
		printf("\n\nThe element poped is:%d\n",topElement);
	else
		printf("\n\nThe stack is empty\n");	
		
	printStack(stack);
	
	while(!isEmpty(stack)){
		pop(stack,&topElement);
	}
	
	printf("\n");
	printStack(stack);
	
	free(stack);	
	
	puts("\n");
	return 0;
}




