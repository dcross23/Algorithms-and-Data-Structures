CC=gcc
#CFLAGS=-c
CFLAGS=-c -g 

.PHONY: all
all: linkedListQueue.o linkedListStack.o heap.o graphCreator.o

linkedListQueue.o: linkedListQueue.c linkedListQueue.h
	$(CC) $(CFLAGS) linkedListQueue.c
	
linkedListStack.o: linkedListStack.c linkedListStack.h
	$(CC) $(CFLAGS) linkedListStack.c
	
heap.o: heap.c heap.h
	$(CC) $(CFLAGS) heap.c	
	
graphCreator.o: graphCreator.c graphCreator.h
	$(CC) $(CFLAGS) graphCreator.c	
	
.PHONY: clean	
clean: 
	rm *.o
