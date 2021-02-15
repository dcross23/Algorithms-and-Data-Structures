#ifndef __ARRAY_DISJOINT_SET_H__
#define __ARRAY_DISJOINT_SET_H__

#define MAX_SETS 16

/**
 * In this type of implementation, a partition is represented by an array.
 *  Elements are considered as the indexes of the elements in the array, and the
 *  elements of the array will contain the representative element of the set where 
 *  the index is contained.
 * For example, if we have 2 sets {3,1} and {2} (with representants 2 and 3) in a 
 *  partition of 3 elements, it will be represented as:
 *  Elements in the array -> 3  2  3  
 *  Indexes of elements   -> 1  2  3
 */

//Disjoint set definitions for partition, sets and elements in sets
typedef int ADsPartition[MAX_SETS];
typedef int ADsSet;
typedef int ADsElement;

//Disjoint set methods
void create(ADsPartition p);
ADsSet search(ADsElement x, ADsPartition p);
void join(ADsSet x, ADsSet y, ADsPartition p);

#endif
