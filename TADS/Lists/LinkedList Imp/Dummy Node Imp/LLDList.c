#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LLDList.h"

int createEmptyList(LLDList *list){
	if (list == NULL) return -1;
	
	//Create a dummy node
	if (NULL == (list->first = list->last = (listNode *)malloc(sizeof(listNode)))) return -2;
        	
	list->first->next = NULL;
	return 0;
    	
}

int isEmpty(LLDList *list){
	if (list == NULL || list->first == NULL) return -1;
	
	return (list->first->next == NULL);
}

listPosition first(LLDList *list){
	if(list==NULL || list->first==NULL) return NULL;
	
	return list->first;	
}

listPosition next(listPosition p, LLDList *list){
	if(list==NULL || list->first==NULL || p==NULL) return NULL;

	return p->next;
}


listPosition prev(listPosition p, LLDList *list){
	if(list==NULL || list->first==NULL || p==NULL) return NULL;

	if(p == list->first)
		return list->first;
	else{
		listPosition previous = list->first;
		while(previous->next != p){
			previous = previous->next;
		}
		return previous;	
	}
}

listPosition end(LLDList *list){
	if(list==NULL || list->first==NULL) return NULL;
	
	return list->last;
}

int listAdd(listElement x, listPosition p, LLDList *list){
	if(p==NULL || list==NULL || list->first==NULL || list->last==NULL) return -1;

	listNode *new;;
	if(NULL == (new = malloc(sizeof(listNode)))) return -2;
	
	new->element = x;
	new->next = p->next;
	p->next = new;

	if(p == end(list)) list->last = new;
	return 0;
}


int listRemove(listPosition p, LLDList *list){
	if(p==NULL || list==NULL || list->first==NULL || list->last==NULL) return -1;

	listPosition toRemove;
	
	if(p == end(list)){
		list->last = prev(p,list);
		list->last->next = NULL;
		toRemove = p;
	}else{
		toRemove = p->next;
		p->next = toRemove->next;
	}  

	free(toRemove); 
	return 0; 

}


listPosition find(listElement x, LLDList *list, int *position){
	if(list == NULL || list->first==NULL || list->last==NULL){
		*position = -1;
		return NULL;
	}
	
	listPosition aux = list->first;
	*position = 0;
	while(aux != end(list)){
		if(aux->next->element == x)
			return aux;	
		else{
			(*position)++;		
			aux = aux->next;
		}
	}

	*position = -2;
	return NULL;
}

listElement get(listPosition p, LLDList *list){
	if(list == NULL || list->first==NULL || list->last==NULL || p==end(list)) return -1;
	
	return p->next->element;
}

int clear(LLDList *list){
	if(list == NULL || list->first==NULL) return -1; 
	
	listPosition aux;

	while(list->first->next != NULL){
		aux = list->first->next;
		list->first->next = list->first->next->next;
		free(aux);
	}
	
	list->first->next = list->last = NULL;
	return 0;
}

int destroy(LLDList *list){
	if(list == NULL || list->first==NULL) return -1; 
	
	clear(list);
	free(list->first);
	list->first = list->last = NULL;
	return 0;
}

void printList(LLDList *list){
	if(list != NULL && list->first !=NULL){
		printf("\nLIST\n");
		if(!isEmpty(list)){
			listPosition p = list->first->next;
			while(p != NULL){
				printf("%d ",p->element);
				p = p->next;
			}
		}else{
			printf("The list is empty");
		}
		puts("");	
	}

}














