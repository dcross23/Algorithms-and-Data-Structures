CC=gcc
#CFLAGS=-c
CFLAGS=-c -g 

all: linkedListQueue.o linkedListStack.o

linkedListQueue.o: linkedListQueue.c linkedListQueue.h
	$(CC) $(CFLAGS) linkedListQueue.c
	
linkedListStack.o: linkedListStack.c linkedListStack.h
	$(CC) $(CFLAGS) linkedListStack.c
	
clean: 
	rm *.o
