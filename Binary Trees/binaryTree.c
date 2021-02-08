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


/**
 * Returns the node (root of a subtree) with the highest info value
 */
BinaryTree searchMax(BinaryTree treeRoot){
	if(treeRoot == NULL)
		return NULL;
	else{
		BinaryTree searchMaxInLeft  = searchMax(treeRoot->left);
		BinaryTree searchMaxInRight = searchMax(treeRoot->right);

		BinaryTree highestValueNode = treeRoot;
		if(searchMaxInLeft != NULL && searchMaxInLeft->info > highestValueNode->info)
			highestValueNode = searchMaxInLeft;
			
		if(searchMaxInRight != NULL && searchMaxInRight->info > highestValueNode->info)
			highestValueNode = searchMaxInRight;
		
		return highestValueNode;
	}
}


/**
 * Returns the node (root of a subtree) with the lowest info value
 */
BinaryTree searchMin(BinaryTree treeRoot){
	if(treeRoot == NULL)
		return NULL;
	else{
		BinaryTree searchMinInLeft  = searchMin(treeRoot->left);
		BinaryTree searchMinInRight = searchMin(treeRoot->right);

		BinaryTree lowestValueNode = treeRoot;
		if(searchMinInLeft != NULL && searchMinInLeft->info < lowestValueNode->info)
			lowestValueNode = searchMinInLeft;
			
		if(searchMinInRight != NULL && searchMinInRight->info < lowestValueNode->info)
			lowestValueNode = searchMinInRight;
		
		return lowestValueNode;
	}
}


/**
 * Returns true(1) if t1 and t2 are similar (have same structure)
 *  or false(0) if they are not.
 */
int similars(BinaryTree t1, BinaryTree t2){
	if(t1 == NULL && t2 == NULL)
		return 1;

	else if(t1!=NULL && t2!=NULL)
		return(similars(t1->left,t2->left) && similars(t1->right,t2->right));	
	
	else
		return 0;	
}

/**
 * Returns true(1) if t1 and t2 are equivalent (have same structure and same
 *   node info) or false(0) if they are not.
 * Equivalent is the same as similar but each node compared must have the same info.
 */
int equivalents(BinaryTree t1, BinaryTree t2){
	if(t1 == NULL && t2 == NULL)
		return 1;

	else if(t1!=NULL && t2!=NULL && t1->info==t2->info)
		return(equivalents(t1->left,t2->left) && equivalents(t1->right,t2->right));	
	
	else
		return 0;	
}


/**
 * Creates a new binary tree but inverted, this is, left child (subtree) now is 
 *  right child and so on.
 */
BinaryTree specular(BinaryTree treeRoot){
	if(treeRoot == NULL)
		return NULL;
	else{
		BinaryTree t;
		t = createBinaryTreeNode(treeRoot->info);
		t->left = specular(treeRoot->right);
		t->right = specular(treeRoot->left);
		return t;
	}
}



/**
 * A binary tree is "left weighted" when :
 *  - There are more nodes in the left subtree than in the right subtree
 *  - Childs are also "left weighted"
 * (A null binary tree is also "left weighted")
 *
 * This function return true(1) if the tree is left weighted or false(0) if is not. 
 */
int leftWeightedTree(BinaryTree treeRoot){
	if(treeRoot == NULL)
		return 1;
		
	else if(leftWeightedTree(treeRoot->left) && leftWeightedTree(treeRoot->right)){
		int leftNodes = numNodes(treeRoot->left);
		int rightNodes = numNodes(treeRoot->right);
		
		if( leftNodes>rightNodes || (leftNodes==0 && rightNodes==0) )
			return 1;
		else
			return 0;		
	}else
		return 0;
}


/**
 * A binary tree is "right weighted" when :
 *  - There are more nodes in the right subtree than in the left subtree
 *  - Childs are also "right weighted"
 * (A null binary tree is also "right weighted")
 *
 * This function return true(1) if the tree is right weighted or false(0) if is not. 
 */
int rightWeightedTree(BinaryTree treeRoot){
	if(treeRoot == NULL)
		return 1;
		
	else if(rightWeightedTree(treeRoot->left) && rightWeightedTree(treeRoot->right)){
		int leftNodes = numNodes(treeRoot->left);
		int rightNodes = numNodes(treeRoot->right);
		
		if( leftNodes<rightNodes || (leftNodes==0 && rightNodes==0) )
			return 1;
		else
			return 0;		
	}else
		return 0;
}




/**
 * Given a binarytree with numbers and operators, it returns the result of 
 *  calculating the arithmetic expresion the tree stores.
 */
int evaluate(BinaryTree treeRoot){
	if(treeRoot != NULL){
		int leftValue = evaluate(treeRoot->left);
		int rightValue = evaluate(treeRoot->right);
	
		switch(treeRoot->info){
			case '+':
				return (leftValue + rightValue);
				
			case '-':
				return (leftValue - rightValue);

			case '*':
				return (leftValue * rightValue);

			case '/':
				if(rightValue == 0) return INF;
				else return (leftValue / rightValue);
			
			default:
				return treeRoot->info - '0';
		}				
	}
}




