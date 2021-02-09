CC=gcc
#CFLAGS=-c
CFLAGS=-c -g 

all: bTreeGenerators.o treeModifStack.o

bTreeGenerators.o: bTreeGenerators.c bTreeGenerators.h
	$(CC) $(CFLAGS) bTreeGenerators.c

treeModifStack.o: treeModifStack.c treeModifStack.h ../binaryTree.h
	$(CC) $(CFLAGS) treeModifStack.c 

clean: 
	rm *.o
