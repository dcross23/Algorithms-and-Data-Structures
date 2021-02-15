#include "LLDisjointSet.h"
#include <stdlib.h>

/**
 * Creates and initializes a Partition. In linked list implementation, 
 *  at the start, each element is part of his own partition. This is,
 *  if there are n elements, at the start there will be n sets (creates
 *  n linked lists) where each element is located alone in a set (is the
 *  first and only node in the set).     O(n)
 */
void create(LLDsPartition p){
	int i;
	LLDsSetNode *aux;
	
	for(i=0; i<MAX_SETS; i++){
		if(NULL == (aux = malloc(sizeof(LLDsSetNode)))){
			return;
		}
		
		aux->element = i;
		aux->next = NULL;
		
		p[i].first = p[i].last = aux;	
	}
}


/**
 * Returns the set where element x is located. In linked list 
 *  implementation, the representant of the set is returned, because
 *  the set is a linked list, not an integer.    O(n)
 */
LLDsSetRepresentant search(LLDsElement x, LLDsPartition p){
	int i;
	LLDsSetNode *aux;
	
	for(i=0; i<MAX_SETS; i++){
		if(p[i].first != NULL){
			aux = p[i].first;
			while (aux != NULL){
				if(aux->element == x)
					return p[i].first->element; //Returns representant
				else
					aux = aux->next;
			}
		}
	}
}

/**
 * Joins y set into x set.         O(1)
 *  It is required that x and y are the representants of the sets, 
 *  so it is convinient to call this function after searching the 
 *  set (representant of it) where the elements we want to join 
 *  are located.
 *
 * For example, if we have {3,1} and {2} with 2 and 3 representants and we
 *  want to join 1 and 2 in the same set, we should do:
 * "join(search(1,p), search(2,p), p)"  instead of   "join(1,2,p)" 
 */
void join(LLDsSetRepresentant x, LLDsSetRepresentant y, LLDsPartition p){
	p[x].last->next = p[y].first;
	p[x].last = p[y].last;
	p[y].first = p[y].last = NULL;	
}

