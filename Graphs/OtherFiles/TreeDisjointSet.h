#ifndef __TREE_DISJOINT_SET_H__
#define __TREE_DISJOINT_SET_H__

#define MAX_SETS 16

/**
 * In this type of implementation, a partition is represented by an array that
 *  represents a tree.
 *  Elements are considered as the indexes of the elements in the array, and the
 *  elements of the array will contain the representative element of the set where 
 *  the index is contained.
 * For example, if we have 2 sets {3,1} and {2} (with representants 2 and 3) in a 
 *  partition of 3 elements, it will be represented as:
 *  Elements in the array -> 3  2  3  
 *  Indexes of elements   -> 1  2  3
 *
 * Normal implementation union-search secuence complexity -> O(n²)
 * Improvemenets union-search secuence complexity -> O(nlogn)
 */

//Disjoint set definitions for partition, sets and elements in sets
typedef int TDsPartition[MAX_SETS];
typedef int TDsSet;
typedef int TDsElement;

//Disjoint set methods
void create(TDsPartition p);
TDsSet search(TDsElement x, TDsPartition p);
void join(TDsSet x, TDsSet y, TDsPartition p);


//Improvements
void joinByHeight(TDsSet x, TDsSet y, TDsPartition p);
void joinBySize(TDsSet x, TDsSet y, TDsPartition p);
TDsSet pathCompressionSearch(TDsElement x, TDsPartition p);

#endif
