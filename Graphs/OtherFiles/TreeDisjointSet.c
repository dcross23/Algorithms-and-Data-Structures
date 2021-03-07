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
 *  to the root (the representant) of the tree.      O(n)
 * There are improvements such as path compression.
 */
TDsSet search(TDsElement x, TDsPartition p){
	if(p[x] < 0) 
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



/**
 * Improvement of normal join (union). Consists of storing in the content of the array of the 
 *  root element the height of the tree that is representing instead of just -1. Then, comparing
 *  the height of the 2 trees we want to join, we can join them creating a "balanced" tree. 
 * For exameple, we have 2 sets: {1,2,3,4}, {5,6} with representants 1 and 5. The trees created are:
 *          1                        5                               1
 *	   / \			   /				   / | \
 * 	  2  3        and         6        --> joining -->        2  3  5
 *       /						         /     /
 *      4							4     6
 *
 * Using this type of union, we are always obtaining a tree with height <= [log k] (k = num of nodes in the tree)
 *  This improves searching because now the complexity time will improve from O(n) to O(logn) because in the worst
 *  case, a tree will have height = [log k].	
 */
void joinByHeight(TDsSet x, TDsSet y, TDsPartition p){
	if(p[x] == p[y]){
		p[x]--;
		p[y] = x;
	
	}else if(p[x] < p[y])
		p[y] = x;
	else 
		p[x] = y;
}



/**
 * Improvement of normal join (union). Consists of storing in the content of the array of the 
 *  root element the size (number of nodes including the root) of the tree that is representing 
 *  instead of just -1. Then, comparing the size of the 2 trees we want to join, we can join 
 *  them creating a "balanced" tree. 
 * For exameple, we have 2 sets: {1,2,3}, {4,5} with representants 1 and 5. The trees created are:
 *          1                        4                               1
 *	   / \			   /				   / | \
 * 	  2  3        and         5        --> joining -->        2  3  4
 *       						               /
 *      							     5
 *
 * Using this type of union, we get a similar result as union by height, search is improved because
 *  tree unions are controlled.
 */
void joinBySize(TDsSet x, TDsSet y, TDsPartition p){
	if(p[x] <= p[y]){
		p[x] += p[y];
		p[y] = x;
	}else{
		p[y] += p[x];
		p[x] = y;
	}


}



/**
 * Improvement of normal search. Consists of reducing tree height while searching for representant. 
 *  For repetitive searches, this algorithm reduces time complexity, but for small amount of 
 *  searches or nodes, this is not recomended (uses more time for path compression than for the search).
 *
 * It is compatible with union by size, but no fully compatible with union by height because both
 *  change tree height. This problem is complex, so it is not recomended to use them together. In case 
 *  of using them together, union by height will not work with the proper heights. Instead, it will work
 *  with estimated heights and union by height now will be called union by rank.
 */
TDsSet pathCompressionSearch(TDsElement x, TDsPartition p){
	if(p[x] < 0)
		return x;
	else{
		p[x] = pathCompressionSearch(p[x], p);
		return p[x];
	}
}






















