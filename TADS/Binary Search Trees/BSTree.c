#include "BSTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * Inits a Binary Search Tree
 */
void initBSTree(BSTree *t){
	if(t != NULL) *t = NULL;
}


/**
 * Creates a new node for a BSTree. Works with trees with 
 *  duplicated or not duplicated keys 
 */
BSTNode* createBSTNode(BSTkey key, BSTinfo info){
	BSTNode *n;
	if(NULL == (n = malloc(sizeof(BSTNode)))){
		return NULL;
	}else{
		n->key = key;
		#ifndef ALLOW_DUPLICATED_KEYS
			n->info = info;
		#else
		 	n->info = malloc(20 * sizeof(char));
			strcpy(n->info, info);
		#endif
		n->left = NULL;
		n->right = NULL;
		return n;
	}
}

/**
 * Auxiliar function to print the tree
 */
void inOrder(BSTree t){
	if(t != NULL){
		inOrder(t->left);
		#ifndef ALLOW_DUPLICATED_KEYS
			printf("(\x1b[35;1m%d\x1b[0m,\x1b[36;1m%d\x1b[0m) ", t->key, t->info);
		#else
			printf("(\x1b[35;1m%d\x1b[0m,\x1b[36;1m%s\x1b[0m) ", t->key, t->info);
		#endif
		inOrder(t->right);
	}
}



#ifndef ALLOW_DUPLICATED_KEYS
	/**
	* Inserts a new key (creates and inserts a new node) in the tree.
	*  This function inserts in a tree that doesnt allow duplicated keys.
	* To do this, when a key is already in the tree, the info atribute 
	*  of that node that has the key given is incremente (info stores)
	*  the number of times that key has been inserted.
	*/
	int insert(BSTkey key, BSTree *tree){
		if(tree == NULL) 
			return -1;

		BSTNode *n;
		if(*tree == NULL){
			if(NULL == (n = createBSTNode(key, 1)))
				return -1;
			
			*tree = n;
			return 0;
			
		}else if(key < (*tree)->key)
			return insert(key, &((*tree)->left));

		else if( key > (*tree)->key)
			return insert(key, &((*tree)->right));
			
		else if(key == (*tree)->key){
			((*tree)->info)++;
			return 0;
		}
	}

#else
	/**
	 * Inserts a new key (creates and inserts a new node) in the tree.
	 *  This function inserts in a tree that allows duplicated keys.
	 * For this to be done, when a key is already on the tree, the new
	 *  node is inserted in the left of the last node that has that key.
	 */
	int insert(BSTkey key, BSTinfo info, BSTree *tree){
		if(tree == NULL)
			return -1;
			
		BSTNode *n;
		if(*tree == NULL){
			if(NULL == (n = createBSTNode(key, info)))
				return -1;
			
			*tree = n;
			return 0;
			
		}else if(key < (*tree)->key)
			return insert(key, info, &((*tree)->left));
		
		else if( key > (*tree)->key)
			return insert(key, info, &((*tree)->right));
		
		else if(key == (*tree)->key){
			//While there is a left child with the same key (or is NULL),
			// it calls recursively to insert on the left
			if((*tree)->left==NULL || (*tree)->left->key==key)
				return insert(key, info, &((*tree)->left));
			
			//If it has a left child but with different key, a new node
			// with the key given is inserted between them 	
			else{
				if(NULL == (n = createBSTNode(key, info)))
					return -1;
				n->left = (*tree)->left;
				(*tree)->left = n;
				return 0;
			}
		}
		
	}
#endif



/**
 * Searches for a node in the tree with an specific key.
 *  It returns the info of the node; also returns the node
 *  finded in the parameter "retNode"
 *
 * -Trees with not duplicated keys: returns the number of 
 *     times that key was inserted (stored in info)
 * -Tree with duplicated keys: returns 1 (and the 1rst node finded) 
 */
