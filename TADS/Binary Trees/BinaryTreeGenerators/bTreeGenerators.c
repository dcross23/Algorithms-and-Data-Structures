#include <string.h>
#include <stdlib.h>
#include "bTreeGenerators.h"

/**
 * Creates a tree from its pre order expression 
 * (works with simple arithmetic expressions)
 */
BinaryTree treeFromPreOrder(char *preOrderExp){
	BinaryTree tree;
	LLStack stack;  createEmptyStack(&stack);
	int i = strlen(preOrderExp)-1;
	char next;
	
	while(i>=0){
		next = preOrderExp[i];
		if(next=='+' || next=='*' || next=='-' || next=='/'){
			tree = createBinaryTreeNode(next);
			pop(&stack, &(tree->left));
			pop(&stack, &(tree->right));
			push(tree, &stack);
		
		}else{
			tree = createBinaryTreeNode(next); 
			push(tree, &stack);
		}
		i--;
	}
	
	pop(&stack, &tree);
	free(stack);
	return tree;
}

/**
 * Creates a tree from its post order expression 
 * (works with simple arithmetic expressions)
 */
BinaryTree treeFromPostOrder(char *postOrderExp){
	BinaryTree tree;
	LLStack stack;  
	createEmptyStack(&stack);
	int i = 0;
	char next = postOrderExp[0];
	
	while(next != '\0'){
		if(next=='+' || next=='*' || next=='-' || next=='/'){
			tree = createBinaryTreeNode(next);
			pop(&stack, &(tree->right));
			pop(&stack, &(tree->left));
			push(tree, &stack);
		
		}else{
			tree = createBinaryTreeNode(next); 
			push(tree, &stack);
		}
		
		i++;
		next = postOrderExp[i];	
	}
	
	pop(&stack, &tree);
	free(stack);
	return tree;
}



/**
 * Creates a tree from its in order expression 
 *  (works with simple arithmetic expressions)
 * 1) It transforms in order expression to post order expression using a stack
 * 2) Creates the tree using treeFromPostOrder function with that post order expression
 */
BinaryTree treeFromInOrder(char *inOrderExp){
	BinaryTree tree, temp;
	LLStack stack;  createEmptyStack(&stack);
	int *p = NULL;
	int i=0, j=0;
	char next = inOrderExp[0];
	char *postOrderExpression = malloc(strlen(inOrderExp) * sizeof(char));
	
	while(next != '\0'){
		if(next=='+' || next=='*' || next=='-' || next=='/'){
			tree = createBinaryTreeNode(next);
			
			if(!stackIsEmpty(&stack) && (tree->info=='*' || tree->info=='/') && 
			    (stack->element->info=='+' || stack->element->info=='-')){
			
				while(!stackIsEmpty(&stack) && (tree->info=='*' || tree->info=='/') && 
			    		(stack->element->info=='+' || stack->element->info=='-')){
			    		
			    		pop(&stack, &temp);
			    		postOrderExpression[j++] = temp->info;
			    		push(tree, &stack); 	
			    	}
						   
			}else
				push(tree, &stack); 
					
		}else{
			tree = createBinaryTreeNode(next);
			postOrderExpression[j++] = tree->info;
		}
		
		i++;
		next = inOrderExp[i];
	}
	
	while(!stackIsEmpty(&stack)){
		pop(&stack, &tree);
    		postOrderExpression[j++] = tree->info;
	}
	postOrderExpression[j] = '\0';
	
	free(stack);
	return treeFromPostOrder(postOrderExpression);
}



/**
 * Creates a tree from its pre order and in order expressions 
 * (works with any type of expressions and trees)
 */
