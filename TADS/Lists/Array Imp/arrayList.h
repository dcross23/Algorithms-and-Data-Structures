#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#define MAX_LIST_SIZE 10

//List element
typedef int listElement;
typedef int listPosition;

//List structure with array implementation
typedef struct arrayList {
	listElement elements[MAX_LIST_SIZE];
	int last;
} ArrayList;

//Stack methods
int createEmptyList(ArrayList *list);
int isEmpty(ArrayList *list);

listPosition first(ArrayList *list);
listPosition next(listPosition p, ArrayList *list);
listPosition prev(listPosition p, ArrayList *list);
listPosition end(ArrayList *list);

int listAdd(listElement x, listPosition p, ArrayList *list);
int listRemove(listPosition p, ArrayList *list);

listPosition find(listElement x, ArrayList *list);
listElement get(listPosition p, ArrayList *list);

int clear(ArrayList *list);
void printList(ArrayList *list);

#endif