int search(BSTkey key, BSTree *tree, BSTNode **retNode){
	if(tree == NULL || *tree == NULL){
		*retNode = NULL;
		return 0;
		
	}else if(key < (*tree)->key)
		return search(key, &((*tree)->left), retNode);
		
	else if(key > (*tree)->key)
		return search(key, &((*tree)->right), retNode);
		
	else if(key == (*tree)->key){
		*retNode = *tree;
		#ifndef ALLOW_DUPLICATED_KEYS
			return ((*tree)->info);
		#else
			return 1;
		#endif
	}
}	

#ifndef ALLOW_DUPLICATED_KEYS
	/**
	 * Deletes the node that has the key given. This works with not
	 *  duplicated keys.
	 *
	 * When this node is removed, the tree has to be reordered. To 
	 *  do this, the node that has the closest key to the removed one
	 *  replaces it. This is, the leftmost node of the right subtree
	 *  of the node that is deleted, or the rightmost node of the
	 *  left subtree.
	 *
	 * In this case, the leftmost node of the right subtree.
	 */
	int deleteNode(BSTkey key, BSTree *tree){
		if(tree == NULL) return -1;
		
		if(*tree == NULL)
			return 0;
		
		else if(key < (*tree)->key)
			return deleteNode(key, &((*tree)->left));
			
		else if(key > (*tree)->key)
			return deleteNode(key, &((*tree)->right));
			
		else if(key == (*tree)->key){
			BSTNode *aux, *prev;
			int nRepeated = (*tree)->info;
			
			aux = *tree;
			//0 or 1 child
			if(aux->right == NULL)
				*tree = aux->left;
			else if(aux->left == NULL)
				*tree = aux->right;
				
			//2 or more childs	
			else{
				prev = aux;
				aux = aux->right;
				
				//Gets the leftmost node of the right subtree
				while(aux->left != NULL){
					prev = aux;
					aux = aux->left;
				}
				//Substitutes the info from that node and the root of the tree
				(*tree)->key = aux->key;
				(*tree)->info = aux->info;
				
				//Joins new subtree, excluding aux node
				if(prev == (*tree)){
					prev->right = aux->right;
				}
				else
					prev->left = aux->right;
			}
			
			//When all is prepared, aux is deleted.
			free(aux);
			return nRepeated;
		}
	}

#else
	/**
	 * Deletes ALL nodes that has the key given. This works with 
	 *  duplicated keys.
	 *
	 * When this node is removed, the tree has to be reordered. To 
	 *  do this, the node that has the closest key to the removed one
	 *  replaces it. This is, the leftmost node of the right subtree
	 *  of the node that is deleted, or the rightmost node of the
	 *  left subtree.
	 *
	 * In this case, the rightmost node of the left subtree (to change 
	 *  from the previous one :D).
	 */
	int deleteNode(BSTkey key, BSTree *tree){
		if(tree == NULL) return -1;
		
		if(*tree == NULL)
			return 0;
		
		else if(key < (*tree)->key)
			return deleteNode(key, &((*tree)->left));
			
		else if(key > (*tree)->key)
			return deleteNode(key, &((*tree)->right));
			
		else if(key == (*tree)->key){
			BSTNode *aux, *prev;
			aux = *tree;
			
			//0 or 1 child
			if(aux->right == NULL)
				*tree = aux->left;
			else if(aux->left == NULL)
				*tree = aux->right;
				
			//2 or more childs	
			else{
				prev = aux;
				aux = aux->left;
				
				//Gets the leftmost node of the right subtree
				while(aux->right != NULL){
					prev = aux;
					aux = aux->right;
				}
				
				//Substitutes the info from that node and the root of the tree
				(*tree)->key = aux->key;
				strcpy((*tree)->info, aux->info);
				
				//Joins new subtree, excluding aux node
				if(prev == (*tree))
					prev->left = aux->left;
				else
					prev->right = aux->left;
			}
			
			//When all is prepared, aux is deleted.
			free(aux);
			
			//If there are nodes with the same key, continues deleating
			if((*tree)!=NULL && (*tree)->key == key)
				return 1 + deleteNode(key, tree);
			else
				return 1;
		}
	}
#endif



