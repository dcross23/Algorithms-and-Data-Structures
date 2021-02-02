#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef char BinaryTreeElement;

typedef struct BinaryTreeNode{
	BinaryTreeElement info;
	struct BinaryTreeNode *left;
	struct BinaryTreeNode *right;
}BinaryTreeNode;

typedef BinaryTreeNode* BinaryTree;

//Create a new BinaryTree (each node is a new BinaryTree)
BinaryTree createBinaryTreeNode(BinaryTreeElement info);

//BinaryTree traversals
void preOrder(BinaryTree tree); 
void inOrder(BinaryTree tree);
void postOrder(BinaryTree tree);
void levelOrder(BinaryTree tree);

//Other BinaryTree functions
int height(BinaryTree treeRoot);
int numNodes(BinaryTree treeRoot);

void freeBinaryTree(BinaryTree *treeRoot);
int replace(BinaryTree treeRoot, BinaryTreeElement x, BinaryTreeElement y);
int numLeafNodes(BinaryTree treeRoot);
int numInternalNodes(BinaryTree treeRoot);
int numOneChildNodes(BinaryTree treeRoot);

#endif
