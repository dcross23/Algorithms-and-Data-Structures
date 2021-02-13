#include "disjointSet.h"

/**
 * Creates and initializes a Partition. In array implementation, 
 *  at the start, each element is part of his own partition. This is,
 *  if there are n elements, at the start there will be n partitions, 
 *  where each element is located alone in a partition.     O(n)
 */
void create(DsPartition p){
	int i;
	for(i=0; i<MAX_ELEMENTS; i++)
		p[i] = i;	
}

/**
 * Returns the set where element x is located.  O(1)
 */
DsSet search(DsElement x, DsPartition p){
	return p[x];
}


/**
 * Joins y set into x set.         O(n)
 *  It is required that x and y are the representants of the sets, 
 *  so it is convinient to call this function after searching the 
 *  set (representant of it) where the elements we want to join 
 *  are located.
 *
 * For example, if we have {3,1} and {2} with 2 and 3 representants and we
 *  want to join 1 and 2 in the same set, we should do:
 * "join(search(1,p), search(2,p), p)"  instead of   "join(1,2,p)" 
 */
void join(DsSet x, DsSet y, DsPartition p){
	int i;
	for(i=0; i<MAX_ELEMENTS; i++)
		if(p[i] == y) 
			p[i] = x;  
}
