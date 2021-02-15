#ifndef __LINKED_LISTS_DISJOINT_SET_H__
#define __LINKED_LISTS_DISJOINT_SET_H__

#define MAX_SETS 16

/**
 * In this type of implementation, a partition is represented by an array of linked lists.
 *  Each linked list in the partition is a set, where each node of the set (linked list) is 
 *  an element of the set. The first element of the set (first node of the linked list) is the 
 *  representant of the set.
 * For example, if we have 2 sets {3,1} and {2} (with representants 2 and 3) in a 
 *  partition of 3 elements, it will be represented as:
 *    3 -> 1 -> NULL
 *    2 -> NULL
 */
 
//Disjoint set definitions for partition, sets and elements in sets
typedef int LLDsSetRepresentant;
typedef int LLDsElement;

typedef struct setNode{
	LLDsElement element;
	struct setNode *next;	
} LLDsSetNode;

typedef struct set{
	LLDsSetNode *first, *last;
} LLDsSet;

typedef LLDsSet LLDsPartition[MAX_SETS];

//Disjoint set methods
void create(LLDsPartition p);
LLDsSetRepresentant search(LLDsElement x, LLDsPartition p);
void join(LLDsSetRepresentant x, LLDsSetRepresentant y, LLDsPartition p);


#endif
