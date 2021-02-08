#ifndef __TREE_MODIF_STACK_H__
#define __TREE_MODIF_STACK_H__

#include "../binaryTree.h"

#define MAX_STACK_SIZE 100

//Stack element
typedef BinaryTree stackElement;

//Stack structure with linked list implementation
typedef struct stackNode {
	stackElement element;
	struct stackNode *next;
} StackNode;

typedef StackNode* LLStack;

//Stack methods
int createEmptyStack(LLStack *stack);
int stackIsEmpty(LLStack *stack);

int push(stackElement newElement, LLStack *stack);
int pop(LLStack *stack, stackElement *returnedElement);

int getTopElement(LLStack *stack, stackElement *returnedElement);

#endif
