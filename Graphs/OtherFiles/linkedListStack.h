#ifndef __LINKED_LIST_STACK_H__
#define __LINKED_LIST_STACK_H__

#define MAX_STACK_SIZE 100

//Stack element
typedef int stackElement;

//Stack structure with linked list implementation
typedef struct stackNode {
	stackElement element;
	struct stackNode *next;
} StackNode;

typedef StackNode* LLStack;

//Stack methods
int createEmptyStack(LLStack *stack);
int isStackEmpty(LLStack *stack);

int push(stackElement newElement, LLStack *stack);
int pop(LLStack *stack, stackElement *returnedElement);

int getTopElement(LLStack *stack, stackElement *returnedElement);

void printStack(LLStack *stack);

#endif
