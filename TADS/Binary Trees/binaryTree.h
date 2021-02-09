#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

#define INF 99999

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

//Somesss BinaryTree functions
int height(BinaryTree treeRoot);
int numNodes(BinaryTree treeRoot);

void freeBinaryTree(BinaryTree *treeRoot);
int replace(BinaryTree treeRoot, BinaryTreeElement x, BinaryTreeElement y);
int numLeafNodes(BinaryTree treeRoot);
int numInternalNodes(BinaryTree treeRoot);
int numOneChildNodes(BinaryTree treeRoot);

BinaryTree searchMax(BinaryTree treeRoot);
BinaryTree searchMin(BinaryTree treeRoot);

int similars(BinaryTree t1, BinaryTree t2);
int equivalents(BinaryTree t1, BinaryTree t2);
BinaryTree specular(BinaryTree treeRoot);

int leftWeightedTree(BinaryTree treeRoot);
int rightWeightedTree(BinaryTree treeRoot);

//Evaluate function for simple arithmetic expresions
int evaluate(BinaryTree treeRoot);


#endif
