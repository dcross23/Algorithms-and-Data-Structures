CC=gcc
#CFLAGS=-c
CFLAGS=-c -g
EXECUTABLE_NAME=tree

all: $(EXECUTABLE_NAME)

$(EXECUTABLE_NAME): main.o binaryTree.o treeModifQueue.o
	$(CC) $^ -o $@ -lm

main.o: main.c
	$(CC) $(CFLAGS) main.c

binaryTree.o: binaryTree.c binaryTree.h
	$(CC) $(CFLAGS) binaryTree.c 

treeModifQueue.o: treeModifQueue.c treeModifQueue.h binaryTree.h
	$(CC) $(CFLAGS) treeModifQueue.c 


clean: 
	rm *.o
	rm $(EXECUTABLE_NAME)
