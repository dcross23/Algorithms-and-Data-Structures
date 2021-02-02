#include <stdio.h>
#include "binaryTree.h"

BinaryTree createExampleTree(void);
BinaryTree createLeftWeightedTree(void);
BinaryTree createRightWeightedTree(void);

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
  	printf("\n   Number of substitutions: %d", replace(tree,'D','X'));
  	printf("\n   In-Order traversal after replacing: "); inOrder(tree);
  	
  	printf("\n\n-%-46s: %d\n", "Number of leaf nodes in the tree", numLeafNodes(tree));
  	printf("-%-46s: %d\n", "Number of internal nodes in the tree", numInternalNodes(tree));
  	printf("-%-46s: %d\n","Number of nodes with just 1 child in the tree", numOneChildNodes(tree));
  	
	BinaryTree maxValueTree = searchMax(tree);
	printf("\n-Highest value in the tree: %c", maxValueTree->info);
	printf("\n   In-Order traversal of max value tree: "); inOrder(maxValueTree);

	BinaryTree minValueTree = searchMin(tree);
	printf("\n-Lowest value in the tree: %c", minValueTree->info);
	printf("\n   In-Order traversal of min value tree: "); inOrder(minValueTree);
  	
  	/* To see if 2 trees are similar and/or equivalent, is going to create 2 equal trees and substitute
  	    a letter. This will provoke trees to be similar but no equivalent */
	BinaryTree t1 = createExampleTree(); 
	BinaryTree t2 = createExampleTree(); replace(t2, 'D', 'X'); 
	
	printf("\n\n-Checking if t1 and t2 are similar and/or equivalent");
	printf("\n   In-Order traversal of t1: "); inOrder(t1);
	printf("\n   In-Order traversal of t2: "); inOrder(t2);
	
	if(similars(t1,t2))
		printf("\n The trees t1 and t2 are similar");
	else
		printf("\n The trees t1 and t2 are not similar");

	if(equivalents(t1,t2))
		printf("\n The trees t1 and t2 are equivalent\n");
	else
		printf("\n The trees t1 and t2 are not equivalent\n");
  	
  	/* To see if the tree is specular, is better if the tree is not symetric
  	  For this, is going to create a new tree and add a new node to get am
  	  asymetric tree
  	*/
	BinaryTree t3 = createExampleTree();
	t3->right->right->right = createBinaryTreeNode('M');
	BinaryTree t4 = specular(t3);
	printf("\n-Created specular tree (t4) of the tree t3");
	printf("\n   In-Order traversal of t3: "); inOrder(t3);
	printf("\n   In-Order traversal of t4: "); inOrder(t4);

  	/* To see if a tree is left weighted or rightweighted, just create those tree */
  	BinaryTree lwt = createLeftWeightedTree();
  	BinaryTree rwt = createRightWeightedTree();
  	
  	printf("\n-Left/Right weighted trees");
	printf("\n   In-Order traversal of lwt: "); inOrder(lwt);
	printf("\n   In-Order traversal of rwt: "); inOrder(rwt);
	
	if(leftWeightedTree(lwt)) printf("\n\n -> lwt is left weighted");
	else			  printf("\n\n -> lwt is not left weighted");
	
	if(rightWeightedTree(lwt)) printf("\n -> lwt is right weighted");
	else			   printf("\n -> lwt is not right weighted");
	
	if(leftWeightedTree(rwt)) printf("\n -> rwt is left weighted");
	else			  printf("\n -> rwt is not left weighted");
	
	if(rightWeightedTree(rwt)) printf("\n -> rwt is right weighted\n");
	else			   printf("\n -> rwt is not right weighted\n");
	
  	
  	//puts("");
  	printf("\n-Removing trees...");
  	freeBinaryTree(&tree);
  	freeBinaryTree(&t1);
  	freeBinaryTree(&t2);
  	freeBinaryTree(&t3);
  	freeBinaryTree(&t4);
  	freeBinaryTree(&lwt);
  	freeBinaryTree(&rwt);
  	//No need to remove minValueTree and maxValueTree because they are subtrees
  	// of tree, so removing tree will remove all 3.
  	printf(" Trees removed\n");
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

BinaryTree createLeftWeightedTree(void){
	BinaryTree tree;

	/* Create left weighted tree
			1
		       / \
		     2    3
		    / \  / 
	           4  5 6  
	          /
	         7
	*/	
	
	tree = createBinaryTreeNode('1');
	tree->left  =createBinaryTreeNode('2');
	tree->right =createBinaryTreeNode('3');
	tree->left->left =createBinaryTreeNode('4');
	tree->left->right=createBinaryTreeNode('5');
	tree->right->left =createBinaryTreeNode('6');
	tree->left->left->left=createBinaryTreeNode('7');
	return tree;
}
	
BinaryTree createRightWeightedTree(void){
	/* Create right weighted tree (specular of left weigthed tree)
			1
		       / \
		     2    3
		      \  / \
	              6 5  4
	           	    \
	                     7  
	*/	
	return specular(createLeftWeightedTree());;
}

