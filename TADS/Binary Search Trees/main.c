#include <stdio.h>
#include <stdlib.h>

#include "BSTree.h"

#define RED_TEXT(text) "\x1b[31;1m"#text"\x1b[0m"

int main(void){
	
	BSTree t;
	BSTNode *toSearch;
	int finded, toDelete, nElem;
	
	initBSTree(&t);	
	
	#ifndef ALLOW_DUPLICATED_KEYS
		//Create random tree
		insert(25, &t);
		insert(35, &t);
		insert(15, &t);
		insert(20, &t);
		insert(12, &t);
		insert(13, &t);
		insert(15, &t);
		insert(15, &t);
		insert(15, &t);
		insert(45, &t);
		insert(30, &t);
		insert(10, &t);
		
		//Show final tree after all inserts
		printf("In order expresion (key,info):\n  "); inOrder(t);
		printf("\n\n");
		
		//Find nodes with 15 and 100 in the tree
		switch( search(15, &t, &toSearch) ){
			case -1: printf(RED_TEXT(Error in search!!\n)); break;
			case 0: printf(RED_TEXT(Node 15 doesnt exist\n)); break;
			default:  printf("\x1b[32;1mFinded node with key=\x1b[0;35;1m%d\x1b[32;1m and info=\x1b[36;1m%d\x1b[0m \n",toSearch->key, toSearch->info);
		}
		
		switch( search(100, &t, &toSearch) ){
			case -1: printf(RED_TEXT(Error in search!!\n)); break;
			case 0: printf(RED_TEXT(Node 100 doesnt exist\n)); break;
			default:  printf("\x1b[32;1mFinded node with key=\x1b[0;35;1m%d\x1b[32;1m and info=\x1b[36;1m%d\x1b[0m \n",toSearch->key, toSearch->info);
		}
		
		printf("\n");
		
		//Deletes  node
		toDelete = 15;
		nElem = deleteNode(toDelete, &t);
		switch( nElem ){
			case -1: printf(RED_TEXT(Error in deleteNode!!)); break;
			case 0: printf("\x1b[31;1mNode %d doesnt exist\n\x1b[0m", toDelete); break;
			default: printf("\x1b[33;3;4mDeleted node with key=%d, %d times inserted\x1b[0m", toDelete, nElem);
		}
	
	
		printf("\nIn order expresion (key,info) after deleating:\n  "); inOrder(t);
		printf("\n\n");
	
	
	#else
		//Create random tree
		insert(25,"allows", &t);
		insert(35,"keys", &t);
		insert(15,"Tree", &t);
		insert(20,"that", &t);
		insert(12,"this", &t);
		insert(13,"is", &t);
		insert(15,"Search", &t);
		insert(15,"Binary", &t);
		insert(15,"a", &t);
		insert(45,":D", &t);
		insert(30,"duplicated", &t);
		insert(10,"hello", &t);
		
		printf("In order expresion (key,info):\n  "); inOrder(t);
		printf("\n\n");
		
		//Find nodes with 15 and 100 in the tree
		switch( search(15, &t, &toSearch) ){
			case -1: printf(RED_TEXT(Error in search!!\n)); break;
			case 0: printf(RED_TEXT(Node 15 doesnt exist\n)); break;
			case 1: printf("\x1b[32;1mFinded node with key=\x1b[0;35;1m%d\x1b[32;1m and info=\x1b[36;1m%s\x1b[0m \n",toSearch->key, toSearch->info);
		}
		
		switch( search(100, &t, &toSearch) ){
			case -1: printf(RED_TEXT(Error in search!!\n)); break;
			case 0: printf(RED_TEXT(Node 100 doesnt exist\n)); break;
			case 1:  printf("\x1b[32;1mFinded node with key=\x1b[0;35;1m%d\x1b[32;1m and info=\x1b[36;1m%s\x1b[0m \n",toSearch->key, toSearch->info);
		}
		
		printf("\n");
		
		//Deletes a node
		toDelete = 12;
		nElem = deleteNode(toDelete, &t);
		switch( nElem ){
			case -1: printf(RED_TEXT(Error in deleteNode!!\n)); break;
			case 0: printf("\x1b[31;1mNode %d doesnt exist\n\x1b[0m\n", toDelete); break;
			default: printf("\x1b[33;3;4mDeleted node with key=%d, %d times inserted\x1b[0m", toDelete, nElem);
		}
	
		printf("\nIn order expresion (key,info) after deleating:\n  "); inOrder(t);
		printf("\n\n");
	#endif	
	
	return 0;
}
