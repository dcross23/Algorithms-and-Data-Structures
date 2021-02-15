#include "TreeDisjointSet.h"

/**
 * Creates and initializes a Partition. In tree implementation, 
 *  at the start, each element is part of his own partition. This is,
 *  if there are n elements, at the start there will be n sets, 
 *  where each element is located alone in his set and he has no parent,
 *  this is, there will be n tree with just the element as the root.    O(n)
 */
void create(TDsPartition p){
	int i;
	for(i=0; i<MAX_SETS; i++)
		p[i] = -1;	
}

/**
 * Returns the set (his representant) where element x is located. In tree 
 *  implementation, the representant will be searched recursively from the element
 *  to the root (the representant) of the tree.      O(log(n))
 * There are improvements such as path compression.
 */
TDsSet search(TDsElement x, TDsPartition p){
	if(p[x] == -1)
		return x;
	else 
		return search(p[x], p);
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
 *
 * For tree implementation, this way just joins a tree to another by getting the root
 *  of "y" tree and add as a child to "x" root. There are improvements to this technique
 *  such as union by height and union by size.
 */
void join(TDsSet x, TDsSet y, TDsPartition p){
	p[y] = x;
}
