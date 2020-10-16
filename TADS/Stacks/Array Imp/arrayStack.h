#ifndef __MATRIX_STACK_H__
#define __MATRIX_STACK_H__

#define MAX_STACK_SIZE 100

//Stack element
typedef int stackElement;

//Stack structure with array implementation
typedef struct arrayStack {
	stackElement elements[MAX_STACK_SIZE];
	int top;
} ArrayStack;

//Stack methods
int createEmptyStack(ArrayStack *stack);
int isEmpty(ArrayStack *stack);

int push(stackElement newElement, ArrayStack *stack);
int pop(ArrayStack *stack, stackElement *returnedElement);

int getTopElement(ArrayStack *stack, stackElement *returnedElement);

void printStack(ArrayStack *stack);

#endif
