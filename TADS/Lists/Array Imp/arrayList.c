#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayList.h"

int createEmptyList(ArrayList *list){
	if(list == NULL) return -1;
	
	list->last = -1;
	return 0;
}


int isEmpty(ArrayList *list){
	if(list == NULL) return -1;
	
	return (list->last == -1);
}

listPosition first(ArrayList *list){
	if(list == NULL) return -1;
	
	if(!isEmpty(list)){
		return 0;
	}else{
		return end(list);
	}
}


listPosition next(listPosition p, ArrayList *list){
	if(list == NULL || p<first(list) || p>end(list)) return -1;
	
	if(p == end(list)){
		return -1;
	}else{
		return (p+1);
	}
}

listPosition prev(listPosition p, ArrayList *list){
	if(list == NULL || p<first(list) || p>end(list)) return -1;
	
	if(p == first(list)){
		return -1;
	}else{
		return (p-1);
	}
}

listPosition end(ArrayList *list){
	if(list == NULL) return -1;
	
	return list->last+1;
}

int listAdd(listElement x, listPosition p, ArrayList *list){
	if(list == NULL || p<first(list) || p>end(list) || end(list) == MAX_LIST_SIZE) return -1;
	if(list->last >= MAX_LIST_SIZE) return -2;
	
	listPosition q;
	for(q = list->last; q >= p; q--){
		list->elements[q+1] = list->elements[q];
	}
	(list->last)++;
	list->elements[p] = x;
	return 0;
}

int listRemove(listPosition p, ArrayList *list){
	if(list == NULL || p<first(list) || p>=end(list)) return -1;
	
	listPosition q;
	for(q = p; q < list->last; q++){
		list->elements[q] = list->elements[q+1];
	}
	(list->last)--;
	return 0;	
}

listPosition find(listElement x, ArrayList *list){
	if(list == NULL) return -1;
	
	listPosition i; 
	for(i=0; i<=list->last; i++){
		if(list->elements[i] == x)
			return i;
	}
	return -1;
}

listElement get(listPosition p, ArrayList *list){
	if(list == NULL || p<first(list) || p>=end(list)) return -1;
	
	return list->elements[p];
}


int clear(ArrayList *list){
	if(list == NULL) return -1;
	
	list->last = -1;
	return 0;
}

void printList(ArrayList *list){
	if(list != NULL){
		printf("\nLIST\n");
		if(!isEmpty(list)){
			listPosition i;
			for(i=0; i<=list->last; i++){
				printf("%d ",list->elements[i]);
			}
		}else{
			printf("The list is empty");
		}
		puts("");
	}
}


