CC=gcc
#CFLAGS=-c
CFLAGS=-c -g 

.PHONY: all
all: linkedListQueue.o linkedListStack.o heap.o

linkedListQueue.o: linkedListQueue.c linkedListQueue.h
	$(CC) $(CFLAGS) linkedListQueue.c
	
linkedListStack.o: linkedListStack.c linkedListStack.h
	$(CC) $(CFLAGS) linkedListStack.c
	
heap.o: heap.c heap.h
	$(CC) $(CFLAGS) heap.c	
	
.PHONY: clean	
clean: 
	rm *.o
