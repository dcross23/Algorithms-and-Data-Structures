#ifndef __LLD_LIST_H__
#define __LLD_LIST_H__

//List element
typedef int listElement;

//List structure with array implementation
typedef struct listNode{
	listElement element;
	struct listNode *next;
} listNode;

typedef struct LLDList {
	listNode *first, *last;
} LLDList;

//List position
typedef listNode* listPosition;

//Stack methods
int createEmptyList(LLDList *list);
int isEmpty(LLDList *list);

listPosition first(LLDList *list);
listPosition next(listPosition p, LLDList *list);
listPosition prev(listPosition p, LLDList *list);
listPosition end(LLDList *list);

int listAdd(listElement x, listPosition p, LLDList *list);
int listRemove(listPosition p, LLDList *list);

listPosition find(listElement x, LLDList *list, int *position);
listElement get(listPosition p, LLDList *list);

int clear(LLDList *list);
int destroy(LLDList *list);
void printList(LLDList *list);

#endif
