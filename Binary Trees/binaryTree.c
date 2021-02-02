#include "binaryTree.h"
#include "treeModifQueue.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * Creates a new tree. Each node of a tree is considered a new tree with no
 *  descendets.
 */
BinaryTree createBinaryTreeNode(BinaryTreeElement info){
	BinaryTreeNode *new;

	if((new = malloc(sizeof(BinaryTreeNode))) == NULL){
		#ifdef DEBUG
			fprintf(stderr,"ERROR: can not create tree node\n");	
		#endif	
		return NULL;
	}else{
		new->info = info;
		new->left = new->right = NULL;
		return new;
	}
}


/*==========================================================================================================*/
/*					       TREE TRAVERSALS 						    */
/*==========================================================================================================*/
/**
 * Level-order traversañ
 */
void levelOrder(BinaryTree tree){
	BinaryTreeNode *node;
	LLQueue queue;
	createEmptyQueue(&queue);

	if(tree!=NULL) 
		queueAdd(tree, &queue);

	while(!isEmpty(&queue)){
		queueRemove(&queue, &node);
		printf("%c ", node->info);
		
		if(node->left  != NULL) queueAdd(node->left, &queue);
		if(node->right != NULL) queueAdd(node->right, &queue);
	}
}


/**
 * Pre-order traversal
 */
void preOrder(BinaryTree tree){
	if(tree != NULL){
		printf("%c ", tree->info);
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

/**
 * In-order traversal
 */
void inOrder(BinaryTree tree){
	if(tree != NULL){
		inOrder(tree->left);
		printf("%c ", tree->info);
		inOrder(tree->right);
	}
}

/**
 * Post-order traversal
 */
void postOrder(BinaryTree tree){
	if(tree != NULL){
		postOrder(tree->left);
		postOrder(tree->right);
		printf("%c ", tree->info);
	}
}




/*==========================================================================================================*/
/*					       OTHER FUNCTIONS						    */
/*==========================================================================================================*/
/**
 * Calculates the height of a tree (recursively) 
 * Return -1 if the tree is NULL instead of 0. This is because it is considered
 *  that leaf nodes have height=0 instead of height=1.
 * To change this behaviour and consider that leaf nodes have height=1, just
 *  change "return -1" to "return 0"
 */
int height(BinaryTree treeRoot){
	if(treeRoot == NULL) 
		return -1;
	else{
		int leftHeight = height(treeRoot->left);
		int rightHeight = height(treeRoot->right);
		
		return (leftHeight >= rightHeight) ? (leftHeight+1) : (rightHeight+1);
	}
}

/**
 * Calculates the number of nodes a tree has.
 */
int numNodes(BinaryTree treeRoot){
	if(treeRoot == NULL) 
		return 0;
	else	
		return (numNodes(treeRoot->left) + numNodes(treeRoot->right) +1);
}


/**
 * Removes a tree releasing memory occupied by the nodes.
 */
void freeBinaryTree(BinaryTree *treeRoot){
	if(treeRoot != NULL && *treeRoot != NULL){
		freeBinaryTree( &((*treeRoot)->left) );
		freeBinaryTree( &((*treeRoot)->right) );
		#ifdef DEBUG
			printf("\nRemoving node: %c ......", (*treeRoot)->info);
		#endif
		
		free(*treeRoot);
		*treeRoot = NULL;
		
		#ifdef DEBUG
			printf(" (removed)");
		#endif
	}
}



/**
 * Replaces nodes with value "x" to value "y" and returns the number
 *  of substitutions.
 */ 
int replace(BinaryTree treeRoot, BinaryTreeElement x, BinaryTreeElement y){
	if(treeRoot == NULL) 
		return 0;
	else{
		int replaceLeft = replace(treeRoot->left, x, y);
		int replaceRight = replace(treeRoot->right, x, y);
		
		if(treeRoot->info == x){
			treeRoot->info = y;
			return (replaceLeft + replaceRight + 1);
		}else
			return (replaceLeft + replaceRight);
		
	}

}

/**
 * Returns the number of leaf nodes in the tree, understanding
 *  leaf node as node with no childs.
 */
int numLeafNodes(BinaryTree treeRoot){
	if(treeRoot == NULL)
		return 0;
	else if(treeRoot->left == NULL && treeRoot->right == NULL)
		return 1;
	else
		return (numLeafNodes(treeRoot->left) + numLeafNodes(treeRoot->right));	
}

/**
 * Returns the number of internal nodes in the tree, understanding
 *  internal node as node with some childs.
 */
int numInternalNodes(BinaryTree treeRoot){
	if(treeRoot == NULL || (treeRoot->left==NULL && treeRoot->right==NULL))
		return 0;
	else
		return (numInternalNodes(treeRoot->left) + numInternalNodes(treeRoot->right) + 1);	
}


/**
 * Returns the number of nodes with just 1 child.
 */
int numOneChildNodes(BinaryTree treeRoot){
	if(treeRoot == NULL)
		return 0;
	
	else if((treeRoot->left==NULL && treeRoot->right==NULL) || (treeRoot->left!=NULL && treeRoot->right!=NULL))
		return (numOneChildNodes(treeRoot->left) + numOneChildNodes(treeRoot->right));

	else
		return (numOneChildNodes(treeRoot->left) + numOneChildNodes(treeRoot->right) + 1); 	
}








