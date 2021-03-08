#ifndef __BINARY_SEARCH_TREE__
#define __BINARY_SEARCH_TREE__

//#define ALLOW_DUPLICATED_KEYS //Uncomment to allow duplicated keys


/**
 * Binary Search Trees (BST) are Binary Trees that stores their nodes
 *  in order, this is :
 * - The left subtree of a node contains only nodes with keys lesser than the node’s key.
 * - The right subtree of a node contains only nodes with keys greater than the node’s key.
 * - The left and right subtree each must also be a binary search tree.
 *
 * For example:            5
 *                        / \
 *                       2   7
 *                      / \   \
 *                     1  3   8
 */


#ifndef ALLOW_DUPLICATED_KEYS
  typedef int BSTkey;
  typedef int BSTinfo;	
#else
  typedef int BSTkey;
  typedef char *BSTinfo;
#endif


typedef struct BSTNode{
	BSTkey key;
	BSTinfo info;
	struct BSTNode *left, *right;
}BSTNode;

typedef BSTNode *BSTree;

//Init BSTree and create node for the tree
void initBSTree(BSTree *t);
BSTNode* createBSTNode(BSTkey key, BSTinfo info);

//BSTree functions
#ifndef ALLOW_DUPLICATED_KEYS
  int insert(BSTkey key, BSTree *tree);
#else
  int insert(BSTkey key, BSTinfo info, BSTree *tree);
#endif

int search(BSTkey key, BSTree *tree, BSTNode **retNode);
int deleteNode(BSTkey key, BSTree *tree);


//Other functions
void inOrder(BSTree t); //Just to print out the tree		
	
#endif
