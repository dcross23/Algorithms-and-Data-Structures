#include <stdio.h>
#include "binaryTree.h"

BinaryTree createExampleTree(void);

int main(void)
{ 
	/* Create xample tree */
	BinaryTree tree = createExampleTree();

	/* BinaryTree traversals */
	puts("=============================================");
  	puts("             TREE TRAVERSALS                 ");
  	puts("=============================================");
	
	printf("%23s","PRE-ORDER traversal: ");
	preOrder(tree);
	printf("\n");

	printf("%23s","IN-ORDER traversal: ");
	inOrder(tree);
	printf("\n");

	printf("%23s","POST-ORDER traversal: ");
	postOrder(tree);
	printf("\n");

	printf("%23s","LEVEL-ORDER traversal: ");
	levelOrder(tree);
	printf("\n\n\n");
	
	/* Other functions */
	puts("=============================================");
  	puts("             OTHER FUNCTIONS                 ");
  	puts("=============================================");
	printf("-BinaryTree height = %d\n", height(tree));
  	printf("-Number of nodes in the tree = %d\n", numNodes(tree));
  	
  	printf("\n-Replace 'D' to 'X'");
  	printf("\n  Number of substitutions: %d", replace(tree,'D','X'));
  	printf("\n  In-Order traversal after replacing: "); inOrder(tree);
  	
  	printf("\n\n-%-46s: %d\n", "Number of leaf nodes in the tree", numLeafNodes(tree));
  	printf("-%-46s: %d\n", "Number of internal nodes in the tree", numInternalNodes(tree));
  	printf("-%-46s: %d\n","Number of nodes with just 1 child in the tree", numOneChildNodes(tree));
  	
  	puts("");
  	//printf("-Removing trees\n");
  	freeBinaryTree(&tree);
  	  	
	return 0;	
}


BinaryTree createExampleTree(void){
	BinaryTree tree;

	/* Create xample tree
			A
		       / \
		     B    C
		    / \  / \
	           D  E F  G
	*/	
	
	tree = createBinaryTreeNode('A');
	tree->left  =createBinaryTreeNode('B');
	tree->right =createBinaryTreeNode('C');
	tree->left->left =createBinaryTreeNode('D');
	tree->left->right=createBinaryTreeNode('E');
	tree->right->left =createBinaryTreeNode('F');
	tree->right->right=createBinaryTreeNode('G');
	return tree;
}
