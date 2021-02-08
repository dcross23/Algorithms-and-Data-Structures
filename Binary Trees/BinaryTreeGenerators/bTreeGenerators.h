#ifndef __B_TREE_GENERATORS_H__
#define __B_TREE_GENERATORS_H__

#include "../binaryTree.h"
#include "treeModifStack.h"

BinaryTree treeFromPostOrder(char *postOrderExp);
BinaryTree treeFromPreOrder(char *preOrderExp);
BinaryTree treeFromInOrder(char *inOrderExp);

BinaryTree treeFromPreOrderAndInOrder(char *preOrderExp, char *inOrderExp, int *valid);
BinaryTree treeFromPostOrderAndInOrder(char *postOrderExp, char *inOrderExp, int *valid);

#endif