BinaryTree treeFromPreOrderAndInOrder(char *preOrderExp, char *inOrderExp, int *valid){
	int preExpLen = strlen(preOrderExp);
	int inExpLen = strlen(inOrderExp);

	//If the expressions are not the same length, a tree cannot be created because
	// the expressions dont correspond to the same number of tree nodes.
	if(preExpLen != inExpLen){
		*valid = 0;
		return NULL;
	
	//If the lenght of both expressions is 1, and the only caracter in the expressions
	// is the same, it returns a new tree with just 1 node (the root)
	}else if(preExpLen == 1){
		if(preOrderExp[0]==inOrderExp[0])
			return createBinaryTreeNode(preOrderExp[0]);
		else{
			*valid = 0;
			return NULL;
		}
	
	//If the lenght of both expressions is equal and is greater than 1, creates the treee
	//  with the algorithm
	}else{
		int i, pos;
		int inR, inL, preR, preL;
		char inLeft[inExpLen], inRight[inExpLen];
		char preLeft[preExpLen], preRight[preExpLen];
		
		//Searches for first coincidence and if it exists, divides  
		//  inOrder expression using that coincidence as separator.
		//(Until it reaches the coincidence, is expression left and from coincidence
		//  to last character, is expression right)
		pos = -1;
		for(i=0, inR=0, inL=0; i<inExpLen; i++){
			if(preOrderExp[0] == inOrderExp[i] && pos==-1){
				pos = i;
			
			}else if(pos == -1){
				inLeft[inL++] = inOrderExp[i];
			}else{
				inRight[inR++] = inOrderExp[i];
			}
		}
		
		//If a coincidence is not found, the expressions have the same lenght but do not correspond
		// to the same tree, so a tree cannot be created.
		if(pos == -1){
			*valid = 0;
			return NULL;
		}
		
		//If a coincidence is found, it creates the node with that coincidence and divides preOrder expression
		// with that coincidente as it was done with inOrder expression before.
		BinaryTree root = createBinaryTreeNode(preOrderExp[0]);
		for(i=1, preR=0, preL=0; i<preExpLen; i++){
			if(i<=pos)
				preLeft[preL++] = preOrderExp[i];
			else
				preRight[preR++] = preOrderExp[i];
		}
		
		inRight[inR] = inLeft[inL] = preRight[preR] = preLeft[preL] = '\0';
		
		*valid = 1;
		root->left = treeFromPreOrderAndInOrder(preLeft, inLeft, valid);
		root->right = treeFromPreOrderAndInOrder(preRight, inRight, valid);
		
		if(!(*valid))   return NULL;
		else		return root;		
	}

}



/**
 * Creates a tree from its post order and in order expressions 
 * (works with any type of expressions and trees)
 */
BinaryTree treeFromPostOrderAndInOrder(char *postOrderExp, char *inOrderExp, int *valid){
	int postExpLen = strlen(postOrderExp);
	int inExpLen = strlen(inOrderExp);

	//If the expressions are not the same length, a tree cannot be created because
	// the expressions dont correspond to the same number of tree nodes.
	if(postExpLen != inExpLen){
		*valid = 0;
		return NULL;
	
	//If the lenght of both expressions is 1, and the only caracter in the expressions
	// is the same, it returns a new tree with just 1 node (the root)
	}else if(postExpLen == 1){
		if(postOrderExp[0]==inOrderExp[0])
			return createBinaryTreeNode(postOrderExp[0]);
		else{
			*valid = 0;
			return NULL;
		}
	
	//If the lenght of both expressions is equal and is greater than 1, creates the tree
	//  with the algorithm
	}else{
		int i, pos;
		int inR, inL, postR, postL;
		char inLeft[inExpLen], inRight[inExpLen];
		char postLeft[postExpLen], postRight[postExpLen];
		
		//Searches for first coincidence and if it exists, divides  
		//  inOrder expression using that coincidence as separator.
		//(Until it reaches the coincidence, is expression left and from coincidence
		//  to last character, is expression right)
		pos = -1;
		for(i=0, inR=0, inL=0; i<inExpLen; i++){
			if(postOrderExp[postExpLen-1] == inOrderExp[i] && pos==-1){
				pos = i;
			
			}else if(pos == -1){
				inLeft[inL++] = inOrderExp[i];
			}else{
				inRight[inR++] = inOrderExp[i];
			}
		}
		
		//If a coincidence is not found, the expressions have the same lenght but do not correspond
		// to the same tree, so a tree cannot be created.
		if(pos == -1){
			*valid = 0;
			return NULL;
		}
		
		//If a coincidence is found, it creates the node with that coincidence and divides postOrder expression
		// with that coincidente as it was done with inOrder expression before.
		BinaryTree root = createBinaryTreeNode(postOrderExp[postExpLen-1]);
		for(i=0, postR=0, postL=0; i<postExpLen-1; i++){
			if(i<pos)
				postLeft[postL++] = postOrderExp[i];
			else
				postRight[postR++] = postOrderExp[i];
		}
		
		inRight[inR] = inLeft[inL] = postRight[postR] = postLeft[postL] = '\0';
		
		*valid = 1;
		root->left = treeFromPostOrderAndInOrder(postLeft, inLeft, valid);
		root->right = treeFromPostOrderAndInOrder(postRight, inRight, valid);
		
		if(!(*valid))   return NULL;
		else		return root;		
	}
	

}



