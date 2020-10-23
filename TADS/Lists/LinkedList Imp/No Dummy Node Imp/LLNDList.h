#ifndef __LLND_LIST_H__
#define __LLND_LIST_H__

//List element
typedef int listElement;

//List structure with array implementation
typedef struct listNode{
	listElement element;
	struct listNode *next;
} listNode;

typedef struct LLNDList {
	listNode *first, *last;
} LLNDList;

//List position
typedef listNode* listPosition;

//Stack methods
int createEmptyList(LLNDList *list);
int isEmpty(LLNDList *list);

listPosition first(LLNDList *list);
listPosition next(listPosition p, LLNDList *list);
listPosition prev(listPosition p, LLNDList *list);
listPosition end(LLNDList *list);

int listAdd(listElement x, listPosition p, LLNDList *list);
int listRemove(listPosition p, LLNDList *list);

listPosition find(listElement x, LLNDList *list, int *position);
listElement get(listPosition p, LLNDList *list);

int clear(LLNDList *list);
void printList(LLNDList *list);

#endif
