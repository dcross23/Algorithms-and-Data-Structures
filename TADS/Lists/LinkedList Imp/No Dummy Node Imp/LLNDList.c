#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LLNDList.h"


int createEmptyList(LLNDList *list){
	if(list == NULL) return -1;
	
	list->first = list->last = NULL;
	return 0;
}


int isEmpty(LLNDList *list){
	if(list == NULL) return -1;
	
	return (list->first == NULL);
}



listPosition first(LLNDList *list){
	if(list == NULL) return NULL;
	return list->first;
}


listPosition next(listPosition p, LLNDList *list){
	if(list == NULL || p == NULL) return NULL;
	return p->next;
}


listPosition prev(listPosition p, LLNDList *list){
	if(list == NULL || p == NULL) return NULL;
	
	if(p == list->first){
		return list->first;
	}else{
		listPosition previous = list->first;
		while(previous!=NULL && previous->next != p){
			previous = previous->next;
		}
		return previous;		
	}
}



listPosition end(LLNDList *list){
	if(list == NULL) return NULL;
	return list->last;
}


int listAdd(listElement x, listPosition p, LLNDList *list){
	if(list == NULL) return -1;
	
	listNode *new;
	if(NULL == (new = malloc(sizeof(listNode)))) return -2;
	new->element = x;
	
	if(!isEmpty(list)){
		//List is not empty
		if(p == list->first && p != list->last){
			//p is the first and there is not only one node (first == last)
			// so it can not be confused with insert in last as insert first
			new->next = list->first;
			list->first = new;
		
		}else{
			//p is not the first
			new->next = p->next;
			p->next = new;
			
			//If p was the last, now the new one is the last
			if(p == list->last) list->last = new;
		}
	}else{
		//List is empty
		new->next = NULL;
		list->first = list->last = new;
	}
	return 0;
}


int listRemove(listPosition p, LLNDList *list){
	if(list == NULL || p == NULL) return -1;
	
	listPosition toRemove = list->first;
	
	if(p == list->first){
		list->first = list->first->next;
	}else{
		listPosition prev;
		while(toRemove != NULL && toRemove != p){
			prev = toRemove;
			toRemove = toRemove->next;
		}
		
		if(toRemove == NULL) return -2;
		
		prev->next = toRemove->next;
		if(toRemove = list->last){
			list->last = prev;
		}
	}
	
	free(toRemove);
	return 0;	
}



listPosition find(listElement x, LLNDList *list, int *position){
	if(list == NULL){
		*position = -1;
		return NULL;
	}
	
	listPosition aux = list->first;
	*position = 0;
	
	while(aux != NULL && aux->element != x){
		aux = aux->next;
		(*position)++;
	}
	
	return aux;
}

listElement get(listPosition p, LLNDList *list){
	if(list == NULL || p == NULL) return -1;
	return p->element;
}


int clear(LLNDList *list){
	if(list == NULL) return -1;
	listPosition p = list->first;
	
	while(list->first != NULL){
		p = list->first;
		list->first = list->first->next;
		free(p);
	}
	
	list->first = list->last = NULL;
	return 0;
}

void printList(LLNDList *list){
	if(list != NULL){
		printf("\nLIST\n");
		if(!isEmpty(list)){
			listPosition p = list->first;
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
















