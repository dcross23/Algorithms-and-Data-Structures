CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=binaryTree

GENERATORS = BinaryTreeGenerators
OBJ = main.o binaryTree.o treeModifQueue.o $(GENERATORS)/bTreeGenerators.o $(GENERATORS)/treeModifStack.o

all: generators $(EXECUTABLE_NAME)

generators:
	cd BinaryTreeGenerators; make

$(EXECUTABLE_NAME): $(OBJ)
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

binaryTree.o: binaryTree.c binaryTree.h
	$(CC) $(CFLAGS) binaryTree.c 

treeModifQueue.o: treeModifQueue.c treeModifQueue.h binaryTree.h
	$(CC) $(CFLAGS) treeModifQueue.c 


clean: 
	rm *.o
	cd BinaryTreeGenerators; make clean
	rm $(EXECUTABLE_NAME)
