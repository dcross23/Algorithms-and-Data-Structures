#ifndef __DISJOINT_SET_H__
#define __DISJOINT_SET_H__

#define MAX_ELEMENTS 16

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
typedef int DsPartition[MAX_ELEMENTS];
typedef int DsSet;
typedef int DsElement;

//Disjoint set methods
void create(DsPartition p);
DsSet search(DsElement x, DsPartition p);
void join(DsSet x, DsSet y, DsPartition p);

#endif
